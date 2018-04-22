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

#ifndef NUBULA_NET_ZPROTO_ZPROTO_FRAME_DATA_H_
#define NUBULA_NET_ZPROTO_ZPROTO_FRAME_DATA_H_

#include <string.h>
#include <list>
#include <map>

#include "nebula/base/io_buf_util.h"
#include "nebula/base/self_register_factory_manager.h"

//////////////////////////////////////////////////////////////////////
namespace zproto {
  
// 数据包体最大长度
#define MAX_FRAME_BODY_LEN 1024*1024 // 1MB

#define SIZEOF_STRING(s) (sizeof(uint32_t)+static_cast<uint32_t>((s).length()))
#define SIZEOF_IOBUF(b) (b ? static_cast<uint32_t>(b->computeChainDataLength()) : 0)

#define MAGIC_NUMBER 0x5342 //

#define CAST_PROTO_MESSAGE(MESSAGE, value) \
  auto value = std::static_pointer_cast<MESSAGE>(message); \
  if (!value) { \
    LOG(ERROR) << "recv a valid " << #MESSAGE << " data."; \
    return; \
  }

// 最后写
inline void WriteFrameIndex(uint16_t frame_index, folly::IOBuf* io_buf) {
  // uint32_t w = (uint32_t)(MAGIC_NUMBER << 16 | frame_index);
  auto i = folly::Endian::big(frame_index);
  memcpy(io_buf->writableData() + 6, &i, sizeof(i));
}

inline void WriteBodyLength(uint32_t buf_len, folly::IOBuf* io_buf) {
  uint32_t l = folly::Endian::big(buf_len);
  memcpy(io_buf->writableData() + 16, &l, sizeof(l));
}

inline void WriteIOBuf(IOBufWriter& iobw, const folly::IOBuf* io_buf) {
  folly::io::Cursor c(io_buf);
  iobw.push(c, static_cast<uint32_t>(io_buf->computeChainDataLength()));
}

inline void WriteString(IOBufWriter& iobw, const std::string& s) {
  iobw.writeBE(static_cast<uint32_t>(s.length()));
  iobw.push(reinterpret_cast<const uint8_t*>(s.data()), s.length());
}

inline void ReadString(folly::io::Cursor& c, std::string& v) {
  uint32_t l = c.readBE<uint32_t>();
  v = c.readFixedString(l);
}

void ReadMapStringString(folly::io::Cursor& c, std::map<std::string, std::string>& maps);
void WriteMapStringString(IOBufWriter& iobw, const std::map<std::string, std::string>& maps);

// Connection Level
struct Frame {
  enum FrameType {
    // Frame层
    PROTO = 0x00,
    PING = 0x01,
    PONG = 0x02,
    DROP = 0x03,
    REDIRECT = 0x04,
    ACK = 0x05,
    HANDSHAKE = 0x06,
    HANDSHAKE_RESPONSE = 07,
    MARS_SIGNAL = 0x08,
  };
  
  enum {
    MIN_HEADER_LEN = 20,
    MAX_HEADER_LEN = 1024,  // 给1K吧
    TAILER_LEN = 4, // crc32
  };
  
  inline uint32_t CalcFrameLength() const {
    return MIN_HEADER_LEN + TAILER_LEN + body_length;
  }
  
  uint8_t GetFrameType() const {
    return command_id >> 24;
  }
  
  bool Decode(std::unique_ptr<folly::IOBuf> frame_data);
  
  std::string ToString() const;
  
  uint16_t magic_number;    // {0x5342}; // 两傻逼，给两字节('SB')
  uint16_t head_length;     // 头长度
  uint16_t client_version;  // 客户端版本号
  uint16_t frame_index;     // 包长度
  uint32_t seq_num;         // {0};
  uint32_t command_id;      // 命令ID

//  uint16_t magic_number {0x5342}; // 两傻逼，给两字节('SB')
//  // Index of package starting from zero.
//  // If packageIndex is broken connection need to be dropped.
//  uint16_t  frame_index {0};
//  
//  // Type of message
//  uint8_t frame_type {0xFF};
//  // Package payload length
  uint32_t body_length {0};  // 3字节
//  // Package payload
  
