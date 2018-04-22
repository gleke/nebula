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

#include <string>
#include <iostream>

#include "nebula/base/testing/testing_util.h"
//#include "nebula/net/zproto/api/api_message_box.h"

using namespace nebula;

void TestZProto() {
#if 0
  auto req = std::make_shared<ApiRpcRequest<teamtalk::IMLoginReq>>();
  (*req)->set_user_name("benqi@zhazha");
  (*req)->set_password("benqi@zhazha.nebula.im");
  (*req)->set_online_status(teamtalk::USER_STATUS_ONLINE);
  (*req)->set_client_type(teamtalk::CLIENT_TYPE_MAC);
//
//  ApiRpcRequest<zproto::TokenAuthReq> token_req;
//  token_req->set_app_key(1);
//  token_req->set_app_token("01234567899876543210");
//  token_req->set_device_hash("111111111111111111111");
//  token_req->set_device_title("benqi");
//  token_req->set_time_zone("Shanghai");
//  
//  token_req.package_header = {1,2, 3};
//  token_req.req_message_id = 1;
//  token_req.method_id = 2;

  std::unique_ptr<folly::IOBuf> o;
  req->SerializeToIOBuf(o);
  
  // folly::io::RWPrivateCursor c2(o.get());
//  auto index = folly::Endian::big32((int32_t)1);
//  c2.write(index);
//  
  Frame frame;
  frame.Decode(std::move(o));
  
  ProtoRawData proto_raw_data;
  proto_raw_data.Decode(frame);
  
  Package package;
  package.Decode(proto_raw_data);

  auto req2 = std::make_shared<ApiRpcRequest<teamtalk::IMLoginReq>>();
  req2->Decode(package);
  
  
  std::cout << (*req2)->Utf8DebugString() << std::endl;
  //  folly::io::Cursor c(o.get());
//  frame.package_index = c.readBE<int32_t>();
//  frame.header = c.readBE<uint8_t>();
//  frame.body_length = c.readBE<int32_t>();
#endif
  
  
  
/*
  RpcRequest req;
  req.package_header = {1,2};
  req.zproto_header = {3,4};
  req.method_id = 123;
  req.body = folly::IOBuf::copyBuffer(std::string("0123456789"));
  
  std::unique_ptr<folly::IOBuf> o;
  req.SerializeToIOBuf(o);
  folly::io::RWPrivateCursor c2(o.get());
  
  auto index = folly::Endian::big32((int32_t)1);;
  // HostToNet32(1);
  // *(int32_t*)(o->writableData()) = index;
  c2.write(index);
  
  Frame frame;
  folly::io::Cursor c(o.get());
  frame.package_index = c.readBE<int32_t>();
  frame.header = c.readBE<uint8_t>();
  frame.body_length = c.readBE<int32_t>();
  o->trimStart(9);
  frame.body.swap(o);
  
  ProtoRawData proto_raw_data;
  proto_raw_data.Decode(frame);
  
  Package package;
  package.Decode(proto_raw_data);
  
  PlainTextMessage plain_text_message;
  plain_text_message.Decode(package);
  
  ZProto zproto;
  zproto.Decode(plain_text_message);
  
  ProtoRpcRequest proto_rpc_request;
  proto_rpc_request.Decode(zproto);
  
  BasicSync sync;
  sync.Decode(proto_rpc_request);
  
  RpcRequest req2;
  req2.Decode(sync);
*/
  
  // TODO(@wubenqi)
  // 直接写吧
}

////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  nebula::TestingFuncManager::Testing();
  
  TestZProto();
  return 0;
}
