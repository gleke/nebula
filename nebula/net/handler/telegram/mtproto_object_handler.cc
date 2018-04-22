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

#include "nebula/net/handler/telegram/mtproto_object_handler.h"

#include <openssl/sha.h>

#include "nebula/base/time_util.h"
#include "nebula/base/crypto_util/dh_util.h"
#include "nebula/net/telegram/core/mtproto_schema.h"

#include "nebula/net/engine/tcp_server.h"
#include "nebula/net/thread_local_conn_manager.h"

#include "nebula/net/handler/telegram/telegram_pipeline_factory.h"

#include "nebula/net/telegram/core/auth_key_manager.h"

using namespace nebula;

void ModuleTelegramInitialize() {
  static ServiceSelfRegisterTemplate g_reg_telegram_tcp_server(std::make_pair("tcp_server", "telegram"),
                                                             [](const ServiceConfig& service_config, const std::shared_ptr<wangle::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
                                                               auto service = std::make_shared<TcpServer<TelegramPipeline>>(service_config, io_group);
                                                               auto factory = std::make_shared<TelegramServerPipelineFactory>(service.get());
                                                               service->SetChildPipeline(factory);
                                                               return service;
                                                             });
}


// 2048位
// 测试私钥证书
static const std::string g_test_private_key =  "-----BEGIN RSA PRIVATE KEY-----\n"
                                        "MIIEpQIBAAKCAQEAtUXgOV7DZ1d9M08gYVOMU/fenTbbLU12b1LoL9sYfRycEpF4\n"
                                        "aqA9RW0rPfzY6yZkfTlQdoFaGxVpUiNMv5V3xY+aVoFQbT7rlsevE87tHK90yG1O\n"
                                        "YyslV7IJiCy/tLu/2DVhbZqg4fgPjs4XYrt7CABmsy/OtHJy6A9I1qPQ40MlSB21\n"
                                        "lmAQI9gKHBc2BGZCvQ/NDj1elun9Qitf3ziH8g/Xsxv18CO8hAev56FUMIFzMtGO\n"
                                        "mhpJDAkQ+zg22yLlxKuxjkWSEkYYzHgzrCiDfqcfSkG34veRdD9CGnLsIPvHtTFV\n"
                                        "/+b05xTUyQxFzZ3kOl41KsTY9OsebYxYThHbTQIDAQABAoIBACI5KAUMzA11qhCG\n"
                                        "ztExKdwsft3lnmmmJ0cLOwTV84CjZx/mUPqoeAjkfHZ+hyGWJQCzUmqdLzrPxwuX\n"
                                        "2ISPHoaw/u14Cowlher4lihCN+fjhEPWxybX3Xv6A+yurh7cF3MlWNiNifQ/lghb\n"
                                        "BnVAehDfqoQH8ZmFxgXj5NeJJAXTtNhRvG8suD1AYY+cRmSzoEyu1mMt3RnSnKDJ\n"
                                        "zvaXNJnWHOVvV5pVLQFNI8UrO+pnyyJ1tWVzhOqzTSlNLULntQNConWHnmmEqlNz\n"
                                        "fxLCCu9ICu+mM5PYLTTg2Jy5K7Og2Jg3CITjWZoLrQmirXu/jkG6xNa60FMAlInv\n"
                                        "nR5yv40CgYEA6cBain4pDtzEw0E4X/rnYa6jmO3nuoNuKtEwlICQhJ+DL1mpcHtp\n"
                                        "vTE7deKMKNCnQbwLHw8+K+6SY8+oQzOkQ1t1fkL4U9RLKwJzFesXHsn3nIXam5Kq\n"
                                        "znsHX+3ikxmUPWUYKOSDeB9TacShSFW1czUalsH1BYnh9XTQ3Q3W388CgYEAxobR\n"
                                        "vUXVZpPYBh2O83rQxV3O5Pxj8+fKuaVrmkN8jz/fQit4AOE7CQRrlMgL5gHyCbEv\n"
                                        "1ap/NQH7gq5BYR/e+EFeooV11qoAj1CyPbcdEatVhkp49ijzwFLzXjiG/KwGb77R\n"
                                        "wlOQtMKD4jUGbudtatlWmcO2C3N1a7UiX2vZHiMCgYEAwNkumbYOP7HKL+D+FsmU\n"
                                        "3dVMKZ6VoR5P5MljkBElqhVEEOujTCa1jR4yFUcMJZxHcYcnkb9spqgUZH5tLsxL\n"
                                        "SDsLi1jLMbYjMd+6fSnQkFlGjP8t5U4y11lPM0i6tmvTDnf6X7pv8Mm/crKD8X6s\n"
                                        "zdjRD/IDKUehgXWX39hMH6cCgYEAi7klcs3shLZ3Ks6w5qJAvzfnvnf4LRitMH3B\n"
                                        "PqBS0UtF6X9IhW3/q7gFs4AcB7TE0Zd4MCxAPWF4z5+u+hmBRz5SyZWeuweJP1Sv\n"
                                        "Lgprlhz9I3fUrINkEq8PA/hK4Rh9qzYk0V0ZEm94fMOPFI0jEDmI3s3EmUiYksa4\n"
                                        "O2pfM/sCgYEAib7YGOWXfH5upVjUW2hFVRpscGDr0IRrg2YapMO/kwLMN722bQAJ\n"
                                        "/Rm6q9u1ZOGkttau+9Sl7bhhtFOpuJp8VkkhvvG7zxGslqXE3yge0vebw6Z9vFbw\n"
                                        "U3OKFv5x4j/CrQpw6vCi1gTmZSSEMhDgG/7Niu7YP6ruoKdl8cTDEcs=\n"
                                        "-----END RSA PRIVATE KEY-----\n";

// 测试公钥证书
static const std::string g_test_public_key =   "-----BEGIN RSA PUBLIC KEY-----\n"
                                        "MIIBCgKCAQEAtUXgOV7DZ1d9M08gYVOMU/fenTbbLU12b1LoL9sYfRycEpF4aqA9\n"
                                        "RW0rPfzY6yZkfTlQdoFaGxVpUiNMv5V3xY+aVoFQbT7rlsevE87tHK90yG1OYysl\n"
                                        "V7IJiCy/tLu/2DVhbZqg4fgPjs4XYrt7CABmsy/OtHJy6A9I1qPQ40MlSB21lmAQ\n"
                                        "I9gKHBc2BGZCvQ/NDj1elun9Qitf3ziH8g/Xsxv18CO8hAev56FUMIFzMtGOmhpJ\n"
                                        "DAkQ+zg22yLlxKuxjkWSEkYYzHgzrCiDfqcfSkG34veRdD9CGnLsIPvHtTFV/+b0\n"
                                        "5xTUyQxFzZ3kOl41KsTY9OsebYxYThHbTQIDAQAB\n"
                                        "-----END RSA PUBLIC KEY-----\n";
