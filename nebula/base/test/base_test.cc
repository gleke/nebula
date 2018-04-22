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

#include "nebula/base/testing/testing_util.h"

#include <iostream>
#include <folly/ScopeGuard.h>
#include <folly/io/async/DelayedDestruction.h>

void ScopeGuradTest() {
  std::cout << "begin: SCOPE_EXIT" << std::endl;
  int i = 1;
  
  std::cout << "SCOPE_EXIT_" << __LINE__ << std::endl;
  std::cout << "SCOPE_EXIT_" << __COUNTER__ << std::endl;

  SCOPE_EXIT {
    std::cout << "0: SCOPE_EXIT: " << i <<  std::endl;
    ++i;
    std::cout << "3: SCOPE_EXIT: " << i <<  std::endl;
  };

  ++i;
  std::cout << "1: SCOPE_EXIT: " << i <<  std::endl;

  std::cout << "SCOPE_EXIT_" << __COUNTER__ << std::endl;
  std::cout << "SCOPE_EXIT_" << __LINE__ << std::endl;
  SCOPE_EXIT {
    std::cout << "4: SCOPE_EXIT: " << i <<  std::endl;
    ++i;
    std::cout << "2: SCOPE_EXIT: " << i <<  std::endl;
  };

  std::cout << "end: SCOPE_EXIT" << std::endl;
}

using namespace folly;

class DeleteGuarder : public DelayedDestruction {
  
  ~DeleteGuarder() {
    doFoo();
  }
  
  void doFoo() {
    DelayedDestructionBase::DestructorGuard dg(this);
    LOG(INFO) << "foo";
  }
};

void DelayedDestructionTest1() {
  auto dg = new DeleteGuarder();
  dg->destroy();
}

void DelayedDestructionTest2() {
  auto dg = new DeleteGuarder();
  DelayedDestructionBase::DestructorGuard guard(dg);
  dg->destroy();
}

int main(int argc, char* argv[]) {
  DelayedDestructionTest1();
  DelayedDestructionTest2();
  // ScopeGuradTest();
  // SelfRegisterFactoryManagerTest();
  
  nebula::TestingFuncManager::Testing();
}

#if 0
#include <openssl/rand.h>
#include <openssl/pem.h>
#include <openssl/aes.h>
#include <openssl/bn.h>

#include <glog/logging.h>

#include <folly/io/IOBufQueue.h>
#include <folly/io/Cursor.h>
#include <folly/Range.h>
#include <wangle/ssl/DHParam.h>

#include "base/sha1.h"
#include "base/timer_manager.h"
#include "base/linked_map.h"
#include "base/linked_hash_map.h"
#include "base/big_number.h"

#include "base/dh_util.h"

#include "base/crypto_util.h"

#include "proto/telegram/core/mtproto_message.h"
#include "proto/telegram/core/mtproto_message_factory.h"
#include "proto/telegram/schema.tl.h"

// namespace  {

REGISTER_MTPROTO_MESSAGE(TL_req_pq, 0x60469778);

// }


void TestLinkedMap() {
  LOG(INFO) << "TestLinkedMap()";
  base::linked_map<int, int> lm;
  lm[4] = 3;
  lm[2] = 1;
  lm[5] = 2;
  lm[2] = 0;
  for ( auto iter = lm.begin(); iter != lm.end(); ++iter ) {
    LOG(INFO) << iter->first << " --> " << iter->second;
  }
}

void TestLinkedHashMap() {
  LOG(INFO) << "TestLinkedHashMap()";
  base::linked_hash_map<int, int> lhm;
  lhm[4] = 3;
  lhm[2] = 1;
  lhm[5] = 2;
  lhm[2] = 0;
  for ( auto iter = lhm.begin(); iter != lhm.end(); ++iter ) {
    LOG(INFO) << iter->first << " --> " << iter->second;
  }
}

void TestIOBufQueue() {
  folly::IOBufQueue q;
  q.append("11234, ");
  q.append("000");
  auto b = q.move();
  LOG(INFO) << "size = " << b->countChainElements()
            << ", len = " << b->computeChainDataLength()
            << ", data = " << b->moveToFbString()
            << ", capacity = " << b->capacity();
}

