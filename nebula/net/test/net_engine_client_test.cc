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
#include "nebula/base/timer_manager.h"
// #include "nebula/net/zproto/zproto_event_callback.h"

// #include "nebula/net/zproto/api/api_message_box.h"

#include "nebula/net/handler/nebula_handler_util.h"

class NetEngineClientTest : public nebula::BaseServer {
public:
  NetEngineClientTest() = default;
  virtual ~NetEngineClientTest() override = default;
  
protected:
  bool Initialize() override {
    RegisterService("net_engine_client_test", "tcp_client", "zproto");
    
    BaseServer::Initialize();
    
    timer_manager_->ScheduleRepeatingTimeout([]() {
#if 0
      // static int i = 0;
      // LOG(INFO) << "ScheduleRepeatingTimeout - " << i++;
      
      ApiRpcRequest<zproto::TokenAuthReq> token_req;
      token_req->set_app_key(1);
      token_req->set_app_token("01234567899876543210");
      token_req->set_device_hash("111111111111111111111");
      token_req->set_device_title("benqi");
      token_req->set_time_zone("Shanghai");
      
      token_req.package_header = {1,2, 3};
      // token_req.req_message_id = 1;
      token_req.method_id = 2;
      
      std::unique_ptr<folly::IOBuf> o;
      token_req.SerializeToIOBuf(o);

      WriterUtil::Write("net_engine_client_test", std::move(o));
#endif
    }, 5000);

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
  return nebula::DoMain<NetEngineClientTest>(argc, argv);
}