namespace {
bool IsHandshake(uint32_t class_id) {
  switch (class_id) {
    case TL_req_pq::CLASS_ID :
    case TL_req_DH_params::CLASS_ID :
    case TL_set_client_DH_params::CLASS_ID :
    return true;
    break;
    default:
    return false;
    break;
  }
}
  
}

///////////////////////////////////////////////////////////////////////////////////////////
void TelegramHandler::read(Context* ctx, std::unique_ptr<folly::IOBuf> msg) {
  auto buf_length = msg->computeChainDataLength();
  // std::shared_ptr<MTProtoBase> mtproto;
  
  do {
    // QuickAckSize
    if (buf_length == kMTProtoQuickAckSize) {
      auto mtproto = std::make_shared<MTProtoQuickAck>();
      if (!mtproto->ParseFromIOBuf(std::move(msg))) {
        LOG(ERROR) << "read - read MTProto error!!!!";
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - MTProtoQuickAck parser error!!!!"));
        break;
      }
      OnMTProtoQuickAck(ctx, mtproto);
    } else if (buf_length < kMTProtoMessageMinSize) {
      LOG(ERROR) << "read - need " << kMTProtoMessageMinSize << ", but only recv len: " << buf_length;
      ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - auth_key_id parser error!!!!"));
      break;
    } else {
      folly::io::Cursor c2(msg.get());
      int64_t key_id = c2.readLE<int64_t>();
      if (key_id != 0) {
        if (auth_key_id_ == 0) {
          auto key = AuthKeyManager::GetInstance()->FindAuthKey(key_id);
          if (!key) {
            LOG(ERROR) << "Can't find key_id: " << key_id;
            ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - auth_key_id error!!!!"));
            break;
          }
          auth_key_ = key;
          auth_key_id_ = key_id;
          /*
            folly::fbstring auth_key_data;
            if(!folly::readFile("./auth_key.dat", auth_key_data)) {
              LOG(ERROR) << "import - Unable to open ./auth_key.dat";
              // << path;
              break;
            }
           */
          // auth_key_.Copy((uint8_t*)auth_key_data.data());
          // memcpy(&auth_key_id_, auth_key_data.data()+256, 8);

        }
        auto mtproto = std::make_shared<MTProtoEncryptedMessage>(auth_key_, auth_key_id_);
        if (!mtproto->ParseFromIOBuf(std::move(msg))) {
          LOG(ERROR) << "read - read MTProto error!!!!";
          ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - MTProtoEncryptedMessage parser error!!!!"));
          break;
        }
        
        LOG(INFO) << "read encrypted message - " << mtproto->ToString();
        // if (session_id_ == 0) {
        session_id_ = mtproto->session_id;
        // } else if (session_id_ != mtproto->session_id) {
        //  LOG(ERROR) << "read - maybe session_id invalid, session_id is " << session_id_;
        // }
        OnMTProtoEncryptedMessage(ctx, mtproto);
      } else {
        auto mtproto = std::make_shared<MTProtoUnencryptedMessage>();
        if (!mtproto->ParseFromIOBuf(std::move(msg))) {
          LOG(ERROR) << "read - read MTProto error!!!!";
          ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("read - MTProtoUnencryptedMessage parser error!!!!"));
          break;
        }
        LOG(INFO) << "read unencrypted message - " << mtproto->ToString();
        OnMTProtoUnencryptedMessage(ctx, mtproto);
      }
    }
  } while(0);
  
#if 0
/*
  uint32_t class_id = 0;
  // c.readLE<uint32_t>();

  TLObjectPtr tl_object;
  folly::IOBuf* message_data;
  if (msg->GetType() == MTProtoBase::UNENCRYPTED_MESSAGE) {
    // TODO(@benqi): MTProtoUnencryptedMessage里实现
    message_data = std::static_pointer_cast<MTProtoUnencryptedMessage>(msg)->message_data.get();
    folly::io::Cursor c(message_data);
    class_id =c.readLE<uint32_t>();
  } else {
    message_data = std::static_pointer_cast<MTProtoEncryptedMessage>(msg)->message_data.get();
    folly::io::Cursor c(message_data);
    class_id =c.readLE<uint32_t>();
  }
 */
  tl_object = TLObject::CreateObjectByIOBuf(class_id);
  if (!tl_object) {
    LOG(ERROR) << "read - create mtproto message error, class_id = " << class_id;
    return;
  }
  
  if (!tl_object->ParseFromIOBuf(message_data, true)) {
    LOG(ERROR) << "read - create tl_object error, class_id = " << class_id;
    return;
  }
  
  LOG(INFO) << "read - received data: " << tl_object->ToString();
  if (first_recved_) {
    if (IsHandshake(class_id)) {
      conn_state_ = WAIT_TL_req_pq;
    } else {
      conn_state_ = RPC_RUNNING;
    }
    first_recved_ = false;
  }
  
  switch (conn_state_) {
    case WAIT_TL_req_pq:
    case WAIT_TL_req_DH_params:
    case WAIT_TL_set_client_DH_params:
      OnHandshake(ctx, tl_object);
      break;
      
    case RPC_RUNNING:
      OnRpcData(ctx, tl_object);
      break;

    default:
      LOG(ERROR) << "conn_state error!!!";
      break;
  }
#endif
}

void TelegramHandler::OnMTProtoQuickAck(Context* ctx, std::shared_ptr<MTProtoQuickAck> mproto) {
  LOG(INFO) << "read - recv QuickAckID";
}

void TelegramHandler::OnMTProtoUnencryptedMessage(Context* ctx, std::shared_ptr<MTProtoUnencryptedMessage> mproto) {
  // 首包处理
  if (first_recved_) {
    conn_state_ = WAIT_TL_req_pq;
    first_recved_ = false;
  }
  
  std::shared_ptr<TLObject> obj(TLObject::CreateObjectByIOBuf(mproto->GetMessageData()));
  
  // TODO(@benqi): 数据包或状态有问题，关闭连接
  if (!obj) {
    LOG(ERROR) << "OnMTProtoUnencryptedMessage - not create object: ";
    return;
  }
  
  if (!IsHandshake(obj->GetClassID())) {
    LOG(ERROR) << "OnMTProtoUnencryptedMessage - ";
    return;
  }
  
  auto r = OnHandshake(ctx, obj);
  if (!r) {
    LOG(ERROR) << "OnMTProtoUnencryptedMessage - ";
    return;
  }
  auto o_mtproto = std::make_shared<MTProtoUnencryptedMessage>(r);
  
  std::unique_ptr<folly::IOBuf> o;
  o_mtproto->SerializeToIOBuf(o);
  write(ctx, std::move(o));
}

