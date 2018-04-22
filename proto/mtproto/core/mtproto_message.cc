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

#include "proto/mtproto/core/mtproto_message.h"

#include <openssl/sha.h>
#include "nebula/base/io_buf_util.h"

using namespace mtproto;

/*
 // Unencrypted Message
 
 | auth_key_id = 0 | message_id | message_data_length | message_data |
 |     int64       |   int64	  |         int32	      |     bytes    |
 
 // 8+8+4 = 20
 
 Encrypted Message
 
 | auth_key_id | msg_key | encrypted_data |
 |    int64    | int128  |     bytes      |
 
 Encrypted Message: encrypted_data
 Contains the cypher text for the following data:
 
 | salt  | session_id | message_id | seq_no | message_data_length | message_data | padding 0..15  |
 | int64	| int64      | int64      | int32  |int32                | bytes        | bytes         |
 
 // 8+16+8+8+8+8 = 56
 */
//std::shared_ptr<BaseMTProtoMessage> BaseMTProtoMessage::make_shared(bool is_encrypted) {
//  // BaseMTProtoMessage* mtproto = nullptr;
//  if (is_encrypted) {
//    return std::make_shared<MTProtoEncrypted>();
//  } else {
//    return std::make_shared<MTProtoUnencrypted>();
//  }
//}
//
//std::unique_ptr<BaseMTProtoMessage> BaseMTProtoMessage::make_unique(bool is_encrypted) {
//  // BaseMTProtoMessage* mtproto = nullptr;
//  if (is_encrypted) {
//    return folly::make_unique<MTProtoEncrypted>();
//  } else {
//    return folly::make_unique<MTProtoUnencrypted>();
//  }
//}

// static MTProtoBase* CreateQuickAck(int type);


int64_t getCurrentTimeMillis() {
  timespec time_spec;
  clock_gettime(CLOCK_REALTIME, &time_spec);
  return (int64_t) time_spec.tv_sec * 1000 + (int64_t) time_spec.tv_nsec / 1000000;
}

int64_t getCurrentTimeMonotonicMillis() {
  timespec time_spec_monotonic;
  clock_gettime(CLOCK_MONOTONIC, &time_spec_monotonic);
  return (int64_t) time_spec_monotonic.tv_sec * 1000 + (int64_t) time_spec_monotonic.tv_nsec / 1000000;
}

inline int64_t GetMessageID_1() {
  int64_t message_id = (int64_t) (((double) getCurrentTimeMillis() * 4294967296.0) / 1000.0);
  
  // 保证 mod % 4 = 1
  while ((message_id % 4) != 1) {
    ++message_id;
  }
  return message_id;
}

inline int64_t GetMessageID_3() {
  int64_t message_id = (int64_t) (((double) getCurrentTimeMillis() * 4294967296.0) / 1000.0);
  while ((message_id % 4) != 3) {
    ++message_id;
  }
  return message_id;
}

static int MTPROTO_VERSION = 2;
static SHA256_CTX g_sha256_ctx;

