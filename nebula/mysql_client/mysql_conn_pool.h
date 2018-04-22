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

#ifndef NEBULA_MYSQL_CLIENT_MYSQL_CONN_POOL_H_
#define NEBULA_MYSQL_CLIENT_MYSQL_CONN_POOL_H_

#include "nebula/base/basictypes.h"

#include <string>
#include <vector>
#include <mutex>

#include "nebula/mysql_client/mysql_conn.h"

class MysqlConnPool {
public:
  MysqlConnPool()
    : conned_pointer_(0) {}
  ~MysqlConnPool();
  
  // 返回连接mysql数量
  size_t Initialize(const DBAddrInfo& db_addr);
  // 小心使用，必须所有的连接回收以后才能执行
  void Shutdown();
  
  MysqlConn* GetFreeConnection();
  void SetFreeConnection(MysqlConn* conn);
  
  // Mysql连接维护
  void OnTimer();
  
private:
  friend class ScopedMysqlConn;

  struct MysqlConnection {
    enum MysqlConnState {
      kState_Null = 0,    // 因为未知原因导致db未创建
      kState_Created = 1, // 已创建但未连接到数据库
      kState_Idle = 2,    // 已连接空闲
      kState_Busy = 3,    // 已连接正在提供服务
    };
    
    MysqlConnection()
      : state(kState_Null),
        conn(NULL) {}
    
    void Swap(MysqlConnection& _conn) {
      std::swap(*this, _conn);
    }
    
    // 是否空闲
    MysqlConnState state;
    // is_idle;
    MysqlConn* conn;
  };
  
  //std::string conn_string_;
  DBAddrInfo db_addr_;
  
  // 同步
  std::mutex mutex_;
  std::vector<MysqlConnection> conn_pool_;
  
  // 当前已经创建的连接数
  int conned_pointer_;
};

class ScopedMysqlConn {
public:
  explicit ScopedMysqlConn(MysqlConnPool* db) {
    CHECK(db);
    db_ = db;
    db_conn_ = db_->GetFreeConnection();
  }
  
  ~ScopedMysqlConn() {
    release();
  }
  
  MysqlConn& operator*() const {
    CHECK(db_conn_);
    return *(db_conn_);
  }
  
  MysqlConn* operator->() const {
    CHECK(db_conn_);
    return db_conn_;
  }
  
  MysqlConn* get() const {
    return db_conn_;
  }
  
  operator bool() const {
    return db_conn_ !=0;
  }
  
  bool operator! () const {
    return db_conn_ == 0;
  }
  
  void release() {
    if (db_conn_) {
      db_->SetFreeConnection(db_conn_);
      db_conn_ = NULL;
    }
  }
  
private:
  MysqlConnPool* db_;
  mutable MysqlConn* db_conn_;
  
  DISALLOW_COPY_AND_ASSIGN(ScopedMysqlConn);
};

#endif
