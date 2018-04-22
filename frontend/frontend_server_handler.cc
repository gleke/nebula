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

#include "frontend/frontend_server_handler.h"

#include "nebula/base/id_util.h"
#include "nebula/base/time_util.h"

#include "proto/mtproto/core/auth_key_manager.h"
#include "proto/mtproto/core/mtproto_schema.h"
#include "base/message_handler_util.h"

using namespace mtproto;

inline uint32_t GetServerID() {
  return 1;
}

///////////////////////////////////////////////////////////////////////////////////////
int FrontendServerHandler::OnNewConnectionCallback(nebula::TcpServiceBase* service, nebula::MTProtoPipeline* pipeline) {
  auto h = pipeline->getHandler<MTProtoHandler>();
  DCHECK(h);
  
  auto handler = std::make_shared<FrontendServerHandler>(service, pipeline, h->GetConnID());
  h->SetAttachData(handler);
  
  return handler->OnNewConnection();
}

int FrontendServerHandler::OnDataReceivedCallback(nebula::MTProtoPipeline* pipeline, std::unique_ptr<folly::IOBuf> message_data) {
  auto h = pipeline->getHandler<MTProtoHandler>();
  DCHECK(h);
  
  auto handler = h->CastByGetAttachData<FrontendServerHandler>();
  
  if (!handler) {
    LOG(ERROR) << "OnDataReceived - CastByGetAttachData";
    return -1;
  }
  
  return handler->OnDataReceived(std::forward<std::unique_ptr<folly::IOBuf>>(message_data));
}

int FrontendServerHandler::OnConnectionClosedCallback(nebula::TcpServiceBase* service, nebula::MTProtoPipeline* pipeline) {
  auto h = pipeline->getHandler<MTProtoHandler>();
  DCHECK(h);
  
  auto handler = h->CastByGetAttachData<FrontendServerHandler>();
  
  if (!handler) {
    LOG(ERROR) << "OnConnectionClosed - CastByGetAttachData";
    return -1;
  }
  
  return handler->OnConnectionClosed();
}

///////////////////////////////////////////////////////////////////////////////////////
int FrontendServerHandler::OnNewConnection() {
  state_ = State::CONNECTED;
  // TODO(@benqi):
  // 启动定时器，一段时间内如果没有收到任何消息，
  // 则认为可能是攻击数据包，关闭连接并记录审计日志IP
  return 0;
}

