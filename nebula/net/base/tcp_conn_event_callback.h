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

#ifndef NEBULA_NET_BASE_TCP_CONN_EVENT_CALLBACK_H_
#define NEBULA_NET_BASE_TCP_CONN_EVENT_CALLBACK_H_

#include <wangle/channel/Pipeline.h>

namespace nebula {
  
//////////////////////////////////////////////////////////////////////////////
class TcpConnEventCallback {
public:
  virtual ~TcpConnEventCallback() = default;
  
  // EventBase线程里执行
  virtual uint64_t OnNewConnection(wangle::PipelineBase* pipeline) { return 0; }
  
  // EventBase线程里执行
  virtual bool OnConnectionClosed(uint64_t conn_id) { return false; }
};

}

#endif

