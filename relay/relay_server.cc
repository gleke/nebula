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

#include "relay/relay_server.h"

#include "nebula/net/base_server.h"
#include "nebula/base/config_manager.h"
#include "nebula/net/net_engine_manager.h"
#include "nebula/net/handler/module_install.h"

#include "relay/tgvoip_handler.h"

bool RelayServer::Initialize() {
  // 注册服务
  // 客户端连接服务
  RegisterService("relay_server", "udp_server", "tgvoip");
  return nebula::BaseServer::Initialize();
}

bool RelayServer::Run() {
  nebula::BaseServer::Run();
  return true;
}

void RelayServer::InstallModule() {
  ModuleUdpTGVoipInitialize();
}

/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  return nebula::DoMain<RelayServer>(argc, argv);
}
