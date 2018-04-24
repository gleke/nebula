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

#ifndef NUBULA_NET_HANDLER_ECHO_UDP_ECHO_HANDLER_H_
#define NUBULA_NET_HANDLER_ECHO_UDP_ECHO_HANDLER_H_

#include <wangle/channel/Handler.h>
#include "nebula/net/handler/nebula_base_handler.h"

//template <typename HandlerPipeline>
//class TestHandlerPipelineFactory : public AcceptPipelineFactory {
//public:
//  AcceptPipeline::Ptr newPipeline(Acceptor*) override {
//    auto pipeline = AcceptPipeline::create();
//    pipeline->addBack(HandlerPipeline());
//    return pipeline;
//  }
//};

class UdpEchoPipeline : public wangle::InboundHandler<wangle::AcceptPipelineType, folly::Unit> {
public:
  UdpEchoPipeline();
  void read(Context*, wangle::AcceptPipelineType) override;
};

// chains the handlers together to define the response pipeline
class UdpEchoPipelineFactory : public wangle::AcceptPipelineFactory, public nebula::NebulaBasePipelineFactory {
public:
  explicit UdpEchoPipelineFactory(nebula::ServiceBase* service)
    : NebulaBasePipelineFactory(service) {}

  wangle::AcceptPipeline::Ptr newPipeline(wangle::Acceptor*) override;
};

#endif

