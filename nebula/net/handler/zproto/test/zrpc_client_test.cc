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

#include "nebula/net/base_server.h"

#include "zrpc_test.pb.h"
#include "nebula/net/zproto/api_message_box.h"

#include "nebula/base/timer_manager.h"
#include "nebula/net/rpc/zrpc_service_util.h"

class ZRpcClientTest : public nebula::BaseServer {
public:
  ZRpcClientTest() = default;
  ~ZRpcClientTest() override = default;
  
protected:
  bool Initialize() override {
    RegisterService("zrpc_client_test", "rpc_client", "zrpc");
    
    BaseServer::Initialize();
  
    // once
    timer_manager_->ScheduleRepeatingTimeout([]() {
      auto req = std::make_shared<ApiRpcRequest<zproto::ZRpcTestReq>>();
      (*req)->set_req_id("11111111");
      ZRpcUtil::DoClientCall("zrpc_client_test", req)
      .within(std::chrono::milliseconds(5000))
      .then([](ProtoRpcResponsePtr rsp2) {
        LOG(INFO) << "zrpc_client_test rsp: " << rsp2->ToString();
      });
    }, 1000);

    return true;
  }
  
  bool Run() override {
    BaseServer::Run();
    return true;
  }
  
};

#include <folly/Checksum.h>

////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  
  // auto method_id = folly::crc32c((const uint8_t*)message_name.data(), message_name.length());
  std::string method_id("zproto.StartTestingAuthReq");
  auto c = folly::crc32c((const uint8_t *)method_id.c_str(), method_id.length());
  printf("%u\n", c);
  
  return nebula::DoMain<ZRpcClientTest>(argc, argv);
}

