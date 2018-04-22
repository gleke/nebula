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

#include "nebula/mysql_client/mysql_client.h"

MysqlClient g_mysql_client;

bool InitializeMysqlClient(const std::vector<DBAddrInfo>& db_addr_list, size_t thread_size) {
  if (thread_size == 0) thread_size = 8;
  auto thread_pool = std::make_shared<wangle::CPUThreadPoolExecutor>(thread_size);
  // MysqlClient mysql_client;
  return g_mysql_client.Initialize(db_addr_list, thread_pool);
}

MysqlClient::MysqlConnectionPool* GetMysqlConnPool(const std::string& name) {
  return g_mysql_client.GetConnPool(name);
}

bool MysqlClient::Initialize(const std::vector<DBAddrInfo>& db_addr_list,
        std::shared_ptr<wangle::CPUThreadPoolExecutor> db_thread_pool) {
  db_thread_pool_ = db_thread_pool;
  if (!db_thread_pool_) {
    db_thread_pool_ = std::make_shared<wangle::CPUThreadPoolExecutor>(8);
  }

  for (const auto & db_addr : db_addr_list) {
    auto pool = std::make_shared<MysqlConnectionPool>(db_addr, db_thread_pool_.get());
    conn_pool_mgr_.insert(std::make_pair(db_addr.db_name, pool));
  }
  return true;
}

MysqlClient::MysqlConnectionPool* MysqlClient::GetConnPool(const std::string& name) {
  MysqlClient::MysqlConnectionPool* pool = nullptr;
  auto it = conn_pool_mgr_.find(name);
  if (it!=conn_pool_mgr_.end()) {
    pool = it->second.get();
  }
  return pool;
}

// 查询语句
QueryResult MysqlClient::MysqlConnectionPool::Query(const folly::StringPiece& q_str) {
  QueryResult query_result;
  folly::fibers::Baton baton;
  
  // 如下几种情况:
  // 1. Query超时
  // 2. 
  thread_pool_->add([&] () {
    // mysql_client_->conn_pool_mgr_.GetMysqlConnPool(instance_name);
    ScopedMysqlConn conn(conn_pool_);
    if (conn) {
      query_result.result_set = conn->Query(q_str);
      query_result.errcode = 0;
    } else {
      query_result.errcode = -1;
    }
    
    baton.post();
  });
  
  baton.wait();
  return query_result;
}

// 插入
// 返回INSERT 操作产生的 ID
uint64_t MysqlClient::MysqlConnectionPool::ExecuteInsertID(const folly::StringPiece& q_str) {
  // auto query_result = std::make_shared<QueryResult>();
  uint64_t r = -1;
  folly::fibers::Baton baton;
  
  thread_pool_->add([&] () {
    ScopedMysqlConn conn(conn_pool_);
    if (conn) {
      r = conn->ExecuteInsertID(q_str);
    }
    baton.post();
  });
  
  baton.wait();
  return r;
}

// 插入和更新
int MysqlClient::MysqlConnectionPool::Execute(const folly::StringPiece& q_str) {
  // auto query_result = std::make_shared<QueryResult>();
  int r = -1;
  folly::fibers::Baton baton;
  
  thread_pool_->add([&] () {
    ScopedMysqlConn conn(conn_pool_);
    if (conn) {
      r = conn->Execute(q_str);
    }
    baton.post();
  });
  
  baton.wait();
  return r;
}
