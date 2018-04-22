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

#ifndef PROTO_MTPROTO_MTPROTO_API_MESSAGE_BOX_H_
#define	PROTO_MTPROTO_MTPROTO_API_MESSAGE_BOX_H_

// #include "proto/zproto/zproto_message_types_util.h"
#include <google/protobuf/message.h>
#include <folly/Checksum.h>

#include "nebula/base/io_buf_util.h"
#include "nebula/net/zproto/zproto_package_data.h"

namespace mtproto {

/*
#if 0
/////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct ApiRpcRequest : public zproto::RpcRequest {
  enum {
    HEADER = zproto::Package::RPC_REQUEST,
  };
  
  ApiRpcRequest() {
    message = std::make_shared<T>();
  }

  explicit ApiRpcRequest(std::shared_ptr<T> other) {
    message = other;
    method_id = T::CLASS_ID;
  }

  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(zproto::Package& package) override {
    try {
      zproto::RpcRequest::Decode(package);
      if (T::CLASS_ID != method_id) return false;

      message = std::make_shared<T>();
      folly::io::Cursor c(package.message.get());
      message->ParseFromIOBuf(c);
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return zproto::RpcRequest::CalcPackageSize() + message->GetObjectSize();
  }
  
  void Encode(IOBufWriter& iobw) const override {
    // TODO(@benqi): 检查message
    try {
      RpcRequest::Encode(iobw);
      message->SerializeToIOBuf(iobw);
    } catch(...) {
    }
  }
  
  uint32_t GetMethodID() const override {
    return method_id;
  }

  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, method_id: {}, payload: {}}}",
                          RpcRequest::ToString(),
                          GetMethodID(),
                          message->ToString());
  }

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

// TODO(@benqi): Handle convert error!!!!
template <typename T>
std::shared_ptr<ApiRpcRequest<T>> ToApiRpcRequest(const std::shared_ptr<zproto::EncodedRpcRequest>& encoded) {
  auto api = std::make_shared<ApiRpcRequest<T>>();
  if (T::CLASS_ID!=encoded->GetMethodID()) return api;
  
  api->package_header = encoded->package_header;
  // api->method
  // message_boxed->CopyHeaderFrom(*this);
  folly::io::Cursor c(encoded->payload.get());
//  zproto::Decode(*(*api), c);
//
//  int length = (int)(encoded->message->payload_size);
//  char* data = new char[length];
//  c.pull(data, length);
//  // rv = message_.ParseFromArray(data, message_.ByteSize());
//  bool rv = (*api)->ParseFromArray(data, length);
//  if (!rv) {
//    LOG(ERROR) << "ToApiRpcRequest - Parse message error: " << encoded->ToString();
//  }
//  delete [] data;
  
  return api;
}

template <typename T>
std::shared_ptr<ApiRpcRequest<T>> ToApiRpcRequest(const std::shared_ptr<zproto::RpcRequest>& request) {
  auto encoded = std::static_pointer_cast<zproto::EncodedRpcRequest>(request);
  DCHECK(encoded);
  return ToApiRpcRequest<T>(encoded);
}


template <typename T>
struct ApiRpcOk : public zproto::RpcOk {
  enum {
    HEADER = zproto::Package::RPC_OK,
  };
  
  ApiRpcOk() = default;
  explicit ApiRpcOk(std::shared_ptr<T> o) {
    message = o;
  }

  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(zproto::Package& package) override {
    try {
      RpcOk::Decode(package);
      
      folly::io::Cursor c(package.message.get());
      // zproto::Decode(*(message.get()), c);
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return zproto::RpcOk::CalcPackageSize(); // + ProtoBox<T>::message->ByteSize();
  }
  
  void Encode(IOBufWriter& iobw) const override {
    try {
      RpcOk::Encode(iobw);
      // zproto::Encode(*(message.get()), iobw);
    } catch(...) {
    }
  }
  
  uint32_t GetMethodResponseID() const override {
    return method_response_id;
  }

  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, req_message_id: {}, method_response_id: {}, payload: {}}}",
                          RpcOk::ToString(),
                          req_message_id,
                          GetMethodResponseID(),
                          "");
  }
  
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

template <typename T>
std::shared_ptr<ApiRpcOk<T>> ToApiRpcOk(const std::shared_ptr<zproto::EncodedRpcOk>& encoded) {
  auto api = std::make_shared<ApiRpcOk<T>>();
  api->package_header = encoded->package_header;
  api->req_message_id = encoded->req_message_id;
  
  // api->method
  // message_boxed->CopyHeaderFrom(*this);
  folly::io::Cursor c(encoded->payload.get());
//  zproto::Decode(*(*api), c);
  
//  int length = (int)(encoded->message->payload_size);
//  char* data = new char[length];
//  c.pull(data, length);
//  // rv = message_.ParseFromArray(data, message_.ByteSize());
//  (*api)->ParseFromArray(data, length);
//  delete [] data;
  
  return api;
}

template <typename T>
std::shared_ptr<ApiRpcOk<T>> ToApiRpcOk(const std::shared_ptr<zproto::ProtoRpcResponse>& response) {
  auto encoded = std::static_pointer_cast<zproto::EncodedRpcOk>(response);
  DCHECK(encoded);
  return ToApiRpcOk<T>(encoded);
}

template <typename T>
struct ApiPush : public zproto::Push {
  enum {
    HEADER = zproto::Package::PUSH,
  };
  
  uint8_t GetPackageType() const override {
    return HEADER;
  }

  bool Decode(zproto::Package& package) override {
    try {
      zproto::Push::Decode(package);
      // Decode(*message, package);
    } catch(...) {
      // TODO(@benqi): error's log
      return false;
    }
    
    return true;
  }
  
  uint32_t CalcPackageSize() const override {
    return Push::CalcPackageSize() + message->ByteSize();
  }
  
  void Encode(IOBufWriter& iobw) const override {
    try {
      Push::Encode(iobw);
      Encode(*message, iobw);
    } catch(...) {
    }
  }
  
  virtual std::string ToString() const override {
    return folly::sformat("{{base: {}, payload: {}}}",
                          Push::ToString(),
                          message->Utf8DebugString());
  }

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

template <typename T>
std::shared_ptr<ApiPush<T>> ToApiPush(const std::shared_ptr<zproto::EncodedPush>& encoded) {
  auto api = std::make_shared<ApiPush<T>>();
  api->package_header = encoded->package_header;
  api->update_id = encoded->update_id;
  
  folly::io::Cursor c(encoded->payload.get());
//  int length = (int)(encoded->message->payload_size);
//  char* data = new char[length];
//  c.pull(data, length);
//  // rv = message_.ParseFromArray(data, message_.ByteSize());
//  (*api)->ParseFromArray(data, length);
//  delete [] data;
  
  return api;
}
 */

// TODO(@benqi):
//  RpcOk可以不用关注具体的Message
//  可以直接生成EncodedRpcOk
// template<typename MESSAGE>
inline zproto::RpcRequestPtr MakeRpcRequest(const TLObject* message) {
  std::unique_ptr<folly::IOBuf> o;
  // TODO(@benqi): TLObject::SerializeToIOBuf增加is_class_id
  message->SerializeToIOBuf(o);
  // 去掉CLASS_ID
  nebula::io_buf_util::TrimStart(o.get(), sizeof(uint32_t));
  return std::make_shared<zproto::RpcRequest>(message->GetClassID(), std::move(o));
  
  // static_assert(std::is_base_of<google::protobuf::Message, MESSAGE>::value,
  //              "MessaegType must be google::protobuf::Message");

  // auto request = std::make_shared<ApiRpcRequest<MESSAGE>>();
  // (*request)->Swap(&message);
  // return request;
}

// 构建RpcOK
// TODO(@benqi):
//  RpcOk可以不用关注具体的Message
//  可以直接生成EncodedRpcOk
inline zproto::ProtoRpcResponsePtr MakeRpcOK(const TLObject& message) {
  // static_assert(std::is_base_of<google::protobuf::Message, MESSAGE>::value,
  //              "MessaegType must be google::protobuf::Message");
  
  std::unique_ptr<folly::IOBuf> o;
  // TODO(@benqi): TLObject::SerializeToIOBuf增加is_class_id
  message.SerializeToIOBuf(o);
  // 去掉CLASS_ID
  nebula::io_buf_util::TrimStart(o.get(), sizeof(uint32_t));
  return std::make_shared<zproto::RpcOk>(message.GetClassID(), std::move(o));
  
  // auto rsp = std::make_shared<ApiRpcOk<MESSAGE>>();
  // rsp->message = message;
  // (*rsp)->Swap(&message);
  // return rsp;
}

inline zproto::ProtoRpcResponsePtr MakeRpcOK(const TLObject* message) {
  return MakeRpcOK(*message);
}

// TODO(@benqi):
//  添加详细出错信息
inline zproto::ProtoRpcResponsePtr MakeRpcError(int error_code) {
  // TODO(@benqi):
  /*
   int32_t error_code;
   // Error Tag like "ACCESS_DENIED"
   std::string error_tag;
   
   // User visible error
   std::string user_message;
   
   // Can user try again
   bool can_try_again;
   
   // Some additional data of error
   std::string error_data;
   */
  auto rsp = std::make_shared<zproto::RpcError>();
  rsp->error_code = error_code;
  return rsp;
}

// TODO(@benqi):
//  添加Delay时间
inline zproto::ProtoRpcResponsePtr MakeRpcFloodWait() {
  return std::make_shared<zproto::RpcFloodWait>();
}

