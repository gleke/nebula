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

#ifndef NEBULA_NET_HANDLER_ZPROTO_ZPROTO_EVENT_CALLBACK_H_
#define NEBULA_NET_HANDLER_ZPROTO_ZPROTO_EVENT_CALLBACK_H_

// #include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/engine/tcp_service_base.h"
// #include "nebula/net/zproto/zproto_package_data.h"

/////////////////////////////////////////////////////////////////////////////////////////
template <typename Pipeline, typename Message>
struct NebulaEventCallback {
  using NewConnectionFunc = std::function<int(nebula::TcpServiceBase*, Pipeline*)>;
  using DataReceivedFunc = std::function<int(Pipeline*, Message)>;
  using ConnectionClosedFunc = std::function<int(nebula::TcpServiceBase*, Pipeline*)>;
  
  static void Initializer(NewConnectionFunc new_connection,
                          DataReceivedFunc data_received,
                          ConnectionClosedFunc connection_closed) {
    g_new_connection = new_connection;
    g_data_received = data_received;
    g_connection_closed = connection_closed;
  }
  
  ///////////////////////////////////////////////////////////////////////////////////////
  static int OnNewConnection(nebula::TcpServiceBase* service, Pipeline* pipeline) {
    if (g_new_connection) {
      return g_new_connection(service, pipeline);
    } else {
      return -1;
    }
  }

  static int OnDataReceived(Pipeline* pipeline, Message message_data) {
    if (g_data_received) {
      return g_data_received(pipeline, std::forward<Message>(message_data));
    } else {
      return -1;
    }
  }
  
  static int OnConnectionClosed(nebula::TcpServiceBase* service,  Pipeline* pipeline) {
    if (g_connection_closed) {
      return g_connection_closed(service, pipeline);
    } else {
      return -1;
    }
  }

  static void Destroy() {
    g_new_connection = nullptr;
    g_data_received = nullptr;
    g_connection_closed = nullptr;
  }
  
  ///////////////////////////////////////////////////////////////////////////////////////
  static NewConnectionFunc g_new_connection;
  static DataReceivedFunc g_data_received;
  static ConnectionClosedFunc g_connection_closed;
  
};

template <typename Pipeline, typename Message>
std::function<int(nebula::TcpServiceBase*, Pipeline*)> NebulaEventCallback<Pipeline, Message>::g_new_connection;
template <typename Pipeline, typename Message>
std::function<int(Pipeline*, Message)> NebulaEventCallback<Pipeline, Message>::g_data_received;
template <typename Pipeline, typename Message>
std::function<int(nebula::TcpServiceBase*, Pipeline*)> NebulaEventCallback<Pipeline, Message>::g_connection_closed;

#endif
