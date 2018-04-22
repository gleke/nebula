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

#include "nebula/net/handler/mtproto/mtproto_transport_handler.h"

#include "nebula/base/io_buf_util.h"

// decode返回码
enum RCODE {
  INVALID = -1,       // 非法数据包
  BREAK = 0,          // 结束循环
  CONTINUE = 1,       // 继续下一个包
  IGNORE = 2,         // 忽略此数据包
  NOT_ENOUGH = 3,     // 长度不够
};

static inline const char* ToString(MTProtoTransportHandler::CodecState state) {
  switch (state) {
    case MTProtoTransportHandler::CodecState::INVALID :
      return "INVALID";
      break;
    case MTProtoTransportHandler::CodecState::WAIT_FIRST_PACKET :
      return "WAIT_FIRST_PACKET";
      break;
    case MTProtoTransportHandler::CodecState::WAIT_PACKET_LENGTH_1 :
      return "WAIT_PACKET_LENGTH_1";
      break;
    case MTProtoTransportHandler::CodecState::WAIT_PACKET_LENGTH_3 :
      return "WAIT_PACKET_LENGTH_3";
      break;
    case MTProtoTransportHandler::CodecState::WAIT_PACKET :
      return "WAIT_PACKET";
      break;
    case MTProtoTransportHandler::CodecState::ERROR :
      return "ERROR";
      break;
    default:
      break;
  }
  return "UNKNOWN";
}

void MTProtoTransportHandler::read(Context* ctx, folly::IOBufQueue& q) {
  if (UNLIKELY(state_ == CodecState::INVALID ||
               state_ == CodecState::ERROR)) {
    LOG(ERROR) << " read - state is error!!!";
    return;
  }
  
  do {
    std::unique_ptr<folly::IOBuf> result;
    size_t needed = 0;
    auto rv = decode(ctx, q, result, needed);
    
    // 是否传递
    if (rv.second) {
      ctx->fireRead(std::move(result));
    }
    
    // 是否继续解析
    if (!rv.first) {
      break;
    }
  } while (1);
}

