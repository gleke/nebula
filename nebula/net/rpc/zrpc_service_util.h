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

#ifndef NEBULA_NET_RPC_ZRPC_SERVICE_UTIL_H_
#define NEBULA_NET_RPC_ZRPC_SERVICE_UTIL_H_

#include <folly/futures/Future.h>

#include "nebula/net/zproto/zproto_package_data.h"

// ZRpc帮助类
struct ZRpcUtil {
  static ZRpcUtil& GetInstance() {
    static ZRpcUtil g_instance;
    return g_instance;
  }
  
  using  ServiceFunc = std::function<zproto::ProtoRpcResponsePtr(zproto::RpcRequestPtr)>;

  static folly::Future<zproto::ProtoRpcResponsePtr> DoClientCall(const std::string& service_name, zproto::RpcRequestPtr request);
  
  static void Register(int method_id, ServiceFunc f);
  
  // Request名字的crc32值作为method_id
  static void Register(const std::string& message_name, ServiceFunc f);
  
protected:
  friend class ZRpcService;
  static zproto::ProtoRpcResponsePtr DoServiceCall(zproto::RpcRequestPtr request);
  
  // TODO(@benqi): 使用FuncFactoryManager
  std::map<int, ServiceFunc> g_rpc_services;
};

#endif
