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

#include "frontend/client_base_handler.h"

#include "frontend/auth_client_handler.h"
#include "frontend/messenger_client_handler.h"

// #include "frontend/online_status_client_handler.h"
// #include "frontend/push_channel_client_handler.h"

#include "nebula/net/handler/zproto/zproto_handler.h"

int ClientBaseHandler::OnNewConnectionCallback(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  auto h = pipeline->getHandler<ZProtoHandler>();
  DCHECK(h);
  
  const std::string& service_name = h->GetServiceBase()->GetServiceName();
  auto handler = ClientBaseHandler::MakeHandler(service_name);
  
  if (!handler) return -1;
  
  handler->Initialize(service, pipeline, h->GetConnID());
  h->SetAttachData(handler);
  
  return handler->OnNewConnection();
}

int ClientBaseHandler::OnDataReceivedCallback(nebula::ZProtoPipeline* pipeline, std::shared_ptr<zproto::PackageMessage> message_data) {
  auto h = pipeline->getHandler<ZProtoHandler>();
  DCHECK(h);
  
  auto handler = h->CastByGetAttachData<ClientBaseHandler>();
  
  if (!handler) {
    LOG(ERROR) << "OnDataReceived - CastByGetAttachData";
    return -1;
  }
  
  return handler->OnDataReceived(message_data);
}

int ClientBaseHandler::OnConnectionClosedCallback(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  auto h = pipeline->getHandler<ZProtoHandler>();
  DCHECK(h);
  
  auto handler = h->CastByGetAttachData<ClientBaseHandler>();
  
  if (!handler) {
    LOG(ERROR) << "OnConnectionClosed - CastByGetAttachData";
    return -1;
  }
  
  return handler->OnConnectionClosed();
}

std::shared_ptr<ClientBaseHandler> ClientBaseHandler::MakeHandler(const std::string& service_name) {
  std::shared_ptr<ClientBaseHandler> handler;

  if (service_name == "messenger_client") {
    handler = std::make_shared<MessengerClientHandler>();
  } else if (service_name == "auth_client") {
    handler = std::make_shared<AuthClientHandler>();
  // } else if (service_name == "push_channel_client") {
  //   handler = std::make_shared<PushChannelClientHandler>();
  // } else if (service_name == "online_statsus_client") {
  //   handler = std::make_shared<OnlineStatusClientHandler>();
  } else {
    LOG(ERROR) << "MakeHandler - Invalid service_name: " << service_name;
    return handler;
  }

  return handler;
}

