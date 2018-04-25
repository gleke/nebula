/*
 *  Copyright (c) 2018, https://github.com/nebulaim/nebula
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

#include "relay/relay_table.h"


void RelayTableManager::OnRelayDataAvailable(const std::string peer_tag,
         const folly::SocketAddress& address,
         const std::unique_ptr<folly::IOBuf>& buf) {

  std::shared_ptr<RelayTable> table;

  auto it = relay_table_map_.find(peer_tag);
  if (it != relay_table_map_.end()) {
    // table = it->second;
    // bool found = false;
    for (auto& i : it->second->peers) {
      if (i.addr == address) {
        // found = true;
        table = it->second;
        break;
      }
    }
    if (!table) {
      table->peers.push_back(Endpoint{address, 0});
    }
    // it->second.peers.push_back(address);
    // Endpoint&
  } else {
    //RelayTable table;
    table = std::make_shared<RelayTable>();
    table->peer_tag = peer_tag;
    table->peers.push_back(Endpoint{address, 0});
    relay_table_map_.emplace(std::make_pair(peer_tag, table));
  }

  for (auto& i : it->second->peers) {
    if (i.addr != address) {
      cb_->onRelayData(i.addr, buf->clone());
    }
  }
}
