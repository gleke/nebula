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

#ifndef NEBULA_NET_RPC_ZRPC_CLIENT_DISPATCHER_H_
#define NEBULA_NET_RPC_ZRPC_CLIENT_DISPATCHER_H_

#include <wangle/service/ClientDispatcher.h>
#include <wangle/channel/Handler.h>

#include "nebula/net/zproto/zproto_package_data.h"

// #include "nebula/net/rpc/zrpc_client_handler.h"

using ZRpcClientPipeline = wangle::Pipeline<folly::IOBufQueue&, zproto::RpcRequestPtr>;

// Client multiplex dispatcher.  Uses Bonk.type as request ID
class ZRpcMultiplexClientDispatcher : public wangle::ClientDispatcherBase<
    ZRpcClientPipeline, zproto::RpcRequestPtr, zproto::ProtoRpcResponsePtr> {
public:
  ~ZRpcMultiplexClientDispatcher() {
    Clear();
    
    // TODO(@benqi): ClientDispatcherBase析构
    // wangle::ClientDispatcherBase<
    // ZRpcClientPipeline, RpcRequestPtr, ProtoRpcResponsePtr>::~ClientDispatcherBase();
  }
      
  void read(Context* ctx, zproto::ProtoRpcResponsePtr in) override;

  folly::Future<zproto::ProtoRpcResponsePtr> operator()(zproto::RpcRequestPtr arg) override;

  // Print some nice messages for close
  virtual folly::Future<folly::Unit> close() override;
  virtual folly::Future<folly::Unit> close(Context* ctx) override;
      
  void Clear();
  
private:
  std::unordered_map<int64_t, folly::Promise<zproto::ProtoRpcResponsePtr>> requests_;
};

// template <typename Req, typename Resp = Req>
class ZRpcClientFilter : public wangle::ServiceFilter<zproto::RpcRequestPtr, zproto::ProtoRpcResponsePtr> {
public:
  explicit ZRpcClientFilter(std::shared_ptr<wangle::Service<zproto::RpcRequestPtr, zproto::ProtoRpcResponsePtr>> service)
    : ServiceFilter<zproto::RpcRequestPtr, zproto::ProtoRpcResponsePtr>(service) {}
  
  ~ZRpcClientFilter() {
  }
  
//  void Clear() {
//    service_->Clear();
//  }
  
  virtual folly::Future<zproto::ProtoRpcResponsePtr> operator()(zproto::RpcRequestPtr req) override;
};

#endif
