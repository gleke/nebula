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

#ifndef NUBULA_NET_HANDLER_ZPROTO_ZPROTO_HANDLER_H_
#define NUBULA_NET_HANDLER_ZPROTO_ZPROTO_HANDLER_H_

// #include "nebula/net/zproto/zproto_package_data.h"

#include "nebula/net/telegram/core/mtproto_message.h"
#include "nebula/net/handler/nebula_base_handler.h"
#include "nebula/net/handler/nebula_event_callback.h"

// using ZProtoPipeline = wangle::Pipeline<folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>>;

// #include "nebula/net/handler/nebula_event_callback.h"

// using TeamtalkPipeline = wangle::Pipeline<folly::IOBufQueue&, std::shared_ptr<teamtalk::PackageMessage>>;

using TelegramEventCallback = NebulaEventCallback<nebula::ZProtoPipeline, std::shared_ptr<MTProtoBase>>;

class MTProtoDecoder;
class TelegramHandler : public wangle::HandlerAdapter<std::shared_ptr<MTProtoBase>, std::unique_ptr<folly::IOBuf>>, public nebula::NebulaBaseHandler {
public:
  enum ConnState {
    NONE = 0,
    CONNECTED,                     // 连接建立
    WAIT_TL_req_pq,                // 等TL_req_pq
    WAIT_TL_req_DH_params,         // 等req_DH_params
    WAIT_TL_set_client_DH_params,  // 等TL_set_client_DH_params
    RPC_RUNNING,                    // 可以running
    CLOSED,
    ERROR
  };

  explicit TelegramHandler(nebula::ServiceBase* service)
    : NebulaBaseHandler(service) {
    // a_ = BN_new();
    // DCHECK(a_);
  }

  virtual ~TelegramHandler() {
    if (a_) BN_free(a_);
    if (p_) BN_free(p_);
  }
  
  //////////////////////////////////////////////////////////////////////////
  // 重载 HandlerAdapter<std::unique_ptr<IOBuf>>
  void read(Context* ctx, std::shared_ptr<MTProtoBase> msg) override;
  folly::Future<folly::Unit> write(Context* ctx, std::unique_ptr<folly::IOBuf> out) override;
  
  void readEOF(Context* ctx) override;
  void readException(Context* ctx, folly::exception_wrapper e) override;
  
  void transportActive(Context* ctx) override;
  void transportInactive(Context* ctx) override;
  
  folly::Future<folly::Unit> close(Context* ctx) override;
  
  const TLInt2048& GetAuthKey() const {
    return auth_key_;
  }

  int64_t GetAuthKeyID() const {
    return auth_key_id_;
  }

private:
  void OnHandshake(Context* ctx, std::shared_ptr<MTProtoBase> msg);
  
  void On_TL_req_pq(Context* ctx, std::shared_ptr<MTProtoBase> mtproto);
  void On_TL_req_DH_params(Context* ctx, std::shared_ptr<MTProtoBase> mtproto);
  void On_TL_set_client_DH_params(Context* ctx, std::shared_ptr<MTProtoBase> mtproto);

  void OnRpcData(Context* ctx, std::shared_ptr<MTProtoBase> msg);

  // TODO(@benqi): s2s应用场景里，连接发起方需要保活，逻辑基本一样，
  //  后续zrpc_client_handler/zproto_handler等统一处理
  static void DoHeartBeat(uint64_t conn_id, uint32_t timeout);
  
  uint64_t conn_id_ {0};
  int conn_state_ {NONE};
  
  std::string remote_address_;
  
  // 客户端发上来的
  TLInt128 nonce_;
  // 服务端生成的
  TLInt128 server_nonce_;
  TLInt256 new_nonce_;

  // TLString g_a_;
  BIGNUM *a_ {nullptr}; //  = BN_new();
  BIGNUM *p_ {nullptr}; //  = BN_new();
  // DCHECK(g_a);

  TLInt2048 auth_key_;
  int64_t auth_key_id_;
  // _nonce_;

  // MTProtoDecoder* mtproto_decoder_ {nullptr};
  
  bool first_recved_ {true};
};

