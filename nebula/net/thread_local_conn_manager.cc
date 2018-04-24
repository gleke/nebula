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

#include "nebula/net/thread_local_conn_manager.h"

#include <folly/io/async/EventBaseManager.h>
#include <folly/SingletonThreadLocal.h>

namespace nebula {

///////////////////////////////////////////////////////////////////////////////////////
uint64_t ThreadLocalConnManager::OnNewConnection(wangle::PipelineBase* pipeline) {
    uint32_t conn_id = 0;
    bool sucess = false;
    do {
        conn_id = ++current_conn_id_;
        // 保证conn_id不为0
        if (conn_id == 0) ++current_conn_id_;
        sucess = pipelines_.insert(std::make_pair(conn_id, pipeline)).second;
    } while(!sucess);
    
    return static_cast<uint64_t>(thread_id_) << 32 | conn_id;
}

bool ThreadLocalConnManager::OnConnectionClosed(uint64_t conn_id) {
    bool rv = true;
    auto it = pipelines_.find(conn_id & 0xffffffff);
    if (it!=pipelines_.end()) {
        pipelines_.erase(it);
    } else {
        rv = false;
        LOG(ERROR) << "OnConnectionClosed - not find conn_id: " << conn_id;
    }
    return rv;
}

ThreadLocalConnManager& GetConnManagerByThreadLocal() {
    return folly::SingletonThreadLocal<ThreadLocalConnManager>::get();
//  g_cache([]() {
//        return new ThreadLocalConnManager();
//    });
//    return g_cache.get();
}

}

