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

#include "nebula/net/handler/telegram/telegram_handler.h"

#include <openssl/sha.h>

#include "nebula/base/time_util.h"
#include "nebula/base/crypto_util/dh_util.h"
#include "nebula/net/telegram/schema.tl.h"

#include "nebula/net/engine/tcp_server.h"
#include "nebula/net/thread_local_conn_manager.h"

#include "nebula/net/handler/telegram/telegram_pipeline_factory.h"

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
void TelegramHandler::read(Context* ctx, std::shared_ptr<MTProtoBase> msg) {
  LOG(INFO) << "read - received data: "; // << msg;
  if (first_recved_) {
    if (IsHandshake(msg->GetClassID())) {
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
      OnHandshake(ctx, msg);
      break;
      
    case RPC_RUNNING:
      OnRpcData(ctx, msg);
      break;

    default:
      LOG(ERROR) << "conn_state error!!!";
      break;
  }
}

void TelegramHandler::OnHandshake(Context* ctx, std::shared_ptr<MTProtoBase> msg) {
  switch (msg->GetClassID()) {
    case TL_req_pq::CLASS_ID :
      On_TL_req_pq(ctx, msg);
      break;
    case TL_req_DH_params::CLASS_ID:
      On_TL_req_DH_params(ctx, msg);
      break;
    case TL_set_client_DH_params::CLASS_ID:
      On_TL_set_client_DH_params(ctx, msg);
      break;
    case TL_msgs_ack::CLASS_ID:
      LOG(INFO) << "Message ack...";
      break;
    default:
      break;
  }
}

void TelegramHandler::OnRpcData(Context* ctx, std::shared_ptr<MTProtoBase> msg) {
  auto pipeline = dynamic_cast<TelegramPipeline*>(ctx->getPipeline());
  
  int rv = TelegramEventCallback::OnDataReceived(pipeline, msg);
  if (rv == -1) {
    // TODO(@benqi): 是否需要断开或其它处理
  }
}

// PQ默认值:
//
// static const uint8_t kDefaultPQ[8] = {0x17, 0xED, 0x48, 0x94, 0x1A, 0x08, 0xF9, 0x81};
// static const uint8_t kDefaultP[4] = {0x49, 0x4C, 0x55, 0x3B};
// static const uint8_t kDefaultQ[4] = {0x53, 0x91, 0x10, 0x73};

void TelegramHandler::On_TL_req_pq(Context* ctx, std::shared_ptr<MTProtoBase> mtproto) {
  MTProto<TL_req_pq>& req_pq = *(mtproto->Cast<TL_req_pq>());
  // std::shared_ptr<MTProto<TL_resPQ>> resPQ = std::make_shared<MTProto<TL_resPQ>>();
  // (*resPQ)->nonce = req_pq->nonce();

  LOG(INFO) << "On_TL_req_pq - " << req_pq->ToString();
  
  // 备份客户端nonce_
  nonce_.Copy(*req_pq->mutable_nonce());
  // 生成服务端server_nonce;
  RandTLIntN(server_nonce_);
  
  // 处理req_pq
  auto resPQ = std::make_shared<TL_resPQ>();
  resPQ->mutable_nonce()->Copy(nonce_);
  resPQ->mutable_server_nonce()->Copy(server_nonce_);
  // server_nonce
  resPQ->mutable_pq()->assign((const char*)kDefaultPQ, 8);
  resPQ->add_server_public_key_fingerprints(kDefaultFingerprint);

  LOG(INFO) << "write resPQ: " << resPQ->ToString();

  MTProtoMessageData resPQ_data(resPQ, false);
  std::unique_ptr<folly::IOBuf> o;
  resPQ_data.Encode(o);
  
  write(ctx, std::move(o));
  
  conn_state_ = WAIT_TL_req_DH_params;
}

void aesIgeEncryption(uint8_t *buffer, uint8_t *key, uint8_t *iv, bool encrypt, bool changeIv, uint32_t length) {
  uint8_t *ivBytes = iv;
  if (!changeIv) {
    ivBytes = new uint8_t[32];
    memcpy(ivBytes, iv, 32);
  }
  AES_KEY akey;
  if (!encrypt) {
    AES_set_decrypt_key(key, 32 * 8, &akey);
    AES_ige_encrypt(buffer, buffer, length, &akey, ivBytes, AES_DECRYPT);
  } else {
    AES_set_encrypt_key(key, 32 * 8, &akey);
    AES_ige_encrypt(buffer, buffer, length, &akey, ivBytes, AES_ENCRYPT);
  }
  if (!changeIv) {
    delete [] ivBytes;
  }
}

inline char* tl_string_as_array(TLString* str) {
  // DO NOT USE const_cast<char*>(str->data())
  return str->empty() ? NULL : &*str->begin();
}

void TelegramHandler::On_TL_req_DH_params(Context* ctx, std::shared_ptr<MTProtoBase> mtproto) {
  MTProto<TL_req_DH_params>& req_DH_params = *(mtproto->Cast<TL_req_DH_params>());

  LOG(INFO) << "On_TL_req_DH_params - " << req_DH_params->ToString();

  bool rv = false;
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
    auto server_dh_params_ok = std::make_shared<TL_server_DH_params_ok>();
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
    
    
    LOG(INFO) << "server_dh_params_ok: " << server_dh_params_ok->ToString();

    MTProtoMessageData server_dh_params_ok_data(server_dh_params_ok, false);
    std::unique_ptr<folly::IOBuf> o2;
    server_dh_params_ok_data.Encode(o2);
    write(ctx, std::move(o2));

    // server_dh_inner_data.set_dh_prime();
    // server_dh_inner_data.set_dh_prime();

    // server_nonce
    // resPQ->mutable_pq()->assign((const char*)kDefaultPQ, 8);
    // resPQ->add_server_public_key_fingerprints(kDefaultFingerprint);

    // 检查
    // check
    /* nhdh      uint32_t innerDataSize = innerData->getObjectSize();
      uint32_t additionalSize = innerDataSize + SHA_DIGEST_LENGTH < 255 ? 255 - (innerDataSize + SHA_DIGEST_LENGTH) : 0;
      NativeByteBuffer *innerDataBuffer = BuffersStorage::getInstance().getFreeBuffer(innerDataSize + additionalSize + SHA_DIGEST_LENGTH);
      innerDataBuffer->position(SHA_DIGEST_LENGTH);
      innerData->serializeToStream(innerDataBuffer);
      delete innerData;
      
      SHA1(innerDataBuffer->bytes() + SHA_DIGEST_LENGTH, innerDataSize, innerDataBuffer->bytes());
      if (additionalSize != 0) {
        RAND_bytes(innerDataBuffer->bytes() + SHA_DIGEST_LENGTH + innerDataSize, additionalSize);
      }
      
      std::string &key = serverPublicKeys[keyIndex];
      
      BIO *keyBio = BIO_new(BIO_s_mem());
      BIO_write(keyBio, key.c_str(), (int) key.length());
      RSA *rsaKey = PEM_read_bio_RSAPublicKey(keyBio, NULL, NULL, NULL);
      BIO_free(keyBio);
      if (bnContext == nullptr) {
        bnContext = BN_CTX_new();
      }
      BIGNUM *a = BN_bin2bn(innerDataBuffer->bytes(), innerDataBuffer->limit(), NULL);
      BIGNUM *r = BN_new();
      BN_mod_exp(r, a, rsaKey->e, rsaKey->n, bnContext);
      uint32_t size = BN_num_bytes(r);
      ByteArray *rsaEncryptedData = new ByteArray(size >= 256 ? size : 256);
      size_t resLen = BN_bn2bin(r, rsaEncryptedData->bytes);
      if (256 - resLen > 0) {
        memset(rsaEncryptedData + resLen, 0, 256 - resLen);
      }
      BN_free(a);
      BN_free(r);
      RSA_free(rsaKey);
      innerDataBuffer->reuse();
      
      request->encrypted_data = std::unique_ptr<ByteArray>(rsaEncryptedData);

    */
    
    rv = true;
  } while(0);
  
  
  conn_state_ = WAIT_TL_set_client_DH_params;

/*
  auto server_DH_inner_data = std::make_shared<TL_server_DH_inner_data>();
/ *
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  int32_t g_;
  TLString dh_prime_;
  TLString g_a_;
  int32_t server_time_;
 * ss/
  // 解析出TL_p_q_inner_data
  TL_p_q_inner_data p_q_inner_data;

  server_DH_inner_data->mutable_nonce()->Copy(nonce_);
  server_DH_inner_data->mutable_server_nonce()->Copy(server_nonce_);
  server_DH_inner_data->set_g(2);
  
  
  // dh_prime: DH2048Wrapper::GetDH2048_P();
  // g_a: 2048位随机数
  
  // server_DH_inner_data->set_dh_prime(kDefaultP);
 */
}

