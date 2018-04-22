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

#include "base/base_zrpc_service.h"

#include "nebula/base/logger/glog_util.h"

bool BaseZRpcService::Initialize(zproto::RpcRequestPtr v) {
  if (!v->has_attach_data()) {
    LOG(FATAL) << "Initialize - attach_data empty!!! " << v->ToString();
    return false;
  }
  
  if (v->attach_data.options.size() == MAX) {
    LOG(ERROR) << "Initialize - attach_data empty!!! " << v->ToString();
    return false;
  }
  
  // TODO(@benqi): 检查附加字段
  rpc_request_ = v;
  
  return false;
}
