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

#include "nebula/net/telegram/schema.tl.h"

#include "nebula/net/telegram/core/tl_codec_util.h"

// 模板不是类型, typedef只能给类型取别名。
// using关键字可以给模板取别名
template <class T>
using TLObjectRegister = nebula::SelfRegisterFactoryManager<TLObject, uint32_t>::RegisterTemplate<T>;

#define REGISTER_TLOBJECT(T) \
static TLObjectRegister<T> g_reg_tl_obejct_##T(T::CLASS_ID)

REGISTER_TLOBJECT(TL_req_pq);
REGISTER_TLOBJECT(TL_resPQ);
REGISTER_TLOBJECT(TL_p_q_inner_data);
REGISTER_TLOBJECT(TL_req_DH_params);
REGISTER_TLOBJECT(TL_server_DH_inner_data);
REGISTER_TLOBJECT(TL_server_DH_params_fail);
REGISTER_TLOBJECT(TL_server_DH_params_ok);
REGISTER_TLOBJECT(TL_client_DH_inner_data);
REGISTER_TLOBJECT(TL_set_client_DH_params);
REGISTER_TLOBJECT(TL_dh_gen_retry);
REGISTER_TLOBJECT(TL_dh_gen_fail);
REGISTER_TLOBJECT(TL_dh_gen_ok);
REGISTER_TLOBJECT(TL_msgs_ack);


//////////////////////////////////////////////////////////////////////////////
bool TL_req_pq::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  
  return true;
}

bool TL_req_pq::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  
  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_resPQ::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadString(iobr, &pq_);
  server_public_key_fingerprints_.Decode(iobr);
  
  return true;
}

bool TL_resPQ::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteString(iobw, pq_);
  server_public_key_fingerprints_.Encode(iobw);
  
  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_p_q_inner_data::Decode(IOBufReader& iobr) {
  ReadString(iobr, &pq_);
  ReadString(iobr, &p_);
  ReadString(iobr, &q_);
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadTLIntN(iobr, &new_nonce_);
  
  return true;
}

bool TL_p_q_inner_data::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, pq_);
  WriteString(iobw, p_);
  WriteString(iobw, q_);
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteTLIntN(iobw, new_nonce_);
  
  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_req_DH_params::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadString(iobr, &p_);
  ReadString(iobr, &q_);
  public_key_fingerprint_ = iobr.readLE<int64_t>();
  ReadString(iobr, &encrypted_data_);
  
  return true;
}

bool TL_req_DH_params::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteString(iobw, p_);
  WriteString(iobw, q_);
  iobw.writeLE(public_key_fingerprint_);
  WriteString(iobw, encrypted_data_);
  
  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_server_DH_inner_data::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  g_ = iobr.readLE<int32_t>();
  ReadString(iobr, &dh_prime_);
  ReadString(iobr, &g_a_);
  server_time_ = iobr.readLE<int32_t>();
  
  return true;
}

bool TL_server_DH_inner_data::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  iobw.writeLE(g_);
  WriteString(iobw, dh_prime_);
  WriteString(iobw, g_a_);
  iobw.writeLE(server_time_);

  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_server_DH_params_fail::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadTLIntN(iobr, &new_nonce_hash_);

  return true;
}

bool TL_server_DH_params_fail::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteTLIntN(iobw, new_nonce_hash_);

  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_server_DH_params_ok::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadString(iobr, &encrypted_answer_);

  return true;
}

bool TL_server_DH_params_ok::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteString(iobw, encrypted_answer_);

  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_client_DH_inner_data::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  retry_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &g_b_);
  
  return true;
}

bool TL_client_DH_inner_data::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  iobw.write(retry_id_);
  WriteString(iobw, g_b_);

  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_set_client_DH_params::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadString(iobr, &encrypted_data_);

  return true;
}

bool TL_set_client_DH_params::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteString(iobw, encrypted_data_);

  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_dh_gen_retry::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadTLIntN(iobr, &new_nonce_hash2_);

  return true;
}

bool TL_dh_gen_retry::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteTLIntN(iobw, new_nonce_hash2_);

  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_dh_gen_fail::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadTLIntN(iobr, &new_nonce_hash3_);

  return true;
}

bool TL_dh_gen_fail::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteTLIntN(iobw, new_nonce_hash3_);

  return true;
}

//////////////////////////////////////////////////////////////////////////////
bool TL_dh_gen_ok::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadTLIntN(iobr, &new_nonce_hash1_);

  return true;
}

bool TL_dh_gen_ok::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteTLIntN(iobw, new_nonce_hash1_);

  return true;
}


bool TL_msgs_ack::Decode(IOBufReader& iobr) {
  msg_ids_.Decode(iobr);
  
  return true;
}

bool TL_msgs_ack::Encode(IOBufWriter& iobw) const {
  msg_ids_.Encode(iobw);
  
  return true;
}

bool TL_message::Decode(IOBufReader& iobr) {
  std::shared_ptr<TLObject> body_;
  msg_id_ = iobr.readLE<int64_t>();
  seqno_ = iobr.readLE<int>();
  bytes_ = iobr.readLE<int>();
  
  auto class_id = iobr.readLE<uint32_t>();
  LOG(INFO) << class_id;
  iobr.skip(bytes_ - sizeof(uint32_t));
  return true;
}

bool TL_message::Encode(IOBufWriter& iobw) const {
  return true;
}

bool TL_msg_container::Decode(IOBufReader& iobr) {
  auto sz = iobr.readLE<uint32_t>();
  for (uint32_t i=0; i<sz; ++i) {
    auto message = std::make_shared<TL_message>();
    iobr.skip(sizeof(uint32_t));
    message->Decode(iobr);
  }
  return true;
}

bool TL_msg_container::Encode(IOBufWriter& iobw) const {
  return true;
}


bool TL_destroy_session::Decode(IOBufReader& iobr) {
  session_id_ = iobr.readLE<int64_t>();

  return true;
}

bool TL_destroy_session::Encode(IOBufWriter& iobw) const {
  return true;
}

bool TL_destroy_session_ok::Decode(IOBufReader& iobr) {
  session_id_ = iobr.readLE<int64_t>();
  
  return true;
}

bool TL_destroy_session_ok::Encode(IOBufWriter& iobw) const {
  return true;
}

bool TL_destroy_session_none::Decode(IOBufReader& iobr) {
  session_id_ = iobr.readLE<int64_t>();
  
  return true;
}

bool TL_destroy_session_none::Encode(IOBufWriter& iobw) const {
  return true;
}

