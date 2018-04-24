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

#ifndef NEBULA_NET_ENGINE_TCP_SERVICE_BASE_H_
#define NEBULA_NET_ENGINE_TCP_SERVICE_BASE_H_

// #include <wangle/channel/Pipeline.h>
#include <folly/executors/IOThreadPoolExecutor.h>

#include "nebula/net/base/tcp_conn_event_callback.h"
#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/base/service_base.h"

using IOThreadPoolExecutorPtr = std::shared_ptr<folly::IOThreadPoolExecutor>;

namespace nebula {

//////////////////////////////////////////////////////////////////////////////
class TcpServiceBase : public ServiceBase, public TcpConnEventCallback {
public:
  TcpServiceBase(const ServiceConfig& config, const IOThreadPoolExecutorPtr& io_group)
    : ServiceBase(config),
      io_group_(io_group) {}
  
  virtual ~TcpServiceBase() = default;

  // Impl from TcpConnEventCallback
  // EventBase线程里执行
  virtual uint64_t OnNewConnection(wangle::PipelineBase* pipeline) override;
  // EventBase线程里执行
  virtual bool OnConnectionClosed(uint64_t conn_id) override;

  inline IOThreadPoolExecutorPtr GetIOThreadPoolExecutor() const {
    return io_group_;
  }
  
protected:
  IOThreadPoolExecutorPtr io_group_;
  
  // TODO(@benqi): 通过回调转发conn事件
  // TcpConnEventCallback* callback_;
};

}

#endif
