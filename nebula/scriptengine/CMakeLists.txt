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

INCLUDE_DIRECTORIES(./lua-5.2.3/src)

SET(SRC_LIST 
 lua_include.hpp
 lua_util.cc
 lua_util.h
 luabind_register_func.h
 luabind_register_manager.h
 script_engine.cc
 script_engine.h
 luatinker/lua_tinker.cpp
 luatinker/lua_tinker.h

 lua-5.2.3/src/lapi.c
 lua-5.2.3/src/lauxlib.c
 lua-5.2.3/src/lbaselib.c
 lua-5.2.3/src/lbitlib.c
 lua-5.2.3/src/lcode.c
 lua-5.2.3/src/lcorolib.c
 lua-5.2.3/src/lctype.c
 lua-5.2.3/src/ldblib.c
 lua-5.2.3/src/ldebug.c
 lua-5.2.3/src/ldo.c
 lua-5.2.3/src/ldump.c
 lua-5.2.3/src/lfunc.c
 lua-5.2.3/src/lgc.c
 lua-5.2.3/src/linit.c
 lua-5.2.3/src/liolib.c
 lua-5.2.3/src/llex.c
 lua-5.2.3/src/lmathlib.c
 lua-5.2.3/src/lmem.c
 lua-5.2.3/src/loadlib.c
 lua-5.2.3/src/lobject.c
 lua-5.2.3/src/lopcodes.c
 lua-5.2.3/src/loslib.c
 lua-5.2.3/src/lparser.c
 lua-5.2.3/src/lstate.c
 lua-5.2.3/src/lstring.c
 lua-5.2.3/src/lstrlib.c
 lua-5.2.3/src/ltable.c
 lua-5.2.3/src/ltablib.c
 lua-5.2.3/src/ltm.c
 lua-5.2.3/src/lua.c
 lua-5.2.3/src/lundump.c
 lua-5.2.3/src/lvm.c
 lua-5.2.3/src/lzio.c
)

SET(LIBRARY_OUTPUT_PATH ${TF_CURRENT_BINARY_PATH_LIB})

ADD_LIBRARY(script_engine STATIC ${SRC_LIST})

add_subdirectory(scriptengine_test/)

