/*
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula
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

#include "nebula/net/base_server.h"
// #include "nebula/base/timer_manager.h"
// #include "nebula/net/zproto/zproto_event_callback.h"

#include "nebula/base/logger/glog_util.h"

#include "nebula/net/handler/telegram/mtproto_object_handler.h"

//#include "nebula/net/engine/tcp_client_group.h"
//#include "nebula/net/engine/tcp_client.h"
//#include "nebula/net/engine/tcp_server.h"

//using namespace nebula;

// 转发器，通过ConnData绑定handler
// 并转发给具体的handler进行处理
  ///////////////////////////////////////////////////////////////////////////////////////
int OnTelegramNewConnection(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  LOG(INFO) << "OnTelegramNewConnection";
  return 0;
}

int OnTelegramDataReceived(nebula::ZProtoPipeline* pipeline, std::shared_ptr<MTProtoBase> message_data) {
  LOG(INFO) << "OnTelegramDataReceived";
  return 0;
}

int OnTelegramConnectionClosed(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  LOG(INFO) << "OnTelegramConnectionClosed";
  return 0;
}

class TelegramServerTest : public nebula::BaseServer {
public:
  TelegramServerTest() = default;
  virtual ~TelegramServerTest() override = default;
  
protected:
  bool Initialize() override {
    // 初始化处理器
    TelegramEventCallback::Initializer(OnTelegramNewConnection,
                                       OnTelegramDataReceived,
                                       OnTelegramConnectionClosed);

    RegisterService("telegram_server_test", "tcp_server", "telegram");

    BaseServer::Initialize();
    
    return true;
  }
  
  bool Run() override {
    BaseServer::Run();
    TelegramEventCallback::Destroy();
    return true;
  }
};

////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  // static NetEngineClientTest g_handler_initializer;
  return nebula::DoMain<TelegramServerTest>(argc, argv);
}

