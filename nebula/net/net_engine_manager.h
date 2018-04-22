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

#ifndef NEBULA_NET_NET_ENGINE_MANAGER_H_
#define NEBULA_NET_NET_ENGINE_MANAGER_H_

#include <unordered_map>

#include <folly/Singleton.h>
#include <folly/futures/Future.h>

#include "nebula/net/thread_group_list_manager.h"
#include "nebula/net/base/service_base.h"

namespace nebula {
  
//////////////////////////////////////////////////////////////////////////////
class NetEngineManager {
public :
  ~NetEngineManager() = default;
  
  static std::shared_ptr<NetEngineManager> GetInstance();
  
  void set_thread_groups(const std::shared_ptr<ThreadGroupListManager>& thread_groups);
  
  void SetupService(const ServicesConfig& config);
  
  // 安装服务
  // 服务启用前必须要先安装
  void Install(const std::string& name, const std::string& type, const std::string& proto);
  
  bool Start();
  bool Pause();
  bool Stop();
    
  folly::EventBase* GetEventBaseByThreadType(ThreadType thread_type) const {
    return thread_groups_->GetEventBaseByThreadType(thread_type);
  }
  
  folly::EventBase* GetEventBaseByThreadID(size_t idx) const {
    return thread_groups_->GetEventBaseByThreadID(idx);
  }
  
  std::shared_ptr<wangle::IOThreadPoolExecutor> GetIOThreadPoolExecutor(ThreadType thread_type) const {
    return thread_groups_->GetIOThreadPoolExecutor(thread_type);
  }
  
  ThreadGroupPtr GetThreadGroupByThreadType(ThreadType thread_type) const {
    return thread_groups_->GetThreadGroupByThreadType(thread_type);
  }
  
  ///////////////////////////////////////////////////////////////////////////////////////////////
  size_t thread_datas_size() const {
    return thread_groups_->thread_datas().size();
  }
  
  const ThreadData& thread_datas(size_t i) const {
    return thread_groups_->thread_datas()[i];
  }
  
  std::shared_ptr<ServiceBase> Lookup(const std::string& service_name);

protected:
  friend struct WriterUtil;
  ServiceBasePtr CreateService(const ServiceConfig& service_config) const;
  
  ServiceConfigPtr LookupServiceConfig(const std::string& name,
                                       const std::string& type,
                                       const std::string& proto) const;
  
  friend class folly::Singleton<NetEngineManager>;
  NetEngineManager() = default;
  
  bool RegisterServiceBase(std::shared_ptr<ServiceBase> service);
  // std::shared_ptr<ServiceBase> Lookup(const std::string& service_name);
  
  // 如果是client，则ServiceBase为分组ClientGroup
  // 添加的时候要处理分组
  // TODO(@benqi): 使用树来管理，后续还要加连接池
  typedef std::unordered_map<std::string, std::shared_ptr<ServiceBase>> ServiceInstanceMap;
  ServiceInstanceMap services_;

  std::shared_ptr<ThreadGroupListManager> thread_groups_;
  
  // 即将运行的，从Install来
  typedef std::vector<std::pair<std::shared_ptr<ServiceConfig>, std::shared_ptr<wangle::IOThreadPoolExecutor>>> InstalledServiceInfoList;
  InstalledServiceInfoList installeds_;
  
  // 配置文件里
  // ServiceFactoryManager service_factory_manager_;
  std::vector<ServiceConfigPtr> service_configs_;
};
  
inline std::string ToString(uint64_t conn_id) {
  return folly::sformat("[conn_id={}, thread_idx={}, conn_idx={}]", conn_id, conn_id>>32, conn_id & 0xffffffff);
}

}

#endif

