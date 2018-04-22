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

#include "nebula/redis_client/redis_client.h"

bool RedisConnPoolMgr::Initialize(const std::vector<RedisAddrInfo>& redis_addr_list) {
  for (const auto & addr : redis_addr_list) {
    auto pool = std::make_shared<RedisConnPool>();
    pool->Initialize(addr);
    conn_pools_.insert(std::make_pair(addr.name, pool));
  }
  return true;
}

