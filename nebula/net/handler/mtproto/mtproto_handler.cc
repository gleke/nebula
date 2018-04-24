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

#include "nebula/net/handler/mtproto/mtproto_handler.h"

#include <wangle/channel/AsyncSocketHandler.h>
#include <wangle/channel/EventBaseHandler.h>
#include <wangle/codec/LineBasedFrameDecoder.h>
#include <wangle/codec/StringCodec.h>

#include "nebula/net/engine/tcp_client_group.h"
#include "nebula/net/engine/tcp_client.h"
#include "nebula/net/engine/tcp_server.h"
#include "nebula/net/thread_local_conn_manager.h"

#include "nebula/net/handler/mtproto/mtproto_pipeline_factory.h"

using namespace nebula;

// 保活心跳
#define HEARTBEAT_TIMEOUT 10000 // 心跳间隔时间：10s

///////////////////////////////////////////////////////////////////////////////////////
// 不能直接使用静态类注册的原因:
// 不在一个.a文件里静态变量不可视
// 通过ModuleMTProtoInitialize显式调用
void ModuleMTProtoInitialize() {
/*
static ServiceSelfRegisterTemplate g_reg_mtproto_tcp_client_group(std::make_pair("tcp_client_group", "mtproto"),
             [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
               auto service= std::make_shared<TcpClientGroup<MTProtoPipeline>>(service_config, io_group);
               return service;
             });

static ServiceSelfRegisterTemplate g_reg_mtproto_tcp_client(std::make_pair("tcp_client", "mtproto"),
             [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
               auto service = std::make_shared<TcpClient<MTProtoPipeline>>(service_config, io_group);
               auto factory = std::make_shared<MTProtoClientPipelineFactory>(service.get());
               service->SetChildPipeline(factory);
               return service;
             });
 */
static ServiceSelfRegisterTemplate g_reg_mtproto_tcp_server(std::make_pair("tcp_server", "mtproto"),
             [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
               auto service = std::make_shared<TcpServer<MTProtoPipeline>>(service_config, io_group);
               auto factory = std::make_shared<MTProtoServerPipelineFactory>(service.get());
               service->SetChildPipeline(factory);
               return service;
             });
}

///////////////////////////////////////////////////////////////////////////////////////////
void MTProtoHandler::read(Context* ctx, std::unique_ptr<folly::IOBuf> msg) {
  LOG(INFO) << "read - received data: "; // << msg;
  auto pipeline = dynamic_cast<MTProtoPipeline*>(ctx->getPipeline());

  int rv = MTProtoEventCallback::OnDataReceived(pipeline, std::forward<std::unique_ptr<folly::IOBuf>>(msg));
  if (rv == -1) {
    // TODO(@benqi): 是否需要断开或其它处理
  }
}

void MTProtoHandler::readEOF(Context* ctx) {
  LOG(INFO) << "readEOF - conn_id = " << conn_id_ << ", MTProtoHandler - Connection closed by "
              << remote_address_
              << ", conn_info: " << service_->GetServiceConfig().ToString();
  close(ctx);
}

void MTProtoHandler::readException(Context* ctx, folly::exception_wrapper e) {
  LOG(ERROR) << "readException - conn_id = " << conn_id_
              << ", MTProtoHandler - Local error: " << exceptionStr(e)
              << ", by "  << remote_address_
              << ", conn_info: " << service_->GetServiceConfig().ToString();
  close(ctx);
}

void MTProtoHandler::transportActive(Context* ctx) {
  auto pipeline = dynamic_cast<MTProtoPipeline*>(ctx->getPipeline());
  auto conn_id = OnNewConnection(pipeline, pipeline->getTransportInfo()->remoteAddr->getAddressStr());
  
  LOG(INFO) << "transportActive - conn_id = " << conn_id_
            << ", MTProtoHandler - Connection connected by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();

  int rv = MTProtoEventCallback::OnNewConnection(service_, pipeline);
  if (rv == -1) {
    // TODO(@benqi): 是否需要断开或其它处理
  }
}

void MTProtoHandler::transportInactive(Context* ctx) {
  if (conn_state_ != ConnState::CONNECTED) {
    return;
  }

  LOG(INFO) << "transportInactive - conn_id = " << conn_id_
            << ", Connection closed by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();

  auto pipeline = dynamic_cast<MTProtoPipeline*>(ctx->getPipeline());
  int rv = MTProtoEventCallback::OnConnectionClosed(service_, pipeline);
  if (rv == -1) {
    // TODO(@benqi): 是否需要其它处理
  }

  OnConnectionClosed();
}

folly::Future<folly::Unit> MTProtoHandler::close(Context* ctx) {
  return ctx->fireClose();
}

