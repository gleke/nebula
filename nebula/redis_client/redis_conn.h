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

#ifndef NEBULA_REDIS_CLIENT_REDIS_CONN_H_
#define NEBULA_REDIS_CLIENT_REDIS_CONN_H_

#include <string>
// #include <folly/Range.h>

struct RedisAddrInfo {
  std::string name;
  
  std::string host {"127.0.0.1"};
  int port {6379};
  int db_number {0};
  int min_conn_count {2};
  int max_conn_count {5};
  
  std::string ToString() const;
};

struct redisContext;
class RedisConn {
public:
  RedisConn() = default;
  virtual ~RedisConn() = default;

  int Open(const RedisAddrInfo& addr);
  
  std::string set(const std::string& key, const std::string &value);

  int64_t incr(const std::string& key);
  int64_t incr(const std::string& key, int64_t value);
  int64_t hincr(const std::string& key, const std::string& field);
  int64_t hincr(const std::string& key, const std::string& field, int64_t value);
  
  int64_t decr(const std::string& key);
  int64_t decr(const std::string& key, int64_t value);
  int64_t hdecr(const std::string& key, const std::string& field);
  int64_t hdecr(const std::string& key, const std::string& field, int64_t value);

  
private:
  int ReConnect();
  
  redisContext* 	context_ {nullptr};
  // uint64_t last_connect_time_ {0};

  RedisAddrInfo addr_;
};


#endif // NEBULA_REDIS_CLIENT_REDIS_CONN_H_
