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

#ifndef NUBULA_NET_ZPROTO_ZPROTO_PACKAGE_DATA_H_
#define NUBULA_NET_ZPROTO_ZPROTO_PACKAGE_DATA_H_

#include <list>

#include "nebula/net/zproto/zproto_frame_data.h"

namespace zproto {
  
//////////////////////////////////////////////////////////////////////
struct PackageHeader {
  std::string ToString() const;
  
  int64_t auth_id {0};
  // random identifier of current session
  int64_t session_id {0};
  int64_t message_id {0};
};

struct AttachDataMessage  {
  uint8_t     proto_revision {1};
  uint64_t    birth_timetick {0};         // 服务端收到一条消息后设置服务端当前时间戳，用来计算每个链路的调用耗时
  uint64_t    birth_track_uuid {0};
  std::string birth_from {"127.0.0.1"};
  uint32_t    birth_server_id {1};
  uint64_t    birth_conn_id {0};
  std::string birth_remote_ip {"127.0.0.1"};
  
  struct OptionData {
    OptionData() = default;
    
    OptionData& operator=(const OptionData& o) {
      type = o.type;
      if (type == 0) {
        data.n = o.data.n;
      } else {
        data.s = new std::string(*o.data.s);
      }
      return *this;
    }

    OptionData(const OptionData& o) {
      type = o.type;
      if (type == 0) {
        data.n = o.data.n;
      } else {
        data.s = new std::string(*o.data.s);
      }
    }
    
    ~OptionData() {
      if (type == 1) {
        delete data.s;
      }
    }
    
    uint32_t CalcOptionDataSize() const {
      return sizeof(type) + type ? SIZEOF_STRING(*data.s) : sizeof(data.n);
    }
    
    uint8_t type {0}; // 0: 数字，1: 字符
    union {
      uint64_t n;
      std::string* s;
    } data;
  };
  
  std::vector<OptionData> options;
  
  uint32_t CalcPackageSize() const {
    // return Package::HEADER_LEN;
    uint32_t sz = sizeof(proto_revision) +
      sizeof(birth_timetick) +
      sizeof(birth_track_uuid) +
      SIZEOF_STRING(birth_from) +
      sizeof(birth_server_id) +
      sizeof(birth_conn_id) +
      SIZEOF_STRING(birth_remote_ip) +
      sizeof(uint32_t);

    for (auto& v : options) {
      sz += v.CalcOptionDataSize();
    }
    return sz;
  }

  std::string ToString() const;
};

typedef AttachDataMessage S2SAttachData;

// Transport Level
// 0xFF
// 0x00001 000
struct Package {
  enum PackageType {
    AUTH_ID_INVALID = 0x01,
    REQUEST_AUTH_ID = 0x02,
    RESPONSE_AUTH_ID = 0x03,
    
    REQUEST_START_AUTH = 0x04,
    RESPONSE_START_AUTH = 0x05,
    REQUEST_GET_SERVER_KEY = 0x06,
    RESPONSE_GET_SERVER_KEY = 0x07,
    REQUEST_DH = 0x08,
    RESPONSE_DO_DH = 0x09,
    
    // SERVER_TO_SERVER_MESSAGE = 0x0A,
    ATTACH_DATA_MESSAGE = 0x0A,
    CONTAINER = 0x0B,
    
    // PROTO_RPC_REQUEST = 0x0C,
    // PROTO_RPC_RESPONSE = 0x0D,
    // PROTO_PUSH = 0x0F,
    
    MESSAGE_ACK = 0x10,
    
    UNSENT_MESSAGE = 0x11,
    UNSENT_RESPONSE = 0x12,
    REQUEST_RESEND = 0x13,
    
    NEW_SESSION = 0x14,
    SESSION_HELLO = 0x15,
    SESSION_LOST = 0x16,
    
    RPC_REQUEST = 0x20,
    RPC_OK = 0x30,
    RPC_ERROR = 0x31,
    RPC_FLOOD_WAIT = 0x32,
    RPC_INTERNAL_ERROR = 0x33,
    
    PUSH = 0x34,
  };
  
  enum {
    HEADER_LEN = 25, //
  };

  bool Decode(ProtoRawData& proto_raw_data);
  
  PackageHeader package_header;
  uint8_t package_type;
  uint32_t seq_num;
  bool _has_attach_data {false};
  AttachDataMessage attach_data;
  
