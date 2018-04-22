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

#ifndef PROTO_MTPROTO_CORE_TL_BOOL_H
#define PROTO_MTPROTO_CORE_TL_BOOL_H

#include "nebula/net/telegram/core/object.h"

namespace mtproto {

// Bool
class Bool : public TLObject {
public:
  virtual ~Bool() override = default;
};

// boolTrue#997275b5 = Bool;
class TL_boolTrue : public Bool {
public:
  enum {
    CLASS_ID = 0x997275b5,
  };

  // static const TLClassID CLASS_ID = 0x997275b5;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  std::string ToString() const override {
    return "boolTrue#997275b5";
  }
  
protected:
  bool Decode(IOBufReader& iobr) override {
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    return true;
  }
};

// boolFalse#bc799737 = Bool;
class TL_boolFalse : public Bool {
public:
  enum {
    CLASS_ID = 0xbc799737,
  };

  // static const TLClassID CLASS_ID = 0xbc799737;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  std::string ToString() const override {
    return "boolFalse#0xbc799737";
  }

protected:
  bool Decode(IOBufReader& iobr) override {
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    return true;
  }
};

// True
class True : public TLObject {
public:
  virtual ~True() override = default;
};

// true#3fedd339 = True;
class TL_true: public True {
public:
  enum {
    CLASS_ID = 0x3fedd339,
  };

  // static const TLClassID CLASS_ID = 0x3fedd339;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  std::string ToString() const override {
    return "true#3fedd339";
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