void TelegramHandler::OnMTProtoEncryptedMessage(Context* ctx, std::shared_ptr<MTProtoEncryptedMessage> mproto) {
  // 首包处理
  if (first_recved_) {
    conn_state_ = RPC_RUNNING;
    first_recved_ = false;
  }
  
  auth_key_id_ = mproto->auth_key_id;
  
  std::shared_ptr<TLObject> obj(TLObject::CreateObjectByIOBuf(mproto->GetMessageData()));
  // TODO(@benqi): 数据包或状态有问题，关闭连接
  if (!obj) {
    LOG(ERROR) << "OnMTProtoEncryptedMessage - not create object: ";
    return;
  }
  
  LOG(INFO) << "OnMTProtoEncryptedMessage - obj: " << obj->ToString();
  auto r = OnRpcData(ctx, obj.get());
  if (r) {
    // TODO(@benqi): 简单粗暴方法
    
    std::shared_ptr<MTProtoEncryptedMessage> o_mtproto;
    
    if (r->GetClassID() == TL_pong::CLASS_ID) {
      std::static_pointer_cast<TL_pong>(r)->set_msg_id(mproto->message_id);
      
      o_mtproto = std::make_shared<MTProtoEncryptedMessage>(auth_key_,
                                                auth_key_id_,
                                                session_id_,
                                                mproto->seq_no,
                                                r);
    } else if (r->GetClassID() == TL_auth_sentCode::CLASS_ID ||
               r->GetClassID() == TL_auth_authorization::CLASS_ID ||
               r->GetClassID() == TL_config::CLASS_ID) {

      LOG(INFO) << "send: " << r->ToString();
      auto rpc_result = std::make_shared<TL_rpc_result>();
      rpc_result->set_req_msg_id(mproto->message_id);
      rpc_result->set_result(r);
      
      o_mtproto = std::make_shared<MTProtoEncryptedMessage>(auth_key_,
                                                            auth_key_id_,
                                                            session_id_,
                                                            mproto->seq_no,
                                                            rpc_result);
    } else {
      LOG(ERROR) <<  "not impl: " << r->ToString();
      return;
    }
    
    std::unique_ptr<folly::IOBuf> o;
    o_mtproto->SerializeToIOBuf(o);
    write(ctx, std::move(o));
  }
}

TLObjectPtr TelegramHandler::OnHandshake(Context* ctx, TLObjectPtr msg) {
  TLObjectPtr obj;
  switch (msg->GetClassID()) {
    case TL_req_pq::CLASS_ID :
      obj = On_TL_req_pq(ctx, msg);
      break;
    case TL_req_DH_params::CLASS_ID:
      obj = On_TL_req_DH_params(ctx, msg);
      break;
    case TL_set_client_DH_params::CLASS_ID:
      obj = On_TL_set_client_DH_params(ctx, msg);
      break;
    case TL_msgs_ack::CLASS_ID:
      LOG(INFO) << "Message ack...";
      break;
    default:
      break;
  }
  
  return obj;
}

TLObjectPtr TelegramHandler::OnRpcData(Context* ctx, const TLObject* msg) {
  // auto pipeline = dynamic_cast<TelegramPipeline*>(ctx->getPipeline());
  TLObjectPtr r;
  
  switch(msg->GetClassID()) {
    case TL_invokeWithLayer::CLASS_ID:
      r = On_TL_invokeWithLayer(ctx, msg);
      break;
    case TL_ping_delay_disconnect::CLASS_ID:
      r = On_TL_ping_delay_disconnect(ctx, msg);
      break;
    case TL_ping::CLASS_ID:
      r = On_TL_ping(ctx, msg);
      break;
    case TL_msg_container::CLASS_ID:
      r = On_TL_msg_container(ctx, msg);
      break;
    case TL_destroy_session::CLASS_ID:
      r = On_TL_destroy_session(ctx, msg);
      break;
    case TL_initConnection::CLASS_ID:
      r = On_TL_initConnection(ctx, msg);
      break;
    case TL_help_getConfig::CLASS_ID:
      r = On_TL_help_getConfig(ctx, msg);
      break;
    case TL_auth_sendCode::CLASS_ID:
      r = On_TL_auth_sendCode(ctx, msg);
      break;
    case TL_auth_signIn::CLASS_ID:
      r = On_TL_auth_signIn(ctx, msg);
      break;
    default:
      LOG(INFO) << "OnRpcData - todo object: " << msg->ToString();
      break;
  }
  
  return r;

#if 0
  // req为0
  TLObject* req = nullptr;
  
  if (msg->GetClassID() == TL_invokeWithLayer::CLASS_ID) {
    auto invoke_with_layer = std::static_pointer_cast<TL_invokeWithLayer>(msg);
    LOG(INFO) << "TL_invokeWithLayer's layer: " << invoke_with_layer->layer();
    LOG(INFO) << "TL_invokeWithLayer's query: " << invoke_with_layer->query()->ToString();
    
    auto x = invoke_with_layer->query();
    if (x->GetClassID() == TL_initConnection::CLASS_ID) {
      auto init_connection = reinterpret_cast<const TL_invokeWithLayer*>(x);
      LOG(INFO) << init_connection->ToString();
    } else if (x->GetClassID() == TL_ping_delay_disconnect::CLASS_ID) {
      auto ping_delay_disconnect = reinterpret_cast<const TL_ping_delay_disconnect*>(x);
      LOG(INFO) << ping_delay_disconnect->ToString();
    } else if (x->GetClassID() == TL_msg_container::CLASS_ID) {
      auto msg_container = reinterpret_cast<const TL_msg_container*>(x);
      LOG(INFO) << msg_container->ToString();
      // r = On_TL_msg_container(ctx, msg);
    } else {
      LOG(INFO) << "OnRpcData - todo object: " << msg->ToString();
    }
  }
  // int rv = TelegramEventCallback::OnDataReceived(pipeline, msg);
  // if (rv == -1) {
  //  // TODO(@benqi): 是否需要断开或其它处理
  // }
  
  return r;
#endif
  
}

