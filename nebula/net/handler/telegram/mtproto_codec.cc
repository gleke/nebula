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

#include "nebula/net/handler/telegram/mtproto_codec.h"

#include <openssl/sha.h>
#include <folly/FileUtil.h>

#include "nebula/net/telegram/core/mtproto_message.h"
#include "nebula/net//telegram/schema.tl.h"
#include "nebula/net//telegram/core/mtproto_message_factory.h"
#include "nebula/net/handler/telegram/telegram_handler.h"

static int MTPROTO_VERSION = 2;
static SHA256_CTX g_sha256_ctx;

inline void GenerateMessageKey(uint8_t *auth_key, uint8_t *message_key, uint8_t *result, bool incoming) {
  uint32_t x = incoming ? 8 : 0;
  uint8_t sha[68];
  switch (MTPROTO_VERSION) {
    case 2:
      SHA256_Init(&g_sha256_ctx);
      SHA256_Update(&g_sha256_ctx, message_key, 16);
      SHA256_Update(&g_sha256_ctx, auth_key + x, 36);
      SHA256_Final(sha, &g_sha256_ctx);
      
      SHA256_Init(&g_sha256_ctx);
      SHA256_Update(&g_sha256_ctx, auth_key + 40 + x, 36);
      SHA256_Update(&g_sha256_ctx, message_key, 16);
      SHA256_Final(sha + 32, &g_sha256_ctx);
      
      memcpy(result, sha, 8);
      memcpy(result + 8, sha + 32 + 8, 16);
      memcpy(result + 8 + 16, sha + 24, 8);
      
      memcpy(result + 32, sha + 32, 8);
      memcpy(result + 32 + 8, sha + 8, 16);
      memcpy(result + 32 + 8 + 16, sha + 32 + 24, 8);
      break;
    default:
      memcpy(sha + 20, message_key, 16);
      memcpy(sha + 20 + 16, message_key + x, 32);
      SHA1(sha + 20, 48, sha);
      memcpy(result, sha, 8);
      memcpy(result + 32, sha + 8, 12);
      
      memcpy(sha + 20, message_key + 32 + x, 16);
      memcpy(sha + 20 + 16, message_key, 16);
      memcpy(sha + 20 + 16 + 16, message_key + 48 + x, 16);
      SHA1(sha + 20, 48, sha);
      memcpy(result + 8, sha + 8, 12);
      memcpy(result + 32 + 12, sha, 8);
      
      memcpy(sha + 20, message_key + 64 + x, 32);
      memcpy(sha + 20 + 32, message_key, 16);
      SHA1(sha + 20, 48, sha);
      memcpy(result + 8 + 12, sha + 4, 12);
      memcpy(result + 32 + 12 + 8, sha + 16, 4);
      
      memcpy(sha + 20, message_key, 16);
      memcpy(sha + 20 + 16, message_key + 96 + x, 32);
      SHA1(sha + 20, 48, sha);
      memcpy(result + 32 + 12 + 8 + 4, sha, 8);
      break;
  }
}

void aesIgeEncryption(uint8_t *buffer, uint8_t *key, uint8_t *iv, bool encrypt, bool changeIv, uint32_t length);

bool MTProtoDecoder::DecryptServerResponse(int64_t key_id, uint8_t *key, uint8_t *data, uint32_t length) {
  bool error = false;
  if (auth_key_id_ != key_id) {
    error = true;
  }
  uint8_t message_key[96];
  GenerateMessageKey(auth_key_.data, key, message_key + 32, false);
  LOG(INFO) << "message_key: " << ToHexStr(folly::ByteRange(message_key, 96));
  
  aesIgeEncryption(data, message_key + 32, message_key + 64, false, false, length);
  
  uint32_t messageLength;
  memcpy(&messageLength, data + 28, sizeof(uint32_t));
  if (messageLength > length - 32) {
    error = true;
  }
  messageLength += 32;
  if (messageLength > length) {
    messageLength = length;
  }
  
  switch (MTPROTO_VERSION) {
    case 2: {
      SHA256_Init(&g_sha256_ctx);
      SHA256_Update(&g_sha256_ctx, auth_key_.data + 88 + 8, 32);
      SHA256_Update(&g_sha256_ctx, data, length);
      SHA256_Final(message_key, &g_sha256_ctx);
      break;
    }
    default: {
      SHA1(data, messageLength, message_key + 4);
      break;
    }
  }
  
  return memcmp(message_key + 8, key, 16) == 0 && !error;
}

