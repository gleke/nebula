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

#ifndef NEBULA_NET_BASE_SERVER_H_
#define NEBULA_NET_BASE_SERVER_H_

#include <list>

#include "nebula/base/base_daemon.h"
#include "nebula/net/base/service_base.h"
#include "nebula/net/thread_group_list_manager.h"

namespace nebula {
  
// 两种情况
// 刚启动时加载配置文件
class BaseServer : public BaseDaemon {
public:
  BaseServer();
  ~BaseServer() override = default;
  
protected:
  // 必须初始化以后才能调用
  void RegisterService(const std::string& name, const std::string& type, const std::string& proto) {
    // TODO(@benqi):
    // 检查是否已经加入
    services_.push_back(std::make_tuple(name, type, proto));
  }
  
  bool LoadConfig(const std::string& config_path) override;
  bool Initialize() override;
  bool Run() override;
  bool Destroy() override;

  virtual void InstallModule();

  // std::map<uint64_t, uint32_t> connected_server_map_;
  ServicesConfig services_config_;
  
  ThreadGroupListOption thread_group_options_;
  
  typedef std::list<std::tuple<std::string, std::string, std::string>> ServiceInstanceList;
  ServiceInstanceList services_;
};

}

#endif


