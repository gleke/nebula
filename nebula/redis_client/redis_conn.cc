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

#include "nebula/redis_client/redis_conn.h"

#include <hiredis/hiredis.h>
#include <folly/Format.h>

#include "nebula/base/logger/glog_util.h"

std::string RedisAddrInfo::ToString() const {
  std::string host;
  int port {6370};
  int db_number {0};
  int min_conn_count {2};
  int max_conn_count {5};

  return folly::sformat("{{host: {}, port: {}, db_number: {}, min_conn_count: {}, max_conn_count: {}}}",
                        host,
                        port,
                        db_number,
                        min_conn_count,
                        max_conn_count);
}

int RedisConn::Open(const RedisAddrInfo& addr) {
  if (context_) {
    return 0;
  }

  addr_ = addr;
  return ReConnect();
}

int RedisConn::ReConnect() {
  //  // 4s 尝试重连一次
  //  uint64_t cur_time = (uint64_t)time(NULL);
  //  if (cur_time < m_last_connect_time + 4) {
  //    return 1;
  //  }
  //
  //  m_last_connect_time = cur_time;
  
  // 200ms超时
  struct timeval timeout = {0, 200000};
  context_ = redisConnectWithTimeout(addr_.host.c_str(), addr_.port, timeout);
  if (!context_ || context_->err) {
    if (context_) {
      LOG(ERROR) << "Open - redisConnect failed: " << context_->errstr << ", by: " << addr_.ToString();
      redisFree(context_);
      context_ = nullptr;
    } else {
      LOG(ERROR) << "Open - redisConnect failed by: " << addr_.ToString();
    }
    
    return 1;
  }
  
  redisReply* reply = (redisReply *)redisCommand(context_, "SELECT %d", addr_.db_number);
  if (reply &&
      (reply->type == REDIS_REPLY_STATUS) &&
      (strncmp(reply->str, "OK", 2) == 0)) {
    freeReplyObject(reply);
    return 0;
  } else {
    LOG(ERROR) << "Open - select cache db failed in: " << addr_.ToString();
    return 2;
  }
}

std::string RedisConn::set(const std::string& key, const std::string &value) {
  std::string ret_value;

  if(ReConnect()) return ret_value;
  
  redisReply* reply = (redisReply *)redisCommand(context_, "SET %s %s", key.c_str(), value.c_str());
  if (!reply) {
    LOG(ERROR) << "set - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return ret_value;
  }
  
  ret_value.append(reply->str, reply->len);
  freeReplyObject(reply);
  return ret_value;
}

int64_t RedisConn::incr(const std::string& key) {
  if(ReConnect()) return -1;
  
  redisReply* reply = (redisReply*)redisCommand(context_, "INCR %s", key.c_str());
  if(!reply) {
    LOG(ERROR) << "incr - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return -1;
  }
  
  int64_t ret_value = reply->integer;
  freeReplyObject(reply);
  return ret_value;
}

int64_t RedisConn::incr(const std::string& key, int64_t value) {
  if(ReConnect()) return -1;
  
  redisReply* reply = (redisReply*)redisCommand(context_, "INCRBY %s %ld", key.c_str(), value);
  if(!reply) {
    LOG(ERROR) << "incr - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return -1;
  }
  
  int64_t ret_value = reply->integer;
  freeReplyObject(reply);
  return ret_value;
}

int64_t RedisConn::hincr(const std::string& key, const std::string& field) {
  if(ReConnect()) return -1;
  
  redisReply* reply = (redisReply *)redisCommand(context_, "HINCRBY %s %s 1", key.c_str(), field.c_str());
  if (!reply) {
    LOG(ERROR) << "hincr - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return -1;
  }
  
  int64_t ret_value = reply->integer;
  freeReplyObject(reply);
  return ret_value;
}

int64_t RedisConn::hincr(const std::string& key, const std::string& field, int64_t value) {
  if(ReConnect()) return -1;
  
  redisReply* reply = (redisReply *)redisCommand(context_, "HINCRBY %s %s %ld", key.c_str(), field.c_str(), value);
  if (!reply) {
    LOG(ERROR) << "hincr - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return -1;
  }
  
  int64_t ret_value = reply->integer;
  freeReplyObject(reply);
  return ret_value;
}

int64_t RedisConn::decr(const std::string& key) {
  if(ReConnect()) return -1;
  
  redisReply* reply = (redisReply *)redisCommand(context_, "DECR %s", key.c_str());
  if (!reply) {
    LOG(ERROR) << "decr - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return -1;
  }
  
  int64_t ret_value = reply->integer;
  freeReplyObject(reply);
  return ret_value;
}

int64_t RedisConn::decr(const std::string& key, int64_t value) {
  if(ReConnect()) return -1;
  
  redisReply* reply = (redisReply *)redisCommand(context_, "DECRBY %s %ld", key.c_str(), value);
  if (!reply) {
    LOG(ERROR) << "decr - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return -1;
  }
  
  int64_t ret_value = reply->integer;
  freeReplyObject(reply);
  return ret_value;
}

int64_t RedisConn::hdecr(const std::string& key, const std::string& field) {
  if(ReConnect()) return -1;
  
  redisReply* reply = (redisReply *)redisCommand(context_, "HINCRBY %s %s -1", key.c_str(), field.c_str());
  if (!reply) {
    LOG(ERROR) << "hdecr - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return -1;
  }
  
  int64_t ret_value = reply->integer;
  freeReplyObject(reply);
  return ret_value;
}

int64_t RedisConn::hdecr(const std::string& key, const std::string& field, int64_t value) {
  if(ReConnect()) return -1;
  
  redisReply* reply = (redisReply *)redisCommand(context_, "HINCRBY %s %s %ld", key.c_str(), field.c_str(), -value);
  if (!reply) {
    LOG(ERROR) << "hdecr - redis Command failed: " << context_->errstr << ", by " << addr_.ToString();
    redisFree(context_);
    context_ = nullptr;
    return -1;
  }
  
  int64_t ret_value = reply->integer;
  freeReplyObject(reply);
  return ret_value;
}
