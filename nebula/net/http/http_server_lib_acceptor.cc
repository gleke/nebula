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
 *  原始出处: https://github.com/facebook/proxygen/blob/master/proxygen/httpserver/HTTPServerAcceptor.cpp
 */

#include "nebula/net/http/http_server_lib_acceptor.h"

#include <proxygen/httpserver/RequestHandlerAdaptor.h>
#include <proxygen/httpserver/RequestHandlerFactory.h>
#include <proxygen/lib/http/codec/HTTP1xCodec.h>
#include <proxygen/lib/http/codec/HTTP2Constants.h>
#include <proxygen/lib/http/session/HTTPDownstreamSession.h>

using folly::SocketAddress;

namespace proxygen {

AcceptorConfiguration HTTPServerLibAcceptor::makeConfig(
    const HTTPServerLib::IPConfig& ipConfig,
    const HTTPServerOptions& opts) {

  AcceptorConfiguration conf;
  conf.bindAddress = ipConfig.address;
  conf.connectionIdleTimeout = opts.idleTimeout;
  conf.transactionIdleTimeout = opts.idleTimeout;
  conf.initialReceiveWindow = opts.initialReceiveWindow;
  conf.receiveStreamWindowSize = opts.receiveStreamWindowSize;
  conf.receiveSessionWindowSize = opts.receiveSessionWindowSize;
  conf.acceptBacklog = opts.listenBacklog;

  if (ipConfig.protocol == HTTPServerLib::Protocol::SPDY) {
    conf.plaintextProtocol = "spdy/3.1";
  } else if (ipConfig.protocol == HTTPServerLib::Protocol::HTTP2) {
    conf.plaintextProtocol = http2::kProtocolCleartextString;
  }

  conf.sslContextConfigs = ipConfig.sslConfigs;
  conf.allowInsecureConnectionsOnSecureServer =
      ipConfig.allowInsecureConnectionsOnSecureServer;
  conf.enableTCPFastOpen = ipConfig.enableTCPFastOpen;
  conf.fastOpenQueueSize = ipConfig.fastOpenQueueSize;
  if (ipConfig.ticketSeeds) {
    conf.initialTicketSeeds = *ipConfig.ticketSeeds;
  }
  return conf;
}

std::unique_ptr<HTTPServerLibAcceptor> HTTPServerLibAcceptor::make(
  const AcceptorConfiguration& conf,
  const HTTPServerOptions& opts,
  const std::shared_ptr<HTTPCodecFactory>& codecFactory) {
  // Create a copy of the filter chain in reverse order since we need to create
  // Handlers in that order.
  std::vector<RequestHandlerFactory*> handlerFactories;
  for (auto& f: opts.handlerFactories) {
    handlerFactories.push_back(f.get());
  }
  std::reverse(handlerFactories.begin(), handlerFactories.end());

  return std::unique_ptr<HTTPServerLibAcceptor>(
      new HTTPServerLibAcceptor(conf, codecFactory, handlerFactories));
}

HTTPServerLibAcceptor::HTTPServerLibAcceptor(
    const AcceptorConfiguration& conf,
    const std::shared_ptr<HTTPCodecFactory>& codecFactory,
    std::vector<RequestHandlerFactory*> handlerFactories)
    : HTTPSessionAcceptor(conf, codecFactory),
      handlerFactories_(handlerFactories) {}

void HTTPServerLibAcceptor::setCompletionCallback(std::function<void()> f) {
  completionCallback_ = f;
}

HTTPServerLibAcceptor::~HTTPServerLibAcceptor() {
}

HTTPTransactionHandler* HTTPServerLibAcceptor::newHandler(
    HTTPTransaction& txn,
    HTTPMessage* msg) noexcept {

  SocketAddress clientAddr, vipAddr;
  txn.getPeerAddress(clientAddr);
  txn.getLocalAddress(vipAddr);
  msg->setClientAddress(clientAddr);
  msg->setDstAddress(vipAddr);

  // Create filters chain
  RequestHandler* h = nullptr;
  for (auto& factory: handlerFactories_) {
    h = factory->onRequest(h, msg);
  }

  return new RequestHandlerAdaptor(h);
}

void HTTPServerLibAcceptor::onConnectionsDrained() {
  if (completionCallback_) {
    completionCallback_();
  }
}

}
