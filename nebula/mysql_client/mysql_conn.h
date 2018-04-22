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

#ifndef NEBULA_MYSQL_CLIENT_MYSQL_CONN_H_
#define NEBULA_MYSQL_CLIENT_MYSQL_CONN_H_

#ifdef OS_WIN
#include <winsock2.h>
#endif

#include <map>
#include <mysql.h>
#include <folly/Range.h>

#include "nebula/base/stl_util.h"
#include "nebula/base/time_util.h"

#include "nebula/mysql_client/mysql_result_set.h"

//------------------------------------------------------------------------
struct DBAddrInfo {
  DBAddrInfo()
  : port(0),
    min_conn_count(2),
    max_conn_count(5) {
  }
  
  // bool ParseFromConnString(const base::StringPiece& conn_string);
  // bool ParseFromConfigFile(const base::ConfigFile& config_file, const char* section_name);
  
  // void PrintDebugString();
  
  void Destroy() {
    port = 0;
    min_conn_count = 2;
    max_conn_count = 5;
    
    STLClearObject(&host);
    STLClearObject(&user);
    STLClearObject(&passwd);
    STLClearObject(&db_name);
    STLClearObject(&db_type);
  }
  
  std::string host;
  int port;
  std::string user;
  std::string passwd;
  std::string db_name;
  std::string db_type;
  int min_conn_count;
  int max_conn_count;
};

//------------------------------------------------------------------------
class MysqlConn {
public:
  MysqlConn();
  virtual ~MysqlConn();
  
  bool Connect(const DBAddrInfo& db_addr) {
    db_addr_ = db_addr;
    return BuildConnection();
  }
  void Close();
  
  bool Ping();
  uint32_t GetIdleDuration() const {
    return Now() - last_query_time_;
  }
  uint32_t GetPingDuration() const {
    return Now() - last_ping_time_;
  }
  
  // 查询语句
  MysqlResultSetPtr Query(const folly::StringPiece& q_str);
  // 插入
  // 返回INSERT 操作产生的 ID
  uint64_t ExecuteInsertID(const folly::StringPiece& q_str);
  // 插入和更新
  int Execute(const folly::StringPiece& q_str);
  
protected:
  bool CheckConnection();
  bool BuildConnection();
  
private:
  int MysqlSafeQuery(const folly::StringPiece& q_str, int* err);
  
  void SetLastQueryTime() {
    last_query_time_ = Now();
  }
  
  DBAddrInfo db_addr_;
  st_mysql* my_;
  st_mysql mysql_;

  // 连接维护，最后连接成功时间
  uint32_t last_ping_time_ {0};
  // 最后访问时间
  uint32_t last_query_time_ {0};
};

#endif
