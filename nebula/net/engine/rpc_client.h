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

#ifndef NEBULA_NET_ENGINE_RPC_CLIENT_H_
#define NEBULA_NET_ENGINE_RPC_CLIENT_H_

#include "nebula/net/engine/tcp_client.h"

namespace nebula {
  
template <typename Pipeline = DefaultPipeline>
class RpcClient : public TcpClient<Pipeline> {
public:
  RpcClient(const ServiceConfig& config, const IOThreadPoolExecutorPtr& io_group)
    : TcpClient<Pipeline>(config, io_group) {
  }

  virtual ~RpcClient() = default;
  
  // Impl from TcpServiceBase
  ServiceModuleType GetModuleType() const override {
    return ServiceModuleType::RPC_CLIENT;
  }
};
  
}

#endif
