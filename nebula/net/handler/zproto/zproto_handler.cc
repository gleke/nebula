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

#include "nebula/net/handler/zproto/zproto_handler.h"

#include <wangle/channel/AsyncSocketHandler.h>
#include <wangle/channel/EventBaseHandler.h>
#include <wangle/codec/LineBasedFrameDecoder.h>
#include <wangle/codec/StringCodec.h>

#include "nebula/net/engine/tcp_client_group.h"
#include "nebula/net/engine/tcp_client.h"
#include "nebula/net/engine/tcp_server.h"
#include "nebula/net/thread_local_conn_manager.h"

#include "nebula/net/handler/zproto/zproto_pipeline_factory.h"

using namespace nebula;
using namespace zproto;

// 保活心跳
#define HEARTBEAT_TIMEOUT 10000 // 心跳间隔时间：10s

///////////////////////////////////////////////////////////////////////////////////////
// 不能直接使用静态类注册的原因:
// 不在一个.a文件里静态变量不可视
// 通过ModuleZProtoInitialize显式调用
void ModuleZProtoInitialize() {
static ServiceSelfRegisterTemplate g_reg_zproto_tcp_client_group(std::make_pair("tcp_client_group", "zproto"),
             [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
               auto service= std::make_shared<TcpClientGroup<ZProtoPipeline>>(service_config, io_group);
               return service;
             });

static ServiceSelfRegisterTemplate g_reg_zproto_tcp_client(std::make_pair("tcp_client", "zproto"),
             [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
               auto service = std::make_shared<TcpClient<ZProtoPipeline>>(service_config, io_group);
               auto factory = std::make_shared<ZProtoClientPipelineFactory>(service.get());
               service->SetChildPipeline(factory);
               return service;
             });

static ServiceSelfRegisterTemplate g_reg_zproto_tcp_server(std::make_pair("tcp_server", "zproto"),
             [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
               auto service = std::make_shared<TcpServer<ZProtoPipeline>>(service_config, io_group);
               auto factory = std::make_shared<ZProtoServerPipelineFactory>(service.get());
               service->SetChildPipeline(factory);
               return service;
             });
}

///////////////////////////////////////////////////////////////////////////////////////////
void ZProtoHandler::read(Context* ctx, std::shared_ptr<zproto::PackageMessage> msg) {
  LOG(INFO) << "read - received data: "; // << msg;
  auto pipeline = dynamic_cast<ZProtoPipeline*>(ctx->getPipeline());

  int rv = ZProtoEventCallback::OnDataReceived(pipeline, msg);
  if (rv == -1) {
    // TODO(@benqi): 是否需要断开或其它处理
  }
}

void ZProtoHandler::readEOF(Context* ctx) {
  LOG(INFO) << "readEOF - conn_id = " << conn_id_ << ", ZProtoHandler - Connection closed by "
              << remote_address_
              << ", conn_info: " << service_->GetServiceConfig().ToString();
  close(ctx);
}

void ZProtoHandler::readException(Context* ctx, folly::exception_wrapper e) {
  LOG(ERROR) << "readException - conn_id = " << conn_id_
              << ", ZProtoHandler - Local error: " << exceptionStr(e)
              << ", by "  << remote_address_
              << ", conn_info: " << service_->GetServiceConfig().ToString();
  close(ctx);
}

void ZProtoHandler::transportActive(Context* ctx) {
  auto pipeline = dynamic_cast<ZProtoPipeline*>(ctx->getPipeline());
  auto conn_id = OnNewConnection(pipeline, pipeline->getTransportInfo()->remoteAddr->getAddressStr());
  
  LOG(INFO) << "transportActive - conn_id = " << conn_id_
            << ", ZProtoHandler - Connection connected by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();

  int rv = ZProtoEventCallback::OnNewConnection(service_, pipeline);
  if (rv == -1) {
    // TODO(@benqi): 是否需要断开或其它处理
  }

  // 客户端主动保活
  if (service_->GetServiceType() == "tcp_client") {
    folly::EventBase* main_eb = folly::EventBaseManager::get()->getEventBase();
    main_eb->runAfterDelay([conn_id] {
      ZProtoHandler::DoHeartBeat(conn_id, HEARTBEAT_TIMEOUT);
    }, HEARTBEAT_TIMEOUT);
  }
}

void ZProtoHandler::transportInactive(Context* ctx) {
  if (conn_state_ != ConnState::CONNECTED) {
    return;
  }

  LOG(INFO) << "transportInactive - conn_id = " << conn_id_
            << ", Connection closed by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();

  auto pipeline = dynamic_cast<ZProtoPipeline*>(ctx->getPipeline());
  int rv = ZProtoEventCallback::OnConnectionClosed(service_, pipeline);
  if (rv == -1) {
    // TODO(@benqi): 是否需要其它处理
  }

  OnConnectionClosed();
}

folly::Future<folly::Unit> ZProtoHandler::close(Context* ctx) {
  return ctx->fireClose();
}

// TODO(@benqi): 可以使用std::weak_ptr<ZRpcClientPipeline>代替conn_id
// 减少一次FindPipeline
void ZProtoHandler::DoHeartBeat(uint64_t conn_id, uint32_t timeout) {
  auto pl = GetConnManagerByThreadLocal().FindPipeline(conn_id);
  if (pl) {
    zproto::Ping ping("zproto_handler");
    std::unique_ptr<folly::IOBuf> data;
    ping.SerializeToIOBuf(data);
    nebula::write(pl, std::move(data));
    
    folly::EventBase* main_eb = folly::EventBaseManager::get()->getEventBase();
    main_eb->runAfterDelay([conn_id, timeout] {
      ZProtoHandler::DoHeartBeat(conn_id, timeout);
    }, timeout);
  }
}
