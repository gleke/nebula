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

#include "frontend/handshake_handler.h"

#include <openssl/sha.h>
#include <openssl/pem.h>

#include "nebula/base/time_util.h"
#include "nebula/base/crypto_util/dh_util.h"

#include "proto/mtproto/core/mtproto_schema.h"
#include "proto/mtproto/core/auth_key_manager.h"

using namespace mtproto;

// 2048位
// 测试私钥证书
static const std::string g_test_private_key =
      "-----BEGIN RSA PRIVATE KEY-----\n"
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
static const std::string g_test_public_key =
      "-----BEGIN RSA PUBLIC KEY-----\n"
      "MIIBCgKCAQEAtUXgOV7DZ1d9M08gYVOMU/fenTbbLU12b1LoL9sYfRycEpF4aqA9\n"
      "RW0rPfzY6yZkfTlQdoFaGxVpUiNMv5V3xY+aVoFQbT7rlsevE87tHK90yG1OYysl\n"
      "V7IJiCy/tLu/2DVhbZqg4fgPjs4XYrt7CABmsy/OtHJy6A9I1qPQ40MlSB21lmAQ\n"
      "I9gKHBc2BGZCvQ/NDj1elun9Qitf3ziH8g/Xsxv18CO8hAev56FUMIFzMtGOmhpJ\n"
      "DAkQ+zg22yLlxKuxjkWSEkYYzHgzrCiDfqcfSkG34veRdD9CGnLsIPvHtTFV/+b0\n"
      "5xTUyQxFzZ3kOl41KsTY9OsebYxYThHbTQIDAQAB\n"
      "-----END RSA PUBLIC KEY-----\n";

inline char* tl_string_as_array2(TLString* str) {
  // DO NOT USE const_cast<char*>(str->data())
  return str->empty() ? NULL : &*str->begin();
}

TLObjectPtr HandshakeHandler::OnHandshake(TLObjectPtr req) {
  TLObjectPtr obj;
  switch (req->GetClassID()) {
    case TL_req_pq::CLASS_ID :
      obj = On_TL_req_pq(req);
      break;
    case TL_req_DH_params::CLASS_ID:
      obj = On_TL_req_DH_params(req);
      break;
    case TL_set_client_DH_params::CLASS_ID:
      obj = On_TL_set_client_DH_params(req);
      break;
    default:
      LOG(ERROR) << "OnHandshake - ";
      break;
  }
  
  return obj;}

TLObjectPtr HandshakeHandler::On_TL_req_pq(TLObjectPtr msg) {
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
  
  state_ = HandshakeState::WAIT_REQ_DH_PARAMS;

  return resPQ;
}

TLObjectPtr HandshakeHandler::On_TL_req_DH_params(TLObjectPtr msg) {
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
    BN_bn2bin(g_a, (uint8_t*)tl_string_as_array2(server_dh_inner_data.mutable_g_a()));
    
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
    
    aesIgeEncryption((uint8_t*)tl_string_as_array2(&v2), tmp_aes_key_and_iv, tmp_aes_key_and_iv+32, true, false, v2.length());
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
  
  
  state_ = HandshakeState::WAIT_SET_CLIENT_DH_PARAMS;
  return server_dh_params_ok;
}

TLObjectPtr HandshakeHandler::On_TL_set_client_DH_params(TLObjectPtr msg) {
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
  
  aesIgeEncryption((uint8_t*)tl_string_as_array2(cache_data), tmp_aes_key_and_iv, tmp_aes_key_and_iv+32, false, false, cache_data->length());
  
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
  
  if (cb_)
    cb_->OnAuthKeyCreated(auth_key_, auth_key_id_);
  
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
  
  state_ = HandshakeState::CREATED;
  
  return dh_gen_ok;
}