int FrontendServerHandler::OnDataReceived(std::unique_ptr<folly::IOBuf> message_data) {
  // TODO(@benqi): 后续处理如果比较复杂，可以使用状态机模式

  auto buf_length = message_data->computeChainDataLength();
  LOG(INFO) << "OnDataReceived - recv data, length = " << buf_length;
  
  // std::shared_ptr<MTProtoBase> mtproto;
  int rv = -1;
  do {
    // QuickAckSize
    if (buf_length == mtproto::kMTProtoQuickAckSize) {
      auto mtproto = std::make_shared<mtproto::MTProtoQuickAck>();
      if (!mtproto->ParseFromIOBuf(std::move(message_data))) {
        LOG(ERROR) << "OnDataReceived - read MTProto error!!!!";
        break;
      }
      OnMTProtoQuickAck(mtproto);
    } else if (buf_length < mtproto::kMTProtoMessageMinSize) {
      // 至少要读出auth_key_id
      LOG(ERROR) << "OnDataReceived - need " << kMTProtoMessageMinSize << ", but only recv len: " << buf_length;
      // ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - auth_key_id parser error!!!!"));
      break;
    } else {
      folly::io::Cursor c2(message_data.get());
      int64_t key_id = c2.readLE<int64_t>();
      
      if (key_id == 0) {
        if (buf_length < kMTProtoUnEncryptedHeaderSize) {
          LOG(ERROR) << "OnDataReceived - need " << kMTProtoUnEncryptedHeaderSize << ", but only recv len: " << buf_length;
          break;
        }
        auto mtproto = std::make_shared<MTProtoUnencryptedMessage>();
        if (!mtproto->ParseFromIOBuf(std::move(message_data))) {
          LOG(ERROR) << "OnDataReceived - read MTProto error!!!!";
          // ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - MTProtoUnencryptedMessage parser error!!!!"));
          break;
        }
        LOG(INFO) << "OnDataReceived - unencrypted message: " << mtproto->ToString();
        OnMTProtoUnencryptedMessage(mtproto);
      } else {
        LOG(INFO) << "OnDataReceived - recv key_id: " << key_id;
        if (buf_length < kMTProtoEncryptedHeaderSize) {
          LOG(ERROR) << "OnDataReceived - need " << kMTProtoEncryptedHeaderSize << ", but only recv len: " << buf_length;
          break;
        }
        
        // TODO(@benqi): 检查状态
        //
        if (auth_key_id_ == 0) {
          auto key = AuthKeyManager::GetInstance()->FindAuthKey(key_id);
          if (!key) {
            LOG(ERROR) << "OnDataReceived - Can't find key_id: " << key_id;
            // ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - auth_key_id error!!!!"));
            break;
          }
          auth_key_ = key;
          auth_key_id_ = key_id;
          
          // AuthKeyManager::GetInstance()->SetAuthKey(key, key_id);
        }
        
        auto mtproto = std::make_shared<MTProtoEncryptedMessage>(auth_key_, auth_key_id_);
        if (!mtproto->ParseFromIOBuf(std::move(message_data))) {
          LOG(ERROR) << "OnDataReceived - read MTProto error!!!!";
          // ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - MTProtoEncryptedMessage parser error!!!!"));
          break;
        }
        
        LOG(INFO) << "OnDataReceived - read encrypted message: " << mtproto->ToString();
        
        if (session_id_ == 0) {
          session_id_ = mtproto->session_id;
        } else if (session_id_ != mtproto->session_id) {
          LOG(ERROR) << "read - maybe session_id invalid, session_id is " << session_id_;
        }

        session_id_ = mtproto->session_id;
        OnMTProtoEncryptedMessage(mtproto);
      }
    }
    rv = 0;
  } while(0);

  return rv;
}

int FrontendServerHandler::OnConnectionClosed() {
/*
  if (state_ >= State::AUTH) {
    NotifyClientOffline();
  }
 */
  
  state_ = State::CLOSING;
  return 0;
}

void FrontendServerHandler::Close(int reason) {
  pipeline_->close();
}

void FrontendServerHandler::OnMTProtoQuickAck(std::shared_ptr<MTProtoQuickAck> mtproto) {
  LOG(INFO) << "read - recv QuickAckID";
}

void FrontendServerHandler::OnMTProtoUnencryptedMessage(std::shared_ptr<MTProtoUnencryptedMessage> mtproto) {
  // 首包处理
  if (is_first_message_) {
    // 如果首包是未加密消息，则走handshake流程
    state_ = State::HANDSHAKE;
    is_first_message_ = false;
    handshake_ = std::make_shared<HandshakeHandler>(this);
  }
  
  std::shared_ptr<TLObject> obj(TLObject::CreateObjectByIOBuf(mtproto->GetMessageData()));
  
  // TODO(@benqi): 数据包或状态有问题，关闭连接
  if (!obj) {
    LOG(ERROR) << "OnMTProtoUnencryptedMessage - not create object: ";
    return;
  }
  
  if (obj->GetClassID() == TL_msgs_ack::CLASS_ID) {
    On_TL_msgs_ack(obj);
    return;
  }
  
  // TODO(@benqi): 检查state
  TLObjectPtr result;
  
  switch (obj->GetClassID()) {
    case TL_req_pq::CLASS_ID :
    case TL_req_DH_params::CLASS_ID:
    case TL_set_client_DH_params::CLASS_ID:
      DCHECK(handshake_.get());
      DCHECK(state_==State::HANDSHAKE);
      result = handshake_->OnHandshake(obj);
      break;
    case TL_destroy_auth_key::CLASS_ID:
      result = On_TL_destroy_auth_key(obj);
      break;
    default:
      break;
  }
  
  if (!result) {
    LOG(ERROR) << "OnMTProtoUnencryptedMessage - ";
    return;
  }
  
  MTProtoUnencryptedMessage rsp(result);
  std::unique_ptr<folly::IOBuf> o;
  rsp.SerializeToIOBuf(o);
  pipeline_->write(std::move(o));
  
  // TODO(@benqi): delete handshake_
}

