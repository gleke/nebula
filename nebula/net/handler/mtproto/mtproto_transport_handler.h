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

#ifndef NUBULA_NET_HANDLER_MPROTO_MPROTO_TRANSPORT_HANDLER_H_
#define NUBULA_NET_HANDLER_MPROTO_MPROTO_TRANSPORT_HANDLER_H_


#include <wangle/channel/Handler.h>

#include "nebula/base/crypto_util/crypto_util.h"

class MTProtoTransportHandler : public wangle::Handler<
    folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>,
    std::unique_ptr<folly::IOBuf>, std::unique_ptr<folly::IOBuf>>
{
// class TcpTransportDecoder : public wangle::HandlerAdapter<folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>> {
public:
  enum CodecState : uint8_t {
    INVALID = 0,
    WAIT_FIRST_PACKET = 1,
    WAIT_PACKET_LENGTH_1 = 2,
    WAIT_PACKET_LENGTH_3 = 3,
    WAIT_PACKET_LENGTH_4 = 4,
    WAIT_PACKET = 5,
    ERROR = 6,
  };
  
  MTProtoTransportHandler() = default;
  
  void read(Context* ctx, folly::IOBufQueue& q) override;
  folly::Future<folly::Unit> write(Context* ctx, std::unique_ptr<folly::IOBuf> out) override;

  void readEOF(Context* ctx) override {
    state_ = CodecState::ERROR;
    ctx->fireReadEOF();
  }

  void transportActive(Context* ctx) override {
    state_ = CodecState::WAIT_FIRST_PACKET;
    ctx->fireTransportActive();
  }

private:
  /**
   * Decode bytes from buf into result.
   *
   * @return pair<bool, bool> - 
   * first value: true if decoding is successful, false if buf
   *                  has insufficient bytes.
   * second value: true if fire
   */
  std::pair<bool, bool> decode(Context* ctx,
              folly::IOBufQueue& buf,
              std::unique_ptr<folly::IOBuf>& result,
              size_t&);
  
  void Reset() {
    // 需要复位mogu_base_/pdu_base_/extend_
    // 但假如在解码时保证状态正确
    // 则可以不需复位mogu_base_/pdu_base_/extend_
    // state_ = kCodecStateNone;
    // decoded_len_ = 0;
  }
  
  bool SetupAuthKey(folly::ByteRange auth_key);
  
  // 加解密
  std::unique_ptr<AesCtrEncrypt> encryptor_;
  std::unique_ptr<AesCtrEncrypt> decryptor_;
  
  // bool first_packet_recved_ {true};
  
  // 等第一个数据包
  CodecState state_ {INVALID};
  // 通过状态机以及长度
  uint32_t last_data_length_ {64};     // 即将接收的下一次数据长度
  
  // bool first_sent_ {true};
};

#endif
