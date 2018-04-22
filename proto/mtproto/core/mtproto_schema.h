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

#ifndef PROTO_MTPROTO_CORE_MTPROTO_SCHEMA_H_
#define PROTO_MTPROTO_CORE_MTPROTO_SCHEMA_H_

#include <folly/Format.h>

#include "proto/mtproto/schema.tl.h"

namespace mtproto {

//message#0x5bb8e511 msg_id:long seqno:int bytes:int body:Object = Message; // parsed manually
class TL_message2 : public TLObject {
public:
  enum {
    CLASS_ID = 0x5bb8e511,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("message#0x5bb8e511: {{msg_id: {}, seqno: {}, bytes: {}, body: {}}}",
                          msg_id_,
                          seqno_,
                          bytes_,
                          body_ ? body_->ToString() : "{}");
  }
  
  int64_t msg_id() const { return msg_id_; }
  void set_msg_id(int64_t v) { msg_id_ = v; }

  int32_t seqno() const { return seqno_; }
  void set_seqno(int32_t v) { seqno_ = v; }

  int32_t bytes() const { return bytes_; }
  void set_bytes(int32_t v) { bytes_ = v; }

  // template <class T>
  // typename std::enable_if<std::is_base_of<TLObject, T>::value, T>::type* body() {
  //   return reinterpret_cast<T*>(body_.get());
  // }
  const TLObject* body() const {
    return body_.get();
  }
  
  void set_body(std::unique_ptr<TLObject> v) { body_ = std::move(v); }

private:
  int64_t msg_id_;
  int32_t seqno_;
  int32_t bytes_;
  std::unique_ptr<TLObject> body_;
};

//msg_container#73f1f8dc messages:vector<message> = MessageContainer; // parsed manually
class TL_msg_container : public TLObject {
public:
  enum {
    CLASS_ID = 0x73f1f8dc,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("msg_container#73f1f8dc: {{messages_size: {}}}",
                          messages_.size());
  }
  
  size_t messages_size() const { return messages_.size(); }
  const TL_message2* messages(int idx) const { return messages_[idx].get(); }
  TL_message2* add_messages() {
    auto message2 = new TL_message2();
    messages_.push_back(std::unique_ptr<TL_message2>(message2));
    return message2;
  };

private:
  std::vector<std::unique_ptr<TL_message2>> messages_;
};

//rpc_result#f35c6d01 req_msg_id:long result:Object = RpcResult; // parsed manually
class TL_rpc_result : public TLObject {
public:
  enum {
    CLASS_ID = 0xf35c6d01,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("rpc_result#f35c6d01: {{req_msg_id: {}}}",
                          req_msg_id_);
  }
  
  int64_t req_msg_id() const { return req_msg_id_; }
  void set_req_msg_id(int64_t v) { req_msg_id_ = v; }

  std::shared_ptr<TLObject> result() const { return result_; }
  void set_result(std::shared_ptr<TLObject> v) { result_ = v; }
  
private:
  int64_t req_msg_id_ {0};
  std::shared_ptr<TLObject> result_;
};

//gzip_packed#3072cfa1 packed_data:string = Object; // parsed manually
class TL_gzip_packed : public TLObject {
public:
  enum {
    CLASS_ID = 0x3072cfa1,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("gzip_packed#3072cfa1: {{{}}}");
  }
  
  std::string* mutable_packed_data() { return &packed_data_; }
  const std::string& packed_data() const { return packed_data_; }
  void set_packed_data(const std::string& v) {
    packed_data_ = v;
  }
  void set_packed_data(const char* v, size_t n) {
    packed_data_.assign(v, n);
  }
  void set_packed_data(const char* v) {
    packed_data_ = v;
  }
  
private:
  std::string packed_data_;

};

}

#endif

