/*
 *  Copyright (c) 2016, https://github.com/zhatalk
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

#ifndef NEBULA_NET_ENGINE_TCP_SERVER_H_
#define NEBULA_NET_ENGINE_TCP_SERVER_H_

#include <wangle/bootstrap/ServerBootstrap.h>

#include "nebula/net/engine/tcp_service_base.h"

namespace nebula {
  
#define DEFAULT_CONN_IDLE_TIMEOUT 240000
  
enum NetModuleState {
  kNetModuleState_None = 0,
};
  
template<typename Pipeline = DefaultPipeline>
class TcpServer : public TcpServiceBase {
public:
  typedef typename wangle::PipelineFactory<Pipeline> ServerPipelineFactory;

  TcpServer(const ServiceConfig& config, const IOThreadPoolExecutorPtr& io_group)
    : TcpServiceBase(config, io_group) {
    
    wangle::ServerSocketConfig acc_config;
    acc_config.connectionIdleTimeout = std::chrono::milliseconds(DEFAULT_CONN_IDLE_TIMEOUT);
    server_.acceptorConfig(acc_config);
    
    // if (!io_group_) {
    //    LOG(ERROR) << "TcpServer - io_group is nil!!!!";
    // }
  }

  virtual ~TcpServer() = default;
  
  void SetChildPipeline(std::shared_ptr<ServerPipelineFactory> factory) {
    factory_ = factory;
  }
  
  // Impl from ServiceBase
  bool Start() override {
    // TODO(@benqi)
    //  检查factory_,conns_,config_等
    // if (!io_group_) {
    //    LOG(ERROR) << "Start - io_group is nil!!!!";
    // }
    server_.childPipeline(factory_);
    server_.group(io_group_);
    server_.bind(config_.port);
    
    return true;
  }
  
  bool Pause() override {
    return true;
  }
  
  bool Stop() override {
    LOG(INFO) << "TcpServer - Stop service: " << config_.ToString();
    
    server_.stop();
    return true;
  }
  
  // Impl from TcpServiceBase
  ServiceModuleType GetModuleType() const override {
    return ServiceModuleType::TCP_SERVER;
  }
  
private:
  // IOThreadPoolExecutorPtr io_group_;
  std::shared_ptr<ServerPipelineFactory> factory_;
  wangle::ServerBootstrap<Pipeline> server_;
};

}

#endif
