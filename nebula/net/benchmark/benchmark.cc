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

DEFINE_int32(port, 33333, "echo server port");
DEFINE_int32(size, 32000, "size");
DEFINE_int32(threads, 0, "threads");
DEFINE_int32(buffering, 0, "buffering");

typedef Pipeline<IOBufQueue&, std::unique_ptr<folly::IOBuf>> EchoPipeline;

// the main logic of our echo server; receives a string and writes it straight
// back
class EchoHandler : public BytesToBytesHandler {
public:

  void read(Context *ctx, IOBufQueue &msg) override {
    ctx->fireWrite(msg.move());
  }


};

// 设置readBufferSettings_
const uint64_t kDefaultMinAvailable = 16*1024;
const uint64_t kDefaultAllocationSize = 32*1024;



// where we define the chain of handlers for each messeage received
class EchoPipelineFactory : public PipelineFactory<EchoPipeline> {
public:
  EchoPipeline::Ptr newPipeline(
    std::shared_ptr<AsyncTransportWrapper> sock) override {

    auto pipeline = EchoPipeline::create();
    pipeline->setReadBufferSettings(FLAGS_size, FLAGS_size);
    pipeline->addBack(AsyncSocketHandler(sock));
    // pipeline->addBack(LineBasedFrameDecoder());
    // pipeline->addBack(StringCodec());
    pipeline->addBack(EchoHandler());
    if (FLAGS_buffering != 0) {
      pipeline->addBack(OutputBufferingHandler());
    }
    pipeline->finalize();
    return pipeline;
  }
};

class MyAsyncServerSocketFactory:public AsyncServerSocketFactory{
public:
public:
  std::shared_ptr<folly::AsyncSocketBase> newSocket(
    folly::SocketAddress address, int /*backlog*/, bool reuse,
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

  int io_group_size = FLAGS_threads;
  if (FLAGS_threads <= 0) {
    io_group_size = std::thread::hardware_concurrency();
    if (io_group_size <= 0) {
      // Reasonable mid-point for concurrency when actual value unknown
      io_group_size = 8;
    }
  }

  auto io_group = std::make_shared<IOThreadPoolExecutor>(
    io_group_size, std::make_shared<NamedThreadFactory>("IO Thread"));

  config.acceptBacklog = 65535;
  config.maxNumPendingConnectionsPerWorker = 65535;
  config.enableTCPFastOpen = true;
  config.fastOpenQueueSize = 65535;
  config.acceptBacklog = 65535;
  // folly::AsyncServerSocket::UniquePtr socket(new AsyncServerSocket);
  // socket
  // server.bind(std::move(socket));
  server.channelFactory(std::make_shared<MyAsyncServerSocketFactory>());
  server.acceptorConfig(config);
  server.childPipeline(std::make_shared<EchoPipelineFactory>());
  server.group(io_group);
  server.bind(FLAGS_port);
  server.waitForStop();

  return 0;
}
