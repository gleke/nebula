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

#ifndef NEBULA_BASE_CONFIGURABLE_H_
#define NEBULA_BASE_CONFIGURABLE_H_

#include <folly/dynamic.h>

namespace nebula {

// 动态配置框架
struct Configurable {
public:
  virtual ~Configurable() = default;
  
  virtual bool SetConf(const folly::dynamic& conf) { return true; }
  virtual bool SetConf(const std::string& conf_name, const folly::dynamic& conf) { return true; }
  
  static folly::dynamic GetConfigValue(const folly::dynamic& conf, const std::string& k) {
    folly::dynamic rv = nullptr;
    
    // confs为一数组对象
    if (conf.isArray()) {
      for (auto& v2 : conf) {
        // confs
        if (!v2.isObject()) continue;
        if (0 == v2.count(k)) continue;
        rv = v2[k];
        break;
      }
    } else {
      auto tmp = conf.get_ptr(k);
      if (tmp) {
        rv = *tmp;
      }
    }
    
    return rv;
  }

};

}

#endif
