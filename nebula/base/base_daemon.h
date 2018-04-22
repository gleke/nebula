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

// 服务器基类,为服务器类提供了一个通用的流程:
// 包括读配置文件,初始化函数,销毁函数,以及循环驱动
//

#ifndef	NEBULA_BASE_BASE_DAEMON_H_
#define	NEBULA_BASE_BASE_DAEMON_H_

#include <folly/init/Init.h>
#include <folly/io/async/EventBase.h>

#include "nebula/base/logger/glog_util.h"

namespace nebula {

class TimerManager;
class ConfigManager;
class BaseDaemon {
public:
  BaseDaemon();
  virtual ~BaseDaemon();
  
  // 主函数,将执行文件的名字作为日志的标志打开日志;屏蔽SIGINT与SIGPIPE信号;
  // 并检查是否有"-config"的默认参数,若存在,把它作为配置文件的名字,
  // 否则用执行文件的名字后缀上".json"作为配置文件的名字, 读取配置文件;
  // 依次执行初始化函数,循环驱动函数,与销毁函数,最后关闭日志
  // 其中每一步都记录到日志中.
  bool DoMain();
  
  // 退出
  void DoQuit() {
    Quit();
  }
  
protected:
  // 读取配置文件,默认的配置文件名为argv[0].json,与argv[0]在同一目录
  // 在Initialize()前执行
  // 若读取不成功要中止程序 时则应该返回false,此应用程序直接退出
  // 注意此时并不执行Destroy()
  virtual bool LoadConfig(const std::string& config_file);
  
  //在LoadConfig()后的第一个函数,用于初始,如创建连接等等
  // 若初始化不成功要中止程序 时则应该返回false,此应用程序将调用Destroy()后退出
  virtual bool Initialize();
  
  // 清理函数,在应用程序即将退出前执行.用来执行释放在initialize()中申请的
  //资源等工作.
  virtual bool Destroy();
  
  // 循环驱动函数
  virtual bool Run();

  // 退出
  virtual void Quit();

  // 内部循环驱动函数
  bool RunInternal( );

  
  folly::EventBase main_eb_;
  std::unique_ptr<TimerManager> timer_manager_;
  ConfigManager* config_manager_ {nullptr};
  std::string config_file_;
};
  
// 应用程序启动帮助类
template<class DAEMON>
int DoMain(int argc, char** argv) {
  folly::init(&argc, &argv, true);
  LogInitializer::Initialize(argv[0]);

  DAEMON daemon;
  return daemon.DoMain();
}
  
// 应用程序名
const char* GetInsanceName();

}

#endif	// NEBULA_BASE_BASE_DAEMON_H_