// PQ默认值:
//
// static const uint8_t kDefaultPQ[8] = {0x17, 0xED, 0x48, 0x94, 0x1A, 0x08, 0xF9, 0x81};
// static const uint8_t kDefaultP[4] = {0x49, 0x4C, 0x55, 0x3B};
// static const uint8_t kDefaultQ[4] = {0x53, 0x91, 0x10, 0x73};

TLObjectPtr TelegramHandler::On_TL_req_pq(Context* ctx, TLObjectPtr msg) {
  auto req_pq = std::static_pointer_cast<TL_req_pq>(msg);
  // std::shared_ptr<MTProto<TL_resPQ>> resPQ = std::make_shared<MTProto<TL_resPQ>>();
  // (*resPQ)->nonce = req_pq->nonce();
  
  // 备份客户端nonce_
  nonce_.Copy(req_pq->nonce());
  // 生成服务端server_nonce;
  RandTLIntN(server_nonce_);

  LOG(INFO) << "On_TL_req_pq - " << req_pq->ToString() << ", noce: " << ToHexStr(nonce_);

  // 处理req_pq
  auto resPQ = std::make_shared<TL_resPQ>();
  resPQ->mutable_nonce()->Copy(nonce_);
  resPQ->mutable_server_nonce()->Copy(server_nonce_);
  // server_nonce
  resPQ->mutable_pq()->assign((const char*)kDefaultPQ, 8);
  resPQ->add_server_public_key_fingerprints(kDefaultFingerprint);

//  LOG(INFO) << "write resPQ: " << resPQ->ToString();
//
//  auto resPQ_data = std::make_shared<MTProtoUnencryptedMessage>(resPQ);
//  // std::unique_ptr<folly::IOBuf> o;
//  // resPQ_data.SerializeToIOBuf(o);
//  write(ctx, resPQ_data);
 
  conn_state_ = WAIT_TL_req_DH_params;
  
  return resPQ;
}

//void aesIgeEncryption(uint8_t *buffer, uint8_t *key, uint8_t *iv, bool encrypt, bool changeIv, uint32_t length) {
//  uint8_t *ivBytes = iv;
//  if (!changeIv) {
//    ivBytes = new uint8_t[32];
//    memcpy(ivBytes, iv, 32);
//  }
//  AES_KEY akey;
//  if (!encrypt) {
//    AES_set_decrypt_key(key, 32 * 8, &akey);
//    AES_ige_encrypt(buffer, buffer, length, &akey, ivBytes, AES_DECRYPT);
//  } else {
//    AES_set_encrypt_key(key, 32 * 8, &akey);
//    AES_ige_encrypt(buffer, buffer, length, &akey, ivBytes, AES_ENCRYPT);
//  }
//  if (!changeIv) {
//    delete [] ivBytes;
//  }
//}

inline char* tl_string_as_array(TLString* str) {
  // DO NOT USE const_cast<char*>(str->data())
  return str->empty() ? NULL : &*str->begin();
}

