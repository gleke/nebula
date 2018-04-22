/*
 *  Copyright (c) 2016, https://github.com/nebula-im
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

#ifndef	BASE_BASE_ZRPC_ZRPC_SERVICE_H_
#define	BASE_BASE_ZRPC_ZRPC_SERVICE_H_

#include "nebula/net/zproto/zproto_package_data.h"

class BaseZRpcService {
public:
  enum AttachDataType {
    APPID = 0,
    UID,
    // TODO(@benqi):
    //  设备信息等
    MAX,
  };
  
  virtual ~BaseZRpcService() = default;

  virtual bool Initialize(zproto::RpcRequestPtr v);
  
  uint64_t session_id() const {
    return rpc_request_->session_id();
  }
  
  const std::string& uid() const {
    return *(rpc_request_->attach_data.options[UID].data.s);
  }

  uint32_t app_id() const {
    return static_cast<uint32_t>(rpc_request_->attach_data.options[APPID].data.n);
  }

  uint64_t conn_id() const {
    return rpc_request_->birth_conn_id();
  }

protected:
  zproto::RpcRequestPtr rpc_request_;
};

#endif

