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

#ifndef NEBULA_NET_RPC_ZRPC_CLIENT_HANDLER_H_
#define NEBULA_NET_RPC_ZRPC_CLIENT_HANDLER_H_

#include "nebula/net/handler/nebula_base_handler.h"
#include "nebula/net/rpc/zrpc_client_dispatcher.h"

#include <wangle/service/ExpiringFilter.h>

// A real rpc server would probably use generated client/server stubs
class ZRpcClientHandler : public nebula::NebulaBaseHandler, public wangle::Handler<
  zproto::PackageMessagePtr, zproto::ProtoRpcResponsePtr,
  zproto::RpcRequestPtr, std::unique_ptr<folly::IOBuf>> {
public:
  explicit ZRpcClientHandler(nebula::ServiceBase* service)
    : NebulaBaseHandler(service) {}

  virtual void read(Context* ctx, zproto::PackageMessagePtr msg) override;

  virtual folly::Future<folly::Unit> write(Context* ctx, zproto::RpcRequestPtr req) override;
  
  virtual void readEOF(Context* ctx) override;
  virtual void readException(Context* ctx, folly::exception_wrapper e) override;
  
  virtual void transportActive(Context* ctx) override;
  virtual void transportInactive(Context* ctx) override;

  // virtual folly::Future<folly::Unit> close(Context* ctx) override;

  folly::Future<zproto::ProtoRpcResponsePtr> ServiceCall(zproto::RpcRequestPtr arg);

protected:
  // TODO(@benqi): s2s应用场景里，连接发起方需要保活，逻辑基本一样，
  //  后续zrpc_client_handler/zproto_handler等统一处理
  //  更智能的保活策略
  static void DoHeartBeat(uint64_t conn_id, uint32_t timeout);

  // std::shared_ptr<ZRpcMultiplexClientDispatcher> dispatcher_;
  std::shared_ptr<ZRpcClientFilter> rpc_service_;
};

#endif
