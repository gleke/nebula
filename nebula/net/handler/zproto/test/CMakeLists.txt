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

include_directories(/usr/local/include ../..)

#add_executable (zproto_test zproto_test.cc)
#target_link_libraries (zproto_test net base)

add_executable (zrpc_client_test zrpc_client_test.cc zrpc_test.pb.cc zrpc_test.pb.h zrpc_test.proto)
target_link_libraries (zrpc_client_test net base protobuf) 

add_executable (zrpc_server_test
 zrpc_server_test.cc
 zrpc_test_service.cc
 zrpc_test_service.h
 zrpc_test_service_impl.cc
 zrpc_test_service_impl.h
 zrpc_test_dispatcher.cc
 zrpc_test_dispatcher.h
 zrpc_test.pb.cc
 zrpc_test.pb.h
 zrpc_test.proto
)
target_link_libraries (zrpc_server_test net base protobuf)

