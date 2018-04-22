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

#include "nebula/mysql_client/mysql_conn.h"

#include <mysql/mysqld_error.h>

#include <folly/Format.h>
#include <folly/Conv.h>

#include "nebula/base/logger/glog_util.h"

// TODO(@benqi): 配置
#define DEFAULT_MYSQL_SET_CHARSET_NAME "utf8mb4"

//------------------------------------------------------------------------
MysqlConn::MysqlConn()
  : my_(NULL) {
  
  last_ping_time_ = last_query_time_ = Now();
}

MysqlConn::~MysqlConn() {
  Close();
}

MysqlResultSetPtr MysqlConn::Query(const folly::StringPiece& q_str) {
  DCHECK(!q_str.empty()) << "Querystring is not empty";
  
  MysqlResultSetPtr mysql_result;

  SetLastQueryTime();
  if (CheckConnection()) {
    int er=0;
    if (MysqlSafeQuery(q_str, &er)) {
      LOG(ERROR) << mysql_error(my_) << ". In sql: " << q_str;
    } else {
      MYSQL_RES *res = mysql_store_result(my_);
      if (!res) {
        LOG(ERROR) << "mysql_store_result failed: " << mysql_error(my_);
        // return NULL;
      } else {
        // MYSQL_RES *res = mysql_store_result(my_);
        uint64_t rows = mysql_affected_rows(my_);
        uint32_t fields = mysql_field_count(my_);
        mysql_result = std::make_shared<MysqlResultSet>(res, fields, rows);
      }
      
      // MysqlResultSet result_set(res);
      // result_set;
    }
  }
  
  // MysqlResultSet mysql_result;
  return mysql_result;
}

uint64_t MysqlConn::ExecuteInsertID(const folly::StringPiece& q_str) {
  DCHECK(!q_str.empty()) << "Querystring is not empty";
  
  SetLastQueryTime();
  if (!CheckConnection()) return 0;
  
  uint64_t ret = 0;
  int er=0;
  if (MysqlSafeQuery(q_str, &er)) {
    LOG(ERROR) << mysql_error(my_) << ". In sql: " << q_str;
  } else {
    ret = mysql_insert_id(my_);
  }
  
  return ret;
}

int MysqlConn::Execute(const folly::StringPiece& q_str) {
  DCHECK(!q_str.empty()) << "Querystring is not empty";
  
  SetLastQueryTime();
  if (!CheckConnection()) return -2000;
  
  int er=0;
  int res = MysqlSafeQuery(q_str, &er);
  if (res) {
    LOG(ERROR) << mysql_error(my_) << ". In sql: " << q_str;
    return -res;
  } else {
    return static_cast<int>(mysql_affected_rows(my_));
  }
}

//bool MySQLDatabase::Open(const base::StringPiece& conn_string) {
//  return BaseDatabase::Open(conn_string);
//}

void MysqlConn::Close() {
  if (my_) {
    mysql_close(my_);
    my_ = NULL;
  }
}

int MysqlConn::MysqlSafeQuery(const folly::StringPiece& q_str, int* err) {
  int res = mysql_real_query(my_, q_str.data(), q_str.size());
  if (res) {
    *err = mysql_errno(my_);
    LOG(ERROR) << "mysql_real_query failed: " << mysql_error(my_) << ", sql: " <<  q_str;
    
    switch (*err) {
      case 1040: // ER_CON_COUNT_ERROR
      case 1042: // ER_BAD_HOST_ERROR
      case 1043: // ER_HANDSHAKE_ERROR
      case 1047: // ER_UNKNOWN_COM_ERROR
      case 1081: // ER_IPSOCK_ERROR
      case 1129: // ER_HOST_IS_BLOCKED
      case 1130: // ER_HOST_NOT_PRIVILEGED
      case 2013: // CR_SERVER_LOST
        {
          res = mysql_ping(my_);
          if ( res ) {
            *err = mysql_errno(my_);
            LOG(ERROR) << "Reconnect to db failed!! err: " << mysql_error(my_);
            // goto line100;
            // return false;
            // 尝试重新建立连接
            break;
          }
        
          last_ping_time_ = Now();

          res = mysql_real_query(my_, q_str.data(), q_str.size());
          if ( res ) {
            *err = mysql_errno(my_);
            // 连接建立成功，但查询还是出错
            LOG(ERROR) << "mysql_real_query failed: " << mysql_error(my_) << ", sql: " <<  q_str;
            return res;
          }
          return res;
        }
        break;
      default:
        LOG(ERROR) << "mysql_real_query failed: " << mysql_error(my_) << ", sql: " <<  q_str;
        // return false;
        // 尝试重新建立连接
        break;
    }

    // 重新建立连接
    if (BuildConnection()) {
      res = mysql_real_query(my_, q_str.data(), q_str.size());
      if (res) {
        *err = mysql_errno(my_);
      }
    }
  } else {
    last_ping_time_ = Now();
  }
  
  return res;
}

bool MysqlConn::CheckConnection() {
  if (my_) return true;
  
  LOG(ERROR) << "Mysql connection not initialized, ready BuildConnection...";
  return BuildConnection();
}

bool MysqlConn::BuildConnection() {
  Close();
  
  MYSQL *my_temp;
  my_temp = mysql_init(&mysql_);
  if (!my_temp) {
    LOG(ERROR) << "Could not initialize Mysql connection";
    return false;
  }
  
  my_bool my_true = (my_bool)1;
  mysql_options(my_temp, MYSQL_OPT_RECONNECT, &my_true);
  mysql_options(my_temp, MYSQL_SET_CHARSET_NAME, DEFAULT_MYSQL_SET_CHARSET_NAME);
  
  my_ = my_temp;
  my_ = mysql_real_connect(my_,
                           db_addr_.host.c_str(),
                           db_addr_.user.c_str(),
                           db_addr_.passwd.c_str(),
                           db_addr_.db_name.c_str(),
                           db_addr_.port,
                           NULL,
                           0);
  
  if (!my_) {
    LOG(ERROR) << "Could not connect to MySQL database at "
          << db_addr_.host
          << ": "
          << mysql_error(my_temp);
    return false;
  }
  
  last_ping_time_ = Now();
  return true;
}

bool MysqlConn::Ping() {
  int er = mysql_ping(my_);
  if (er != 0) {
    // rv = _Reconnect(static_cast<MySQLDatabaseConnection*>(con_ptr));
  } else {
    // 成功执行ping
    last_ping_time_ = Now();
  }
  return er==0;
}