TLObjectPtr TelegramHandler::On_TL_req_DH_params(Context* ctx, TLObjectPtr msg) {
  auto req_DH_params = std::static_pointer_cast<TL_req_DH_params>(msg);
  // (mtproto->Cast<TL_req_DH_params>());

  std::shared_ptr<TL_server_DH_params_ok> server_dh_params_ok;
  
  LOG(INFO) << "On_TL_req_DH_params - " << req_DH_params->ToString();

  // bool rv = false;
  do {
    // 检查客户端发送的数据
    if (!nonce_.Compare(req_DH_params->mutable_nonce())) {
      break;
    }

    if (!server_nonce_.Compare(req_DH_params->mutable_server_nonce())) {
      break;
    }

    // 验证p，q
    // if (req_DH_params->g() != 2) {
    //   break;
    // }
    
    // public_key_fingerprint_
    // RSA解密
    // uint32_t

    const auto & encrypted_data = req_DH_params->encrypted_data();

    /**
     3、RSA加密算法流程：
     
     选择一对不同的、并且足够大的素数 p 和 q
     计算 n = p * q
     计算欧拉函数 f(n) = (p-1) * (q-1)，p 和 q 需要保密
     寻找与 f(n)  互质 的数 e，并且 1 < e < f(n)
     计算 d，使得 d * e  ≡  1 mod f(n)
     公钥 KU = (e , n)   私钥 KR = (d , n)
     加密时，将明文变换成 0 ~ n-1 的一个整数 M。明文较长可以分割。设密文为 C，则加密过程是：C  ≡  M^e mod n
     解密时，M  ≡  C^d mod n
     */

    BIO *key_bio = BIO_new(BIO_s_mem());
    BIO_write(key_bio, g_test_private_key.c_str(), (int) g_test_private_key.length());
    RSA *rsa_key = PEM_read_bio_RSAPrivateKey(key_bio, NULL, NULL, NULL);
    BIO_free(key_bio);
    
    auto bn_context = BN_CTX_new();

    BIGNUM *C = BN_bin2bn((uint8_t*)encrypted_data.data(), encrypted_data.length(), NULL);
    BIGNUM *r = BN_new();
    BN_mod_exp(r, C, rsa_key->d, rsa_key->n, bn_context);
    uint32_t size = BN_num_bytes(r);
    
    auto io_buf = folly::IOBuf::create(size);
    size_t res_len = BN_bn2bin(r, io_buf->writableData());
    io_buf->append(res_len);
    
    BN_free(C);
    BN_free(r);
    RSA_free(rsa_key);
    
    // innerDataBuffer->reuse();

    // TODO(@benqi): 长度检查
    // folly::StringPiece sha1_digest(encrypted_data, 0, SHA_DIGEST_LENGTH);
    // auto io_buf = folly::IOBuf::wrapBuffer(encrypted_data.data()+SHA_DIGEST_LENGTH, encrypted_data.length()-SHA_DIGEST_LENGTH);
    
    io_buf->trimStart(SHA_DIGEST_LENGTH);
    TL_p_q_inner_data p_q_inner_data;
    
    p_q_inner_data.ParseFromIOBuf(io_buf.get(), true);
    
    new_nonce_.Copy(p_q_inner_data.new_nonce());
    
    LOG(INFO) << "descrypt p_q_inner_data: " << p_q_inner_data.ToString();
    
    auto obj_size = p_q_inner_data.GetObjectSize();

    
    // write
    // server_DH_params_ok
    // 处理req_pq
    server_dh_params_ok = std::make_shared<TL_server_DH_params_ok>();
    // TLInt128 nonce_;
    // TLInt128 server_nonce_;
    // TLInt128 new_nonce_hash_;
    // TLString encrypted_answer_;

    server_dh_params_ok->mutable_nonce()->Copy(nonce_);
    server_dh_params_ok->mutable_server_nonce()->Copy(server_nonce_);
    
    TL_server_DH_inner_data server_dh_inner_data;
    // TLInt128 nonce_;
    // TLInt128 server_nonce_;
    // int32_t g_;
    // TLString dh_prime_;
    // TLString g_a_;
    // int32_t server_time_;
    
    server_dh_inner_data.mutable_nonce()->Copy(nonce_);
    server_dh_inner_data.mutable_server_nonce()->Copy(server_nonce_);
    server_dh_inner_data.set_g(DH2048Wrapper::GetDH2048_G());
    server_dh_inner_data.mutable_dh_prime()->assign((char*)DH2048Wrapper::GetDH2048_P(), DH2048Wrapper::GetDH2048_Bits()/8);
    
    
    if (!p_) {
      p_ = BN_bin2bn(DH2048Wrapper::GetDH2048_P(), DH2048Wrapper::GetDH2048_Bits()/8, NULL);
      DCHECK(p_);
    }
    
    BIGNUM *g = BN_new();
    DCHECK(g);
    BN_set_word(g, DH2048Wrapper::GetDH2048_G());

    if (!a_) {
      uint8_t bytes[256];
      RAND_bytes(bytes, 256);
      a_ = BN_bin2bn(bytes, 256, NULL);
      DCHECK(a_);
    }
    
    BIGNUM *g_a = BN_new();
    DCHECK(g_a);

    // auto bn_context = BN_CTX_new();
    BN_mod_exp(g_a, g, a_, p_, bn_context);

    size = BN_num_bytes(g_a);
    server_dh_inner_data.mutable_g_a()->resize(size);
    // auto tmp_g_a = server_dh_inner_data.mutable_g_a();
    // (uint8_t*)(&(*tmp_g_a)[0]);
    BN_bn2bin(g_a, (uint8_t*)tl_string_as_array(server_dh_inner_data.mutable_g_a()));

    server_dh_inner_data.set_server_time(Now());
    BN_free(g);
    BN_free(g_a);
    // BN_free(p);
    BN_CTX_free(bn_context);

    LOG(INFO) << "server_dh_inner_data: size = " << server_dh_inner_data.GetObjectSize()
                << ", " << server_dh_inner_data.ToString();
    std::unique_ptr<folly::IOBuf> o;
    server_dh_inner_data.SerializeToIOBuf(o);
    
    uint8_t o_sha1[20];
    SHA1(o->data(), o->length(), o_sha1);
    LOG(INFO) << "serialized's server_dh_inner_data size: " << o->length();
    // size(), new_nonce_and_server_nonce.data());

    // o->moveToFbString();
    
    // new_nonce+server_nonce
    // server_nonce + new_nonce
    // new_nonce + new_nonce
    //
    
    uint8_t tmp_aes_key_and_iv[64];
    
    std::string new_nonce_and_server_nonce((char*)(new_nonce_.data), new_nonce_.size());
    new_nonce_and_server_nonce.append((char*)server_nonce_.data, server_nonce_.size());
    ::SHA1((const unsigned char *)new_nonce_and_server_nonce.data(), new_nonce_and_server_nonce.size(), tmp_aes_key_and_iv);
    

    std::string server_nonce_and_new_nonce((char*)(server_nonce_.data), server_nonce_.size());
    server_nonce_and_new_nonce.append((char*)new_nonce_.data, new_nonce_.size());
    ::SHA1((const unsigned char *)server_nonce_and_new_nonce.data(), server_nonce_and_new_nonce.size(), tmp_aes_key_and_iv+20);

    std::string new_nonce_and_new_nonce((char*)(new_nonce_.data), new_nonce_.size());
    new_nonce_and_new_nonce.append((char*)new_nonce_.data, new_nonce_.size());
    ::SHA1((const unsigned char *)new_nonce_and_new_nonce.data(), new_nonce_and_new_nonce.size(), tmp_aes_key_and_iv+40);

    memcpy(tmp_aes_key_and_iv + 60, new_nonce_.data, 4);

    TLString v2((const char*)o_sha1, 20);
    v2.append((const char*)o->data(), o->length());
    int pad_size = v2.length() % 16;
    if (pad_size > 0) {
      v2.append(16-pad_size, 0);
    }

    aesIgeEncryption((uint8_t*)tl_string_as_array(&v2), tmp_aes_key_and_iv, tmp_aes_key_and_iv+32, true, false, v2.length());
    //auto v = o->moveToFbString();
    //v = TLString()
    server_dh_params_ok->set_encrypted_answer(v2);
    // ->assign((const char*)o_sha1, 20);
    // server_dh_params_ok->mutable_encrypted_answer()->append((const char*)o->data(), o->length());
    
    
//    LOG(INFO) << "server_dh_params_ok: " << server_dh_params_ok->ToString();
//
//    auto server_dh_params_ok_data = std::make_shared<MTProtoUnencryptedMessage>(server_dh_params_ok);
//    // std::unique_ptr<folly::IOBuf> o2;
//    // server_dh_params_ok_data.SerializeToIOBuf(o2);
//    write(ctx, server_dh_params_ok_data);
//    rv = true;
  } while(0);
  
  
  conn_state_ = WAIT_TL_set_client_DH_params;
  return server_dh_params_ok;
}

