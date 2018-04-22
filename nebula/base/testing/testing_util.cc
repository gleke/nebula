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

#include "nebula/base/testing/testing_util.h"


namespace nebula {
  
// 假如这样使用，有问题
/*
 static std::list<TestingFuncManager::VoidFunc> g_testing_funcs;
 
 TestingFuncManager::TestingFuncManager(VoidFunc func) {
   // 在这里有问题
   // TODO(@benqi): 找出出问题原因
   // 找本编译和链接的书看看为什么会出问题？？
   g_testing_funcs.push_back(std::move(func));
 }
 
 void TestingFuncManager::Testing() {
   for (auto f : g_testing_funcs) {
     f();
   }
 }
 */
// hack如下 
std::list<TestingFuncManager::VoidFunc>& get() {
  static std::list<TestingFuncManager::VoidFunc> g_testing_funcs;
  return g_testing_funcs;
}

TestingFuncManager::TestingFuncManager(VoidFunc func) {
//  for (auto f : g_testing_funcs) {
//    f();
//  }
  auto & funcs = get();
  funcs.push_back(std::move(func));
}

void TestingFuncManager::Testing() {
  auto & funcs = get();
  for (auto f : funcs) {
    f();
  }
}

}
