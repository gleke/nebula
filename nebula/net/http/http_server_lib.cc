/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

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
 *  原始出处: https://github.com/facebook/proxygen/blob/master/proxygen/httpserver/HTTPServer.cpp
 */

#include "nebula/net/http/http_server_lib.h"

#include <folly/ThreadName.h>
#include <folly/io/async/EventBaseManager.h>

#include "nebula/net/http/http_server_lib_acceptor.h"

// #include <proxygen/httpserver/SignalHandler.h>
#include <proxygen/httpserver/filters/RejectConnectFilter.h>
#include <proxygen/httpserver/filters/ZlibServerFilter.h>
#include <wangle/ssl/SSLContextManager.h>

using folly::AsyncServerSocket;
using folly::EventBase;
using folly::EventBaseManager;
using folly::SocketAddress;
using wangle::IOThreadPoolExecutor;
using wangle::ThreadPoolExecutor;

namespace proxygen {

///> https://raw.githubusercontent.com/facebook/proxygen/master/proxygen/httpserver/SignalHandler.cpp
LibSignalHandler::LibSignalHandler(HTTPServerLib* server)
  : folly::AsyncSignalHandler(EventBaseManager::get()->getEventBase()),
    server_(server) {
}

void LibSignalHandler::install(const std::vector<int>& signals) {
  for (const int& signal: signals) {
    registerSignalHandler(signal);
  }
}

void LibSignalHandler::signalReceived(int signum) noexcept {
  server_->stop();
}

class AcceptorLibFactory : public wangle::AcceptorFactory {
 public:
  AcceptorLibFactory(std::shared_ptr<HTTPServerOptions> options,
                  std::shared_ptr<HTTPCodecFactory> codecFactory,
                  AcceptorConfiguration config,
                  HTTPSession::InfoCallback* sessionInfoCb) :
      options_(options),
      codecFactory_(codecFactory),
      config_(config),
      sessionInfoCb_(sessionInfoCb) {}
  std::shared_ptr<wangle::Acceptor> newAcceptor(
      folly::EventBase* eventBase) override {
    auto acc = std::shared_ptr<HTTPServerLibAcceptor>(
      HTTPServerLibAcceptor::make(config_, *options_, codecFactory_).release());
    if (sessionInfoCb_) {
      acc->setSessionInfoCallback(sessionInfoCb_);
    }
    acc->init(nullptr, eventBase);
    return acc;
  }

 private:
  std::shared_ptr<HTTPServerOptions> options_;
  std::shared_ptr<HTTPCodecFactory> codecFactory_;
  AcceptorConfiguration config_;
  HTTPSession::InfoCallback* sessionInfoCb_;
};

HTTPServerLib::HTTPServerLib(HTTPServerOptions options):
    options_(std::make_shared<HTTPServerOptions>(std::move(options))) {

  // Insert a filter to fail all the CONNECT request, if required
  if (!options_->supportsConnect) {
    options_->handlerFactories.insert(
        options_->handlerFactories.begin(),
        folly::make_unique<RejectConnectFilterFactory>());
  }

  // Add Content Compression filter (gzip), if needed. Should be
  // final filter
  if (options_->enableContentCompression) {
    options_->handlerFactories.insert(
        options_->handlerFactories.begin(),
        folly::make_unique<ZlibServerFilterFactory>(
          options_->contentCompressionLevel,
          options_->contentCompressionMinimumSize,
          options_->contentCompressionTypes));
  }
}

HTTPServerLib::~HTTPServerLib() {
  // CHECK(!mainEventBase_) << "Forgot to stop() server?";
}

void HTTPServerLib::bind(std::vector<IPConfig>& addrs) {
  addresses_ = addrs;
}

class LibHandlerCallbacks : public ThreadPoolExecutor::Observer {
 public:
  explicit LibHandlerCallbacks(std::shared_ptr<HTTPServerOptions> options) : options_(options) {}

  void threadStarted(ThreadPoolExecutor::ThreadHandle* h) override {
    auto evb = IOThreadPoolExecutor::getEventBase(h);
    evb->runInEventBaseThread([=](){
      for (auto& factory: options_->handlerFactories) {
        factory->onServerStart(evb);
      }
    });
  }
  void threadStopped(ThreadPoolExecutor::ThreadHandle* h) override {
    IOThreadPoolExecutor::getEventBase(h)->runInEventBaseThread([&](){
      for (auto& factory: options_->handlerFactories) {
        factory->onServerStop();
      }
    });
  }

