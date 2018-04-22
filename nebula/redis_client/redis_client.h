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

#ifndef NEBULA_REDIS_CLIENT_REDIS_CLIENT_H_
#define NEBULA_REDIS_CLIENT_REDIS_CLIENT_H_

#include <wangle/concurrent/CPUThreadPoolExecutor.h>
#include "nebula/redis_client/redis_conn_pool.h"

class RedisConnPoolMgr {
public:
  RedisConnPoolMgr() = default;
  ~RedisConnPoolMgr() = default;
  
  // static std::shared_ptr<MysqlConnPoolMgr> GetInstance();
  bool Initialize(const std::vector<RedisAddrInfo>& redis_addr_list);
  
  RedisConnPool* GetRedisConnPool(const std::string& instance_name) {
    // TODO(@benqi): 有问题
    auto it = conn_pools_.find(instance_name);
    if (it!=conn_pools_.end()) {
      return it->second.get();
    }
    
    return nullptr;
  }
  
private:
  std::map<std::string, std::shared_ptr<RedisConnPool>> conn_pools_;
  // std::shared_ptr<wangle::CPUThreadPoolExecutor> db_thread_pool_;
};

#endif // NEBULA_REDIS_CLIENT_REDIS_CLIENT_H_
