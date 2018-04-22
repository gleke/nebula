/*
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula
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

#include "nebula/net/engine/http_client.h"

void HttpClientTest(folly::EventBase* evb, const std::string& url) {
  HttpClientGet(evb, url, [&] (HttpClientReply& reply) {
    switch (reply.result) {
      case HttpClientReply::OK:
        reply.headers->dumpMessageToSink(nullptr);
        std::cout << reply.body->moveToFbString() << std::endl;
        // reply.body
        break;
      case HttpClientReply::INVALID:
        LOG(INFO) << "INVALID";
        break;
      case HttpClientReply::CONNECT_ERROR:
        LOG(INFO) << "CONNECT_ERROR";
        break;
      case HttpClientReply::HTTP_ERROR:
        LOG(INFO) << "HTTP_ERROR";
        break;
      default:
        break;
    }
  });
}


int main(int argc, char* argv[]) {
  folly::EventBase main_eb;
  
  HttpClientTest(&main_eb, "http://www.baidu.com");
  
  main_eb.loopForever();
  
  return 0;
}
