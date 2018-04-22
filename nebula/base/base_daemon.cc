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

#include "nebula/base/base_daemon.h"

#include <signal.h>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "nebula/base/config_manager.h"
#include "nebula/base/logger/glog_util.h"
#include "nebula/base/timer_manager.h"

DEFINE_string(config, "", "json config file");

// 为什么使用匿名空间，可以参考https://google.github.io/styleguide/cppguide.html
namespace {
  
// 接收信号后执行退出程序
// folly::EventBase* g_main_evb = nullptr;
nebula::BaseDaemon* g_main_daemon = nullptr;
  
void OnShutdownDaemon(nebula::BaseDaemon* main_daemon) {
  // LOG(INFO) << "OnShutdownDaemon...";
  // if (main_evb) {
  //   // DCHECK()
  //   main_evb->terminateLoopSoon();
  // }
  if (main_daemon) {
    main_daemon->DoQuit();
  }
}

void SignalHandler(int signum) {
  switch(signum) {
    case SIGTERM:
    case SIGINT:
    case SIGHUP:
      OnShutdownDaemon(g_main_daemon);
      break;
  }
}
  
}

namespace nebula {

BaseDaemon::BaseDaemon()
  : timer_manager_(folly::make_unique<TimerManager>(&main_eb_)) {
  
  // g_main_evb = &main_eb_;
  g_main_daemon = this;
  config_manager_ = ConfigManager::GetInstance();
  
  // 注册logger配置
  config_manager_->Register("logger", GetLogInitializerSingleton().get());
}
                   
BaseDaemon::~BaseDaemon() {
  g_main_daemon = nullptr;
}

bool BaseDaemon::LoadConfig(const std::string& config_file) {
  LOG(INFO) << "LoadConfig - " << config_file;
  bool rv = ConfigManager::GetInstance()->Initialize(config_file);
  if (rv == false) {
    LOG(ERROR) << "LoadConfig - ConfigManager::Initialize() error, config_path: " << config_file;
  }
  return rv;
}

bool	BaseDaemon::Initialize() {
  LOG(INFO) << "Initialize - Initialize...";
	return true;
}

bool BaseDaemon::Run() {
  LOG(INFO) << "Run - Run...";
  main_eb_.loopForever();
  return true;
}

// 退出
void BaseDaemon::Quit() {
  main_eb_.terminateLoopSoon();
}

bool BaseDaemon::RunInternal() {
  Run();
	return true;
}

bool BaseDaemon::Destroy() {
  LOG(INFO) << "Destroy - Destroy...";
	return true;
}

bool BaseDaemon::DoMain() {
  LOG(INFO) << "DoMain - DoMain...";
  
  // Ignore SIGPIPE
  signal(SIGPIPE, SIG_IGN);
  
  // kill
  signal(SIGTERM, SignalHandler);
  signal(SIGINT, SignalHandler);
  signal(SIGHUP, SignalHandler);
  
  if (FLAGS_config.empty()) {
    config_file_ = google::ProgramInvocationShortName();
    config_file_ += ".json";
  } else {
    config_file_ = FLAGS_config;
  }
  
  LOG(INFO) << "DoMain - LoadConfig: " <<  config_file_;

  if(!LoadConfig(config_file_)) {
    LOG(ERROR) << "DoMain - LoadConfig error: " << config_file_;
		return false;
	}

	LOG(INFO) << "DoMain - Initialize...";
	if(!Initialize()) {
		LOG(ERROR) << "DoMain - error initialize";
		return false;
	}

	LOG(INFO) << "DoMain - Running...";
	RunInternal();

  timer_manager_.reset();
	LOG(INFO) << "DoMain - Destroy...";
	Destroy();

	LOG(INFO) << "DoMain - Shutdown...";
	return true;
}

const char* GetInstanceName() {
  return google::ProgramInvocationShortName();
}

}