void TestQueueAppender() {
  folly::IOBufQueue q;
  folly::io::QueueAppender c(&q, 512);
  c.writeBE((int)1111);
  c.writeLE((int)2222);
  c.push((const uint8_t*)"1234", 5);
  
  auto b = q.move();
  int v1, v2;
  char a[50];
  
  folly::io::Cursor c2(b.get());
  v1 = c2.readBE<int>();
  v2 = c2.readLE<int>();
  c2.pull(a, 5);
  
  LOG(INFO) << "v1 = " << v1 << ", v2 = " << v2 << ", a = " << a;
}

void TestAppender() {
  folly::IOBufQueue q;
  folly::io::QueueAppender c(&q, 512);
  c.writeBE((int)1111);
  c.writeLE((int)2222);
  c.push((const uint8_t*)"1234", 5);
  
  auto b = q.move();
  int v1, v2;
  char a[50];
  
  folly::io::Cursor c2(b.get());
  v1 = c2.readBE<int>();
  v2 = c2.readLE<int>();
  c2.pull(a, 5);
  
  LOG(INFO) << "v1 = " << v1 << ", v2 = " << v2 << ", a = " << a;
}

template<size_t N>
folly::ByteRange ToByteRange(const std::array<uint8_t, N>& a) {
  return folly::ByteRange(a.data(), a.size());
}

void TestCryptoUtil() {
  AuthKeyGenerator auth_key;
  AesCtrEncrypt aes_ctr_encryt(auth_key.encrypt_key(), auth_key.encrypt_iv());
  AesCtrEncrypt aes_ctr_decryt(auth_key.encrypt_key(), auth_key.encrypt_iv());
  
  folly::MutableByteRange nonce = auth_key.nonce();
  LOG(INFO) << "nonce: " << ToHexStr(nonce);

  // 测试
  //  char a[100];
  //  aes_ctr_encryt.Encrypt((uint8_t*)a, (uint8_t*)a, 100);
  //  // LOG(INFO) << "encrypt: " << ToHexStr(nonce);
  //  aes_ctr_decryt.Encrypt((uint8_t*)a, (uint8_t*)a, 100);

  // 我了个去
  aes_ctr_encryt.Encrypt(nonce.data(), nonce.data(), 64);
  LOG(INFO) << "encrypt: " << ToHexStr(nonce);
  memset(nonce.data(), 0, 56);
  aes_ctr_decryt.Encrypt(nonce.data(), nonce.data(), 64);
  LOG(INFO) << "decrypt: " << ToHexStr(nonce);

//  aes_ctr_encryt.Encrypt(nonce.data(), nonce.data(), 64);
//  LOG(INFO) << "encrypt: " << ToHexStr(nonce);
//  
//  aes_ctr_decryt.Encrypt(nonce.data(), nonce.data(), 64);
//  LOG(INFO) << "decrypt: " << ToHexStr(nonce);
//
//  aes_ctr_encryt.Encrypt(nonce.data(), nonce.data(), 64);
//  LOG(INFO) << "encrypt: " << ToHexStr(nonce);
//  
//  aes_ctr_decryt.Encrypt(nonce.data(), nonce.data(), 64);
//  LOG(INFO) << "decrypt: " << ToHexStr(nonce);

#if 0
/*
  LOG(INFO) << "encrypt_key: " << ToHexStr(auth_key.encrypt_key()); // .toString();
  LOG(INFO) << "encrypt_iv: " << ToHexStr(auth_key.encrypt_iv());
  LOG(INFO) << "decrypt_key: " << ToHexStr(auth_key.decrypt_key());
  LOG(INFO) << "decrypt_iv: " << ToHexStr(auth_key.decrypt_iv());
  
  LOG(INFO) << "nonce: " << ToHexStr(auth_key.nonce());
 */
  AesCtrEncrypt aes_ctr_encryt(encrypt_key.encrypt_key(), encrypt_key.encrypt_iv());
  folly::MutableByteRange nonce2(encrypt_key.nonce());
  LOG(INFO) << "source_key: " << ToHexStr(nonce2);

  std::array<uint8_t, 64> nonce;
  aes_ctr_encryt.Encrypt(nonce2.data(), nonce.data(), 64);
  LOG(INFO) << "encrypted key1: " << ToHexStr<64>(nonce);
  aes_ctr_encryt.Encrypt(nonce.data(), nonce.data(), 64);
  LOG(INFO) << "encrypted key10: " << ToHexStr<64>(nonce);

  memcpy(nonce.data(), nonce2.data(), 64-8);
  
  LOG(INFO) << "encrypted key2: " << ToHexStr<64>(nonce);

  AuthKeyGenerator decrypt_key(folly::ByteRange(nonce.data(), nonce.size()));
  AesCtrEncrypt aes_ctr_decryt(decrypt_key.encrypt_key(), decrypt_key.encrypt_iv());
 
  aes_ctr_encryt.Encrypt(nonce.data()+64-8, nonce.data()+64-8, 8);
  
  LOG(INFO) << "decrypted key: " << ToHexStr<64>(nonce);
#endif
  
}

