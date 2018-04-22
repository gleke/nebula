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

#ifndef NEBULA_NET_RPC_ZRPC_SERVICE_H_
#define NEBULA_NET_RPC_ZRPC_SERVICE_H_

#include <wangle/channel/Handler.h>
#include <wangle/service/Service.h>

#include "nebula/base/func_factory_manager.h"
#include "nebula/net/zproto/zproto_package_data.h"

class ZRpcService : public wangle::Service<zproto::RpcRequestPtr, zproto::ProtoRpcResponsePtr> {
public:
  virtual folly::Future<zproto::ProtoRpcResponsePtr> operator()(zproto::RpcRequestPtr request) override;
};

/*
typedef ProtoRpcResponsePtr(*ZRpcServiceFunc(ProtoRpcResponsePtr);
typedef nebula::FuncFactoryManager<RpcServiceFunc> ZRpcServiceFactory;

#define REGISTER_HTTP_HANDLER(K, F) \
static ZRpcServiceFactory::RegisterTemplate g_reg_zrpc_func_##K(K, &F)
*/

#endif
