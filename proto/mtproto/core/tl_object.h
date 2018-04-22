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

#ifndef PROTO_MTPROTO_CORE_TL_OBJECT_H
#define PROTO_MTPROTO_CORE_TL_OBJECT_H

#include "nebula/base/io_buf_util.h"
#include "nebula/base/self_register_factory_manager.h"

#include "proto/mtproto/core/tl_types.h"

namespace mtproto {
  
class TLObject {
public:  
  virtual ~TLObject() = default;
  
  static TLObject* CreateObjectByIOBuf(folly::io::Cursor& iobr);
  static TLObject* CreateObjectByIOBuf(const folly::IOBuf* io_buf);

/*
  template <class T=TLObject>
  static typename std::enable_if<
    std::is_base_of<TLObject, T>::value, T
  >::type* CreateObjectByIOBuf(folly::io::Cursor& iobr) {
    if (iobr.length() < sizeof(uint32_t)) {
      return nullptr;
    }
    
    auto class_id = iobr.readLE<uint32_t>();
    auto obj = TLObjectFactory::CreateInstance(class_id);
    if (obj) {
      obj->Decode(iobr);
      if (!obj) {
        delete obj;
        return nullptr;
      }
    } else {
      LOG(ERROR) << "CreateObjectByIOBuf - not find class_id: " << class_id;
    }
    
    if (dynamic_cast<T*>(obj)) {
      return dynamic_cast<T*>(obj);
    } else {
      delete obj;
    }
    return nullptr;
  }
 */
  
  // 获取TLClassID
  virtual TLClassID GetClassID() const = 0;
  virtual size_t GetObjectSize() const { return 0; }
  virtual std::string ToString() const { return ""; }

  // TLObject序列化和反序列化
  bool ParseFromIOBuf(const folly::IOBuf* io_buf, bool is_read_class_id = false);
  bool SerializeToIOBuf(std::unique_ptr<folly::IOBuf>& io_buf) const;

  bool ParseFromIOBuf(IOBufReader& iobr, bool is_read_class_id = false);
  bool SerializeToIOBuf(IOBufWriter& iobw) const;

  virtual TLObject* Clone() const {
    // TODO(@benqi): CHECK
    return nullptr;
  }
  
  virtual void CopyFrom(const TLObject* o) {
    // TODO(@benqi): CHECK
  }
  
protected:
  virtual bool Decode(IOBufReader& iobr) { return true; }
  virtual bool Encode(IOBufWriter& iobw) const {return true; }
};

using TLObjectPtr = std::shared_ptr<TLObject>;
using TQueryType = std::shared_ptr<TLObject>;

}

// 定义成员宏
// 普通对象，例如string等不需要自己管理内存的对象
#define PROPERTY_OBJECT_DECLARE(class_name, proterty) \
  inline const class_name & proterty() const { return proterty##_; } \
  inline void set_##proterty(const class_name & val) { proterty##_ = val; } \
  inline class_name * mutable_##proterty() { return &proterty##_; }

// 自定义对象，存储的是对象指针，分配和释放需要自己管理
#define PROPERTY_OBJECTPTR_DECLARE(class_name, proterty) \
  inline const class_name & proterty() const { return *proterty##_; } \
  inline void set_##proterty(const class_name & val) { *(mutable_##proterty()) = val; } \
  inline class_name * mutable_##proterty() { if (proterty##_ == NULL) proterty##_ = new class_name(); return proterty##_; }

// 基本类型，如int
#define PROPERTY_BASIC_TYPE_DECLARE(class_type, proterty) \
  inline class_type proterty() const { return proterty##_; } \
  inline void set_##proterty( class_type val ) { proterty##_ = val; }

//////////////////////////////////////////////////////////////////////////
// 普通对象，例如string等不需要自己管理内存的对象
#define PROPERTY_OBJECT_ARRAY_DECLARE(class_name, proterty) \
  inline int proterty_##size() const { return proterty##_.size(); } \
  inline const class_name##& proterty(int index) const { return proterty##_[index]; } \
  inline void add_##proterty( const class_name& val ) { proterty##_.push_back(val); } \
  inline std::vector<class_name##*>* mutable_##proterty() { return &proterty##_; }

// 自定义对象，存储的是对象指针，分配和释放需要自己管理
#define PROPERTY_OBJECTPTR_ARRAY_DECLARE(class_name, proterty) \
  inline int proterty_##size() const { return proterty##_.size(); } \
  inline const std::vector<class_name *> & proterty() const { return proterty##_; } \
  inline const class_name & proterty(int index) const { return *proterty##_[index]; } \
  inline class_name * add_##proterty() { class_name * val = new class_name(); proterty##_.push_back(val); return val; } \
  inline std::vector<class_name *>* mutable_##proterty() { return &proterty##_; }

// 基本类型，如int
#define PROPERTY_BASIC_TYPE_ARRAY_DECLARE(class_type, proterty) \
  inline int proterty_##size() const { return proterty##_.size(); } \
  inline const std::vector<class_type>& proterty() const { return proterty##_; } \
  inline class_type proterty(int index) const { return proterty##_[index]; } \
  inline void add_##proterty( class_type val ) { proterty##_.push_back(val); } \
  inline std::vector<class_type>* mutable_##proterty() { return &proterty##_; }


using TLObjectFactory = nebula::SelfRegisterFactoryManager<mtproto::TLObject, uint32_t>;

template <class T>
using TLObjectRegister = nebula::SelfRegisterFactoryManager<mtproto::TLObject, uint32_t>::RegisterTemplate<T>;
#define REGISTER_TLOBJECT(T) \
  static TLObjectRegister<T> g_reg_tl_obejct_##T(T::CLASS_ID)

#endif
