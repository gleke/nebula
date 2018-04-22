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

#ifndef NEBULA_MYSQL_CLIENT_MYSQL_RESULT_SET_H_
#define NEBULA_MYSQL_CLIENT_MYSQL_RESULT_SET_H_

#ifdef OS_WIN
#include <winsock2.h>
#endif

#include <map>
#include <mysql.h>

#include <iostream>

#include <folly/Range.h>
#include "nebula/base/stl_util.h"
#include "nebula/base/logger/glog_util.h"

#define CHECK_IS_FETCH() if (!is_fetched_) { \
  LOG(ERROR) << "must first call FetchRow()!!!!!"; \
  return false; \
}

//------------------------------------------------------------------------
class MysqlResultSet {
public:
  MysqlResultSet(MYSQL_RES *res, uint32_t columns, uint64_t rows) {
    is_fetched_ = false;
    lengths_ = NULL;
    row_ = NULL;
    res_ = res;
    column_count_ = columns;
    row_count_ = rows;
    fields_ = res->fields;
  }
  
  ~MysqlResultSet() {
    if (res_) {
      mysql_free_result(res_);
    }
    res_ = 0;
    lengths_ = NULL;
  }
  
  inline uint32_t GetColumnCount() const { return column_count_; }
  inline uint64_t GetRowCount() const { return row_count_; }

  std::string GetColumnValue(uint32_t clm) const {
    std::string ret;
    GetColumn(clm, &ret);
    return ret;
  }
  
  std::string GetColumnValue(const folly::StringPiece& clm) const {
    std::string ret;
    GetColumn(clm, &ret);
    return ret;
  }

  bool FetchRow() {
    if (!is_fetched_) is_fetched_ = true;
    if (res_ && (row_ = mysql_fetch_row(res_))) {
      lengths_ = mysql_fetch_lengths(res_);
      return true;
    } else {
      return false;
    }
  }
  
  //------------------------------------------------------------------------
  bool GetColumn(const folly::StringPiece& clm, std::string* val) const {
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      return GetColumn(index, val);
    } else {
      return false;
    }
  }
  
  uint32_t GetColumnLength(const folly::StringPiece& clm) const {
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      return GetColumnLength(index);
    } else {
      return 0;
    }
  }
  
  bool ColumnIsNull(const folly::StringPiece& clm) const {
    bool result = false;
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      result = ColumnIsNull(index);
    }
    return result;
  }
  
  bool GetColumn(const folly::StringPiece& clm, uint64_t* val) const {
    bool result = false;
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      result = GetColumn(index, val);
    }
    return result;
  }
  
  bool GetColumn(const folly::StringPiece& clm, int64_t* val) const {
    bool result = false;
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      result = GetColumn(index, val);
    }
    return result;
  }
  
  bool GetColumn(const folly::StringPiece& clm, uint32_t* val) const {
    bool result = false;
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      result = GetColumn(index, val);
    }
    return result;
  }
  
  bool GetColumn(const folly::StringPiece& clm, int* val) const {
    bool result = false;
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      result = GetColumn(index, val);
    }
    return result;
  }
  
  bool GetColumn(const folly::StringPiece& clm, float* val) const {
    bool result = false;
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      result = GetColumn(index, val);
    }
    return result;
  }
  
  bool GetColumn(const folly::StringPiece& clm, bool* val) const {
    bool result = false;
    uint32_t index = GetIndexByFieldName(clm);
    if (index < column_count_) {
      result = GetColumn(index, val);
    }
    return result;
  }

  virtual void PrintDebugFieldNames() const {
    for (uint32_t i=0; i<column_count_; ++i) {
      std::cout << fields_[i].name << std::endl;
    }
  }
  
  const char* GetColumnName(uint32_t clm) const {
    CHECK(clm < column_count_);
    return fields_[clm].name;
  }
  
  
  bool GetColumn(uint32_t clm, std::string* val) const {
    CHECK_IS_FETCH();
    
    CHECK(clm < column_count_);
    if(row_[clm]) {
      val->clear();
      val->assign(row_[clm], lengths_[clm]);
    } else {
      
    }
    return true;
  }
  
  uint32_t GetColumnLength(uint32_t clm) const {
    CHECK_IS_FETCH();
    
    CHECK(clm < column_count_);
    return static_cast<uint32_t>(lengths_[clm]);
  }
  
  bool ColumnIsNull(uint32_t clm) const {
    CHECK_IS_FETCH();
    
    return row_[clm]==NULL;
  }
  
  
  bool GetColumn(uint32_t clm, uint64_t* val) const {
    CHECK_IS_FETCH();
    
    CHECK(clm < column_count_);
    if (row_[clm]) {
      // TODO(@benqi): 捕获异常
      *val = folly::to<uint64_t>(row_[clm]);
      return true;
    } else {
      *val = 0;
      return false;
    }
  }
  
  bool GetColumn(uint32_t clm, int64_t* val) const {
    CHECK_IS_FETCH();
    
    CHECK(clm < column_count_);
    if (row_[clm]) {
      // TODO(@benqi): 捕获异常
      *val = folly::to<int64_t>(row_[clm]);
      return true;
    } else {
      *val = 0;
      return false;
    }
  }
  
  bool GetColumn(uint32_t clm, uint32_t *val) const {
    CHECK_IS_FETCH();
    
    CHECK(clm < column_count_);
    if (row_[clm]) {
      // TODO(@benqi): 捕获异常
      *val = folly::to<uint32_t>(row_[clm]);
      return true;
    } else {
      *val = 0;
      return false;
    }
  }
  
  bool GetColumn(uint32_t clm, int *val) const {
    CHECK_IS_FETCH();
    
    CHECK(clm < column_count_);
    if (row_[clm]) {
      // TODO(@benqi): 捕获异常
      *val = folly::to<int>(row_[clm]);
      return true;
      
    } else {
      *val = 0;
      return false;
    }
  }
  
  bool GetColumn(uint32_t clm, float* val) const {
    CHECK_IS_FETCH();
    
    CHECK(clm < column_count_);
    if (row_[clm]) {
      // TODO(@benqi): 捕获异常
      *val = folly::to<float>(row_[clm]);
      return true;
      
    } else {
      *val = 0.0;
      return false;
    }
  }
  
  bool GetColumn(uint32_t clm, bool* val) const {
    CHECK_IS_FETCH();
    
    CHECK(clm < column_count_);
    if (row_[clm]) {
      // TODO(@benqi): 捕获异常
      int val2 = folly::to<int>(row_[clm]);
      *val = (val2==0 ? false:true);
      return true;
      
    } else {
      *val = false;
      return false;
    }
  }
  
private:
  uint32_t GetIndexByFieldName(const folly::StringPiece& name) const;
  
  MYSQL_RES *res_;
  MYSQL_ROW row_;
  MYSQL_FIELD* fields_;
  unsigned long *lengths_;
  bool is_fetched_;
  
  uint32_t column_count_;
  uint64_t row_count_;
};

#define DB_GET_RETURN_COLUMN(in, out) \
if (!answ.GetColumn(in, &(out))) { \
  LOG(ERROR) << "Parse column " << #in << " data error."; \
  result = ERROR; \
  break; \
}

#define DB_GET_COLUMN(in, out) \
if (!answ.ColumnIsNull(in)) { \
  out = answ.GetColumnValue(in); \
}

using MysqlResultSetPtr = std::shared_ptr<MysqlResultSet>;

#endif
