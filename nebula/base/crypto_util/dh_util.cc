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

#include "nebula/base/crypto_util/dh_util.h"

#include <stdlib.h>
#include <algorithm>
#include <openssl/rand.h>
#include <openssl/sha.h>
// #include <openssl/bn.h>
#include <openssl/pem.h>
#include <openssl/aes.h>
#include <memory.h>

#include <glog/logging.h>

unsigned char DH2048Wrapper::dh2048_p[]={
  0xF8,0x87,0xA5,0x15,0x98,0x35,0x20,0x1E,0xF5,0x81,0xE5,0x95,
  0x1B,0xE4,0x54,0xEA,0x53,0xF5,0xE7,0x26,0x30,0x03,0x06,0x79,
  0x3C,0xC1,0x0B,0xAD,0x3B,0x59,0x3C,0x61,0x13,0x03,0x7B,0x02,
  0x70,0xDE,0xC1,0x20,0x11,0x9E,0x94,0x13,0x50,0xF7,0x62,0xFC,
  0x99,0x0D,0xC1,0x12,0x6E,0x03,0x95,0xA3,0x57,0xC7,0x3C,0xB8,
  0x6B,0x40,0x56,0x65,0x70,0xFB,0x7A,0xE9,0x02,0xEC,0xD2,0xB6,
  0x54,0xD7,0x34,0xAD,0x3D,0x9E,0x11,0x61,0x53,0xBE,0xEA,0xB8,
  0x17,0x48,0xA8,0xDC,0x70,0xAE,0x65,0x99,0x3F,0x82,0x4C,0xFF,
  0x6A,0xC9,0xFA,0xB1,0xFA,0xE4,0x4F,0x5D,0xA4,0x05,0xC2,0x8E,
  0x55,0xC0,0xB1,0x1D,0xCC,0x17,0xF3,0xFA,0x65,0xD8,0x6B,0x09,
  0x13,0x01,0x2A,0x39,0xF1,0x86,0x73,0xE3,0x7A,0xC8,0xDB,0x7D,
  0xDA,0x1C,0xA1,0x2D,0xBA,0x2C,0x00,0x6B,0x2C,0x55,0x28,0x2B,
  0xD5,0xF5,0x3C,0x9F,0x50,0xA7,0xB7,0x28,0x9F,0x22,0xD5,0x3A,
  0xC4,0x53,0x01,0xC9,0xF3,0x69,0xB1,0x8D,0x01,0x36,0xF8,0xA8,
  0x89,0xCA,0x2E,0x72,0xBC,0x36,0x3A,0x42,0xC1,0x06,0xD6,0x0E,
  0xCB,0x4D,0x5C,0x1F,0xE4,0xA1,0x17,0xBF,0x55,0x64,0x1B,0xB4,
  0x52,0xEC,0x15,0xED,0x32,0xB1,0x81,0x07,0xC9,0x71,0x25,0xF9,
  0x4D,0x48,0x3D,0x18,0xF4,0x12,0x09,0x32,0xC4,0x0B,0x7A,0x4E,
  0x83,0xC3,0x10,0x90,0x51,0x2E,0xBE,0x87,0xF9,0xDE,0xB4,0xE6,
  0x3C,0x29,0xB5,0x32,0x01,0x9D,0x95,0x04,0xBD,0x42,0x89,0xFD,
  0x21,0xEB,0xE9,0x88,0x5A,0x27,0xBB,0x31,0xC4,0x26,0x99,0xAB,
  0x8C,0xA1,0x76,0xDB,
};

unsigned char DH2048Wrapper::dh2048_g[]={
  0x02,
};


DH2048Wrapper::DH2048Wrapper() {
  DH *dh;
  
  if ((dh=DH_new()) == nullptr)
    return;
  
  dh->p=BN_bin2bn(dh2048_p,(int)sizeof(dh2048_p),nullptr);
  dh->g=BN_bin2bn(dh2048_g,(int)sizeof(dh2048_g),nullptr);
  if ((dh->p == nullptr) || (dh->g == nullptr)) {
    DH_free(dh);
    return;
  }
  
  dh_ = dh;
}

// TODO(@wubenqi): thread_local storage bnContext!
static BN_CTX *bnContext;

static int BN_primality_test(int *is_probably_prime, const BIGNUM *candidate,
                      int checks, BN_CTX *ctx, int do_trial_division,
                      BN_GENCB *cb) {
  switch (BN_is_prime_fasttest_ex(candidate, checks, ctx, do_trial_division, cb)) {
    case 1:
      *is_probably_prime = 1;
      return 1;
    case 0:
      *is_probably_prime = 0;
      return 1;
    default:
      *is_probably_prime = 0;
      return 0;
  }
}


