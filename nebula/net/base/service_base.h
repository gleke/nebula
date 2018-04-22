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

#ifndef NEBULA_NET_BASE_SERVICE_BASE_H_
#define NEBULA_NET_BASE_SERVICE_BASE_H_

#include <wangle/concurrent/IOThreadPoolExecutor.h>

#include "nebula/net/base/service_config.h"
// #include "nebula/base/factory_object.h"
#include "nebula/base/func_factory_manager.h"

namespace folly {
class IOBuf;
}

namespace nebula {
  
enum class ServiceModuleType : int {
    INVALID = 0,
    TCP_SERVER = 1,
    TCP_CLIENT_GROUP = 2,
    TCP_CLIENT_POOL = 3,
    TCP_CLIENT = 4,
    UDP_SERVER = 5,
    UDP_CLIENT = 6,
    HTTP_SERVER = 7,
    RPC_SERVER = 8,
    RPC_CLIENT = 9,
    MAX_SIZE = 10
};
  
class ServiceBase;

class ServiceBase {
public:
  ServiceBase(const ServiceConfig& config)
    : config_(config) {}
  
  virtual ~ServiceBase() = default;
  
  virtual ServiceModuleType GetModuleType() const = 0;
  
  inline const ServiceConfig& GetServiceConfig() const {
    return config_;
  }
  inline const std::string& GetServiceName() const {
    return config_.name;
  }
  inline const std::string& GetServiceType() const {
    return config_.type;
  }
  inline const std::string& GetServiceProto() const {
    return config_.proto;
  }
  
  virtual bool Start() { return false; }
  virtual bool Pause() { return false; }
  virtual bool Stop() { return false; }
  
  virtual bool AddChild(std::shared_ptr<ServiceBase> service) { return false; }
  
protected:
  ServiceConfig config_;
};
  
using ServiceBasePtr = std::shared_ptr<ServiceBase>;

using NewServiceBaseFunc = std::function<
  ServiceBasePtr(const ServiceConfig&, const std::shared_ptr<wangle::IOThreadPoolExecutor>&)
>;
  
using ServiceSelfRegisterFactoryManager = FuncFactoryManager<
  NewServiceBaseFunc, std::pair<std::string, std::string>
>;

using ServiceSelfRegisterTemplate = ServiceSelfRegisterFactoryManager::RegisterTemplate;


}

  
#endif