  std::unique_ptr<folly::IOBuf> body;
  
  // CRC32 of body
  uint32_t crc32 {0};
};

struct FrameMessage {
  virtual ~FrameMessage() = default;
  
  virtual uint8_t GetFrameType() const = 0;
  virtual bool Decode(Frame& frame) { return true; }
  
  virtual std::string ToString() const { return ""; }
  
  virtual uint32_t CalcFrameSize() const {
    return Frame::MIN_HEADER_LEN + Frame::TAILER_LEN;
  }
  
  bool SerializeToIOBuf(std::unique_ptr<folly::IOBuf>& io_buf) const;
  virtual void Encode(IOBufWriter& iobw) const {}
  
  virtual uint32_t GetCommandID() const {
    return (uint32_t)GetFrameType() << 24;
  }
  
  uint32_t seq_num{0};         // {0};
  // uint32_t command_id{0};
};

// HEADER_PROTO = 0;
struct ProtoRawData : FrameMessage {
  enum {
    HEADER = Frame::PROTO
  };

  uint8_t GetFrameType() const override {
    return HEADER;
  }

  // Impl from FrameMessage
  bool Decode(Frame& frame) override {
    message_data.swap(frame.body);
    command_id = frame.command_id;
    seq_num = frame.seq_num;
    return true;
  }
  
  uint32_t CalcFrameSize() const override {
    return (FrameMessage::CalcFrameSize() +
            SIZEOF_IOBUF(message_data));
  }
  
  void Encode(IOBufWriter& iobw) const override {
    WriteIOBuf(iobw, message_data.get());
  }
  
  uint32_t GetCommandID() const override {
    return command_id;
  }
  
  std::unique_ptr<folly::IOBuf> message_data;
  
  uint32_t command_id;      // 命令ID
};


// Ping message can be sent from both sides
struct Ping : public FrameMessage {
  enum {
    HEADER = Frame::PING
  };

  Ping() = default;
  explicit Ping(const std::string& r) {
    random_bytes = folly::IOBuf::copyBuffer(r);
  }
  
  uint8_t GetFrameType() const override {
    return HEADER;
  }
  
  bool Decode(Frame& frame) override {
    random_bytes.swap(frame.body);
    return true;
  }
  
  uint32_t CalcFrameSize() const override {
    return (FrameMessage::CalcFrameSize() +
            SIZEOF_IOBUF(random_bytes));
  }

  void Encode(IOBufWriter& iobw) const override {
    WriteIOBuf(iobw, random_bytes.get());
  }

  std::unique_ptr<folly::IOBuf> random_bytes;
};

// Pong message need to be sent immediately after receving Ping message
struct Pong : public FrameMessage {
  enum {
    HEADER = Frame::PONG
  };

  uint8_t GetFrameType() const override {
    return HEADER;
  }
  
  bool Decode(Frame& frame) override {
    random_bytes.swap(frame.body);
    return true;
  }
  
  uint32_t CalcFrameSize() const override {
    return (FrameMessage::CalcFrameSize() +
            SIZEOF_IOBUF(random_bytes));
  }

  void Encode(IOBufWriter& iobw) const override {
    WriteIOBuf(iobw, random_bytes.get());
  }

  // Same bytes as in Ping package
  std::unique_ptr<folly::IOBuf> random_bytes;
};

// header = 3
// Notification about connection drop
struct Drop : public FrameMessage {
  enum {
    HEADER = Frame::DROP
  };

  uint8_t GetFrameType() const override {
    return HEADER;
  }
  
  bool Decode(Frame& frame) override;
  
  uint32_t CalcFrameSize() const override {
    return (FrameMessage::CalcFrameSize() +
            sizeof(message_id) +
            sizeof(error_code) +
            SIZEOF_STRING(error_message));
  }
  
  void Encode(IOBufWriter& iobw) const override {
    iobw.writeBE(message_id);
    iobw.writeBE(error_code);
    WriteString(iobw, error_message);
  }

