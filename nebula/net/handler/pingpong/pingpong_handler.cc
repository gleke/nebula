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

#include "nebula/net/handler/pingpong/pingpong_handler.h"

#include <wangle/channel/AsyncSocketHandler.h>
#include <wangle/channel/EventBaseHandler.h>
#include <wangle/channel/OutputBufferingHandler.h>
#include "nebula/net/engine/tcp_server.h"

using namespace nebula;

///////////////////////////////////////////////////////////////////////////////////////
// 不能直接使用静态类注册的原因:
// 不在一个.a文件里静态变量不可视
// 通过ModulePingpongInitialize显式调用
void ModulePingpongInitialize() {
  static ServiceSelfRegisterTemplate g_reg_pingpong_tcp_server(std::make_pair("tcp_server", "pingpong"),
       [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
         auto service = std::make_shared<TcpServer<PingpongPipeline>>(service_config, io_group);
         auto factory = std::make_shared<PingpongServerPipelineFactory>(service.get());
         service->SetChildPipeline(factory);
         return service;
       });
}

///////////////////////////////////////////////////////////////////////////////////////
void PingpongHandler::transportActive(Context* ctx) {
  // auto pipeline = dynamic_cast<EchoPipeline*>(ctx->getPipeline());
  // OnNewConnection(pipeline, pipeline->getTransportInfo()->remoteAddr->getAddressStr());

  // LOG(INFO) << "transportActive - conn_id = " << conn_id_
  //           << ", ZProtoHandler - Connection connected by "
  //           << remote_address_
  //           << ", conn_info: " << service_->GetServiceConfig().ToString();
}

void PingpongHandler::transportInactive(Context* ctx) {
  // if (conn_state_ != ConnState::CONNECTED) {
  //   return;
  // }

  // LOG(INFO) << "transportInactive - conn_id = " << conn_id_
  //           << ", Connection closed by "
  //           << remote_address_
  //           << ", conn_info: " << service_->GetServiceConfig().ToString();
  // OnConnectionClosed();
}

void PingpongHandler::read(Context* ctx, folly::IOBufQueue &msg) {
  // LOG(INFO) << "received back: " << msg;
  ctx->fireWrite(msg.move());
}

void PingpongHandler::readException(Context* ctx, folly::exception_wrapper e) {
  LOG(ERROR) << exceptionStr(e);
  close(ctx);
}

void PingpongHandler::readEOF(Context* ctx) {
  // LOG(INFO) << "EOF received :(";
  close(ctx);
}

folly::Future<folly::Unit> PingpongHandler::close(Context* ctx) {
  // OnConnectionClosed();
  return ctx->fireClose();
}

// 设置readBufferSettings_
const uint64_t kDefaultMinAvailable = 32*1024;
const uint64_t kDefaultAllocationSize = 64*1024;

///////////////////////////////////////////////////////////////////////////////////////
PingpongPipeline::Ptr PingpongServerPipelineFactory::newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock) {
  auto pipeline = PingpongPipeline::create();
  pipeline->setReadBufferSettings(kDefaultMinAvailable, kDefaultAllocationSize);
  pipeline->addBack(wangle::AsyncSocketHandler(sock));
  pipeline->addBack(PingpongHandler(service_));
  pipeline->addBack(wangle::OutputBufferingHandler());
  pipeline->finalize();
  return pipeline;
}
