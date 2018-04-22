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

#ifndef SCRIPTENGINE_LUA_UTIL_H_
#define SCRIPTENGINE_LUA_UTIL_H_

// Lua脚本引擎
//

//get rid of the annoying but unavoidable forcing int to bool warning
#pragma warning (disable:4800)

#include "nebula/scriptengine/lua_include.hpp"
//#include "base/logging.h"

//这里有一个有用的帮助函数，它dump整个堆栈的内容：
void LuaDumpStackHelper (lua_State* L);

#endif
