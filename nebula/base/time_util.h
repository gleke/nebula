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

#ifndef BASE_TIME_UTIL_H_
#define BASE_TIME_UTIL_H_

#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>

// 获取毫秒时间
int64_t NowInMsecTime();

// 获取微秒时间
int64_t NowInUsecTime();

//
uint32_t Now();

///////////////////////////////////////////////////////////////////////////////
class DiffTimeUtil {
public:
  DiffTimeUtil() {
    gettimeofday(&now_, nullptr);
  }
  
  void Reset() {
    gettimeofday(&now_, nullptr);
  }
  
  uint64_t GetDiffTime() const {
    struct timeval t;
    gettimeofday(&t, nullptr);
    return static_cast<uint64_t>((t.tv_sec - now_.tv_sec)*1000) + (t.tv_usec - now_.tv_usec)/1000;
  }
  
  struct timeval now_;
};

#endif