void TestMTProto() {
  MTProtoBase* proto = MTProtoMessageFactory::CreateInstance(TL_req_pq::CLASS_ID);
  auto mtp_req_pq = proto->Cast<TL_req_pq>();
  auto req_pq = mtp_req_pq->get();
  RandTLIntN(req_pq->mutable_nonce());
  //->data, req_pq->mutable_nonce()->size);
  LOG(INFO) << proto->ToString();
}

/**
int32_t Datacenter::selectPublicKey(std::vector<int64_t> &fingerprints) {
  if (serverPublicKeys.empty()) {
    serverPublicKeys.push_back("-----BEGIN RSA PUBLIC KEY-----\n"
                               "MIIBCgKCAQEAwVACPi9w23mF3tBkdZz+zwrzKOaaQdr01vAbU4E1pvkfj4sqDsm6\n"
                               "lyDONS789sVoD/xCS9Y0hkkC3gtL1tSfTlgCMOOul9lcixlEKzwKENj1Yz/s7daS\n"
                               "an9tqw3bfUV/nqgbhGX81v/+7RFAEd+RwFnK7a+XYl9sluzHRyVVaTTveB2GazTw\n"
                               "Efzk2DWgkBluml8OREmvfraX3bkHZJTKX4EQSjBbbdJ2ZXIsRrYOXfaA+xayEGB+\n"
                               "8hdlLmAjbCVfaigxX0CDqWeR1yFL9kwd9P0NsZRPsmoqVwMbMu7mStFai6aIhc3n\n"
                               "Slv8kg9qv1m6XHVQY3PnEw+QQtqSIXklHwIDAQAB\n"
                               "-----END RSA PUBLIC KEY-----");
    serverPublicKeysFingerprints.push_back(0xc3b42b026ce86b21LL);
    
    serverPublicKeys.push_back("-----BEGIN RSA PUBLIC KEY-----\n"
                               "MIIBCgKCAQEAxq7aeLAqJR20tkQQMfRn+ocfrtMlJsQ2Uksfs7Xcoo77jAid0bRt\n"
                               "ksiVmT2HEIJUlRxfABoPBV8wY9zRTUMaMA654pUX41mhyVN+XoerGxFvrs9dF1Ru\n"
                               "vCHbI02dM2ppPvyytvvMoefRoL5BTcpAihFgm5xCaakgsJ/tH5oVl74CdhQw8J5L\n"
                               "xI/K++KJBUyZ26Uba1632cOiq05JBUW0Z2vWIOk4BLysk7+U9z+SxynKiZR3/xdi\n"
                               "XvFKk01R3BHV+GUKM2RYazpS/P8v7eyKhAbKxOdRcFpHLlVwfjyM1VlDQrEZxsMp\n"
                               "NTLYXb6Sce1Uov0YtNx5wEowlREH1WOTlwIDAQAB\n"
                               "-----END RSA PUBLIC KEY-----");
    serverPublicKeysFingerprints.push_back(0x9a996a1db11c729bLL);
    
    serverPublicKeys.push_back("-----BEGIN RSA PUBLIC KEY-----\n"
                               "MIIBCgKCAQEAsQZnSWVZNfClk29RcDTJQ76n8zZaiTGuUsi8sUhW8AS4PSbPKDm+\n"
                               "DyJgdHDWdIF3HBzl7DHeFrILuqTs0vfS7Pa2NW8nUBwiaYQmPtwEa4n7bTmBVGsB\n"
                               "1700/tz8wQWOLUlL2nMv+BPlDhxq4kmJCyJfgrIrHlX8sGPcPA4Y6Rwo0MSqYn3s\n"
                               "g1Pu5gOKlaT9HKmE6wn5Sut6IiBjWozrRQ6n5h2RXNtO7O2qCDqjgB2vBxhV7B+z\n"
                               "hRbLbCmW0tYMDsvPpX5M8fsO05svN+lKtCAuz1leFns8piZpptpSCFn7bWxiA9/f\n"
                               "x5x17D7pfah3Sy2pA+NDXyzSlGcKdaUmwQIDAQAB\n"
                               "-----END RSA PUBLIC KEY-----");
    serverPublicKeysFingerprints.push_back(0xb05b2a6f70cdea78LL);
    
    serverPublicKeys.push_back("-----BEGIN RSA PUBLIC KEY-----\n"
                               "MIIBCgKCAQEAwqjFW0pi4reKGbkc9pK83Eunwj/k0G8ZTioMMPbZmW99GivMibwa\n"
                               "xDM9RDWabEMyUtGoQC2ZcDeLWRK3W8jMP6dnEKAlvLkDLfC4fXYHzFO5KHEqF06i\n"
                               "qAqBdmI1iBGdQv/OQCBcbXIWCGDY2AsiqLhlGQfPOI7/vvKc188rTriocgUtoTUc\n"
                               "/n/sIUzkgwTqRyvWYynWARWzQg0I9olLBBC2q5RQJJlnYXZwyTL3y9tdb7zOHkks\n"
                               "WV9IMQmZmyZh/N7sMbGWQpt4NMchGpPGeJ2e5gHBjDnlIf2p1yZOYeUYrdbwcS0t\n"
                               "UiggS4UeE8TzIuXFQxw7fzEIlmhIaq3FnwIDAQAB\n"
                               "-----END RSA PUBLIC KEY-----");
 
    serverPublicKeysFingerprints.push_back(0x71e025b6c76033e3LL);
  }
  
  size_t count1 = fingerprints.size();
  size_t count2 = serverPublicKeysFingerprints.size();
  for (uint32_t a = 0; a < count1; a++) {
    for (uint32_t b = 0; b < count2; b++) {
      if ((uint64_t) fingerprints[a] == serverPublicKeysFingerprints[b]) {
        return b;
      }
    }
  }
  return -1;
}
 */