TLObjectPtr TelegramHandler::On_TL_set_client_DH_params(Context* ctx, TLObjectPtr msg) {
  auto client_DH_params = std::static_pointer_cast<TL_set_client_DH_params>(msg);

  LOG(INFO) << "On_TL_set_client_DH_params - " << client_DH_params->ToString();

  auto cache_data = client_DH_params->mutable_encrypted_data();
  
  // 解密
  uint8_t tmp_aes_key_and_iv[64];
  
  std::string new_nonce_and_server_nonce((char*)(new_nonce_.data), new_nonce_.size());
  new_nonce_and_server_nonce.append((char*)server_nonce_.data, server_nonce_.size());
  ::SHA1((const unsigned char *)new_nonce_and_server_nonce.data(), new_nonce_and_server_nonce.size(), tmp_aes_key_and_iv);
  
  
  std::string server_nonce_and_new_nonce((char*)(server_nonce_.data), server_nonce_.size());
  server_nonce_and_new_nonce.append((char*)new_nonce_.data, new_nonce_.size());
  ::SHA1((const unsigned char *)server_nonce_and_new_nonce.data(), server_nonce_and_new_nonce.size(), tmp_aes_key_and_iv+20);
  
  std::string new_nonce_and_new_nonce((char*)(new_nonce_.data), new_nonce_.size());
  new_nonce_and_new_nonce.append((char*)new_nonce_.data, new_nonce_.size());
  ::SHA1((const unsigned char *)new_nonce_and_new_nonce.data(), new_nonce_and_new_nonce.size(), tmp_aes_key_and_iv+40);
  
  memcpy(tmp_aes_key_and_iv + 60, new_nonce_.data, 4);

  aesIgeEncryption((uint8_t*)tl_string_as_array(cache_data), tmp_aes_key_and_iv, tmp_aes_key_and_iv+32, false, false, cache_data->length());

  TL_client_DH_inner_data client_DH_inner_data;
  auto cache_io = folly::IOBuf::wrapBuffer(cache_data->data()+SHA_DIGEST_LENGTH, cache_data->length()-SHA_DIGEST_LENGTH);
  client_DH_inner_data.ParseFromIOBuf(cache_io.get(), true);
  
  LOG(INFO) << "serialized's client_DH_inner_data: " << client_DH_inner_data.ToString();
  
  auto g_b = BN_bin2bn((const uint8_t*)client_DH_inner_data.g_b().data(),
                       client_DH_inner_data.g_b().length(),
                       NULL);

  auto bn_context = BN_CTX_new();

  auto auth_key_num = BN_new();
  BN_mod_exp(auth_key_num, g_b, a_, p_, bn_context);
  size_t l = BN_num_bytes(auth_key_num);

  uint8_t handshake_auth_key[256];
  BN_bn2bin(auth_key_num, handshake_auth_key);
  if (l < 256) {
    memmove(handshake_auth_key + 256 - l, handshake_auth_key, l);
    memset(handshake_auth_key, 0, 256 - l);
  }

  TLString auth_key_aux_hash((char*)new_nonce_.data, new_nonce_.size());
  auth_key_aux_hash.append(1, (char)1);
  uint8_t h[20];
  SHA1((const uint8_t*)handshake_auth_key, 256, h);
  auth_key_aux_hash.append((char*)h, 20);
  
  SHA1((const uint8_t*)auth_key_aux_hash.data(), auth_key_aux_hash.length()-12, h);
  auth_key_aux_hash.append((char*)h, 20);

  auto dh_gen_ok = std::make_shared<TL_dh_gen_ok>();
  dh_gen_ok->mutable_nonce()->Copy(nonce_);
  dh_gen_ok->mutable_server_nonce()->Copy(server_nonce_);
  
  auto new_nonce_hash1 = dh_gen_ok->mutable_new_nonce_hash1();
  new_nonce_hash1->Copy(server_nonce_);
  memcpy(new_nonce_hash1->data, auth_key_aux_hash.data()+auth_key_aux_hash.length()-16, 16);
  // dh_gen_ok->mutable_new_nonce_hash1()->Copy(server_nonce_);

  // authKeyAuxHashBuffer->position(authNewNonce->length + 1 + 12);
  // authKeyId = authKeyAuxHashBuffer->readInt64(nullptr);

  
  // int64_t key_id = 0;
  memcpy(&auth_key_id_, auth_key_aux_hash.data()+new_nonce_.size()+1+12, 8);
  auth_key_ = std::make_shared<TLInt2048>();
  auth_key_->Copy(handshake_auth_key);

  LOG(INFO) << "build key ok, auth_key: " << ToHexStr(*auth_key_) << ", auth_key_id: " << auth_key_id_;
  AuthKeyManager::GetInstance()->SetAuthKey(auth_key_, auth_key_id_);
  
  // folly::readFile()
  
//  folly::fbstring fb_data;
//  
//  if(!folly::readFile("./auth_key.dat", fb_data)) {
//    // LOG(ERROR) << "import - Unable to open ./auth_key.dat";
//    // << path;
//    // break;
//  }

/*
  folly::fbstring fb_data((char*)auth_key_.data, 256);
  fb_data.append((char*)auth_key_.data, 256);
  fb_data.append((char*)&auth_key_id_, 8);
  folly::writeFile(fb_data, "./auth_key.dat");
 */
  
  LOG(INFO) << "write dh_gen_ok: " << dh_gen_ok->ToString();
  
  // auto dh_gen_ok_data = std::make_shared<MTProtoUnencryptedMessage>(dh_gen_ok);
  // std::unique_ptr<folly::IOBuf> o;
  // dh_gen_ok_data.SerializeToIOBuf(o);
  //
  // write(ctx, dh_gen_ok_data);

  conn_state_ = RPC_RUNNING;
  
  return dh_gen_ok;
}

folly::Future<folly::Unit> TelegramHandler::write(Context* ctx, std::unique_ptr<folly::IOBuf> out) {
  // LOG(INFO) << "conn_id = " << conn_id_ << ", TelegramHandler - write length: " << out->length();
  //所有发送数据字节数统计
  // return ctx->fireWrite(std::shared_ptr<BaseMTProtoMessage>(out));
  return ctx->fireWrite(std::move(out));
}

void TelegramHandler::readEOF(Context* ctx) {
  LOG(INFO) << "readEOF - conn_id = " << conn_id_ << ", TelegramHandler - Connection closed by "
        << remote_address_
        << ", conn_info: " << service_->GetServiceConfig().ToString();
  close(ctx);
}

void TelegramHandler::readException(Context* ctx, folly::exception_wrapper e) {
  LOG(ERROR) << "readException - conn_id = " << conn_id_
        << ", TelegramHandler - Local error: " << exceptionStr(e)
        << ", by "  << remote_address_
        << ", conn_info: " << service_->GetServiceConfig().ToString();
  close(ctx);
}

void TelegramHandler::transportActive(Context* ctx) {
  conn_state_ = CONNECTED;
  
  auto pipeline = dynamic_cast<TelegramPipeline*>(ctx->getPipeline());
  OnNewConnection(pipeline, pipeline->getTransportInfo()->remoteAddr->getAddressStr());
  
  LOG(INFO) << "transportActive - conn_id = " << conn_id_
        << ", TelegramHandler - Connection connected by "
        << remote_address_
        << ", conn_info: " << service_->GetServiceConfig().ToString();
  
  int rv = TelegramEventCallback::OnNewConnection(service_, pipeline);
  if (rv == -1) {
    // TODO(@benqi): 是否需要断开或其它处理
  }
  
  conn_state_ = WAIT_TL_req_pq;
}

