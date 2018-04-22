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

#ifndef NUBULA_NET_HANDLER_ECHO_ECHO_HANDLER_H_
#define NUBULA_NET_HANDLER_ECHO_ECHO_HANDLER_H_

#include "nebula/net/handler/nebula_base_handler.h"

typedef wangle::Pipeline<folly::IOBufQueue&, std::string> EchoPipeline;

// the handler for receiving messages back from the server
class EchoHandler : public wangle::HandlerAdapter<std::string>, public nebula::NebulaBaseHandler {
public:
  explicit EchoHandler(nebula::ServiceBase* service)
    : NebulaBaseHandler(service) {}

  virtual void transportActive(Context* ctx) override;
  virtual void transportInactive(Context* ctx) override;

  virtual void read(Context* ctx, std::string msg) override;

  virtual void readException(Context* ctx, folly::exception_wrapper e) override;
  virtual void readEOF(Context* ctx) override;
  
  virtual folly::Future<folly::Unit> close(Context* ctx) override;
};

// chains the handlers together to define the response pipeline
class EchoClientPipelineFactory : public wangle::PipelineFactory<EchoPipeline>, public nebula::NebulaBasePipelineFactory {
public:
  explicit EchoClientPipelineFactory(nebula::ServiceBase* service)
    : NebulaBasePipelineFactory(service) {}
  
  EchoPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
};

// where we define the chain of handlers for each messeage received
class EchoServerPipelineFactory : public wangle::PipelineFactory<EchoPipeline>, public nebula::NebulaBasePipelineFactory {
public:
  EchoServerPipelineFactory(nebula::ServiceBase* service)
    : NebulaBasePipelineFactory(service) {}
  
  EchoPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
};

// 通过配置文件的proto来启用
// 需要显示调用
void ModuleEchoInitialize();

#endif

