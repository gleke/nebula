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

#include "nebula/net/rpc/zrpc_service.h"

// #define DEBUG_TEST
#ifdef DEBUG_TEST
#include "proto/zproto/zproto_message_types_util.h"
#include "nebula/net/zproto/api/api_message_boxed.h"
#endif

#include "nebula/net/rpc/zrpc_service_util.h"

folly::Future<zproto::ProtoRpcResponsePtr> ZRpcService::operator()(zproto::RpcRequestPtr request) {
  LOG(INFO) << "ZRpcService - recv request: " << request->ToString();
  
  return ZRpcUtil::DoServiceCall(request);
  
  // Oh no, we got Bonked!  Quick, Bonk back
  // printf("Bonk: %s, %i\n", request.message.c_str(), request.type);
  
  /* sleep override: ignore lint
   * useful for testing dispatcher behavior by hand
   */
  // Wait for a bit
#ifdef DEBUG_TEST
  return folly::futures::sleep(std::chrono::seconds(1/*request.type*/))
  .then([request]() {
    
    auto encoded_req = std::static_pointer_cast<EncodedRpcRequest>(request);
    auto req = ::ToApiRpcRequest<zproto::TokenAuthReq>(encoded_req);
    
    // auto req = std::static_pointer_cast<ApiRpcRequest<zproto::TokenAuthReq>>(request);
    std::cout << (*req)->Utf8DebugString() << std::endl;
    
    auto response = std::make_shared<ApiRpcOk<zproto::AuthRsp>>();
    response->package_header = req->package_header;
    response->req_message_id = request->message_id();
    (*response)->set_user_id("@benqi");
    // ProtoRpcResponsePtr response;
    // response.string_thing = "Stop saying " + request.message + "!";
    // response.i32_thing = request.type;
    return response;
  });
#endif
}

