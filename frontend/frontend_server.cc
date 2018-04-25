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

#include "frontend/frontend_server.h"

#include "frontend/frontend_server_handler.h"
#include "frontend/client_base_handler.h"

bool FrontendServer::Initialize() {
  // 初始化处理器
  MTProtoEventCallback::Initializer(FrontendServerHandler::OnNewConnectionCallback,
        FrontendServerHandler::OnDataReceivedCallback,
        FrontendServerHandler::OnConnectionClosedCallback);

  ZProtoEventCallback::Initializer(ClientBaseHandler::OnNewConnectionCallback,
        ClientBaseHandler::OnDataReceivedCallback,
        ClientBaseHandler::OnConnectionClosedCallback);

  // 注册服务
  // 客户端连接服务
  RegisterService("frontend_server", "tcp_server", "mtproto");
  
/*
  // TODO(@benqi): 直接转发到router_server
  // 推消息等
  RegisterService("push_channel_client", "tcp_client", "zproto");
  // 在线状态
  RegisterService("online_status_client", "tcp_client", "zproto");
  // 登录认证
 */

  // RegisterService("auth_client", "tcp_client", "zproto");
  // IM核心服务
  RegisterService("messenger_client", "tcp_client", "zproto");
  // 非IM核心业务
  // RegisterService("app_client", "tcp_client", "zproto");
  return BaseServer::Initialize();
}

bool FrontendServer::Run() {
  BaseServer::Run();
  MTProtoEventCallback::Destroy();
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  return nebula::DoMain<FrontendServer>(argc, argv);
}
