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

#include "nebula/net/rpc/zrpc_server_handler.h"

using namespace zproto;

void ZRpcServerHandler::read(Context* ctx, PackageMessagePtr msg) {
  LOG(INFO) << "read - received data: "; // << msg;
  auto received = std::static_pointer_cast<RpcRequest>(msg);
  ctx->fireRead(received);
}

folly::Future<folly::Unit> ZRpcServerHandler::write(Context* ctx, ProtoRpcResponsePtr rsp) {
  std::unique_ptr<folly::IOBuf> out;
  rsp->SerializeToIOBuf(out);
  return ctx->fireWrite(std::move(out));
}

void ZRpcServerHandler::readEOF(Context* ctx) {
  LOG(INFO) << "readEOF - conn_id = " << conn_id_ << ", Connection closed by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();
  close(ctx);
}

void ZRpcServerHandler::readException(Context* ctx, folly::exception_wrapper e) {
  LOG(ERROR) << "readException - conn_id = " << conn_id_
            << ", Local error: " << exceptionStr(e)
            << ", by "  << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();
  close(ctx);
}

void ZRpcServerHandler::transportActive(Context* ctx) {
  auto pipeline = dynamic_cast<ZRpcServerPipeline*>(ctx->getPipeline());
  OnNewConnection(pipeline, pipeline->getTransportInfo()->remoteAddr->getAddressStr());
  
  LOG(INFO) << "transportActive - conn_id = " << conn_id_
            << ", Connection connected by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();
  
}

void ZRpcServerHandler::transportInactive(Context* ctx) {
  if (conn_state_ != ConnState::CONNECTED) {
    return;
  }
  LOG(INFO) << "transportInactive - conn_id = " << conn_id_
            << ", Connection closed by "
            << remote_address_
            << ", conn_info: " << service_->GetServiceConfig().ToString();
  
  OnConnectionClosed();
}

folly::Future<folly::Unit> ZRpcServerHandler::close(Context* ctx) {
  return ctx->fireClose();
}