  // Same bytes as in Ping package
  int64_t message_id;
  uint8_t error_code;
  std::string error_message;
};

// header = 4
// Sent by server when we need to temporary redirect to another server
struct Redirect : public FrameMessage {
  enum {
    HEADER = Frame::REDIRECT
  };

  uint8_t GetFrameType() const override {
    return HEADER;
  }
  
  bool Decode(Frame& frame) override;
  
  uint32_t CalcFrameSize() const override {
    return (FrameMessage::CalcFrameSize() +
            SIZEOF_STRING(host) +
            sizeof(port) +
            sizeof(timeout));
  }

  void Encode(IOBufWriter& iobw) const override {
    WriteString(iobw, host);
    iobw.writeBE(port);
    iobw.writeBE(timeout);
  }

  std::string host;
  int port;
  // Redirection timeout
  int timeout;
};

// header = 6
// Proto package is received by destination peer. Used for determening of connection state
struct Ack : public FrameMessage {
  enum {
    HEADER = Frame::ACK,
  };
  uint8_t GetFrameType() const override {
    return HEADER;
  }
  
  bool Decode(Frame& frame) override;
  
  uint32_t CalcFrameSize() const override {
    return (FrameMessage::CalcFrameSize() +
            sizeof(received_package_index));
  }

  void Encode(IOBufWriter& iobw) const override {
    iobw.writeBE(received_package_index);
  }

  int received_package_index;
};

struct Handshake : public FrameMessage {
  enum {
    HEADER = Frame::HANDSHAKE,
  };

  uint8_t GetFrameType() const override {
    return HEADER;
  }
  
  bool Decode(Frame& frame) override;
  
  uint32_t CalcFrameSize() const override {
    return (FrameMessage::CalcFrameSize() +
            sizeof(proto_revision) +
            sizeof(api_major_version) +
            sizeof(api_minor_version) +
            sizeof(random_bytes));
  }

  void Encode(IOBufWriter& iobw) const override {
    iobw.writeBE(proto_revision);
    iobw.writeBE(api_major_version);
    iobw.writeBE(proto_revision);
    iobw.writeBE(api_minor_version);
    iobw.push(random_bytes, 32);
  }

  // Current MTProto revision
  // For Rev 2 need to eq 1
  uint8_t proto_revision;
  // API Major and Minor version
  uint8_t api_major_version;
  uint8_t api_minor_version;
  
  // Some Random Bytes (suggested size is 32 bytes)
  uint8_t random_bytes[32];
};

struct HandshakeResponse : public FrameMessage {
  enum {
    HEADER = Frame::HANDSHAKE_RESPONSE,
  };

  uint8_t GetFrameType() const override {
    return HEADER;
  }
  
  bool Decode(Frame& frame) override;
  
  uint32_t CalcFrameSize() const override {
    return (FrameMessage::CalcFrameSize() +
            sizeof(proto_revision) +
            sizeof(api_major_version) +
            sizeof(api_minor_version) +
            sizeof(sha1));
  }

  void Encode(IOBufWriter& iobw) const override {
    iobw.writeBE(proto_revision);
    iobw.writeBE(api_major_version);
    iobw.writeBE(proto_revision);
    iobw.writeBE(api_minor_version);
    iobw.push(sha1, 32);
  }

  // return same versions as request, 0 - version is not supported
  uint8_t proto_revision;
  uint8_t api_major_version;
  uint8_t api_minor_version;
  
  // SHA256 of randomBytes from request
  uint8_t sha1[32];
};


struct MarsSignal : public FrameMessage {
  enum {
    HEADER = Frame::MARS_SIGNAL,
  };
  
  uint8_t GetFrameType() const override {
    return HEADER;
  }
  
  bool Decode(Frame& frame) override {
    return true;
  }
  
  uint32_t CalcFrameSize() const override {
    return FrameMessage::CalcFrameSize();
  }
  
  void Encode(IOBufWriter& iobw) const override {
  }
};

}

using FrameFactory = nebula::SelfRegisterFactoryManager<zproto::FrameMessage, uint8_t>;

#endif // NUBULA_NET_ZPROTO_ZPROTO_FRAME_DATA_H_

