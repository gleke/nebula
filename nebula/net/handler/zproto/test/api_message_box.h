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

#ifndef	PROTO_API_API_MESSAGE_BOX_H_
#define	PROTO_API_API_MESSAGE_BOX_H_

#include <folly/Checksum.h>

// #include "proto/zproto/zproto_message_types_util.h"
#include "nebula/net/zproto/zproto_package_data.h"

template <class T>
typename std::enable_if<std::is_base_of<google::protobuf::Message, T>::value>::type*
Decode(T& protobuf_message, Package& package) {
  // TODO(@benqi): 性能问题
  folly::io::Cursor c(package.message.get());
  int length = (int)(c.totalLength());
  char* data = new char[length];
  c.pull(data, length);
  // rv = message_.ParseFromArray(data, message_.ByteSize());
  protobuf_message.ParseFromArray(data, length);
  delete [] data;
  
  return nullptr;
  // return &protobuf_message;
}

template<typename T>
typename std::enable_if<std::is_base_of<google::protobuf::Message, T>::value>::type*
Encode(T& protobuf_message, IOBufWriter& iobw) {
  // TODO(@benqi): 性能问题
  auto protobuf_message_size = protobuf_message.ByteSize();
  char* data = new char[protobuf_message_size];
  protobuf_message.SerializeToArray(data, protobuf_message_size);
  iobw.push((const uint8_t*)data, protobuf_message_size);
  delete [] data;
  
  return nullptr;

  // return &protobuf_message;
}

inline uint32_t CRC32(const std::string& data) {
  return folly::crc32c((const uint8_t*)data.data(), data.length());
}

template <typename T>
struct ApiRpcRequest : public ProtoBox<T>, public RpcRequest {
  enum {
    HEADER = Package::RPC_REQUEST,
  };
  
  ApiRpcRequest() {
    method_id = CRC32(ProtoBox<T>::message.GetTypeName());
  }
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(Package& package) override {
    try {
      RpcRequest::Decode(package);
      ::Decode(ProtoBox<T>::message, package);
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return RpcRequest::CalcPackageSize() + ProtoBox<T>::message.ByteSize();
  }
  
  void Encode(IOBufWriter& iobw) const override {
    try {
      RpcRequest::Encode(iobw);
      ::Encode(ProtoBox<T>::message, iobw);
    } catch(...) {
    }
  }
  
  uint32_t GetMethodID() const override {
    // return proto::GetMessageType<T>();
    return method_id;
  }

  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, method_id: {}, payload: {}}}",
                          RpcRequest::ToString(),
                          GetMethodID(),
                          ProtoBox<T>::message.Utf8DebugString());
  }

};

template <typename T>
std::shared_ptr<ApiRpcRequest<T>> ToApiRpcRequest(const std::shared_ptr<EncodedRpcRequest>& encoded) {
  auto api = std::make_shared<ApiRpcRequest<T>>();
  api->package_header = encoded->package_header;
  // api->method
  // message_boxed->CopyHeaderFrom(*this);
  folly::io::Cursor c(encoded->message.payload.get());
  int length = (int)(encoded->message.payload_size);
  char* data = new char[length];
  c.pull(data, length);
  // rv = message_.ParseFromArray(data, message_.ByteSize());
  (*api)->ParseFromArray(data, length);
  delete [] data;
  
  return api;
}

template <typename T>
std::shared_ptr<ApiRpcRequest<T>> ToApiRpcRequest(const std::shared_ptr<RpcRequest>& request) {
  auto encoded = std::static_pointer_cast<EncodedRpcRequest>(request);
  DCHECK(encoded);
  return ToApiRpcRequest<T>(encoded);
}


template <typename T>
struct ApiRpcOk : public RpcOk, public ProtoBox<T> {
  enum {
    HEADER = Package::RPC_OK,
  };
  
  ApiRpcOk() {
    method_response_id = CRC32(ProtoBox<T>::message.GetTypeName());
  }

  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(Package& package) override {
    try {
      RpcOk::Decode(package);
      ::Decode(ProtoBox<T>::message, package);
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return RpcOk::CalcPackageSize() + ProtoBox<T>::message.ByteSize();
  }
  
  void Encode(IOBufWriter& iobw) const override {
    try {
      RpcOk::Encode(iobw);
      ::Encode(ProtoBox<T>::message, iobw);
    } catch(...) {
    }
  }
  
  uint32_t GetMethodResponseID() const override {
    // return proto::GetMessageType<T>();

    return method_response_id;
  }

  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, req_message_id: {}, method_response_id: {}, payload: {}}}",
                          RpcOk::ToString(),
                          req_message_id,
                          GetMethodResponseID(),
                          ProtoBox<T>::message.Utf8DebugString());
  }
};

template <typename T>
std::shared_ptr<ApiRpcOk<T>> ToApiRpcOk(const std::shared_ptr<EncodedRpcOk>& encoded) {
  auto api = std::make_shared<ApiRpcOk<T>>();
  api->package_header = encoded->package_header;
  api->req_message_id = encoded->req_message_id;
  
  // api->method
  // message_boxed->CopyHeaderFrom(*this);
  folly::io::Cursor c(encoded->message.payload.get());
  int length = (int)(encoded->message.payload_size);
  char* data = new char[length];
  c.pull(data, length);
  // rv = message_.ParseFromArray(data, message_.ByteSize());
  (*api)->ParseFromArray(data, length);
  delete [] data;
  
  return api;
}

template <typename T>
std::shared_ptr<ApiRpcOk<T>> ToApiRpcOk(const std::shared_ptr<ProtoRpcResponse>& response) {
  auto encoded = std::static_pointer_cast<EncodedRpcOk>(response);
  DCHECK(encoded);
  return ToApiRpcOk<T>(encoded);
}

template <typename T>
struct ApiPush : public Push, public ProtoBox<T> {
  enum {
    HEADER = Package::PUSH,
  };
  
//  ApiPush() {
//    method_id = CRC32(ProtoBox<T>::message.GetTypeName());
//  }

  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(Package& package) override {
    try {
      Push::Decode(package);
      ::Decode(ProtoBox<T>::message, package);
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return Push::CalcPackageSize() + ProtoBox<T>::message.ByteSize();
  }
  
  void Encode(IOBufWriter& iobw) const override {
    try {
      Push::Encode(iobw);
      ::Encode(ProtoBox<T>::message, iobw);
    } catch(...) {
    }
  }
  
  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, payload: {}}}",
                          Push::ToString(),
                          ProtoBox<T>::message.Utf8DebugString());
  }

};

template <typename T>
std::shared_ptr<ApiPush<T>> ToApiPush(const std::shared_ptr<EncodedPush>& encoded) {
  auto api = std::make_shared<ApiPush<T>>();
  api->package_header = encoded->package_header;
  api->update_id = encoded->update_id;
  
  folly::io::Cursor c(encoded->message.payload.get());
  int length = (int)(encoded->message.payload_size);
  char* data = new char[length];
  c.pull(data, length);
  // rv = message_.ParseFromArray(data, message_.ByteSize());
  (*api)->ParseFromArray(data, length);
  delete [] data;
  
  return api;
}

#endif // PROTO_API_API_MESSAGE_BOX_H_

