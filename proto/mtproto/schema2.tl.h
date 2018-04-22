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

#ifndef PROTO_TELEGRAM_SCHEMA_TL_H
#define PROTO_TELEGRAM_SCHEMA_TL_H

#include "nebula/base/crypto_util/crypto_util.h"
#include "nebula/net/telegram/core/tl_object.h"
#include "nebula/net/telegram/core/tl_vector.h"
#include "nebula/base/self_register_factory_manager.h"

// req_pq#60469778 nonce:int128 = ResPQ;
class TL_req_pq : public TLObject {
public:
  enum {
    CLASS_ID = 0x60469778,
  };

  // static constexpr TLClassID CLASS_ID = 0x60469778;
  
  TLClassID GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("req_pq#0x60469778: {{nonce = {}}}",
                          ToHexStr(nonce_));
  }

  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }

private:
  TLInt128 nonce_;
};

// resPQ#05162463 nonce:int128 server_nonce:int128 pq:string server_public_key_fingerprints:Vector<long> = ResPQ;
class TL_resPQ : public TLObject {
public:
  enum {
    CLASS_ID = 0x05162463,
  };

  // static constexpr TLClassID CLASS_ID = 0x05162463;
  
  TLClassID GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("resPQ#0x05162463: {{nonce:{}, server_nonce:{}, pq:{}}}",
                          ToHexStr(nonce_),
                          ToHexStr(server_nonce_),
                          ToHexStr(pq_));
  }
  
  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }

  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }

  inline const TLString& pq() const { return pq_; }
  inline TLString* mutable_pq() { return &pq_; }
  inline void set_pq(const TLString & v) { pq_ = v; }

  inline size_t server_public_key_fingerprints_size() const { return server_public_key_fingerprints_.size(); }
  inline const TLInt64Vector& server_public_key_fingerprints() const { return server_public_key_fingerprints_; }
  inline int64_t server_public_key_fingerprints(int idx) const { return server_public_key_fingerprints_.vector()[idx]; }
  inline void add_server_public_key_fingerprints( int64_t val ) { server_public_key_fingerprints_.mutable_vector()->push_back(val); }
  inline TLInt64Vector* mutable_server_public_key_fingerprints() { return &server_public_key_fingerprints_; }
 
private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLString pq_;
  TLInt64Vector server_public_key_fingerprints_;
};

// p_q_inner_data#83c95aec pq:string p:string q:string nonce:int128 server_nonce:int128 new_nonce:int256 = P_Q_inner_data;
class TL_p_q_inner_data : public TLObject {
public:
  enum {
    CLASS_ID = 0x83c95aec,
  };

  // static constexpr TLClassID CLASS_ID = 0x83c95aec;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  size_t GetObjectSize() const override {
    return CalcObjSize(pq_) +
            CalcObjSize(p_) +
            CalcObjSize(q_) +
            CalcObjSize(nonce_) +
            CalcObjSize(server_nonce_) +
            CalcObjSize(new_nonce_);
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("p_q_inner_data#83c95aec: {{pq:{}, p:{}, q:{}, nonce:{}, server_nonce:{}, new_nonce:{}}}",
                          ToHexStr(pq_),
                          ToHexStr(p_),
                          ToHexStr(q_),
                          ToHexStr(nonce_),
                          ToHexStr(server_nonce_),
                          ToHexStr(new_nonce_));
  }

  ///////////////////////////////////////////////////////////////////////////////
  inline const TLString& pq() const { return pq_; }
  inline TLString* mutable_pq() { return &pq_; }
  inline void set_pq(const TLString & v) { pq_ = v; }

  inline const TLString& p() const { return p_; }
  inline TLString* mutable_p() { return &p_; }
  inline void set_p(const TLString & v) { p_ = v; }

  inline const TLString& q() const { return q_; }
  inline TLString* mutable_q() { return &q_; }
  inline void set_q(const TLString & v) { q_ = v; }

  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }
  
  inline const TLInt256& new_nonce() const { return new_nonce_; }
  inline TLInt256* mutable_new_nonce() { return &new_nonce_; }
  
private:
  TLString pq_;
  TLString p_;
  TLString q_;
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt256 new_nonce_;
};

// req_DH_params#d712e4be nonce:int128 server_nonce:int128 p:string q:string public_key_fingerprint:long encrypted_data:string = Server_DH_Params;
class TL_req_DH_params : public TLObject {
public:
  enum {
    CLASS_ID = 0xd712e4be,
  };

