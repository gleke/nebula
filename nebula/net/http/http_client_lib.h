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
 */

// https://raw.githubusercontent.com/facebook/proxygen/master/proxygen/httpclient/samples/curl/CurlClient.h

#ifndef NEBULA_NET_HTTP_HTTP_CLIENT_LIB_H_
#define NEBULA_NET_HTTP_HTTP_CLIENT_LIB_H_

#pragma once

#include <folly/io/async/EventBase.h>
#include <folly/io/async/SSLContext.h>
#include <proxygen/lib/http/HTTPConnector.h>
#include <proxygen/lib/http/session/HTTPTransaction.h>
#include <proxygen/lib/utils/URL.h>

// namespace CurlService {

class HTTPClientLibCallback {
public:
  virtual ~HTTPClientLibCallback() {}
  
  virtual void OnHeadersComplete(std::unique_ptr<proxygen::HTTPMessage> msg) = 0;
  virtual void OnBodyComplete(std::unique_ptr<folly::IOBuf> body) = 0;
  virtual void OnConnectError(const folly::AsyncSocketException& ex) = 0;
  virtual void OnError(const proxygen::HTTPException& error) = 0;
};

// TODO(@benqi):
// 支持spdy/http2/http1.1
// keep_alive支持
// ...
class HTTPClientLib : public proxygen::HTTPConnector::Callback,
                   public proxygen::HTTPTransactionHandler {
 public:
//  HTTPClientLib(folly::EventBase* evb, proxygen::HTTPMethod httpMethod,
//             const proxygen::URL& url, const proxygen::HTTPHeaders& headers,
//             const std::string& inputFilename, HTTPClientLibCallback* cb);
  
  HTTPClientLib(folly::EventBase* evb, proxygen::HTTPMethod httpMethod,
             const proxygen::URL& url, const proxygen::HTTPHeaders& headers,
             std::unique_ptr<folly::IOBuf> postData, HTTPClientLibCallback* cb);
  
  ~HTTPClientLib() override;

  // initial SSL related structures
  void initializeSsl(const std::string& certPath,
                     const std::string& nextProtos);
  void sslHandshakeFollowup(proxygen::HTTPUpstreamSession* session) noexcept;

  // HTTPConnector methods
  void connectSuccess(proxygen::HTTPUpstreamSession* session) override;
  void connectError(const folly::AsyncSocketException& ex) override;

  // HTTPTransactionHandler methods
  void setTransaction(proxygen::HTTPTransaction* txn) noexcept override;
  void detachTransaction() noexcept override;
  void onHeadersComplete(
      std::unique_ptr<proxygen::HTTPMessage> msg) noexcept override;
  void onBody(std::unique_ptr<folly::IOBuf> chain) noexcept override;
  void onTrailers(
      std::unique_ptr<proxygen::HTTPHeaders> trailers) noexcept override;
  void onEOM() noexcept override;
  void onUpgrade(proxygen::UpgradeProtocol protocol) noexcept override;
  void onError(const proxygen::HTTPException& error) noexcept override;
  void onEgressPaused() noexcept override;
  void onEgressResumed() noexcept override;

  // Getters
  folly::SSLContextPtr getSSLContext() { return sslContext_; }

  const std::string& getServerName() const;

  void setFlowControlSettings(int32_t recvWindow);

  // const proxygen::HTTPMessage* getResponse() const {
  //  return response_.get();
  // }

  void setLogging(bool enabled) {
    loggingEnabled_ = enabled;
  }

protected:
  proxygen::HTTPTransaction* txn_{nullptr};
  folly::EventBase* evb_{nullptr};
  proxygen::HTTPMethod httpMethod_;
  proxygen::URL url_;
  proxygen::HTTPMessage request_;
  // const std::string inputFilename_;
  folly::SSLContextPtr sslContext_;
  int32_t recvWindow_;
  bool loggingEnabled_{true};

  // std::unique_ptr<proxygen::HTTPMessage> response_;

  // Add by @benqi
  std::unique_ptr<folly::IOBuf> postData_;
  std::unique_ptr<folly::IOBuf> body_;
  HTTPClientLibCallback* cb_;

};

// } // CurlService namespace

#endif

