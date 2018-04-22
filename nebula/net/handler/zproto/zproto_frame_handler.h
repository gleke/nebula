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

#ifndef NUBULA_NET_HANDLER_ZPROTO_ZPROTO_FRAME_HANDLER_H_
#define NUBULA_NET_HANDLER_ZPROTO_ZPROTO_FRAME_HANDLER_H_

#include <wangle/channel/Handler.h>

#include "nebula/net/zproto/zproto_frame_data.h"

class ZProtoFrameDecoder : public wangle::InboundHandler<folly::IOBufQueue&, std::shared_ptr<zproto::FrameMessage>> {
public:
  typedef typename InboundHandler<folly::IOBufQueue&, std::shared_ptr<zproto::FrameMessage>>::Context Context;
  
  ZProtoFrameDecoder() = default;
  
  void read(Context* ctx, folly::IOBufQueue& q) override;
  void readEOF(Context* ctx) override {
    // state_ = CodecState::ERROR;
    ctx->fireReadEOF();
  }
  
  void transportActive(Context* ctx) override {
    // state_ = CodecState::WAIT_FIRST_PACKET;
    ctx->fireTransportActive();
  }
  
protected:
  // 处理流程：
  //  非法包，packageIndex is broken，要断开连接
  //  CRC32校验错误，要断开连接
  //  header无法识别，忽略
  bool OnFrameHandler(Context* ctx, zproto::Frame& frame);
  
private:
  
  // 返回为-1/0/1
  // -1: 不完整frame，有3种情况
  //     接收到空数据
  //     包不完整，还未收到收到body的length
  //     包不完整，但已经知道了整个frame的长度，也就是已经收到了body的length
  //  0: 刚好一个完整frame
  //  1: 超过一个frame
  int decode(Context* ctx, folly::IOBufQueue& buf, zproto::Frame& result);
  
  bool CheckPackageIndex(uint16_t frame_index);
  
  // last_package_index_值为-1，也意味着为此时在处理第一个数据包
  uint16_t last_frame_index_ {0};
  // {std::numeric_limits<uint16_t>::max()};   //
  // int32_t decoded_body_length_ {0}    // >0，则已经解析出frame长度
  zproto::Frame cached_frame_;
};

class ZProtoFrameHandler : public wangle::Handler<
        std::shared_ptr<zproto::FrameMessage>, std::shared_ptr<zproto::ProtoRawData>,
        std::unique_ptr<folly::IOBuf>, std::unique_ptr<folly::IOBuf>> {
public:
  ZProtoFrameHandler() = default;
  
  void read(Context* ctx, std::shared_ptr<zproto::FrameMessage> msg) override;
  folly::Future<folly::Unit> write(Context* ctx, std::unique_ptr<folly::IOBuf> msg) override;

  void OnProtoRawData(Context* ctx, std::shared_ptr<zproto::FrameMessage> message);
  void OnPing(Context* ctx, std::shared_ptr<zproto::FrameMessage> message);
  void OnPong(Context* ctx, std::shared_ptr<zproto::FrameMessage> message);
  void OnDrop(Context* ctx, std::shared_ptr<zproto::FrameMessage> message);
  void OnRedirect(Context* ctx, std::shared_ptr<zproto::FrameMessage> message);
  void OnAck(Context* ctx, std::shared_ptr<zproto::FrameMessage> message);
  void OnHandshake(Context* ctx, std::shared_ptr<zproto::FrameMessage> message);
  void OnHandshakeResponse(Context* ctx, std::shared_ptr<zproto::FrameMessage> message);
          
private:
  void WriteFrameMessage(Context *ctx, const zproto::FrameMessage* message);
          
  uint16_t last_send_frame_index_ {0};
};

#endif
