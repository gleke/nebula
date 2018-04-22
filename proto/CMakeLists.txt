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

set (PROTO_SRC_LIST
  mtproto/core/mtproto_message.cc
  mtproto/core/mtproto_message.h
  mtproto/core/tl_codec_util.cc
  mtproto/core/tl_types.h
  mtproto/core/tl_codec_util.cc
  mtproto/core/tl_codec_util.h
  mtproto/core/tl_object.cc
  mtproto/core/tl_object.h
  mtproto/core/tl_bool.h
  mtproto/core/tl_null.h
  mtproto/core/tl_error.h
  mtproto/core/tl_vector.cc
  mtproto/core/tl_vector.h
  mtproto/core/mtproto_api_message_box.h
  mtproto/core/mtproto_api_message_box2.h
  mtproto/core/mtproto_schema.cc
  mtproto/core/mtproto_schema.h
  mtproto/schema.tl.cc
  mtproto/schema.tl.h
  mtproto/core/auth_key_manager.cc
  mtproto/core/auth_key_manager.h
  mtproto/scheme/scheme.tl
  mtproto/scheme/generate.py
)

add_library(proto STATIC ${PROTO_SRC_LIST})
target_link_libraries(proto protobuf)

#add_subdirectory(base/test)