void FrontendServerHandler::OnMTProtoEncryptedMessage(std::shared_ptr<MTProtoEncryptedMessage> mtproto) {
  // 首包处理
  if (is_first_message_) {
    // conn_state_ = RPC_RUNNING;
    is_first_message_ = false;
  }
  
  if (state_ == State::AUTH_KEY_CREATED) {
    // TODO(@benqi): delete handshake
  }
  
  // auth_key_id_ = mtproto->auth_key_id;
  std::shared_ptr<TLObject> obj(TLObject::CreateObjectByIOBuf(mtproto->GetMessageData()));
  // TODO(@benqi): 数据包或状态有问题，关闭连接
  if (!obj) {
    LOG(ERROR) << "OnMTProtoEncryptedMessage - not create object: ";
    return;
  }
  
  
  try {
    LOG(INFO) << "OnMTProtoEncryptedMessage - recv tl_object: " << obj->ToString();
  } catch (std::exception& e) {
    int r=0;
    r = 1;
  } catch (...) {
    int r=0;
    r = 1;
  }

  if (obj->GetClassID() == TL_msgs_ack::CLASS_ID) {
    On_TL_msgs_ack(obj);
    return;
  }

  TLObjectPtr result;

  // frontend里处理System Message
  // decode处理
  switch (obj->GetClassID()) {
    case TL_ping::CLASS_ID :
      result = On_TL_ping(obj);
      break;
    case TL_ping_delay_disconnect::CLASS_ID :
      result = On_TL_ping_delay_disconnect(obj);
      break;
    case TL_destroy_session::CLASS_ID :
      result = On_TL_destroy_session(obj);
      break;
    case TL_get_future_salts::CLASS_ID :
      result = On_TL_get_future_salts(obj);
      break;
    case TL_rpc_drop_answer::CLASS_ID :
      result = On_TL_rpc_drop_answer(obj);
      break;

    case TL_contest_saveDeveloperInfo::CLASS_ID :
      result = On_TL_contest_saveDeveloperInfo(obj);
      break;
    case TL_invokeWithLayer::CLASS_ID:
      result = On_TL_invokeWithLayer(obj, mtproto->message_id, mtproto->seq_no);
      return;
      break;
    case TL_invokeAfterMsg::CLASS_ID:
      result = On_TL_invokeAfterMsg(obj, mtproto->message_id, mtproto->seq_no);
      return;
      break;
    case TL_msg_container::CLASS_ID :
      result = On_TL_msg_container(obj);
      break;
    case TL_gzip_packed::CLASS_ID:
      result = On_TL_gzip_packed(obj);
      break;
    // case TL_msgs_ack::CLASS_ID:
    //  result = On_TL_msgs_ack(obj);
    //  break;
      
    default:
      result = On_TL_api_message_request(obj, mtproto->message_id, mtproto->seq_no);
      return;
      // RPC
      break;
  }
  
  if (!result) {
    LOG(ERROR) << "OnMTProtoEncryptedMessage - ";
    return;
  }

  // session_id
  MTProtoEncryptedMessage rsp(auth_key_, auth_key_id_, session_id_, mtproto->seq_no, result);
  std::unique_ptr<folly::IOBuf> o;
  rsp.SerializeToIOBuf(o);
  pipeline_->write(std::move(o));
}

void FrontendServerHandler::On_TL_msgs_ack(TLObjectPtr msg) {
  // TODO(@beni): 暂时不实现
}

TLObjectPtr FrontendServerHandler::On_TL_destroy_auth_key(TLObjectPtr msg) {
  TLObjectPtr result;
  return result;
}

