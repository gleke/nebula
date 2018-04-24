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

#ifndef NEBULA_NET_RPC_ZRPC_PIPELINE_FACTORY_H_
#define NEBULA_NET_RPC_ZRPC_PIPELINE_FACTORY_H_

#include <wangle/service/Service.h>
#include <wangle/service/ExecutorFilter.h>
#include <wangle/channel/AsyncSocketHandler.h>
#include <folly/executors/CPUThreadPoolExecutor.h>

#include "nebula/net/rpc/zrpc_client_handler.h"
#include "nebula/net/rpc/zrpc_server_handler.h"

#include "nebula/net/rpc/zrpc_service.h"

//
class ZRpcClientPipelineFactory : public wangle::PipelineFactory<ZRpcClientPipeline> {
public:
  ZRpcClientPipelineFactory(nebula::ServiceBase* service)
    : service_(service) {}

  ZRpcClientPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock) override;
  
private:
  nebula::ServiceBase* service_{nullptr};
};

class ZRpcServerPipelineFactory : public wangle::PipelineFactory<ZRpcServerPipeline> {
public:
  ZRpcServerPipelineFactory(nebula::ServiceBase* service)
    : service_(service) {}

  ZRpcServerPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock) override;
  
private:
  wangle::ExecutorFilter<zproto::RpcRequestPtr, zproto::ProtoRpcResponsePtr> rpc_service_{
    std::make_shared<folly::CPUThreadPoolExecutor>(10),
    std::make_shared<ZRpcService>()};
  
  nebula::ServiceBase* service_{nullptr};
};

#endif
