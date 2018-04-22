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

#ifndef NEBULA_MYSQL_CLIENT_MYSQL_CONN_POOL_MANAGER_H_
#define NEBULA_MYSQL_CLIENT_MYSQL_CONN_POOL_MANAGER_H_

#include <folly/io/async/EventBase.h>
#include <folly/fibers/Baton.h>

#include <wangle/concurrent/CPUThreadPoolExecutor.h>
#include "nebula/mysql_client/mysql_conn_pool.h"

struct QueryResult {
  MysqlResultSet& operator*() const {
    CHECK(result_set);
    return *(result_set);
  }
  
  const MysqlResultSetPtr& operator->() const {
    CHECK(result_set);
    return result_set;
  }

  MysqlResultSetPtr& operator->() {
    CHECK(result_set);
    return result_set;
  }

  MysqlResultSetPtr get() const {
    return result_set;
  }
  
  operator bool() const {
    return errcode == 0 && result_set.get() != nullptr;
  }
  
  bool operator! () const {
    return errcode != 0 || result_set.get() == nullptr;
  }
  
  int GetErrcode() const {
    return errcode;
  }
  
  // 无可用连接
  // 超时
  // 负载太大
  // 查询出错
  int errcode {-1};
  MysqlResultSetPtr result_set;
};
// typedef std::shared_ptr<QueryResult> QueryResultPtr;

class MysqlClient {
public:
  MysqlClient() = default;
  ~MysqlClient() = default;

  // 一个管理线程
  // 一个线程池
  bool Initialize(const std::vector<DBAddrInfo>& db_addr_list,
                  std::shared_ptr<wangle::CPUThreadPoolExecutor> db_thread_pool);
  
  class MysqlConnectionPool {
  public:
    explicit MysqlConnectionPool(const DBAddrInfo& db_addr, wangle::CPUThreadPoolExecutor* thread_pool)
      : thread_pool_(thread_pool) {
        conn_pool_ = new MysqlConnPool();
        conn_pool_->Initialize(db_addr);
    }
    
    ~MysqlConnectionPool() {
      if (conn_pool_) delete conn_pool_;
    }
   
    // 异步
    // 同步
    // 协程同步
    
    // 查询语句
    QueryResult Query(const folly::StringPiece& q_str);
    // 插入
    // 返回INSERT 操作产生的 ID
    uint64_t ExecuteInsertID(const folly::StringPiece& q_str);
    // 插入和更新
    int Execute(const folly::StringPiece& q_str);

  private:
    MysqlConnPool* conn_pool_ {nullptr};
    wangle::CPUThreadPoolExecutor* thread_pool_ {nullptr};
  };
  
  MysqlConnectionPool* GetConnPool(const std::string& name);

private:
  typedef std::map<std::string, std::shared_ptr<MysqlConnectionPool>> MysqlConnPoolMgr;
  MysqlConnPoolMgr conn_pool_mgr_;
  
  std::shared_ptr<wangle::CPUThreadPoolExecutor> db_thread_pool_;
  // folly::EventBase* main_evb_{nullptr};
};

bool InitializeMysqlClient(const std::vector<DBAddrInfo>& db_addr_list, size_t thread_size = 0);
MysqlClient::MysqlConnectionPool* GetMysqlConnPool(const std::string& name);

#endif