/*
 Request for several future salts
 The client may at any time request from the server several
 (between 1 and 64) future server salts together with their validity periods.
 Having stored them in persistent memory,
 the client may use them to send messages in the future even
 if he changes sessions (a server salt is attached to
 the authorization key rather than being session-specific).
 
 get_future_salts#b921bd04 num:int = FutureSalts;
 future_salt#0949d9dc valid_since:int valid_until:int salt:long = FutureSalt;
 future_salts#ae500895 req_msg_id:long now:int salts:vector future_salt = FutureSalts;
 The client must check to see that the response’s req_msg_id in fact
 coincides with msg_id of the query for get_future_salts.
 The server returns a maximum of num future server salts (may return fewer).
 The response serves as the acknowledgment of the query and does not require an acknowledgment itself.
 */
TLObjectPtr FrontendServerHandler::On_TL_get_future_salts(TLObjectPtr msg) {
  auto get_future_salts = std::static_pointer_cast<TL_get_future_salts>(msg);
  LOG(INFO) << "On_TL_get_future_salts - " << get_future_salts->ToString();
  
  // TODO(@benqi): 暂时不实现
  std::shared_ptr<TL_future_salts> future_salts;
  // = std::make_shared<TL_future_salts>();
  // TODO(@benqi): set_msg_id
  // pong->set_ping_id(ping_delay_disconnect->ping_id());
  return future_salts;
}

////////////////////////////////////////////////////////////////////////////////////////////
TLObjectPtr FrontendServerHandler::On_TL_ping_delay_disconnect(TLObjectPtr msg) {
  // TODO(@benqi): delay disconnect
  auto ping_delay_disconnect = std::static_pointer_cast<TL_ping_delay_disconnect>(msg);
  LOG(INFO) << "On_TL_ping_delay_disconnect - " << ping_delay_disconnect->ToString();
  
  auto pong = std::make_shared<TL_pong>();
  // TODO(@benqi): set_msg_id
  pong->set_ping_id(ping_delay_disconnect->ping_id());
  return pong;
}

TLObjectPtr FrontendServerHandler::On_TL_ping(TLObjectPtr msg) {
  auto ping = std::static_pointer_cast<TL_ping>(msg);

  LOG(INFO) << "On_TL_ping - " << ping->ToString();
  
  auto pong = std::make_shared<TL_pong>();
  pong->set_ping_id(ping->ping_id());
  return pong;
}

// Used by the client to notify the server
// that it may forget the data from a different session belonging to the same user (i. e. with the same auth_key_id).
// The result of this being applied to the current session is undefined.
TLObjectPtr FrontendServerHandler::On_TL_destroy_session(TLObjectPtr msg) {
  LOG(INFO) << "On_TL_destroy_session - " << msg->ToString();
  // r = On_TL_destroy_session(ctx, msg);
  auto destroy_session = std::static_pointer_cast<TL_destroy_session>(msg);
  auto destroy_session_ok = std::make_shared<TL_destroy_session_ok>();
  destroy_session_ok->set_session_id(destroy_session->session_id());
  return destroy_session_ok;
}

TLObjectPtr FrontendServerHandler::On_TL_contest_saveDeveloperInfo(TLObjectPtr msg) {
  auto contest_saveDeveloperInfo = std::static_pointer_cast<TL_contest_saveDeveloperInfo>(msg);
  contest_saveDeveloperInfo->vk_id();
  contest_saveDeveloperInfo->name();
  contest_saveDeveloperInfo->phone_number();
  contest_saveDeveloperInfo->age();
  contest_saveDeveloperInfo->city();
  
  auto rv = std::make_shared<TL_true>();
  return rv;
}

