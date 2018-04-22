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

#include "nebula/net/engine/tcp_service_base.h"

#include "nebula/net/thread_local_conn_manager.h"

namespace nebula {

// TODO(@benqi): 不直接使用GetConnManagerByThreadLocal, 通过回调注册来进行调用
uint64_t TcpServiceBase::OnNewConnection(wangle::PipelineBase* pipeline) {
  return GetConnManagerByThreadLocal().OnNewConnection(pipeline);
}

bool TcpServiceBase::OnConnectionClosed(uint64_t conn_id) {
  return GetConnManagerByThreadLocal().OnConnectionClosed(conn_id);
}

}
