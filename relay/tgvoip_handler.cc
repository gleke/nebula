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
#include "nebula/net/engine/udp_server.h"

#include "relay/relay_table.h"

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

UdpTGVoipPipeline::UdpTGVoipPipeline()
  : relay_table_manager_(this) {
  LOG(INFO) << "UdpTGVoipPipeline::UdpTGVoipPipeline()";
}

void UdpTGVoipPipeline::read(Context* ctx, wangle::AcceptPipelineType conn) {
  LOG(INFO) << "UdpTGVoipPipeline::read()";
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

  std::string peer_tag;
  c.readFixedString(16);

  uint32_t packet_types[4];
  packet_types[0] = c.readLE<uint32_t>();
  packet_types[1] = c.readLE<uint32_t>();
  packet_types[2] = c.readLE<uint32_t>();
  packet_types[3] = c.readLE<uint32_t>();

  if (packet_types[0] == 0xFFFFFFFF &&
    packet_types[1] == 0xFFFFFFFF &&
    packet_types[2] == 0xFFFFFFFF &&
    packet_types[3] == 0xFFFFFFFF) {
    onPublicEndpointsRequest(ctx, conn);
  } else if (packet_types[0] == uint32_t(-1) &&
    packet_types[1] == uint32_t(-1) &&
    packet_types[2] == uint32_t(-1) &&
    packet_types[3] == uint32_t(-2)) {
    onUdpPing(ctx, conn);
  } else {
    // TODO(@benqi): length invalid check
    relay_table_manager_.OnRelayDataAvailable(peer_tag, address, std::unique_ptr<folly::IOBuf>(buf));
  }

}

void UdpTGVoipPipeline::readException(Context* ctx, folly::exception_wrapper e) {
  LOG(INFO) << "UdpTGVoipPipeline::readException()";
}

void UdpTGVoipPipeline::onUdpPing(Context* ctx, wangle::AcceptPipelineType conn) {
}

void UdpTGVoipPipeline::onPublicEndpointsRequest(Context* ctx, wangle::AcceptPipelineType conn) {
}

///////////////////////////////////////////////////////////////////////////////////////////
void UdpTGVoipPipeline::onRelayData(const folly::SocketAddress& address,
                                    const std::unique_ptr<folly::IOBuf>& buf) {
  // LOG(INFO) << "UdpTGVoipPipeline::onRelayData()";
}

///////////////////////////////////////////////////////////////////////////////////////////
wangle::AcceptPipeline::Ptr UdpTGVoipPipelineFactory::newPipeline(wangle::Acceptor*) {
  auto pipeline = wangle::AcceptPipeline::create();
  pipeline->addBack(UdpTGVoipPipeline());
  return pipeline;
}
