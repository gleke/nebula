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

#ifndef PROTO_MTPROTO_CORE_TL_CODEC_UTIL_H
#define PROTO_MTPROTO_CORE_TL_CODEC_UTIL_H

#include "nebula/base/io_buf_util.h"

#include "proto/mtproto/core/tl_types.h"

namespace mtproto {
  
template <typename T>
inline size_t CalcObjSize(const T& t) {
  return t.size();
}

bool ReadString(IOBufReader& iobr, TLString* data);
bool WriteString(IOBufWriter& iobw, const TLString& data);
template<> size_t CalcObjSize(const TLString& t);

template <size_t N>
inline bool ReadTLIntN(IOBufReader& iobr, TLIntN<N>* data) {
  iobr.pull(data->data, N);
  return true;
}

template <size_t N>
inline bool WriteTLIntN(IOBufWriter& iobw, const TLIntN<N>& data) {
  iobw.push(data.data, N);
  return true;
}

}

#endif
