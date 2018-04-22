/*
 *  Copyright (c) 2016, https://github.com/nebula-im
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

#include "nebula/redis_client/redis_conn_pool.h"

#include <folly/Format.h>


size_t RedisConnPool::Initialize(const RedisAddrInfo& addr) {
  addr_ = addr;
  conn_pool_.resize(addr.max_conn_count);
  
  for (int i=0; i<addr.max_conn_count; ++i) {
    conn_pool_[i].state = RedisConnection::kConnState_Created;
    conn_pool_[i].conn = new RedisConn;
    
    if (i<addr.min_conn_count) {
      if (0 == conn_pool_[i].conn->Open(addr)) {
        conn_pool_[i].state = RedisConnection::kConnState_Idle;
      }
      conned_pointer_++;
    }
  }
  
  return conned_pointer_;
}

void RedisConnPool::Shutdown() {
  for (size_t i=0; i<conn_pool_.size(); ++i) {
    if (conn_pool_[i].conn != NULL) {
      delete conn_pool_[i].conn;
    }
  }
  conn_pool_.clear();
}

RedisConn* RedisConnPool::GetFreeConnection() {
  RedisConn* conn = NULL;
  std::lock_guard<std::mutex> g(mutex_);
  
  for (int i=0; i<conned_pointer_; ++i) {
    if (conn_pool_[i].state == RedisConnection::kConnState_Idle) {
      conn_pool_[i].state = RedisConnection::kConnState_Busy;
      conn = conn_pool_[i].conn;
      break;
    }
  }
  if (conn == NULL && conned_pointer_ < addr_.max_conn_count
      && conn_pool_[conned_pointer_].state==RedisConnection::kConnState_Created) {
    // 连接到db
    if (0 == conn_pool_[conned_pointer_].conn->Open(addr_)) {
      conn_pool_[conned_pointer_].state = RedisConnection::kConnState_Busy;
      conn = conn_pool_[conned_pointer_].conn;
      conned_pointer_++;
    }
  }
  return conn;
}

void RedisConnPool::SetFreeConnection(RedisConn* conn) {
  std::lock_guard<std::mutex> g(mutex_);
  for (int i=0; i<conned_pointer_; ++i) {
    if (conn_pool_[i].conn == conn) {
      conn_pool_[i].state = RedisConnection::kConnState_Idle;
      break;
    }
  }
}

namespace {
  
std::shared_ptr<RedisConnPool> Make(const std::string name) {
  RedisAddrInfo addr;
  addr.name = name;
  auto pool = std::make_shared<RedisConnPool>();
  pool->Initialize(addr);
  return pool;
}
  
}

RedisConnPool* GetRedisConnPool(const std::string& name) {
  // TODO(@benqi): 有问题
  static std::map<std::string, std::shared_ptr<RedisConnPool>> g_redis_conn_pools;
  
  auto it = g_redis_conn_pools.find(name);
  if (it==g_redis_conn_pools.end()) {
    auto conn_pool = Make(name);
    g_redis_conn_pools[name] = conn_pool;
    return conn_pool.get();
  } else {
    return it->second.get();
  }
}
