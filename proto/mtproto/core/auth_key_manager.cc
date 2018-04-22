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

#include "proto/mtproto/core/auth_key_manager.h"

#include <folly/FileUtil.h>

#define AUTH_KEY_SIZE 264
#define AUTH_KEY_FILE "/Users/benqi/Github/nebula-im/out/imengine/bin/Debug/auth_key.dat"

using namespace mtproto;
  
static folly::Singleton<AuthKeyManager> g_auth_key_manager;

AuthKeyManager::AuthKeyManager() {
  folly::fbstring auth_key_data;
  if(folly::readFile(AUTH_KEY_FILE, auth_key_data)) {
    int size = auth_key_data.length() / AUTH_KEY_SIZE;
    for (int i=0; i<size; ++i) {
      int64_t k_id;
      auto k = std::make_shared<TLInt2048>();
      k->Copy((const uint8_t *)auth_key_data.c_str()+i*AUTH_KEY_SIZE);
      memcpy(&k_id, auth_key_data.data()+i*AUTH_KEY_SIZE+256, 8);
      auth_key_manager_.insert(std::make_pair(k_id, k));
      LOG(INFO) << "AuthKeyManager - kid ==> " << k_id;
    }
  }
}

std::shared_ptr<AuthKeyManager> AuthKeyManager::GetInstance() {
  return g_auth_key_manager.try_get();
}

std::shared_ptr<TLInt2048> AuthKeyManager::FindAuthKey(int64_t auth_key_id) const {
  std::shared_ptr<TLInt2048> k;
  auto it = auth_key_manager_.find(auth_key_id);
  if (it != auth_key_manager_.end()) {
    k = it->second;
  }
  return k;
}

void AuthKeyManager::SetAuthKey(const std::shared_ptr<TLInt2048>& auth_key, int64_t auth_key_id) {
  auth_key_manager_[auth_key_id] = auth_key;
  
  folly::fbstring keys_data;
  for (auto it=auth_key_manager_.begin(); it!=auth_key_manager_.end(); ++it) {
    keys_data.append((const char*)it->second->data, 256);
    keys_data.append((const char*)&(it->first), 8);
    
    LOG(INFO) << "SetAuthKey - kid ==> " << it->first;
  }
  
  folly::writeFile(keys_data, AUTH_KEY_FILE);
}