TLObjectPtr FrontendServerHandler::On_TL_invokeWithLayer(TLObjectPtr msg, int64_t message_id, int seq_no) {
  TLObjectPtr r;
  auto invoke_with_layer = std::static_pointer_cast<TL_invokeWithLayer>(msg);
  LOG(INFO) << "On_TL_invokeWithLayer - TL_invokeWithLayer's layer: " << invoke_with_layer->layer();
  
  auto x = invoke_with_layer->query();
  if (!x) {
    LOG(INFO) << "On_TL_invokeWithLayer - query is nil";
    return r;
  }
  
  LOG(INFO) << "On_TL_invokeWithLayer - TL_invokeWithLayer's query: " << invoke_with_layer->query()->ToString();
  On_TL_initConnection(invoke_with_layer->query(), message_id, seq_no);
  // r = OnRpcData(ctx, x);
  return r;
}

TLObjectPtr FrontendServerHandler::On_TL_invokeAfterMsg(TLObjectPtr msg, int64_t message_id, int seq_no) {
  TLObjectPtr r;
  auto invoke_after_msg = std::static_pointer_cast<TL_invokeAfterMsg>(msg);
  LOG(INFO) << "On_TL_invokeAfterMsg - TL_invokeAfterMsg layer: " << invoke_after_msg->msg_id();
  
  auto query = invoke_after_msg->query();
  if (!query) {
    LOG(INFO) << "On_TL_invokeAfterMsg - query is nil";
    return r;
  }
  
  LOG(INFO) << "On_TL_invokeAfterMsg - TL_invokeAfterMsg query: " << invoke_after_msg->query()->ToString();

  std::unique_ptr<folly::IOBuf> o;
  query->SerializeToIOBuf(o);
  
  auto rpc_request = std::make_shared<zproto::RpcRequest>(query->GetClassID(), std::move(o));
  
  //  if (encoded->GetMethodID() != CRC32("zproto.StartTestingAuthReq")) {
  //    LOG(ERROR) << "OnDataReceived － Will recv StartTestingAuthReq, method_id: " << CRC32("zproto.StartTestingAuthReq")
  //    << ", but recv a invalid method_id: " << encoded->ToString();
  //    Close(0);
  //    return 0;
  //  }
  
  // TODO(@benqi): S2SAttachData其它数据设置
  rpc_request->set_message_id(message_id);
  rpc_request->seq_num = seq_no;
  rpc_request->set_session_id(session_id_);
  rpc_request->set_birth_conn_id(conn_id_);
  rpc_request->set_birth_server_id(GetServerID());
  rpc_request->set_birth_track_uuid(GetNextIDBySnowflake());
  rpc_request->set_birth_timetick(NowInMsecTime());
  rpc_request->set_birth_remote_ip(pipeline_->getHandler<MTProtoHandler>()->GetRemoteAddress());
  rpc_request->set_birth_from("frontend_server");
  
  // TODO(@benqi): 借鉴RPC
  LOG(INFO) << "On_TL_invokeAfterMsg - will send rpc_request: " << rpc_request->ToString();
  WritePackage("messenger_client", rpc_request);
  return r;
}

void FrontendServerHandler::On_TL_initConnection(const mtproto::TLObject* query, int64_t message_id, int seq_no) {
  const mtproto::TL_initConnection* init_connections = dynamic_cast<const mtproto::TL_initConnection*>(query);
  LOG(INFO) << "On_TL_initConnection - dispatch query to messenger_client: " << init_connections->query()->ToString();

  std::unique_ptr<folly::IOBuf> o;
  init_connections->query()->SerializeToIOBuf(o);
  
  auto rpc_request = std::make_shared<zproto::RpcRequest>(init_connections->query()->GetClassID(), std::move(o));
  
  //  if (encoded->GetMethodID() != CRC32("zproto.StartTestingAuthReq")) {
  //    LOG(ERROR) << "OnDataReceived － Will recv StartTestingAuthReq, method_id: " << CRC32("zproto.StartTestingAuthReq")
  //    << ", but recv a invalid method_id: " << encoded->ToString();
  //    Close(0);
  //    return 0;
  //  }
  
  // TODO(@benqi): S2SAttachData其它数据设置
  rpc_request->set_message_id(message_id);
  rpc_request->seq_num = seq_no;
  rpc_request->set_session_id(session_id_);
  rpc_request->set_birth_conn_id(conn_id_);
  rpc_request->set_birth_server_id(GetServerID());
  rpc_request->set_birth_track_uuid(GetNextIDBySnowflake());
  rpc_request->set_birth_timetick(NowInMsecTime());
  rpc_request->set_birth_remote_ip(pipeline_->getHandler<MTProtoHandler>()->GetRemoteAddress());
  rpc_request->set_birth_from("frontend_server");
  
  // TODO(@benqi): 借鉴RPC
  LOG(INFO) << "On_TL_initConnection - will send rpc_request: " << rpc_request->ToString();
  WritePackage("messenger_client", rpc_request);
}

