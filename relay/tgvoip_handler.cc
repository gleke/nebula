/*
 *  Copyright (c) 2018, https://github.com/nebulaim
 *  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "relay/tgvoip_handler.h"

#include <folly/Singleton.h>
#include "nebula/base/logger/glog_util.h"
#include "nebula/base/io_buf_util.h"
#include "nebula/net/engine/udp_server.h"

#define TLID_DECRYPTED_AUDIO_BLOCK 0xDBF948C1
#define TLID_SIMPLE_AUDIO_BLOCK 0xCC0D0E76
#define TLID_UDP_REFLECTOR_PEER_INFO 0x27D9371C
#define TLID_UDP_REFLECTOR_PEER_INFO_IPV6 0x83fc73b1
#define TLID_UDP_REFLECTOR_SELF_INFO 0xc01572c7

using namespace nebula;

// AcceptPipelineType
typedef std::tuple<folly::IOBuf*, std::shared_ptr<folly::AsyncUDPSocket>, folly::SocketAddress> UdpTupleData;

////////////////////////////////////////////////////////////////////////////////////
void ModuleUdpTGVoipInitialize() {
  static ServiceSelfRegisterTemplate g_reg_udp_tgvoip_server(std::make_pair("udp_server", "tgvoip"),
         [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
           auto service = std::make_shared<UdpServer>(service_config, io_group);
           auto factory = std::make_shared<UdpTGVoipPipelineFactory>(service.get());
           service->SetPipeline(factory);
           return service;
         });
}

//UdpTGVoipPipeline::UdpTGVoipPipeline()
//  : relay_table_manager_(this) {
//  LOG(INFO) << "UdpTGVoipPipeline::UdpTGVoipPipeline()";
//}
//
//UdpTGVoipPipeline::~UdpTGVoipPipeline() {
//  LOG(INFO) << "UdpTGVoipPipeline::~UdpTGVoipPipeline()";
//}


void UdpTGVoipPipeline::read(Context* ctx, wangle::AcceptPipelineType conn) {
  // LOG(INFO) << "UdpTGVoipPipeline::read()";
  if (conn.type() != typeid(UdpTupleData)) {
    LOG(ERROR) << "";
  }

  auto tuple_data = boost::get<UdpTupleData>(conn);
  auto buf = std::get<0>(tuple_data);

  if (!socket_) {
    socket_ = std::get<1>(tuple_data);
  }

  auto address = std::get<2>(tuple_data);

  // auto socket = std::get<1>(tuple_data);

  // socket->write(addr, std::unique_ptr<folly::IOBuf>(buf));
  if (buf->length() < 32) {
    LOG(ERROR) << "";
  }

  folly::io::Cursor c(buf);

  std::string peer_tag = c.readFixedString(16);

  uint32_t packet_types[4];
  packet_types[0] = c.readLE<uint32_t>();
  packet_types[1] = c.readLE<uint32_t>();
  packet_types[2] = c.readLE<uint32_t>();
  packet_types[3] = c.readLE<uint32_t>();

  if (packet_types[0] == 0xFFFFFFFF &&
    packet_types[1] == 0xFFFFFFFF &&
    packet_types[2] == 0xFFFFFFFF &&
    packet_types[3] == 0xFFFFFFFF) {
    onPublicEndpointsRequest(address, peer_tag);
  } else if (packet_types[0] == uint32_t(-1) &&
    packet_types[1] == uint32_t(-1) &&
    packet_types[2] == uint32_t(-1) &&
    packet_types[3] == uint32_t(-2)) {

    onUdpPing(address, peer_tag, c.readLE<uint64_t>());
  } else {
    // TODO(@benqi): length invalid check
    onRelayDataAvailable(address, peer_tag, std::unique_ptr<folly::IOBuf>(buf));
  }

}

void UdpTGVoipPipeline::readException(Context* ctx, folly::exception_wrapper e) {
  LOG(INFO) << "UdpTGVoipPipeline::readException()";
}

void UdpTGVoipPipeline::onUdpPing(const folly::SocketAddress& address, const std::string& peer_tag, uint64_t query_id) {
  LOG(INFO) << "onUdpPing - recv from " << address << ", peer_tag: " << peer_tag << ", query_id: " << query_id;

  auto io_buf2 = folly::IOBuf::create(1024);
  IOBufWriter iobw(io_buf2.get(), 1024);
  iobw.push((const uint8_t*)peer_tag.data(), peer_tag.size());
  iobw.writeLE(uint32_t(-1));
  iobw.writeLE(uint32_t(-1));
  iobw.writeLE(uint32_t(-1));
  iobw.writeLE((uint32_t)TLID_UDP_REFLECTOR_SELF_INFO);

  iobw.writeLE(static_cast<uint32_t>(time(nullptr)));
  iobw.writeLE(query_id);
  char ip[16];
  address.getAddressStr(ip, 16);
  iobw.push((const uint8_t*)ip, 16);
  iobw.writeLE((uint32_t)address.getPort());

  // udp ping
  socket_->write(address, io_buf2);

  // TODO(@benqi): forward to???
}

void UdpTGVoipPipeline::onPublicEndpointsRequest(const folly::SocketAddress& address, const std::string& peer_tag) {
  LOG(INFO) << "onPublicEndpointsRequest - recv from " << address << ", peer_tag: " << peer_tag;
}

void UdpTGVoipPipeline::onRelayDataAvailable(const folly::SocketAddress& address,
                                             const std::string peer_tag,
                                             const std::unique_ptr<folly::IOBuf>& buf) {
  LOG(INFO) << "onRelayDataAvailable - recv from " << address << ", peer_tag: " << peer_tag << ", len: " << buf->length();

  std::shared_ptr<RelayTable> table;

  auto it = relay_table_map_.find(peer_tag);
  if (it != relay_table_map_.end()) {
    table = it->second;
    bool found = false;
    for (auto& i : it->second->peers) {
      if (i.addr == address) {
        found = true;
        // table = it->second;
        break;
      }
    }
    if (!found) {
      table->peers.push_back(Endpoint{address, 0});
    }
    // it->second.peers.push_back(address);
    // Endpoint&
  } else {
    //RelayTable table;
    table = std::make_shared<RelayTable>();
    table->peer_tag = peer_tag;
    table->peers.push_back(Endpoint{address, 0});
    relay_table_map_.insert(std::make_pair(peer_tag, table));
  }

  // it = relay_table_map_.find(peer_tag);
  for (auto i : table->peers) {
    if (i.addr != address) {
      LOG(INFO) << "onRelayData - send data to address " << address;
      // socket_->write(address, buf);
      socket_->write(i.addr, buf->clone());
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////
wangle::AcceptPipeline::Ptr UdpTGVoipPipelineFactory::newPipeline(wangle::Acceptor*) {
  auto pipeline = wangle::AcceptPipeline::create();
  pipeline->addBack(UdpTGVoipPipeline());
  return pipeline;
}