void ModuleTelegramInitialize();

#endif


#if 0
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

#ifndef NET_TELEGRAM_TELEGRAM_HANDLER_H_
#define NET_TELEGRAM_TELEGRAM_HANDLER_H_

#include <string>
#include <wangle/channel/AsyncSocketHandler.h>

#include <wangle/channel/Pipeline.h>

#include "nebula/net/engine/tcp_service_base.h"

#include "nebula/net/telegram/core/mtproto_message.h"

#include "nebula/net/handler/telegram/telegram_handshake_handler.h"
#include "nebula/net/handler/telegram/telegram_rpc_handler.h"

// class TcpServiceBase;
using TelegramPipeline = wangle::Pipeline<folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>>;

// 使用AttachData存储连接附加数据
// 比如用户名等
struct ConnAttachData {
  virtual ~ConnAttachData() = default;
};

typedef std::shared_ptr<ConnAttachData> ConnAttachDataPtr;

class TelegramHandler : public wangle::HandlerAdapter<std::shared_ptr<MTProtoBase>, std::unique_ptr<folly::IOBuf>> {
public:
  enum ConnState {
    NONE = 0,
    CONNECTED,                     // 连接建立
    WAIT_TL_req_pq,                // 等TL_req_pq
    WAIT_TL_req_DH_params,         // 等req_DH_params
    WAIT_TL_set_client_DH_params,  // 等TL_set_client_DH_params
    RPC_RUNNING,                    // 可以running
    CLOSED,
    ERROR
  };
  
  explicit TelegramHandler(nebula::ServiceBase* service)
    : service_(dynamic_cast<nebula::TcpServiceBase*>(service)),
      conn_id_(0),
      conn_state_(NONE) {
  }
  
  //////////////////////////////////////////////////////////////////////////
  inline nebula::TcpServiceBase* GetServiceBase() {
    return service_;
  }
  
  inline ConnAttachData* GetAttachData() {
    return attach_data_.get();
  }
  
  //////////////////////////////////////////////////////////////////////////
  template <class T>
  inline T* CastByGetAttachData() {
    return nullptr;
  }
  
  template <class T>
  inline typename std::enable_if<std::is_base_of<ConnAttachData, T>::value>::type*
  CastByGetAttachData() {
    return dynamic_cast<T*>(attach_data_.get());
  }
  
  inline void SetAttachData(const std::shared_ptr<ConnAttachData>& v) {
    attach_data_ = v;
  }
  
  inline uint64_t GetConnID() const {
    return conn_id_;
  }
  
  //////////////////////////////////////////////////////////////////////////
  // 重载 HandlerAdapter<std::unique_ptr<IOBuf>>
  void read(Context* ctx, std::shared_ptr<MTProtoBase> msg) override;
  folly::Future<folly::Unit> write(Context* ctx, std::unique_ptr<folly::IOBuf> out) override;
  
  void readEOF(Context* ctx) override;
  void readException(Context* ctx, folly::exception_wrapper e) override;
  
  void transportActive(Context* ctx) override;
  folly::Future<folly::Unit> close(Context* ctx) override;
  
  inline const std::string& GetRemoteAddress() const {
    return remote_address_;
  }
  
protected:
  void OnHandshake(Context* ctx, std::shared_ptr<MTProtoBase> mtproto);
  
  void On_TL_req_pq(Context* ctx, std::shared_ptr<MTProtoBase> mtproto);
  void On_TL_req_DH_params(Context* ctx, std::shared_ptr<MTProtoBase> mtproto);
  void On_TL_set_client_DH_params(Context* ctx, std::shared_ptr<MTProtoBase> mtproto);
  
  // 全局的
  nebula::TcpServiceBase* service_{nullptr};
  std::shared_ptr<ConnAttachData> attach_data_;
  
  uint64_t conn_id_;
  int conn_state_ {kNone};
  
  std::string remote_address_;

  // 客户度啊安发上来的
  TLInt128 nonce_;
  // 服务端生成的
  TLInt128 server_nonce_;
  
  TLInt256 new_nonce_;
  
  TLString g_a_;

};

#endif
#endif
