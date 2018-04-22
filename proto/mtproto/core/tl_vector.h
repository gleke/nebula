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

#ifndef PROTO_MTPROTO_CORE_TL_VECTOR_H
#define PROTO_MTPROTO_CORE_TL_VECTOR_H

#include <vector>
#include "nebula/base/stl_util.h"

#include "proto/mtproto/core/tl_object.h"
#include "proto/mtproto/core/tl_codec_util.h"

namespace mtproto {

/*
template<typename T>
bool ReadTL(IOBufReader& iobr, T* tl) {
}

template<typename T>
bool WriteTL(IOBufWriter& iobw, const T& tl) {
}
 */

// vector#1cb5c415 {t:Type} # [ t ] = Vector t;
// 必须是如下类型：
// 数值类型
// fbstring
// TLObject

enum TLVectorType : uint8_t {
  INT32 = 0,
  INT64 = 1,
  STRING = 2,
  TLOBJECT = 4,
};

template<class T>
class TLVector : public TLObject {
public:
  enum {
    CLASS_ID = 0x1cb5c415,
  };

  // static_assert(std::is_integral<typename BaseIter::value_type>::value,
  //              "BitIterator may only be used with integral types");

  virtual ~TLVector() override = default;
  
  // static const TLClassID CLASS_ID = 0x1cb5c415;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  // 阻止非继承构造
  virtual TLVectorType GetVectorType() const = 0;

/*
  virtual bool Decode(IOBufReader& iobr) override {
    auto magic = iobr.readLE<TLClassID>();
    if (magic != CLASS_ID) {
      return false;
    }
    
//    auto count = iobr.readLE<uint32_t>();
//    for (uint32_t i=0; i<count; ++i) {
//      // server_public_key_fingerprints_.push_back(iobr.readLE<int64_t>());
//    }
    
    return true;
  }
  
  virtual bool Encode(IOBufWriter& iobw) const override {
    iobw.writeLE(static_cast<TLClassID>(CLASS_ID));
//    iobw.writeLE(static_cast<uint32_t>(v_.size()));
//    for (size_t i=0; i<v_.size(); ++i) {
//      // iobw.writeLE(server_public_key_fingerprints_[i]);
//    }
    return true;
  }
 */
  
  std::string ToString() const override {
    return "vector#1cb5c415";
  }
  
  size_t size() const { return vector_.size(); }

/*
  // TODO(@benqi): 使用traits决定是否启用
  //  数值类型
  const T& v(size_t idx) const {
    CHECK(idx<v_.size()) << "TLVector - out range idx: " << idx;
    return v_[idx];
  }
  
  void add_v(const T& v) {
    v_.push_back(v);
  }
  T* mutable_add_v() {
    auto v = new T();
    v.push_back(v);
    return v;
  }
 */
  
  ///////////////////////////////////////////////////////////////////////////////////
  std::vector<T>* mutable_vector() {
    return &vector_;
  }

  const std::vector<T>& vector() const {
    return vector_;
  }

protected:
  std::vector<T> vector_;
};

class TLInt32Vector : public TLVector<int32_t> {
public:
  ~TLInt32Vector() override = default;

  TLVectorType GetVectorType() const override { return TLVectorType::INT32; }

protected:
  bool Decode(IOBufReader& iobr) override {
    auto count = iobr.readLE<uint32_t>();
    for (uint32_t i=0; i<count; ++i) {
      vector_.push_back(iobr.readLE<int32_t>());
    }
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    iobw.writeLE(static_cast<uint32_t>(vector_.size()));
    for (size_t i=0; i<vector_.size(); ++i) {
      iobw.writeLE(vector_[i]);
    }
    return true;
  }
  
};

class TLInt64Vector : public TLVector<int64_t> {
public:
  ~TLInt64Vector() override = default;

  TLVectorType GetVectorType() const override { return TLVectorType::INT64; }

protected:
  bool Decode(IOBufReader& iobr) override {
    auto count = iobr.readLE<uint32_t>();
    for (uint32_t i=0; i<count; ++i) {
      vector_.push_back(iobr.readLE<int64_t>());
    }
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    iobw.writeLE(static_cast<uint32_t>(vector_.size()));
    for (size_t i=0; i<vector_.size(); ++i) {
      iobw.writeLE(vector_[i]);
    }
    
    return true;
  }
};

class TLStringVector : public TLVector<TLString> {
public:
  ~TLStringVector() override = default;
  
  TLVectorType GetVectorType() const override { return TLVectorType::STRING; }

protected:
  bool Decode(IOBufReader& iobr) override {
    auto count = iobr.readLE<uint32_t>();
    for (uint32_t i=0; i<count; ++i) {
      vector_.emplace_back();
      ReadString(iobr, &(vector_.back()));
    }
    
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    iobw.writeLE(static_cast<uint32_t>(vector_.size()));
    for (size_t i=0; i<vector_.size(); ++i) {
      WriteString(iobw, vector_[i]);
    }
    
    return true;
  }
};

template <class TLOBJECT>
class TLObjectVector : public TLVector<std::unique_ptr<TLOBJECT>> {
public:
   static_assert(std::is_base_of<TLObject, TLOBJECT>::value,
                "TLObjectVector may only be used TLObject types");

  // TODO(@wubenqi): 为什么需要下面一行
  typedef TLVector<std::unique_ptr<TLOBJECT>> TLObjectVectorType;
  
  //  typename TLVector<T*> a;
  // TODO(@wubenqi): 检查TLObject对象
  
  // ~TLObjectVector() override {
  //  ::STLDeleteElements(&(TLObjectVectorType::vector_));
  // }
  
  TLVectorType GetVectorType() const override { return TLVectorType::TLOBJECT; }

protected:
  bool Decode(IOBufReader& iobr) override {
    auto count = iobr.readLE<uint32_t>();
    for (uint32_t i=0; i<count; ++i) {
      auto v = TLObject::CreateObjectByIOBuf(iobr);
      // TODO(@benqi): CHECK
      TLObjectVectorType::vector_.push_back(std::unique_ptr<TLOBJECT>(reinterpret_cast<TLOBJECT*>(v)));
    }
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    iobw.writeLE(static_cast<uint32_t>(TLObjectVectorType::vector_.size()));
    for (size_t i=0; i<TLObjectVectorType::vector_.size(); ++i) {
      TLObjectVectorType::vector_[i]->SerializeToIOBuf(iobw);
    }
    return true;
  }
};

}

#endif
