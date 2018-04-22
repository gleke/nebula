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

#include "proto/mtproto/core/tl_object.h"

#include <glog/logging.h>
#include <folly/ExceptionString.h>

using namespace mtproto;

enum { GROWTH_SIZE = 2000 };

TLObject* TLObject::CreateObjectByIOBuf(folly::io::Cursor& iobr) {
  if (iobr.length() < sizeof(uint32_t)) {
    return nullptr;
  }
  auto class_id = iobr.readLE<uint32_t>();
  auto obj = TLObjectFactory::CreateInstance(class_id);
  if (obj) {
    obj->Decode(iobr);
  } else {
    LOG(ERROR) << "CreateObjectByIOBuf - not find class_id: " << class_id;
  }
  
  return obj;
}

TLObject* TLObject::CreateObjectByIOBuf(const folly::IOBuf* io_buf) {
  CHECK(io_buf) << "CreateObjectByIOBuf - io_buf is nullptr!";
  folly::io::Cursor c(io_buf);
  return TLObject::CreateObjectByIOBuf(c);
}

// TLObject序列化和反序列化
bool TLObject::ParseFromIOBuf(const folly::IOBuf* io_buf, bool is_read_class_id) {
  CHECK(io_buf) << "ParseFromIOBuf - io_buf is nullptr";
  IOBufReader iobr(io_buf);
  return ParseFromIOBuf(iobr, is_read_class_id);
}

bool TLObject::SerializeToIOBuf(std::unique_ptr<folly::IOBuf>& io_buf) const {
  auto io_buf2 = folly::IOBuf::create(GROWTH_SIZE);
  IOBufWriter iobw(io_buf2.get(), GROWTH_SIZE);
  if (SerializeToIOBuf(iobw)) {
    io_buf = std::move(io_buf2);
    return true;
  } else {
    return false;
  }
}

bool TLObject::ParseFromIOBuf(IOBufReader& iobr, bool is_read_class_id) {
  // CHECK(io_buf) << "ParseFromIOBuf - io_buf is nullptr";
  bool rv = true;
  // IOBufReader iobr(io_buf);
  try {
    if (is_read_class_id) {
      TLClassID class_id = iobr.readLE<uint32_t>();
      if (class_id != GetClassID()) {
        LOG(ERROR) << "ParseFromIOBuf - Oh my god!!! read class_id: " << class_id << ", object's class_id: " << GetClassID();
        rv = false;
      }
    }
    
    if (rv) {
      rv = Decode(iobr);
    }
  } catch(const std::exception& e) {
    LOG(ERROR) << "ParseFromIOBuf - catch a threwn exception: " << folly::exceptionStr(e);
    rv = false;
  } catch (...) {
    LOG(ERROR) << "ParseFromIOBuf - catch a unknown threwn exception";
    rv = false;
  }
  
  return rv;
}

bool TLObject::SerializeToIOBuf(IOBufWriter& iobw) const {
  bool rv = true;
  try {
    iobw.writeLE(GetClassID());
    rv = Encode(iobw);
  } catch(const std::exception& e) {
    LOG(ERROR) << "SerializeToIOBuf - catch a threwn exception: " << folly::exceptionStr(e);
    rv = false;
  } catch (...) {
    LOG(ERROR) << "SerializeToIOBuf - catch a unknown threwn exception";
    rv = false;
  }
  return rv;
}
