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

#include "nebula/base/crypto_util/big_number.h"

#include <string.h>
#include <openssl/bn.h>
#include <algorithm>

namespace nebula {
  
BigNumber::BigNumber() {
	bn_ = BN_new();
	array_ = NULL;
}

BigNumber::BigNumber(const BigNumber &bn)
{
	bn_ = BN_dup(bn.bn_);
	array_ = NULL;
}

BigNumber::BigNumber(uint32_t val) {
	bn_ = BN_new();
	BN_set_word(bn_, val);
	array_ = NULL;
}

BigNumber::~BigNumber() {
	BN_free(bn_);
	delete[] array_;
}

void BigNumber::SetDword(uint32_t val) {
	BN_set_word(bn_, val);
}

void BigNumber::SetQword(uint64_t val) {
	BN_add_word(bn_, (uint32_t)(val >> 32));
	BN_lshift(bn_, bn_, 32);
	BN_add_word(bn_, (uint32_t)(val & 0xFFFFFFFF));
}

void BigNumber::SetBinary(const uint8_t *bytes, int len) {
	uint8_t t[1000];
	for (int i = 0; i < len; i++) t[i] = bytes[len - 1 - i];
	BN_bin2bn(t, len, bn_);
}

void BigNumber::SetHexStr(const char *str) {
	BN_hex2bn(&bn_, str);
}

void BigNumber::SetRand(int numbits) {
	BN_rand(bn_, numbits, 0, 1);
}


BigNumber BigNumber::operator=(const BigNumber &bn) {
	BN_copy(bn_, bn.bn_);
	return *this;
}

BigNumber BigNumber::operator+=(const BigNumber &bn) {
	BN_add(bn_, bn_, bn.bn_);
	return *this;
}

BigNumber BigNumber::operator-=(const BigNumber &bn) {
	BN_sub(bn_, bn_, bn.bn_);
	return *this;
}

BigNumber BigNumber::operator*=(const BigNumber &bn) {
	BN_CTX *bnctx;

	bnctx = BN_CTX_new();
	BN_mul(bn_, bn_, bn.bn_, bnctx);
	BN_CTX_free(bnctx);

	return *this;
}

BigNumber BigNumber::operator/=(const BigNumber &bn) {
	BN_CTX *bnctx;

	bnctx = BN_CTX_new();
	BN_div(bn_, NULL, bn_, bn.bn_, bnctx);
	BN_CTX_free(bnctx);

	return *this;
}

BigNumber BigNumber::operator%=(const BigNumber &bn) {
	BN_CTX *bnctx;

	bnctx = BN_CTX_new();
	BN_mod(bn_, bn_, bn.bn_, bnctx);
	BN_CTX_free(bnctx);

	return *this;
}

BigNumber BigNumber::Exp(const BigNumber &bn) {
	BigNumber ret;
	BN_CTX *bnctx;

	bnctx = BN_CTX_new();
	BN_exp(ret.bn_, bn_, bn.bn_, bnctx);
	BN_CTX_free(bnctx);

	return ret;
}

BigNumber BigNumber::ModExp(const BigNumber &bn1, const BigNumber &bn2) {
	BigNumber ret;
	BN_CTX *bnctx;

	bnctx = BN_CTX_new();
	BN_mod_exp(ret.bn_, bn_, bn1.bn_, bn2.bn_, bnctx);
	BN_CTX_free(bnctx);

	return ret;
}

int BigNumber::GetNumBytes(void) {
	return BN_num_bytes(bn_);
}

uint32_t BigNumber::AsDword() {
	return (uint32_t)BN_get_word(bn_);
}

uint8_t *BigNumber::AsByteArray() {
	if (array_) {
		delete[] array_;
		array_ = NULL;
	}
	array_ = new uint8_t[GetNumBytes()];
	BN_bn2bin(bn_, (unsigned char *)array_);

	std::reverse(array_, array_ + GetNumBytes());

	return array_;
}

//folly::ByteRange BigNumber::AsByteBuffer() {
//	ByteBuffer ret(GetNumBytes());
//	ret.append(AsByteArray(), GetNumBytes());
//	return ret;
//}

std::vector<uint8_t> BigNumber::AsByteVector() {
	std::vector<uint8_t> ret;
	ret.resize(GetNumBytes());
	memcpy(&ret[0], AsByteArray(), GetNumBytes());
	return ret;
}

const char *BigNumber::AsHexStr() {
	return BN_bn2hex(bn_);
}

const char *BigNumber::AsDecStr() {
	return BN_bn2dec(bn_);
}

} // namespace nebula