  // message contents
  // message: PlainTextMessage/EncryptedMessage/Drop/AuthIdInvalid
  std::unique_ptr<folly::IOBuf> message;
};

struct PackageMessage {
  virtual ~PackageMessage() = default;
  
  uint32_t GetCommandID() const {
    return (uint32_t)GetPackageType() << 16;
  }
  /////////////////////////////////////////////////////////////////////
  // auth_id
  inline int64_t auth_id() const {
    return package_header.auth_id;
  }
  inline void set_auth_id(int64_t v) {
    package_header.auth_id = v;
  }
  
  // session_id
  inline int64_t session_id() const {
    return package_header.session_id;
  }
  void set_session_id(int64_t v) {
    package_header.session_id = v;
  }

  // message_id
  inline int64_t message_id() const {
    return package_header.message_id;
  }
  void set_message_id(int64_t v) {
    package_header.message_id = v;
  }

  /////////////////////////////////////////////////////////////////////
  // _has_attach_data
  inline bool has_attach_data() const {
    return _has_attach_data;
  }
  inline void set_has_attach_data() {
    _has_attach_data = true;
  }
  inline void clear_has_attach_data() {
    _has_attach_data = false;
  }

  // proto_revision
  inline uint8_t proto_revision() const {
    return attach_data.proto_revision;
  }
  inline void set_proto_revision(uint8_t v) {
    attach_data.proto_revision = v;
    _has_attach_data = true;
  }

  // birth_timetick
  inline uint64_t birth_timetick() const {
    return attach_data.birth_timetick;
  }
  inline void set_birth_timetick(uint64_t v) {
    attach_data.birth_timetick = v;
    _has_attach_data = true;
  }

  // birth_track_uuid
  inline uint64_t birth_track_uuid() const {
    return attach_data.birth_track_uuid;
  }
  inline void set_birth_track_uuid(uint64_t v) {
    attach_data.birth_track_uuid = v;
    _has_attach_data = true;
  }

  // birth_from
  inline const std::string& birth_from() const {
    return attach_data.birth_from;
  }
  inline void set_birth_from(const std::string& v) {
    attach_data.birth_from = v;
    _has_attach_data = true;
  }

  // birth_server_id
  inline uint32_t birth_server_id() const {
    return attach_data.birth_server_id;
  }
  inline void set_birth_server_id(uint32_t v) {
    attach_data.birth_server_id = v;
    _has_attach_data = true;
  }

  // birth_conn_id
  inline uint64_t birth_conn_id() const {
    return attach_data.birth_conn_id;
  }
  inline void set_birth_conn_id(uint64_t v) {
    attach_data.birth_conn_id = v;
    _has_attach_data = true;
  }

  // birth_remote_ip
  inline const std::string& birth_remote_ip() const {
    return attach_data.birth_remote_ip;
  }
  inline void set_birth_remote_ip(const std::string& v) {
    attach_data.birth_remote_ip = v;
    _has_attach_data = true;
  }

  // options
  const std::vector<AttachDataMessage::OptionData>& options() const {
    return attach_data.options;
  }
  
  size_t push_back_option(uint64_t v) {
    // attach_data.options[k] = v;
    AttachDataMessage::OptionData o;
    o.type = 0;
    o.data.n = v;
    attach_data.options.push_back(o);
    _has_attach_data = true;
    return attach_data.options.size();
  }

  size_t push_back_option(const std::string& v) {
    AttachDataMessage::OptionData o;
    o.type = 1;
    o.data.s = new std::string(v);
    attach_data.options.push_back(o);
    _has_attach_data = true;
    return attach_data.options.size();
  }

  /////////////////////////////////////////////////////////////////////
  // Imp from FrameMessage
  inline uint8_t GetFrameType() const {
    return Frame::PROTO;
  }
  
  virtual std::string ToString() const; // { return ""; }

  virtual uint8_t GetPackageType() const = 0;
  
  virtual bool Decode(Package& package) {
    seq_num = package.seq_num;
    package_header = package.package_header;
    _has_attach_data = package._has_attach_data;
    if (_has_attach_data) {
      attach_data = package.attach_data;
    }
    return true;
  }
  
  bool SerializeToIOBuf(std::unique_ptr<folly::IOBuf>& io_buf) const;
  virtual uint32_t CalcPackageSize() const { return Package::HEADER_LEN; }
  
