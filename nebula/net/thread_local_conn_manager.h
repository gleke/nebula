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

#ifndef NET_THREAD_LOCAL_CONN_MANAGER_H_
#define NET_THREAD_LOCAL_CONN_MANAGER_H_

// #undef HAVE_LIBATOMIC

#include <folly/FBVector.h>


#include <folly/executors/IOThreadPoolExecutor.h>
#include <wangle/channel/Pipeline.h>

#include "nebula/base/map_util.h"
#include "nebula/base/timer_manager.h"
#include "nebula/net/base/tcp_conn_event_callback.h"

namespace nebula {
  
class ThreadLocalConnManager : public TcpConnEventCallback {
public:
  ThreadLocalConnManager() {
    timer_manager_ = folly::make_unique<TimerManager>();
  }
  
  inline void set_thread_id(size_t thread_id) { thread_id_ = thread_id; }
  inline size_t thread_id() const { return thread_id_; }
  inline bool is_self_thread(uint32_t thread_id) const {
    return thread_id == thread_id_;
  }
  
  // EventBase线程里执行
  uint64_t OnNewConnection(wangle::PipelineBase* pipeline) override;
  // EventBase线程里执行
  bool OnConnectionClosed(uint64_t conn_id) override;

  /////////////////////////////////////////////////////////////////////////////////////
  wangle::PipelineBase* FindPipeline(uint64_t conn_id) {
    if (conn_id >> 32 != thread_id_) return nullptr;
    return FindPtrOrNull(pipelines_, conn_id & 0xffffffff);
  }
  
  TimerManager* GetTimerManager() {
    return timer_manager_.get();
  }
  
protected:
  inline uint32_t GetNextID() {
    if (current_conn_id_ == 0) ++current_conn_id_;
    return current_conn_id_++;
  }
  
  uint32_t current_conn_id_ {0};      // 0为无效值
  
  size_t thread_id_ {0};  // 线程ID
  std::unordered_map<uint32_t, wangle::PipelineBase*> pipelines_;

  std::unique_ptr<TimerManager> timer_manager_;
};


ThreadLocalConnManager& GetConnManagerByThreadLocal();

}

#endif
