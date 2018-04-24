/*
 *  Copyright (c) 2018, https://github.com/nebula-im/nebula
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

#include "wangle/bootstrap/ServerBootstrap.h"
#include "wangle/bootstrap/ClientBootstrap.h"
#include "wangle/channel/Handler.h"

#include <glog/logging.h>
#include <boost/thread.hpp>
#include <folly/String.h>

using namespace wangle;
using namespace folly;

typedef Pipeline<IOBufQueue&, std::unique_ptr<IOBuf>> BytesPipeline;

typedef ServerBootstrap<BytesPipeline> TestServer;

std::atomic<int> connections{0};

class TestPipelineFactory : public PipelineFactory<BytesPipeline> {
public:
  BytesPipeline::Ptr newPipeline(
    std::shared_ptr<AsyncTransportWrapper>) override {
    pipelines++;
    auto pipeline = BytesPipeline::create();
    pipeline->addBack(new BytesToBytesHandler());
    pipeline->finalize();
    return pipeline;
  }
  std::atomic<int> pipelines{0};
};

template <typename HandlerPipeline>
class TestHandlerPipelineFactory : public AcceptPipelineFactory {
public:
  AcceptPipeline::Ptr newPipeline(Acceptor*) override {
    LOG(INFO) << "newPipeline.";
    auto pipeline = AcceptPipeline::create();
    pipeline->addBack(HandlerPipeline());
    return pipeline;
  }
};

class TestUDPPipeline : public InboundHandler<AcceptPipelineType, Unit> {
public:
  void read(Context*, AcceptPipelineType) override {
    connections++;
    LOG(INFO) << "connections: " << connections;
  }
};


folly::EventBase sevb;

class AsyncUDPServerSocket2Factory : public ServerSocketFactory {
public:
  std::shared_ptr<folly::AsyncSocketBase> newSocket(
    folly::SocketAddress address, int /*backlog*/, bool reuse,
    const ServerSocketConfig& /*config*/) override {

    folly::EventBase* evb = folly::EventBaseManager::get()->getEventBase();
    std::shared_ptr<folly::AsyncUDPServerSocket> socket(
      new folly::AsyncUDPServerSocket(evb),
      ThreadSafeDestructor());
    socket->setReusePort(reuse);
    socket->bind(address);
    socket->listen();

    return socket;
  }

  void removeAcceptCB(std::shared_ptr<folly::AsyncSocketBase> /*s*/,
                      Acceptor* /*callback*/,
                      folly::EventBase* /*base*/) override {
  }

  void addAcceptCB(std::shared_ptr<folly::AsyncSocketBase> s,
                   Acceptor* callback, folly::EventBase* base) override {
    auto socket = std::dynamic_pointer_cast<folly::AsyncUDPServerSocket>(s);
    DCHECK(socket);
    socket->addListener(base, callback);
    // socket->listen();
  }

  class ThreadSafeDestructor {
  public:
    void operator()(folly::AsyncUDPServerSocket* socket) const {
      socket->getEventBase()->runImmediatelyOrRunInEventBaseThreadAndWait(
        [socket]() {
          delete socket;
        }
      );
    }
  };
};

int main(int argc, char* argv[]) {
  google::SetStderrLogging(google::FATAL);
  FLAGS_stderrthreshold = google::INFO;
  // FLAGS_v = 20;
  LOG(INFO) << "12345";

  // folly::EventBase base;
  connections = 0;

  // folly::EventBase sevb;
  // UDPServer server(&sevb, folly::SocketAddress("0.0.0.0", 22345), 4);


  auto io_group = std::make_shared<IOThreadPoolExecutor>(
    1, std::make_shared<NamedThreadFactory>("IO Thread"));

  TestServer server;
  auto serverThread = std::thread([] () {
    LOG(INFO) << "loopForever...";
    sevb.loopForever();

    // sevb.loopForever();
  });

  // Start event loop in a separate thread

  // Wait for event loop to start
  sevb.waitUntilRunning();

  // Start the server
  sevb.runInEventBaseThreadAndWait([&]() {
    auto factory = std::make_shared<TestPipelineFactory>();
    auto pipelinefactory =
      std::make_shared<TestHandlerPipelineFactory<TestUDPPipeline>>();
    server.pipeline(pipelinefactory);
    server.channelFactory(std::make_shared<AsyncUDPServerSocket2Factory>());
    server.group(io_group);
    folly::SocketAddress addr("0.0.0.0", 22345);
    server.bindImpl(addr);

    LOG(INFO) << "22345";
  });

  serverThread.join();

  sevb.runInEventBaseThread([&] () {
    server.stop();
    server.join();
    sevb.terminateLoopSoon();
  });

  // auto base = EventBaseManager::get()->getEventBase();

//  SocketAddress address;
//  // server.getSockets()[0]->getAddress(&address);
//
//  SocketAddress localhost("127.0.0.1", 10000);
//  AsyncUDPSocket client(base);
//  client.bind(localhost);
//  auto data = IOBuf::create(1);
//  data->append(1);
//  *(data->writableData()) = 'a';
//  LOG(INFO) << "write...";
//  // client.write(address, std::move(data));
//  client.write(SocketAddress("127.0.0.1", 22345), std::move(data));
//  auto f = []() {
//    LOG(INFO) << "11";
//
//  };

//  base->runAfterDelay([](){
//    LOG(INFO) << "11";
//  }, 10);
//  base->loopForever();
//  server.stop();
//  server.join();
}