// PQ默认值:
//
void TestDH() {
  //TODO run in different thread?
  uint64_t pq = ((uint64_t) (kDefaultPQ[0] & 0xff) << 56) |
                ((uint64_t) (kDefaultPQ[1] & 0xff) << 48) |
                ((uint64_t) (kDefaultPQ[2] & 0xff) << 40) |
                ((uint64_t) (kDefaultPQ[3] & 0xff) << 32) |
                ((uint64_t) (kDefaultPQ[4] & 0xff) << 24) |
                ((uint64_t) (kDefaultPQ[5] & 0xff) << 16) |
                ((uint64_t) (kDefaultPQ[6] & 0xff) << 8) |
                ((uint64_t) (kDefaultPQ[7] & 0xff));
  
  uint32_t p = ((uint32_t) (kDefaultP[0] & 0xff) << 24) |
               ((uint32_t) (kDefaultP[1] & 0xff) << 16) |
               ((uint32_t) (kDefaultP[2] & 0xff) << 8) |
               ((uint32_t) (kDefaultP[3] & 0xff));
  
  uint32_t q = ((uint32_t) (kDefaultQ[0] & 0xff) << 24) |
               ((uint32_t) (kDefaultQ[1] & 0xff) << 16) |
               ((uint32_t) (kDefaultQ[2] & 0xff) << 8) |
               ((uint32_t) (kDefaultQ[3] & 0xff));

  uint32_t p1,q1;
  
  factorizeValue(pq, p1, q1);
  
  LOG(INFO) << "pq = " << pq
            << ", p = " << p
            << ", q = " << q
            << ", p1 = " << p1
            << ", q1 = " << q1;
  
}

// 2048位
// 测试私钥证书
const std::string g_test_private_key =  "-----BEGIN RSA PRIVATE KEY-----\n"
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
const std::string g_test_public_key =   "-----BEGIN RSA PUBLIC KEY-----\n"
                                        "MIIBCgKCAQEAtUXgOV7DZ1d9M08gYVOMU/fenTbbLU12b1LoL9sYfRycEpF4aqA9\n"
                                        "RW0rPfzY6yZkfTlQdoFaGxVpUiNMv5V3xY+aVoFQbT7rlsevE87tHK90yG1OYysl\n"
                                        "V7IJiCy/tLu/2DVhbZqg4fgPjs4XYrt7CABmsy/OtHJy6A9I1qPQ40MlSB21lmAQ\n"
                                        "I9gKHBc2BGZCvQ/NDj1elun9Qitf3ziH8g/Xsxv18CO8hAev56FUMIFzMtGOmhpJ\n"
                                        "DAkQ+zg22yLlxKuxjkWSEkYYzHgzrCiDfqcfSkG34veRdD9CGnLsIPvHtTFV/+b0\n"
                                        "5xTUyQxFzZ3kOl41KsTY9OsebYxYThHbTQIDAQAB\n"
                                        "-----END RSA PUBLIC KEY-----\n";