  // static constexpr TLClassID CLASS_ID = 0xd712e4be;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("req_DH_params#0xd712e4be: {{nonce:{}, server_nonce:{}, p:{}, q:{}, public_key_fingerprint_:{}, encrypted_data_:{}}}",
                          ToHexStr(nonce_),
                          ToHexStr(server_nonce_),
                          ToHexStr(p_),
                          ToHexStr(q_),
                          public_key_fingerprint_,
                          ToHexStr(encrypted_data_));
  }
  
  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }
  
  inline const TLString& p() const { return p_; }
  inline TLString* mutable_p() { return &p_; }
  inline void set_p(const TLString & v) { p_ = v; }
  
  inline const TLString& q() const { return q_; }
  inline TLString* mutable_q() { return &q_; }
  inline void set_q(const TLString & v) { q_ = v; }

  inline int64_t public_key_fingerprint() const { return public_key_fingerprint_; }
  inline void set_public_key_fingerprint(int64_t v) { public_key_fingerprint_ = v; }

  inline const TLString& encrypted_data() const { return encrypted_data_; }
  inline TLString* mutable_encrypted_data() { return &encrypted_data_; }
  inline void set_encrypted_data(const TLString & v) { encrypted_data_ = v; }
  
private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLString p_;
  TLString q_;
  int64_t public_key_fingerprint_;
  TLString encrypted_data_;
};

// server_DH_inner_data#b5890dba nonce:int128 server_nonce:int128 g:int dh_prime:string g_a:string server_time:int = Server_DH_inner_data;
class TL_server_DH_inner_data : public TLObject {
public:
  enum {
    CLASS_ID = 0xb5890dba,
  };

  // static constexpr TLClassID CLASS_ID = 0xb5890dba;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  size_t GetObjectSize() const override {
    return CalcObjSize(nonce_) +
            CalcObjSize(server_nonce_) +
            4 +
            CalcObjSize(dh_prime_) +
            CalcObjSize(g_a_) +
            4;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("server_DH_inner_data#b5890dba: {{nonce:{}, server_nonce:{}, g:{}, dh_prime_:{}, g_a_:{}, server_time_:{}}}",
                          ToHexStr(nonce_),
                          ToHexStr(server_nonce_),
                          g_,
                          ToHexStr(dh_prime_),
                          ToHexStr(g_a_),
                          server_time_);

  }
  
  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }

  inline int32_t g() const { return g_; }
  inline void set_g(int32_t v) { g_ = v; }

  inline const TLString& dh_prime() const { return dh_prime_; }
  inline TLString* mutable_dh_prime() { return &dh_prime_; }
  inline void set_dh_prime(const TLString & v) { dh_prime_ = v; }

  inline const TLString& g_a() const { return g_a_; }
  inline TLString* mutable_g_a() { return &g_a_; }
  inline void set_g_a(const TLString & v) { g_a_ = v; }
  
  inline int32_t server_time() const { return server_time_; }
  inline void set_server_time(int32_t v) { server_time_ = v; }

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  int32_t g_;
  TLString dh_prime_;
  TLString g_a_;
  int32_t server_time_;
};

// server_DH_params_fail#79cb045d nonce:int128 server_nonce:int128 new_nonce_hash:int128 = Server_DH_Params;
// server_DH_params_ok#d0e8075c nonce:int128 server_nonce:int128 encrypted_answer:string = Server_DH_Params;
class Server_DH_Params : public TLObject {
public:
  virtual ~Server_DH_Params() override = default;
};

class TL_server_DH_params_fail : public Server_DH_Params {
public:
  enum {
    CLASS_ID = 0x79cb045d,
  };

  // static constexpr TLClassID CLASS_ID = 0x79cb045d;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "TL_server_DH_params_fail#79cb045d";
  }
  
  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }

  inline const TLInt128& new_nonce_hash() const { return new_nonce_hash_; }
  inline TLInt128* mutable_new_nonce_hash() { return &new_nonce_hash_; }

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt128 new_nonce_hash_;
};

class TL_server_DH_params_ok : public Server_DH_Params {
public:
  enum {
    CLASS_ID = 0xd0e8075c,
  };

