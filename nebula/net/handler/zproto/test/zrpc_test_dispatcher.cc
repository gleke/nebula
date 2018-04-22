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

#include "zrpc_test_dispatcher.h"

#include "zrpc_test.pb.h"
#include "nebula/net/rpc/zrpc_service_util.h"
#include "zrpc_test_service_impl.h"
#include "nebula/net/zproto/api_message_box.h"

static ZRpcTestDispatcher g_rpc_test_dispatcher;

ZRpcTestDispatcher::ZRpcTestDispatcher() {
  ZRpcUtil::Register("zproto.ZRpcTestReq", ZRpcTestDispatcher::OnZRpcTestReq);
}

ProtoRpcResponsePtr ZRpcTestDispatcher::OnZRpcTestReq(RpcRequestPtr request) {
  CAST_RPC_REQUEST(ZRpcTestReq, rpc_test_req);
  LOG(INFO) << rpc_test_req.Utf8DebugString();
  zproto::ZRpcTestRsp message_rsp;
  
  ZRpcTestServiceImpl service_impl;
  service_impl.OnZRpcTest(rpc_test_req, &message_rsp);
  
  return ::MakeRpcOK(message_rsp);
}
