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

#include "nebula/net/handler/zproto/zproto_frame_handler.h"

#include <limits>

#include <folly/Likely.h>
#include <folly/Format.h>

#include "nebula/base/func_factory_manager.h"

using namespace zproto;

///////////////////////////////////////////////////////////////////////////////////////
// 初始化
typedef void(ZProtoFrameHandler::*ExecHandler)(ZProtoFrameHandler::Context*, std::shared_ptr<FrameMessage>);
typedef nebula::FuncFactoryManager<ExecHandler, uint8_t> ExecHandlerFactory;
#define REGISTER_EXECUTE_HANDLER(T) \
  static ExecHandlerFactory::RegisterTemplate g_reg_tcp_transport_handler_##T(T::HEADER, &ZProtoFrameHandler::On##T)

// Frame
REGISTER_EXECUTE_HANDLER(ProtoRawData);
REGISTER_EXECUTE_HANDLER(Ping);
REGISTER_EXECUTE_HANDLER(Pong);
REGISTER_EXECUTE_HANDLER(Drop);
REGISTER_EXECUTE_HANDLER(Redirect);
REGISTER_EXECUTE_HANDLER(Ack);
REGISTER_EXECUTE_HANDLER(Handshake);
REGISTER_EXECUTE_HANDLER(HandshakeResponse);

void ZProtoFrameDecoder::read(Context* ctx, folly::IOBufQueue& q) {
  do {
    // 包不完整
    // 刚好一个完整包
    // 不止一个包
    int rv = decode(ctx, q, cached_frame_);
    if (rv < 0) {
      // 非完整frame
      break;
    } else {
      if (!OnFrameHandler(ctx, cached_frame_)) {
        break;
      }
    }
    
    // 刚好一个完整的frame
    if (rv == 0) {
      break;
    }
    
    // rv > 1
    // 还有frame，继续
  } while (1);
}

enum {
  kUnpackOk = 0,
  kHeaderContinue = 1,
  kBodyContinue = 2,
  kMagicNumberError = -1,
  kHeadLengError = -2,
  kClientVersionError = -3,
  kFrameIndexError = -4,
  kFrameTypeError = -5,
  kCrc32Error = -6,
  kLengthError = -7,
};

int ZProtoFrameDecoder::decode(Context* ctx, folly::IOBufQueue& buf, Frame& result) {
  if (buf.empty()) {
    return -1;
  }
  
//  r >> magic_number
//  >> head_length
//  >> client_version
//  >> frame_index
//  >> seq_num
//  >> command_id
//  >> body.data_len;

  auto buf_length = buf.chainLength();
  
  if (result.body_length == 0) {
    // 先解码到body_length
    if (buf_length >= Frame::MIN_HEADER_LEN) {
      folly::io::Cursor c(buf.front());
      
      // 包索引/类型／body
      result.magic_number = c.readBE<uint16_t>();
      if (result.magic_number != 0x5342) {
        LOG(ERROR) << "decode - Check magic_number invalid, 0x5342 != magic_number: " << result.magic_number;
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("decode - Check magic_number invalid"));
        return kMagicNumberError;
      }
      
      result.head_length = c.readBE<uint16_t>();
      if (result.head_length<Frame::MIN_HEADER_LEN || result.head_length > Frame::MAX_HEADER_LEN) {
        LOG(ERROR) << "decode - Check head_length invalid, head_length = " << result.head_length;
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("decode - Check head_length invalid"));
        return kHeadLengError;
      }
      
      result.client_version = c.readBE<uint16_t>();
      if (result.client_version!=200) {
        LOG(ERROR) << "decode - Check client_version invalid, client_version = " << result.client_version;
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("decode - Check client_version invalid"));
        return kClientVersionError;
      }
      
      // TODO(@benqi): Check frame_index
      // if (frame_index!=last_frame_index) {
      //   // TODO(@benqi): XLOG
      //   return kFrameIndexError;
      // }
      result.frame_index = c.readBE<uint16_t>();
      // packageIndex is broken，要断开连接
