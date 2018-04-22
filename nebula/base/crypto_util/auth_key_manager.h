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

#ifndef NEBULA_BASE_CRYPTO_UTIL_AUTH_KEY_MANAGER_H_
#define NEBULA_BASE_CRYPTO_UTIL_AUTH_KEY_MANAGER_H_

#include <map>
#include <folly/Singleton.h>

#include ""
class AuthKeyManager {
public:
  ~AuthKeyManager() = default;
  
  static AuthKeyManager* GetInstance();
  
  const std::shared_ptr<TLIntN2048> FindAuthKey(int64_t auth_key_id) const;
  void SetAuthKey(const std::shared_ptr<TLIntN2048> auth_key, int64_t auth_key_id);
  
protected:
  AuthKeyManager();
  friend class folly::Singleton<AuthKeyManager>;

  std::map<int64_t, std::shared_ptr<TLIntN2048>> auth_key_manager_;
};
#endif