void TelegramHandler::transportInactive(Context* ctx) {
  if (conn_state_ != ConnState::CONNECTED) {
    return;
  }
  
  LOG(INFO) << "transportInactive - conn_id = " << conn_id_
        << ", Connection closed by "
        << remote_address_
        << ", conn_info: " << service_->GetServiceConfig().ToString();
  
  auto pipeline = dynamic_cast<TelegramPipeline*>(ctx->getPipeline());
  int rv = TelegramEventCallback::OnConnectionClosed(service_, pipeline);
  if (rv == -1) {
    // TODO(@benqi): 是否需要其它处理
  }
  
  OnConnectionClosed();
  
  conn_state_ = CLOSED;
}

folly::Future<folly::Unit> TelegramHandler::close(Context* ctx) {
  return ctx->fireClose();
}

////////////////////////////////////////////////////////////////////////////////////
TLObjectPtr TelegramHandler::On_TL_invokeWithLayer(Context* ctx, const TLObject* msg) {
  TLObjectPtr r;
  auto invoke_with_layer = dynamic_cast<const TL_invokeWithLayer*>(msg);
  LOG(INFO) << "On_TL_invokeWithLayer - TL_invokeWithLayer's layer: " << invoke_with_layer->layer();
  
  auto x = invoke_with_layer->query();
  if (!x) {
    LOG(INFO) << "On_TL_invokeWithLayer - query is nil";
    return r;
  }
  
  LOG(INFO) << "On_TL_invokeWithLayer - TL_invokeWithLayer's query: " << invoke_with_layer->query()->ToString();
  r = OnRpcData(ctx, x);
  return r;
/*
  if (x->GetClassID() == TL_initConnection::CLASS_ID) {
    auto init_connection = reinterpret_cast<const TL_invokeWithLayer*>(x);
    LOG(INFO) << init_connection->ToString();
  } else if (x->GetClassID() == TL_ping_delay_disconnect::CLASS_ID) {
    auto ping_delay_disconnect = reinterpret_cast<const TL_ping_delay_disconnect*>(x);
    LOG(INFO) << ping_delay_disconnect->ToString();
  } else if (x->GetClassID() == TL_msg_container::CLASS_ID) {
    auto msg_container = reinterpret_cast<const TL_msg_container*>(x);
    LOG(INFO) << msg_container->ToString();
    // r = On_TL_msg_container(ctx, msg);
  } else {
    LOG(INFO) << "OnRpcData - todo object: " << msg->ToString();
  }
 */
}

// pong#347773c5 msg_id:long ping_id:long = Pong;
TLObjectPtr TelegramHandler::On_TL_ping_delay_disconnect(Context* ctx, const TLObject* msg) {
  auto ping_delay_disconnect = dynamic_cast<const TL_ping_delay_disconnect*>(msg);
  LOG(INFO) << "ping_delay_disconnect - " << ping_delay_disconnect->ToString();
  
  auto pong = std::make_shared<TL_pong>();
  pong->set_ping_id(ping_delay_disconnect->ping_id());
  return pong;
}

TLObjectPtr TelegramHandler::On_TL_ping(Context* ctx, const TLObject* msg) {
  auto ping = dynamic_cast<const TL_ping*>(msg);
  LOG(INFO) << "On_TL_ping - " << ping->ToString();

  auto pong = std::make_shared<TL_pong>();
  pong->set_ping_id(ping->ping_id());
  return pong;
}

TLObjectPtr TelegramHandler::On_TL_msg_container(Context* ctx, const TLObject* msg) {
  TLObjectPtr rsp;
  
  auto msg_container = dynamic_cast<const TL_msg_container*>(msg);
  
  LOG(INFO) << "On_TL_msg_container - " << msg_container->ToString();
  for (size_t i=0; i<msg_container->messages_size(); ++i) {
    auto message2 = msg_container->messages(i);
    LOG(INFO) << "On_TL_msg_container - message2: " << message2->ToString();
    auto r = OnRpcData(ctx, message2->body());
    if (r) {
      if (r->GetClassID() == TL_auth_sentCode::CLASS_ID ||
          r->GetClassID() == TL_auth_authorization::CLASS_ID ||
          r->GetClassID() == TL_config::CLASS_ID) {
        
        auto rpc_result = std::make_shared<TL_rpc_result>();
        rpc_result->set_req_msg_id(message2->msg_id());
        rpc_result->set_result(r);
        
        auto r_mtproto = std::make_shared<MTProtoEncryptedMessage>(auth_key_,
                                                                   auth_key_id_,
                                                                   session_id_,
                                                                   message2->seqno(),
                                                                   rpc_result);
        std::unique_ptr<folly::IOBuf> out;
        r_mtproto->SerializeToIOBuf(out);
        if (out) {
          write(ctx, std::move(out));
        }
      } else {
        auto r_mtproto = std::make_shared<MTProtoEncryptedMessage>(auth_key_,
                                                                   auth_key_id_,
                                                                   session_id_,
                                                                   message2->seqno(),
                                                                   r);
        std::unique_ptr<folly::IOBuf> out;
        r_mtproto->SerializeToIOBuf(out);
        if (out) {
          write(ctx, std::move(out));
        }
      }
    }
  }
  return rsp;
}

TLObjectPtr TelegramHandler::On_TL_destroy_session(Context* ctx, const TLObject* msg) {
  LOG(INFO) << "On_TL_destroy_session - " << msg->ToString();
  // r = On_TL_destroy_session(ctx, msg);
  auto destroy_session = dynamic_cast<const TL_destroy_session*>(msg);
  auto destroy_session_ok = std::make_shared<TL_destroy_session_ok>();
  destroy_session_ok->set_session_id(destroy_session->session_id());
  return destroy_session_ok;
}

TLObjectPtr TelegramHandler::On_TL_initConnection(Context* ctx, const TLObject* msg) {
  LOG(INFO) << "On_TL_initConnection - " << msg->ToString();
  auto initConnection = dynamic_cast<const TL_initConnection*>(msg);
  TLObjectPtr o;
  if (initConnection->query()) {
    o = OnRpcData(ctx, initConnection->query());
  } else {
    LOG(ERROR) << "On_TL_initConnection - query is nil!!!";
  }
  
  return o;
}

