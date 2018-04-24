/*
 *  Copyright (c) 2016, https://github.com/zhatalk
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

#include "nebula/net/thread_group_list_manager.h"

#include <folly/Random.h>
#include <folly/executors/CPUThreadPoolExecutor.h>

#include "nebula/base/logger/glog_util.h"
#include "nebula/net/thread_local_conn_manager.h"

namespace nebula {
  
// folly::Singleton<ThreadGroupListManager> g_thread_group_list_manager;

ThreadGroup::ThreadGroup(std::shared_ptr<folly::ThreadPoolExecutor> pool,
                         ThreadType thread_type,
                         const NewThreadDataCallback& cb)
  : thread_pool_(pool),
    thread_type_(thread_type),
    thread_observer_(std::make_shared<ThreadGroupObserver>(this, cb)) {
  
  thread_pool_->addObserver(thread_observer_);
}


void ThreadGroup::ThreadGroupObserver::threadStarted(folly::ThreadPoolExecutor::ThreadHandle* handle) {
  // LOG(INFO) << "threadStarted - ";
  if (callback_) {
    // LOG(INFO) << "threadStarted - ";
    size_t idx = callback_(thread_group_, handle);
    thread_group_->thread_idxs_.push_back(idx);
  }
}

void ThreadGroup::ThreadGroupObserver::threadStopped(folly::ThreadPoolExecutor::ThreadHandle* handle) {
  if (callback_) {
    // callback_(thread_group_, handle);
  }
}

bool ThreadGroupListOption::SetConf(const std::string &conf_name, const folly::dynamic& conf) {
  if (!conf.isObject()) {
    LOG(ERROR) << "SetConf - config error, conf_name: " << conf_name << ", data: " << conf;
    return false;
  }
  
  // bool is_conn = false, is_accept = false, is_client = false;
  auto conn = conf.get_ptr("conn");
  if (conn && conn->isInt()) {
    options.emplace_back(ThreadType::CONN, static_cast<int>(conn->asInt()));
    // is_conn = true;
  } else {
    auto accept = conf.get_ptr("accept");
    if (accept && accept->isInt()) {
      options.emplace_back(ThreadType::CONN_ACCEPT, static_cast<int>(accept->asInt()));
      // is_accept = true;
    }
    
    auto client = conf.get_ptr("client");
    if (client && client->isInt()) {
      options.emplace_back(ThreadType::CONN_CLIENT, static_cast<int>(client->asInt()));
      // is_client = true;
    }
  }
  
  auto fiber = conf.get_ptr("fiber");
  if (fiber && fiber->isInt()) {
    options.emplace_back(ThreadType::FIBER, static_cast<int>(fiber->asInt()));
  }
  
  auto db = conf.get_ptr("db");
  if (db && db->isInt()) {
    options.emplace_back(ThreadType::DB, static_cast<int>(db->asInt()));
  }
  
  auto redis = conf.get_ptr("redis");
  if (redis && redis->isInt()) {
    options.emplace_back(ThreadType::REDIS, static_cast<int>(redis->asInt()));
  }
  
  return true;
}

ThreadGroupListManager::ThreadGroupListManager(const ThreadGroupListOption& options)
  : thread_groups_(static_cast<int>(ThreadType::MAX)) {
  Initialize(options);
}

bool ThreadGroupListManager::Initialize(const ThreadGroupListOption& options) {
  if (options.options.empty()) {
    LOG(ERROR) << "Initialize - options is empty";
    return false;
  }
  
  for (auto& option : options.options) {
    auto thread_group = MakeThreadGroup(option.thread_type, option.thread_size);
    int idx = static_cast<int>(option.thread_type);
    thread_groups_[idx] = thread_group;
  }
  
  return true;
}

ThreadGroupPtr ThreadGroupListManager::MakeThreadGroup(ThreadType thread_type, int thread_size) {
  ThreadGroupPtr thread_group;
  std::shared_ptr<folly::ThreadPoolExecutor> pool;
  switch (thread_type) {
    case ThreadType::NORMAL:
        break;
    case ThreadType::CONN_ACCEPT:
    case ThreadType::CONN_CLIENT:
    case ThreadType::CONN:
    case ThreadType::FIBER:
        pool = std::make_shared<folly::IOThreadPoolExecutor>(thread_size);
        break;
    case ThreadType::DB:
    case ThreadType::REDIS:
        pool = std::make_shared<folly::CPUThreadPoolExecutor>(thread_size);
        break;
    default:
        LOG(ERROR) << "MakeThreadGroup - thread_type: " << ToString(thread_type) << " not support!!!";
        break;
  }
  
  if (pool) {
    auto cb = [&](ThreadGroup* group,
                  folly::ThreadPoolExecutor::ThreadHandle* handle) -> size_t {
      size_t idx = thread_datas_.size();
      
      folly::EventBase* evb = nullptr;
      auto t = group->GetThreadType();
      switch (t) {
        case ThreadType::CONN_ACCEPT:
        case ThreadType::CONN_CLIENT:
        case ThreadType::CONN:
        case ThreadType::FIBER:
          evb = folly::IOThreadPoolExecutor::getEventBase(handle);
          evb->runImmediatelyOrRunInEventBaseThreadAndWait([idx](){
              LOG(INFO) << "MakeThreadGroup - thread_idx: " << idx;
              GetConnManagerByThreadLocal().set_thread_id(idx);
          });
          break;
        default:
          break;
      }
      
      LOG(INFO) << "MakeThreadGroup - thread_type: " << ToString(thread_type) << ", thread_idx: " << idx;
      thread_datas_.emplace_back(group, idx, evb);
      return idx;
    };
    
    thread_group = std::make_shared<ThreadGroup>(pool, thread_type, cb);
  } else {
    LOG(ERROR) << "MakeThreadGroup - pool is nil";
  }
  
  return thread_group;
}


// 通过ThreadType获取IOThreadPoolExecutor
std::shared_ptr<folly::IOThreadPoolExecutor> ThreadGroupListManager::GetIOThreadPoolExecutor(ThreadType thread_type) const {
  std::shared_ptr<folly::IOThreadPoolExecutor> pool;
  if (thread_type == ThreadType::CONN_ACCEPT ||
      thread_type == ThreadType::CONN_CLIENT ||
      thread_type == ThreadType::CONN ||
      thread_type == ThreadType::FIBER) {
    auto idx = static_cast<size_t>(thread_type);
    auto thread_group = thread_groups_[idx];
    if (thread_group) {
      auto p = thread_group->GetThreadPool();
      pool = std::static_pointer_cast<folly::IOThreadPoolExecutor>(p);
      if (!pool) {
        LOG(ERROR) << "GetIOThreadPoolExecutor - Not find thread_type: " << ToString(thread_type)
        << ", idx:" << idx << " in thread_groups!!!!";
      }
    }
    // auto idx = thread_groups_[static_cast<int>(thread_type);
    // pool = std::static_pointer_cast<folly::IOThreadPoolExecutor>(]->GetThreadPool());
  }
  return pool;
}

folly::EventBase* ThreadGroupListManager::GetEventBaseByThreadType(ThreadType thread_type) const {
  auto group = GetThreadGroupByThreadType(thread_type);
  if (group) {
    folly::ThreadLocalPRNG rng;
    uint32_t idx = folly::Random::rand32(static_cast<uint32_t>(group->thread_idxs_.size()));
    return thread_datas_[idx].evb;
  } else {
    return nullptr;
  }
}
  
}