  virtual void Encode(IOBufWriter& iobw) const {
    iobw.writeBE(package_header.auth_id);
    iobw.writeBE(package_header.session_id);
    iobw.writeBE(package_header.message_id);

    if (_has_attach_data) {
      iobw.writeBE((uint8_t)Package::ATTACH_DATA_MESSAGE);
      iobw.writeBE(attach_data.proto_revision);
      iobw.writeBE(attach_data.birth_timetick);
      iobw.writeBE(attach_data.birth_track_uuid);
      WriteString(iobw, attach_data.birth_from);
      iobw.writeBE(attach_data.birth_server_id);
      iobw.writeBE(attach_data.birth_conn_id);
      WriteString(iobw, attach_data.birth_remote_ip);
      
      // write options
      iobw.writeBE((uint32_t)attach_data.options.size());
      for (auto& v : attach_data.options) {
        iobw.writeBE(v.type);
        if (v.type == 0) {
          iobw.writeBE(v.data.n);
        } else {
          WriteString(iobw, *v.data.s);
        }
      }
      // WriteMapStringString(iobw, attachx_data.options);
    }

    iobw.writeBE(GetPackageType());
  }
 
  uint32_t seq_num {0};
  uint32_t command_id {0};
  
  PackageHeader package_header;
  bool _has_attach_data {false};
  AttachDataMessage attach_data;
};

using PackageMessagePtr = std::shared_ptr<PackageMessage>;

////////////////////////////////////////////////////////////////////////////////////////////
struct AuthIdInvalid : public PackageMessage {
  enum {
    HEADER = Package::AUTH_ID_INVALID,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
};

struct RequestAuthId : public PackageMessage {
  enum {
    HEADER = Package::REQUEST_AUTH_ID,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
};

struct ResponseAuthId : public PackageMessage {
  enum {
    HEADER = Package::RESPONSE_AUTH_ID,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      auth_id = c.readBE<int64_t>();
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  // HEADER = 0xF1
  int64_t auth_id;
};

///////////////////////////////////////////////////////////////////////////////////
// Authentication Key

// Before start Client MUST send RequestStartAuth message:
struct RequestStartAuth : public PackageMessage {
  enum {
    HEADER = Package::REQUEST_START_AUTH,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
  
  int64_t random_id;
};

// Server MUST return list of truncated to 8 bytes of SHA-256 of available keyss
struct ResponseStartAuth : public PackageMessage {
  enum {
    HEADER = Package::RESPONSE_START_AUTH,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
  
  int64_t random_id;
  std::list<int64_t> available_keys;
  std::string server_nonce;
};

// Client downloads required key. Client can skip downloading keys if it have built-in keys installed.
struct RequestGetServerKey : public PackageMessage {
  enum {
    HEADER = Package::REQUEST_GET_SERVER_KEY,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
  
  int64_t key_id;
};

// Server return raw key data. Client MUST to check received key by comparing FULL hash that is hardcoded inside application. Again, DON'T compare truncated hashes - this is insecure.
struct ResponseGetServerKey : public PackageMessage {
  enum {
    HEADER = Package::RESPONSE_GET_SERVER_KEY,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
  
  int64_t key_id;
  std::string key;
};

// Performing Diffie Hellman
struct RequestDH : public PackageMessage {
  enum {
    HEADER = Package::REQUEST_DH,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
  
  int64_t random_id;
  
  // Used keyId
  int64_t key_id;
  
  // Client's 32 securely generated bytes
  std::string client_nonce;
  // Client's key used for encryption
  std::string client_key;
};

// master_secret is result encryption key.
// First 128 bytes is US encryption keys and last 128 bytes is Russian encryption keys.
// HEADER_RESPONSE_DO_DH
struct ResponseDoDH : public PackageMessage {
  enum {
    HEADER = Package::RESPONSE_DO_DH,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
  
  int64_t random_id;
  std::string verify;
  std::string verify_sign;
};

/////////////////////////////////////////////////////////////////////////////////////////
// RpcRequest/RpcOk/Push消息的playload
// 提供了一个帮助类包装数据包体内容，并兼容Protobuf(Message)接口
struct EncodedMessage {
  // const void* GetRawData() const;
  // int GetRawDataLength() const;
  
  // 为了和ProtobufMessage接口兼容
  uint32_t ByteSize() const {
    return payload_size;
  }
  
