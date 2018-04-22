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

#ifndef NEBULA_ZORM_ZORM_TEMPLATE_H_
#define NEBULA_ZORM_ZORM_TEMPLATE_H_

#include <list>

#include "nebula/base/reflection_util.h"
#include "nebula/storage/storage_util.h"

struct DAOInterface {
  virtual ~DAOInterface() = default;
};

struct UserDO {
  uint32_t id;
  uint32_t app_id{1};
  std::string user_id;
  std::string avatar;
  std::string nick;
  int status{1};
  uint32_t created_at{0};
  uint32_t updated_at{0};
  
  void PrintDebug() const;
  
  META(id, app_id, user_id, avatar, nick, status, created_at, updated_at);
};

struct UserDAO {
  virtual uint64_t Insert(UserDO& user) = 0;
  virtual std::list<std::shared_ptr<UserDO>> SelectByID(uint64_t id) = 0;
};

template<std::size_t I = 0, typename Tuple>
typename std::enable_if<
    I == std::tuple_size<Tuple>::value
  >::type FromQueryAnswer(const Tuple& t, db::QueryAnswer& answ) {
}

template<std::size_t I = 0, typename Tuple>
typename std::enable_if<
    I < std::tuple_size<Tuple>::value
  >::type FromQueryAnswer(const Tuple& t, db::QueryAnswer& answ) {
  auto fld = std::get<I>(t);
  answ.GetColumn(fld.first, &fld.second);
  FromQueryAnswer<I + 1>(t, answ);
}

struct DBUserDAO : public UserDAO {
  virtual ~DBUserDAO() = default;
  
  virtual uint64_t Insert(UserDO& user) override;
  virtual std::list<std::shared_ptr<UserDO>> SelectByID(uint64_t id) override;
};

#endif
