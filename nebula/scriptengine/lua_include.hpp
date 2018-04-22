/*
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula
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

// Lua脚本引擎
//

#ifndef SCRIPTENGINE_LUA_INCLUDE_HPP_
#define SCRIPTENGINE_LUA_INCLUDE_HPP_

//#ifndef LUABIND_CPLUSPLUS_LUA
extern "C" {
//#endif
#include "nebula/scriptengine/lua-5.2.3/src/lua.h"
#include "nebula/scriptengine/lua-5.2.3/src/lauxlib.h"
#include "nebula/scriptengine/lua-5.2.3/src/lualib.h"
// #include "lua.h"
// #include "lauxlib.h"
//#ifndef LUABIND_CPLUSPLUS_LUA
}
//#endif

#endif