  bool Decode(Package& package) {
    payload.swap(package.message);
    payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
    return true;
  }
  
  void Encode(IOBufWriter& iobw) const {
    folly::io::Cursor c(payload.get());
    iobw.push(c, payload_size);
  }

  std::string Utf8DebugString() const {
    return "{}";
  }
  
  void PrintDebugString() const {}
  
  std::string ToString() const {
    return folly::sformat("{{payload_size: {}}}", payload_size);
  }
  
  void SwapPayload(std::unique_ptr<folly::IOBuf>& io_buf) {
    payload.swap(io_buf);
    payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
  }
  
  std::unique_ptr<folly::IOBuf> payload;
  uint32_t payload_size {0};
};

/////////////////////////////////////////////////////////////////////////////////////////
/*
template <typename T>
struct ProtoBox  {
  ProtoBox() {}
  explicit ProtoBox(std::shared_ptr<T>) {}
  
  // 通过指针方式直接使用MESSAGE
  T& operator*() {
    return *message;
  }
  
  const T& operator*() const {
    return *message;
  }
  
  T* operator->() {
    return message.get();
  }
  
  const T* operator->() const {
    return message.get();
  }
  
  T* get() {
    return message.get();
  }
  
  const T* get() const {
    return message.get();
  }
  
  std::shared_ptr<T> message;
};
*/
  
// RPC用
struct ProtoRpcRequest : public PackageMessage {
  bool CheckPackageType() const {
    return GetPackageType() == Package::RPC_REQUEST;
  }
  
  // int64_t req_message_id;
};
  
struct ProtoRpcResponse : public PackageMessage {
  ProtoRpcResponse() = default;
  explicit ProtoRpcResponse(int64_t _req_message_id)
    : req_message_id(_req_message_id) {}
  
  void set_req_message_id(int64_t v) {
    req_message_id = v;
  }
  
  bool CheckPackageType() const {
    return GetPackageType() == Package::RPC_OK ||
            GetPackageType() == Package::RPC_ERROR ||
            GetPackageType() == Package::RPC_FLOOD_WAIT ||
            GetPackageType() == Package::RPC_INTERNAL_ERROR;
  }

  int64_t req_message_id {0};
};
  
struct ProtoPush : public PackageMessage {
  bool CheckPackageType() const {
    return GetPackageType() == Package::PUSH;
  }
};

using ProtoRpcRequestPtr = std::shared_ptr<ProtoRpcRequest>;
using ProtoRpcResponsePtr = std::shared_ptr<ProtoRpcResponse>;
using ProtoPushPtr = std::shared_ptr<ProtoPush>;

///////////////////////////////////////////////////////////////////////////////////////
struct RpcRequest : public ProtoRpcRequest {
  enum {
    HEADER = Package::RPC_REQUEST,
  };

  RpcRequest() = default;
  explicit RpcRequest(uint32_t _method_id, std::unique_ptr<folly::IOBuf> buf) {
    method_id = _method_id;
    body = std::move(buf);
    // payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
  }

  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    folly::io::Cursor c(package.message.get());
    // req_message_id = c.readBE<int64_t>();
    method_id = c.readBE<uint32_t>();
    nebula::io_buf_util::TrimStart(package.message.get(), sizeof(method_id));
    body.swap(package.message);
    return true;
  }
  
  void Encode(IOBufWriter& iobw) const override {
    PackageMessage::Encode(iobw);
    iobw.writeBE(GetMethodID());
    folly::io::Cursor c(body.get());
    iobw.push(c, static_cast<uint32_t>(body->computeChainDataLength()));
  }

  uint32_t CalcPackageSize() const override {
    // CHECK(true);
    
    return sizeof(method_id) + body->computeChainDataLength();
    // + static_cast<uint32_t>(message.ByteSize());
  }

  virtual uint32_t GetMethodID() const {
    return method_id;
  }

  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, method_id: {}, encoded: {}}}",
                          PackageMessage::ToString(),
                          method_id,
                          "");
  }