//      if (false == CheckPackageIndex(result.frame_index)) {
//        LOG(ERROR) << "decode - Check package_index invalid, last_frame_index: "
//        << last_frame_index_ << ", recved frame: " << result.ToString();
//        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("decode - Check package_index invalid"));
//        return kFrameIndexError;
//      }

      result.seq_num = c.readBE<uint32_t>();

      result.command_id = c.readBE<uint32_t>();
//      if (!CheckFrameType(command_id)) {
//        // TODO(@benqi): XLOG
//        return kFrameTypeError;
//      }
      
      if (buf_length < result.head_length) {
        LOG(WARNING) << "decode - need " << result.head_length << " byte, but only recv len: " << buf_length;
        return kHeaderContinue;
      }

      result.body_length = c.readBE<uint32_t>();
      // TODO(@benqi): 使用宏或配置文件
      if (result.body_length + result.head_length + Frame::TAILER_LEN > MAX_FRAME_BODY_LEN) {
         LOG(ERROR) << "decode - Invalid body length(>1MB), recved frame: " << result.ToString();
        ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("decode - Check body length invalid"));
        return kLengthError;
      }

    } else {
      // TODO(@wubenqi): 考虑日志输出更详细的信息(conn_id/ip...)
      LOG(WARNING) << "decode - need 20 byte, but only recv len: " << buf_length;
      return -1;
    }
  }
  
  // 检查是否一个完整frame
  if (buf_length < result.CalcFrameLength()) {
    LOG(WARNING) << "decode - need " << result.CalcFrameLength()
                  << " byte, but only recv len: " << buf_length;
 
    return -1;
  }
  
   // LOG(INFO) << result.ToString();
  
  // nebula::io_buf_util::TrimStart(&buf, 9);
  buf.trimStart(Frame::MIN_HEADER_LEN);
  auto d = buf.split(result.body_length);
  result.body = std::move(d);

  folly::io::Cursor c(buf.front());
  
  result.crc32 = c.readBE<int32_t>();
  buf.trimStart(sizeof(result.crc32));

  if (buf_length == result.CalcFrameLength()) {
    return 0;
  } else {
    return 1;
  }
}

bool ZProtoFrameDecoder::CheckPackageIndex(uint16_t frame_index) {
  //
  return frame_index-last_frame_index_ == 1 ||
        (last_frame_index_ == std::numeric_limits<uint16_t>::max() &&
         frame_index == 0);
}
//  header无法识别，忽略
bool ZProtoFrameDecoder::OnFrameHandler(Context* ctx, Frame& frame) {
  // TODO(@benqi): CRC32校验错误，要断开连接
  // int crc32 = CRC();
  // if (crc32 != frame.crc32) {
  // LOG(ERROR) << "OnFrameHandler - crc32 error, crc32: "
  //                << crc32 << ", recved frame: " << frame.ToString();
  // ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("OnFrameHandler - crc32 check error"));
  //   return false;
  // }
  
  auto frame_message = FrameFactory::CreateSharedInstance(frame.GetFrameType());
  if (frame_message) {
    if (frame_message->Decode(frame) &&
        // 检查解压包的长度是否一致，避免格式一样，
        // 但数据长度不一样(FrameMessage里有string等字段，可能会有解压后长度与body长度不一致情况)
        frame_message->CalcFrameSize() == frame.CalcFrameLength()) {
      frame_message->seq_num = frame.seq_num;
      
      ctx->fireRead(frame_message);
    } else {
      LOG(ERROR) << "OnFrameHandler - Decode FrameMessage error " << frame.ToString();
      ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("OnFrameHandler - Decode FrameMessage error"));
      return false;
    }
  }

  // 设置下一步数据
  if (UNLIKELY(frame.frame_index == std::numeric_limits<uint16_t>::max())) {
    last_frame_index_ = 0;
  } else {
    last_frame_index_ = frame.frame_index;
  }
  
  frame.body_length = 0;
  return true;
}

void ZProtoFrameHandler::read(Context* ctx, std::shared_ptr<FrameMessage> msg) {
  ExecHandlerFactory::Execute2<ZProtoFrameHandler>(this, msg->GetFrameType(), ctx, msg);
}

