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
 *
 *  基于：https://github.com/facebook/wangle/blob/master/wangle/bootstrap/ClientBootstrap.h
 *  修改目的，移除group_，指定EventBase创建，使得能在指定线程处理网络事件
 *  使得同属于一个分组的连接都在同一个EventBase线程里
 */

#ifndef NEBULA_NET_BASE_CLIENT_BOOTSTRAP2_H_
#define NEBULA_NET_BASE_CLIENT_BOOTSTRAP2_H_

#include <folly/io/async/AsyncSSLSocket.h>
#include <folly/io/async/AsyncSocket.h>
#include <folly/io/async/EventBaseManager.h>
#include <wangle/channel/Pipeline.h>
#include <folly/executors/IOThreadPoolExecutor.h>

namespace wangle {
    
/*
 * A thin wrapper around Pipeline and AsyncSocket to match
 * ServerBootstrap.  On connect() a new pipeline is created.
 */
template <typename Pipeline>
class ClientBootstrap2 {
    
  class ConnectCallback : public folly::AsyncSocket::ConnectCallback {
  public:
    ConnectCallback(folly::Promise<Pipeline*> promise, ClientBootstrap2* bootstrap)
    : promise_(std::move(promise))
    , bootstrap_(bootstrap) {}
    
    void connectSuccess() noexcept override {
      if (bootstrap_->getPipeline()) {
        bootstrap_->getPipeline()->transportActive();
      }
      promise_.setValue(bootstrap_->getPipeline());
      delete this;
    }
    
    void connectErr(const folly::AsyncSocketException& ex) noexcept override {
      promise_.setException(
                            folly::make_exception_wrapper<folly::AsyncSocketException>(ex));
      delete this;
    }
  private:
    folly::Promise<Pipeline*> promise_;
    ClientBootstrap2* bootstrap_;
  };
  
public:
  explicit ClientBootstrap2(folly::EventBase* base = nullptr)
  : base_(base) {
  }
  
  ClientBootstrap2* sslContext(folly::SSLContextPtr sslContext) {
    sslContext_ = sslContext;
    return this;
  }
  
  ClientBootstrap2* sslSession(SSL_SESSION* sslSession) {
    sslSession_ = sslSession;
    return this;
  }
  
  ClientBootstrap2* bind(int port) {
    port_ = port;
    return this;
  }
  
  folly::Future<Pipeline*> connect(
                                   const folly::SocketAddress& address,
                                   std::chrono::milliseconds timeout = std::chrono::milliseconds(0)) {
    DCHECK(pipelineFactory_);
    if (base_ == nullptr) {
      base_ = folly::EventBaseManager::get()->getEventBase();
    }
    folly::Future<Pipeline*> retval((Pipeline*)nullptr);
    base_->runImmediatelyOrRunInEventBaseThreadAndWait([&](){
      std::shared_ptr<folly::AsyncSocket> socket;
      if (sslContext_) {
        auto sslSocket = folly::AsyncSSLSocket::newSocket(sslContext_, base_);
        if (sslSession_) {
          sslSocket->setSSLSession(sslSession_, true);
        }
        socket = sslSocket;
      } else {
        socket = folly::AsyncSocket::newSocket(base_);
      }
      folly::Promise<Pipeline*> promise;
      retval = promise.getFuture();
      socket->connect(
                      new ConnectCallback(std::move(promise), this),
                      address,
                      timeout.count());
      pipeline_ = pipelineFactory_->newPipeline(socket);
    });
    return retval;
  }
  
  ClientBootstrap2* pipelineFactory(
                                    std::shared_ptr<PipelineFactory<Pipeline>> factory) {
    pipelineFactory_ = factory;
    return this;
  }
  
  Pipeline* getPipeline() {
    return pipeline_.get();
  }
  
  folly::EventBase* getEventBase() {
    return base_;
  }
  void setEventBase(folly::EventBase* base) {
    base_ = base;
  }
  
  virtual ~ClientBootstrap2() = default;
  
protected:
  typename Pipeline::Ptr pipeline_;
  
  int port_;
  
  std::shared_ptr<PipelineFactory<Pipeline>> pipelineFactory_;
  folly::EventBase* base_{nullptr};
  
  folly::SSLContextPtr sslContext_;
  SSL_SESSION* sslSession_{nullptr};
};

} // namespace wangle

#endif
