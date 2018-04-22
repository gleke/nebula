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

#include "nebula/net/rpc/zrpc_client_dispatcher.h"

#include "nebula/base/id_util.h"

using namespace zproto;

void ZRpcMultiplexClientDispatcher::read(Context* ctx, ProtoRpcResponsePtr in) {
  LOG(INFO) << "read - " << in->ToString();
  
  auto it = requests_.find(in->req_message_id);
  // CHECK(search != requests_.end());

  if (it == requests_.end()) {
    LOG(ERROR) << "read - not find req's req_message_id: " << in->req_message_id;
  } else {
    auto p = std::move(it->second);
    requests_.erase(in->req_message_id);
    p.setValue(in);
  }
}

folly::Future<ProtoRpcResponsePtr> ZRpcMultiplexClientDispatcher::operator()(RpcRequestPtr arg) {
  auto& p = requests_[arg->message_id()];
  auto f = p.getFuture();
  p.setInterruptHandler([arg, this, &p](const folly::exception_wrapper& e) {
    // 超时
    LOG(INFO) << "setInterruptHandler: " << folly::exceptionStr(e);
    auto rpc_error = std::make_shared<RpcInternalError>(arg->message_id());
    // rpc_error->set_req_message_id(arg->message_id());
    p.setValue(rpc_error);
    this->requests_.erase(arg->message_id());
  });

  this->pipeline_->write(arg);
  return f;
}

// Print some nice messages for close

folly::Future<folly::Unit> ZRpcMultiplexClientDispatcher::close() {
  LOG(INFO) << "close - Channel closed";
  return ClientDispatcherBase::close();
}

folly::Future<folly::Unit> ZRpcMultiplexClientDispatcher::close(Context* ctx) {
  LOG(INFO) << "close - Channel closed";
  return ClientDispatcherBase::close(ctx);
}

// 网络断开等
void ZRpcMultiplexClientDispatcher::Clear() {
  auto rpc_error = std::make_shared<RpcInternalError>(0);
  for (auto it=requests_.begin(); it!=requests_.end(); ++it) {
    it->second.setValue(rpc_error);
  }
  
  requests_.clear();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
folly::Future<ProtoRpcResponsePtr> ZRpcClientFilter::operator()(RpcRequestPtr req) {
  // TODO(@benqi): 共享包
  if (req->message_id()==0) {
    req->set_message_id(GetNextIDBySnowflake());
  }
  return (*this->service_)(std::move(req));
//  auto p = std::make_shared<folly::Promise<ProtoRpcResponsePtr>>();// p;
//  auto f = p->getFuture();
//  (*this->service_)(req)
//  .then([p](ProtoRpcResponsePtr rsp) {
//    LOG(INFO) << "ZRpcClientFilter - then";
//    p->setValue(rsp);
//    return rsp;
//  })
//  .onTimeout(std::chrono::milliseconds(5000), [p]() {
//    LOG(INFO) << "ZRpcClientFilter - onTimeout!!";
//    ProtoRpcResponsePtr rsp;
//    p->setValue(rsp);
//    return folly::makeFuture(rsp);
//  });
//  return f;
}

