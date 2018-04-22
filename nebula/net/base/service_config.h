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

#ifndef NEBULA_NET_BASE_SERVICE_CONFIG_H_
#define NEBULA_NET_BASE_SERVICE_CONFIG_H_

#include "nebula/base/configurable.h"
#include "nebula/base/reflection_util.h"

namespace nebula {
  
struct ServiceConfig : public Configurable {
  virtual ~ServiceConfig() = default;
  
  // Override from Configurable
  bool SetConf(const std::string& conf_name, const folly::dynamic& conf) override;
  
  std::string ToString() const;
  void PrintDebug() const;
  
  std::string name;
  std::string type;
  std::string proto;
  std::string hosts;
  uint32_t    port;
  
  uint32_t max_conn_cnt {40960};
  
  META(name, type, proto, hosts, port, max_conn_cnt);
};

using ServiceConfigPtr = std::shared_ptr<ServiceConfig>;
  
struct ServicesConfig : public Configurable {
  virtual ~ServicesConfig() = default;

  static std::vector<std::shared_ptr<ServiceConfig>> ToServiceConfigs(const folly::dynamic& conf);

  bool SetConf(const std::string& conf_name, const folly::dynamic& conf) override {
    service_configs = ToServiceConfigs(conf);
    return true;
  }
  
  void PrintDebug() const {
    for(auto& v : service_configs) {
      v->PrintDebug();
    }
  }
  
  std::vector<std::shared_ptr<ServiceConfig>> service_configs;
};
  
}

#endif