/*
  flags = 2
  date = 1497279323
  expires = 1497283400
  test_mode = false
  this_dc = 5
  dc_options[0] = {
    flags = 0,
    id = 1
    ip_address = “149.154.175.50”
    port = 443
  }
  dc_options[1] = {
    flags = 1,
    id = 1
    ip_address = "2001:0b28:f23d:f001:0000:0000:0000:000a”
    port = 443
  }
  dc_options[2] = {
    flags = 0,
    id = 1
    ip_address = “149.154.167.51”
    port = 443
  }
  dc_options[3] = {
    flags = 1,
    id = 1
    ip_address = "2001:067c:04e8:f002:0000:0000:0000:000a"
    port = 443
  }
  chat_size_max = 200
  megagroup_size_max = 5000
  forwarded_count_max = 100
  online_update_preiod_ms = 120000
  offline_blue_timeout_ms = 5000
  offline_idle_timeout_ms = 30000
  online_cloud_timeout_ms = 300000
  notify_default_delay_ms = 1500
  chat_big_size = 10
  push_chat_period_ms = 60000
  push_chat_limit = 2
  saved_gifs_limit = 200
  edit_time_limit = 172800
  rating_e_deay = 2419200
  stickers_recent_limit = 30
  tmp_sessions = 0
  pinned_dialogs_count_max = 5
  call_receive_timeout_ms = 20000
  call_ring_timeout_ms = 90000
  call_connect_timeout_ms = 30000
  call_packet_timeout_ms = 10000
  me_url_prefix = “https://t.me/“
  disable_features = 0
 */

// config#cb601684:
// flags:# phonecalls_enabled:flags.1?true
// date:int
// expires:int
// test_mode:Bool
// this_dc:int
// dc_options:Vector<DcOption>
// chat_size_max:int
// megagroup_size_max:int
// forwarded_count_max:int
// online_update_period_ms:int
// offline_blur_timeout_ms:int
// offline_idle_timeout_ms:int
// online_cloud_timeout_ms:int
// notify_cloud_delay_ms:int
// notify_default_delay_ms:int
// chat_big_size:int
// push_chat_period_ms:int
// push_chat_limit:int
// saved_gifs_limit:int
// edit_time_limit:int
// rating_e_decay:int
// stickers_recent_limit:int
// tmp_sessions:flags.0?int
// pinned_dialogs_count_max:int
// call_receive_timeout_ms:int
// call_ring_timeout_ms:int
// call_connect_timeout_ms:int
// call_packet_timeout_ms:int
// me_url_prefix:string
// disabled_features:Vector<DisabledFeature>
// = Config;
TLObjectPtr TelegramHandler::On_TL_help_getConfig(Context* ctx, const TLObject* msg) {
  LOG(INFO) << "On_TL_destroy_session - " << msg->ToString();
  auto config = std::make_shared<TL_config>();
  
  config->set_date(1497279323);
  config->set_expires(1497283400);
  config->mutable_test_mode<TL_boolFalse>();
  config->set_this_dc(5);
  auto dc_option = config->add_dc_options<TL_dcOption>();
  // dc_option->set_flags(0);
  dc_option->set_id(1);
  dc_option->set_ip_address("192.168.48.184");
  dc_option->set_port(12345);
  config->set_chat_size_max(200);
  config->set_megagroup_size_max(5000);
  config->set_forwarded_count_max(100);
  config->set_forwarded_count_max(100);
  config->set_online_update_period_ms(120000);
  config->set_offline_blur_timeout_ms(5000);
  config->set_offline_idle_timeout_ms(30000);
  config->set_online_cloud_timeout_ms(300000);
  config->set_notify_cloud_delay_ms(1500);
  config->set_chat_big_size(10);
  config->set_push_chat_period_ms(60000);
  config->set_push_chat_limit(2);
  config->set_saved_gifs_limit(200);
  config->set_edit_time_limit(172800);
  config->set_rating_e_decay(2419200);
  config->set_stickers_recent_limit(30);
  config->set_tmp_sessions(0);
  config->set_pinned_dialogs_count_max(5);
  config->set_call_receive_timeout_ms(20000);
  config->set_call_ring_timeout_ms(90000);
  config->set_call_connect_timeout_ms(30000);
  config->set_call_packet_timeout_ms(10000);
  config->set_me_url_prefix("https://t.me/");

  return config;
}

// auth.sentCode#5e002502 flags:# phone_registered:flags.0?true type:auth.SentCodeType phone_code_hash:string next_type:flags.1?auth.CodeType timeout:flags.2?int = auth.SentCode;
TLObjectPtr TelegramHandler::On_TL_auth_sendCode(Context* ctx, const TLObject* msg) {
  // // auth.sendCode#86aef0ec flags:# allow_flashcall:flags.0?true phone_number:string current_number:flags.0?Bool api_id:int api_hash:string = auth.SentCode;
  auto auth_sendCode = dynamic_cast<const TL_auth_sendCode*>(msg);
  LOG(INFO) << "On_TL_auth_sendCode - " << auth_sendCode->ToString();
  
  auto auth_sentCode = std::make_shared<TL_auth_sentCode>();
  auto sent_code_type = auth_sentCode->mutable_type<TL_auth_sentCodeTypeApp>();
  sent_code_type->set_length(6);
  auth_sentCode->set_phone_code_hash("123456");
  
  return auth_sentCode;
}

// auth.signIn#bcd51581 phone_number:string phone_code_hash:string phone_code:string = auth.Authorization;
// user#2e13f4c3 flags:# self:flags.10?true contact:flags.11?true mutual_contact:flags.12?true deleted:flags.13?true bot:flags.14?true bot_chat_history:flags.15?true bot_nochats:flags.16?true verified:flags.17?true restricted:flags.18?true min:flags.20?true bot_inline_geo:flags.21?true id:int access_hash:flags.0?long first_name:flags.1?string last_name:flags.2?string username:flags.3?string phone:flags.4?string photo:flags.5?UserProfilePhoto status:flags.6?UserStatus bot_info_version:flags.14?int restriction_reason:flags.18?string bot_inline_placeholder:flags.19?string lang_code:flags.22?string = User;
TLObjectPtr TelegramHandler::On_TL_auth_signIn(Context* ctx, const TLObject* msg) {
  auto auth_signIn = dynamic_cast<const TL_auth_signIn*>(msg);
  LOG(INFO) << "On_TL_auth_signIn - " << auth_signIn->ToString();
  
  auto auth_authorization = std::make_shared<TL_auth_authorization>();
  auto user = auth_authorization->mutable_user<TL_user>();
  user->set_id(1);
  user->set_access_hash(1);
  user->set_first_name("wu");
  user->set_first_name("benqi");
  user->set_username("benqi");
  user->set_phone("8613606512716");

  return auth_authorization;
}

