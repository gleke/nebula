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

#ifndef NEBULA_NET_ENGINE_TCP_CLIENT_POOL_H_
#define NEBULA_NET_ENGINE_TCP_CLIENT_POOL_H_

#include "nebula/net/base/service_base.h"

namespace nebula {
  
//TODO(@benqi): 连接池实现
template<typename Pipeline = DefaultPipeline>
class TcpClientPool {
public:
  virtual ~TcpClientPool() = default;
};

}

#endif
