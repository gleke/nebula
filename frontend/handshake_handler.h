/*
 *  Copyright (c) 2016, https://github.com/nebula-im/imengine
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

#ifndef	FRONTEND_FRONTEND_HANDSHAKE_HANDLER_H_
#define	FRONTEND_FRONTEND_HANDSHAKE_HANDLER_H_

#include "nebula/base/crypto_util/crypto_util.h"
#include "proto/mtproto/core/tl_object.h"

// TODO(@benqi): error处理

class HandshakeHandler {
public:
  class Callback {
  public:
    virtual ~Callback() = default;
    
    virtual void OnAuthKeyCreated(std::shared_ptr<mtproto::TLInt2048> key, int64_t key_id) {}
  };
  
  enum class HandshakeState : int {
    NONE = 0,
    WAIT_REQ_PQ = 1,                // Handshake
    WAIT_REQ_DH_PARAMS = 2,         // Handshake
    WAIT_SET_CLIENT_DH_PARAMS = 3,  // Handshake
    CREATED = 4,                    // Handshake
    ERROR = 10
  };

  explicit HandshakeHandler(Callback* cb)
    : cb_(cb) {}
  
  ~HandshakeHandler() {}
  
  mtproto::TLObjectPtr OnHandshake(mtproto::TLObjectPtr req);
  
  bool IsAuthKeyCreated() const {
    return state_ == HandshakeState::CREATED;
  }
  
  std::pair<std::shared_ptr<mtproto::TLInt2048>, int64_t> GetAuthKey() const {
    return std::make_pair(auth_key_, auth_key_id_);
  }
  
private:
  mtproto::TLObjectPtr On_TL_req_pq(mtproto::TLObjectPtr msg);
  mtproto::TLObjectPtr On_TL_req_DH_params(mtproto::TLObjectPtr msg);
  mtproto::TLObjectPtr On_TL_set_client_DH_params(mtproto::TLObjectPtr msg);

  // 客户端发上来的
  mtproto::TLInt128 nonce_;
  // 服务端生成的
  mtproto::TLInt128 server_nonce_;
  mtproto::TLInt256 new_nonce_;
  
  // TLString g_a_;
  BIGNUM *a_ {nullptr}; //  = BN_new();
  BIGNUM *p_ {nullptr}; //  = BN_new();
  // DCHECK(g_a);
  
  std::shared_ptr<mtproto::TLInt2048> auth_key_;
  int64_t auth_key_id_ {0};
  
  HandshakeState state_ {HandshakeState::NONE};
  Callback* cb_ {nullptr};
};

#endif