inline void GenerateMessageKey(const uint8_t *auth_key, uint8_t *message_key, uint8_t *result, bool incoming) {
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

bool DecryptEncryptedMessage(const TLInt2048& auth_key, int64_t key_id, uint8_t *key, uint8_t *data, uint32_t length) {
  bool error = false;
  
//  if (auth_key_id_ != key_id) {
//    error = true;
//  }
  
  uint8_t message_key[96];
  GenerateMessageKey(auth_key.data, key, message_key + 32, false);
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
      SHA256_Update(&g_sha256_ctx, auth_key.data + 88 + 8, 32);
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

//uint32_t generateMessageSeqNo(bool increment) {
//  uint32_t value = nextSeqNo;
//  if (increment) {
//    nextSeqNo++;
//  }
//  return value * 2 + (increment ? 1 : 0);
//}

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace mtproto {
  
bool MTProtoBase::SerializeToIOBuf(std::unique_ptr<folly::IOBuf>& io_buf) const {
  bool rv = true;
  auto io_buf2 = folly::IOBuf::create(2048);
  IOBufWriter iobw(io_buf2.get(), 2048);
  try {
    rv = Encode(iobw);
    if (rv) {
      io_buf = std::move(io_buf2);
    }
  } catch(const std::exception& e) {
    LOG(ERROR) << "SerializeToIOBuf - catch a threwn exception: " << folly::exceptionStr(e);
    rv = false;
  } catch (...) {
    LOG(ERROR) << "SerializeToIOBuf - catch a unknown threwn exception";
    rv = false;
  }
  return rv;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
MTProtoUnencryptedMessage::MTProtoUnencryptedMessage(std::shared_ptr<TLObject> o) {
  auth_key_id = 0;
  message_id = GetMessageID_1();
  message_data = std::make_unique<folly::IOBuf>();
  o->SerializeToIOBuf(message_data);
  message_data_length = message_data->length();
  
  class_id = o->GetClassID();
}

bool MTProtoUnencryptedMessage::ParseFromIOBuf(std::unique_ptr<folly::IOBuf> io_buf) {
  folly::io::Cursor c(io_buf.get());
  
  auth_key_id = c.readLE<int64_t>();
  message_id = c.readLE<int64_t>();
  message_data_length = c.readLE<int32_t>();

  class_id = c.readLE<uint32_t>();

  message_data.swap(io_buf);
  nebula::io_buf_util::TrimStart(message_data.get(), kMTProtoUnEncryptedHeaderSize);
  return true;
}

bool MTProtoUnencryptedMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(auth_key_id);
  iobw.writeLE(message_id);
  iobw.writeLE(message_data_length);
  
  folly::io::Cursor c(message_data.get());
  iobw.push(c, static_cast<uint32_t>(message_data->computeChainDataLength()));
  
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
MTProtoEncryptedMessage::MTProtoEncryptedMessage(std::shared_ptr<TLInt2048> _auth_key,
                                                 int64_t _auth_key_id,
                                                 int64_t _session_id,
                                                 int32_t _seq_no,
                                                 std::shared_ptr<TLObject> o)
  : auth_key(_auth_key) {

  auth_key_id = _auth_key_id;
  session_id = _session_id;
  message_id = GetMessageID_1();
  seq_no = _seq_no;
  // message_data = std::make_unique<folly::IOBuf>();
  o->SerializeToIOBuf(message_data);
  message_data_length = message_data->length();
    
  class_id = o->GetClassID();
}

MTProtoEncryptedMessage::MTProtoEncryptedMessage(std::shared_ptr<TLInt2048> _auth_key,
                                                 int64_t _auth_key_id,
                                                 int64_t _session_id,
                                                 int32_t _seq_no,
                                                 uint32_t _class_id,
                                                 std::unique_ptr<folly::IOBuf>& o)
  : auth_key(_auth_key) {
  
  auth_key_id = _auth_key_id;
  session_id = _session_id;
  message_id = GetMessageID_1();
  seq_no = _seq_no;
  class_id = _class_id;
  message_data.swap(o);
  message_data_length = message_data->length();
}

MTProtoEncryptedMessage::MTProtoEncryptedMessage(std::shared_ptr<TLInt2048> _auth_key, int64_t _auth_key_id)
  : auth_key(_auth_key) {
  
  auth_key_id = _auth_key_id;
  //  message.unencrypted.auth_key_id = -1;
  //  message.unencrypted.message_id = GetMessageID_1();
  //  message_data = std::make_unique<folly::IOBuf>();
  //  o->SerializeToIOBuf(message_data);
}

bool MTProtoEncryptedMessage::ParseFromIOBuf(std::unique_ptr<folly::IOBuf> io_buf) {
  folly::io::Cursor c(io_buf.get());
  
  auth_key_id = c.readLE<int64_t>();
  
  io_buf->coalesce();
  // 解密
  ::DecryptEncryptedMessage(*auth_key, auth_key_id, io_buf->writableData()+8, io_buf->writableData()+24, io_buf->length()-24);
  // ::DecryptEncryptedMessage(*auth_key, auth_key_id, buf.data()+8, buf.data()+24, buf.size()-24);

  c.pull(msg_key, 16);
  salt = c.readLE<int64_t>();
  session_id = c.readLE<int64_t>();
  message_id = c.readLE<int64_t>();
  seq_no = c.readLE<int32_t>();
  message_data_length = c.readLE<int32_t>();
  
  class_id = c.readLE<uint32_t>();
  message_data.swap(io_buf);
  nebula::io_buf_util::TrimStart(message_data.get(), kMTProtoEncryptedHeaderSize);
  
  return true;
}

bool MTProtoEncryptedMessage::Encode(IOBufWriter& iobw) const {
  uint32_t additional_size = (32 + message_data_length) % 16;
  if (additional_size != 0) {
    additional_size = 16 - additional_size;
  }
  if (MTPROTO_VERSION == 2 && additional_size < 12) {
    additional_size += 16;
  }

  // 保存写的位置
  auto p_data = iobw.writableData();

  iobw.writeLE(auth_key_id);
  iobw.push(msg_key, 16);
  iobw.writeLE(salt);
  iobw.writeLE(session_id);
  iobw.writeLE(message_id);
  iobw.writeLE(seq_no);
  iobw.writeLE(message_data_length);
  message_data->append(additional_size);
  RAND_bytes(p_data + 56 + message_data_length, additional_size);
  
  folly::io::Cursor c(message_data.get());
  iobw.push(c, static_cast<uint32_t>(message_data->computeChainDataLength()));

  uint8_t message_key[96];
  switch (MTPROTO_VERSION) {
    case 2: {
      SHA256_Init(&g_sha256_ctx);
      SHA256_Update(&g_sha256_ctx, auth_key->data + 88 + 8, 32);
      SHA256_Update(&g_sha256_ctx, p_data + 24, 32 + message_data_length + additional_size);
      SHA256_Final(message_key, &g_sha256_ctx);
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
      SHA1(p_data + 24, 32 + message_data_length + additional_size, message_key + 4);
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
  memcpy(p_data + 8, message_key + 8, 16);
  
  GenerateMessageKey(auth_key->data, message_key + 8, message_key + 32, true);
  aesIgeEncryption(p_data + 24, message_key + 32, message_key + 64, true, false, 32+message_data_length+additional_size);
  
  return true;
}

}

