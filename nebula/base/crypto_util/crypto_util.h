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

#ifndef NEBULA_BASE_CRYPTO_UTIL_CRYPTO_UTIL_H_
#define NEBULA_BASE_CRYPTO_UTIL_CRYPTO_UTIL_H_

#include <stdint.h>
#include <string.h>

#include <openssl/aes.h>
#include <array>

#include <folly/Range.h>
#include <folly/Format.h>
#include <folly/io/IOBuf.h>

// 按照Telegram规则创建key
// 注意: 最后生成的key交换时还需要加密最后16位
// AES_ctr128_encrypt(bytes, temp, 64, &encryptKey, encryptIv, encryptCount, &encryptNum);
// memcpy(bytes + 56, temp + 56, 8);
class AuthKeyGenerator {
public:
  // 创建key
  AuthKeyGenerator();
  
  // 网络传输等预先创建好的key进行初始化
  // 注意：如果key长度不为64，会抛出异常
  // 如果是网络过来的，则是对方的key，获取key和iv时也要注意语义
  AuthKeyGenerator(folly::ByteRange key);
  
  ~AuthKeyGenerator() = default;
  
  inline folly::ByteRange encrypt_key() {
    return folly::ByteRange(nonce_.data()+8, 32);
  }
  
  inline folly::ByteRange encrypt_iv() {
    return folly::ByteRange(nonce_.data()+40, 16);
  }
  
  inline folly::ByteRange decrypt_key() {
    return folly::ByteRange(nonce_.data()+64, 32);
  }
  
  inline folly::ByteRange decrypt_iv() {
    return folly::ByteRange(nonce_.data()+96, 16);
  }
  
  inline folly::MutableByteRange nonce() {
    return folly::MutableByteRange(nonce_.data(), 64);
  }
  
private:
  // 低64位存储encrypt的key，高48位存储descrypt的key
  // |  0 ~ 63  | 64 ~ 127 |
  // | encrypt  | descrypt |
  std::array<uint8_t, 128> nonce_;
};

// AES_ctr128_encrypt简单封装
// 小心使用，容易犯错，加解密是有状态的
// 要注意线程安全，应该需要在同一个线程里使用
class AesCtrEncrypt {
public:
  // 初始化key
  // 注意：如果key长度不为32或iv长度不为16，会抛出异常
  AesCtrEncrypt(folly::ByteRange key, folly::ByteRange iv);
  AesCtrEncrypt(uint8_t* key, int key_len, uint8_t* iv, int iv_len);

  ~AesCtrEncrypt() = default;
  
  uint32_t Encrypt(const uint8_t* in, uint8_t* out, uint32_t len);
  uint32_t Encrypt(folly::IOBuf* io_buf, uint32_t len);
  void Encrypt(folly::IOBuf* io_buf);

private:
  // ctr used inplace, encrypt the data and leave it at the same place
  struct CTRState {
    static constexpr int kKeySize = 32;
    static constexpr int kIvecSize = 16;
    static constexpr int kEcountSize = 16;
    
    static_assert(CTRState::kIvecSize == AES_BLOCK_SIZE, "Wrong size of ctr ivec!");
    static_assert(CTRState::kEcountSize == AES_BLOCK_SIZE, "Wrong size of ctr ecount!");

    uint8_t  ivec[kIvecSize] = { 0 };
    uint32_t num {0};
    uint8_t  ecount[kEcountSize] = { 0 };
  };

  AES_KEY  aes_key_;
  CTRState aes_ctr_state_;
};

// void GenerateRsaKey();

void aesIgeEncryption(uint8_t *buffer, uint8_t *key, uint8_t *iv, bool encrypt, bool changeIv, uint32_t length);

// Hex工具函数
std::string ToHexStr(folly::ByteRange sp);

#endif // NEBULA_BASE_CRYPTO_UTIL_CRYPTO_UTIL_H_