  // ID of API Method Request
  uint32_t method_id; //: int
  // Encoded Request
  // body: bytes
  mutable std::unique_ptr<folly::IOBuf> body;
};

using RpcRequestPtr = std::shared_ptr<RpcRequest>;

/*
struct EncodedRpcRequest : public RpcRequest {
  enum {
    HEADER = Package::RPC_REQUEST,
  };
  
  // TODO(@benqi): 增加序列化、反序列化标志
  EncodedRpcRequest() = default;
  
  explicit EncodedRpcRequest(uint32_t _method_id, std::unique_ptr<folly::IOBuf> buf) {
    method_id = _method_id;
    payload = std::move(buf);
    payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
  }
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(Package& package) override {
    try {
      RpcRequest::Decode(package);
      payload.swap(package.message);
      payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
      // message->Decode(package);
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }

  uint32_t CalcPackageSize() const override {
    return RpcRequest::CalcPackageSize() + payload_size;
  }

  void Encode(IOBufWriter& iobw) const override {
    try {
      RpcRequest::Encode(iobw);
      folly::io::Cursor c(payload.get());
      iobw.push(c, payload_size);
      // message->Encode(iobw);
    } catch(...) {
      
    }
  }
  
  uint32_t GetMethodID() const override {
    return method_id;
  }

  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, method_id: {}, encoded: {}}}",
                          RpcRequest::ToString(),
                          method_id,
                          "");
  }
  
  // std::shared_ptr<EncodedMessage> message;
  std::unique_ptr<folly::IOBuf> payload;
  uint32_t payload_size {0};
};
*/
  
// Successful RPC
struct RpcOk : public ProtoRpcResponse {
  enum {
    HEADER = Package::RPC_OK,
  };
  
  RpcOk() = default;
  explicit RpcOk(uint32_t _method_response_id, std::unique_ptr<folly::IOBuf> buf) {
    method_response_id = _method_response_id;
    body = std::move(buf);
  }
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      req_message_id = c.readBE<int64_t>();
      method_response_id = c.readBE<uint32_t>();
      
      // TODO(@benqi): 使用c已读长度
      nebula::io_buf_util::TrimStart(package.message.get(), sizeof(req_message_id) + sizeof(method_response_id));
      body.swap(package.message);

    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return sizeof(req_message_id) + sizeof(method_response_id);
  }
  

  void Encode(IOBufWriter& iobw) const override {
    PackageMessage::Encode(iobw);
    iobw.writeBE(req_message_id);
    iobw.writeBE(GetMethodResponseID());
    folly::io::Cursor c(body.get());
    iobw.push(c, static_cast<uint32_t>(body->computeChainDataLength()));
  }
  
  uint32_t GetMethodResponseID() const {
    return method_response_id;
  }
  
  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, req_message_id: {}, method_response_id: {}, encoded: {}}}",
                          ProtoRpcResponse::ToString(),
                          req_message_id,
                          method_response_id,
                          "");
  }

  // ID of API Method Response
  uint32_t method_response_id; // : int
  // Encoded response
  // body: bytes
  mutable std::unique_ptr<folly::IOBuf> body;
};

/*
struct EncodedRpcOk : public RpcOk {
  enum {
    HEADER = Package::RPC_OK,
  };
  
  EncodedRpcOk() = default;
  explicit EncodedRpcOk(uint32_t _method_response_id, std::unique_ptr<folly::IOBuf> buf) {
    method_response_id = _method_response_id;
    payload = std::move(buf);
    payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
  }

  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(Package& package) override {
    try {
      RpcOk::Decode(package);
      payload.swap(package.message);
      payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }

  uint32_t CalcPackageSize() const override {
    return RpcOk::CalcPackageSize() + payload_size;
  }

  void Encode(IOBufWriter& iobw) const override {
    try {
      RpcOk::Encode(iobw);
      folly::io::Cursor c(payload.get());
      iobw.push(c, payload_size);
    } catch(...) {
    }
  }
  
  uint32_t GetMethodResponseID() const override {
    return method_response_id;
  }

  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, req_message_id: {}, method_response_id: {}, encoded: {}}}",
                          RpcOk::ToString(),
                          req_message_id,
                          method_response_id,
                          "");
  }

  // std::shared_ptr<EncodedMessage> message;
  std::unique_ptr<folly::IOBuf> payload;
  uint32_t payload_size {0};
};
*/
  
// RPC Error
struct RpcError : public ProtoRpcResponse {
  enum {
    HEADER = Package::RPC_ERROR,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      req_message_id = c.readBE<int64_t>();
      error_code = c.readBE<int32_t>();
      
      auto len = c.readBE<int32_t>();
      error_tag = c.readFixedString(len);
      
