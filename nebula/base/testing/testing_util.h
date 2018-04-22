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

#ifndef NUBULA_BASE_TESTING_UTIL_H_
#define NUBULA_BASE_TESTING_UTIL_H_

#include <functional>
#include <list>

namespace nebula {

// typedef VoidFunc (void*)();
  
// 简单测试框架
// TODO(@wubenqi): 使用gtest
/* 用例子
  static TestingFuncManager g_testing_func([] {
    static MessageFactoryManager::RegisterTemplate<Message1> g_reg1("message1");
    static MessageFactoryManager::RegisterTemplate<Message2> g_reg2("message2");
    
    auto message1 = MessageFactoryManager::CreateSharedInstance("message1");
    auto message2 = MessageFactoryManager::CreateSharedInstance("message2");
  });
 */
  
struct TestingFuncManager {
  using VoidFunc = std::function<void()>;
  TestingFuncManager(VoidFunc func);
  
  static void Testing();
};

}

#endif

// NUBULA_BASE_TEST_BASE_TEST_H_
