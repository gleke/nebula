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

#include "nebula/net/handler/zproto/zproto_package_handler.h"

#include "nebula/base/func_factory_manager.h"

using namespace zproto;
///////////////////////////////////////////////////////////////////////////////////////
// 初始化
// Package
typedef void(ZProtoPackageHandler::*ExecPackageHandler)(ZProtoPackageHandler::Context*, std::shared_ptr<PackageMessage>);
typedef nebula::FuncFactoryManager<ExecPackageHandler, uint8_t> ExecPackageHandlerFactory;
#define REGISTER_EXECUTE_PACKAGE_HANDLER(T) \
  static ExecPackageHandlerFactory::RegisterTemplate g_reg_package_handler_##T(T::HEADER, &ZProtoPackageHandler::On##T)
//


REGISTER_EXECUTE_PACKAGE_HANDLER(AuthIdInvalid);
REGISTER_EXECUTE_PACKAGE_HANDLER(RequestAuthId);
REGISTER_EXECUTE_PACKAGE_HANDLER(ResponseAuthId);
REGISTER_EXECUTE_PACKAGE_HANDLER(RequestStartAuth);
REGISTER_EXECUTE_PACKAGE_HANDLER(ResponseStartAuth);
REGISTER_EXECUTE_PACKAGE_HANDLER(RequestGetServerKey);
REGISTER_EXECUTE_PACKAGE_HANDLER(ResponseGetServerKey);
REGISTER_EXECUTE_PACKAGE_HANDLER(RequestDH);
REGISTER_EXECUTE_PACKAGE_HANDLER(ResponseDoDH);

// REGISTER_EXECUTE_PACKAGE_HANDLER(AttachDataMessage);
REGISTER_EXECUTE_PACKAGE_HANDLER(Container);

REGISTER_EXECUTE_PACKAGE_HANDLER(RpcRequest);
REGISTER_EXECUTE_PACKAGE_HANDLER(RpcOk);
REGISTER_EXECUTE_PACKAGE_HANDLER(RpcError);
REGISTER_EXECUTE_PACKAGE_HANDLER(RpcFloodWait);
REGISTER_EXECUTE_PACKAGE_HANDLER(RpcInternalError);

REGISTER_EXECUTE_PACKAGE_HANDLER(Push);
REGISTER_EXECUTE_PACKAGE_HANDLER(MessageAck);

REGISTER_EXECUTE_PACKAGE_HANDLER(UnsentMessage);
REGISTER_EXECUTE_PACKAGE_HANDLER(UnsentResponse);
REGISTER_EXECUTE_PACKAGE_HANDLER(RequestResend);

REGISTER_EXECUTE_PACKAGE_HANDLER(NewSession);
REGISTER_EXECUTE_PACKAGE_HANDLER(SessionHello);
REGISTER_EXECUTE_PACKAGE_HANDLER(SessionLost);

////////////////////////////////////////////////////////////////////////////////////////////////////////
void ZProtoPackageHandler::read(Context* ctx, std::shared_ptr<ProtoRawData> msg) {
  Package package;
  if (!package.Decode(*msg)) {
    LOG(ERROR) << "read - decode proto_raw_data error";
    
    ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("ZProtoPackageHandler - Decode package error"));
    return;
  }
  
  // if (package.message_header)
  auto message_data = PackageFactory::CreateSharedInstance(package.package_type);
  
  if (!message_data || !message_data->Decode(package)) {
    LOG(ERROR) << "read - decode package_message error!!";
    ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("ZProtoPackageHandler - Decode package_message error"));
    return;
  }
  
  ctx->fireRead(message_data);

  // ExecPackageHandlerFactory::Execute2<ZProtoPackageHandler>(this, package.package_type, ctx, message_data);
}

////////////////////////////////////////////////////////////////////////////
void ZProtoPackageHandler::OnAuthIdInvalid(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnRequestAuthId(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnResponseAuthId(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnRequestStartAuth(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnResponseStartAuth(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnRequestGetServerKey(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnResponseGetServerKey(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnRequestDH(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnResponseDoDH(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}


////////////////////////////////////////////////////////////////////////////
void ZProtoPackageHandler::OnAttachDataMessage(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnContainer(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

////////////////////////////////////////////////////////////////////////////
void ZProtoPackageHandler::OnRpcRequest(Context* ctx, std::shared_ptr<PackageMessage> message) {
  ctx->fireRead(message);
}

void ZProtoPackageHandler::OnRpcOk(Context* ctx, std::shared_ptr<PackageMessage> message) {
  ctx->fireRead(message);
}

void ZProtoPackageHandler::OnRpcError(Context* ctx, std::shared_ptr<PackageMessage> message) {
  ctx->fireRead(message);
}

void ZProtoPackageHandler::OnRpcFloodWait(Context* ctx, std::shared_ptr<PackageMessage> message) {
  ctx->fireRead(message);
}

void ZProtoPackageHandler::OnRpcInternalError(Context* ctx, std::shared_ptr<PackageMessage> message) {
  ctx->fireRead(message);
}


////////////////////////////////////////////////////////////////////////////
void ZProtoPackageHandler::OnPush(Context* ctx, std::shared_ptr<PackageMessage> message) {
  ctx->fireRead(message);
}

void ZProtoPackageHandler::OnMessageAck(Context* ctx, std::shared_ptr<PackageMessage> message) {
  ctx->fireRead(message);
}

////////////////////////////////////////////////////////////////////////////
void ZProtoPackageHandler::OnUnsentMessage(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnUnsentResponse(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnRequestResend(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

////////////////////////////////////////////////////////////////////////////
void ZProtoPackageHandler::OnNewSession(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnSessionHello(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

void ZProtoPackageHandler::OnSessionLost(Context* ctx, std::shared_ptr<PackageMessage> message) {
  
}

