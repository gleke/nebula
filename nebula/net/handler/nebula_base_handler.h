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

#ifndef NUBULA_NET_HANDLER_NEBULA_BASE_HANDLER_H_
#define NUBULA_NET_HANDLER_NEBULA_BASE_HANDLER_H_

#include <wangle/channel/Handler.h>

#include "nebula/net/engine/tcp_service_base.h"


namespace nebula {

// 使用AttachData存储连接附加数据
// 比如用户名等
struct ConnAttachData {
  virtual ~ConnAttachData() = default;
};

typedef std::shared_ptr<ConnAttachData> ConnAttachDataPtr;

class NebulaBaseHandler {
public:
  enum class ConnState : uint8_t {
    NONE = 0,
    CONNECTED = 1,                     // 连接建立
    CLOSED = 2,
    ERROR
  };

  explicit NebulaBaseHandler(ServiceBase* service)
    : service_(dynamic_cast<TcpServiceBase*>(service)),
      conn_id_(0),
      conn_state_(ConnState::NONE) {
  
  }
  
  virtual ~NebulaBaseHandler() = default;
    
  // uint64_t ThreadLocalConnManager::OnNewConnection(wangle::PipelineBase* pipeline) {

  uint64_t OnNewConnection(wangle::PipelineBase* pipeline, const std::string& remote_address);
  void OnConnectionClosed();
  

  //////////////////////////////////////////////////////////////////////////
  inline nebula::TcpServiceBase* GetServiceBase() {
    return service_;
  }
  
  inline ConnAttachData* GetAttachData() {
    return attach_data_.get();
  }
  
  //////////////////////////////////////////////////////////////////////////
//  template <class T>
//  inline T* CastByGetAttachData() {
//    return nullptr;
//  }
  
  template <class T>
  inline typename std::enable_if<std::is_base_of<ConnAttachData, T>::value, T>::type*
  CastByGetAttachData() {
    return dynamic_cast<T*>(attach_data_.get());
  }

  inline void SetAttachData(const std::shared_ptr<ConnAttachData>& v) {
    attach_data_ = v;
  }
  
  inline uint64_t GetConnID() const {
    return conn_id_;
  }
  
  inline const std::string& GetRemoteAddress() const {
    return remote_address_;
  }
  
  inline bool IsTcpServer() const {
    return service_->GetServiceType() == "tcp_server";
  }
  
  inline bool IsTcpClient() const {
    return service_->GetServiceType() == "tcp_client";
  }

protected:
  // 全局的
  TcpServiceBase* service_{nullptr};
  uint64_t conn_id_ {0};
  std::shared_ptr<ConnAttachData> attach_data_;
  ConnState conn_state_ {ConnState::NONE};
  
  std::string remote_address_;
};

class NebulaBasePipelineFactory {
public:
  virtual ~NebulaBasePipelineFactory() = default;
  
  explicit NebulaBasePipelineFactory(ServiceBase* service)
    : service_(service) {
  }
  
protected:
  ServiceBase* service_{nullptr};
};
  
}

#endif
