/*
 *  Copyright (c) 2016, https://github.com/nebula-im/imengine
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

#include "frontend/auth_client_handler.h"

#include "base/message_handler_util.h"
#include "nebula/net/net_engine_manager.h"

#include "frontend/frontend_server_handler.h"

int AuthClientHandler::OnNewConnection() {
  return 0;
}

int AuthClientHandler::OnDataReceived(std::shared_ptr<zproto::PackageMessage> message_data) {
  auto conn_id = message_data->birth_conn_id();
  
  auto evb = nebula::NetEngineManager::GetInstance()->GetEventBaseByThreadID(conn_id>>32);
  if (!evb) {
    // 不可能发生，消息数据被篡改了
    LOG(ERROR) << "OnDataReceived - invalid error, not find thread_id: " << nebula::ToString(conn_id);
    return -1;
  }

  // 转发给front_server_handler线程
  evb->runInEventBaseThread([conn_id, message_data]() {
    auto& conn_manager2 = nebula::GetConnManagerByThreadLocal();
    auto pipeline = conn_manager2.FindPipeline(conn_id);
    if (pipeline) {
      auto handler = pipeline->getHandler<MTProtoHandler>()->CastByGetAttachData<FrontendServerHandler>();
      handler->OnMessengerClientDataArrived(std::static_pointer_cast<zproto::ProtoRpcResponse>(message_data));
    } else {
      LOG(ERROR) << "Recv auth_rsp, but client closed, message_data: " << message_data->ToString();
    }
  });
  
  return 0;
}

int AuthClientHandler::OnConnectionClosed() {
  return 0;
}
