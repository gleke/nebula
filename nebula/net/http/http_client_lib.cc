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

// https://raw.githubusercontent.com/facebook/proxygen/master/proxygen/httpclient/samples/curl/CurlClient.cpp

#include "nebula/net/http/http_client_lib.h"

// #include <gflags/gflags.h>
#include <errno.h>
#include <sys/stat.h>

// #include <fstream>

#include <folly/FileUtil.h>
#include <folly/String.h>
#include <proxygen/lib/http/HTTPMessage.h>
#include <proxygen/lib/http/session/HTTPUpstreamSession.h>
#include <wangle/ssl/SSLContextConfig.h>

using namespace folly;
using namespace proxygen;
using namespace std;

// DECLARE_int32(recv_window);

// namespace CurlService {
HTTPClientLib::HTTPClientLib(EventBase* evb, HTTPMethod httpMethod, const URL& url,
                       const HTTPHeaders& headers, std::unique_ptr<folly::IOBuf> postData,
                       HTTPClientLibCallback* cb):
    evb_(evb), httpMethod_(httpMethod), url_(url),
    postData_(std::move(postData)), cb_(cb) {
  headers.forEach([this] (const string& header, const string& val) {
      request_.getHeaders().add(header, val);
    });
}

HTTPClientLib::~HTTPClientLib() {
}


void HTTPClientLib::initializeSsl(const string& certPath,
                               const string& nextProtos) {
  sslContext_ = std::make_shared<folly::SSLContext>();
  sslContext_->setOptions(SSL_OP_NO_COMPRESSION);
  wangle::SSLContextConfig config;
  sslContext_->ciphers(config.sslCiphers);
  sslContext_->loadTrustedCertificates(certPath.c_str());
  list<string> nextProtoList;
  folly::splitTo<string>(',', nextProtos, std::inserter(nextProtoList,
                                                        nextProtoList.begin()));
  sslContext_->setAdvertisedNextProtocols(nextProtoList);
}


void HTTPClientLib::sslHandshakeFollowup(HTTPUpstreamSession* session) noexcept {
  AsyncSSLSocket* sslSocket = dynamic_cast<AsyncSSLSocket*>(
    session->getTransport());

  const unsigned char* nextProto = nullptr;
  unsigned nextProtoLength = 0;
  sslSocket->getSelectedNextProtocol(&nextProto, &nextProtoLength);
  if (nextProto) {
    VLOG(1) << "Client selected next protocol " <<
      string((const char*)nextProto, nextProtoLength);
  } else {
    VLOG(1) << "Client did not select a next protocol";
  }

  // Note: This ssl session can be used by defining a member and setting
  // something like sslSession_ = sslSocket->getSSLSession() and then
  // passing it to the connector::connectSSL() method
}

void HTTPClientLib::setFlowControlSettings(int32_t recvWindow) {
  recvWindow_ = recvWindow;
}

