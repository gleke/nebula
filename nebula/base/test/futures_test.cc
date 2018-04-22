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
#include <glog/logging.h>

#include <folly/futures/Future.h>
#include <folly/MoveWrapper.h>

#include "nebula/net/thread_group_list_manager.h"

using namespace nebula;
using namespace folly;
using namespace std;


ThreadGroupListManager* g_thread_pool = nullptr;

folly::Future<int> Write() {
  folly::Promise<int> p;
  auto f = p.getFuture();

  auto mp = folly::makeMoveWrapper(p);
  auto evb = g_thread_pool->GetEventBaseByThreadID(2);
  evb->runInEventBaseThread([mp]() mutable {
    // mp.setValue(1);
    LOG(INFO) << "ready do...";
    mp.move().setValue(1);
    LOG(INFO) << "done 1";
  });
  LOG(INFO) << "Write";
  return f;
}

///////////////////////////////////////////////////////////////////
void FutureTest() {
  // 1. 加载线程组
  ThreadGroupListOption thread_group_list_option;
  thread_group_list_option.options.emplace_back(ThreadType::CONN, 4);
  ThreadGroupListManager thread_groups(thread_group_list_option);
  g_thread_pool = &thread_groups;
  
  // 2. make一个future，并在其它线程里返回
  auto f = Write();
  f.then([] {
        LOG(INFO) << "then...";
      })
  .then([] {
    LOG(INFO) << "then2...";
  });
  LOG(INFO) << "ready get...";
  LOG(INFO) << f.get();
  LOG(INFO) << "geted!!!";

  folly::EventBase main_eb;
  main_eb.loopForever();
}

void FutureTest2() {
  // 模拟RPC
  // Req在5秒内等Rsp
  //
  
  folly::Promise<int> p;
  auto foo = p.getFuture();

  LOG(INFO) << "Ready...";
  // auto foo = folly::makeFuture(1);
  foo
  .then([] (int i) {
    LOG(INFO) << "then";
    return 1;
  })
  .onTimeout(std::chrono::milliseconds(1000), []{
    // You must maintain the resultant future's type
    // ... handle timeout ...
    LOG(INFO) << "onTimeout";
    return -1;
  });
  
  
  folly::EventBase main_eb;
  main_eb.loopForever();
  
  
  
}

void foo(int x) {
  // do something with x
  cout << "foo(" << x << ")" << endl;
}

void FutureTest3() {
  // ...
  
  cout << "making Promise" << endl;
  Promise<int> p;
  Future<int> f = p.getFuture();
  f.then(foo);
  cout << "Future chain made" << endl;
  
  // ... now perhaps in another event callback
  
  cout << "fulfilling Promise" << endl;
  p.setValue(42);
  cout << "Promise fulfilled" << endl;
}


// static TestingFuncManager g_testing_func(FutureTest3);

