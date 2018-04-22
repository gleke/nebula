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

#include "nebula/zorm/zorm_template.h"

#include <iostream>
#include <folly/Format.h>

#include "nebula/base/reflection_util.h"

/*
 <?xml version="1.0" encoding="UTF-8"?>
 <table sqlname="users">
	<operation name="insert">
   <sql>
   INSERT INTO
   users(app_id,user_id,avatar,nick,status,created_at,updated_at)
   VALUES (?,?,?,?,?,?,?)
   </sql>
	</operation>
	<operation name="selectByID">
   <sql>
   SELECT app_id,user_id,avatar,nick,status,created_at,updated_at FROM users WHERE id=?
   </sql>
	</operation>
 </table>
 */


void UserDO::PrintDebug() const {
  std::cout << "id = " << id << "\n"
        << "app_id = " << app_id << "\n"
        << "user_id = " << user_id << "\n"
        << "avatar = " << avatar << "\n"
        << "nick = " << nick << "\n"
        << "status = " << status << "\n"
        << "created_at = " << created_at << "\n"
        << "updated_at = " << updated_at << std::endl;
}

struct CreateUser : public BaseSqlQuery {
  CreateUser(UserDO& _user)
    : user(_user) {}
  
  bool SerializeToQuery(std::string& query_string) const {
    auto tuple = user.Meta();
    folly::format(&query_string, "INSERT INTO users({},{},{},{},{},{},{}) VALUES ({},'{}','{}','{}',{},{},{})",
                  std::get<1>(tuple).first,
                  std::get<2>(tuple).first,
                  std::get<3>(tuple).first,
                  std::get<4>(tuple).first,
                  std::get<5>(tuple).first,
                  std::get<6>(tuple).first,
                  std::get<7>(tuple).first,
                  std::get<1>(tuple).second,
                  std::get<2>(tuple).second,
                  std::get<3>(tuple).second,
                  std::get<4>(tuple).second,
                  std::get<5>(tuple).second,
                  std::get<6>(tuple).second,
                  std::get<7>(tuple).second);
    std::cout << "CreateUser - " << query_string << std::endl;
    return !query_string.empty();
  }
  UserDO& user;
};

struct GetUserInfoByID  : public QueryWithResult {
  GetUserInfoByID(uint64_t _id)
    : id(_id) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  int ParseFrom(db::QueryAnswer& answ) override;
  
  uint64_t id;
  std::list<std::shared_ptr<UserDO>> users;
};

bool GetUserInfoByID::SerializeToQuery(std::string& query_string) const {
  folly::format(&query_string, "SELECT * FROM users WHERE id={}", id);
  return !query_string.empty();
}

int GetUserInfoByID::ParseFrom(db::QueryAnswer& answ) {
  auto user = std::make_shared<UserDO>();
  
  FromQueryAnswer(user->Meta(), answ);
  users.push_back(user);
  
  return CONTINUE;
}

uint64_t DBUserDAO::Insert(UserDO& user) {
  CreateUser create_user(user);
  // std::string query_string;
  // create_user.SerializeToQuery(query_string);
  SqlExecuteInsertID("nebula_platform", create_user);
  return 0;
}

std::list<std::shared_ptr<UserDO>> DBUserDAO::SelectByID(uint64_t id) {
  GetUserInfoByID get_user_info(id);
  SqlQuery("nebula_platform", get_user_info);
  return get_user_info.users;
}

///////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  DBUserDAO db_user_dao;
  UserDO user;
  user.user_id = "zhazha@zhazha";
  user.avatar = "/avatar/1/1.png";
  
  // CreateUser create_user_op(user);
  db_user_dao.Insert(user);
  
  return 0;
}

