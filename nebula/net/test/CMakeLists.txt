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

set (SRC_NET_ENGINE_CLIENT_LIST
  net_engine_client_test.cc
  )

#add_executable (net_engine_client_test ${SRC_NET_ENGINE_CLIENT_LIST})
#target_link_libraries (net_engine_client_test net base)

set (SRC_NET_ENGINE_SERVER_LIST
  net_engine_server_test.cc
  )

add_executable (net_engine_server_test ${SRC_NET_ENGINE_SERVER_LIST})
target_link_libraries (net_engine_server_test net base)

set (SRC_LIST2
  thread_util_test.cc
)

#add_executable (thread_util_test ${SRC_LIST2})
#target_link_libraries (thread_util_test net base)

#set (SRC_HTTP_CLIENT_TEST_LIST
#  http_client_test.cc
#  )
#
#add_executable (http_client_test ${SRC_HTTP_CLIENT_TEST_LIST})
#target_link_libraries (http_client_test net base)
#
#
#set (SRC_TELEGRAM_HANDSHAKE_TEST_LIST
#  telegram_handshake_test.cc
#  )
#
#add_executable (telegram_handshake_test ${SRC_TELEGRAM_HANDSHAKE_TEST_LIST})
#target_link_libraries (telegram_handshake_test net base)
#
#set (SRC_TELEGRAM_SERVER_TEST_LIST
#  telegram_server_test.cc
#  )
#
#add_executable (telegram_server_test ${SRC_TELEGRAM_SERVER_TEST_LIST})
#target_link_libraries (telegram_server_test net base)

set (SRC_UDP_ECHO_SERVER_TEST_LIST
  udp_echo_server_test.cc
 )

add_executable (udp_echo_server_test ${SRC_UDP_ECHO_SERVER_TEST_LIST})
target_link_libraries (udp_echo_server_test net base)

set (SRC_UDP_TEST_LIST
  udp_test.cc
 )

add_executable (udp_test ${SRC_UDP_TEST_LIST})
target_link_libraries (udp_test net base)

set (SRC_PINGPONG_TEST_LIST
  pingpong_server_test.cc
 )

add_executable (pingpong_server_test ${SRC_PINGPONG_TEST_LIST})
target_link_libraries (pingpong_server_test net base)

set (SRC_ASYNC_UDP_SOCKET_TEST_LIST
  async_udp_socket_test.cc
 )

add_executable (async_udp_socket_test ${SRC_ASYNC_UDP_SOCKET_TEST_LIST})
target_link_libraries (async_udp_socket_test /usr/local/lib/libfolly.a boost_context-mt boost_filesystem-mt boost_system-mt double-conversion glog gflags event /usr/local/opt/openssl/lib/libcrypto.a /usr/local/opt/openssl/lib/libssl.a pthread z)
