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

#ifndef PROTO_MTPROTO_CORE_TL_NULL_H
#define PROTO_MTPROTO_CORE_TL_NULL_H

#include "proto/mtproto/core/object.h"

namespace mtproto {

// True
class Null : public TLObject {
public:
  virtual ~Null() override = default;
};

// null#56730bcc = Null;
class TL_null: public Null {
public:
  enum {
    CLASS_ID = 0x56730bcc,
  };

  // static const TLClassID CLASS_ID = 0x56730bcc;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  std::string ToString() const override {
    return "null#56730bcc";
  }

protected:
  bool Decode(IOBufReader& iobr) override {
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    return true;
  }
};
  
}

#endif
