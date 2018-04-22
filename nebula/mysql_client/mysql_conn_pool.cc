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

#include "nebula/mysql_client/mysql_conn_pool.h"

#include <folly/Format.h>

// 90秒保活
#define PING_TIMEOUT  90
// 踢掉空闲连接
#define KICKOUT_IDLE_CONN_TIMEOUT  900

MysqlConnPool::~MysqlConnPool() {
  Shutdown();
}

size_t MysqlConnPool::Initialize(const DBAddrInfo& db_addr) {
  std::lock_guard<std::mutex> g(mutex_);

  db_addr_ = db_addr;
  //conn_string_ = conn_string;
  
  //min_conn_count_ = min_conn_count;
  //max_conn_count_ = max_conn_count;
  
  conn_pool_.resize(db_addr.max_conn_count);
  
  for (int i=0; i<db_addr.max_conn_count; ++i) {
    conn_pool_[i].state = MysqlConnection::kState_Created;
    conn_pool_[i].conn = new MysqlConn();
    //conn_pool_[i].conn = new MySQLDatabase();
    
    if (i<db_addr.min_conn_count) {
      if (conn_pool_[i].conn->Connect(db_addr)) {
        conn_pool_[i].state = MysqlConnection::kState_Idle;
      }
      conned_pointer_++;
    }
  }
  
  return conned_pointer_;
}

void MysqlConnPool::Shutdown() {
  std::lock_guard<std::mutex> g(mutex_);
  for (size_t i=0; i<conn_pool_.size(); ++i) {
    if (conn_pool_[i].conn != NULL) {
      delete conn_pool_[i].conn;
    }
  }
  conn_pool_.clear();
  conned_pointer_ = 0;
}

MysqlConn* MysqlConnPool::GetFreeConnection() {
  MysqlConn* conn = NULL;
  std::lock_guard<std::mutex> g(mutex_);
  
  for (int i=0; i<conned_pointer_; ++i) {
    if (conn_pool_[i].state == MysqlConnection::kState_Idle) {
      conn_pool_[i].state = MysqlConnection::kState_Busy;
      conn = conn_pool_[i].conn;
      break;
    }
  }
  if (conn == NULL && conned_pointer_ < db_addr_.max_conn_count
      && conn_pool_[conned_pointer_].state==MysqlConnection::kState_Created) {
    // 连接到db
    if (conn_pool_[conned_pointer_].conn->Connect(db_addr_)) {
      conn_pool_[conned_pointer_].state = MysqlConnection::kState_Busy;
      conn = conn_pool_[conned_pointer_].conn;
      conned_pointer_++;
    }
  }
  return conn;
}

void MysqlConnPool::SetFreeConnection(MysqlConn* conn) {
  std::lock_guard<std::mutex> g(mutex_);
  for (int i=0; i<conned_pointer_; ++i) {
    if (conn_pool_[i].conn == conn) {
      conn_pool_[i].state = MysqlConnection::kState_Idle;
      break;
    }
  }
}

// 定时维护连接
void MysqlConnPool::OnTimer() {
  std::lock_guard<std::mutex> g(mutex_);
  
  // Kick out idle conn
  if (conned_pointer_>db_addr_.min_conn_count) {
    for (int i=0; i<conned_pointer_; ++i) {
      if (conn_pool_[i].state == MysqlConnection::kState_Idle) {
        if (conn_pool_[i].conn->GetIdleDuration() >= KICKOUT_IDLE_CONN_TIMEOUT) {
          conn_pool_[i].conn->Close();
          conn_pool_[i].state = MysqlConnection::kState_Created;
          if (i!=conned_pointer_-1) {
            conn_pool_[i].Swap(conn_pool_[conned_pointer_-1]);
          }
          --conned_pointer_;
        }
      }
    }
  }
  
  for (int i=0; i<conned_pointer_; ++i) {
    // PING_TIMEOUT保活
    if (conn_pool_[i].state == MysqlConnection::kState_Idle) {
      if (conn_pool_[i].conn->GetPingDuration() >= PING_TIMEOUT) {
        conn_pool_[i].conn->Ping();
      }
    }
  }
}

