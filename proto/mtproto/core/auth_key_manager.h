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

#ifndef PROTO_MTPROTO_CORE_AUTH_KEY_MANAGER_H_
#define PROTO_MTPROTO_CORE_AUTH_KEY_MANAGER_H_

#include <map>
#include <folly/Singleton.h>

#include "proto/mtproto/core/tl_types.h"

namespace mtproto {
  
class AuthKeyManager {
public:
  ~AuthKeyManager() = default;
  
  static std::shared_ptr<AuthKeyManager> GetInstance();
  
  std::shared_ptr<TLInt2048> FindAuthKey(int64_t auth_key_id) const;
  void SetAuthKey(const std::shared_ptr<TLInt2048>& auth_key, int64_t auth_key_id);
  
protected:
  friend class folly::Singleton<AuthKeyManager>;

  AuthKeyManager();

  std::map<int64_t, std::shared_ptr<TLInt2048>> auth_key_manager_;
};

}

#endif // PROTO_MTPROTO_CORE_AUTH_KEY_MANAGER_H_