      len = c.readBE<int32_t>();
      user_message = c.readFixedString(len);
      
      can_try_again = c.readBE<uint8_t>();
      // == 0 ? false : true;
      
      len = c.readBE<int32_t>();
      error_data = c.readFixedString(len);
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return sizeof(req_message_id) +
            sizeof(error_code) +
            SIZEOF_STRING(error_tag) +
            SIZEOF_STRING(user_message) +
            sizeof(uint8_t) +
            SIZEOF_STRING(error_data);
  }
  
  void Encode(IOBufWriter& iobw) const override {
    PackageMessage::Encode(iobw);
    iobw.writeBE(req_message_id);
    iobw.writeBE(error_code);
    
    iobw.writeBE((int32_t)error_tag.length());
    iobw.push((const uint8_t*)error_tag.data(), error_data.length());
    
    iobw.writeBE((int32_t)user_message.length());
    iobw.push((const uint8_t*)user_message.data(), user_message.length());
    
    uint8_t try2 = can_try_again ? 1 : 0;
    iobw.writeBE(try2);
    
    iobw.writeBE((int32_t)error_data.length());
    iobw.push((const uint8_t*)error_data.data(), error_data.length());
  }
  
//  virtual std::string ToString() const override {
//    return folly::sformat("{{base: {}, method_response_id: {}, encoded: {{}}}}}",
//                          RpcOk::ToString(),
//                          method_response_id);
//  }

  // int64_t req_message_id;

  // Error Code like HTTP Error code
  int32_t error_code;
  // Error Tag like "ACCESS_DENIED"
  std::string error_tag;
  
  // User visible error
  std::string user_message;
  
  // Can user try again
  bool can_try_again;
  
  // Some additional data of error
  std::string error_data;
};

// RPC Flood Control.
// Client need to repeat request after delay
struct RpcFloodWait : public ProtoRpcResponse {
  enum {
    HEADER = Package::RPC_FLOOD_WAIT,
  };
  
  RpcFloodWait() = default;
  explicit RpcFloodWait(int32_t _delay)
    : delay(_delay) {}
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      req_message_id = c.readBE<int64_t>();
      delay = c.readBE<int32_t>();
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return sizeof(req_message_id) + sizeof(delay);
  }
  
  void Encode(IOBufWriter& iobw) const override {
    PackageMessage::Encode(iobw);
    iobw.writeBE(req_message_id);
    iobw.writeBE(delay);
  }
  
  // int64_t req_message_id;
  // Repeat delay on seconds
  int32_t delay {0};
};

// Internal Server Error
// Client may try to resend message
struct RpcInternalError : public ProtoRpcResponse {
  enum {
    HEADER = Package::RPC_INTERNAL_ERROR,
  };
  
  RpcInternalError() = default;
  
  explicit RpcInternalError(int64_t _req_message_id, int32_t _try_again_delay = 0)
    : ProtoRpcResponse(_req_message_id) {
    if (_try_again_delay>0) {
      can_try_again = true;
      try_again_delay = _try_again_delay;
    } else {
      can_try_again = false;
      try_again_delay = 0;
    }
  }
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      
      req_message_id = c.readBE<int64_t>();
      can_try_again = c.readBE<uint8_t>();
      try_again_delay = c.readBE<int32_t>();
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return sizeof(uint8_t) + sizeof(try_again_delay);
  }
  
  void Encode(IOBufWriter& iobw) const override {
    PackageMessage::Encode(iobw);
    iobw.writeBE(req_message_id);
    uint8_t try2 = can_try_again ? 1 : 0;
    iobw.writeBE(try2);
    
    iobw.writeBE(try_again_delay);
  }
  
  virtual std::string ToString() const override {
    return folly::sformat("{{req_message_id: {}, can_try_again: {}, try_again_delay: {}}}",
                          req_message_id,
                          can_try_again ? "true" : "false",
                          try_again_delay);
  }
  
  // int64_t req_message_id;
  bool can_try_again; //: bool
  int32_t try_again_delay; //: int
};

struct Push : public ProtoPush {
  enum {
    HEADER = Package::PUSH,
  };
  
  Push() = default;
  explicit Push(std::unique_ptr<folly::IOBuf> buf) {
    body = std::move(buf);
    // payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
  }
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    folly::io::Cursor c(package.message.get());
    
