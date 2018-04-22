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

#include <iostream>
#include <folly/Function.h>
#include <folly/fibers/BoostContextCompatibility.h>

#include <folly/io/async/EventBase.h>
#include <folly/fibers/Baton.h>
#include <folly/fibers/FiberManager.h>
#include <folly/fibers/EventBaseLoopController.h>

struct FiberStack {
  unsigned char stack[16*1024];
  size_t stack_size {16*1024};
};

FiberStack g_stacks[2];

//void F0(folly::fibers::FiberImpl& fiber0, folly::fibers::FiberImpl& fiber1) {
//}
//
//void F1(folly::fibers::FiberImpl* ) {
//  unsigned char stack[16*1024]
//  size_t stack_size = 16*1024;
//  
//}

//unsigned char* stackLimit,
//size_t stackSize)

// FiberImpl有两个运行环境上下文，一个是当前，另一个是协程
// 1. main/f
// 和boost例子一样的
void FiberImplTest() {

  folly::fibers::FiberImpl* fiber0 = nullptr;
  folly::fibers::FiberImpl* fiber1 = nullptr;

  fiber0 = new folly::fibers::FiberImpl([&] () {
    
    fiber1 = new folly::fibers::FiberImpl([&] () {
      std::cout << "Enter fiber1..." << std::endl;
      std::cout << "Jump fiber0..." << std::endl;
      
      // 退出当前运行空间后，后面的代码不可能执行
      fiber1->deactivate();
      std::cout << "Leave fiber1!" << std::endl;
      //fiber1.deactivate();
      //std::cout << "Leave fiber1!" << std::endl;
    }, g_stacks[1].stack, g_stacks[1].stack_size);

    std::cout << "Enter fiber0..." << std::endl;
    std::cout << "Call fiber1..." << std::endl;
    fiber1->activate();
    std::cout << "Return fiber1!" << std::endl;
    
    // 不退出当前运行环境，mac下直接退出程序
    fiber0->deactivate();
  }, g_stacks[0].stack, g_stacks[0].stack_size);
  
  std::cout << "Main call f0..." << std::endl;
  // main->f0
  fiber0->activate();
  //fiber1->deactivate();
  
  std::cout << "Quit call0..." << std::endl;

  delete fiber0;
  delete fiber1;
  
  std::cout << "Quit Main call1..." << std::endl;
}

/*
///////////////////////////////////////////////////////////////////////////
boost::context::fcontext_t fcm,fc1,fc2;
void f1(intptr_t) {
  std::cout<<"f1: entered"<<std::endl;
  std::cout<<"f1: call jump_fcontext( & fc1, fc2, 0)"<< std::endl;
  // fc1 -> fc2;
  boost::context::jump_fcontext(&fc1,fc2,0);
  std::cout<<"f1: return"<<std::endl;
  
  // fc1->main
  boost::context::jump_fcontext(&fc1,fcm,0);
}

void f2(intptr_t) {
  std::cout<<"f2: entered"<<std::endl;
  std::cout<<"f2: call jump_fcontext( & fc2, fc1, 0)"<<std::endl;
  // fc2 -> fc1
  boost::context::jump_fcontext(&fc2,fc1,0);
  std::cout << "f2: never returns" << std::endl;
}

void BoostContextTest() {
  // boost::context::guarded_stack_allocator alloc;
  std::size_t size(8192);
  void* sp1(std::malloc(size));
  void* sp2(std::malloc(size));
  fc1=boost::context::make_fcontext(sp1,size,f1);
  fc2=boost::context::make_fcontext(sp2,size,f2);
  std::cout<<"main: call jump_fcontext( & fcm, fc1, 0)"<<std::endl;
  // main->fc1
  boost::context::jump_fcontext(&fcm,fc1,0);
}
*/

///////////////////////////////////////////////////////////////////////////
struct LocalData {
  int l1{0};
  int l2{0};
  
  void Print() const {
    std::cout << "l1 = " << l1 << ", l2 = " << l2 << std::endl;
  }
  void Print(const char* f, int i) const {
    std::cout << "f>" << f << "! i: " << i << "] l1 = " << l1 << ", l2 = " << l2 << std::endl;
  }
};

folly::ThreadLocalPtr<LocalData> g_local_data;

void DoFiberFunc() {
  g_local_data.get()->l1 = 1;
  g_local_data.get()->l2 = 1;
  g_local_data.get()->Print();
  
}

///////////////////////////////////////////////////////////////////////////
void FiberTest() {
  srand(time(nullptr));
  
  folly::EventBase evb;
  g_local_data.reset(new LocalData);
  g_local_data.get()->Print();

  folly::fibers::FiberManager fm(folly::fibers::LocalType<LocalData>(), folly::make_unique<folly::fibers::EventBaseLoopController>());
  dynamic_cast<folly::fibers::EventBaseLoopController&>(fm.loopController())
  .attachEventBase(evb);

  for (int i=0; i<10; ++i) {
    g_local_data.get()->l1 = i;
    // g_local_data.get()->Print();
    
    fm.addTask([&, i] () {
      auto& l1 = folly::fibers::local<LocalData>();
      g_local_data.get()->Print();
      l1.Print("fb", i);
      l1.l1 = i;
      l1.Print("fs", i);
      // auto l2 = l1;
      // g_local_data.get()->l2 = i;
      folly::fibers::Baton baton;
      // g_local_data.get()->Print(i);
      baton.timed_wait(std::chrono::milliseconds(rand()%1000));
      // g_local_data.get()->Print(i);
      // auto& l2 = folly::fibers::local<LocalData>();
      l1.Print("fe", i);
      // l2.Print(i);
    });
  }
  
  evb.loopForever();
}

// static nebula::TestingFuncManager g_testing_fibers(FiberImplTest);
// static nebula::TestingFuncManager g_testing_boost(BoostContextTest);
static nebula::TestingFuncManager g_testing_fiber_test(FiberTest);

