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

#include "nebula/net/zproto/zproto_package_data.h"

using namespace zproto;

template <class T>
using PackageRegister = nebula::SelfRegisterFactoryManager<PackageMessage, uint8_t>::RegisterTemplate<T>;

#define REGISTER_PACKAGE(T) \
  static PackageRegister<T> g_reg_package_##T(T::HEADER)

// Package
REGISTER_PACKAGE(AuthIdInvalid);
REGISTER_PACKAGE(RequestAuthId);
REGISTER_PACKAGE(ResponseAuthId);
REGISTER_PACKAGE(RequestStartAuth);
REGISTER_PACKAGE(ResponseStartAuth);
REGISTER_PACKAGE(RequestGetServerKey);
REGISTER_PACKAGE(ResponseGetServerKey);
REGISTER_PACKAGE(RequestDH);
REGISTER_PACKAGE(ResponseDoDH);

REGISTER_PACKAGE(RpcRequest);
REGISTER_PACKAGE(RpcOk);
REGISTER_PACKAGE(RpcFloodWait);
REGISTER_PACKAGE(RpcError);
REGISTER_PACKAGE(RpcInternalError);

REGISTER_PACKAGE(Push);
REGISTER_PACKAGE(MessageAck);

REGISTER_PACKAGE(UnsentMessage);
REGISTER_PACKAGE(UnsentResponse);
REGISTER_PACKAGE(RequestResend);

REGISTER_PACKAGE(NewSession);
REGISTER_PACKAGE(SessionHello);
REGISTER_PACKAGE(SessionLost);

REGISTER_PACKAGE(Container);
// REGISTER_PACKAGE(AttachDataMessage);

std::string PackageHeader::ToString() const {
  return folly::sformat("{{package_header: [auth_id: {}, session_id: {}, message_id: {}]}}",
                        auth_id,
                        session_id,
                        message_id);
}

std::string AttachDataMessage::ToString() const {
  std::ostringstream oss;
  oss << "{proto_revision: " << proto_revision << ", "
  << "birth_timetick: " << birth_timetick << ", "
  << "birth_track_uuid: " << birth_track_uuid << ", "
  << "birth_from: " << birth_from << ", "
  << "birth_server_id: " << birth_server_id << ", "
  << "birth_conn_id: " << birth_conn_id << ", "
  << "birth_remote_ip: " << birth_remote_ip << ", "
  << "options: [";
  if (!options.empty()) {
    for (size_t i=1; i<options.size(); ++i) {
      if (options[i].type==0) {
        oss << ", " << options[i].data.n;
      } else {
        oss << ", " << *options[i].data.s;
      }
    }
  }
  oss << "]}";
  
  return oss.str();
}

bool Package::Decode(ProtoRawData& proto_raw_data) {
  message.swap(proto_raw_data.message_data);
  try {
    seq_num = proto_raw_data.seq_num;
    folly::io::Cursor c_b(message.get());
    folly::io::Cursor c(message.get());

    // size_t trim_size = HEADER_LEN;
    
    package_header.auth_id = c.readBE<int64_t>();
    package_header.session_id = c.readBE<int64_t>();
    
    // TODO(@benqi): 加密功能添加
    //  auth_id为0未加密，为0则加密
    package_header.message_id = c.readBE<int64_t>();

    package_type = c.readBE<uint8_t>();

    // package_type = proto_raw_data.command_id >> 16 & 0xff; //  c.readBE<uint8_t>();
    // LOG(INFO) << "command_id: " << proto_raw_data.command_id << ", package_type:" << (int)package_type;
    
    if (package_type == Package::ATTACH_DATA_MESSAGE) {
      _has_attach_data = true;
      attach_data.proto_revision = c.readBE<uint8_t>();
      attach_data.birth_timetick = c.readBE<uint64_t>();
      attach_data.birth_track_uuid = c.readBE<uint64_t>();
      ReadString(c, attach_data.birth_from);
      attach_data.birth_server_id = c.readBE<uint32_t>();
      attach_data.birth_conn_id = c.readBE<uint64_t>();
      ReadString(c, attach_data.birth_remote_ip);

      // read options
      uint32_t l = c.readBE<uint32_t>();
      for (uint32_t i=0; i<l; ++i) {
        // if ()
        AttachDataMessage::OptionData o;
        o.type = c.readBE<uint8_t>();
        if (o.type == 0) {
          o.data.n = c.readBE<uint64_t>();
        } else {
          o.data.s = new std::string();
          ReadString(c, *o.data.s);
        }
        
        attach_data.options.push_back(o);
      }
      // ReadMapStringString(c, attach_data.options);
      package_type = c.readBE<uint8_t>();
      
      // trim_size += attach_data.CalcPackageSize();
    }

    nebula::io_buf_util::TrimStart(message.get(), c-c_b);
  } catch(...) {
    // TODO(@wubenqi): error's log
    return false;
  }
  return true;
}

bool PackageMessage::SerializeToIOBuf(std::unique_ptr<folly::IOBuf>& io_buf) const {
  bool rv = true;
  auto io_buf2 = folly::IOBuf::create(2000);
  IOBufWriter iobw(io_buf2.get(), 2000);
  try {
    // uint32_t buf_len = CalcPackageSize() + Package::HEADER_LEN;
    
    // Frame
    iobw.writeBE(uint16_t(0x5342));
    iobw.writeBE((uint16_t)(20));
    
    iobw.writeBE((uint16_t)(200));
    iobw.writeBE((uint16_t)(1));

    iobw.writeBE(seq_num);
    iobw.writeBE(GetCommandID());
    
    // iobw.writeBE((uint8_t)(buf_len >> 16));
    // iobw.writeBE((uint16_t)buf_len & 0xffff);
    // iobw.writeBE((uint8_t)0);
    iobw.writeBE((uint32_t)0);
    
    
    // iobw.writeBE(GetPackageType());
    
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

std::string PackageMessage::ToString() const {
  if (_has_attach_data) {
    return folly::sformat("{{header:{{}}, attach_data:{{}}}}", package_header.ToString(), attach_data.ToString());
  } else {
    return folly::sformat("{{header:{}}}", package_header.ToString());
  }
}



