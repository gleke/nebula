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
redis_conn.cc
redis_conn.h
redis_conn_pool.cc
redis_conn_pool.h
redis_client.cc
redis_client.h
)


#link_directories(
#/usr/local/lib    
#)


add_library (redis_client ${SRC_LIST})
target_link_libraries (redis_client -lhiredis)

#add_subdirectory(test)

