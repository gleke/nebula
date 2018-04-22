/*
 *  Copyright (c) 2016, https://github.com/zhatalk
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

#include <iostream>
#include <folly/Format.h>

#include "nebula/base/testing/testing_util.h"
#include "nebula/mysql_client/mysql_client_util.h"

void Initialize_Testing() {
  // SelfRegisterFactoryManagerTest();
  DBAddrInfo db_addr;
  db_addr.host = "localhost";
  db_addr.port = 3307;
  db_addr.user = "root";
  db_addr.passwd = "";
  db_addr.db_name = "nebula_platform";
  db_addr.db_type = "mysql";
  
  std::vector<DBAddrInfo> db_addrs = {db_addr};
  InitializeMysqlClient(db_addrs, 2);
}

void MysqlClientTest() {
  Initialize_Testing();
  
  std::string q = folly::sformat("SELECT app_id,org_id,app_name,product_name,descr,status,created_at,updated_at FROM apps WHERE app_id={}",
                                 1);
  auto conn_pool = GetMysqlConnPool("nebula_platform");
  auto r = conn_pool->Query(q);
  std::cout << r.errcode << std::endl;
}

void MysqlClientTest2() {
  Initialize_Testing();
  
  struct AppData {
    int app_id;
    int org_id;
    std::string app_name;
    std::string product_name;
    std::string descr;
    int status;
    int64_t created_at;
    int64_t updated_at;
    
    void Print() {
      std::string o = folly::sformat("{{app_id:{}, org_id:{}, app_name:{}, product_name:{}, descr:{}, status:{}, created_at:{}, updated_at:{}}}",
                                     app_id,
                                     org_id,
                                     app_name,
                                     product_name,
                                     descr,
                                     status,
                                     created_at,
                                     updated_at);
      std::cout << o << std::endl;
      
    }
  } app_data;
  
  DoStorageQuery("nebula_platform",
                 [&](std::string& query_string) {
                   folly::format(&query_string, "SELECT app_id,org_id,app_name,product_name,descr,status,created_at,updated_at FROM apps WHERE app_id={}",
                                 1);
                 },
                 [&](MysqlResultSet& answ) -> int {
                   // group.app_id = 1;
                   // ...
                   answ.GetColumn(0, &app_data.app_id);
                   answ.GetColumn(1, &app_data.org_id);
                   answ.GetColumn(2, &app_data.app_name);
                   answ.GetColumn(3, &app_data.product_name);
                   answ.GetColumn(4, &app_data.descr);
                   answ.GetColumn(5, &app_data.status);
                   answ.GetColumn(6, &app_data.created_at);
                   answ.GetColumn(7, &app_data.updated_at);
                   
                   app_data.Print();
                   return BREAK;
                 });

}

static nebula::TestingFuncManager g_testing_mysql_client(MysqlClientTest2);


int main(int argc, char* argv[]) {
  
  nebula::TestingFuncManager::Testing();
}
