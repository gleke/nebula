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
#include "nebula/net/rpc/zrpc_service_util.h"

#include "nebula/net/zproto/api_message_box.h"

//////////////////////////////////////////////////////////////////////////////////////////////
class ZRpcServerTest : public nebula::BaseServer {
public:
  ZRpcServerTest() = default;
  ~ZRpcServerTest() override = default;
  
protected:
  bool Initialize() override {
    RegisterService("zrpc_server_test", "rpc_server", "zrpc");
    
    // ZRpcUtil::Register("zproto.ZRpcTestReq", DoZRpcTestReq);

    BaseServer::Initialize();
    return true;
  }
  
  bool Run() override {
    BaseServer::Run();
    return true;
  }
};

////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  return nebula::DoMain<ZRpcServerTest>(argc, argv);
}

