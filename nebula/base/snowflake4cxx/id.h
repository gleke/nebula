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
 *  Twitter的分布式自增ID算法Snowflake的C++移植
 *  参考:
 *    https://github.com/twitter/snowflake
 *    http://itindex.net/detail/53406-twitter-id-%E7%AE%97%E6%B3%95
 *
 */

#ifndef SNOWFLAKE4CXX_ID_WORKER_H_
#define SNOWFLAKE4CXX_ID_WORKER_H_

#include <stdint.h>
#include <mutex>

namespace snowflake4cxx {
  
// 结构为：
//
// 0---0000000000 0000000000 0000000000 0000000000 0 --- 00000 ---00000 ---0000000000 00
// 在上面的字符串中，第一位为未使用（实际上也可作为long的符号位），接下来的41位为毫秒级时间，然后5位datacenter标识位，
// 5位机器ID（并不算标识符，实际是为线程标识），然后12位该毫秒内的当前毫秒内的计数，加起来刚好64位，为一个Long型。
//
// 这样的好处是，整体上按照时间自增排序，并且整个分布式系统内不会产生ID碰撞（由datacenter和机器ID作区分），
// 并且效率较高，经测试，snowflake每秒能够产生26万ID左右，完全满足需要。
//
class IdWorkerUnThreadSafe {
public:
  // TODO(@benqi): 检查worker_id和data_center_id
  IdWorkerUnThreadSafe(uint16_t worker_id, uint16_t data_center_id)
    : worker_id_(worker_id),
      data_center_id_(data_center_id) {}
  
  uint64_t GetNextID();
  
protected:
  uint16_t worker_id_{0};
  uint16_t data_center_id_{0};
  uint64_t last_timestamp_{0};
  uint32_t sequence_{0};
};

class IdWorkerThreadSafe {
public:
  IdWorkerThreadSafe(uint16_t worker_id, uint16_t data_center_id)
    : id_worker_(worker_id, data_center_id) {}
  
  uint64_t GetNextID() {
    std::lock_guard<std::mutex> g(mutex_);
    return id_worker_.GetNextID();
  }
  
protected:
  IdWorkerUnThreadSafe id_worker_;
  std::mutex mutex_;
};

} // namespace snowflake4cxx

#endif

