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

#include "nebula/net/handler/telegram/mtproto_message_handler.h"

#include <openssl/sha.h>
#include <folly/FileUtil.h>

#include "nebula/net/telegram/core/mtproto_message.h"
#include "nebula/net/telegram/schema.tl.h"
#include "nebula/net/telegram/core/mtproto_message_factory.h"
#include "nebula/net/handler/telegram/mtproto_object_handler.h"

// void aesIgeEncryption(uint8_t *buffer, uint8_t *key, uint8_t *iv, bool encrypt, bool changeIv, uint32_t length);

bool MTProtoMessageHandler::DecryptServerResponse(int64_t key_id, uint8_t *key, uint8_t *data, uint32_t length) {
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

void MTProtoMessageHandler::read(Context* ctx, std::unique_ptr<folly::IOBuf> msg) {
  auto buf_length = msg->computeChainDataLength();
  std::shared_ptr<MTProtoBase> mtproto;
  
  do {
    // QuickAckSize
    if (buf_length == kMTProtoQuickAckSize) {
      mtproto = std::make_shared<MTProtoQuickAck>();
      // mtproto->ParseFromIOBuf(std::move(msg));
      // break;
      // return;
    } else if (buf_length < kMTProtoMessageMinSize) {
      LOG(ERROR) << "read - need " << kMTProtoMessageMinSize << ", but only recv len: " << buf_length;
      ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - auth_key_id parser error!!!!"));
      break;
    } else {
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
      
      if (key_id == 0) {
        mtproto = std::make_shared<MTProtoUnencryptedMessage>();
      } else {
        mtproto = std::make_shared<MTProtoEncryptedMessage>();
      }
    }
    if (!mtproto->ParseFromIOBuf(std::move(msg))) {
      LOG(ERROR) << "read - read MTProto error!!!!";
      ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - MTProto parser error!!!!"));
      break;
    }
  
    LOG(INFO) << "read - " << mtproto->ToString();
    
    // folly::io::Cursor c(message.message_data.get());
    // auto class_id =c.readLE<uint32_t>();
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

    // auto mtproto = TLObjectFactory::CreateSharedInstance(class_id);
    // if (!mtproto) {
    //  LOG(ERROR) << "read - create mtproto message error, class_id = " << class_id;
    //  ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - create mtproto message error!!!!"));
    //  break;
    // }

  
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

  if (mtproto)
    ctx->fireRead(mtproto);

}

folly::Future<folly::Unit> MTProtoMessageHandler::write(Context* ctx, std::shared_ptr<MTProtoBase> out) {
  std::unique_ptr<folly::IOBuf> o;

  auto message_type = out->GetType();
  switch (message_type) {
    case MTProtoBase::QUICK_ACKID:
      o = OnWriteQuickAck(ctx, std::static_pointer_cast<MTProtoQuickAck>(out));
      break;
    case MTProtoBase::UNENCRYPTED_MESSAGE:
      o = OnWriteUnencryptedMessage(ctx, std::static_pointer_cast<MTProtoUnencryptedMessage>(out));
      break;
    case MTProtoBase::ENCRYPTED_MESSAGE:
      o = OnWriteEncryptedMessage(ctx, std::static_pointer_cast<MTProtoEncryptedMessage>(out));
      break;
    default:
      break;
  }
  
  CHECK(o) << "write - o is null";
  return ctx->fireWrite(std::move(o));

}

std::unique_ptr<folly::IOBuf> MTProtoMessageHandler::OnWriteQuickAck(Context* ctx, std::shared_ptr<MTProtoQuickAck> out) {
  std::unique_ptr<folly::IOBuf> o;
  out->SerializeToIOBuf(o);
  return o;
}

std::unique_ptr<folly::IOBuf> MTProtoMessageHandler::OnWriteUnencryptedMessage(Context* ctx, std::shared_ptr<MTProtoUnencryptedMessage> out) {
  std::unique_ptr<folly::IOBuf> o;
  out->SerializeToIOBuf(o);
  return o;
}

std::unique_ptr<folly::IOBuf> MTProtoMessageHandler::OnWriteEncryptedMessage(Context* ctx, std::shared_ptr<MTProtoEncryptedMessage> out) {
  std::unique_ptr<folly::IOBuf> o;
  //  TODO(@benqi): o不要使用链式
  out->SerializeToIOBuf(o);

  // TODO(@benqi): 填充header
#if 0
  buffer->writeInt64(getServerSalt());
  buffer->writeInt64(connection->getSissionId());
  buffer->writeInt64(messageId);
  buffer->writeInt32(messageSeqNo);
  buffer->writeInt32(messageSize);
#endif

  auto message_data_length = o->length() - 56;
  uint32_t additionalSize = (32 + message_data_length) % 16;
  if (additionalSize != 0) {
    additionalSize = 16 - additionalSize;
  }
  if (MTPROTO_VERSION == 2 && additionalSize < 12) {
    additionalSize += 16;
  }
  
  if (additionalSize != 0) {
    o->append(additionalSize);
    RAND_bytes(o->writableData() + 24 + 32 + message_data_length, additionalSize);
  }
  
  static uint8_t messageKey[96];
  switch (MTPROTO_VERSION) {
    case 2: {
      SHA256_Init(&g_sha256_ctx);
      SHA256_Update(&g_sha256_ctx, auth_key_.data + 88, 32);
      SHA256_Update(&g_sha256_ctx, o->writableData() + 24, 32 + message_data_length + additionalSize);
      SHA256_Final(messageKey, &g_sha256_ctx);
#if 0
      if (quickAckId != nullptr) {
        *quickAckId = (((messageKey[0] & 0xff)) |
                       ((messageKey[1] & 0xff) << 8) |
                       ((messageKey[2] & 0xff) << 16) |
                       ((messageKey[3] & 0xff) << 24)) & 0x7fffffff;
      }
#endif
      break;
    }
    default: {
      SHA1(o->writableData() + 24 + 24, 32 + message_data_length, messageKey + 4);
#if 0
      if (quickAckId != nullptr) {
        *quickAckId = (((messageKey[4] & 0xff)) |
                       ((messageKey[5] & 0xff) << 8) |
                       ((messageKey[6] & 0xff) << 16) |
                       ((messageKey[7] & 0xff) << 24)) & 0x7fffffff;
      }
#endif
      break;
    }
  }
  memcpy(o->writableData() + 8, messageKey + 8, 16);
  
  GenerateMessageKey(auth_key_.data, messageKey + 8, messageKey + 32, false);
  aesIgeEncryption(o->writableData() + 24, messageKey + 32, messageKey + 64, true, false, o->length() - 24);
  
  
#if 0
  int32_t mtProtoVersion = ConnectionsManager::getInstance().getMtProtoVersion();
  uint32_t messageSize = messageBody->getObjectSize();
  uint32_t additionalSize = (32 + messageSize) % 16;
  if (additionalSize != 0) {
    additionalSize = 16 - additionalSize;
  }
  if (mtProtoVersion == 2 && additionalSize < 12) {
    additionalSize += 16;
  }
  NativeByteBuffer *buffer = BuffersStorage::getInstance().getFreeBuffer(24 + 32 + messageSize + additionalSize);
  buffer->writeInt64(authKeyId);
  buffer->position(24);
  
  buffer->writeInt64(getServerSalt());
  buffer->writeInt64(connection->getSissionId());
  buffer->writeInt64(messageId);
  buffer->writeInt32(messageSeqNo);
  buffer->writeInt32(messageSize);
  messageBody->serializeToStream(buffer);
  if (freeMessageBody) {
    delete messageBody;
  }
  
  if (additionalSize != 0) {
    RAND_bytes(buffer->bytes() + 24 + 32 + messageSize, additionalSize);
  }
  static uint8_t messageKey[96];
  switch (mtProtoVersion) {
    case 2: {
      SHA256_Init(&sha256Ctx);
      SHA256_Update(&sha256Ctx, authKey->bytes + 88, 32);
      SHA256_Update(&sha256Ctx, buffer->bytes() + 24, 32 + messageSize + additionalSize);
      SHA256_Final(messageKey, &sha256Ctx);
      if (quickAckId != nullptr) {
        *quickAckId = (((messageKey[0] & 0xff)) |
                       ((messageKey[1] & 0xff) << 8) |
                       ((messageKey[2] & 0xff) << 16) |
                       ((messageKey[3] & 0xff) << 24)) & 0x7fffffff;
      }
      break;
    }
    default: {
      SHA1(buffer->bytes() + 24, 32 + messageSize, messageKey + 4);
      if (quickAckId != nullptr) {
        *quickAckId = (((messageKey[4] & 0xff)) |
                       ((messageKey[5] & 0xff) << 8) |
                       ((messageKey[6] & 0xff) << 16) |
                       ((messageKey[7] & 0xff) << 24)) & 0x7fffffff;
      }
      break;
    }
  }
  memcpy(buffer->bytes() + 8, messageKey + 8, 16);
  
  generateMessageKey(authKey->bytes, messageKey + 8, messageKey + 32, false);
  aesIgeEncryption(buffer->bytes() + 24, messageKey + 32, messageKey + 64, true, false, o->length() - 24);
#endif

  return o;
}
