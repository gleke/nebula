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

#ifndef NEBULA_BASE_JSON_JSON_H_
#define NEBULA_BASE_JSON_JSON_H_

// #include <folly/dynamic.h>
// #include <folly/DynamicConverter.h>
// #if 0
// #define PATCH_BY_BENQI

#include <folly/json.h>
#include <folly/io/IOBuf.h>
#include "nebula/base/reflection_util.h"
#include "nebula/base/json/dynamic_converter.h"

// using namespace kapok;

// 使用go语言json接口
template<typename T>
inline T Unmarshal(const folly::dynamic& root) {
  return JsonConvertTo<T>(root);
}

// 会抛出异常...
template<typename T>
inline folly::dynamic Marshal(const T& o, const char* key = nullptr) {
  if (key == nullptr || key[0] == '\0' ) {
    return ToJsonDynamic(o);
  } else {
    return folly::dynamic::object(key, ToJsonDynamic(o));
  }
}

inline std::unique_ptr<folly::IOBuf> ToJsonIOBuf(const folly::dynamic& d) {
  auto&& json = folly::toJson(d);
  return folly::IOBuf::copyBuffer(json.c_str(), json.length());
}

#endif
