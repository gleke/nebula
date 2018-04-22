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

#include <iostream>

#include "nebula/base/crypto_util/md5.h"
#include "nebula/scriptengine/script_engine.h"

std::string MD5String2(const std::string& str) {
  nebula::MD5Digest digest;
  nebula::MD5Sum(str.c_str(), str.length(), &digest);
  return nebula::MD5DigestToBase16(digest);
}

lua_tinker::table TableTest(lua_tinker::table t) {
  //base::MD5Digest digest;
  //base::MD5Sum(str.c_str(), str.length(), &digest);
  //return base::MD5DigestToBase16(digest);
  return t;
}

// void Luabind_Base_Register(lua_State* L) {
//   lua_tinker::def(L, "MD5String", &MD5String2);
//   lua_tinker::def(L, "UTF8ToNativeMB", &UTF8ToNativeMB);
// }

struct T {
//public:
//  T() {
//    std::cout << "T::T()" << std::endl;
//  }
//  ~T() {
//    std::cout << "T::~T()" << std::endl;
//  }
  void Print() {
    std::cout << "T::Print()" << std::endl;
  }
};

std::shared_ptr<T> CreateTSharedPtrTest() {
  return std::shared_ptr<T>(new T());
}

T CreateTTest() {
  return T();
}

void CppTestingRegister(ScriptEngine* script_engine) {
#undef RegisterClass
  script_engine->RegisterClass<T>("T");
  script_engine->RegisterClassFuncnction<T>("Print", &T::Print);

  script_engine->RegisterClass<std::shared_ptr<T> >("SharedPtr_T");
  script_engine->RegisterClassFuncnction<std::shared_ptr<T> >("Get", &std::shared_ptr<T>::get);

  script_engine->RegisterFunction("MD5String", &MD5String2);
  script_engine->RegisterFunction("TableTest", &TableTest);

  script_engine->RegisterFunction("CreateTSharedPtrTest", &CreateTSharedPtrTest);
  script_engine->RegisterFunction("CreateTTest", &CreateTTest);
}



int main(int argc, char* argv[]) {
/*
  ScriptEngine script_engine;
  script_engine.Initialize();
  CppTestingRegister(&script_engine);
  script_engine.DoFile(argv[1]);
  script_engine.CallFunction<int>("DoMain");
  script_engine.Destroy();
 */


  ScriptEngine script_engine;
  script_engine.Initialize();
  CppTestingRegister(&script_engine);

  script_engine.DoFile(argv[1]);

  // lua_tinker::table haha(script_engine.GetLuaState(),"haha");
  script_engine.CallFunction<int>("DoMain");
  {
  //  lua_tinker::table ret = lua_tinker::call<lua_tinker::table>(script_engine.GetLuaState(), "return_table", "give me a table !!");
  //  script_engine.CallFunction<void>("print_table", ret); 
  //  script_engine.CallFunction<void>("print_table2", ret); 
  }

  // script_engine.CallFunction<int>("DoMain");
  // lua_tinker::table haha(L,"haha");

  script_engine.Destroy();

  // lua_tinker::table haha(L,"haha");
  return 0;
}
