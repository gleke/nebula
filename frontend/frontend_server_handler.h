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

#ifndef	FRONTEND_FRONTEND_SERVER_HANDLER_H_
#define	FRONTEND_FRONTEND_SERVER_HANDLER_H_

#include <folly/io/async/EventBase.h>

#include "nebula/net/handler/nebula_base_handler.h"
#include "nebula/net/handler/mtproto/mtproto_handler.h"
#include "nebula/net/zproto/zproto_package_data.h"

#include "proto/mtproto/core/mtproto_message.h"
#include "frontend/handshake_handler.h"

// 客户端连接成功后
// 1. 10秒内没收到数据包则断开
// 2. 收到的第一个包必须是用户认证包
// 3. 认证包转发给auth服务器处理
// 4. 认证必须在15秒内返回
// 5. 认证成功后通知状态服务器客户端上线
// 6. 通知成功后返回后认证成功
// 7. 可以接收客户端消息
// 8. 收到消息后转发给router
class FrontendServerHandler : public nebula::ConnAttachData, public HandshakeHandler::Callback {
public:
  FrontendServerHandler(nebula::TcpServiceBase* service, nebula::MTProtoPipeline* pipeline, uint64_t conn_id)
    : service_(service),
      pipeline_(pipeline),
      conn_id_(conn_id) {}
  
  
  virtual ~FrontendServerHandler() = default;

  enum class State : int {
    NONE = 0,
    CONNECTED = 1,
    HANDSHAKE = 2,
    // WAIT_req_pq = 3,                // Handshake
    // WAIT_req_DH_params = 4,         // Handshake
    // WAIT_set_client_DH_params = 5,  // Handshake
    // data
    AUTH_KEY_CREATED = 6,
    FORWARD_TO_STATUS = 7,
    WORKING = 8,
    CLOSING = 9,
    ERROR = 10
  };

  // MTProtoEventCallback
  static int OnNewConnectionCallback(nebula::TcpServiceBase* service, nebula::MTProtoPipeline* pipeline);
  static int OnDataReceivedCallback(nebula::MTProtoPipeline* pipeline, std::unique_ptr<folly::IOBuf> message_data);
  static int OnConnectionClosedCallback(nebula::TcpServiceBase* service, nebula::MTProtoPipeline* pipeline);
    
  ///////////////////////////////////////////////////////////////////////////////////////
  virtual void OnAuthKeyCreated(std::shared_ptr<mtproto::TLInt2048> key, int64_t key_id) {
    auth_key_ = key;
    auth_key_id_ = key_id;
    
    state_ = State::AUTH_KEY_CREATED;
  }

  // TODO(@benqi): 支持异步关闭
  void Close(int resaon);

  // messenger_client_handler
  void OnMessengerClientDataArrived(std::shared_ptr<zproto::ProtoRpcResponse> message_data);
    
protected:
    ///////////////////////////////////////////////////////////////////////////////////////
    int OnNewConnection();
    int OnDataReceived(std::unique_ptr<folly::IOBuf> message_data);
    int OnConnectionClosed();
    
    bool IsHandshaking() const {
      return state_ == State::HANDSHAKE;
    }
    
    // OnMTProto
    void OnMTProtoQuickAck(std::shared_ptr<mtproto::MTProtoQuickAck> mtproto);
    void OnMTProtoUnencryptedMessage(std::shared_ptr<mtproto::MTProtoUnencryptedMessage> mtproto);
    void OnMTProtoEncryptedMessage(std::shared_ptr<mtproto::MTProtoEncryptedMessage> mtproto);

    //
    void On_TL_msgs_ack(mtproto::TLObjectPtr msg);
    
    // handshake
    // TLObjectPtr On_TL_req_pq(TLObjectPtr msg);
    // TLObjectPtr On_TL_req_DH_params(TLObjectPtr msg);
    // TLObjectPtr On_TL_set_client_DH_params(TLObjectPtr msg);
    mtproto::TLObjectPtr On_TL_destroy_auth_key(mtproto::TLObjectPtr msg);
    
    // Service Messages
    mtproto::TLObjectPtr On_TL_rpc_drop_answer(mtproto::TLObjectPtr msg);
    
    mtproto::TLObjectPtr On_TL_get_future_salts(mtproto::TLObjectPtr msg);
    mtproto::TLObjectPtr On_TL_destroy_session(mtproto::TLObjectPtr msg);
    mtproto::TLObjectPtr On_TL_contest_saveDeveloperInfo(mtproto::TLObjectPtr msg);

    mtproto::TLObjectPtr On_TL_invokeWithLayer(mtproto::TLObjectPtr msg, int64_t message_id, int seq_no);
    // invokeAfterMsg#cb9f372d {X:Type} msg_id:long query:!X = X;
    mtproto::TLObjectPtr On_TL_invokeAfterMsg(mtproto::TLObjectPtr msg, int64_t message_id, int seq_no);
    // invokeAfterMsgs#3dc4b4f0 {X:Type} msg_ids:Vector<long> query:!X = X;
    // mtproto::TLObjectPtr On_TL_invokeAfterMsgs(mtproto::TLObjectPtr msg, int64_t message_id, int seq_no);
    // invokeWithoutUpdates#bf9459b7 {X:Type} query:!X = X;
    // mtproto::TLObjectPtr On_TL_invokeWithoutUpdates(mtproto::TLObjectPtr msg, int64_t message_id, int seq_no);

    void On_TL_initConnection(const mtproto::TLObject* query, int64_t message_id, int seq_no);
    mtproto::TLObjectPtr On_TL_msg_container(mtproto::TLObjectPtr msg);
    mtproto::TLObjectPtr On_TL_gzip_packed(mtproto::TLObjectPtr msg);

    mtproto::TLObjectPtr On_TL_ping(mtproto::TLObjectPtr msg);
    mtproto::TLObjectPtr On_TL_ping_delay_disconnect(mtproto::TLObjectPtr msg);

    // main api
    mtproto::TLObjectPtr On_TL_api_message_request(mtproto::TLObjectPtr msg, int64_t message_id, int seq_no);
    
    ///////////////////////////////////////////////////////////////////////////////////
    nebula::TcpServiceBase* service_ {nullptr};
    nebula::MTProtoPipeline* pipeline_ {nullptr};
    uint64_t conn_id_ {0};

    State state_ {State::NONE};
    
  // 用户基本信息
  // TODO(@benqi): 缓存更多的用户数据
    bool is_first_message_ {true};
    
    ///////////////////////////////////////////////////////////////////////////////////
    std::shared_ptr<mtproto::TLInt2048> auth_key_;
    int64_t auth_key_id_ {0};
    
    std::shared_ptr<HandshakeHandler> handshake_;
    
    int64_t session_id_ {0};
};

#endif // FRONTEND_FRONTEND_SERVER_HANDLER_H_