/////////////////////////////////////////////////////////////////////////////////////////
class Context;

// make
std::shared_ptr<TL_req_pq> make_req_qp() {
  auto req_pq = std::make_shared<TL_req_pq>();
  
  RandTLIntN(req_pq->mutable_nonce());
  
  return req_pq;
}

std::shared_ptr<TL_resPQ> make_resPQ(std::shared_ptr<TL_req_pq> req_pq) {
  auto resPQ = std::make_shared<TL_resPQ>();
  
  resPQ->mutable_nonce()->Copy(req_pq->nonce());
  // server_nonce
  RandTLIntN(resPQ->mutable_server_nonce());
  resPQ->mutable_pq()->assign((const char*)kDefaultPQ, 8);
  resPQ->add_server_public_key_fingerprints(kDefaultFingerprint);
  return resPQ;
}

BN_CTX* g_bn_context = nullptr;

std::shared_ptr<TL_req_DH_params> make_req_DH_params(std::shared_ptr<TL_resPQ> res_PQ) {
  auto req_DH_params = std::make_shared<TL_req_DH_params>();
  req_DH_params->mutable_nonce()->Copy(res_PQ->nonce());
  req_DH_params->mutable_server_nonce()->Copy(res_PQ->server_nonce());
  
  // pq
  const auto& pq_data = res_PQ->pq();
  uint64_t pq = ((uint64_t) ((uint8_t)pq_data[0] & 0xff) << 56) |
                ((uint64_t) ((uint8_t)pq_data[1] & 0xff) << 48) |
                ((uint64_t) ((uint8_t)pq_data[2] & 0xff) << 40) |
                ((uint64_t) ((uint8_t)pq_data[3] & 0xff) << 32) |
                ((uint64_t) ((uint8_t)pq_data[4] & 0xff) << 24) |
                ((uint64_t) ((uint8_t)pq_data[5] & 0xff) << 16) |
                ((uint64_t) ((uint8_t)pq_data[6] & 0xff) << 8) |
                ((uint64_t) ((uint8_t)pq_data[7] & 0xff));
  uint32_t p;
  uint32_t q;
  factorizeValue(pq, p, q);
  uint8_t p_data[4] = {(uint8_t)(p >> 24 & 0xff), (uint8_t)(p >> 16  & 0xff), (uint8_t)(p >> 8 & 0xff), (uint8_t)(p & 0xff)};
  uint8_t q_data[4] = {(uint8_t)(q >> 24 & 0xff), (uint8_t)(q >> 16  & 0xff), (uint8_t)(q >> 8 & 0xff), (uint8_t)(q & 0xff)};
  req_DH_params->set_p(TLString((char*)p_data, 4));
  req_DH_params->set_q(TLString((char*)q_data, 4));
  
  req_DH_params->set_public_key_fingerprint(res_PQ->server_public_key_fingerprints(0));
  
  // 加密
  //
  // const auto& encrypted_data = res_PQ->
  TL_p_q_inner_data p_q_inner_data;
  p_q_inner_data.set_pq(res_PQ->pq());
  p_q_inner_data.set_p(req_DH_params->p());
  p_q_inner_data.set_q(req_DH_params->q());
  p_q_inner_data.mutable_nonce()->Copy(req_DH_params->nonce());
  p_q_inner_data.mutable_server_nonce()->Copy(req_DH_params->server_nonce());
  RandTLIntN(p_q_inner_data.mutable_server_nonce());
  
  // 序列化
  std::unique_ptr<folly::IOBuf> io_buf;
  p_q_inner_data.SerializeToIOBuf(io_buf);
  
  auto d = io_buf->moveToFbString().toStdString();
  //();
  
  size_t inner_data_size = d.size();
  // io_buf->computeChainDataLength();
  // innerData->getObjectSize();
  size_t additional_size = inner_data_size + SHA_DIGEST_LENGTH < 255 ? 255 - (inner_data_size + SHA_DIGEST_LENGTH) : 0;
  
  // char sha
  // uint8_t sha_hash[SHA_DIGEST_LENGTH];
  
  // o.reserve(SHA_DIGEST_LENGTH + inner_data_size + additional_size);
  TLString o; // = *(req_DH_params->mutable_encrypted_data());
  o = base::SHA1HashString(d);
  o += d;
  char a1[256];
  RAND_bytes((uint8_t*)a1, 256);
  if (additional_size != 0) o.append(a1, additional_size);
  
  
  //o.assign(sha_hash, SHA_DIGEST_LENGTH);
  //o += d;
  // );
  
  // std::string &key = serverPublicKeys[keyIndex];
  
  BIO *key_bio = BIO_new(BIO_s_mem());
  BIO_write(key_bio,  g_test_public_key.c_str(), (int) g_test_public_key.length());
  RSA *rsa_key = PEM_read_bio_RSAPublicKey(key_bio, NULL, NULL, NULL);
  BIO_free(key_bio);
  if (g_bn_context == nullptr) {
    g_bn_context = BN_CTX_new();
  }
  
  BIGNUM *a = BN_bin2bn((const uint8_t*)o.data(), (int)o.length(), NULL);
  BIGNUM *r = BN_new();
  BN_mod_exp(r, a, rsa_key->e, rsa_key->n, g_bn_context);
  uint32_t size = BN_num_bytes(r);
  
  // ByteArray *rsaEncryptedData = new ByteArray(size >= 256 ? size : 256);
  TLString& o2 = *(req_DH_params->mutable_encrypted_data());
  o2.resize(size >= 256 ? size : 256);
  // size_t res_len =
  BN_bn2bin(r, (uint8_t*)o2.data());
  // if (256 - res_len > 0) {
  //  memset(rsaEncryptedData + resLen, 0, 256 - resLen);
  // }
  
  BN_free(a);
  BN_free(r);
  RSA_free(rsa_key);
  // innerDataBuffer->reuse();

  
/*
 
  NativeByteBuffer *innerDataBuffer = BuffersStorage::getInstance().getFreeBuffer(innerDataSize + additionalSize + SHA_DIGEST_LENGTH);
  innerDataBuffer->position(SHA_DIGEST_LENGTH);
  innerData->serializeToStream(innerDataBuffer);
  delete innerData;
  
  SHA1(innerDataBuffer->bytes() + SHA_DIGEST_LENGTH, innerDataSize, innerDataBuffer->bytes());
  if (additionalSize != 0) {
    RAND_bytes(innerDataBuffer->bytes() + SHA_DIGEST_LENGTH + innerDataSize, additionalSize);
  }
 */
  
//  TLString pq_;
//  TLString p_;
//  TLString q_;
//  TLInt128 nonce_;
//  TLInt128 server_nonce_;
//  TLInt256 new_nonce_;

  return req_DH_params;
}

