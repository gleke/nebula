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

#include "nebula/net/handler/nebula_base_handler.h"

namespace nebula {
  
uint64_t NebulaBaseHandler::OnNewConnection(wangle::PipelineBase* pipeline, const std::string& remote_address) {
  // 连接建立
  // TODO(@benqi): 检查输入参数以及状态
  conn_state_ = ConnState::CONNECTED;
  remote_address_ = remote_address;
  conn_id_ = service_->OnNewConnection(pipeline);

  return conn_id_;
}

void NebulaBaseHandler::OnConnectionClosed() {
  if (conn_state_ == ConnState::CONNECTED) {
    service_->OnConnectionClosed(conn_id_);
    conn_state_ = ConnState::CLOSED;
    remote_address_.clear();
    conn_id_ = 0;
  } else {
    // TODO(@benqi): LOG() <<
  }
}

}