  // static constexpr TLClassID CLASS_ID = 0xd0e8075c;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("server_DH_inner_data#b5890dba: {{nonce:{}, server_nonce:{}, encrypted_answer_:{}}}",
                          ToHexStr(nonce_),
                          ToHexStr(server_nonce_),
                          ToHexStr(encrypted_answer_));

  }
  
  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }
  
  inline const TLString& encrypted_answer() const { return encrypted_answer_; }
  inline TLString* mutable_encrypted_answer() { return &encrypted_answer_; }
  inline void set_encrypted_answer(const TLString & v) { encrypted_answer_ = v; }
  
private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  // TLInt128 new_nonce_hash_;
  TLString encrypted_answer_;
};

// client_DH_inner_data#6643b654 nonce:int128 server_nonce:int128 retry_id:long g_b:string = Client_DH_Inner_Data;
class TL_client_DH_inner_data : public TLObject {
public:
  enum {
    CLASS_ID = 0x6643b654,
  };

  // static constexpr TLClassID CLASS_ID = 0x6643b654;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("client_DH_inner_data#6643b654: {{nonce:{}, server_nonce:{}, retry_id:{}, g_b:{}}}",
                          ToHexStr(nonce_),
                          ToHexStr(server_nonce_),
                          retry_id_,
                          ToHexStr(g_b_));

  }
  
  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }

  inline int64_t retry_id() const { return retry_id_; }
  inline void set_retry_id(int64_t v) { retry_id_ = v; }
  
  inline const TLString& g_b() const { return g_b_; }
  inline TLString* mutable_g_b() { return &g_b_; }
  inline void set_g_b(const TLString & v) { g_b_ = v; }
  
private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  int64_t retry_id_;
  TLString g_b_;
};


// set_client_DH_params#f5045f1f nonce:int128 server_nonce:int128 encrypted_data:string = Set_client_DH_params_answer;
class TL_set_client_DH_params : public TLObject {
public:
  enum {
    CLASS_ID = 0xf5045f1f,
  };

  // static constexpr TLClassID CLASS_ID = 0xf5045f1f;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return folly::sformat("set_client_DH_params#f5045f1f: {{nonce:{}, server_nonce:{}, encrypted_data:{}}}",
                          ToHexStr(nonce_),
                          ToHexStr(server_nonce_),
                          ToHexStr(encrypted_data_));

  }
  
  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }
  
  inline const TLString& encrypted_data() const { return encrypted_data_; }
  inline TLString* mutable_encrypted_data() { return &encrypted_data_; }
  inline void set_encrypted_data(const TLString & v) { encrypted_data_ = v; }

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLString encrypted_data_;
};

// dh_gen_ok#3bcbf734 nonce:int128 server_nonce:int128 new_nonce_hash1:int128 = Set_client_DH_params_answer;
// dh_gen_retry#46dc1fb9 nonce:int128 server_nonce:int128 new_nonce_hash2:int128 = Set_client_DH_params_answer;
// dh_gen_fail#a69dae02 nonce:int128 server_nonce:int128 new_nonce_hash3:int128 = Set_client_DH_params_answer;
class Set_client_DH_params_answer : public TLObject {
public:
  virtual ~Set_client_DH_params_answer() override = default;
};

class TL_dh_gen_retry : public Set_client_DH_params_answer {
public:
  enum {
    CLASS_ID = 0x46dc1fb9,
  };

  // static constexpr TLClassID CLASS_ID = 0x46dc1fb9;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "set_client_DH_params#f5045f1f";
  }

  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }
  
  inline const TLInt128& new_nonce_hash2() const { return new_nonce_hash2_; }
  inline TLInt128* mutable_new_nonce_hash2() { return &new_nonce_hash2_; }
  
private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt128 new_nonce_hash2_;
};

class TL_dh_gen_fail : public Set_client_DH_params_answer {
public:
  enum {
    CLASS_ID = 0xa69dae02,
  };

  // static constexpr TLClassID CLASS_ID = 0xa69dae02;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "set_client_DH_params#a69dae02";
  }

  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }
  
  inline const TLInt128& new_nonce_hash3() const { return new_nonce_hash3_; }
  inline TLInt128* mutable_new_nonce_hash3() { return &new_nonce_hash3_; }

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt128 new_nonce_hash3_;
};

