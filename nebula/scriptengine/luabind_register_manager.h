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

#ifndef SCRIPTENGINE_LUABIND_REGISTER_MANAGER_H_
#define SCRIPTENGINE_LUABIND_REGISTER_MANAGER_H_

#include "nebula/scriptengine/luabind_register_func.h"

class LuabindRegisterManager {
public:
  static LuabindRegisterManager* GetInstance() {
    static LuabindRegisterManager instance;
    return &instance;
  }

  void RegisterLuabindRegisterFunc(const std::string& module_name, LuabindRegister_Func func) {
    LuabindRegisterFuncListMap::iterator it = registers_.find(module_name);
    if (it == registers_.end()) {
      registers_[module_name].push_back(func);
    } else {
      it->second.push_back(func);
    }
	}

	LuabindRegisterFuncListMap& MutableRegisters() {
		return registers_;
	}

  void RestiterAll(lua_State* L) {
    for (LuabindRegisterFuncListMap::iterator it=registers_.begin(); it!=registers_.end(); ++it) {
      LuabindRegisterFuncList& funcs = it->second;
      for (size_t i=0; i<funcs.size(); ++i) {
        funcs[i](L);
      }
    }
  }

private:
  LuabindRegisterManager() {}
	~LuabindRegisterManager() {}

  LuabindRegisterFuncListMap registers_;
};


#endif // SCRIPTENGINE_LUABIND_PB_REGISTER_MANAGER_H_
