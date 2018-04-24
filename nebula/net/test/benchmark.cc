/*
 * Copyright 2017-present Facebook, Inc.
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

#include <gflags/gflags.h>
#include <wangle/bootstrap/ServerBootstrap.h>
#include <wangle/channel/AsyncSocketHandler.h>
#include <wangle/codec/LineBasedFrameDecoder.h>
#include <wangle/codec/StringCodec.h>
#include <wangle/channel/OutputBufferingHandler.h>

using namespace folly;
using namespace wangle;

DEFINE_int32(port, 8080, "echo server port");

typedef Pipeline<IOBufQueue&, std::unique_ptrfolly::IOBuf> EchoPipeline;

// the main logic of our echo server; receives a string and writes it straight
// back
class EchoHandler : public BytesToBytesHandler {
public:

  void read(Context *ctx, IOBufQueue &msg) override {
    ctx->fireWrite(msg.move());
  }
};

// where we define the chain of handlers for each messeage received
class EchoPipelineFactory : public PipelineFactory {
public:
  EchoPipeline::Ptr newPipeline(
    std::shared_ptr sock) override {

    auto pipeline = EchoPipeline::create();
    pipeline->addBack(AsyncSocketHandler(sock));
// pipeline->addBack(LineBasedFrameDecoder());
// pipeline->addBack(StringCodec());
    pipeline->addBack(EchoHandler());
// pipeline->addBack(OutputBufferingHandler());
    pipeline->finalize();
    return pipeline;
  }
};

class MyAsyncServerSocketFactory:public AsyncServerSocketFactory{
public:
public:
  std::shared_ptrfolly::AsyncSocketBase newSocket(
    folly::SocketAddress address, int /backlog/, bool reuse,
  const ServerSocketConfig& config) override {

    auto* evb = folly::EventBaseManager::get()->getEventBase();
    std::shared_ptr<folly::AsyncServerSocket> socket(
      new folly::AsyncServerSocket(evb),
      ThreadSafeDestructor());
    socket->setMaxNumMessagesInQueue(
      config.maxNumPendingConnectionsPerWorker);
    socket->setReusePortEnabled(reuse);
    if (config.enableTCPFastOpen) {
      socket->setTFOEnabled(true, config.fastOpenQueueSize);
    }
    socket->setZeroCopy(true);
    socket->setKeepAliveEnabled(true);
    socket->setMaxAcceptAtOnce(65535);
    socket->bind(address);

    socket->listen(config.acceptBacklog);
    socket->startAccepting();

    return socket;
  }
};

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  ServerBootstrap<EchoPipeline> server;
  ServerSocketConfig config;

  config.acceptBacklog = 65535;
  config.maxNumPendingConnectionsPerWorker = 65535;
  config.enableTCPFastOpen = true;
  config.fastOpenQueueSize = 65535;
  config.acceptBacklog = 65535;

  server.channelFactory(std::make_shared<MyAsyncServerSocketFactory>());
  server.acceptorConfig(config);
  server.childPipeline(std::make_shared<EchoPipelineFactory>());
  server.bind(FLAGS_port);
  server.waitForStop();

  return 0;
}