class TL_dh_gen_ok : public Set_client_DH_params_answer {
public:
  enum {
    CLASS_ID = 0x3bcbf734,
  };

  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    // return "set_client_DH_params#3bcbf734";
    return folly::sformat("TL_dh_gen_ok#0x3bcbf734: {{nonce:{}, server_nonce:{}, new_nonce_hash1:{}}}",
                          ToHexStr(nonce_),
                          ToHexStr(server_nonce_),
                          ToHexStr(new_nonce_hash1_));

  }

  ///////////////////////////////////////////////////////////////////////////////
  inline const TLInt128& nonce() const { return nonce_; }
  inline TLInt128* mutable_nonce() { return &nonce_; }
  
  inline const TLInt128& server_nonce() const { return server_nonce_; }
  inline TLInt128* mutable_server_nonce() { return &server_nonce_; }
  
  inline const TLInt128& new_nonce_hash1() const { return new_nonce_hash1_; }
  inline TLInt128* mutable_new_nonce_hash1() { return &new_nonce_hash1_; }

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt128 new_nonce_hash1_;
};


class TL_msgs_ack : public TLObject {
public:
  enum {
    CLASS_ID = 0x62d6b459,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "msgs_ack#0x62d6b459";
  }
  
  inline size_t msg_ids_size() const { return msg_ids_.size(); }
  inline const TLInt64Vector& msg_ids() const { return msg_ids_; }
  inline int64_t msg_ids(int idx) const { return msg_ids_.vector()[idx]; }
  inline void add_msg_ids( int64_t val ) { msg_ids_.mutable_vector()->push_back(val); }
  inline TLInt64Vector* mutable_msg_ids() { return &msg_ids_; }

private:
  TLInt64Vector msg_ids_;
/*
public:
  static const uint32_t constructor = 0x62d6b459;
  
  std::vector<int64_ msg_ids;
  
  static TL_msgs_ack *TLdeserialize(NativeByteBuffer *stream, uint32_t constructor, bool &error);
  void readParams(NativeByteBuffer *stream, bool &error);
  void serializeToStream(NativeByteBuffer *stream);
 */
};

//message#0x5bb8e511 msg_id:long seqno:int bytes:int body:Object = Message; // parsed manually
class TL_message : public TLObject {
public:
  enum {
    CLASS_ID = 0x5bb8e511,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "message#0x5bb8e511";
  }
  
private:
  int64_t msg_id_;
  int seqno_;
  int bytes_;
  std::shared_ptr<TLObject> body_;
};

//msg_container#73f1f8dc messages:vector<message> = MessageContainer; // parsed manually
class TL_msg_container : public TLObject {
public:
  enum {
    CLASS_ID = 0x73f1f8dc,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "msg_container#73f1f8dc";
  }
  
private:
  std::vector<std::shared_ptr<TL_message>> messages_;
};

//msg_copy#e06046b2 orig_message:Message = MessageCopy; // parsed manually, not used - use msg_container
class TL_msg_copy : public TLObject {
public:
  enum {
    CLASS_ID = 0xe06046b2,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "msg_copy#e06046b2";
  }
  
private:
  std::shared_ptr<TL_message> orig_message_;
};

//gzip_packed#3072cfa1 packed_data:string = Object; // parsed manually
class TL_gzip_packed : public TLObject {
public:
  enum {
    CLASS_ID = 0x3072cfa1,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "TL_gzip_packed#3072cfa1";
  }
  
private:
  TLString packed_data_;
};

// destroy_session#e7512126 session_id:long = DestroySessionRes;
class TL_destroy_session : public TLObject {
public:
  enum {
    CLASS_ID = 0xe7512126,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "destroy_session#e7512126";
  }
  
private:
  int64_t session_id_;
};

// destroy_session_ok#e22045fc session_id:long = DestroySessionRes;
// destroy_session_none#62d350c9 session_id:long = DestroySessionRes;
class DestroySessionRes : public TLObject {
public:
  virtual ~DestroySessionRes() override = default;
};

class TL_destroy_session_ok : public DestroySessionRes {
public:
  enum {
    CLASS_ID = 0xe22045fc,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "destroy_session_ok#e22045fc";
  }
  
private:
  int64_t session_id_;
};

class TL_destroy_session_none : public DestroySessionRes {
public:
  enum {
    CLASS_ID = 0x62d350c9,
  };
  
  // static constexpr TLClassID CLASS_ID = 0x3bcbf734;
  
  uint32_t GetClassID() const override {
    return CLASS_ID;
  }
  
  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;
  
  std::string ToString() const override {
    return "destroy_session_none#62d350c9";
  }
  
private:
  int64_t session_id_;
};



using TLObjectFactory = nebula::SelfRegisterFactoryManager<TLObject, uint32_t>;

#endif
