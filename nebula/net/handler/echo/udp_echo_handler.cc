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

#include "nebula/net/handler/echo/udp_echo_handler.h"

#include "nebula/base/logger/glog_util.h"
#include "nebula/net/engine/udp_server.h"

using namespace nebula;

void ModuleUdpEchoInitialize() {
  static ServiceSelfRegisterTemplate g_reg_echo_udp_server(std::make_pair("udp_server", "echo"),
         [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
           auto service = std::make_shared<UdpServer>(service_config, io_group);
           auto factory = std::make_shared<UdpEchoPipelineFactory>(service.get());
           service->SetPipeline(factory);
           return service;
         });
}

UdpEchoPipeline::UdpEchoPipeline() {
  LOG(INFO) << "UdpEchoPipeline::UdpEchoPipeline()";
}

void UdpEchoPipeline::read(Context*, wangle::AcceptPipelineType) {
  LOG(INFO) << "UdpEchoPipeline::read()";
}


wangle::AcceptPipeline::Ptr UdpEchoPipelineFactory::newPipeline(wangle::Acceptor*) {
  auto pipeline = wangle::AcceptPipeline::create();
  pipeline->addBack(UdpEchoPipeline());
  return pipeline;
}