    update_id = c.readBE<int32_t>();
    nebula::io_buf_util::TrimStart(package.message.get(), 4);
    body.swap(package.message);

    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return sizeof(update_id) + static_cast<int32_t>(body->computeChainDataLength());
  }
  
  void Encode(IOBufWriter& iobw) const override {
    PackageMessage::Encode(iobw);
    iobw.writeBE(update_id);
    folly::io::Cursor c(body.get());
    iobw.push(c, static_cast<int32_t>(body->computeChainDataLength()));
  }
  
  // Push Entity Id
  int32_t update_id; //: int
  // Encoded Push body
  mutable std::unique_ptr<folly::IOBuf> body;
};

using PushPtr = std::shared_ptr<Push>;

/*
/////////////////////////////////////////////////////////////////////////////////////////////////
struct EncodedPush : public Push {
  enum {
    HEADER = Package::PUSH,
  };
  
  EncodedPush() = default;
  explicit EncodedPush(std::unique_ptr<folly::IOBuf> buf) {
    payload = std::move(buf);
    payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
  }

  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(Package& package) override {
    try {
      Push::Decode(package);
      payload.swap(package.message);
      payload_size = static_cast<uint32_t>(payload->computeChainDataLength());
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return Push::CalcPackageSize() + payload_size;
  }
  
  void Encode(IOBufWriter& iobw) const override {
    try {
      Push::Encode(iobw);
      folly::io::Cursor c(payload.get());
      iobw.push(c, payload_size);
    } catch(...) {
    }
  }

  std::unique_ptr<folly::IOBuf> payload;
  uint32_t payload_size {0};
};
*/
  
struct MessageAck : public PackageMessage {
  enum {
    HEADER = Package::MESSAGE_ACK,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      int size = c.readBE<int>();
      for (int i=0; i<size; ++i) {
        message_ids.push_back(c.readBE<int64_t>());
      }
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  // Message Identificators for confirmation
  std::vector<int64_t> message_ids;
};

// Notification about unsent message (usually ProtoRpcRequest or ProtoPush)
struct UnsentMessage : public PackageMessage {
  enum {
    HEADER = Package::UNSENT_MESSAGE,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      
      message_id = c.readBE<int64_t>();
      len = c.readBE<int32_t>();
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  // HEADER = 0x07
  // Sent Message Id
  int64_t message_id;
  // Size of message in bytes
  int32_t len;
};

// Notification about unsent ProtoRpcResponse
struct UnsentResponse : public PackageMessage {
  enum {
    HEADER = Package::UNSENT_RESPONSE,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      
      message_id = c.readBE<int64_t>();
      request_message_id = c.readBE<int64_t>();
      len = c.readBE<int32_t>();
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  // HEADER = 0x08
  // Sent Message Id
  int64_t message_id;
  // Request Message Id
  int64_t request_message_id;
  // Size of message in bytes
  int32_t len;
};

// Requesting resending of message
struct RequestResend : public PackageMessage {
  enum {
    HEADER = Package::REQUEST_RESEND,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      
      message_id = c.readBE<int64_t>();
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  // HEADER = 0x09
  // Message Id for resend
  int64_t message_id; // : long
};

struct NewSession : public PackageMessage {
  enum {
    HEADER = Package::NEW_SESSION,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    try {
      folly::io::Cursor c(package.message.get());
      
      session_id = c.readBE<int64_t>();
      message_id = c.readBE<int64_t>();
    } catch(...) {
      // TODO(@wubenqi): error's log
      return false;
    }
    return true;
  }
  
  // HEADER = 0x0C
  // Created Session Id
  int64_t session_id;
  // Message Id of Message that created session
  int64_t message_id;
};

struct SessionHello : public PackageMessage {
  enum {
    HEADER = Package::SESSION_HELLO,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
};

struct SessionLost : public PackageMessage {
  enum {
    HEADER = Package::SESSION_LOST,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
};

struct Container : public PackageMessage {
  enum {
    HEADER = Package::CONTAINER,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }
  
  bool Decode(Package& package) override {
    PackageMessage::Decode(package);
    return true;
  }
  
  // Messages count
  // int32_t count;
  // Messages in container
  std::list<PackageMessagePtr> data;
};

}

using PackageFactory = nebula::SelfRegisterFactoryManager<zproto::PackageMessage, uint8_t>;

#endif // NUBULA_NET_ZPROTO_ZPROTO_PACKAGE_DATA_H_

