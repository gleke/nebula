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

#include "nebula/net/handler/echo/echo_handler.h"

#include <wangle/channel/AsyncSocketHandler.h>
#include <wangle/channel/EventBaseHandler.h>
#include <wangle/codec/LineBasedFrameDecoder.h>
#include <wangle/codec/StringCodec.h>

#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/engine/tcp_client_group.h"
#include "nebula/net/engine/tcp_client.h"
#include "nebula/net/engine/tcp_server.h"

using namespace nebula;

///////////////////////////////////////////////////////////////////////////////////////
// 不能直接使用静态类注册的原因:
// 不在一个.a文件里静态变量不可视
// 通过ModuleEchoInitialize显式调用
void ModuleEchoInitialize() {
  static ServiceSelfRegisterTemplate g_reg_echo_tcp_client_group(std::make_pair("tcp_client_group", "echo"),
               [](const ServiceConfig& service_config, const std::shared_ptr<wangle::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
                 auto service= std::make_shared<TcpClientGroup<EchoPipeline>>(service_config, io_group);
                 return service;
               });

  static ServiceSelfRegisterTemplate g_reg_echo_tcp_client(std::make_pair("tcp_client", "echo"),
               [](const ServiceConfig& service_config, const std::shared_ptr<wangle::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
                 auto service = std::make_shared<TcpClient<EchoPipeline>>(service_config, io_group);
                 auto factory = std::make_shared<EchoClientPipelineFactory>(service.get());
                 service->SetChildPipeline(factory);
                 return service;
               });

  static ServiceSelfRegisterTemplate g_reg_echo_tcp_server(std::make_pair("tcp_server", "echo"),
               [](const ServiceConfig& service_config, const std::shared_ptr<wangle::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
                 auto service = std::make_shared<TcpServer<EchoPipeline>>(service_config, io_group);
                 auto factory = std::make_shared<EchoServerPipelineFactory>(service.get());
                 service->SetChildPipeline(factory);
                 return service;
               });
}



///////////////////////////////////////////////////////////////////////////////////////
void EchoHandler::transportActive(Context* ctx) {
  auto pipeline = dynamic_cast<EchoPipeline*>(ctx->getPipeline());
  OnNewConnection(pipeline, pipeline->getTransportInfo()->remoteAddr->getAddressStr());
  
  LOG(INFO) << "transportActive - conn_id = " << conn_id_
            << ", ZProtoHandler - Connection connected by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();
}

void EchoHandler::transportInactive(Context* ctx) {
  if (conn_state_ != ConnState::CONNECTED) {
    return;
  }

  LOG(INFO) << "transportInactive - conn_id = " << conn_id_
            << ", Connection closed by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();
            
  OnConnectionClosed();
}

void EchoHandler::read(Context* ctx, std::string msg) {
  LOG(INFO) << "received back: " << msg;
  
  if (IsTcpServer()) {
    write(ctx, msg + "\r\n");
    
    // Test
    // WriterUtil::Write(conn_id_, msg + "\r\n");
    // WriterUtil::Write(1, msg + "\r\n");
  }
}

void EchoHandler::readException(Context* ctx, folly::exception_wrapper e) {
  LOG(ERROR) << exceptionStr(e);
  close(ctx);
}

void EchoHandler::readEOF(Context* ctx) {
  LOG(INFO) << "EOF received :(";
  close(ctx);
}

folly::Future<folly::Unit> EchoHandler::close(Context* ctx) {
  OnConnectionClosed();
  return ctx->fireClose();
}

///////////////////////////////////////////////////////////////////////////////////////
EchoPipeline::Ptr EchoClientPipelineFactory::newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock) {
  auto pipeline = EchoPipeline::create();
  
  SetPipelineAddr(pipeline.get(), sock.get());
  
  pipeline->addBack(wangle::AsyncSocketHandler(sock));
  pipeline->addBack(wangle::EventBaseHandler()); // ensure we can write from any thread
  pipeline->addBack(wangle::LineBasedFrameDecoder(8192, false));
  pipeline->addBack(wangle::StringCodec());
  pipeline->addBack(EchoHandler(service_));
  pipeline->finalize();
  return pipeline;
}

///////////////////////////////////////////////////////////////////////////////////////
EchoPipeline::Ptr EchoServerPipelineFactory::newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock) {
  auto pipeline = EchoPipeline::create();
  pipeline->addBack(wangle::AsyncSocketHandler(sock));
  pipeline->addBack(wangle::LineBasedFrameDecoder(8192));
  pipeline->addBack(wangle::StringCodec());
  pipeline->addBack(EchoHandler(service_));
  pipeline->finalize();
  return pipeline;
}
