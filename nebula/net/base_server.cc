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

#include "nebula/net/base_server.h"

#include "nebula/base/config_manager.h"
// #include "nebula/base/gperftools_profiler.h"

#include "nebula/net/net_engine_manager.h"
#include "nebula/net/handler/module_install.h"

namespace nebula {
  
BaseServer::BaseServer() {
  auto config_manager = ConfigManager::GetInstance();
  
  config_manager->Register("services", &services_config_);
  config_manager->Register("thread_group", &thread_group_options_);
}

bool BaseServer::LoadConfig(const std::string& config_path) {
  bool rv = BaseDaemon::LoadConfig(config_path);
  return rv;
}

bool BaseServer::Initialize() {
  BaseDaemon::Initialize();
  this->InstallModule();

  // 初始化程序
  auto thread_groups = std::make_shared<ThreadGroupListManager>(thread_group_options_);
  auto net_engine_manager = NetEngineManager::GetInstance();
  net_engine_manager->set_thread_groups(thread_groups);
  net_engine_manager->SetupService(services_config_);
  
  for (auto it=services_.begin(); it!=services_.end(); ++it) {
    net_engine_manager->Install(std::get<0>(*it), std::get<1>(*it), std::get<2>(*it));
  }
  
  return true;
}

bool BaseServer::Run() {
  auto net_engine_manager = NetEngineManager::GetInstance();
  // 启动成功
  try {
    net_engine_manager->Start();
  } catch (std::exception& e) {
    LOG(ERROR) << "Run - catch exception: " << e.what();
    return -1;
  } catch (...) {
    LOG(ERROR) << "Run - catch  a invalid exception";
    return -1;
  }
  
  // GPerftoolsProfiler profiler;
  // profiler.ProfilerStart();

  BaseDaemon::Run();

  // profiler.ProfilerStop();
  
  net_engine_manager->Stop();
  return true;
}

bool BaseServer::Destroy() {
  return BaseDaemon::Destroy();
}

void BaseServer::InstallModule() {
  ::InstallModule();
}

}

