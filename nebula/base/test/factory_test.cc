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

#include <string>
#include <iostream>

#include "nebula/base/self_register_factory_manager.h"
//#include "nebula/base/factory_object.h"
#include "nebula/base/func_factory_manager.h"

using namespace nebula;


struct BaseMessage {
  BaseMessage() {
    std::cout << "BaseMessage::BaseMessage()" << std::endl;
  }
  
  virtual ~BaseMessage() {
    std::cout << "BaseMessage::~BaseMessage()" << std::endl;
  }
};


class Message1 : public BaseMessage {
public:
  Message1() {
    std::cout << "Message1::Message1()" << std::endl;
  }
  
  ~Message1() {
    std::cout << "Message1::~Message1()" << std::endl;
  }
};

class Message2 : public BaseMessage {
public:
  Message2() {
    std::cout << "Message2::Message2()" << std::endl;
  }
  
  ~Message2() {
    std::cout << "Message2::~Message2()" << std::endl;
  }
};

using MessageFactoryManager = SelfRegisterFactoryManager<BaseMessage, std::string>;

struct IntMessage {
  virtual ~IntMessage() = default;
};


struct IntMessage1 : public IntMessage {
  IntMessage1() {
    std::cout << "IntMessage1::IntMessage1()" << std::endl;
  }
  
  ~IntMessage1() {
    std::cout << "IntMessage1::~IntMessage1()" << std::endl;
  }
};

using IntMessageFactoryManager = SelfRegisterFactoryManager<IntMessage, int>;

//void SelfRegisterFactoryManagerTest() {
//}
static TestingFuncManager g_testing_func([] {
  //static MessageFactoryManager::RegisterTemplate<Message1> g_reg1("message1");
  //static MessageFactoryManager::RegisterTemplate<Message2> g_reg2("message2");
  // REGISTER_OBJECT(BaseMessage, std::string, )
  
  
//  REGISTER_STRING_KEY_OBJECT(BaseMessage, Message1, message1);
//  REGISTER_STRING_KEY_OBJECT(BaseMessage, Message2, message2);
//  REGISTER_NUMBER_KEY_OBJECT(IntMessage, int, IntMessage1, 1);
//
//  auto message1 = MessageFactoryManager::CreateSharedInstance("message1");
//  auto message2 = MessageFactoryManager::CreateSharedInstance("message2");
//  
//  auto int_message1 = IntMessageFactoryManager::CreateSharedInstance(1);
  
});


void Func1() {
  std::cout << "Func1()" << std::endl;
}

void Func2() {
  std::cout << "Func2()" << std::endl;
}

void Func3() {
  std::cout << "Func3()" << std::endl;
}


// 妈的，难用无比
struct A1 {
  // typedef void (A1::*Func)();
  // = &A::setA;

  void Func1() {
    std::cout << "A1::Func1()" << std::endl;
  }
  
  void Func2() {
    std::cout << "A1::Func1()" << std::endl;
  }

  void Func3int() {
    std::cout << "A1::Func1()" << std::endl;
  }
};

// 注意注意
typedef void (A1::*A1Func)();

// using VoidFunc2 = std::function<void()>;
typedef FuncFactoryManager<A1Func, std::string> FuncFactory;

//A1 a1;
//
//template<>
//bool FuncFactory::Execute(const std::string& k, int i) {
//  auto& factories = GetInstance().factories_;
//  auto it = factories.find(k);
//  if (it == factories.end()) {
//    LOG(ERROR) << "CreateInstance - not exist func key: " << k;
//    return false;
//  } else {
//    (a1.*it->second)();
//    return true;
//  }
//}

#if 0
static TestingFuncManager g_testing_func2([] {
  // emplate<class F, class K> using FuncRegister = FuncFactoryManager<F, K>::RegisterTemplate<T, K>;
  //
  // template <class T>
  // using FrameRegister = SelfRegisterFactoryManager<FrameMessage, uint8_t>::RegisterTemplate<T>;

  // using FuncFactoryManager<TestingFuncManager::VoidFunc, std::string>::RegisterTemplate;
  
  static FuncFactoryManager<TestingFuncManager::VoidFunc, std::string>::RegisterTemplate g_func1("func1", Func1);
  static FuncFactoryManager<TestingFuncManager::VoidFunc, std::string>::RegisterTemplate g_func2("func2", Func2);
  static FuncFactoryManager<TestingFuncManager::VoidFunc, std::string>::RegisterTemplate g_func3("func3", Func3);

  FuncFactoryManager<TestingFuncManager::VoidFunc, std::string>::Execute("func1");
  FuncFactoryManager<TestingFuncManager::VoidFunc, std::string>::Execute("func2");
  FuncFactoryManager<TestingFuncManager::VoidFunc, std::string>::Execute("func3");

  
  // Func a = std::bind(&A1::Func1);
  
  FuncFactory::RegisterTemplate g_a_func1("func1", &A1::Func1);
  A1 a1;
  FuncFactory::Execute2<A1>(&a1, "func1");
  
  // g_a_func1("func1", &A1::Func1);
  
  // FuncFactory::RegisterTemplate g_a_func2("func2", &A1::Func2);
  // FuncFactory::RegisterTemplate g_a_func3("func3", &A1::Func3);
  
  // g_func1.Execute();
  // g_func1.Execute();
});
#endif

// FuncFactoryManager<>


