/*
 *  Copyright (c) 2016, https://github.com/zhatalk
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

#include "nebula/net/zproto/zproto_frame_data.h"

#include <folly/Format.h>

using namespace zproto;

// 模板不是类型, typedef只能给类型取别名。
// using关键字可以给模板取别名
template <class T>
using FrameRegister = nebula::SelfRegisterFactoryManager<FrameMessage, uint8_t>::RegisterTemplate<T>;

#define REGISTER_FRAME(T) \
  static FrameRegister<T> g_reg_frame_##T(T::HEADER)

// Frame
REGISTER_FRAME(ProtoRawData);
REGISTER_FRAME(Ping);
REGISTER_FRAME(Pong);
REGISTER_FRAME(Drop);
REGISTER_FRAME(Redirect);
REGISTER_FRAME(Ack);
REGISTER_FRAME(Handshake);
REGISTER_FRAME(HandshakeResponse);
REGISTER_FRAME(MarsSignal);


void ReadMapStringString(folly::io::Cursor& c, std::map<std::string, std::string>& maps) {
  uint32_t l = c.readBE<uint32_t>();
  for (uint32_t i=0; i<l; ++i) {
    std::string k, v;
    ReadString(c, k);
    ReadString(c, v);
    maps.insert(std::make_pair(k, v));
  }
}

void WriteMapStringString(IOBufWriter& iobw, const std::map<std::string, std::string>& maps) {
  iobw.writeBE(static_cast<uint32_t>(maps.size()));
  
  for (auto it = maps.begin(); it!=maps.end(); ++it) {
    WriteString(iobw, it->first);
    WriteString(iobw, it->second);
  }
}

std::string Frame::ToString() const {
  return folly::sformat("{{magic_number:{}, head_length:{}, client_version: {}, frame_index:{}, seq_num:{}, command_id: {}, body_length:{}, crc32:{}}}",
                        magic_number,
                        head_length,
                        client_version,
                        frame_index,
                        seq_num,
                        command_id,
                        body_length,
                        crc32);
}

bool Frame::Decode(std::unique_ptr<folly::IOBuf> frame_data) {
  folly::io::Cursor c(frame_data.get());
  
  try {
    // TODO(@benqi): 检查数据合法
    magic_number = c.readBE<uint16_t>();
    head_length = c.readBE<uint16_t>();
    client_version = c.readBE<uint16_t>();
    frame_index = c.readBE<uint16_t>();
    seq_num = c.readBE<uint32_t>();
    command_id = c.readBE<uint32_t>();
    // c.skip();
    
    //uint32_t tmp = c.readBE<int32_t>();
    //frame_type = tmp >> 24;
    //body_length = tmp & 0xffffff;
    body_length = c.readBE<uint32_t>();
    
    c.skip(body_length);
    crc32 = c.readBE<int32_t>();
    
    // frame_data->trimStart(9);
    body.swap(frame_data);
    // body->trimStart(9);
    nebula::io_buf_util::TrimStart(body.get(), MIN_HEADER_LEN);
    nebula::io_buf_util::TrimEnd(body.get(), TAILER_LEN);
  } catch (...) {
    // TODO(@wubenqi): error's log
    return false;
  }
  
  return true;
}

bool FrameMessage::SerializeToIOBuf(std::unique_ptr<folly::IOBuf>& io_buf) const {
  bool rv = true;
  auto io_buf2 = folly::IOBuf::create(2000);
  IOBufWriter iobw(io_buf2.get(), 2000);
  try {
    // Frame
    
    iobw.writeBE(uint16_t(0x5342));
    iobw.writeBE((uint16_t)(20));
    iobw.writeBE((uint16_t)(200));
    iobw.writeBE((uint16_t)(1));
    
    // seq_number
    iobw.writeBE(seq_num);
    // command_id
    iobw.writeBE(GetCommandID());
    iobw.writeBE(0);

    // iobw.writeBE((uint8_t)(buf_len >> 16));
    // iobw.writeBE((uint16_t)buf_len & 0xffff);
    //iobw.writeBE((uint8_t)0);
    //iobw.writeBE((uint16_t)0);

    // TODO(@benqi): 使用skip(sizoef(uint32_t))
    // magic_number + frame_index
    // iobw.writeBE((uint32_t)0);
    // iobw.writeBE((uint16_t)0);
    
    // iobw.writeBE((uint32_t) GetFrameType()>>24 & ((CalcFrameSize()-FrameMessage::CalcFrameSize()) & 0xffffff));
    // iobw.writeBE(buf_len);
    
    Encode(iobw);
    
    // crc32
    iobw.writeBE(uint32_t(0));
    
    // 返回值
    io_buf = std::move(io_buf2);
    
    auto size = io_buf->computeChainDataLength();
    WriteBodyLength(static_cast<uint32_t>(size-24), io_buf.get());

  } catch(const std::exception& e) {
    LOG(ERROR) << "SerializeToIOBuf - catch a threwn exception: " << folly::exceptionStr(e);
    rv = false;
  } catch (...) {
    LOG(ERROR) << "SerializeToIOBuf - catch a unknown threwn exception";
    rv = false;
  }
  return rv;
}

bool Drop::Decode(Frame& frame) {
  try {
    folly::io::Cursor c(frame.body.get());
    
    message_id = c.readBE<int64_t>();
    error_code = c.readBE<uint8_t>();
    int32_t l = c.readBE<int32_t>();
    error_message = c.readFixedString(l);
    
    // TODO(@benqi): 检查解压完以后的长度和body_len是否一致
  } catch(...) {
    // TODO(@wubenqi): error's log
    return false;
  }
  return true;
}

bool Redirect::Decode(Frame& frame) {
  try {
    folly::io::Cursor c(frame.body.get());
    
    int32_t l = c.readBE<int32_t>();
    host = c.readFixedString(l);
    port = c.readBE<int>();
    timeout = c.readBE<int>();
  } catch(...) {
    // TODO(@wubenqi): error's log
    return false;
  }
  return true;
}

bool Ack::Decode(Frame& frame) {
  try {
    folly::io::Cursor c(frame.body.get());
    
    received_package_index = c.readBE<int>();
  } catch(...) {
    // TODO(@wubenqi): error's log
    return false;
  }
  return true;
}

bool Handshake::Decode(Frame& frame) {
  try {
    folly::io::Cursor c(frame.body.get());
    
    proto_revision = c.readBE<uint8_t>();
    api_major_version = c.readBE<uint8_t>();
    api_minor_version = c.readBE<uint8_t>();
    c.pull(random_bytes, 32);
  } catch(...) {
    // TODO(@wubenqi): error's log
    return false;
  }
  return true;
}

bool HandshakeResponse::Decode(Frame& frame) {
  try {
    folly::io::Cursor c(frame.body.get());
    
    proto_revision = c.readBE<uint8_t>();
    api_major_version = c.readBE<uint8_t>();
    api_minor_version = c.readBE<uint8_t>();
    c.pull(sha1, 32);
  } catch(...) {
    // TODO(@wubenqi): error's log
    return false;
  }
  return true;
}
