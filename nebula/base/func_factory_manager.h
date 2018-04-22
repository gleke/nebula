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

#ifndef NEBULA_BASE_FUNC_FACTORY_MANAGER_H_
#define NEBULA_BASE_FUNC_FACTORY_MANAGER_H_

#include <string>
#include <unordered_map>

#include "nebula/base/logger/glog_util.h"

namespace nebula {
  
//////////////////////////////////////////////////////////////////////////
template<typename F, typename K=std::string>
class FuncFactoryManager {
public:
  ~FuncFactoryManager() {}
  
  struct RegisterTemplate {
    RegisterTemplate(const K& k, F f) {
      auto& factories = FuncFactoryManager<F, K>::GetInstance().factories_;
      auto it = factories.find(k);
      if (it != factories.end()) {
        LOG(ERROR) << "RegisterTemplate - duplicate entry for key: " << k;
      } else {
        // lambda表达式
        factories.emplace(k, f);
      }
    }
    
    explicit RegisterTemplate(F f) {
      auto& default_func = FuncFactoryManager<F, K>::GetInstance().default_func_;
      default_func = f;
    }
  };

  template<typename... Args>
  static bool Execute(const K& k, Args... args) {
    auto& factories = GetInstance().factories_;
    auto it = factories.find(k);
    if (it == factories.end()) {
      auto& default_f = GetInstance().default_func_;
      if (default_f) {
        default_f(args...);
        return true;
      } else {
        // TODO(@benqi): 是否需要抛出异常？
        LOG(ERROR) << "Execute - not exist func key: " << k;
        return false;
      }
    } else {
      it->second(args...);
      return true;
    }
  }

  // 执行类成员函数
  template<typename C, typename... Args>
  static bool Execute2(C* c, const K& k, Args... args) {
    auto& factories = GetInstance().factories_;
    auto it = factories.find(k);
    if (it == factories.end()) {
      auto& default_f = GetInstance().default_func_;
      if (default_f) {
        (c->*default_f)(args...);
        return true;
      } else {
        // TODO(@benqi): 是否需要抛出异常？
        LOG(ERROR) << "Execute2 - not exist func key: " << k;
        return false;
      }
    } else {
      // TODO(@benqi): 是否需要抛出异常？
      (c->*it->second)(args...);
      return true;
    }
  }

  // 有返回值
  template<typename... Args>
  static typename std::result_of<F(Args... args)>::type Execute3(const K& k, Args... args) {
    auto& factories = GetInstance().factories_;
    auto it = factories.find(k);
    if (it == factories.end()) {
      LOG(ERROR) << "Execute3 - not exist func key: " << k;
    } else {
    }
    
    return it->second(args...);
  }

  // 检查是K否存在
  static bool Check(const K& k) {
    auto& factories = GetInstance().factories_;
    return factories.find(k) != factories.end();
  }
  
private:
  FuncFactoryManager() = default;
  FuncFactoryManager(const FuncFactoryManager&) = delete;
  FuncFactoryManager(FuncFactoryManager&&) = delete;
  
  static FuncFactoryManager& GetInstance() {
    static FuncFactoryManager g_func_factorys;
    return g_func_factorys;
  }
  
  std::unordered_map<K, F> factories_;
  F default_func_;      // 默认
};

// template<class F, class K>
// using FuncRegister = FuncFactoryManager<F, K>::RegisterTemplate;

}

#endif // NEBULA_BASE_FUNC_FACTORY_MANAGER_H_

