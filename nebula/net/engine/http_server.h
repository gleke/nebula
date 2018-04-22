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

#ifndef NEULA_NET_ENGINE_HTTP_SERVER_H_
#define NEULA_NET_ENGINE_HTTP_SERVER_H_

#include "nebula/net/engine/tcp_service_base.h"
#include "nebula/net/http/http_server_lib.h"

namespace nebula {

class HttpServer : public ServiceBase {
public:
  HttpServer(const ServiceConfig& config, const IOThreadPoolExecutorPtr& io_group)
    : ServiceBase(config),
      io_group_(io_group) {}
  
  virtual ~HttpServer() = default;
  
  // Impl from TcpServiceBase
  ServiceModuleType GetModuleType() const override {
    return ServiceModuleType::HTTP_SERVER;
  }
  
  bool Start() override;
  bool Pause() override;
  bool Stop() override;
  
private:
  IOThreadPoolExecutorPtr io_group_;
  std::unique_ptr<proxygen::HTTPServerLib> server_;
};

}


#endif
