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

#include "nebula/net/handler/echo/echo_handler.h"

//#include "nebula/net/engine/tcp_client_group.h"
//#include "nebula/net/engine/tcp_client.h"
//#include "nebula/net/engine/tcp_server.h"

//using namespace nebula;

class NetEngineServerTest : public nebula::BaseServer {
public:
  NetEngineServerTest() = default;
  virtual ~NetEngineServerTest() override = default;
  
protected:
  bool Initialize() override {
    RegisterService("net_engine_server_test", "tcp_server", "zproto");
    
    BaseServer::Initialize();
    
    return true;
  }
  
  bool Run() override {
    BaseServer::Run();
    return true;
  }
};

////////////////////////////////////////////////////////////////////////////
//
//class ZProtoClientHandler {
//public:
//  ZProtoClientHandler() {
//    ZProtoEventCallback::Initializer(ZProtoClientHandler::OnNewConnection,
//                                     ZProtoClientHandler::OnDataReceived,
//                                     ZProtoClientHandler::OnConnectionClosed);
//  }
//
//  ///////////////////////////////////////////////////////////////////////////////////////
//  static int OnNewConnection(nebula::TcpServiceBase* service, NebulaPipelinePtr pipeline) {
//    LOG(INFO) << "OnNewConnection - conn new";
//    return 0;
//  }
//
//  static int OnDataReceived(NebulaPipelinePtr pipeline, std::shared_ptr<BasicSyncMessage> message_data) {
//    LOG(INFO) << "OnDataReceived - recv data";
//    return 0;
//  }
//
//  static int OnConnectionClosed(nebula::TcpServiceBase* service, NebulaPipelinePtr pipeline) {
//    LOG(INFO) << "OnDataReceived - conn closed";
//    return 0;
//  }
//};


////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  // static NetEngineClientTest g_handler_initializer;
  return nebula::DoMain<NetEngineServerTest>(argc, argv);
}

