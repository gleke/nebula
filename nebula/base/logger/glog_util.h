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

#ifndef NEBULA_BASE_GLOG_UTIL_H_
#define NEBULA_BASE_GLOG_UTIL_H_

#include <glog/logging.h>
#include <glog/stl_logging.h>

#include "nebula/base/configurable.h"

namespace nebula {

// 配置
struct LogInitializer : public Configurable {
  virtual ~LogInitializer() = default;
  
  static void Initialize(const char* argv0);
  
  // 配置改变
  bool SetConf(const std::string& conf_name, const folly::dynamic& conf) override;
};

std::shared_ptr<LogInitializer> GetLogInitializerSingleton();

}

#endif
