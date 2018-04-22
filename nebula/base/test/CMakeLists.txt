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

set (BASE_TEST_LIST
  base_test.cc
  factory_test.cc
  futures_test.cc
  json_test.cc
  fibers_test.cc
  )

if(APPLE)
add_executable (base_test ${BASE_TEST_LIST})
target_link_libraries (base_test net base)
endif()

