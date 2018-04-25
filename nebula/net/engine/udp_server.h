/*
 *  Copyright (c) 2018, https://github.com/zhatalk
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

#ifndef NEBULA_NET_ENGINE_UDP_SERVER_H_
#define NEBULA_NET_ENGINE_UDP_SERVER_H_

#include <wangle/bootstrap/ServerBootstrap.h>

#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/base/service_base.h"

namespace nebula {

// template<typename Pipeline = DefaultPipeline>
class UdpServer : public ServiceBase {
public:
  UdpServer(const ServiceConfig &config, const IOThreadPoolExecutorPtr &io_group)
    : ServiceBase(config),
      io_group_(io_group) {}

  virtual ~UdpServer() = default;

  // Impl from ServiceBase
  ServiceModuleType GetModuleType() const override {
    return ServiceModuleType::UDP_SERVER;
  }

  void SetPipeline(std::shared_ptr<wangle::AcceptPipelineFactory> factory) {
    factory_ = factory;
  }

  bool Start() override {
    LOG(INFO) << "UdpServer - Start service: " << config_.ToString();
    server_.channelFactory(std::make_shared<wangle::AsyncUDPServerSocketFactory>());
    server_.pipeline(factory_);
    server_.group(io_group_);
    folly::SocketAddress addr(config_.hosts, config_.port);
    server_.bindImpl(addr);
    return true;
  }

  bool Pause() override {
    return true;
  }

  bool Stop() override {
    LOG(INFO) << "UdpServer - Stop service: " << config_.ToString();

    server_.stop();
    return true;
  }

private:
  IOThreadPoolExecutorPtr io_group_;
  std::shared_ptr<wangle::AcceptPipelineFactory> factory_;
  wangle::ServerBootstrap<DefaultPipeline> server_;
};

}

#endif // NEBULA_NET_ENGINE_UDP_SERVER_H_
