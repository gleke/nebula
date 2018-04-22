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

#ifndef NUBULA_NET_HANDLER_ZPROTO_ZPROTO_PACKAGE_HANDLER_H_
#define NUBULA_NET_HANDLER_ZPROTO_ZPROTO_PACKAGE_HANDLER_H_

#include <wangle/channel/Handler.h>

#include "nebula/net/zproto/zproto_package_data.h"

// Transport Level处理器
class ZProtoPackageHandler : public wangle::Handler<std::shared_ptr<zproto::ProtoRawData>, std::shared_ptr<zproto::PackageMessage>,
              std::unique_ptr<folly::IOBuf>, std::unique_ptr<folly::IOBuf>>
{
public:
  ZProtoPackageHandler() = default;
  
  void read(Context* ctx, std::shared_ptr<zproto::ProtoRawData> msg) override;
  
  folly::Future<folly::Unit> write(Context* ctx, std::unique_ptr<folly::IOBuf> msg) override {
    return ctx->fireWrite(std::forward<std::unique_ptr<folly::IOBuf>>(msg));
  }

  ////////////////////////////////////////////////////////////////////////////
  // Auth
  void OnAuthIdInvalid(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRequestAuthId(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnResponseAuthId(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRequestStartAuth(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnResponseStartAuth(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRequestGetServerKey(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnResponseGetServerKey(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRequestDH(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnResponseDoDH(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);

  ////////////////////////////////////////////////////////////////////////////
  // Pack
  void OnAttachDataMessage(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnContainer(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);

  ////////////////////////////////////////////////////////////////////////////
  // Sync
  void OnRpcRequest(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRpcOk(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRpcError(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRpcFloodWait(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRpcInternalError(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);

  ////////////////////////////////////////////////////////////////////////////
  void OnPush(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnMessageAck(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);

  ////////////////////////////////////////////////////////////////////////////
  // resend
  void OnUnsentMessage(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnUnsentResponse(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnRequestResend(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);

  ////////////////////////////////////////////////////////////////////////////
  // session
  void OnNewSession(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnSessionHello(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
  void OnSessionLost(Context* ctx, std::shared_ptr<zproto::PackageMessage> message);
};

#endif
