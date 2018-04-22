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

#ifndef NEBULA_NET_HANDLER_NEBULA_HANDLER_UTIL_H_
#define NEBULA_NET_HANDLER_NEBULA_HANDLER_UTIL_H_

#include <glog/logging.h>

#include <folly/futures/Future.h>
#include <folly/MoveWrapper.h>

#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/thread_local_conn_manager.h"
#include "nebula/net/engine/tcp_client_group.h"
#include "nebula/net/net_engine_manager.h"

// 用一个结构体的
struct WriterUtil {
  
  template <typename T>
  static folly::Future<folly::Unit> Write(uint64_t conn_id, T msg) {
    auto net_engine = nebula::NetEngineManager::GetInstance();
    // auto& conn_manager = nebula::GetConnManagerByThreadLocal();
    
    uint32_t tid = conn_id >> 32;
    // 检查是否在同一线程
//    if (conn_manager.is_self_thread(tid)) {
//      // 同一线程里
//      auto pipeline = conn_manager.FindPipeline(conn_id);
//      if (!pipeline) {
//        LOG(ERROR) << "Write - invalid error, not find conn_id: " << nebula::ToString(conn_id);
//        return folly::makeFuture();
//      }
//      
//      // return write(pipeline, std::forward(msg));
//      return nebula::write<T>(pipeline, std::forward<T>(msg));
//
//    } else {
//      // 不在同一线程。
//      // 应用层要尽可能要让发送在同一线程里
      auto evb = net_engine->GetEventBaseByThreadID(tid);
      if (!evb) {
        LOG(ERROR) << "Write - invalid error, not find thread_id: " << nebula::ToString(conn_id);
        return folly::makeFuture();
      }

      // 是否可行？？？
      folly::Promise<folly::Unit> p;
      auto f = p.getFuture();
      auto p_move = folly::makeMoveWrapper(p);
      auto msg_move = folly::makeMoveWrapper(msg);
      evb->runInEventBaseThread([p_move, conn_id, msg_move]() mutable {
        auto& conn_manager2 = nebula::GetConnManagerByThreadLocal();
        auto pipeline = conn_manager2.FindPipeline(conn_id);
        if (!pipeline) {
          LOG(ERROR) << "Write - invalid error, not find conn_id: " << nebula::ToString(conn_id);
          // return folly::makeFuture();
          p_move.move().setValue();
        } else {
          // LOG(INFO) << "Write - write data by conn_id: " << nebula::ToString(conn_id);
          nebula::write<T>(pipeline, std::forward<T>(msg_move.move())).then([p_move]() mutable {
            p_move.move().setValue();
          });
        }
      });

      return f;
//    }
  }
  
  template <typename T>
  static folly::Future<folly::Unit> Write(const std::string& service_name, T msg) {
    auto net_engine = nebula::NetEngineManager::GetInstance();
    // auto& conn_manager = nebula::GetConnManagerByThreadLocal();
    
    auto service = net_engine->Lookup(service_name);
    if (!service) {
      LOG(ERROR) << "Write - invalid error, not find service_name: " << service_name;
      return folly::makeFuture();
    }
    
    auto group = std::static_pointer_cast<nebula::TcpClientGroupBase>(service);
    nebula::TcpClientGroupBase::OnlineTcpClient client;
    if (!group->GetOnlineClientByRandom(&client)) {
      LOG(ERROR) << "Write - invalid error, not online client's service_name: " << service_name;
      return folly::makeFuture();
    }
    
    // if (tcp_client_group)
    auto pipeline = client.second.lock();
    if (!pipeline) {
      LOG(ERROR) << "Write - invalid error, not online client's service_name: " << service_name;
      return folly::makeFuture();
    }

    auto client_evb = pipeline->getTransport()->getEventBase();

    if (client_evb->isInEventBaseThread()) {
      return nebula::write<T>(pipeline.get(), std::forward<T>(msg));
    } else {
      // 不在同一线程。
      // 应用层要尽可能要让发送在同一线程里
      
      // 是否可行？？？
      folly::Promise<folly::Unit> p;
      auto f = p.getFuture();
      auto p_move = folly::makeMoveWrapper(p);
      auto msg_move = folly::makeMoveWrapper(msg);
      
      auto cpature_pipeline = client.second;
      client_evb->runInEventBaseThread([p_move, cpature_pipeline, msg_move]() mutable {
        auto pl = cpature_pipeline.lock();
        if (!pl) {
          // LOG(ERROR) << "Write - invalid error, not find conn_id: " << nebula::ToString(conn_id);
          // return folly::makeFuture();
          p_move.move().setValue();
        } else {
          // LOG(INFO) << "Write - write data by conn_id: " << nebula::ToString(conn_id);
          nebula::write<T>(pl.get(), std::forward<T>(msg_move.move())).then([p_move]() mutable {
            p_move.move().setValue();
          });
        }
      });
      
      return f;
    }
  }

};

#endif

