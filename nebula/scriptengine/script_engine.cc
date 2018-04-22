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

#include "nebula/scriptengine/script_engine.h"

#include <list>

// #include <boost/filesystem/path.hpp>
// #include <boost/filesystem/operations.hpp>
// 
// #include <luabind/iterator_policy.hpp>

//#include "base/file_util.h"
//#include "base2/file_path_util.h"
//#include "base/logging.h"

void ScriptEngine::Initialize() {
  // 确保只会初始化一次
  if (!lua_state_) {
    lua_state_ = luaL_newstate(); // 创建Lua状态
    if (!lua_state_) {
      LOG(ERROR) << "ScriptEngine::Init() lua_open failed!";
      return;
    }
    luaL_openlibs(lua_state_); // 为该Lua状态打开所有Lua库
    //luabind::open(lua_state_); // 为该Lua状态打开luabind库
    //luaopen_zmq(lua_state_);

    //lua_interface_.Init(lua_state_);

	lua_tinker::init(lua_state_);
  }
}

ScriptEngine::~ScriptEngine() {
  Destroy();
}

void ScriptEngine::Refresh() {
  Destroy();
  Initialize();
}

void ScriptEngine::Destroy() {
  if (lua_state_) {
    lua_close(lua_state_);
    lua_state_ = NULL;
  }
}

void ScriptEngine::DoFile(const std::string& file_path) {
  CHECK(lua_state_ != NULL);
  lua_tinker::dofile( lua_state_, file_path.c_str());
}

void ScriptEngine::DoBuffer(const char* data, size_t data_len) {
  CHECK(lua_state_ != NULL);

  lua_tinker::dobuffer(lua_state_, data, data_len);
}

void ScriptEngine::DoBuffer(const std::string& buffer) {
  DoBuffer(buffer.c_str(), buffer.length());
}
