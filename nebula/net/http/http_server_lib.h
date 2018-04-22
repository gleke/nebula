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
 *  原始出处: https://github.com/facebook/proxygen/blob/master/proxygen/httpserver/HTTPServer.h
 */

#ifndef NEBULA_NET_HTTP_HTTP_SERVER_LIB_H_
#define NEBULA_NET_HTTP_HTTP_SERVER_LIB_H_

#pragma once

#include <wangle/ssl/SSLContextConfig.h>
#include <folly/io/async/AsyncServerSocket.h>
#include <folly/io/async/EventBase.h>
#include <folly/io/async/AsyncSignalHandler.h>

#include <wangle/bootstrap/ServerBootstrap.h>
#include <proxygen/httpserver/HTTPServerOptions.h>
#include <proxygen/lib/http/codec/HTTPCodecFactory.h>
#include <proxygen/lib/http/session/HTTPSession.h>
#include <thread>

namespace proxygen {

class HTTPServerLib;
class HTTPServerAcceptorLib;

// https://raw.githubusercontent.com/facebook/proxygen/master/proxygen/httpserver/SignalHandler.h
/**
 * Installs signal handler which will stop HTTPServer when the user presses
 * Ctrl-C. To be used if HTTPServer is the main process.
 *
 * Note: Should only be created from the thread invoking `HTTPServer::start()`.
 */
class LibSignalHandler: private folly::AsyncSignalHandler {
public:
  explicit LibSignalHandler(HTTPServerLib* server);
  
  void install(const std::vector<int>& signals);
private:
  // AsyncSignalHandler
  void signalReceived(int signum) noexcept override;
  
  HTTPServerLib* const server_{nullptr};
};

  
/**
 * HTTPServer based on proxygen http libraries
 */
class HTTPServerLib final {
 public:
  /**
   * For each IP you can specify HTTP protocol to use.  You can use plain old
   * HTTP/1.1 protocol or SPDY/3.1 for now.
   */
  enum class Protocol: uint8_t {
    HTTP,
    SPDY,
    HTTP2,
  };

  struct IPConfig {
    IPConfig(folly::SocketAddress a,
             Protocol p,
             std::shared_ptr<HTTPCodecFactory> c = nullptr)
        : address(a),
          protocol(p),
          codecFactory(c) {}

    folly::SocketAddress address;
    Protocol protocol;
    std::shared_ptr<HTTPCodecFactory> codecFactory;
    std::vector<wangle::SSLContextConfig> sslConfigs;

    /*
     * Sets the initial ticket seeds to use when starting the HTTPServer.
     * Ticket seeds are used to generate the session ticket encryption keys
     * for ticket resumption. When using session tickets, it is important
     * to change them and keep them updated, see updateTicketSeeds to keep
     * seeds up to date.
     */
    folly::Optional<wangle::TLSTicketKeySeeds> ticketSeeds;

    /*
     * Whether to allow an insecure connection on a secure port.
     * This should be used in very few cases where a HTTP server needs to
     * support insecure and secure connections.
     */
    bool allowInsecureConnectionsOnSecureServer{false};
    bool enableTCPFastOpen{false};
    /**
     * Maximum queue size of pending fast open connections.
     */
    uint32_t fastOpenQueueSize{10000};
  };

  /**
   * Create a new HTTPServer
   */
  explicit HTTPServerLib(HTTPServerOptions options);
  ~HTTPServerLib();

  /**
   * Bind server to the following addresses. Can be called from any thread.
   *
   * Throws exception on error (say port is already busy). You can try binding
   * to different set of ports. Though once it succeeds, it is a FATAL to call
   * it again.
   *
   * The list is updated in-place to contain final port server bound to if
   * ephemeral port was given. If the call fails, the list might be partially
   * updated.
   */
  void bind(std::vector<IPConfig>& addrs);

  /**
   * Start HTTPServer.
   *
   * Note this is a blocking call and the current thread will be used to listen
   * for incoming connections. Throws exception if something goes wrong (say
   * somebody else is already listening on that socket).
   *
   * `onSuccess` callback will be invoked from the event loop which shows that
   * all the setup was successfully done.
   *
   * `onError` callback will be invoked if some errors occurs while starting the
   * server instead of throwing exception.
   */
  void start(std::function<void()> onSuccess = nullptr,
             std::function<void(std::exception_ptr)> onError = nullptr);

  // Add by @benqi: 可指定IOThreadPoolExecutor启动
  void start(std::shared_ptr<wangle::IOThreadPoolExecutor> ioGroup, std::function<void()> onSuccess = nullptr,
             std::function<void(std::exception_ptr)> onError = nullptr);

  /**
   * Stop listening on bound ports. (Stop accepting new work).
   * It does not wait for pending work to complete.
   * You must still invoke stop() before destroying the server.
   * You do NOT need to invoke this before calling stop().
   * This can be called from any thread, and it is idempotent.
   * The only restriction is it should be called after start() has completed.
   */
  void stopListening();

  /**
   * Stop HTTPServer.
   *
   * Can be called from any thread. Server will stop listening for new
   * connections and will wait for running requests to finish.
   *
   * TODO: Separate method to do hard shutdown?
   */
  void stop();

  /**
   * Get the list of addresses server is listening on. Empty if sockets are not
   * bound yet.
   */
  std::vector<IPConfig> addresses() const {
    return addresses_;
  }

  /**
   * Get the sockets the server is currently bound to.
   */
  const std::vector<const folly::AsyncSocketBase*> getSockets() const;

  void setSessionInfoCallback(HTTPSession::InfoCallback* cb) {
    sessionInfoCb_ = cb;
  }

  /**
   * Returns a file descriptor associated with the listening socket
   */
  int getListenSocket() const;

  /**
   * Updates ticket seeds for the HTTPServer for all the VIPs.
   */
  void updateTicketSeeds(wangle::TLSTicketKeySeeds seeds);

 private:
  std::shared_ptr<HTTPServerOptions> options_;

  /**
   * Event base in which we binded server sockets.
   */
  // folly::EventBase* mainEventBase_{nullptr};

  /**
   * Optional signal handlers on which we should shutdown server
   */
  // Edit by @benqi: 使用 LibSignalHandler
  // std::unique_ptr<LibSignalHandler> signalHandler_;

  /**
   * Addresses we are listening on
   */
  std::vector<IPConfig> addresses_;
  std::vector<wangle::ServerBootstrap<wangle::DefaultPipeline>> bootstrap_;

  /**
   * Callback for session create/destruction
   */
  HTTPSession::InfoCallback* sessionInfoCb_{nullptr};
};

}

#endif

