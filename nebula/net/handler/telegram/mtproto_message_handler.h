/*
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula
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

#ifndef NET_TELEGRAM_MTPROTO_MESSAGE_HANDLER_H_
#define NET_TELEGRAM_MTPROTO_MESSAGE_HANDLER_H_

#include <wangle/channel/Handler.h>
#include "nebula/net/telegram/core/mtproto_message.h"

// using BytesToMTProtoMessage = wangle::InboundHandler<std::unique_ptr<folly::IOBuf>, std::shared_ptr<MTProtoBase>>;

class MTProtoMessageHandler : public wangle::Handler<
      std::unique_ptr<folly::IOBuf>, std::shared_ptr<MTProtoBase>,
      std::shared_ptr<MTProtoBase>, std::unique_ptr<folly::IOBuf>
  >
{
public:
  MTProtoMessageHandler() = default;
  ~MTProtoMessageHandler() override = default;
  
  //////////////////////////////////////////////////////////////////////////
  void read(Context* ctx, std::unique_ptr<folly::IOBuf> msg) override;
  folly::Future<folly::Unit> write(Context* ctx, std::shared_ptr<MTProtoBase> out) override;

private:
  bool DecryptServerResponse(int64_t key_id, uint8_t *key, uint8_t *data, uint32_t length);

  std::unique_ptr<folly::IOBuf> OnWriteQuickAck(Context* ctx, std::shared_ptr<MTProtoQuickAck> out);
  std::unique_ptr<folly::IOBuf> OnWriteUnencryptedMessage(Context* ctx, std::shared_ptr<MTProtoUnencryptedMessage> out);
  std::unique_ptr<folly::IOBuf> OnWriteEncryptedMessage(Context* ctx, std::shared_ptr<MTProtoEncryptedMessage> out);
  
  bool loaded_ {false};
  TLInt2048 auth_key_;
  int64_t auth_key_id_ {0};
};

#endif

