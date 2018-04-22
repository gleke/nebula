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

#include "nebula/base/config_manager.h"

#include <iostream>

#include <glog/logging.h>

#include <folly/FileUtil.h>
#include <folly/Range.h>
#include <folly/json.h>

#include "nebula/base/config/import_resolver_if.h"
#include "nebula/base/config/config_preprocessor.h"

#define DISABLE_INOTIFY // 暂时不支持inotify机制

#ifndef DISABLE_INOTIFY
#include "nebula/base/config/file_observer.h"
#endif


namespace {

const folly::StringKeyedUnorderedMap<folly::dynamic> kConfigGlobalParams{};

class ConfigImportResolver : public ImportResolverIf {
public:
  std::string import(folly::StringPiece path) override {
    folly::fbstring json_data;
    if(!folly::readFile(path.data(), json_data)) {
      LOG(ERROR) << "import - Unable to open import path << " << path;
    }
    return json_data.toStdString();
  }
};

}

namespace nebula {
  
ConfigManager* ConfigManager::GetInstance() {
  static ConfigManager g_config_manager;
  return &g_config_manager;
}

void ConfigManager::Register(const folly::fbstring& item_name, Configurable* item, bool recv_updated) {
  std::cout << "ConfigManager::RegisterConfig - register config_item: " << item_name << std::endl;
  
  if (config_items_.find(item_name) != config_items_.end()) {
    std::cerr << "ConfigManager::RegisterConfig - config_item is registed: " << item_name << std::endl;
  } else {
    ConfigurableWithUpdated v;
    v.configurable = item;
    v.recv_updated = recv_updated;
    config_items_.insert(std::make_pair(item_name, v));
  }
}

void ConfigManager::UnRegister(const folly::fbstring& item_name) {
  LOG(INFO) << "ConfigManager::UnRegisterConfig - register config_item: " << item_name;
  
  ConfigItemMap::iterator it = config_items_.find(item_name);
  if (it != config_items_.end()) {
    config_items_.erase(it);
  }
}

bool ConfigManager::Initialize(const std::string& config_file) {
  if (!config_file_.empty()) {
    LOG(ERROR) << "Initialize - config_file is initialized, existed config_file: " << config_file_
                << ", will config_file: " << config_file;
    return false;
  }
  
  config_file_ = config_file;
  return OnConfigFileUpdated();
}

bool ConfigManager::OnConfigFileUpdated() {
  bool rv = false;
  
  folly::fbstring config_data;
  if(!folly::readFile(config_file_.c_str(), config_data)) {
    LOG(ERROR) << "OnConfigFileUpdated - Unable to open config_file << " << config_file_;
    return rv;
  } else {
    rv = OnConfigDataUpdated(config_data, true);
  }
  
  return rv;
}

bool ConfigManager::OnConfigDataUpdated(const folly::fbstring& config_data, bool is_first) {
  bool rv = false;
  ConfigImportResolver resolver;
  try {
    auto configs = ConfigPreprocessor::getConfigWithoutMacros(config_data, resolver, kConfigGlobalParams);
    for (auto& it : configs.items()) {
      auto& key = const_cast<folly::dynamic&>(it.first);
      auto& value = const_cast<folly::dynamic&>(it.second);
      
      ConfigItemMap::iterator it2 = config_items_.find(key.asString());
      if (it2 != config_items_.end()) {
        if (it2->second.configurable && (is_first || it2->second.recv_updated)) {
          // 规则：
          //  1. 是第一次，则全部通知
          //  2. 如果配置项有变更指定接收，则通知
          it2->second.configurable->SetConf(it2->first.toStdString(), value);
        }
      } else {
        LOG(ERROR) << "OnConfigFileUpdated - Unregister config_item: " << key.asString();
      }
    }
    rv = true;
    
  } catch (std::exception& e) {
    LOG(ERROR) << "OnConfigFileUpdated - getConfigWithoutMacros in config_file: " << config_file_
                << ", catch a exception: " << e.what();
  } catch (...) {
    LOG(ERROR) << "OnConfigFileUpdated - getConfigWithoutMacros in config_file: " << config_file_
                << ", catch a invalid exception.";
  }
  
  return rv;
}


void ConfigManager::StartObservingConfigFile(folly::EventBase* evb) {
#ifndef DISABLE_INOTIFY
  if(is_watched_)
    return;
  
  startObservingFile(
                     config_file_,
                     *evb,
                     100,
                     10000,
                     [this](std::string data) {
                     // std::move([this](std::string data) {
    LOG(INFO) << "ConfigManager - OnConfigDataUpdated, data " << data;
    OnConfigDataUpdated(data, false);
  }));
#endif
}

}

