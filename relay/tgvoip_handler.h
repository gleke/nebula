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

#ifndef RELAY_TGVOIP_HANDLER_H_
#define RELAY_TGVOIP_HANDLER_H_

#include "nebula/net/handler/nebula_base_handler.h"

struct Endpoint {
  folly::SocketAddress addr;
  uint64_t last_recved_time;
};

struct RelayTable {
  std::string peer_tag;
  std::list<Endpoint> peers;
};

class UdpTGVoipPipeline : public wangle::InboundHandler<wangle::AcceptPipelineType, folly::Unit> {
public:
//  UdpTGVoipPipeline();
//  ~UdpTGVoipPipeline();

  // Impl InboundHandler
  void read(Context* ctx, wangle::AcceptPipelineType conn) override;
  void readException(Context* ctx, folly::exception_wrapper e) override;

private:
  void onUdpPing(const folly::SocketAddress& address, const std::string& peer_tag, uint64_t query_id);
  void onPublicEndpointsRequest(const folly::SocketAddress& address, const std::string& peer_tag);
  void onRelayDataAvailable(const folly::SocketAddress& address,
                            const std::string peer_tag,
                            const std::unique_ptr<folly::IOBuf>& buf);

  std::shared_ptr<folly::AsyncUDPSocket> socket_;
  // RelayTableManager relay_table_manager_;
  std::map<std::string, std::shared_ptr<RelayTable>> relay_table_map_;
};

// chains the handlers together to define the response pipeline
class UdpTGVoipPipelineFactory : public wangle::AcceptPipelineFactory, public nebula::NebulaBasePipelineFactory {
public:
  explicit UdpTGVoipPipelineFactory(nebula::ServiceBase* service)
    : NebulaBasePipelineFactory(service) {}

  wangle::AcceptPipeline::Ptr newPipeline(wangle::Acceptor*) override;
};

// 通过配置文件的proto来启用
// 需要显示调用
void ModuleUdpTGVoipInitialize();

#endif

