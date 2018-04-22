#  Copyright (c) 2016, https://github.com/nebula-im/nebula
#  All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#include_directories(/usr/local/include/mysql /usr/local/include)

set (SRC_LIST
mysql_client.cc
mysql_client.h
mysql_client_util.cc
mysql_client_util.h
mysql_conn.cc
mysql_conn.h
mysql_conn_pool.cc
mysql_conn_pool.h
mysql_result_set.cc
mysql_result_set.h
mysql_query_util.cc
mysql_query_util.h
)

#link_directories(
#/usr/local/lib    
#)


add_library (mysql_client ${SRC_LIST})
target_link_libraries (mysql_client /usr/local/mysql/lib/libmysqlclient.a)

add_subdirectory(test)