std::shared_ptr<Server_DH_Params> make_Server_DH_Params(std::shared_ptr<TL_req_DH_params> req_DH_params) {
  auto server_DH_params_ok = std::make_shared<TL_server_DH_params_ok>();
  server_DH_params_ok->mutable_nonce()->Copy(req_DH_params->nonce());
  server_DH_params_ok->mutable_server_nonce()->Copy(req_DH_params->server_nonce());
  
  // 生成server_DH_inner_data
  TL_server_DH_inner_data server_DH_inner_data;
  server_DH_inner_data.mutable_nonce()->Copy(req_DH_params->nonce());
  server_DH_inner_data.mutable_server_nonce()->Copy(req_DH_params->server_nonce());
  
  // auto dh = get_dh2048();
  server_DH_inner_data.set_g(DH2048Wrapper::GetDH2048_G());
  server_DH_inner_data.mutable_dh_prime()->assign((const char*)DH2048Wrapper::GetDH2048_P(), 256);
  server_DH_inner_data.set_server_time(1373993675);
  
  //TLInt2048 a;
  //RandTLIntN(a);
  
  BigNumber g(2);
  BigNumber a;
  a.SetRand(2048);
  BigNumber p;
  p.SetBinary(DH2048Wrapper::GetDH2048_P(), 256);
  auto g_a = g.ModExp(a, p);
  server_DH_inner_data.mutable_g_a()->assign(g_a.AsByteArray(), g_a.GetNumBytes());
  
  // 加密
  
/*
  // g.ModExp(, );
  
  // BIGNUM *g_a = BN_new();
  // if (!BN_mod_exp(g_a, g, a, p, bnContext)) {

  // BN_mod_exp(r, a, rsaKey->e, rsaKey->n, g_bn_context);

  // char a[256];

  
  
  // server_DH_inner_data.set
  // TL_server_DH_params_ok *result = (TL_server_DH_params_ok *) message;
 */
  
  return nullptr;
}


