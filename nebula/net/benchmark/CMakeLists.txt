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

set (SRC_BENCHMARK_LIST
  benchmark.cc
 )

add_executable (benchmark ${SRC_BENCHMARK_LIST})
target_link_libraries (benchmark folly.a wangle.a boost_context-mt boost_filesystem-mt boost_system-mt double-conversion glog gflags event /usr/local/opt/openssl/lib/libcrypto.a /usr/local/opt/openssl/lib/libssl.a pthread z)

set (SRC_BENCH_ASIO_LIST
  bench_asio.cc
 )

add_executable (bench_asio ${SRC_BENCH_ASIO_LIST})
target_link_libraries (bench_asio boost_context-mt boost_filesystem-mt boost_system-mt double-conversion glog gflags event /usr/local/opt/openssl/lib/libcrypto.a /usr/local/opt/openssl/lib/libssl.a pthread z)