void MTProtoDecoder::read(Context* ctx, std::unique_ptr<folly::IOBuf> msg) {
  auto buf_length = msg->computeChainDataLength();
  do {
    if (buf_length < kMTProtoMinSize) {
      LOG(ERROR) << "read - need " << kMTProtoMinSize << ", but only recv len: " << buf_length;
      ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - auth_key_id parser error!!!!"));
      break;
    }
    
    folly::io::Cursor c2(msg.get());
    int64_t key_id = c2.readLE<int64_t>();
    if (key_id != 0) {
      if (!loaded_) {
        folly::fbstring auth_key_data;
        if(!folly::readFile("./auth_key.dat", auth_key_data)) {
          LOG(ERROR) << "import - Unable to open ./auth_key.dat";
          // << path;
          break;
        }
        auth_key_.Copy((uint8_t*)auth_key_data.data());
        memcpy(&auth_key_id_, auth_key_data.data()+256, 8);
        loaded_ = true;
        // return json_data.toStdString();
      }
      // const auto& tmp = ctx->getPipeline()->getHandler<TelegramHandler>()->GetAuthKey();
      // auth_key_.Copy(tmp);
      // auth_key_id_ = ctx->getPipeline()->getHandler<TelegramHandler>()->GetAuthKeyID();
      
      DecryptServerResponse(key_id, msg->writableData()+8, msg->writableData()+24, msg->length()-24);
    }
    
    MTProtoMessageData message;
    if (!message.Decode(std::move(msg))) {
      LOG(ERROR) << "read - read MTProtoMessageData error!!!!";
      ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - MTProtoMessageData parser error!!!!"));
      break;
    }
  
    folly::io::Cursor c(message.message_data.get());
    auto class_id =c.readLE<uint32_t>();
/*
    LOG(INFO) << "class_id --> " << std::hex << class_id;
    auto class_id2 =c.readLE<uint32_t>();
    LOG(INFO) << "class_id --> " << std::hex << class_id2;
    auto count =c.readLE<uint32_t>();
    LOG(INFO) << "class_id --> " << std::hex << count;
 
    std::shared_ptr<MTProtoBase> mtproto;
    
    switch(class_id) {
      case TL_req_pq::CLASS_ID:
        LOG(INFO) << "TL_msgs_ack";
        mtproto = make_mtproto<TL_req_pq>();
        break;
      case TL_msgs_ack::CLASS_ID:
        LOG(INFO) << "TL_msgs_ack";
        mtproto = make_mtproto<TL_msgs_ack>();
        break;
      case TL_req_DH_params::CLASS_ID:
        LOG(INFO) << "TL_req_DH_params";
        mtproto = make_mtproto<TL_req_DH_params>();
        break;
      case TL_set_client_DH_params::CLASS_ID:
        LOG(INFO) << "TL_set_client_DH_params";
        mtproto = make_mtproto<TL_set_client_DH_params>();
        break;
      case TL_msg_container::CLASS_ID:
        LOG(INFO) << "TL_msg_container";
        mtproto = make_mtproto<TL_msg_container>();
        break;
      case TL_destroy_session::CLASS_ID:
        LOG(INFO) << "TL_destroy_session";
        mtproto = make_mtproto<TL_destroy_session>();
        break;
      default:
        LOG(INFO) << "unknown's class_id: " << std::hex << class_id;
        break;
    }
 
    auto mtproto = TLObjectFactory::CreateSharedInstance(class_id);
    if (mtproto) {
      if (mtproto->Decode(message)) {
        ctx->fireRead(mtproto);
      } else {
        //      LOG(ERROR) << "read - create mtproto message error, class_id = " << class_id;
        //      ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - create mtproto message error!!!!"));
      }
    }
*/

    auto mtproto = TLObjectFactory::CreateSharedInstance(class_id);
    if (!mtproto) {
      LOG(ERROR) << "read - create mtproto message error, class_id = " << class_id;
      ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - create mtproto message error!!!!"));
      break;
    }

    ctx->fireRead(mtproto);
  
/*
    folly::io::Cursor c(msg.get());
    int64_t auth_key_id = c.readBE<int64_t>();
    if (auth_key_id != 0) {
      if (buf_length < kMTProtoUnEncryptedHeaderSize) {
        LOG(ERROR) << "read - read Unencrypted Message's header, need " << kMTProtoUnEncryptedHeaderSize
                      << ", but only recv len: " << buf_length;
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - Unencrypted Message's header parser error!!!!"));
        break;
      }
      
      MTProtoMessageData message;
      message.set_auth_key_id(auth_key_id);
      // auto message = BaseMTProtoMessage::make_unique();
      if (!message.message.unencrypted.Decode(std::move(msg))) {
        LOG(ERROR) << "read - ";
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - Unencrypted Message's parser error!!!!"));
      }
      
      c.reset(message.message.unencrypted.message_data.get());
      std::shared_ptr<MTProtoBase> mt_proto;
      auto class_id =c.read<uint32_t>();
      if (class_id == TL_req_pq::CLASS_ID) {
        mt_proto = std::make_shared<MTProto<TL_req_pq>>();
        mt_proto->Decode(message);
      }
      ctx->fireRead(mt_proto);
    } else {
      if (buf_length < kMTProtoEncryptedHeaderSize) {
        LOG(ERROR) << "read - read Encrypted Message's header, need " << kMTProtoEncryptedHeaderSize
                    << ", but only recv len: " << buf_length;
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - Encrypted Message's header parser error!!!!"));
        break;
      }

      MTProtoMessageData message;
      message.set_auth_key_id(auth_key_id);

      if (!message.message.encrypted.Decode(std::move(msg))) {
        LOG(ERROR) << "read - ";
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - Encrypted Message's parser error!!!!"));
        break;
      }
      
      c.reset(message.message.encrypted.message_data.get());
      
      std::shared_ptr<MTProtoBase> mt_proto;
      auto class_id =c.read<uint32_t>();
      if (class_id == TL_req_pq::CLASS_ID) {
        mt_proto = std::make_shared<MTProto<TL_req_pq>>();
        mt_proto->Decode(message);
      }
      
      ctx->fireRead(mt_proto);
    }
 */
  } while (0);
}