void On_TL_req_pq(Context* ctx, std::shared_ptr<MTProtoBase> mtproto) {
  auto& req_pq = *(mtproto->Cast<TL_req_pq>());
  // RandTLIntN(req_pq->mutable_nonce());
  ///////////////////////////////////////////////////////////////////
  // req_pq->nonce();
  
  auto& resPQ = *(make_mtproto<TL_resPQ>());
  // nonce
  resPQ->mutable_nonce()->Copy(req_pq->nonce());
  // server_nonce
  RandTLIntN(resPQ->mutable_server_nonce());
  
  resPQ->mutable_pq()->assign((const char*)kDefaultPQ, 8);
  resPQ->add_server_public_key_fingerprints(kDefaultFingerprint);
}

void On_TL_req_DH_params(Context* ctx, std::shared_ptr<MTProtoBase> mtproto) {
/*
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLString p_;
  TLString q_;
  int64_t public_key_fingerprint_;
  TLString encrypted_data_;
 */
 
  // auto& req_DH_params = *(mtproto->Cast<TL_req_DH_params>());
  // 检查req_DH_params数据合法性
  // 1. nonce
  // 2. server_nonce
  // 3. p_
  // 4. q_
  // 5. public_key_fingerprint_
  // 6. encrypted_data_
  
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
  // 解密encrypted_data_
  // const TLString& encrypted_data = req_DH_params->encrypted_data();
  
  // TL_p_q_inner_data p_q_inner_data;
  // p_q_inner_data.set_pq();
  
  
}

void On_TL_set_client_DH_params(Context* ctx, std::shared_ptr<MTProtoBase> mtproto) {
  
}

void TestRSA() {
//  BIO *keyBio = BIO_new(BIO_s_mem());
//  BIO_write(keyBio, key.c_str(), (int) key.length());
//  RSA *rsaKey = PEM_read_bio_RSAPublicKey(keyBio, NULL, NULL, NULL);
//  BIO_free(keyBio);
//  if (bnContext == nullptr) {
//    bnContext = BN_CTX_new();
//  }
//  BIGNUM *a = BN_bin2bn(innerDataBuffer->bytes(), innerDataBuffer->limit(), NULL);
//  BIGNUM *r = BN_new();
//  BN_mod_exp(r, a, rsaKey->e, rsaKey->n, bnContext);
//  uint32_t size = BN_num_bytes(r);
//  ByteArray *rsaEncryptedData = new ByteArray(size >= 256 ? size : 256);
//  size_t resLen = BN_bn2bin(r, rsaEncryptedData->bytes);
//  if (256 - resLen > 0) {
//    memset(rsaEncryptedData + resLen, 0, 256 - resLen);
//  }
//  BN_free(a);
//  BN_free(r);
//  RSA_free(rsaKey);
}

class BaseDaemonTest : public BaseServer {
public:
  BaseDaemonTest() = default;
  ~BaseDaemonTest() override = default;
  
protected:
  bool Initialize() override {
#ifdef TEST_SERVER
    BaseServer::Initialize();

    // one
    timer_manager_->ScheduleOneShotTimeout([]() {
      LOG(INFO) << "ScheduleOneShotTimeout!!!!";
    }, 1000);

    // once
    timer_manager_->ScheduleRepeatingTimeout([]() {
      static int i = 0;
      LOG(INFO) << "ScheduleRepeatingTimeout - " << i++;
    }, 1000);
#endif
    
    return true;
  }
  
  bool Run() override {
#ifdef TEST_SERVER
    BaseServer::Run();
#else
    // TestLinkedMap();
    // TestLinkedHashMap();
    // TestIOBufQueue();
    // TestQueueAppender();
    // TestCryptoUtil();
    // TestMTProto();
    
    TestDH();
    
#endif
    return true;
  }
};

int main(int argc, char* argv[]) {
  return base::DoMain<BaseDaemonTest>(argc, argv);
}

#endif
