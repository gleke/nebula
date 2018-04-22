// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

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

#include "nebula/base/crypto_util/base64.h"

#include <stddef.h>

#include "nebula/base/crypto_util/modp_b64/modp_b64.h"

namespace nebula {

void Base64Encode(const folly::StringPiece& input, std::string* output) {
  std::string temp;
  temp.resize(modp_b64_encode_len(input.size()));  // makes room for null byte

  // modp_b64_encode_len() returns at least 1, so temp[0] is safe to use.
  size_t output_size = modp_b64_encode(&(temp[0]), input.data(), input.size());

  temp.resize(output_size);  // strips off null byte
  output->swap(temp);
}

bool Base64Decode(const folly::StringPiece& input, std::string* output) {
  std::string temp;
  temp.resize(modp_b64_decode_len(input.size()));

  // does not null terminate result since result is binary data!
  size_t input_size = input.size();
  size_t output_size = modp_b64_decode(&(temp[0]), input.data(), input_size);
  if (output_size == MODP_B64_ERROR)
    return false;

  temp.resize(output_size);
  output->swap(temp);
  return true;
}

}  // namespace nebula