TLObjectPtr FrontendServerHandler::On_TL_msg_container(TLObjectPtr msg) {
  // TLObjectPtr result;
  TLObjectPtr rsp;
  
  auto msg_container = std::static_pointer_cast<TL_msg_container>(msg);
  
  LOG(INFO) << "On_TL_msg_container - " << msg_container->ToString();
  for (size_t i=0; i<msg_container->messages_size(); ++i) {
    auto message2 = msg_container->messages(i);
    LOG(INFO) << "On_TL_msg_container - message2: idx = " << i << ", ";//  << message2->ToString();
    
/*
    std::unique_ptr<folly::IOBuf> o;
    message2->body()->SerializeToIOBuf(o);
    
    auto rpc_request = std::make_shared<zproto::RpcRequest>(message2->body()->GetClassID(), std::move(o));
    
    //  if (encoded->GetMethodID() != CRC32("zproto.StartTestingAuthReq")) {
    //    LOG(ERROR) << "OnDataReceived － Will recv StartTestingAuthReq, method_id: " << CRC32("zproto.StartTestingAuthReq")
    //    << ", but recv a invalid method_id: " << encoded->ToString();
    //    Close(0);
    //    return 0;
    //  }
    
    // TODO(@benqi): S2SAttachData其它数据设置
    rpc_request->set_message_id(message2->msg_id());
    rpc_request->seq_num = message2->seqno();
    rpc_request->set_session_id(session_id_);
    rpc_request->set_birth_conn_id(conn_id_);
    rpc_request->set_birth_server_id(GetServerID());
    rpc_request->set_birth_track_uuid(GetNextIDBySnowflake());
    rpc_request->set_birth_timetick(NowInMsecTime());
    rpc_request->set_birth_remote_ip(pipeline_->getHandler<MTProtoHandler>()->GetRemoteAddress());
    rpc_request->set_birth_from("frontend_server");
    LOG(INFO) << "On_TL_api_message_request - will send rpc_request: " << rpc_request->ToString();
    // TODO(@benqi): 借鉴RPC
    WritePackage("messenger_client", rpc_request);
 */
    
    //    auto r = OnRpcData(ctx, message2->body());
//    if (r) {
//      if (r->GetClassID() == TL_auth_sentCode::CLASS_ID ||
//          r->GetClassID() == TL_auth_authorization::CLASS_ID ||
//          r->GetClassID() == TL_config::CLASS_ID) {
//        
//        auto rpc_result = std::make_shared<TL_rpc_result>();
//        rpc_result->set_req_msg_id(message2->msg_id());
//        rpc_result->set_result(r);
//        
//        auto r_mtproto = std::make_shared<MTProtoEncryptedMessage>(auth_key_,
//                                                                   auth_key_id_,
//                                                                   session_id_,
//                                                                   message2->seqno(),
//                                                                   rpc_result);
//        std::unique_ptr<folly::IOBuf> out;
//        r_mtproto->SerializeToIOBuf(out);
//        if (out) {
//          write(ctx, std::move(out));
//        }
//      } else {
//        auto r_mtproto = std::make_shared<MTProtoEncryptedMessage>(auth_key_,
//                                                                   auth_key_id_,
//                                                                   session_id_,
//                                                                   message2->seqno(),
//                                                                   r);
//        std::unique_ptr<folly::IOBuf> out;
//        r_mtproto->SerializeToIOBuf(out);
//        if (out) {
//          write(ctx, std::move(out));
//        }
//      }
//    }
  }
  return rsp;
  // return result;
}