uint64_t gcd(uint64_t a, uint64_t b) {
  while (a != 0 && b != 0) {
    while ((b & 1) == 0) {
      b >>= 1;
    }
    while ((a & 1) == 0) {
      a >>= 1;
    }
    if (a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  return b == 0 ? a : b;
}

bool factorizeValue(uint64_t what, uint32_t &p, uint32_t &q) {
  int32_t it = 0, i, j;
  uint64_t g = 0;
  for (i = 0; i < 3 || it < 1000; i++) {
    uint64_t t = ((lrand48() & 15) + 17) % what;
    uint64_t x = (long long) lrand48() % (what - 1) + 1, y = x;
    int32_t lim = 1 << (i + 18);
    for (j = 1; j < lim; j++) {
      ++it;
      uint64_t a = x, b = x, c = t;
      while (b) {
        if (b & 1) {
          c += a;
          if (c >= what) {
            c -= what;
          }
        }
        a += a;
        if (a >= what) {
          a -= what;
        }
        b >>= 1;
      }
      x = c;
      uint64_t z = x < y ? what + x - y : x - y;
      g = gcd(z, what);
      if (g != 1) {
        break;
      }
      if (!(j & (j - 1))) {
        y = x;
      }
    }
    if (g > 1 && g < what) {
      break;
    }
  }
  
  if (g > 1 && g < what) {
    p = (uint32_t) g;
    q = (uint32_t) (what / g);
    if (p > q) {
      uint32_t tmp = p;
      p = q;
      q = tmp;
    }
    return true;
  } else {
    // DEBUG_E("factorization failed for %llu", what);
    p = 0;
    q = 0;
    return false;
  }
}

bool check_prime(BIGNUM *p) {
  int result = 0;
  if (!BN_primality_test(&result, p, BN_prime_checks, bnContext, 0, NULL)) {
    LOG(ERROR) << "OpenSSL error at BN_primality_test";
    return false;
  }
  return result != 0;
}

bool isGoodPrime(BIGNUM *p, uint32_t g) {
  //TODO check against known good primes
  if (g < 2 || g > 7 || BN_num_bits(p) != 2048) {
    return false;
  }
  
  BIGNUM *t = BN_new();
  BIGNUM *dh_g = BN_new();
  
  if (!BN_set_word(dh_g, 4 * g)) {
    LOG(ERROR) << "OpenSSL error at BN_set_word(dh_g, 4 * g)";
    BN_free(t);
    BN_free(dh_g);
    return false;
  }
  if (!BN_mod(t, p, dh_g, bnContext)) {
    LOG(ERROR) << "OpenSSL error at BN_mod";
    BN_free(t);
    BN_free(dh_g);
    return false;
  }
  uint64_t x = BN_get_word(t);
  if (x >= 4 * g) {
    LOG(ERROR) << "OpenSSL error at BN_get_word";
    BN_free(t);
    BN_free(dh_g);
    return false;
  }
  
  BN_free(dh_g);
  
  bool result = true;
  switch (g) {
    case 2:
      if (x != 7) {
        result = false;
      }
      break;
    case 3:
      if (x % 3 != 2) {
        result = false;
      }
      break;
    case 5:
      if (x % 5 != 1 && x % 5 != 4) {
        result = false;
      }
      break;
    case 6:
      if (x != 19 && x != 23) {
        result = false;
      }
      break;
    case 7:
      if (x % 7 != 3 && x % 7 != 5 && x % 7 != 6) {
        result = false;
      }
      break;
    default:
      break;
  }
  
  char *prime = BN_bn2hex(p);
  static const char *goodPrime = "c71caeb9c6b1c9048e6c522f70f13f73980d40238e3e21c14934d037563d930f48198a0aa7c14058229493d22530f4dbfa336f6e0ac925139543aed44cce7c3720fd51f69458705ac68cd4fe6b6b13abdc9746512969328454f18faf8c595f642477fe96bb2a941d5bcd1d4ac8cc49880708fa9b378e3c4f3a9060bee67cf9a4a4a695811051907e162753b56b0f6b410dba74d8a84b2a14b3144e0ef1284754fd17ed950d5965b4b9dd46582db1178d169c6bc465b0d6ff9ca3928fef5b9ae4e418fc15e83ebea0f87fa9ff5eed70050ded2849f47bf959d956850ce929851f0d8115f635b105ee2e4e15d04b2454bf6f4fadf034b10403119cd8e3b92fcc5b";
  if (!strcasecmp(prime, goodPrime)) {
    delete [] prime;
    BN_free(t);
    return true;
  }
  delete [] prime;
  
  if (!result || !check_prime(p)) {
    BN_free(t);
    return false;
  }
  
  BIGNUM *b = BN_new();
  if (!BN_set_word(b, 2)) {
    LOG(ERROR) << "OpenSSL error at BN_set_word(b, 2)";
    BN_free(b);
    BN_free(t);
    return false;
  }
  if (!BN_div(t, 0, p, b, bnContext)) {
    LOG(ERROR) << "OpenSSL error at BN_div";
    BN_free(b);
    BN_free(t);
    return false;
  }
  if (!check_prime(t)) {
    result = false;
  }
  BN_free(b);
  BN_free(t);
  return result;
}

bool isGoodGaAndGb(BIGNUM *g_a, BIGNUM *p) {
  if (BN_num_bytes(g_a) > 256 || BN_num_bits(g_a) < 2048 - 64 || BN_cmp(p, g_a) <= 0) {
    return false;
  }
  BIGNUM *dif = BN_new();
  BN_sub(dif, p, g_a);
  if (BN_num_bits(dif) < 2048 - 64) {
    BN_free(dif);
    return false;
  }
  BN_free(dif);
  return true;
}