 private:
  std::shared_ptr<HTTPServerOptions> options_;
};

void HTTPServerLib::start(std::function<void()> onSuccess,
                       std::function<void(std::exception_ptr)> onError) {
  // Edit by @benqi
  auto exe = std::make_shared<IOThreadPoolExecutor>(options_->threads);
  start(exe, onSuccess, onError);
}

// Add by @benqi: 可指定IOThreadPoolExecutor启动
void HTTPServerLib::start(std::shared_ptr<wangle::IOThreadPoolExecutor> ioGroup, std::function<void()> onSuccess,
                          std::function<void(std::exception_ptr)> onError) {
  // mainEventBase_ = EventBaseManager::get()->getEventBase();
  
  auto accExe = std::make_shared<IOThreadPoolExecutor>(1);
  auto exe = ioGroup;
  // auto exe = std::make_shared<IOThreadPoolExecutor>(options_->threads);
  auto exeObserver = std::make_shared<LibHandlerCallbacks>(options_);
  // Observer has to be set before bind(), so onServerStart() callbacks run
  exe->addObserver(exeObserver);
  
  try {
    FOR_EACH_RANGE (i, 0, addresses_.size()) {
      auto codecFactory = addresses_[i].codecFactory;
      auto accConfig = HTTPServerLibAcceptor::makeConfig(addresses_[i], *options_);
      auto factory = std::make_shared<AcceptorLibFactory>(
                                                       options_,
                                                       codecFactory,
                                                       accConfig,
                                                       sessionInfoCb_);
      bootstrap_.push_back(
                           wangle::ServerBootstrap<wangle::DefaultPipeline>());
      bootstrap_[i].childHandler(factory);
      if (accConfig.enableTCPFastOpen) {
        // We need to do this because wangle's bootstrap has 2 acceptor configs
        // and the socketConfig gets passed to the SocketFactory. The number of
        // configs should really be one, and when that happens, we can remove
        // this code path.
        bootstrap_[i].socketConfig.enableTCPFastOpen = true;
        bootstrap_[i].socketConfig.fastOpenQueueSize =
        accConfig.fastOpenQueueSize;
      }
      bootstrap_[i].group(accExe, exe);
      bootstrap_[i].bind(addresses_[i].address);
    }
  } catch (const std::exception& ex) {
    stop();
    
    if (onError) {
      onError(std::current_exception());
      return;
    }
    
    throw;
  }
  
  // Install signal handler if required
  if (!options_->shutdownOn.empty()) {
    // signalHandler_ = folly::make_unique<LibSignalHandler>(this);
    // signalHandler_->install(options_->shutdownOn);
  }
  
  // Start the main event loop
  if (onSuccess) {
    onSuccess();
  }
  // mainEventBase_->loopForever();
}

void HTTPServerLib::stopListening() {
  // CHECK(mainEventBase_);
  for (auto& bootstrap : bootstrap_) {
    bootstrap.stop();
  }
}

void HTTPServerLib::stop() {
  stopListening();

  for (auto& bootstrap : bootstrap_) {
    bootstrap.join();
  }

  // signalHandler_.reset();
  // mainEventBase_->terminateLoopSoon();
  // mainEventBase_ = nullptr;
}

const std::vector<const folly::AsyncSocketBase*>
  HTTPServerLib::getSockets() const {

  std::vector<const folly::AsyncSocketBase*> sockets;
  FOR_EACH_RANGE(i, 0, bootstrap_.size()) {
    auto& bootstrapSockets = bootstrap_[i].getSockets();
    FOR_EACH_RANGE(j, 0, bootstrapSockets.size()) {
      sockets.push_back(bootstrapSockets[j].get());
    }
  }

  return sockets;
}

int HTTPServerLib::getListenSocket() const {
  if (bootstrap_.size() == 0) {
    return -1;
  }

  auto& bootstrapSockets = bootstrap_[0].getSockets();
  if (bootstrapSockets.size() == 0) {
    return -1;
  }

  auto serverSocket =
      std::dynamic_pointer_cast<folly::AsyncServerSocket>(bootstrapSockets[0]);
  auto socketFds = serverSocket->getSockets();
  if (socketFds.size() == 0) {
    return -1;
  }

  return socketFds[0];
}

void HTTPServerLib::updateTicketSeeds(wangle::TLSTicketKeySeeds seeds) {
  for (auto& bootstrap : bootstrap_) {
    bootstrap.forEachWorker([&](wangle::Acceptor* acceptor) {
      if (!acceptor) {
        return;
      }
      auto evb = acceptor->getEventBase();
      if (!evb) {
        return;
      }
      evb->runInEventBaseThread([acceptor, seeds] {
        auto ctxMgr = acceptor->getSSLContextManager();
        if (!ctxMgr) {
          return;
        }
        ctxMgr->reloadTLSTicketKeys(
            seeds.oldSeeds, seeds.currentSeeds, seeds.newSeeds);
      });
    });
  }
}

}
