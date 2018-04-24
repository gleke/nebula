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

#include "nebula/net/handler/http/http_request_handler.h"

#include <proxygen/httpserver/ResponseBuilder.h>

#include "nebula/net/engine/http_server.h"

using namespace nebula;

// 通过headers.getPath()分发

///////////////////////////////////////////////////////////////////////////////////////
// 不能直接使用静态类注册的原因:
// 不在一个.a文件里静态变量不可视
// 通过ModuleEchoInitialize显式调用
void ModuleHttpInitialize() {
  static ServiceSelfRegisterTemplate g_reg_http_server(std::make_pair("http_server", "http"),
         [](const ServiceConfig& service_config,
            const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
           auto service = std::make_shared<HttpServer>(service_config, io_group);
           return service;
         });
}

HttpRequestHandler::~HttpRequestHandler() {
  LOG(INFO) << "HttpRequestHandler Destroy...";
}

void HttpRequestHandler::onEOM() noexcept {
  try {
    proxygen::ResponseBuilder r(downstream_);
    r.status(200, "OK");
    OnHttpHandler(*request_, &requestBody_, &r);
    r.sendWithEOM();
  } catch (const std::exception& ex) {
    proxygen::ResponseBuilder(downstream_)
    .status(500, "Internal Server Error")
    .body(ex.what())
    .sendWithEOM();
  } catch (...) {
    proxygen::ResponseBuilder(downstream_)
    .status(500, "Internal Server Error")
    .body("Unknown exception thrown")
    .sendWithEOM();
  }
}

void HttpRequestHandler::requestComplete() noexcept {
  LOG(INFO) << "NebulaHttpRequestHandler, requestComplete!";
  delete this;
  // self.reset();
}

void HttpRequestHandler::onError(proxygen::ProxygenError err) noexcept {
  LOG(ERROR) << "NebulaHttpRequestHandler, onError : " << err;
  delete this;
  // self.reset();
}

void HttpRequestHandler::OnHttpHandler(const proxygen::HTTPMessage& headers,
                                       folly::IOBufQueue* body,
                                       proxygen::ResponseBuilder* r) {
  ExecHttpHandlerFactory::Execute(headers.getPath(), headers, body, r);
}
