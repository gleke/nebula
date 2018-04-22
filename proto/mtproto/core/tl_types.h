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

#ifndef PROTO_MTPROTO_CORE_TL_TYPES_H
#define PROTO_MTPROTO_CORE_TL_TYPES_H

#include <openssl/rand.h>

#include <folly/FBString.h>
#include <folly/FBVector.h>
#include <folly/Range.h>

#include <folly/io/Cursor.h>
#include <folly/Format.h>

// typedef uint32_t TLClassID;

typedef uint32_t TLClassID;

namespace mtproto {
  
// auth层
template <size_t N>
struct TLIntN {
  bool Compare(const TLIntN<N>& other) {
    return memcmp(data, other.data, N) == 0;
  }

  bool Compare(const TLIntN<N>* other) {
    if (!other) return false;
    return memcmp(data, other->data, N) == 0;
  }

  bool Copy(const TLIntN<N>& other) {
    memcpy(data, other.data, N);
    return true;
  }

  bool Copy(const uint8_t* other, size_t n = N) {
    if (N!=n) {
      // LOG(ERROR) << "";
      return false;
    }
    memcpy(data, other, N);
    return true;
  }

  bool Copy(folly::ByteRange other) {
    if (other.size()!=N) {
      // LOG(ERROR) << "";
      return false;
    }
    memcpy(data, other, N);
    return true;
  }

  bool Copy(const folly::ByteRange& other) {
    if (other.size()!=N) {
      // LOG(ERROR) << "";
      return false;
    }
    memcpy(data, other.data(), N);
    return true;
  }

  bool Copy(const std::string& other) {
    if (other.length()!=N) {
      // LOG(ERROR) << "";
      return false;
    }
    memcpy(data, other.data(), N);
    return true;
  }

  bool Copy(const folly::fbstring& other) {
    if (other.length()!=N) {
      // LOG(ERROR) << "";
      return false;
    }
    memcpy(data, other.data(), N);
    return true;
  }

  size_t size() const {
    return N;
  }
  
  uint8_t data[N];
  // size_t size {N};
};

using  TLInt128 = TLIntN<16>;
using  TLInt256 = TLIntN<32>;
using  TLInt512 = TLIntN<64>;
using TLInt1024 = TLIntN<128>;
using TLInt2048 = TLIntN<256>;

/*
// std::array<uint8_t, 16>;
using TLInt256 = std::array<uint8_t, 32>;
using TLInt512 = std::array<uint8_t, 64>;
using TLInt1024 = std::array<uint8_t, 128>;
*/

using TLString = std::string;
// template <typename T>
// using TLVector = folly::fbvector<T>;

template <size_t N>
inline void RandTLIntN(TLIntN<N>& o) {
  RAND_bytes(o.data, N);
}

template <size_t N>
inline void RandTLIntN(TLIntN<N>* o) {
  RAND_bytes(o->data, N);
}
  
}


inline std::string ToHexStr(const mtproto::TLString& sp) {
  std::string out;
  for (auto ch : sp) {
    out.append(folly::sformat("{:02x}", (uint8_t) ch));
  }
  return out;
}

template <size_t N>
std::string ToHexStr(const mtproto::TLIntN<N>& sp) {
  std::string out;
  for (size_t i=0; i<N; ++i) {
    out.append(folly::sformat("{:02x}", sp.data[i]));
  }
  return out;
}

#endif