void ZProtoFrameHandler::OnProtoRawData(Context* ctx, std::shared_ptr<FrameMessage> message) {
  CAST_PROTO_MESSAGE(ProtoRawData, message_data);
  ctx->fireRead(message_data);
}

void ZProtoFrameHandler::OnPing(Context* ctx, std::shared_ptr<FrameMessage> message) {
  CAST_PROTO_MESSAGE(Ping, ping);
  // LOG(INFO) << "OnPing - recv ping: " << (char*)ping->random_bytes->data();

  // 直接返回
  Pong pong;
  pong.seq_num = ping->seq_num;
  pong.random_bytes.swap(ping->random_bytes);
  WriteFrameMessage(ctx, &pong);
}

void ZProtoFrameHandler::OnPong(Context* ctx, std::shared_ptr<FrameMessage> message) {
  CAST_PROTO_MESSAGE(Pong, pong);
  
  // TODO(@benqi): 调试环境开启
  // LOG(INFO) << "OnPong - recv pong";
}

void ZProtoFrameHandler::OnDrop(Context* ctx, std::shared_ptr<FrameMessage> message) {
  CAST_PROTO_MESSAGE(Drop, drop);
  
  // TODO(@benqi): 调试环境开启
  // LOG(INFO) << "OnDrop - recv drop";
  
  // 关闭连接
  // TODO(@benqi)
  ctx->fireReadException(folly::make_exception_wrapper<std::runtime_error>("OnDrop - recv drop packet, will close"));
}

void ZProtoFrameHandler::OnRedirect(Context* ctx, std::shared_ptr<FrameMessage> message) {
  CAST_PROTO_MESSAGE(Redirect, redirect);
  
  LOG(INFO) << "OnRedirect - recv redirect";
  
}

void ZProtoFrameHandler::OnAck(Context* ctx, std::shared_ptr<FrameMessage> message) {
  CAST_PROTO_MESSAGE(Ack, ack);

  // TODO(@benqi): 调试环境开启
  LOG(INFO) << "OnAck - recv ack";

  // TODO(@benqi): process ack，检测连接状态
}

void ZProtoFrameHandler::OnHandshake(Context* ctx, std::shared_ptr<FrameMessage> message) {
  CAST_PROTO_MESSAGE(Handshake, handshake);

  // TODO(@benqi): 调试环境开启
  LOG(INFO) << "OnHandshake - recv handshake";
  
  HandshakeResponse handshake_response;
  handshake_response.seq_num = handshake->seq_num;

  handshake_response.proto_revision = handshake->proto_revision;
  handshake_response.api_major_version = handshake->api_major_version;
  handshake_response.api_minor_version = handshake->api_minor_version;
  memcpy(handshake_response.sha1, handshake->random_bytes, 32);
  
  WriteFrameMessage(ctx, &handshake_response);
}

void ZProtoFrameHandler::OnHandshakeResponse(Context* ctx, std::shared_ptr<FrameMessage> message) {
  CAST_PROTO_MESSAGE(HandshakeResponse, handshake_response);
  
  // TODO(@benqi): 调试环境开启
  LOG(INFO) << "OnHandshakeResponse - recv handshake_response";
}

void ZProtoFrameHandler::WriteFrameMessage(Context *ctx, const FrameMessage* message) {
  std::unique_ptr<folly::IOBuf> io_buf;
  if (!message->SerializeToIOBuf(io_buf)) {
    LOG(ERROR) << "WriteFrameMessage - SerializeToIOBuf message error!!!";
    return;
  }
  
  write(ctx, std::move(io_buf));
}

folly::Future<folly::Unit> ZProtoFrameHandler::write(Context* ctx, std::unique_ptr<folly::IOBuf> msg) {
  uint16_t send_frame_index = ++last_send_frame_index_;
  WriteFrameIndex(send_frame_index, msg.get());
  
  return ctx->fireWrite(std::forward<std::unique_ptr<folly::IOBuf>>(msg));
}

