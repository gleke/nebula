/*
 *  Copyright (c) 2018, https://github.com/nebulaim/nebula
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

#ifndef NUBULA_NET_HANDLER_PINGPONG_PINGPONG_HANDLER_H_
#define NUBULA_NET_HANDLER_PINGPONG_PINGPONG_HANDLER_H_

#include "nebula/net/handler/nebula_base_handler.h"

typedef wangle::Pipeline<folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>> PingpongPipeline;

// the handler for receiving messages back from the server
class PingpongHandler : public wangle::BytesToBytesHandler, public nebula::NebulaBaseHandler {
public:
  explicit PingpongHandler(nebula::ServiceBase* service)
    : NebulaBaseHandler(service) {}

  virtual void transportActive(Context* ctx) override;
  virtual void transportInactive(Context* ctx) override;

  virtual void read(Context* ctx, folly::IOBufQueue &msg) override;

  virtual void readException(Context* ctx, folly::exception_wrapper e) override;
  virtual void readEOF(Context* ctx) override;

  virtual folly::Future<folly::Unit> close(Context* ctx) override;
};

// where we define the chain of handlers for each messeage received
class PingpongServerPipelineFactory : public wangle::PipelineFactory<PingpongPipeline>, public nebula::NebulaBasePipelineFactory {
public:
  PingpongServerPipelineFactory(nebula::ServiceBase* service)
    : NebulaBasePipelineFactory(service) {}

  PingpongPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
};

// 通过配置文件的proto来启用
// 需要显示调用
void ModulePingpongInitialize();

#endif