void HTTPClientLib::connectSuccess(HTTPUpstreamSession* session) {

  if (url_.isSecure()) {
    sslHandshakeFollowup(session);
  }

  session->setFlowControl(recvWindow_, recvWindow_, recvWindow_);

  txn_ = session->newTransaction(this);
  request_.setMethod(httpMethod_);
  request_.setHTTPVersion(1, 1);
  request_.setURL(url_.makeRelativeURL());
  request_.setSecure(url_.isSecure());

  if (!request_.getHeaders().getNumberOfValues(HTTP_HEADER_USER_AGENT)) {
    request_.getHeaders().add(HTTP_HEADER_USER_AGENT, "proxygen_curl");
  }
  if (!request_.getHeaders().getNumberOfValues(HTTP_HEADER_HOST)) {
    request_.getHeaders().add(HTTP_HEADER_HOST, url_.getHostAndPort());
  }
  if (!request_.getHeaders().getNumberOfValues(HTTP_HEADER_ACCEPT)) {
    request_.getHeaders().add("Accept", "*/*");
  }
  if (loggingEnabled_) {
    request_.dumpMessage(4);
  }

  txn_->sendHeaders(request_);

  unique_ptr<IOBuf> buf;
  if (httpMethod_ == HTTPMethod::POST) {
    /**
      const uint16_t kReadSize = 4096;
      ifstream inputFile(inputFilename_, ios::in | ios::binary);

      // Reading from the file by chunks
      // Important note: It's pretty bad to call a blocking i/o function like
      // ifstream::read() in an eventloop - but for the sake of this simple
      // example, we'll do it.
      // An alternative would be to put this into some folly::AsyncReader
      // object.
      while (inputFile.good()) {
        buf = IOBuf::createCombined(kReadSize);
        inputFile.read((char*)buf->writableData(), kReadSize);
        buf->append(inputFile.gcount());
        txn_->sendBody(move(buf));
      }
     */
    txn_->sendBody(move(postData_));
  }

  // note that sendBody() is called only for POST. It's fine not to call it
  // at all.

  txn_->sendEOM();
  session->closeWhenIdle();
}

void HTTPClientLib::connectError(const folly::AsyncSocketException& ex) {
  LOG_IF(ERROR, loggingEnabled_) << "Coudln't connect to "
                                 << url_.getHostAndPort() << ":" << ex.what();
  if (cb_) cb_->OnConnectError(ex);
}

void HTTPClientLib::setTransaction(HTTPTransaction*) noexcept {
}

void HTTPClientLib::detachTransaction() noexcept {
  if (cb_) cb_->OnBodyComplete(std::move(body_));
}

void HTTPClientLib::onHeadersComplete(unique_ptr<HTTPMessage> msg) noexcept {
  // response_ = std::move(msg);
  if (cb_) cb_->OnHeadersComplete(std::move(msg));

  if (!loggingEnabled_) {
    return;
  }
  
  // response_->getHeaders().forEach([&](const string& header, const string& val) {
  //  cout << header << ": " << val << endl;
  // });
}

void HTTPClientLib::onBody(std::unique_ptr<folly::IOBuf> chain) noexcept {
  /**
    if (!loggingEnabled_) {
      return;
    }
    if (chain) {
      const IOBuf* p = chain.get();
      do {
        cout.write((const char*)p->data(), p->length());
        p = p->next();
      } while (p != chain.get());
    }
  */
  if (!body_) {
    // LOG(INFO) << "onBody1";
    body_ = std::move(chain);
  } else {
    // LOG(INFO) << "onBody2";
    body_->prependChain(std::move(chain));
  }

}

void HTTPClientLib::onTrailers(std::unique_ptr<HTTPHeaders>) noexcept {
  LOG_IF(INFO, loggingEnabled_) << "Discarding trailers";
}

void HTTPClientLib::onEOM() noexcept {
  LOG_IF(INFO, loggingEnabled_) << "Got EOM";
}

void HTTPClientLib::onUpgrade(UpgradeProtocol) noexcept {
  LOG_IF(INFO, loggingEnabled_) << "Discarding upgrade protocol";
}

void HTTPClientLib::onError(const HTTPException& error) noexcept {
  LOG_IF(ERROR, loggingEnabled_) << "An error occurred: " << error.what();
  if (cb_) cb_->OnError(error);
}

void HTTPClientLib::onEgressPaused() noexcept {
  LOG_IF(INFO, loggingEnabled_) << "Egress paused";
}

void HTTPClientLib::onEgressResumed() noexcept {
  LOG_IF(INFO, loggingEnabled_) << "Egress resumed";
}

const string& HTTPClientLib::getServerName() const {
  const string& res = request_.getHeaders().getSingleOrEmpty(HTTP_HEADER_HOST);
  if (res.empty()) {
    return url_.getHost();
  }
  return res;
}

// }  // namespace CurlService
