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

#ifndef NEBULA_NET_HANDLER_HTTP_HTTP_REQUEST_HANDLER_H_
#define NEBULA_NET_HANDLER_HTTP_HTTP_REQUEST_HANDLER_H_

#include <folly/Memory.h>

#include <proxygen/httpserver/RequestHandler.h>
#include <proxygen/httpserver/RequestHandlerFactory.h>
#include <proxygen/httpserver/ResponseBuilder.h>

#include "nebula/base/func_factory_manager.h"

namespace nebula {
  
class HttpRequestHandler : public proxygen::RequestHandler,
	public std::enable_shared_from_this<HttpRequestHandler> {
public:
  HttpRequestHandler()
    : requestBody_(folly::IOBufQueue::cacheChainLength()) {}

  virtual ~HttpRequestHandler();
  
  void onRequest(std::unique_ptr<proxygen::HTTPMessage> headers) noexcept override {
      request_ = std::move(headers);
  }
  
  void onBody(std::unique_ptr<folly::IOBuf> body) noexcept override {
      requestBody_.append(std::move(body));
  }
  
  void onUpgrade(proxygen::UpgradeProtocol proto) noexcept override {}
  
  void onEOM() noexcept override;
  
  virtual void OnHttpHandler(const proxygen::HTTPMessage& headers,
                             folly::IOBufQueue* body,
                             proxygen::ResponseBuilder* r);
  
  void requestComplete() noexcept override;

  void onError(proxygen::ProxygenError err) noexcept override;
  
protected:
  std::unique_ptr<proxygen::HTTPMessage> request_;
  folly::IOBufQueue requestBody_;
  // std::shared_ptr<HttpRequestHandler> self;
};

class HttpRequestHandlerFactory : public proxygen::RequestHandlerFactory {
public:
  HttpRequestHandlerFactory() {}
  
  void onServerStart(folly::EventBase* evb) noexcept override {}
  
  void onServerStop() noexcept override {}
  
  proxygen::RequestHandler* onRequest(proxygen::RequestHandler*, proxygen::HTTPMessage*) noexcept override {
      // TODO(@benqi): 统计HTTP服务接收到HTTP请求的数量

    return new HttpRequestHandler();
  }
};

}

typedef void(*ExecuteHttpHandler)(const proxygen::HTTPMessage&, folly::IOBufQueue*, proxygen::ResponseBuilder*);
typedef nebula::FuncFactoryManager<ExecuteHttpHandler> ExecHttpHandlerFactory;

#define REGISTER_HTTP_HANDLER(K, PATH, HANDLER) \
  static ExecHttpHandlerFactory::RegisterTemplate g_reg_http_handler_##K(PATH, &HANDLER)

#define REGISTER_DEFAULT_HTTP_HANDLER(HANDLER) \
static ExecHttpHandlerFactory::RegisterTemplate g_reg_default_http_handler(&HANDLER)

#endif

