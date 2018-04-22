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

#ifndef NEBULA_BASE_CONFIG_MANAGER_H_
#define NEBULA_BASE_CONFIG_MANAGER_H_

#include <string>
#include <map>

#include <folly/FBString.h>
#include <folly/Singleton.h>

#include "nebula/base/configurable.h"

namespace folly {
class EventBase;
} // folly

namespace nebula {
  
class ConfigManager {
public:
  ~ConfigManager() = default;
  
  // 单件接口
  static ConfigManager* GetInstance();
  
  void Register(const folly::fbstring& item_name, Configurable* item, bool recv_updated = false);
  void UnRegister(const folly::fbstring& item_name);
  
  bool Initialize(const std::string& config_file);
  
  void StartObservingConfigFile(folly::EventBase* evb);
  
private:
  friend class folly::Singleton<ConfigManager>;
  
  ConfigManager() = default;
  
  bool OnConfigFileUpdated();
  bool OnConfigDataUpdated(const folly::fbstring& config_data, bool is_first);
  
  std::string config_file_;
  
  struct ConfigurableWithUpdated {
    Configurable* configurable{nullptr};
    bool recv_updated{false};
  };
  
  typedef std::map<folly::fbstring, ConfigurableWithUpdated> ConfigItemMap;
  ConfigItemMap config_items_;
  
  bool is_watched_{false};
};

}

#endif
