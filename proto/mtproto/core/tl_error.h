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

#include "proto/mtproto/core/object.h"

namespace mtproto {

// True
class Error : public TLObject {
public:
  virtual ~Error() override = default;
};

// error#c4b9f9bb code:int text:string = Error;
class TL_error: public Error {
public:
  enum {
    CLASS_ID = 0xc4b9f9bb,
  };

  // static const TLClassID CLASS_ID = 0xc4b9f9bb;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  std::string ToString() const override {
    return "error#c4b9f9bb";
  }
  
protected:
  bool Decode(IOBufReader& iobr) override {
    code_ = iobr.readLE<int32_t>();
    ReadString(iobr, &text_);
    return true;
  }
  
  bool Encode(IOBufWriter& iobw) const override {
    iobw.writeLE(code_);
    WriteString(iobw, text_);
    return true;
  }

private:
  int32_t code_;
  TLString text_;
};

}

#endif
