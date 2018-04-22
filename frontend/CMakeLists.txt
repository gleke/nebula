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

include_directories(. ..)

set (SRC_LIST
  frontend_server.cc
  frontend_server.h
  frontend_server_handler.cc
  frontend_server_handler.h
  handshake_handler.cc
  handshake_handler.h
  auth_client_handler.cc
  auth_client_handler.h
  messenger_client_handler.cc
  messenger_client_handler.h
  client_base_handler.cc
  client_base_handler.h
)

add_executable (frontend ${SRC_LIST})
target_link_libraries (frontend net base proto)

