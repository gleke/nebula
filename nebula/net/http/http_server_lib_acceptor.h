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

#ifndef NEBULA_NET_HTTP_HTTP_SERVER_LIB_ACCEPTOR_H_
#define NEBULA_NET_HTTP_HTTP_SERVER_LIB_ACCEPTOR_H_

#pragma once

#include "nebula/net/http/http_server_lib.h"

#include <proxygen/httpserver/HTTPServerOptions.h>
#include <proxygen/lib/http/session/HTTPSessionAcceptor.h>

namespace proxygen {

class HTTPServerLibAcceptor final : public HTTPSessionAcceptor {
 public:
  static AcceptorConfiguration makeConfig(
    const HTTPServerLib::IPConfig& ipConfig,
    const HTTPServerOptions& opts);

  static std::unique_ptr<HTTPServerLibAcceptor> make(
    const AcceptorConfiguration& conf,
    const HTTPServerOptions& opts,
    const std::shared_ptr<HTTPCodecFactory>& codecFactory = nullptr);

  /**
   * Invokes the given method when all the connections are drained
   */
  void setCompletionCallback(std::function<void()> f);

  ~HTTPServerLibAcceptor() override;

 private:
  HTTPServerLibAcceptor(const AcceptorConfiguration& conf,
                     const std::shared_ptr<HTTPCodecFactory>& codecFactory,
                     std::vector<RequestHandlerFactory*> handlerFactories);

  // HTTPSessionAcceptor
  HTTPTransaction::Handler* newHandler(HTTPTransaction& txn,
                                       HTTPMessage* msg) noexcept override;
  void onConnectionsDrained() override;

  std::function<void()> completionCallback_;
  const std::vector<RequestHandlerFactory*> handlerFactories_{nullptr};
};

}

#endif // NEBULA_NET_HTTP_HTTP_SERVER_LIB_ACCEPTOR_H_