std::pair<bool, bool> MTProtoTransportHandler::decode(Context* ctx,
                             folly::IOBufQueue& buf,
                             std::unique_ptr<folly::IOBuf>& result,
                             size_t&) {
  // std::pair<bool, bool> rv = std::make_pair(false, false);
  
  // Check buf
  if (buf.empty()) {
    return std::make_pair(false, false);
  }
  
  auto buf_length = buf.chainLength();
  LOG(INFO) << "decode - recv buf: " << buf_length;
  // 检查是否有可以足够处理的长度
  if (buf_length < last_data_length_) {
    LOG(WARNING) << "decode - need " << last_data_length_
                  << " byte, but only recv len: " << buf_length
                  << ", state = " << ToString(state_);
    return std::make_pair(false, false);
  }
  
  do {
    if (state_ == CodecState::WAIT_FIRST_PACKET) {
      DCHECK(last_data_length_ == 64);
      // bool rv = true;
      folly::io::Cursor c(buf.front());

      // 获取key
      uint8_t first_data[64];
      c.pull(first_data, 64);      // 处理

      LOG(INFO) << "decode - recv first packet: " << ToHexStr(folly::ByteRange(first_data, 64));

      buf.trimStart(64);
      buf_length -= 64;

      // 检查val和val2
      uint32_t val = (first_data[3] << 24) | (first_data[2] << 16) | (first_data[1] << 8) | (first_data[0]);
      uint32_t val2 = (first_data[7] << 24) | (first_data[6] << 16) | (first_data[5] << 8) | (first_data[4]);
      if (first_data[0] != 0xef &&
          val  != 0x44414548 &&
          val  != 0x54534f50 &&
          val  != 0x20544547 &&
          val  != 0x4954504f &&
          val  != 0xeeeeeeee &&
          val2 != 0x00000000) {
        LOG(INFO) << "VALID";
      } else {
        LOG(ERROR) << "AuthKeyGenerator - throw exception: invalid key: " << ToHexStr(folly::ByteRange(first_data, 64));
        throw std::runtime_error("invalid key");
      }

      
      uint8_t temp[64];
      // 生成decrypt_key
      for (int i = 0; i < 48; ++i) {
        temp[i] = first_data[55 - i];
      }

      encryptor_ = folly::make_unique<AesCtrEncrypt>(temp, 32, temp+32, 16);
      decryptor_ = folly::make_unique<AesCtrEncrypt>(first_data+8, 32, first_data+40, 16);

      // 解密
      decryptor_->Encrypt(first_data, temp, last_data_length_);
      
      // 检查temp
      // bytes[56] = bytes[57] = bytes[58] = bytes[59] = 0xef;
      if (temp[56] != 0xef &&
          temp[57] != 0xef &&
          temp[58] != 0xef &&
          temp[59] != 0xef) {
        LOG(ERROR) << "AuthKeyGenerator - throw exception: invalid key: " << ToHexStr(folly::ByteRange(first_data, 64));
        throw std::runtime_error("invalid key");
      }
      
      // 设置状态
      state_ = CodecState::WAIT_PACKET_LENGTH_1;
      last_data_length_ = 1;
      
      // 无fire，但可能会继续执行
    } else if (state_ == CodecState::WAIT_PACKET_LENGTH_1) {
      DCHECK(last_data_length_ == 1);

      folly::io::Cursor c(buf.front());

      // 一个字节
      uint8_t length_first_byte = c.read<uint8_t>();

      buf.trimStart(1);
      buf_length -= 1;

      LOG(INFO) << "decode - recv data, lengeh_1 byte: " << (int)length_first_byte;

      // 解密
      decryptor_->Encrypt(&length_first_byte, &length_first_byte, last_data_length_);
      // 只有一个字节
      // TODO(@wubenqi): 请求ACK length_first_byte & (1<<7), quickAck, 0x80
      uint8_t b = length_first_byte & 0x7f;
      if (b < 0x7f) {
        last_data_length_ = b * 4;
        state_ = CodecState::WAIT_PACKET;
        LOG(INFO) << "decode - will recv data: " << (int)last_data_length_;
      } else {
        last_data_length_ = 3;
        state_ = CodecState::WAIT_PACKET_LENGTH_3;
        LOG(INFO) << "decode - will recv lengeh_3";
      }

//      if ((length_first_byte & (1 << 7)) != 0) {
//        last_data_length_ = 4;
//        state_ = CodecState::WAIT_PACKET_LENGTH_4;
//      } else if (length_first_byte != 0x7f) {
//        last_data_length_ = length_first_byte * 4;
//        state_ = CodecState::WAIT_PACKET;
//      } else {
//        last_data_length_ = 3;
//        state_ = CodecState::WAIT_PACKET_LENGTH_3;
//      }
    } else if (state_ == CodecState::WAIT_PACKET_LENGTH_3) {
      DCHECK(last_data_length_ == 3) << "decode - ";
      
      folly::io::Cursor c(buf.front());

      uint8_t length_other_bytes[3];
      c.pull(length_other_bytes, 3);

      buf.trimStart(3);
      buf_length -= 3;


      decryptor_->Encrypt(length_other_bytes, length_other_bytes, last_data_length_);
      
      last_data_length_ = (uint32_t) length_other_bytes[0] |
                          ((uint32_t) length_other_bytes[1] << 8) |
                          ((uint32_t) length_other_bytes[2] << 16);
      last_data_length_ *= 4;
      LOG(INFO) << "decode - recv data, lengeh_3 byte: " << last_data_length_;
      
      state_ = CodecState::WAIT_PACKET;
    } else if (state_ == CodecState::WAIT_PACKET_LENGTH_4) {
      LOG(INFO) << "decode - recv data, lengeh_4 byte!!!";
      folly::io::Cursor c(buf.front());
      uint8_t ack[4];
      c.pull(ack, 4);

      decryptor_->Encrypt(ack, ack, 4);

      buf.trimStart(4);
      buf_length -= 4;
      last_data_length_ = 1;
      state_ = CodecState::WAIT_PACKET_LENGTH_1;
      
    } else if (state_ == CodecState::WAIT_PACKET) {
      result = buf.split(last_data_length_);
      buf_length -= last_data_length_;

      LOG(INFO) << "decode - recv data, packet byte: " << last_data_length_;

      // 解密
      decryptor_->Encrypt(result.get());
      // result = io_buf;
      
      state_ = CodecState::WAIT_PACKET_LENGTH_1;
      last_data_length_ = 1;

      if (buf_length < 1) {
        return std::make_pair(false, true);
      } else {
        // 继续执行
        return std::make_pair(true, true);
      }
    } else {
      // LOG(ERROR) << "";
      return std::make_pair(false, false);
    }
  } while (buf_length >= last_data_length_);
  
  return std::make_pair(false, false);
}


bool MTProtoTransportHandler::SetupAuthKey(folly::ByteRange auth_key) {
  try {
    // 提取key
    AuthKeyGenerator key_generator(auth_key);
    encryptor_ = folly::make_unique<AesCtrEncrypt>(key_generator.decrypt_key(), key_generator.decrypt_iv());
    decryptor_ = folly::make_unique<AesCtrEncrypt>(key_generator.encrypt_key(), key_generator.encrypt_iv());
  } catch (const std::exception& e) {
    LOG(ERROR) << "SetupAuthKey - catch a threwn exception in setup auth_key: " << ToHexStr(auth_key);
    return false;
  }
  return true;
}


folly::Future<folly::Unit> MTProtoTransportHandler::write(Context* ctx, std::unique_ptr<folly::IOBuf> out) {
  // 长度
  uint32_t buffer_len = 0;
  uint32_t packet_length = out->length() / 4;
  
  auto io_buf2 = folly::IOBuf::create(2000);
  IOBufWriter iobw(io_buf2.get(), 2000);
  
  if (packet_length < 0x7f) {
    buffer_len++;
  } else {
    buffer_len += 4;
  }
  
  if (packet_length < 0x7f) {
    iobw.write((uint8_t) packet_length);
  } else {
    packet_length = (packet_length << 8) + 0x7f;
    iobw.writeLE(packet_length);
  }
  
  folly::io::Cursor c(out.get());
  iobw.push(c, static_cast<uint32_t>(out->computeChainDataLength()));

  encryptor_->Encrypt(io_buf2.get());
  // 加密
  return ctx->fireWrite(std::forward<std::unique_ptr<folly::IOBuf>>(io_buf2));
}

