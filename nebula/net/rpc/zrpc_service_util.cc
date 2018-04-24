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

#include "nebula/net/rpc/zrpc_service_util.h"

#include <folly/MoveWrapper.h>
#include <folly/Hash/Checksum.h>

#include "nebula/base/id_util.h"
#include "nebula/base/map_util.h"

#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/thread_local_conn_manager.h"
#include "nebula/net/engine/tcp_client_group.h"
#include "nebula/net/net_engine_manager.h"

#include "nebula/net/rpc/zrpc_client_handler.h"

using namespace zproto;

// std::map<int, ZRpcUtil::ServiceFunc> ZRpcUtil::g_rpc_services;
// static ProtoRpcResponsePtr kEmptyResponse;

folly::Future<zproto::ProtoRpcResponsePtr> ZRpcUtil::DoClientCall(const std::string& service_name, zproto::RpcRequestPtr request) {
  CHECK(request);
  
  // TODO(@benqi): 移入tcp_client_group_util.h里
  auto net_engine = nebula::NetEngineManager::GetInstance();
  // auto& conn_manager = nebula::GetConnManagerByThreadLocal();
  
  auto service = net_engine->Lookup(service_name);
  if (!service) {
    LOG(ERROR) << "Write - invalid error, not find service_name: " << service_name;
    ProtoRpcResponsePtr r = std::make_shared<RpcInternalError>(request->message_id());
    return folly::makeFuture(r);
  }
  
  auto group = std::static_pointer_cast<nebula::TcpClientGroupBase>(service);
  nebula::TcpClientGroupBase::OnlineTcpClient client;
  if (!group->GetOnlineClientByRandom(&client)) {
    LOG(ERROR) << "Write - invalid error, not online client's service_name: " << service_name;
    ProtoRpcResponsePtr r = std::make_shared<RpcInternalError>(request->message_id());
    return folly::makeFuture(r);
  }
  
  auto pipeline = client.second.lock();
  if (!pipeline) {
    LOG(ERROR) << "Write - invalid error, not online client's service_name: " << service_name;
    ProtoRpcResponsePtr r = std::make_shared<RpcInternalError>(request->message_id());
    return folly::makeFuture(r);
  }
  
  auto handler = dynamic_cast<ZRpcClientPipeline*>(pipeline.get())->getHandler<ZRpcClientHandler>();
  
  // TODO(@benqi): 线程同步
  return handler->ServiceCall(request);
}

void ZRpcUtil::Register(int method_id, ServiceFunc f) {
  if (ContainsKey(GetInstance().g_rpc_services, method_id)) {
    // 重新检查
    LOG(FATAL) << "Register - duplicate entry for method_id: " << method_id;
  } else {
    GetInstance().g_rpc_services.emplace(method_id, f);
  }
}

void ZRpcUtil::Register(const std::string& message_name, ServiceFunc f) {
  auto method_id = folly::crc32c((const uint8_t*)message_name.data(), message_name.length());
  DLOG(INFO) << "message_name: " << message_name
              << ", method_id: " << method_id;
  
  Register(method_id, f);
}

ProtoRpcResponsePtr ZRpcUtil::DoServiceCall(RpcRequestPtr request) {
  CHECK(request);
  
  ProtoRpcResponsePtr r;
  auto it = GetInstance().g_rpc_services.find(request->method_id);
  if (it != GetInstance().g_rpc_services.end()) {
    r = (it->second)(request);
    // r->set_message_id(GetNextIDBySnowflake());
    // return r;
    //(it->second)(request);
    r->set_req_message_id(request->message_id());
  } else {
    LOG(ERROR) << "ServiceCall - Not register request: " << request->ToString();
    r = std::make_shared<RpcInternalError>(request->message_id());
  }
  
  // TODO(@benqi): 是否要关注应用层的设置？
  r->set_message_id(GetNextIDBySnowflake());
  r->set_auth_id(request->auth_id());
  r->set_session_id(request->session_id());
  r->seq_num = request->seq_num;
  
  // 如果response未设置，则填充attach_data
  if (!r->has_attach_data() && request->has_attach_data()) {
    r->set_has_attach_data();
    r->attach_data = request->attach_data;
    
    // TODO(@benqi): 设置和机器相关的attach_data数据
  }
  return r;
}

