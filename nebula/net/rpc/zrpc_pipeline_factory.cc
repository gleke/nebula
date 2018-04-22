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


#include "nebula/net/rpc/zrpc_pipeline_factory.h"

#include <wangle/service/Service.h>
#include <wangle/service/ExpiringFilter.h>
#include <wangle/service/ExecutorFilter.h>
#include <wangle/service/ServerDispatcher.h>

#include <wangle/channel/AsyncSocketHandler.h>
//#include <wangle/codec/LengthFieldBasedFrameDecoder.h>
//#include <wangle/codec/LengthFieldPrepender.h>
#include <wangle/channel/EventBaseHandler.h>

#include "nebula/net/handler/zproto/zproto_frame_handler.h"
#include "nebula/net/handler/zproto/zproto_package_handler.h"

// 设置readBufferSettings_
const uint64_t kDefaultMinAvailable = 8096;
const uint64_t kDefaultAllocationSize = 16192;

ZRpcClientPipeline::Ptr ZRpcClientPipelineFactory::newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock) {
  auto pipeline = ZRpcClientPipeline::create();
  
  pipeline->setReadBufferSettings(kDefaultMinAvailable, kDefaultAllocationSize);
  
  // Initialize TransportInfo and set it on the pipeline
  auto transportInfo = std::make_shared<wangle::TransportInfo>();
  folly::SocketAddress localAddr, peerAddr;
  sock->getLocalAddress(&localAddr);
  sock->getPeerAddress(&peerAddr);
  transportInfo->localAddr = std::make_shared<folly::SocketAddress>(localAddr);
  transportInfo->remoteAddr = std::make_shared<folly::SocketAddress>(peerAddr);
  pipeline->setTransportInfo(transportInfo);

  pipeline->addBack(wangle::AsyncSocketHandler(sock));
  // ensure we can write from any thread
  pipeline->addBack(wangle::EventBaseHandler());
  pipeline->addBack(ZProtoFrameDecoder());
  pipeline->addBack(ZProtoFrameHandler());
  pipeline->addBack(ZProtoPackageHandler());
  pipeline->addBack(ZRpcClientHandler(service_));
  pipeline->finalize();
  return pipeline;
}


ZRpcServerPipeline::Ptr ZRpcServerPipelineFactory::newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock) {
  auto pipeline = ZRpcServerPipeline::create();
  pipeline->addBack(wangle::AsyncSocketHandler(sock));
  // ensure we can write from any thread
  pipeline->addBack(wangle::EventBaseHandler());
  
  pipeline->addBack(ZProtoFrameDecoder());
  pipeline->addBack(ZProtoFrameHandler());
  pipeline->addBack(ZProtoPackageHandler());

//  pipeline->addBack(wangle::LengthFieldBasedFrameDecoder());
//  pipeline->addBack(wangle::LengthFieldPrepender());
  pipeline->addBack(ZRpcServerHandler(service_));
  // We could use a serial dispatcher instead easily
  // pipeline->addBack(SerialServerDispatcher<Bonk>(&service_));
  // Or a Pipelined Dispatcher
  // pipeline->addBack(PipelinedServerDispatcher<Bonk>(&service_));
  pipeline->addBack(wangle::MultiplexServerDispatcher<zproto::RpcRequestPtr, zproto::ProtoRpcResponsePtr>(&rpc_service_));
  pipeline->finalize();
  
  return pipeline;
}
