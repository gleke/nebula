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

#ifndef NEBULA_NET_ENGINE_TCP_CLIENT_H_
#define NEBULA_NET_ENGINE_TCP_CLIENT_H_

#include <folly/MoveWrapper.h>

#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/engine/tcp_service_base.h"
#include "nebula/net/base/client_bootstrap2.h"

// #include "nebula/net/zproto/zproto_pipeline_factory.h"

namespace nebula {

#define RECONNECT_TIMEOUT 10000 // 重连间隔时间：10s
  
// TODO(@benqi)
// 一旦分配到一个线程，即使断开重连，也落在这个线程里
template <typename Pipeline = DefaultPipeline>
class TcpClient : public TcpServiceBase, public wangle::PipelineManager {
public:
  TcpClient(const ServiceConfig& config, const IOThreadPoolExecutorPtr& io_group)
    : TcpServiceBase(config, io_group),
      client_(std::make_shared<wangle::ClientBootstrap2<Pipeline>>(io_group ? io_group->getEventBase() : nullptr)),
      conn_address_(config.hosts.c_str(), static_cast<uint16_t>(config.port)) {
  }
  
  virtual ~TcpClient() {
    // LOG(INFO) << "~TcpClient()";
    if (client_ && client_->getPipeline()) {
      client_->getPipeline()->setPipelineManager(nullptr);
    }
  }
  
  // 设置所属分组
  void set_group_event_callback(TcpConnEventCallback* cb) {
    group_event_callback_ = cb;
  }

  // Impl from TcpConnEventCallback
  // 内网经常断线的可能性不大，故让tcp_client_group维护一个已经连接列表
  uint64_t OnNewConnection(wangle::PipelineBase* pipeline) override {
    CHECK(group_event_callback_);
    return group_event_callback_->OnNewConnection(pipeline);
  }
  
  // EventBase线程里执行
  bool OnConnectionClosed(uint64_t conn_id) override {
    CHECK(group_event_callback_);
    return group_event_callback_->OnConnectionClosed(conn_id);
  }

  folly::EventBase* GetEventBase() {
    // CHECK(client_);
    return client_ ? client_->getEventBase() : nullptr;
  }
  
  // Impl from TcpServiceBase
  virtual ServiceModuleType GetModuleType() const override {
    return ServiceModuleType::TCP_CLIENT;
  }
  
  void SetChildPipeline(std::shared_ptr<wangle::PipelineFactory<Pipeline>> factory) {
    factory_ = factory;
  }
  
  bool Start() override {
    // TODO(@benqi)
    //  检查factory_,conns_,config_等
    CHECK(client_);

    client_->pipelineFactory(factory_);
    auto main_eb = client_->getEventBase();
    main_eb->runImmediatelyOrRunInEventBaseThreadAndWait([this]() {
      DoConnect();
    });
    return true;
  }
  
  bool Pause() override {
    // TODO(@benqi):
    
    CHECK(client_);
    return true;
  }
  
  bool Stop() override {
    LOG(INFO) << "TcpClient - Stop service: " << GetServiceConfig().ToString();
    
    auto main_eb = GetEventBase(); // client_->getEventBase();
    if (main_eb) {
      main_eb->runImmediatelyOrRunInEventBaseThreadAndWait([&]() {
        stoped_ = true;
        if (connected_.load()) {
          client_->getPipeline()->close();
        }
        client_.reset();
      });
    }
    
    return true;
  }
  
  // PipelineManager implementation
  void deletePipeline(wangle::PipelineBase* pipeline) override {
    connected_.store(false);
    CHECK(client_);
    // CHECK(client_->getPipeline() == pipeline);
    if (!stoped_) {
      auto main_eb = client_->getEventBase();
      CHECK(main_eb);
      // folly::EventBase* main_eb = folly::EventBaseManager::get()->getEventBase();
      main_eb->runAfterDelay([&] {
        this->DoConnect();
        // this->Start();
      }, RECONNECT_TIMEOUT);
    }
  }
  
  void refreshTimeout() override {
    // TODO(@benqi):
    CHECK(client_);
  }
  
  bool connected() {
    return connected_.load();
  }
  
protected:
  // TODO(@benqi): 支持更多的重连策略，比如指数级重试
  void DoConnect(int timeout = 0) {
    client_->connect(conn_address_, std::chrono::milliseconds(timeout))
    .then([this](Pipeline* pipeline) {
      LOG(INFO) << "TcpClient - Connect sucess: " << config_.ToString();
      pipeline->setPipelineManager(this);
      this->connected_.store(true);
    })
    .onError([this, timeout](const std::exception& ex) {
      // LOG(ERROR) << "TcpClient - Error connecting to : "
      //     << config_.ToString()
      //    << ", exception: " << folly::exceptionStr(ex);
      
      // folly::EventBaseManager::get()->getEventBase();
      auto main_eb = client_->getEventBase();
      main_eb->runAfterDelay([&] {
        DoConnect(timeout);
      }, RECONNECT_TIMEOUT);
    });
  }
  
  std::shared_ptr<wangle::PipelineFactory<Pipeline>> factory_;
  std::shared_ptr<wangle::ClientBootstrap2<Pipeline>> client_;
  std::atomic<bool> connected_ {false};
  bool stoped_ {false};
  
  // 所属分组
  folly::SocketAddress conn_address_;
  
  TcpConnEventCallback* group_event_callback_ {nullptr};
};

}

#endif

