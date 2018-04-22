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

#include "nebula/net/base/nebula_pipeline.h"

namespace nebula {
  
// TODO(@benqi): 配置
// const uint64_t kDefaultMinAvailable = 4096;
// const uint64_t kDefaultAllocationSize = 4096;

void SetPipelineAddr(wangle::PipelineBase* pipeline, folly::AsyncTransportWrapper* sock) {
  // Initialize TransportInfo and set it on the pipeline
  auto transportInfo = std::make_shared<wangle::TransportInfo>();
  folly::SocketAddress localAddr, peerAddr;
  sock->getLocalAddress(&localAddr);
  sock->getPeerAddress(&peerAddr);
  transportInfo->localAddr = std::make_shared<folly::SocketAddress>(localAddr);
  transportInfo->remoteAddr = std::make_shared<folly::SocketAddress>(peerAddr);
  pipeline->setTransportInfo(transportInfo);
}

}
