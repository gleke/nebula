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

#ifndef NEBULA_BASE_BIG_NUMBER_H_
#define NEBULA_BASE_BIG_NUMBER_H_

#include <stdint.h>
#include <vector>

struct bignum_st;

namespace nebula {

class BigNumber {
public:
  BigNumber();
  BigNumber(const BigNumber &bn);
  BigNumber(uint32_t);
  ~BigNumber();
  
  void SetDword(uint32_t);
  void SetQword(uint64_t);
  void SetBinary(const uint8_t *bytes, int len);
  void SetHexStr(const char *str);
  
  void SetRand(int numbits);
  
  BigNumber operator=(const BigNumber &bn);
  //	  BigNumber operator=(Sha1Hash &hash);
  
  BigNumber operator+=(const BigNumber &bn);
  BigNumber operator+(const BigNumber &bn) {
    BigNumber t(*this);
    return t += bn;
  }
  BigNumber operator-=(const BigNumber &bn);
  BigNumber operator-(const BigNumber &bn) {
    BigNumber t(*this);
    return t -= bn;
  }
  BigNumber operator*=(const BigNumber &bn);
  BigNumber operator*(const BigNumber &bn) {
    BigNumber t(*this);
    return t *= bn;
  }
  BigNumber operator/=(const BigNumber &bn);
  BigNumber operator/(const BigNumber &bn) {
    BigNumber t(*this);
    return t /= bn;
  }
  BigNumber operator%=(const BigNumber &bn);
  BigNumber operator%(const BigNumber &bn) {
    BigNumber t(*this);
    return t %= bn;
  }
  
  BigNumber ModExp(const BigNumber& bn1, const BigNumber& bn2);
  BigNumber Exp(const BigNumber &);
  
  int GetNumBytes(void);
  
  struct bignum_st* BN() { return bn_; }
  
  uint32_t AsDword();
  uint8_t* AsByteArray();
  
  // folly::ByteRange AsByteBuffer();
  std::vector<uint8_t> AsByteVector();
  
  const char *AsHexStr();
  const char *AsDecStr();
  
private:
  struct bignum_st *bn_;
  uint8_t *array_;
};
  
}

#endif // NEBULA_BASE_BIG_NUMBER_H_

