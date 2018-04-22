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

#ifndef PROTO_MTPROTO_CORE_MTPROTO_MESSAGE_H_
#define PROTO_MTPROTO_CORE_MTPROTO_MESSAGE_H_

#include <glog/logging.h>
#include <folly/Format.h>

#include "nebula/base/io_buf_util.h"
#include "nebula/base/crypto_util/crypto_util.h"

#include "proto/mtproto/core/tl_object.h"

namespace mtproto {
  
const size_t kMTProtoQuickAckSize = 4;
const size_t kMTProtoMessageMinSize = 8;
const size_t kMTProtoUnEncryptedHeaderSize = 20;
const size_t kMTProtoEncryptedHeaderSize = 56;

struct MTProtoBase {
  enum MTProtoMessageType {
    UNKNOWN = 0,
    QUICK_ACKID,
    UNENCRYPTED_MESSAGE,
    ENCRYPTED_MESSAGE,
  };
  
  virtual ~MTProtoBase() = default;
  virtual int GetType() const = 0;
  
  // TLObject序列化和反序列化
  virtual bool ParseFromIOBuf(std::unique_ptr<folly::IOBuf> io_buf) = 0;
  bool SerializeToIOBuf(std::unique_ptr<folly::IOBuf>& io_buf) const;

  virtual bool Encode(IOBufWriter& iobw) const = 0;

  virtual std::string ToString() const {
    return "";
  }
  
  virtual folly::IOBuf* GetMessageData() { return nullptr; }
};

/////////////////////////////////////////////////////////////////////////////////////////////////
struct MTProtoQuickAck : public MTProtoBase {
  // enum { QUICK_ACK_SIZE = 4, };

  int GetType() const override {
    return QUICK_ACKID;
  }

  bool ParseFromIOBuf(std::unique_ptr<folly::IOBuf> io_buf) override {
    folly::io::Cursor c(io_buf.get());
    ack_id = c.readLE<uint32_t>();
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    iobw.writeLE(ack_id);
    return true;
  }

  uint32_t ack_id;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
struct MTProtoUnencryptedMessage : public MTProtoBase {
  // enum { HEADER_SIZE = 20, };
  MTProtoUnencryptedMessage() = default;
  explicit MTProtoUnencryptedMessage(std::shared_ptr<TLObject> o);
  
  int GetType() const override {
    return UNENCRYPTED_MESSAGE;
  }
  
  bool ParseFromIOBuf(std::unique_ptr<folly::IOBuf> io_buf) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return folly::sformat("{{auth_key_id: {}, message_id: {}, message_data_length: {}, message_data: {}}}",
                          auth_key_id,
                          message_id,
                          message_data_length,
                          message_data ? ToHexStr(folly::ByteRange(message_data->data(), message_data->length())) : "nil");
  }

  folly::IOBuf* GetMessageData() override { return message_data.get(); }

  uint32_t GetClassID() const {
    return class_id;
  }
  
  int64_t auth_key_id {0};          // 8
  int64_t message_id {0};           // 8
  int32_t message_data_length {0};  // 4
  std::unique_ptr<folly::IOBuf> message_data;
  
private:
  TLClassID class_id {0};
};

/////////////////////////////////////////////////////////////////////////////////////////////////
struct MTProtoEncryptedMessage : public MTProtoBase {
  // enum { HEADER_SIZE = 56, };
  // MTProtoEncryptedMessage(const MTProtoEncryptedMessage& o);
  MTProtoEncryptedMessage(std::shared_ptr<TLInt2048> auth_key, int64_t key_id);
  
  MTProtoEncryptedMessage(std::shared_ptr<TLInt2048> auth_key,
       int64_t _auth_key_id,
       int64_t _session_id,
       int32_t _seq_no,
       std::shared_ptr<TLObject> o);

  MTProtoEncryptedMessage(std::shared_ptr<TLInt2048> auth_key,
       int64_t _auth_key_id,
       int64_t _session_id,
       int32_t _seq_no,
       uint32_t _class_id,
       std::unique_ptr<folly::IOBuf>& o);


  int GetType() const override {
    return ENCRYPTED_MESSAGE;
  }
  
  bool ParseFromIOBuf(std::unique_ptr<folly::IOBuf> io_buf) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return folly::sformat("{{auth_key_id: {}, msg_key: {}, salt: {}, session_id: {}, message_id: {}, seq_no: {}, message_data_length: {}, message_data: {}}}",
                          auth_key_id,
                          ToHexStr(folly::ByteRange(msg_key, 16)),
                          salt,
                          session_id,
                          message_id,
                          seq_no,
                          message_data_length,
                          message_data ? ToHexStr(folly::ByteRange(message_data->data(), message_data->length())) : "nil");
  }
  
  folly::IOBuf* GetMessageData() override { return message_data.get(); }

  uint32_t GetClassID() const {
    return class_id;
  }

  int64_t auth_key_id {-1};         // 8
  uint8_t msg_key[16];              // 16
  int64_t salt {0};                 // 8
  int64_t session_id {0};           // 8
  int64_t message_id {0};           // 8
  int32_t seq_no {0};               // 4
  int32_t message_data_length {0};  // 4
  std::unique_ptr<folly::IOBuf> message_data;
  
  std::shared_ptr<TLInt2048> auth_key;
  
private:
  TLClassID class_id {0};
};
  
}

#endif
