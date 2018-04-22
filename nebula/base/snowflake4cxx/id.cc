/*
 *  Copyright (c) 2016, https://github.com/nebula-im/snowflake4cxx
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
 *
 */

#include "nebula/base/snowflake4cxx/id.h"

#include <sys/time.h>

namespace snowflake4cxx {

namespace {
  
// TODO(@benqi): 更高效的gettimeofday实现
inline uint64_t NowInMsec() {
  timeval tv;
  gettimeofday(&tv, 0);
  return uint64_t(tv.tv_sec) * 1000 + tv.tv_usec/1000;
}
  
uint64_t WaitUntilNextMillis(uint64_t last_timestamp) {
  uint64_t timestamp = NowInMsec();
  while (timestamp <= last_timestamp) {
    timestamp = NowInMsec();
  }
  return timestamp;
}

}

uint64_t IdWorkerUnThreadSafe::GetNextID() {
  uint64_t timestamp = NowInMsec();
  
  // 在当前秒内
  if (last_timestamp_ == timestamp) {
    sequence_ = (sequence_ + 1) & 0xFFF;
    if (sequence_ == 0) {
      timestamp = WaitUntilNextMillis(last_timestamp_);
    }
  } else {
    sequence_ = 0;
  }
  
  last_timestamp_ = timestamp;
  return ((timestamp & 0x1FFFFFF) << 22 |
          (data_center_id_ & 0x1F) << 17 |
          (worker_id_& 0x1F) << 12 |
          (sequence_ & 0xFFF));
  
}

}

