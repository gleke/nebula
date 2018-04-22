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

#ifndef NEBULA_BASE_PLUGIN_H_
#define NEBULA_BASE_PLUGIN_H_

#include <string>
#include <folly/dynamic.h>
namespace nebula {

class Plugin {
public:
  virtual ~Plugin() = default;
  
  
  virtual const std::string& GetPluginName() const = 0;
  virtual void Install(const folly::dynamic& conf) = 0;
  
  virtual void Initialize() = 0;
  virtual void Shutdown() = 0;
  
  virtual void Uninstall() = 0;
};

class PluginFactory {
public:
  virtual ~PluginFactory ()  {}
  
  virtual const std::string& GetPluginName() const = 0;
  virtual Plugin* CreateInstance() = 0;
  virtual void DestroyInstance(Plugin* module) = 0;
};

}

#endif