void TelegramHandler::On_TL_set_client_DH_params(Context* ctx, std::shared_ptr<MTProtoBase> mtproto) {
  MTProto<TL_set_client_DH_params>& client_DH_params = *(mtproto->Cast<TL_set_client_DH_params>());
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

  // Length
  // | new_noce | 1 | SHA1(handshakeAuthKey) | SHA1(authKeyAuxHashLength-12) |

/*
  BIGNUM *authKeyNum = BN_new();
  BN_mod_exp(authKeyNum, g_a, b, p, bnContext);
  size_t l = BN_num_bytes(authKeyNum);
  handshakeAuthKey = new ByteArray(256);
  BN_bn2bin(authKeyNum, handshakeAuthKey->bytes);
  if (l < 256) {
    memmove(handshakeAuthKey->bytes + 256 - l, handshakeAuthKey->bytes, l);
    memset(handshakeAuthKey->bytes, 0, 256 - l);
  }
 */
  
  auto dh_gen_ok = std::make_shared<TL_dh_gen_ok>();
  dh_gen_ok->mutable_nonce()->Copy(nonce_);
  dh_gen_ok->mutable_server_nonce()->Copy(server_nonce_);
  
  auto new_nonce_hash1 = dh_gen_ok->mutable_new_nonce_hash1();
  new_nonce_hash1->Copy(server_nonce_);
  memcpy(new_nonce_hash1->data, auth_key_aux_hash.data()+auth_key_aux_hash.length()-16, 16);
  // dh_gen_ok->mutable_new_nonce_hash1()->Copy(server_nonce_);

  memcpy(&auth_key_id_, auth_key_aux_hash.data()+new_nonce_.size()+1+12, 8);
  auth_key_.Copy(handshake_auth_key);

  LOG(INFO) << "build key ok, auth_key: " << ToHexStr(auth_key_) << ", auth_key_id_: " << auth_key_id_;

  folly::fbstring fb_data((char*)auth_key_.data, 256);
  fb_data.append((char*)&auth_key_id_, 8);
  folly::writeFile(fb_data, "./auth_key.dat");
  
  LOG(INFO) << "write dh_gen_ok: " << dh_gen_ok->ToString();
  
  MTProtoMessageData dh_gen_ok_data(dh_gen_ok, false);
  std::unique_ptr<folly::IOBuf> o;
  dh_gen_ok_data.Encode(o);
  
  write(ctx, std::move(o));
  
/*
  uint32_t authKeyAuxHashLength = authNewNonce->length + SHA_DIGEST_LENGTH + 1;
  NativeByteBuffer *authKeyAuxHashBuffer = BuffersStorage::getInstance().getFreeBuffer(authKeyAuxHashLength + SHA_DIGEST_LENGTH);
  authKeyAuxHashBuffer->writeBytes(authNewNonce);
  SHA1(handshakeAuthKey->bytes, handshakeAuthKey->length, authKeyAuxHashBuffer->bytes() + authNewNonce->length + 1);
 
  authKeyAuxHashBuffer->writeByte(1);
  SHA1(authKeyAuxHashBuffer->bytes(), authKeyAuxHashLength - 12, authKeyAuxHashBuffer->bytes() + authKeyAuxHashLength);
  
  if (memcmp(result->new_nonce_hash1->bytes, authKeyAuxHashBuffer->bytes() + authKeyAuxHashLength + SHA_DIGEST_LENGTH - 16, 16)) {
    DEBUG_E("dc%u handshake: invalid DH answer nonce hash 1", datacenterId);
    authKeyAuxHashBuffer->reuse();
    beginHandshake(false);
  } else {
    DEBUG_D("dc%u handshake: completed, time difference = %d", datacenterId, timeDifference);
    authKey = handshakeAuthKey;
    handshakeAuthKey = nullptr;
    authKeyAuxHashBuffer->position(authNewNonce->length + 1 + 12);
    authKeyId = authKeyAuxHashBuffer->readInt64(nullptr);
    std::unique_ptr<TL_future_salt> salt = std::unique_ptr<TL_future_salt>(handshakeServerSalt);
    addServerSalt(salt);
    handshakeServerSalt = nullptr;
    ConnectionsManager::getInstance().onDatacenterHandshakeComplete(this, timeDifference);
    cleanupHandshake();
  }
  authKeyAuxHashBuffer->reuse();
 */

  conn_state_ = RPC_RUNNING;
}

folly::Future<folly::Unit> TelegramHandler::write(Context* ctx, std::unique_ptr<folly::IOBuf> out) {
  // LOG(INFO) << "conn_id = " << conn_id_ << ", TelegramHandler - write length: " << out->length();
  //所有发送数据字节数统计
  // return ctx->fireWrite(std::shared_ptr<BaseMTProtoMessage>(out));
  return ctx->fireWrite(std::forward<std::unique_ptr<folly::IOBuf>>(out));
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

