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

#include "nebula/net/engine/http_server.h"

#include "nebula/net/handler/http/http_request_handler.h"

#define HTTP_IDLE_TIMEOUT 60000

namespace nebula {

//////////////////////////////////////////////////////////////////////////////
bool HttpServer::Start() {
  std::vector<proxygen::HTTPServerLib::IPConfig> IPs = {
      {folly::SocketAddress(config_.hosts.c_str(), static_cast<uint16_t>(config_.port), true), proxygen::HTTPServerLib::Protocol::HTTP},
  };

  // TODO(@benqi): https支持
  //  wangle::SSLContextConfig sslCfg;
  //  sslCfg.isDefault = true;
  //  sslCfg.setCertificate("./certs/test_cert1.pem",
  //                        "./certs/test_key1.pem",
  //                        "");
  //  IPs[0].sslConfigs.push_back(sslCfg);
  
  proxygen::HTTPServerOptions options;
  // options.threads = static_cast<size_t>(FLAGS_threads);
  options.idleTimeout = std::chrono::milliseconds(HTTP_IDLE_TIMEOUT);
  // options.shutdownOn = {SIGINT, SIGTERM};
  // options.enableContentCompression = true;
  
  options.handlerFactories = proxygen::RequestHandlerChain()
      .addThen<HttpRequestHandlerFactory>()
      .build();
  
  if (!server_) {
      server_ = folly::make_unique<proxygen::HTTPServerLib>(std::move(options));
  }
  
  server_->bind(IPs);
  server_->start(io_group_);
  
  return true;
}

bool HttpServer::Pause() {
  return true;
}

bool HttpServer::Stop() {
  LOG(INFO) << "HttpServer - Stop service: " << config_.ToString();

  server_->stop();
  return true;
}

}
