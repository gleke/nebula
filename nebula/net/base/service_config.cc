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

#include "nebula/net/base/service_config.h"

#include <iostream>
#include "nebula/base/json/json.h"

namespace nebula {
  
// Override from Configurable
bool ServiceConfig::SetConf(const std::string& conf_name, const folly::dynamic& conf) {
  folly::dynamic v = nullptr;
  v = Configurable::GetConfigValue(conf, "name");
  if (v.isString()) name = v.asString();
  v = Configurable::GetConfigValue(conf, "type");
  if (v.isString()) type = v.asString();
  v = Configurable::GetConfigValue(conf, "proto");
  if (v.isString()) proto = v.asString();
  v = Configurable::GetConfigValue(conf, "hosts");
  if (v.isString()) hosts = v.asString();
  v = Configurable::GetConfigValue(conf, "port");
  if (v.isInt()) port = static_cast<uint32_t>(v.asInt());
  
  v = Configurable::GetConfigValue(conf, "max_conn_cnt");
  if (v.isInt()) max_conn_cnt = static_cast<uint32_t>(v.asInt());

  return true;
}

std::string ServiceConfig::ToString() const {
  return folly::sformat("{{name:{}, type:{}, proto:{}, hosts:{}, port:{}}}",
                        name,
                        type,
                        proto,
                        hosts,
                        port);
}

void ServiceConfig::PrintDebug() const {
  std::cout << "name: " << name
            << ", type: " << type
            << ", proto: " << proto
            << ", hosts: " << hosts
            << ", port: " << port
            << ", max_conn_cnt: " << max_conn_cnt
            << std::endl;
}

std::vector<std::shared_ptr<ServiceConfig>> ServicesConfig::ToServiceConfigs(const folly::dynamic& conf) {
  std::vector<std::shared_ptr<ServiceConfig>> v;
  
  for (auto& v2 : conf) {
    auto config_info = std::make_shared<ServiceConfig>();
    config_info->SetConf("", v2);
    v.push_back(config_info);
  }
  
  return v;
}

}

