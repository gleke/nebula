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

#ifndef	RELAY_RELAY_TABLE_H_
#define RELAY_RELAY_TABLE_H_

#include <string>
#include <list>
#include <map>
#include <folly/SocketAddress.h>
#include <folly/io/IOBuf.h>

struct Endpoint {
  folly::SocketAddress addr;
  uint64_t last_recved_time;
};

struct RelayTable {
  std::string peer_tag;
  std::list<Endpoint> peers;
};

class RelayTableManager {
public:
  class Callback {
  public:
    virtual void onRelayData(const folly::SocketAddress& address,
           const std::unique_ptr<folly::IOBuf>& buf) {}
    virtual ~Callback() = default;
  };

  explicit RelayTableManager(Callback* cb)
    : cb_(cb) {}

  void OnRelayDataAvailable(const std::string peer_tag,
            const folly::SocketAddress& address,
            const std::unique_ptr<folly::IOBuf>& buf);

private:
  Callback *cb_;
  // std::shared_ptr<folly::AsyncUDPSocket> socket_;
  std::map<std::string, std::shared_ptr<RelayTable>> relay_table_map_;
};

#endif
