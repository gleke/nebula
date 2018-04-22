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

#include "proto/mtproto/core/mtproto_schema.h"

using namespace mtproto;

REGISTER_TLOBJECT(TL_message2);
REGISTER_TLOBJECT(TL_msg_container);
REGISTER_TLOBJECT(TL_gzip_packed);

// static TLObjectRegister<TL_msg_container> g_reg_tl_obejct_TL_msg_container(TL_msg_container::CLASS_ID);

//////////////////////////////////////////////////////////////////////////////
bool TL_message2::Decode(IOBufReader& iobr) {
  msg_id_ = iobr.readLE<int64_t>();
  seqno_ = iobr.readLE<int>();
  bytes_ = iobr.readLE<int>();
  
  auto o = TLObject::CreateObjectByIOBuf(iobr);
  if (o) {
    body_.reset(o); // = std::unique_ptr<TLObject>(o);
    LOG(INFO) << "Decode - TL_message2's message is: " << ToString();
  } else {
    LOG(ERROR) << "Decode - ";
    return false;
  }
  
  return true;
}

bool TL_message2::Encode(IOBufWriter& iobw) const {
  DCHECK(body_) << "body is nil!!!!";
  
  if (body_) {
    return false;
  }
  
  iobw.writeLE(msg_id_);
  iobw.writeLE(seqno_);
  iobw.writeLE(bytes_);
  
  auto p_bytes = iobw.writableData();
  auto l = iobw.length();
  body_->SerializeToIOBuf(iobw);
  l = iobw.length() - l;
  memcpy(p_bytes, &l, sizeof(bytes_));
  
  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_msg_container::Decode(IOBufReader& iobr) {
  auto sz = iobr.readLE<uint32_t>();
  for (uint32_t i=0; i<sz; ++i) {
    auto message = std::make_unique<TL_message2>();
    // iobr.skip(sizeof(uint32_t));
    message->ParseFromIOBuf(iobr);
    messages_.push_back(std::move(message));
  }
  return true;
}

bool TL_msg_container::Encode(IOBufWriter& iobw) const {
  iobw.writeLE((uint32_t)messages_.size());
  for (size_t i=0; i<messages_.size(); ++i) {
    messages_[i]->SerializeToIOBuf(iobw);
  }
  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_rpc_result::Decode(IOBufReader& iobr) {
  req_msg_id_ = iobr.readLE<int64_t>();
  auto o = TLObject::CreateObjectByIOBuf(iobr);
  if (o) {
    result_ = std::shared_ptr<TLObject>(o);
    LOG(INFO) << "Decode - TL_rpc_result's object is: " << ToString();
  } else {
    LOG(ERROR) << "Decode - ";
    return false;
  }
  return true;
}

bool TL_rpc_result::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(req_msg_id_);
  result_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_gzip_packed::Decode(IOBufReader& iobr) {
  ReadString(iobr, &packed_data_);
  return true;
}

bool TL_gzip_packed::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, packed_data_);
  return true;
}
