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

#include "nebula/net/engine/tcp_client_group.h"

#include <glog/logging.h>

#include <folly/Random.h>
#include <folly/SocketAddress.h>

namespace nebula {

uint64_t TcpClientGroupBase::OnNewConnection(wangle::PipelineBase* pipeline) {
  auto conn_id = TcpServiceBase::OnNewConnection(pipeline); {
    std::weak_ptr<wangle::PipelineBase> cli(pipeline->shared_from_this());
    // TODO(@benqi): 读多写少，用读写锁
    std::lock_guard<std::mutex> g(online_mutex_);
    online_clients_.push_back(std::make_pair(conn_id, cli));
  }
  return conn_id;
}

bool TcpClientGroupBase::OnConnectionClosed(uint64_t conn_id) {
  {
  std::lock_guard<std::mutex> g(online_mutex_);
  for (auto it=online_clients_.begin(); it!=online_clients_.end(); ++it) {
    if (it->first == conn_id) {
      online_clients_.erase(it);
      break;
    }
  }
  }
  
  return TcpServiceBase::OnConnectionClosed(conn_id);
}

bool TcpClientGroupBase::GetOnlineClientByRandom(OnlineTcpClient* client) const {
  bool rv = true;
  
  folly::ThreadLocalPRNG rng; {
    std::lock_guard<std::mutex> g(online_mutex_);
    if (!online_clients_.empty()) {
      uint32_t idx = folly::Random::rand32(static_cast<uint32_t>(online_clients_.size()));
      *client = online_clients_[idx];
    } else {
      rv = false;
    }
  }
  
  return rv;
}

// TODO(@benqi): 暂时未实现
bool TcpClientGroupBase::GetOnlineClientByConsistencyHash(OnlineTcpClient* client) const {
  bool rv = false;
  return rv;
}

bool TcpClientGroupBase::GetOnlineClients(OnlineTcpClientList* clients) const {
  bool rv = true; {
    std::lock_guard<std::mutex> g(online_mutex_);
    
    if (!online_clients_.empty()) {
      *clients = online_clients_;
    } else {
      rv = false;
    }
  }
  return rv;
}
  
}