TLObjectPtr FrontendServerHandler::On_TL_gzip_packed(TLObjectPtr msg) {
  TLObjectPtr result;
  return result;
}

TLObjectPtr FrontendServerHandler::On_TL_rpc_drop_answer(TLObjectPtr msg) {
  TLObjectPtr result;
  return result;
}

// main api
TLObjectPtr FrontendServerHandler::On_TL_api_message_request(TLObjectPtr msg, int64_t message_id, int seq_no) {
  LOG(INFO) << "On_TL_api_message_request - dispatch api to messenger_client: " << msg->ToString();

  TLObjectPtr result;

  std::unique_ptr<folly::IOBuf> o;
  msg->SerializeToIOBuf(o);
  
  auto rpc_request = std::make_shared<zproto::RpcRequest>(msg->GetClassID(), std::move(o));
  
//  if (encoded->GetMethodID() != CRC32("zproto.StartTestingAuthReq")) {
//    LOG(ERROR) << "OnDataReceived － Will recv StartTestingAuthReq, method_id: " << CRC32("zproto.StartTestingAuthReq")
//    << ", but recv a invalid method_id: " << encoded->ToString();
//    Close(0);
//    return 0;
//  }
  
  // TODO(@benqi): S2SAttachData其它数据设置
  rpc_request->set_message_id(message_id);
  rpc_request->seq_num = seq_no;
  rpc_request->set_session_id(session_id_);
  rpc_request->set_birth_conn_id(conn_id_);
  rpc_request->set_birth_server_id(GetServerID());
  rpc_request->set_birth_track_uuid(GetNextIDBySnowflake());
  rpc_request->set_birth_timetick(NowInMsecTime());
  rpc_request->set_birth_remote_ip(pipeline_->getHandler<MTProtoHandler>()->GetRemoteAddress());
  rpc_request->set_birth_from("frontend_server");
  LOG(INFO) << "On_TL_api_message_request - will send rpc_request: " << rpc_request->ToString();
  // TODO(@benqi): 借鉴RPC
  WritePackage("messenger_client", rpc_request);

  
  return result;
}

void FrontendServerHandler::OnMessengerClientDataArrived(std::shared_ptr<zproto::ProtoRpcResponse> message_data) {
  std::shared_ptr<mtproto::TLObject> rpc_result;
  
  if (message_data->GetPackageType() != zproto::RpcOk::HEADER) {
    // return;
    auto rpc_error = std::make_shared<mtproto::TL_rpc_error>();
    rpc_error->set_error_code(-1);
    if (message_data->GetPackageType() == zproto::RpcInternalError::HEADER) {
      rpc_error->set_error_code(-2);
    } else if (message_data->GetPackageType() == zproto::RpcError::HEADER) {
      rpc_error->set_error_code(std::static_pointer_cast<zproto::RpcError>(message_data)->error_code);
    }
    rpc_result = rpc_error;
  } else {
    auto rpc_ok = std::static_pointer_cast<zproto::RpcOk>(message_data);
    auto rpc_result2 = std::make_shared<mtproto::TL_rpc_result>();
    rpc_result2->set_req_msg_id(rpc_ok->req_message_id);
    auto obj = TLObjectFactory::CreateSharedInstance(rpc_ok->GetMethodResponseID());
    obj->ParseFromIOBuf(rpc_ok->body.get());
    
    LOG(INFO) << "OnMessengerClientDataArrived - rpc_ok: " << obj->ToString();

    rpc_result2->set_result(obj);
    rpc_result = rpc_result2;
  }
  
  MTProtoEncryptedMessage rsp(auth_key_,
                              auth_key_id_,
                              message_data->session_id(),
                              message_data->seq_num,
                              rpc_result);
  std::unique_ptr<folly::IOBuf> o;
  rsp.SerializeToIOBuf(o);
  pipeline_->write(std::move(o));
}