  // TODO(@benqi):
// bool can_try_again;      //: bool
// int32_t try_again_delay; //: int
inline zproto::ProtoRpcResponsePtr MakeRpcInternalError() {
  // TODO(@benqi):
  return std::make_shared<zproto::RpcInternalError>();
}

/*
inline bool ToRpcRequestMessage(const std::shared_ptr<zproto::RpcRequest>& request,
                                TLObject* message) {
  DCHECK(message);
  auto encoded = std::static_pointer_cast<zproto::EncodedRpcRequest>(request);
  DCHECK(encoded);
  
  // TODO(@benqi)
  //  ZeroCopy性能优化
  folly::io::Cursor c(encoded->payload.get());
  return message->ParseFromIOBuf(c, false);
}
 */
// #if 0
// TODO(@benqi):
//  RpcOk可以不用关注具体的Message
//  可以直接生成EncodedPush
inline zproto::PushPtr MakePush(const TLObject* message) {
  // static_assert(std::is_base_of<google::protobuf::Message, MESSAGE>::value,
  //              "MessaegType must be google::protobuf::Message");
  
  std::unique_ptr<folly::IOBuf> o;
  // TODO(@benqi): TLObject::SerializeToIOBuf增加is_class_id
  message->SerializeToIOBuf(o);
  return std::make_shared<zproto::Push>(std::move(o));

  // auto request = std::make_shared<ApiPush<MESSAGE>>();
  // (*request)->Swap(&message);
  // return request;
}
// #endif
 
}

//bool c_r = mtproto::ToRpcRequestMessage(request, &message_req); \

///////////////////////////////////////////////////////////////////////////////////
#define CAST_RPC_REQUEST(MESSAGE, message_req) \
  CHECK(MESSAGE::CLASS_ID==request->GetMethodID()); \
  if (MESSAGE::CLASS_ID!=request->GetMethodID()) { \
    LOG(ERROR) << "ToRpcRequestMessage error: " << request->ToString(); \
    return mtproto::MakeRpcInternalError(); \
  } \
  MESSAGE message_req; \
  folly::io::Cursor c(request->body.get()); \
  bool c_r = message_req.ParseFromIOBuf(c, false); \
  if (!c_r) { \
    LOG(ERROR) << "ToRpcRequestMessage error: " << request->ToString(); \
    return mtproto::MakeRpcInternalError(); \
  }

#endif // NUBULA_NET_ZPROTO_API_API_MESSAGE_BOX_H_

