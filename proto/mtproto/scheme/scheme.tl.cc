/*
WARNING! All changes made in this file will be lost!
Created from 'scheme.tl' by 'codegen_scheme'

This file is part of Telegram Desktop,
the official desktop version of Telegram messaging app, see https://telegram.org

Telegram Desktop is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

It is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

Full license: https://github.com/telegramdesktop/tdesktop/blob/master/LICENSE
Copyright (c) 2014 John Preston, https://desktop.telegram.org
*/
#include "scheme.h"

using Types = QVector<mtpTypeId>;
using StagesFlags = QVector<int32>;

void Serialize_resPQ(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ resPQ");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pq: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  server_public_key_fingerprints: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_p_q_inner_data(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ p_q_inner_data");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  pq: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  p: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  q: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  new_nonce: "); ++stages.back(); types.push_back(mtpc_int256+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_server_DH_params_fail(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ server_DH_params_fail");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  new_nonce_hash: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_server_DH_params_ok(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ server_DH_params_ok");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  encrypted_answer: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_server_DH_inner_data(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ server_DH_inner_data");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  g: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  dh_prime: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  g_a: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  server_time: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_client_DH_inner_data(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ client_DH_inner_data");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  retry_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  g_b: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_dh_gen_ok(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ dh_gen_ok");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  new_nonce_hash1: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_dh_gen_retry(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ dh_gen_retry");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  new_nonce_hash2: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_dh_gen_fail(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ dh_gen_fail");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  new_nonce_hash3: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_destroy_auth_key_ok(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ destroy_auth_key_ok }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_destroy_auth_key_none(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ destroy_auth_key_none }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_destroy_auth_key_fail(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ destroy_auth_key_fail }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_msgs_ack(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ msgs_ack");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_ids: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_bad_msg_notification(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ bad_msg_notification");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  bad_msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  bad_msg_seqno: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  error_code: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_bad_server_salt(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ bad_server_salt");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  bad_msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  bad_msg_seqno: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  error_code: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  new_server_salt: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_msgs_state_req(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ msgs_state_req");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_ids: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_msgs_state_info(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ msgs_state_info");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  req_msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  info: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_msgs_all_info(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ msgs_all_info");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_ids: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  info: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_msg_detailed_info(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ msg_detailed_info");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  answer_msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  status: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_msg_new_detailed_info(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ msg_new_detailed_info");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  answer_msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  status: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_msg_resend_req(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ msg_resend_req");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_ids: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_rpc_error(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ rpc_error");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  error_code: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  error_message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_rpc_answer_unknown(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ rpc_answer_unknown }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_rpc_answer_dropped_running(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ rpc_answer_dropped_running }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_rpc_answer_dropped(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ rpc_answer_dropped");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  seq_no: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_future_salt(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ future_salt");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  valid_since: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  valid_until: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  salt: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_future_salts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ future_salts");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  req_msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  now: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  salts: "); ++stages.back(); types.push_back(mtpc_vector); vtypes.push_back(mtpc_future_salt); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pong(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pong");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  ping_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_destroy_session_ok(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ destroy_session_ok");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  session_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_destroy_session_none(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ destroy_session_none");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  session_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_new_session_created(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ new_session_created");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  first_msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  unique_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  server_salt: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_http_wait(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ http_wait");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  max_delay: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  wait_after: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  max_wait: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_boolFalse(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ boolFalse }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_boolTrue(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ boolTrue }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_true(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ true }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_error(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ error");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  code: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_null(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ null }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPeerEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPeerEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPeerSelf(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPeerSelf }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPeerChat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPeerChat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPeerUser(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPeerUser");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPeerChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPeerChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputUserEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputUserEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputUserSelf(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputUserSelf }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputUser(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputUser");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPhoneContact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPhoneContact");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  client_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  first_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  last_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  parts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  md5_checksum: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputFileBig(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputFileBig");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  parts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMediaEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMediaUploadedPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputMediaUploadedPhoto::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaUploadedPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  file: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  stickers: "); ++stages.back(); if (flag & MTPDinputMediaUploadedPhoto::Flag::f_stickers) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaGeoPoint(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaGeoPoint");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  geo_point: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaContact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaContact");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  first_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  last_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaUploadedDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputMediaUploadedDocument::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaUploadedDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  file: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  mime_type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  attributes: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  stickers: "); ++stages.back(); if (flag & MTPDinputMediaUploadedDocument::Flag::f_stickers) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaUploadedThumbDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputMediaUploadedThumbDocument::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaUploadedThumbDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  file: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  thumb: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  mime_type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  attributes: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  stickers: "); ++stages.back(); if (flag & MTPDinputMediaUploadedThumbDocument::Flag::f_stickers) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaVenue(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaVenue");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  geo_point: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  address: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  provider: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  venue_id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaGifExternal(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaGifExternal");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  q: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaPhotoExternal(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaPhotoExternal");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaDocumentExternal(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaDocumentExternal");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaGame(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaGame");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMediaInvoice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputMediaInvoice::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMediaInvoice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  description: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  photo: "); ++stages.back(); if (flag & MTPDinputMediaInvoice::Flag::f_photo) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  invoice: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  payload: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  provider: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  start_param: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputChatPhotoEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputChatPhotoEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputChatUploadedPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputChatUploadedPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  file: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputChatPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputChatPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputGeoPointEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputGeoPointEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputGeoPoint(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputGeoPoint");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  lat: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  long: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPhotoEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPhotoEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputFileLocation(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputFileLocation");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  volume_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  local_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  secret: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputEncryptedFileLocation(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputEncryptedFileLocation");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputDocumentFileLocation(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputDocumentFileLocation");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputAppEvent(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputAppEvent");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  time: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  peer: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  data: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_peerUser(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ peerUser");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_peerChat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ peerChat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_peerChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ peerChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_storage_fileUnknown(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_fileUnknown }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_filePartial(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_filePartial }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_fileJpeg(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_fileJpeg }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_fileGif(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_fileGif }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_filePng(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_filePng }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_filePdf(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_filePdf }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_fileMp3(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_fileMp3 }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_fileMov(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_fileMov }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_fileMp4(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_fileMp4 }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_storage_fileWebp(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ storage_fileWebp }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_fileLocationUnavailable(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ fileLocationUnavailable");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  volume_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  local_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  secret: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_fileLocation(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ fileLocation");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  dc_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  volume_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  local_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  secret: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_userEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ userEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_user(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDuser::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ user");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  self: "); ++stages.back(); if (flag & MTPDuser::Flag::f_self) { to.add("YES [ BY BIT 10 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 10 IN FIELD flags ]"); } break;
	case 2: to.add("  contact: "); ++stages.back(); if (flag & MTPDuser::Flag::f_contact) { to.add("YES [ BY BIT 11 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 11 IN FIELD flags ]"); } break;
	case 3: to.add("  mutual_contact: "); ++stages.back(); if (flag & MTPDuser::Flag::f_mutual_contact) { to.add("YES [ BY BIT 12 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 12 IN FIELD flags ]"); } break;
	case 4: to.add("  deleted: "); ++stages.back(); if (flag & MTPDuser::Flag::f_deleted) { to.add("YES [ BY BIT 13 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 13 IN FIELD flags ]"); } break;
	case 5: to.add("  bot: "); ++stages.back(); if (flag & MTPDuser::Flag::f_bot) { to.add("YES [ BY BIT 14 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 14 IN FIELD flags ]"); } break;
	case 6: to.add("  bot_chat_history: "); ++stages.back(); if (flag & MTPDuser::Flag::f_bot_chat_history) { to.add("YES [ BY BIT 15 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 15 IN FIELD flags ]"); } break;
	case 7: to.add("  bot_nochats: "); ++stages.back(); if (flag & MTPDuser::Flag::f_bot_nochats) { to.add("YES [ BY BIT 16 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 16 IN FIELD flags ]"); } break;
	case 8: to.add("  verified: "); ++stages.back(); if (flag & MTPDuser::Flag::f_verified) { to.add("YES [ BY BIT 17 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 17 IN FIELD flags ]"); } break;
	case 9: to.add("  restricted: "); ++stages.back(); if (flag & MTPDuser::Flag::f_restricted) { to.add("YES [ BY BIT 18 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 18 IN FIELD flags ]"); } break;
	case 10: to.add("  min: "); ++stages.back(); if (flag & MTPDuser::Flag::f_min) { to.add("YES [ BY BIT 20 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 20 IN FIELD flags ]"); } break;
	case 11: to.add("  bot_inline_geo: "); ++stages.back(); if (flag & MTPDuser::Flag::f_bot_inline_geo) { to.add("YES [ BY BIT 21 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 21 IN FIELD flags ]"); } break;
	case 12: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 13: to.add("  access_hash: "); ++stages.back(); if (flag & MTPDuser::Flag::f_access_hash) { types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 14: to.add("  first_name: "); ++stages.back(); if (flag & MTPDuser::Flag::f_first_name) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 15: to.add("  last_name: "); ++stages.back(); if (flag & MTPDuser::Flag::f_last_name) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 16: to.add("  username: "); ++stages.back(); if (flag & MTPDuser::Flag::f_username) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 17: to.add("  phone: "); ++stages.back(); if (flag & MTPDuser::Flag::f_phone) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 18: to.add("  photo: "); ++stages.back(); if (flag & MTPDuser::Flag::f_photo) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 19: to.add("  status: "); ++stages.back(); if (flag & MTPDuser::Flag::f_status) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 20: to.add("  bot_info_version: "); ++stages.back(); if (flag & MTPDuser::Flag::f_bot_info_version) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 14 IN FIELD flags ]"); } break;
	case 21: to.add("  restriction_reason: "); ++stages.back(); if (flag & MTPDuser::Flag::f_restriction_reason) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 18 IN FIELD flags ]"); } break;
	case 22: to.add("  bot_inline_placeholder: "); ++stages.back(); if (flag & MTPDuser::Flag::f_bot_inline_placeholder) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 19 IN FIELD flags ]"); } break;
	case 23: to.add("  lang_code: "); ++stages.back(); if (flag & MTPDuser::Flag::f_lang_code) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 22 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_userProfilePhotoEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ userProfilePhotoEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_userProfilePhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ userProfilePhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  photo_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  photo_small: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  photo_big: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_userStatusEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ userStatusEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_userStatusOnline(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ userStatusOnline");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  expires: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_userStatusOffline(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ userStatusOffline");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  was_online: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_userStatusRecently(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ userStatusRecently }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_userStatusLastWeek(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ userStatusLastWeek }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_userStatusLastMonth(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ userStatusLastMonth }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_chatEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDchat::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  creator: "); ++stages.back(); if (flag & MTPDchat::Flag::f_creator) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  kicked: "); ++stages.back(); if (flag & MTPDchat::Flag::f_kicked) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  left: "); ++stages.back(); if (flag & MTPDchat::Flag::f_left) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  admins_enabled: "); ++stages.back(); if (flag & MTPDchat::Flag::f_admins_enabled) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 5: to.add("  admin: "); ++stages.back(); if (flag & MTPDchat::Flag::f_admin) { to.add("YES [ BY BIT 4 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 6: to.add("  deactivated: "); ++stages.back(); if (flag & MTPDchat::Flag::f_deactivated) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 7: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  participants_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 11: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 12: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 13: to.add("  migrated_to: "); ++stages.back(); if (flag & MTPDchat::Flag::f_migrated_to) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatForbidden(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatForbidden");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDchannel::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  creator: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_creator) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  kicked: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_kicked) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  left: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_left) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  editor: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_editor) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 5: to.add("  moderator: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_moderator) { to.add("YES [ BY BIT 4 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 6: to.add("  broadcast: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_broadcast) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 7: to.add("  verified: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_verified) { to.add("YES [ BY BIT 7 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	case 8: to.add("  megagroup: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_megagroup) { to.add("YES [ BY BIT 8 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 8 IN FIELD flags ]"); } break;
	case 9: to.add("  restricted: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_restricted) { to.add("YES [ BY BIT 9 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 9 IN FIELD flags ]"); } break;
	case 10: to.add("  democracy: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_democracy) { to.add("YES [ BY BIT 10 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 10 IN FIELD flags ]"); } break;
	case 11: to.add("  signatures: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_signatures) { to.add("YES [ BY BIT 11 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 11 IN FIELD flags ]"); } break;
	case 12: to.add("  min: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_min) { to.add("YES [ BY BIT 12 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 12 IN FIELD flags ]"); } break;
	case 13: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 14: to.add("  access_hash: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_access_hash) { types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 13 IN FIELD flags ]"); } break;
	case 15: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 16: to.add("  username: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_username) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 17: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 18: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 19: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 20: to.add("  restriction_reason: "); ++stages.back(); if (flag & MTPDchannel::Flag::f_restriction_reason) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 9 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelForbidden(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDchannelForbidden::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelForbidden");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  broadcast: "); ++stages.back(); if (flag & MTPDchannelForbidden::Flag::f_broadcast) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 2: to.add("  megagroup: "); ++stages.back(); if (flag & MTPDchannelForbidden::Flag::f_megagroup) { to.add("YES [ BY BIT 8 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 8 IN FIELD flags ]"); } break;
	case 3: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatFull(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatFull");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  participants: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  chat_photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  notify_settings: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  exported_invite: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  bot_info: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelFull(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDchannelFull::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelFull");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  can_view_participants: "); ++stages.back(); if (flag & MTPDchannelFull::Flag::f_can_view_participants) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 2: to.add("  can_set_username: "); ++stages.back(); if (flag & MTPDchannelFull::Flag::f_can_set_username) { to.add("YES [ BY BIT 6 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 3: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  about: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  participants_count: "); ++stages.back(); if (flag & MTPDchannelFull::Flag::f_participants_count) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 6: to.add("  admins_count: "); ++stages.back(); if (flag & MTPDchannelFull::Flag::f_admins_count) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 7: to.add("  kicked_count: "); ++stages.back(); if (flag & MTPDchannelFull::Flag::f_kicked_count) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 8: to.add("  read_inbox_max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  read_outbox_max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  unread_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 11: to.add("  chat_photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 12: to.add("  notify_settings: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 13: to.add("  exported_invite: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 14: to.add("  bot_info: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 15: to.add("  migrated_from_chat_id: "); ++stages.back(); if (flag & MTPDchannelFull::Flag::f_migrated_from_chat_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 16: to.add("  migrated_from_max_id: "); ++stages.back(); if (flag & MTPDchannelFull::Flag::f_migrated_from_max_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 17: to.add("  pinned_msg_id: "); ++stages.back(); if (flag & MTPDchannelFull::Flag::f_pinned_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatParticipant(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatParticipant");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  inviter_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatParticipantCreator(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatParticipantCreator");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatParticipantAdmin(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatParticipantAdmin");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  inviter_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatParticipantsForbidden(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDchatParticipantsForbidden::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatParticipantsForbidden");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  self_participant: "); ++stages.back(); if (flag & MTPDchatParticipantsForbidden::Flag::f_self_participant) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatParticipants(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatParticipants");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  participants: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatPhotoEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ chatPhotoEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_chatPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  photo_small: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  photo_big: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_message(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ message");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  out: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_out) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  mentioned: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_mentioned) { to.add("YES [ BY BIT 4 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 3: to.add("  media_unread: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_media_unread) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 4: to.add("  silent: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_silent) { to.add("YES [ BY BIT 13 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 13 IN FIELD flags ]"); } break;
	case 5: to.add("  post: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_post) { to.add("YES [ BY BIT 14 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 14 IN FIELD flags ]"); } break;
	case 6: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  from_id: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_from_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 8 IN FIELD flags ]"); } break;
	case 8: to.add("  to_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  fwd_from: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_fwd_from) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 10: to.add("  via_bot_id: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_via_bot_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 11 IN FIELD flags ]"); } break;
	case 11: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 12: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 13: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 14: to.add("  media: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_media) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 9 IN FIELD flags ]"); } break;
	case 15: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 16: to.add("  entities: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	case 17: to.add("  views: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_views) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 10 IN FIELD flags ]"); } break;
	case 18: to.add("  edit_date: "); ++stages.back(); if (flag & MTPDmessage::Flag::f_edit_date) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 15 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageService(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessageService::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageService");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  out: "); ++stages.back(); if (flag & MTPDmessageService::Flag::f_out) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  mentioned: "); ++stages.back(); if (flag & MTPDmessageService::Flag::f_mentioned) { to.add("YES [ BY BIT 4 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 3: to.add("  media_unread: "); ++stages.back(); if (flag & MTPDmessageService::Flag::f_media_unread) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 4: to.add("  silent: "); ++stages.back(); if (flag & MTPDmessageService::Flag::f_silent) { to.add("YES [ BY BIT 13 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 13 IN FIELD flags ]"); } break;
	case 5: to.add("  post: "); ++stages.back(); if (flag & MTPDmessageService::Flag::f_post) { to.add("YES [ BY BIT 14 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 14 IN FIELD flags ]"); } break;
	case 6: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  from_id: "); ++stages.back(); if (flag & MTPDmessageService::Flag::f_from_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 8 IN FIELD flags ]"); } break;
	case 8: to.add("  to_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPDmessageService::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 10: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 11: to.add("  action: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageMediaEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messageMediaEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messageMediaPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageMediaPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageMediaGeo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageMediaGeo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  geo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageMediaContact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageMediaContact");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  first_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  last_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageMediaUnsupported(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messageMediaUnsupported }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messageMediaDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageMediaDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  document: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageMediaWebPage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageMediaWebPage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  webpage: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageMediaVenue(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageMediaVenue");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  geo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  address: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  provider: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  venue_id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageMediaGame(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageMediaGame");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  game: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageMediaInvoice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessageMediaInvoice::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageMediaInvoice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  shipping_address_requested: "); ++stages.back(); if (flag & MTPDmessageMediaInvoice::Flag::f_shipping_address_requested) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  test: "); ++stages.back(); if (flag & MTPDmessageMediaInvoice::Flag::f_test) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 3: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  description: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  photo: "); ++stages.back(); if (flag & MTPDmessageMediaInvoice::Flag::f_photo) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 6: to.add("  receipt_msg_id: "); ++stages.back(); if (flag & MTPDmessageMediaInvoice::Flag::f_receipt_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 7: to.add("  currency: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  total_amount: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  start_param: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messageActionEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messageActionChatCreate(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChatCreate");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionChatEditTitle(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChatEditTitle");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionChatEditPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChatEditPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionChatDeletePhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messageActionChatDeletePhoto }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messageActionChatAddUser(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChatAddUser");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  users: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionChatDeleteUser(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChatDeleteUser");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionChatJoinedByLink(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChatJoinedByLink");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  inviter_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionChannelCreate(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChannelCreate");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionChatMigrateTo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChatMigrateTo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionChannelMigrateFrom(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionChannelMigrateFrom");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionPinMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messageActionPinMessage }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messageActionHistoryClear(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messageActionHistoryClear }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messageActionGameScore(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionGameScore");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  game_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  score: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionPaymentSentMe(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessageActionPaymentSentMe::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionPaymentSentMe");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  currency: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  total_amount: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  payload: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  info: "); ++stages.back(); if (flag & MTPDmessageActionPaymentSentMe::Flag::f_info) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 5: to.add("  shipping_option_id: "); ++stages.back(); if (flag & MTPDmessageActionPaymentSentMe::Flag::f_shipping_option_id) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 6: to.add("  charge: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionPaymentSent(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionPaymentSent");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  currency: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  total_amount: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageActionPhoneCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessageActionPhoneCall::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageActionPhoneCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  call_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  reason: "); ++stages.back(); if (flag & MTPDmessageActionPhoneCall::Flag::f_reason) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 3: to.add("  duration: "); ++stages.back(); if (flag & MTPDmessageActionPhoneCall::Flag::f_duration) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_dialog(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDdialog::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ dialog");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pinned: "); ++stages.back(); if (flag & MTPDdialog::Flag::f_pinned) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 2: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  top_message: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  read_inbox_max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  read_outbox_max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  unread_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  notify_settings: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  pts: "); ++stages.back(); if (flag & MTPDdialog::Flag::f_pts) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 9: to.add("  draft: "); ++stages.back(); if (flag & MTPDdialog::Flag::f_draft) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photoEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photoEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDphoto::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  has_stickers: "); ++stages.back(); if (flag & MTPDphoto::Flag::f_has_stickers) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  sizes: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photoSizeEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photoSizeEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photoSize(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photoSize");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  location: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  w: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  h: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  size: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photoCachedSize(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photoCachedSize");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  location: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  w: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  h: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_geoPointEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ geoPointEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_geoPoint(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ geoPoint");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  long: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  lat: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_checkedPhone(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_checkedPhone");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_registered: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_sentCode(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDauth_sentCode::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_sentCode");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_registered: "); ++stages.back(); if (flag & MTPDauth_sentCode::Flag::f_phone_registered) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  type: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  phone_code_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  next_type: "); ++stages.back(); if (flag & MTPDauth_sentCode::Flag::f_next_type) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 5: to.add("  timeout: "); ++stages.back(); if (flag & MTPDauth_sentCode::Flag::f_timeout) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_authorization(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDauth_authorization::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_authorization");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  tmp_sessions: "); ++stages.back(); if (flag & MTPDauth_authorization::Flag::f_tmp_sessions) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  user: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_exportedAuthorization(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_exportedAuthorization");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputNotifyPeer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputNotifyPeer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputNotifyUsers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputNotifyUsers }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputNotifyChats(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputNotifyChats }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputNotifyAll(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputNotifyAll }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPeerNotifyEventsEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPeerNotifyEventsEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPeerNotifyEventsAll(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPeerNotifyEventsAll }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPeerNotifySettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputPeerNotifySettings::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPeerNotifySettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  show_previews: "); ++stages.back(); if (flag & MTPDinputPeerNotifySettings::Flag::f_show_previews) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  silent: "); ++stages.back(); if (flag & MTPDinputPeerNotifySettings::Flag::f_silent) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  mute_until: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  sound: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_peerNotifyEventsEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ peerNotifyEventsEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_peerNotifyEventsAll(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ peerNotifyEventsAll }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_peerNotifySettingsEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ peerNotifySettingsEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_peerNotifySettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpeerNotifySettings::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ peerNotifySettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  show_previews: "); ++stages.back(); if (flag & MTPDpeerNotifySettings::Flag::f_show_previews) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  silent: "); ++stages.back(); if (flag & MTPDpeerNotifySettings::Flag::f_silent) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  mute_until: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  sound: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_peerSettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpeerSettings::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ peerSettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  report_spam: "); ++stages.back(); if (flag & MTPDpeerSettings::Flag::f_report_spam) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_wallPaper(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ wallPaper");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  sizes: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  color: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_wallPaperSolid(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ wallPaperSolid");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  bg_color: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  color: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputReportReasonSpam(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputReportReasonSpam }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputReportReasonViolence(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputReportReasonViolence }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputReportReasonPornography(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputReportReasonPornography }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputReportReasonOther(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputReportReasonOther");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_userFull(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDuserFull::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ userFull");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  blocked: "); ++stages.back(); if (flag & MTPDuserFull::Flag::f_blocked) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  phone_calls_available: "); ++stages.back(); if (flag & MTPDuserFull::Flag::f_phone_calls_available) { to.add("YES [ BY BIT 4 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 3: to.add("  phone_calls_private: "); ++stages.back(); if (flag & MTPDuserFull::Flag::f_phone_calls_private) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 4: to.add("  user: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  about: "); ++stages.back(); if (flag & MTPDuserFull::Flag::f_about) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 6: to.add("  link: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  profile_photo: "); ++stages.back(); if (flag & MTPDuserFull::Flag::f_profile_photo) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 8: to.add("  notify_settings: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  bot_info: "); ++stages.back(); if (flag & MTPDuserFull::Flag::f_bot_info) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 10: to.add("  common_chats_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contact");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  mutual: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_importedContact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ importedContact");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  client_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contactBlocked(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contactBlocked");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contactStatus(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contactStatus");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  status: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_link(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_link");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  my_link: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  foreign_link: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  user: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_contactsNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ contacts_contactsNotModified }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_contacts_contacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_contacts");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  contacts: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_importedContacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_importedContacts");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  imported: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  retry_contacts: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_blocked(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_blocked");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  blocked: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_blockedSlice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_blockedSlice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  blocked: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_dialogs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_dialogs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  dialogs: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_dialogsSlice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_dialogsSlice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  dialogs: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_messages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_messages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_messagesSlice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_messagesSlice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_channelMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_channelMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_chats(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_chats");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_chatsSlice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_chatsSlice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_chatFull(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_chatFull");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  full_chat: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_affectedHistory(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_affectedHistory");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMessagesFilterEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterPhotos(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterPhotos }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterVideo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterVideo }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterPhotoVideo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterPhotoVideo }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterPhotoVideoDocuments(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterPhotoVideoDocuments }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterDocument }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterUrl(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterUrl }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterGif(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterGif }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterVoice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterVoice }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterMusic(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterMusic }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterChatPhotos(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterChatPhotos }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterPhoneCalls(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputMessagesFilterPhoneCalls::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMessagesFilterPhoneCalls");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  missed: "); ++stages.back(); if (flag & MTPDinputMessagesFilterPhoneCalls::Flag::f_missed) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMessagesFilterRoundVoice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterRoundVoice }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputMessagesFilterRoundVideo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputMessagesFilterRoundVideo }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updateNewMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateNewMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateMessageID(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateMessageID");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateDeleteMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateDeleteMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  messages: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateUserTyping(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateUserTyping");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  action: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChatUserTyping(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChatUserTyping");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  action: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChatParticipants(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChatParticipants");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  participants: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateUserStatus(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateUserStatus");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  status: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateUserName(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateUserName");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  first_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  last_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  username: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateUserPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateUserPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  previous: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateContactRegistered(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateContactRegistered");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateContactLink(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateContactLink");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  my_link: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  foreign_link: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateNewEncryptedMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateNewEncryptedMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  qts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateEncryptedChatTyping(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateEncryptedChatTyping");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateEncryption(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateEncryption");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateEncryptedMessagesRead(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateEncryptedMessagesRead");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChatParticipantAdd(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChatParticipantAdd");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  inviter_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChatParticipantDelete(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChatParticipantDelete");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateDcOptions(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateDcOptions");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  dc_options: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateUserBlocked(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateUserBlocked");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  blocked: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateNotifySettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateNotifySettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  notify_settings: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateServiceNotification(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateServiceNotification::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateServiceNotification");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  popup: "); ++stages.back(); if (flag & MTPDupdateServiceNotification::Flag::f_popup) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  inbox_date: "); ++stages.back(); if (flag & MTPDupdateServiceNotification::Flag::f_inbox_date) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  media: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  entities: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updatePrivacy(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updatePrivacy");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  key: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  rules: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateUserPhone(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateUserPhone");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateReadHistoryInbox(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateReadHistoryInbox");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateReadHistoryOutbox(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateReadHistoryOutbox");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateWebPage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateWebPage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  webpage: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateReadMessagesContents(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateReadMessagesContents");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  messages: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChannelTooLong(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateChannelTooLong::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChannelTooLong");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts: "); ++stages.back(); if (flag & MTPDupdateChannelTooLong::Flag::f_pts) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateNewChannelMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateNewChannelMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateReadChannelInbox(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateReadChannelInbox");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateDeleteChannelMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateDeleteChannelMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  messages: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChannelMessageViews(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChannelMessageViews");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  views: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChatAdmins(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChatAdmins");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  enabled: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChatParticipantAdmin(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChatParticipantAdmin");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  is_admin: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateNewStickerSet(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateNewStickerSet");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  stickerset: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateStickerSetsOrder(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateStickerSetsOrder::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateStickerSetsOrder");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  masks: "); ++stages.back(); if (flag & MTPDupdateStickerSetsOrder::Flag::f_masks) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  order: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateStickerSets(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ updateStickerSets }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updateSavedGifs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ updateSavedGifs }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updateBotInlineQuery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateBotInlineQuery::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateBotInlineQuery");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  query: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  geo: "); ++stages.back(); if (flag & MTPDupdateBotInlineQuery::Flag::f_geo) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 5: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateBotInlineSend(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateBotInlineSend::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateBotInlineSend");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  query: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  geo: "); ++stages.back(); if (flag & MTPDupdateBotInlineSend::Flag::f_geo) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  msg_id: "); ++stages.back(); if (flag & MTPDupdateBotInlineSend::Flag::f_msg_id) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateEditChannelMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateEditChannelMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateChannelPinnedMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChannelPinnedMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateBotCallbackQuery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateBotCallbackQuery::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateBotCallbackQuery");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  chat_instance: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  data: "); ++stages.back(); if (flag & MTPDupdateBotCallbackQuery::Flag::f_data) { types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 7: to.add("  game_short_name: "); ++stages.back(); if (flag & MTPDupdateBotCallbackQuery::Flag::f_game_short_name) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateEditMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateEditMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateInlineBotCallbackQuery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateInlineBotCallbackQuery::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateInlineBotCallbackQuery");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  msg_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  chat_instance: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  data: "); ++stages.back(); if (flag & MTPDupdateInlineBotCallbackQuery::Flag::f_data) { types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 6: to.add("  game_short_name: "); ++stages.back(); if (flag & MTPDupdateInlineBotCallbackQuery::Flag::f_game_short_name) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateReadChannelOutbox(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateReadChannelOutbox");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateDraftMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateDraftMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  draft: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateReadFeaturedStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ updateReadFeaturedStickers }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updateRecentStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ updateRecentStickers }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updateConfig(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ updateConfig }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updatePtsChanged(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ updatePtsChanged }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updateChannelWebPage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateChannelWebPage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  webpage: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateDialogPinned(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateDialogPinned::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateDialogPinned");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pinned: "); ++stages.back(); if (flag & MTPDupdateDialogPinned::Flag::f_pinned) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updatePinnedDialogs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdatePinnedDialogs::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updatePinnedDialogs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  order: "); ++stages.back(); if (flag & MTPDupdatePinnedDialogs::Flag::f_order) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateBotWebhookJSON(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateBotWebhookJSON");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  data: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateBotWebhookJSONQuery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateBotWebhookJSONQuery");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  data: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  timeout: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateBotShippingQuery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateBotShippingQuery");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  payload: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  shipping_address: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateBotPrecheckoutQuery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateBotPrecheckoutQuery::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateBotPrecheckoutQuery");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  payload: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  info: "); ++stages.back(); if (flag & MTPDupdateBotPrecheckoutQuery::Flag::f_info) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 5: to.add("  shipping_option_id: "); ++stages.back(); if (flag & MTPDupdateBotPrecheckoutQuery::Flag::f_shipping_option_id) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 6: to.add("  currency: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  total_amount: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updatePhoneCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updatePhoneCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_call: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_state(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_state");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  qts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  seq: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  unread_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_differenceEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_differenceEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  seq: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_difference(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_difference");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  new_messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  new_encrypted_messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  other_updates: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  state: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_differenceSlice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_differenceSlice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  new_messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  new_encrypted_messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  other_updates: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  intermediate_state: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_differenceTooLong(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_differenceTooLong");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updatesTooLong(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ updatesTooLong }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updateShortMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateShortMessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateShortMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  out: "); ++stages.back(); if (flag & MTPDupdateShortMessage::Flag::f_out) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  mentioned: "); ++stages.back(); if (flag & MTPDupdateShortMessage::Flag::f_mentioned) { to.add("YES [ BY BIT 4 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 3: to.add("  media_unread: "); ++stages.back(); if (flag & MTPDupdateShortMessage::Flag::f_media_unread) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 4: to.add("  silent: "); ++stages.back(); if (flag & MTPDupdateShortMessage::Flag::f_silent) { to.add("YES [ BY BIT 13 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 13 IN FIELD flags ]"); } break;
	case 5: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 11: to.add("  fwd_from: "); ++stages.back(); if (flag & MTPDupdateShortMessage::Flag::f_fwd_from) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 12: to.add("  via_bot_id: "); ++stages.back(); if (flag & MTPDupdateShortMessage::Flag::f_via_bot_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 11 IN FIELD flags ]"); } break;
	case 13: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPDupdateShortMessage::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 14: to.add("  entities: "); ++stages.back(); if (flag & MTPDupdateShortMessage::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateShortChatMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateShortChatMessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateShortChatMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  out: "); ++stages.back(); if (flag & MTPDupdateShortChatMessage::Flag::f_out) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  mentioned: "); ++stages.back(); if (flag & MTPDupdateShortChatMessage::Flag::f_mentioned) { to.add("YES [ BY BIT 4 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 3: to.add("  media_unread: "); ++stages.back(); if (flag & MTPDupdateShortChatMessage::Flag::f_media_unread) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 4: to.add("  silent: "); ++stages.back(); if (flag & MTPDupdateShortChatMessage::Flag::f_silent) { to.add("YES [ BY BIT 13 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 13 IN FIELD flags ]"); } break;
	case 5: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  from_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 11: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 12: to.add("  fwd_from: "); ++stages.back(); if (flag & MTPDupdateShortChatMessage::Flag::f_fwd_from) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 13: to.add("  via_bot_id: "); ++stages.back(); if (flag & MTPDupdateShortChatMessage::Flag::f_via_bot_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 11 IN FIELD flags ]"); } break;
	case 14: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPDupdateShortChatMessage::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 15: to.add("  entities: "); ++stages.back(); if (flag & MTPDupdateShortChatMessage::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateShort(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateShort");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  update: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updatesCombined(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updatesCombined");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  updates: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  seq_start: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  seq: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  updates: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  seq: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updateShortSentMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdateShortSentMessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updateShortSentMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  out: "); ++stages.back(); if (flag & MTPDupdateShortSentMessage::Flag::f_out) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  media: "); ++stages.back(); if (flag & MTPDupdateShortSentMessage::Flag::f_media) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 9 IN FIELD flags ]"); } break;
	case 7: to.add("  entities: "); ++stages.back(); if (flag & MTPDupdateShortSentMessage::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photos_photos(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photos_photos");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  photos: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photos_photosSlice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photos_photosSlice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  photos: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photos_photo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photos_photo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_file(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_file");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  type: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  mtime: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_fileCdnRedirect(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_fileCdnRedirect");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  dc_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  file_token: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  encryption_key: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  encryption_iv: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_dcOption(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDdcOption::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ dcOption");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  ipv6: "); ++stages.back(); if (flag & MTPDdcOption::Flag::f_ipv6) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  media_only: "); ++stages.back(); if (flag & MTPDdcOption::Flag::f_media_only) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  tcpo_only: "); ++stages.back(); if (flag & MTPDdcOption::Flag::f_tcpo_only) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  cdn: "); ++stages.back(); if (flag & MTPDdcOption::Flag::f_cdn) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 5: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  ip_address: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  port: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_config(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDconfig::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ config");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phonecalls_enabled: "); ++stages.back(); if (flag & MTPDconfig::Flag::f_phonecalls_enabled) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  expires: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  test_mode: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  this_dc: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  dc_options: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  chat_size_max: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  megagroup_size_max: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  forwarded_count_max: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  online_update_period_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 11: to.add("  offline_blur_timeout_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 12: to.add("  offline_idle_timeout_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 13: to.add("  online_cloud_timeout_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 14: to.add("  notify_cloud_delay_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 15: to.add("  notify_default_delay_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 16: to.add("  chat_big_size: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 17: to.add("  push_chat_period_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 18: to.add("  push_chat_limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 19: to.add("  saved_gifs_limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 20: to.add("  edit_time_limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 21: to.add("  rating_e_decay: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 22: to.add("  stickers_recent_limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 23: to.add("  tmp_sessions: "); ++stages.back(); if (flag & MTPDconfig::Flag::f_tmp_sessions) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 24: to.add("  pinned_dialogs_count_max: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 25: to.add("  call_receive_timeout_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 26: to.add("  call_ring_timeout_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 27: to.add("  call_connect_timeout_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 28: to.add("  call_packet_timeout_ms: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 29: to.add("  me_url_prefix: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 30: to.add("  disabled_features: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_nearestDc(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ nearestDc");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  country: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  this_dc: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  nearest_dc: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_help_appUpdate(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ help_appUpdate");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  critical: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_help_noAppUpdate(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ help_noAppUpdate }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_help_inviteText(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ help_inviteText");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_encryptedChatEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ encryptedChatEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_encryptedChatWaiting(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ encryptedChatWaiting");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  admin_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  participant_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_encryptedChatRequested(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ encryptedChatRequested");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  admin_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  participant_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  g_a: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_encryptedChat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ encryptedChat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  admin_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  participant_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  g_a_or_b: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  key_fingerprint: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_encryptedChatDiscarded(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ encryptedChatDiscarded");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputEncryptedChat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputEncryptedChat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_encryptedFileEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ encryptedFileEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_encryptedFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ encryptedFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  size: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  dc_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  key_fingerprint: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputEncryptedFileEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputEncryptedFileEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputEncryptedFileUploaded(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputEncryptedFileUploaded");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  parts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  md5_checksum: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  key_fingerprint: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputEncryptedFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputEncryptedFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputEncryptedFileBigUploaded(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputEncryptedFileBigUploaded");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  parts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  key_fingerprint: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_encryptedMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ encryptedMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  file: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_encryptedMessageService(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ encryptedMessageService");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_dhConfigNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_dhConfigNotModified");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  random: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_dhConfig(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_dhConfig");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  g: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  p: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  random: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_sentEncryptedMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_sentEncryptedMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_sentEncryptedFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_sentEncryptedFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  file: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputDocumentEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputDocumentEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_documentEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ documentEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_document(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ document");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  mime_type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  size: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  thumb: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  dc_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  attributes: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_help_support(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ help_support");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_notifyPeer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ notifyPeer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_notifyUsers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ notifyUsers }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_notifyChats(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ notifyChats }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_notifyAll(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ notifyAll }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageTypingAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ sendMessageTypingAction }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageCancelAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ sendMessageCancelAction }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageRecordVideoAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ sendMessageRecordVideoAction }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageUploadVideoAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ sendMessageUploadVideoAction");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  progress: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_sendMessageRecordAudioAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ sendMessageRecordAudioAction }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageUploadAudioAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ sendMessageUploadAudioAction");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  progress: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_sendMessageUploadPhotoAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ sendMessageUploadPhotoAction");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  progress: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_sendMessageUploadDocumentAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ sendMessageUploadDocumentAction");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  progress: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_sendMessageGeoLocationAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ sendMessageGeoLocationAction }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageChooseContactAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ sendMessageChooseContactAction }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageGamePlayAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ sendMessageGamePlayAction }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageRecordRoundAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ sendMessageRecordRoundAction }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_sendMessageUploadRoundAction(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ sendMessageUploadRoundAction");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  progress: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_found(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_found");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  results: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPrivacyKeyStatusTimestamp(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPrivacyKeyStatusTimestamp }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPrivacyKeyChatInvite(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPrivacyKeyChatInvite }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPrivacyKeyPhoneCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPrivacyKeyPhoneCall }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_privacyKeyStatusTimestamp(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ privacyKeyStatusTimestamp }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_privacyKeyChatInvite(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ privacyKeyChatInvite }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_privacyKeyPhoneCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ privacyKeyPhoneCall }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPrivacyValueAllowContacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPrivacyValueAllowContacts }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPrivacyValueAllowAll(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPrivacyValueAllowAll }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPrivacyValueAllowUsers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPrivacyValueAllowUsers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPrivacyValueDisallowContacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPrivacyValueDisallowContacts }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPrivacyValueDisallowAll(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputPrivacyValueDisallowAll }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputPrivacyValueDisallowUsers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPrivacyValueDisallowUsers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_privacyValueAllowContacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ privacyValueAllowContacts }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_privacyValueAllowAll(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ privacyValueAllowAll }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_privacyValueAllowUsers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ privacyValueAllowUsers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  users: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_privacyValueDisallowContacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ privacyValueDisallowContacts }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_privacyValueDisallowAll(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ privacyValueDisallowAll }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_privacyValueDisallowUsers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ privacyValueDisallowUsers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  users: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_privacyRules(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_privacyRules");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  rules: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_accountDaysTTL(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ accountDaysTTL");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  days: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_documentAttributeImageSize(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ documentAttributeImageSize");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  w: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  h: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_documentAttributeAnimated(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ documentAttributeAnimated }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_documentAttributeSticker(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDdocumentAttributeSticker::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ documentAttributeSticker");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  mask: "); ++stages.back(); if (flag & MTPDdocumentAttributeSticker::Flag::f_mask) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  alt: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  stickerset: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  mask_coords: "); ++stages.back(); if (flag & MTPDdocumentAttributeSticker::Flag::f_mask_coords) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_documentAttributeVideo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDdocumentAttributeVideo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ documentAttributeVideo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  round_message: "); ++stages.back(); if (flag & MTPDdocumentAttributeVideo::Flag::f_round_message) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  duration: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  w: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  h: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_documentAttributeAudio(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDdocumentAttributeAudio::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ documentAttributeAudio");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  voice: "); ++stages.back(); if (flag & MTPDdocumentAttributeAudio::Flag::f_voice) { to.add("YES [ BY BIT 10 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 10 IN FIELD flags ]"); } break;
	case 2: to.add("  duration: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  title: "); ++stages.back(); if (flag & MTPDdocumentAttributeAudio::Flag::f_title) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  performer: "); ++stages.back(); if (flag & MTPDdocumentAttributeAudio::Flag::f_performer) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 5: to.add("  waveform: "); ++stages.back(); if (flag & MTPDdocumentAttributeAudio::Flag::f_waveform) { types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_documentAttributeFilename(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ documentAttributeFilename");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  file_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_documentAttributeHasStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ documentAttributeHasStickers }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_stickersNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messages_stickersNotModified }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_stickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_stickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  stickers: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_stickerPack(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ stickerPack");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  emoticon: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  documents: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_allStickersNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messages_allStickersNotModified }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_allStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_allStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  sets: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_disabledFeature(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ disabledFeature");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  feature: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  description: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_affectedMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_affectedMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contactLinkUnknown(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ contactLinkUnknown }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_contactLinkNone(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ contactLinkNone }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_contactLinkHasPhone(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ contactLinkHasPhone }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_contactLinkContact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ contactLinkContact }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_webPageEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ webPageEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_webPagePending(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ webPagePending");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_webPage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDwebPage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ webPage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  display_url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  type: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_type) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 6: to.add("  site_name: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_site_name) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 7: to.add("  title: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_title) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 8: to.add("  description: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_description) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 9: to.add("  photo: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_photo) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 10: to.add("  embed_url: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_embed_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 11: to.add("  embed_type: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_embed_type) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 12: to.add("  embed_width: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_embed_width) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 13: to.add("  embed_height: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_embed_height) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 14: to.add("  duration: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_duration) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	case 15: to.add("  author: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_author) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 8 IN FIELD flags ]"); } break;
	case 16: to.add("  document: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_document) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 9 IN FIELD flags ]"); } break;
	case 17: to.add("  cached_page: "); ++stages.back(); if (flag & MTPDwebPage::Flag::f_cached_page) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 10 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_webPageNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ webPageNotModified }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_authorization(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ authorization");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  flags: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  device_model: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  platform: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  system_version: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  api_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  app_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  app_version: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  date_created: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  date_active: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  ip: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 11: to.add("  country: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 12: to.add("  region: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_authorizations(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_authorizations");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  authorizations: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_noPassword(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_noPassword");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  new_salt: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  email_unconfirmed_pattern: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_password(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_password");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  current_salt: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  new_salt: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  hint: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  has_recovery: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  email_unconfirmed_pattern: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_passwordSettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_passwordSettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  email: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_passwordInputSettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDaccount_passwordInputSettings::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_passwordInputSettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  new_salt: "); ++stages.back(); if (flag & MTPDaccount_passwordInputSettings::Flag::f_new_salt) { types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  new_password_hash: "); ++stages.back(); if (flag & MTPDaccount_passwordInputSettings::Flag::f_new_password_hash) { types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 3: to.add("  hint: "); ++stages.back(); if (flag & MTPDaccount_passwordInputSettings::Flag::f_hint) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  email: "); ++stages.back(); if (flag & MTPDaccount_passwordInputSettings::Flag::f_email) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_passwordRecovery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_passwordRecovery");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  email_pattern: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_receivedNotifyMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ receivedNotifyMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  flags: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatInviteEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ chatInviteEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_chatInviteExported(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatInviteExported");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  link: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatInviteAlready(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatInviteAlready");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_chatInvite(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDchatInvite::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ chatInvite");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  channel: "); ++stages.back(); if (flag & MTPDchatInvite::Flag::f_channel) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  broadcast: "); ++stages.back(); if (flag & MTPDchatInvite::Flag::f_broadcast) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  public: "); ++stages.back(); if (flag & MTPDchatInvite::Flag::f_public) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  megagroup: "); ++stages.back(); if (flag & MTPDchatInvite::Flag::f_megagroup) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 5: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  participants_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  participants: "); ++stages.back(); if (flag & MTPDchatInvite::Flag::f_participants) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputStickerSetEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputStickerSetEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputStickerSetID(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputStickerSetID");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputStickerSetShortName(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputStickerSetShortName");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  short_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_stickerSet(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDstickerSet::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ stickerSet");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  installed: "); ++stages.back(); if (flag & MTPDstickerSet::Flag::f_installed) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  archived: "); ++stages.back(); if (flag & MTPDstickerSet::Flag::f_archived) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  official: "); ++stages.back(); if (flag & MTPDstickerSet::Flag::f_official) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  masks: "); ++stages.back(); if (flag & MTPDstickerSet::Flag::f_masks) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 5: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  short_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_stickerSet(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_stickerSet");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  set: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  packs: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  documents: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botCommand(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botCommand");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  command: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  description: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botInfo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botInfo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  description: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  commands: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButton(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButton");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButtonUrl(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButtonUrl");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButtonCallback(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButtonCallback");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  data: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButtonRequestPhone(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButtonRequestPhone");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButtonRequestGeoLocation(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButtonRequestGeoLocation");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButtonSwitchInline(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDkeyboardButtonSwitchInline::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButtonSwitchInline");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  same_peer: "); ++stages.back(); if (flag & MTPDkeyboardButtonSwitchInline::Flag::f_same_peer) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  query: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButtonGame(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButtonGame");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButtonBuy(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButtonBuy");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_keyboardButtonRow(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ keyboardButtonRow");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  buttons: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_replyKeyboardHide(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDreplyKeyboardHide::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ replyKeyboardHide");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  selective: "); ++stages.back(); if (flag & MTPDreplyKeyboardHide::Flag::f_selective) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_replyKeyboardForceReply(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDreplyKeyboardForceReply::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ replyKeyboardForceReply");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  single_use: "); ++stages.back(); if (flag & MTPDreplyKeyboardForceReply::Flag::f_single_use) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  selective: "); ++stages.back(); if (flag & MTPDreplyKeyboardForceReply::Flag::f_selective) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_replyKeyboardMarkup(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDreplyKeyboardMarkup::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ replyKeyboardMarkup");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  resize: "); ++stages.back(); if (flag & MTPDreplyKeyboardMarkup::Flag::f_resize) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  single_use: "); ++stages.back(); if (flag & MTPDreplyKeyboardMarkup::Flag::f_single_use) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  selective: "); ++stages.back(); if (flag & MTPDreplyKeyboardMarkup::Flag::f_selective) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  rows: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_replyInlineMarkup(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ replyInlineMarkup");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  rows: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityUnknown(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityUnknown");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityMention(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityMention");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityHashtag(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityHashtag");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityBotCommand(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityBotCommand");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityUrl(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityUrl");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityEmail(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityEmail");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityBold(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityBold");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityItalic(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityItalic");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityCode(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityCode");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityPre(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityPre");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  language: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityTextUrl(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityTextUrl");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageEntityMentionName(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageEntityMentionName");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputMessageEntityMentionName(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputMessageEntityMentionName");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputChannelEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ inputChannelEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_inputChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_resolvedPeer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_resolvedPeer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageRange(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageRange");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  min_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_channelDifferenceEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdates_channelDifferenceEmpty::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_channelDifferenceEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  final: "); ++stages.back(); if (flag & MTPDupdates_channelDifferenceEmpty::Flag::f_final) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  timeout: "); ++stages.back(); if (flag & MTPDupdates_channelDifferenceEmpty::Flag::f_timeout) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_channelDifferenceTooLong(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdates_channelDifferenceTooLong::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_channelDifferenceTooLong");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  final: "); ++stages.back(); if (flag & MTPDupdates_channelDifferenceTooLong::Flag::f_final) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  timeout: "); ++stages.back(); if (flag & MTPDupdates_channelDifferenceTooLong::Flag::f_timeout) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  top_message: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  read_inbox_max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  read_outbox_max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  unread_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_channelDifference(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDupdates_channelDifference::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_channelDifference");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  final: "); ++stages.back(); if (flag & MTPDupdates_channelDifference::Flag::f_final) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  timeout: "); ++stages.back(); if (flag & MTPDupdates_channelDifference::Flag::f_timeout) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  new_messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  other_updates: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelMessagesFilterEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channelMessagesFilterEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channelMessagesFilter(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDchannelMessagesFilter::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelMessagesFilter");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  exclude_new_messages: "); ++stages.back(); if (flag & MTPDchannelMessagesFilter::Flag::f_exclude_new_messages) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  ranges: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelParticipant(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelParticipant");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelParticipantSelf(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelParticipantSelf");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  inviter_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelParticipantModerator(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelParticipantModerator");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  inviter_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelParticipantEditor(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelParticipantEditor");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  inviter_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelParticipantKicked(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelParticipantKicked");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  kicked_by: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelParticipantCreator(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channelParticipantCreator");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channelParticipantsRecent(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channelParticipantsRecent }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channelParticipantsAdmins(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channelParticipantsAdmins }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channelParticipantsKicked(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channelParticipantsKicked }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channelParticipantsBots(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channelParticipantsBots }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channelRoleEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channelRoleEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channelRoleModerator(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channelRoleModerator }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channelRoleEditor(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channelRoleEditor }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channels_channelParticipants(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_channelParticipants");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  participants: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_channelParticipant(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_channelParticipant");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  participant: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_help_termsOfService(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ help_termsOfService");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_foundGif(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ foundGif");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  thumb_url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  content_url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  content_type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  w: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  h: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_foundGifCached(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ foundGifCached");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  document: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_foundGifs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_foundGifs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  next_offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  results: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_savedGifsNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messages_savedGifsNotModified }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_savedGifs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_savedGifs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  gifs: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineMessageMediaAuto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputBotInlineMessageMediaAuto::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineMessageMediaAuto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDinputBotInlineMessageMediaAuto::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineMessageText(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputBotInlineMessageText::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineMessageText");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  no_webpage: "); ++stages.back(); if (flag & MTPDinputBotInlineMessageText::Flag::f_no_webpage) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  entities: "); ++stages.back(); if (flag & MTPDinputBotInlineMessageText::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDinputBotInlineMessageText::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineMessageMediaGeo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputBotInlineMessageMediaGeo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineMessageMediaGeo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  geo_point: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDinputBotInlineMessageMediaGeo::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineMessageMediaVenue(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputBotInlineMessageMediaVenue::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineMessageMediaVenue");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  geo_point: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  address: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  provider: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  venue_id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDinputBotInlineMessageMediaVenue::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineMessageMediaContact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputBotInlineMessageMediaContact::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineMessageMediaContact");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  first_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  last_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDinputBotInlineMessageMediaContact::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineMessageGame(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputBotInlineMessageGame::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineMessageGame");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDinputBotInlineMessageGame::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineResult(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputBotInlineResult::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineResult");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  title: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_title) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  description: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_description) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 5: to.add("  url: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 6: to.add("  thumb_url: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_thumb_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 7: to.add("  content_url: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_content_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 8: to.add("  content_type: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_content_type) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 9: to.add("  w: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_w) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 10: to.add("  h: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_h) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 11: to.add("  duration: "); ++stages.back(); if (flag & MTPDinputBotInlineResult::Flag::f_duration) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	case 12: to.add("  send_message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineResultPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineResultPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  send_message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineResultDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputBotInlineResultDocument::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineResultDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  title: "); ++stages.back(); if (flag & MTPDinputBotInlineResultDocument::Flag::f_title) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  description: "); ++stages.back(); if (flag & MTPDinputBotInlineResultDocument::Flag::f_description) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 5: to.add("  document: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  send_message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineResultGame(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineResultGame");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  short_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  send_message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botInlineMessageMediaAuto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDbotInlineMessageMediaAuto::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botInlineMessageMediaAuto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDbotInlineMessageMediaAuto::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botInlineMessageText(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDbotInlineMessageText::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botInlineMessageText");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  no_webpage: "); ++stages.back(); if (flag & MTPDbotInlineMessageText::Flag::f_no_webpage) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  entities: "); ++stages.back(); if (flag & MTPDbotInlineMessageText::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDbotInlineMessageText::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botInlineMessageMediaGeo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDbotInlineMessageMediaGeo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botInlineMessageMediaGeo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  geo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDbotInlineMessageMediaGeo::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botInlineMessageMediaVenue(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDbotInlineMessageMediaVenue::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botInlineMessageMediaVenue");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  geo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  address: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  provider: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  venue_id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDbotInlineMessageMediaVenue::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botInlineMessageMediaContact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDbotInlineMessageMediaContact::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botInlineMessageMediaContact");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  first_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  last_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPDbotInlineMessageMediaContact::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botInlineResult(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDbotInlineResult::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botInlineResult");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  title: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_title) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  description: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_description) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 5: to.add("  url: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 6: to.add("  thumb_url: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_thumb_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 7: to.add("  content_url: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_content_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 8: to.add("  content_type: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_content_type) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 9: to.add("  w: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_w) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 10: to.add("  h: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_h) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 11: to.add("  duration: "); ++stages.back(); if (flag & MTPDbotInlineResult::Flag::f_duration) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	case 12: to.add("  send_message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_botInlineMediaResult(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDbotInlineMediaResult::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ botInlineMediaResult");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  photo: "); ++stages.back(); if (flag & MTPDbotInlineMediaResult::Flag::f_photo) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  document: "); ++stages.back(); if (flag & MTPDbotInlineMediaResult::Flag::f_document) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 5: to.add("  title: "); ++stages.back(); if (flag & MTPDbotInlineMediaResult::Flag::f_title) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 6: to.add("  description: "); ++stages.back(); if (flag & MTPDbotInlineMediaResult::Flag::f_description) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 7: to.add("  send_message: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_botResults(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessages_botResults::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_botResults");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  gallery: "); ++stages.back(); if (flag & MTPDmessages_botResults::Flag::f_gallery) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  next_offset: "); ++stages.back(); if (flag & MTPDmessages_botResults::Flag::f_next_offset) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  switch_pm: "); ++stages.back(); if (flag & MTPDmessages_botResults::Flag::f_switch_pm) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 5: to.add("  results: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  cache_time: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_exportedMessageLink(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ exportedMessageLink");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  link: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messageFwdHeader(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessageFwdHeader::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messageFwdHeader");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  from_id: "); ++stages.back(); if (flag & MTPDmessageFwdHeader::Flag::f_from_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  channel_id: "); ++stages.back(); if (flag & MTPDmessageFwdHeader::Flag::f_channel_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  channel_post: "); ++stages.back(); if (flag & MTPDmessageFwdHeader::Flag::f_channel_post) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_codeTypeSms(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ auth_codeTypeSms }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_auth_codeTypeCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ auth_codeTypeCall }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_auth_codeTypeFlashCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ auth_codeTypeFlashCall }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_auth_sentCodeTypeApp(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_sentCodeTypeApp");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_sentCodeTypeSms(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_sentCodeTypeSms");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_sentCodeTypeCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_sentCodeTypeCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_sentCodeTypeFlashCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_sentCodeTypeFlashCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  pattern: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_botCallbackAnswer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessages_botCallbackAnswer::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_botCallbackAnswer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  alert: "); ++stages.back(); if (flag & MTPDmessages_botCallbackAnswer::Flag::f_alert) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  has_url: "); ++stages.back(); if (flag & MTPDmessages_botCallbackAnswer::Flag::f_has_url) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 3: to.add("  message: "); ++stages.back(); if (flag & MTPDmessages_botCallbackAnswer::Flag::f_message) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  url: "); ++stages.back(); if (flag & MTPDmessages_botCallbackAnswer::Flag::f_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 5: to.add("  cache_time: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_messageEditData(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDmessages_messageEditData::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_messageEditData");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); if (flag & MTPDmessages_messageEditData::Flag::f_caption) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputBotInlineMessageID(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputBotInlineMessageID");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  dc_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inlineBotSwitchPM(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inlineBotSwitchPM");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  start_param: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_peerDialogs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_peerDialogs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  dialogs: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  messages: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  state: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_topPeer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ topPeer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  rating: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_topPeerCategoryBotsPM(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ topPeerCategoryBotsPM }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_topPeerCategoryBotsInline(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ topPeerCategoryBotsInline }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_topPeerCategoryCorrespondents(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ topPeerCategoryCorrespondents }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_topPeerCategoryGroups(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ topPeerCategoryGroups }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_topPeerCategoryChannels(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ topPeerCategoryChannels }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_topPeerCategoryPeers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ topPeerCategoryPeers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  category: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  peers: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_topPeersNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ contacts_topPeersNotModified }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_contacts_topPeers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_topPeers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  categories: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  chats: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_draftMessageEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ draftMessageEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_draftMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDdraftMessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ draftMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  no_webpage: "); ++stages.back(); if (flag & MTPDdraftMessage::Flag::f_no_webpage) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPDdraftMessage::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 3: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  entities: "); ++stages.back(); if (flag & MTPDdraftMessage::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 5: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_featuredStickersNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messages_featuredStickersNotModified }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_featuredStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_featuredStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  sets: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  unread: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_recentStickersNotModified(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messages_recentStickersNotModified }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_recentStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_recentStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  stickers: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_archivedStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_archivedStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  sets: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_stickerSetInstallResultSuccess(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messages_stickerSetInstallResultSuccess }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_stickerSetInstallResultArchive(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_stickerSetInstallResultArchive");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  sets: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_stickerSetCovered(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ stickerSetCovered");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  set: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  cover: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_stickerSetMultiCovered(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ stickerSetMultiCovered");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  set: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  covers: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_maskCoords(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ maskCoords");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  n: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  x: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  y: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  zoom: "); ++stages.back(); types.push_back(mtpc_double+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputStickeredMediaPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputStickeredMediaPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputStickeredMediaDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputStickeredMediaDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_game(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDgame::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ game");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  short_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  description: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  document: "); ++stages.back(); if (flag & MTPDgame::Flag::f_document) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputGameID(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputGameID");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputGameShortName(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputGameShortName");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  bot_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  short_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_highScore(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ highScore");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  pos: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  score: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_highScores(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_highScores");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  scores: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ textEmpty }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_textPlain(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textPlain");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textBold(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textBold");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textItalic(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textItalic");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textUnderline(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textUnderline");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textStrike(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textStrike");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textFixed(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textFixed");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textUrl(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textUrl");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  webpage_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textEmail(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textEmail");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  email: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_textConcat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ textConcat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  texts: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockUnsupported(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ pageBlockUnsupported }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_pageBlockTitle(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockTitle");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockSubtitle(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockSubtitle");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockAuthorDate(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockAuthorDate");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  author: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  published_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockHeader(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockHeader");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockSubheader(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockSubheader");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockParagraph(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockParagraph");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockPreformatted(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockPreformatted");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  language: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockFooter(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockFooter");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockDivider(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ pageBlockDivider }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_pageBlockAnchor(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockAnchor");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockList(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockList");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  ordered: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  items: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockBlockquote(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockBlockquote");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockPullquote(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockPullquote");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  text: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  photo_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockVideo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpageBlockVideo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockVideo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  autoplay: "); ++stages.back(); if (flag & MTPDpageBlockVideo::Flag::f_autoplay) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  loop: "); ++stages.back(); if (flag & MTPDpageBlockVideo::Flag::f_loop) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  video_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  caption: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockCover(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockCover");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  cover: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockEmbed(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpageBlockEmbed::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockEmbed");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  full_width: "); ++stages.back(); if (flag & MTPDpageBlockEmbed::Flag::f_full_width) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  allow_scrolling: "); ++stages.back(); if (flag & MTPDpageBlockEmbed::Flag::f_allow_scrolling) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 3: to.add("  url: "); ++stages.back(); if (flag & MTPDpageBlockEmbed::Flag::f_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  html: "); ++stages.back(); if (flag & MTPDpageBlockEmbed::Flag::f_html) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 5: to.add("  poster_photo_id: "); ++stages.back(); if (flag & MTPDpageBlockEmbed::Flag::f_poster_photo_id) { types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 6: to.add("  w: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  h: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  caption: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockEmbedPost(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockEmbedPost");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  webpage_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  author_photo_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  author: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  blocks: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  caption: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockCollage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockCollage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  items: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockSlideshow(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockSlideshow");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  items: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  caption: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageBlockChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageBlockChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pagePart(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pagePart");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  blocks: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  photos: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  videos: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_pageFull(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ pageFull");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  blocks: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  photos: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  videos: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneCallDiscardReasonMissed(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ phoneCallDiscardReasonMissed }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_phoneCallDiscardReasonDisconnect(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ phoneCallDiscardReasonDisconnect }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_phoneCallDiscardReasonHangup(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ phoneCallDiscardReasonHangup }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_phoneCallDiscardReasonBusy(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ phoneCallDiscardReasonBusy }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_dataJSON(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ dataJSON");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  data: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_labeledPrice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ labeledPrice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  label: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  amount: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_invoice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinvoice::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ invoice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  test: "); ++stages.back(); if (flag & MTPDinvoice::Flag::f_test) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  name_requested: "); ++stages.back(); if (flag & MTPDinvoice::Flag::f_name_requested) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  phone_requested: "); ++stages.back(); if (flag & MTPDinvoice::Flag::f_phone_requested) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  email_requested: "); ++stages.back(); if (flag & MTPDinvoice::Flag::f_email_requested) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 5: to.add("  shipping_address_requested: "); ++stages.back(); if (flag & MTPDinvoice::Flag::f_shipping_address_requested) { to.add("YES [ BY BIT 4 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 6: to.add("  flexible: "); ++stages.back(); if (flag & MTPDinvoice::Flag::f_flexible) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 7: to.add("  currency: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  prices: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_paymentCharge(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ paymentCharge");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  provider_charge_id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_postAddress(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ postAddress");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  street_line1: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  street_line2: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  city: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  state: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  country_iso2: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  post_code: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_paymentRequestedInfo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpaymentRequestedInfo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ paymentRequestedInfo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  name: "); ++stages.back(); if (flag & MTPDpaymentRequestedInfo::Flag::f_name) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  phone: "); ++stages.back(); if (flag & MTPDpaymentRequestedInfo::Flag::f_phone) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  email: "); ++stages.back(); if (flag & MTPDpaymentRequestedInfo::Flag::f_email) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  shipping_address: "); ++stages.back(); if (flag & MTPDpaymentRequestedInfo::Flag::f_shipping_address) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_paymentSavedCredentialsCard(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ paymentSavedCredentialsCard");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_webDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ webDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  size: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  mime_type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  attributes: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  dc_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputWebDocument(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputWebDocument");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  size: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  mime_type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  attributes: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputWebFileLocation(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputWebFileLocation");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_webFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_webFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  size: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  mime_type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  file_type: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  mtime: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_paymentForm(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpayments_paymentForm::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_paymentForm");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  can_save_credentials: "); ++stages.back(); if (flag & MTPDpayments_paymentForm::Flag::f_can_save_credentials) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 2: to.add("  password_missing: "); ++stages.back(); if (flag & MTPDpayments_paymentForm::Flag::f_password_missing) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 3: to.add("  bot_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  invoice: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  provider_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  native_provider: "); ++stages.back(); if (flag & MTPDpayments_paymentForm::Flag::f_native_provider) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 8: to.add("  native_params: "); ++stages.back(); if (flag & MTPDpayments_paymentForm::Flag::f_native_params) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 4 IN FIELD flags ]"); } break;
	case 9: to.add("  saved_info: "); ++stages.back(); if (flag & MTPDpayments_paymentForm::Flag::f_saved_info) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 10: to.add("  saved_credentials: "); ++stages.back(); if (flag & MTPDpayments_paymentForm::Flag::f_saved_credentials) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 11: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_validatedRequestedInfo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpayments_validatedRequestedInfo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_validatedRequestedInfo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); if (flag & MTPDpayments_validatedRequestedInfo::Flag::f_id) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  shipping_options: "); ++stages.back(); if (flag & MTPDpayments_validatedRequestedInfo::Flag::f_shipping_options) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_paymentResult(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_paymentResult");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  updates: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_paymentVerficationNeeded(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_paymentVerficationNeeded");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_paymentReceipt(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpayments_paymentReceipt::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_paymentReceipt");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  bot_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  invoice: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  provider_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  info: "); ++stages.back(); if (flag & MTPDpayments_paymentReceipt::Flag::f_info) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 6: to.add("  shipping: "); ++stages.back(); if (flag & MTPDpayments_paymentReceipt::Flag::f_shipping) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 7: to.add("  currency: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  total_amount: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  credentials_title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_savedInfo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDpayments_savedInfo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_savedInfo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  has_saved_credentials: "); ++stages.back(); if (flag & MTPDpayments_savedInfo::Flag::f_has_saved_credentials) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  saved_info: "); ++stages.back(); if (flag & MTPDpayments_savedInfo::Flag::f_saved_info) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPaymentCredentialsSaved(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPaymentCredentialsSaved");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  tmp_password: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPaymentCredentials(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDinputPaymentCredentials::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPaymentCredentials");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  save: "); ++stages.back(); if (flag & MTPDinputPaymentCredentials::Flag::f_save) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  data: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_tmpPassword(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_tmpPassword");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  tmp_password: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  valid_until: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_shippingOption(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ shippingOption");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  prices: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_inputPhoneCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ inputPhoneCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneCallEmpty(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phoneCallEmpty");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneCallWaiting(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDphoneCallWaiting::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phoneCallWaiting");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  admin_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  participant_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  protocol: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  receive_date: "); ++stages.back(); if (flag & MTPDphoneCallWaiting::Flag::f_receive_date) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneCallRequested(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phoneCallRequested");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  admin_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  participant_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  g_a_hash: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  protocol: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneCallAccepted(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phoneCallAccepted");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  admin_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  participant_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  g_b: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  protocol: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phoneCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  access_hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  admin_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  participant_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  g_a_or_b: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  key_fingerprint: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  protocol: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  connection: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  alternative_connections: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 10: to.add("  start_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneCallDiscarded(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDphoneCallDiscarded::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phoneCallDiscarded");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  need_rating: "); ++stages.back(); if (flag & MTPDphoneCallDiscarded::Flag::f_need_rating) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 2: to.add("  need_debug: "); ++stages.back(); if (flag & MTPDphoneCallDiscarded::Flag::f_need_debug) { to.add("YES [ BY BIT 3 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	case 3: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  reason: "); ++stages.back(); if (flag & MTPDphoneCallDiscarded::Flag::f_reason) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 5: to.add("  duration: "); ++stages.back(); if (flag & MTPDphoneCallDiscarded::Flag::f_duration) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneConnection(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phoneConnection");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  ip: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  ipv6: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  port: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  peer_tag: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phoneCallProtocol(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPDphoneCallProtocol::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phoneCallProtocol");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  udp_p2p: "); ++stages.back(); if (flag & MTPDphoneCallProtocol::Flag::f_udp_p2p) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  udp_reflector: "); ++stages.back(); if (flag & MTPDphoneCallProtocol::Flag::f_udp_reflector) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  min_layer: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  max_layer: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phone_phoneCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phone_phoneCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_call: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_cdnFileReuploadNeeded(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_cdnFileReuploadNeeded");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  request_token: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_cdnFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_cdnFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_cdnPublicKey(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ cdnPublicKey");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  dc_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  public_key: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_cdnConfig(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ cdnConfig");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  public_keys: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_req_pq(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ req_pq");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_req_DH_params(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ req_DH_params");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  p: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  q: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  public_key_fingerprint: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  encrypted_data: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_set_client_DH_params(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ set_client_DH_params");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  server_nonce: "); ++stages.back(); types.push_back(mtpc_int128+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  encrypted_data: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_destroy_auth_key(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ destroy_auth_key }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_rpc_drop_answer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ rpc_drop_answer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  req_msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_get_future_salts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ get_future_salts");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  num: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_ping(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ ping");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  ping_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_ping_delay_disconnect(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ ping_delay_disconnect");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  ping_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  disconnect_delay: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_destroy_session(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ destroy_session");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  session_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contest_saveDeveloperInfo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contest_saveDeveloperInfo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  vk_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  age: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  city: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_logOut(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ auth_logOut }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_auth_resetAuthorizations(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ auth_resetAuthorizations }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_auth_sendInvites(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_sendInvites");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_numbers: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_string+0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_bindTempAuthKey(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_bindTempAuthKey");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  perm_auth_key_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  nonce: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  expires_at: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  encrypted_message: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_cancelCode(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_cancelCode");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_code_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_dropTempAuthKeys(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_dropTempAuthKeys");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  except_auth_keys: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_registerDevice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_registerDevice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  token_type: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  token: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_unregisterDevice(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_unregisterDevice");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  token_type: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  token: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_updateNotifySettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_updateNotifySettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  settings: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_resetNotifySettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ account_resetNotifySettings }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_account_updateStatus(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_updateStatus");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offline: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_reportPeer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_reportPeer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  reason: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_checkUsername(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_checkUsername");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  username: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_deleteAccount(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_deleteAccount");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  reason: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_setAccountTTL(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_setAccountTTL");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  ttl: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_updateDeviceLocked(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_updateDeviceLocked");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  period: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_resetAuthorization(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_resetAuthorization");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_updatePasswordSettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_updatePasswordSettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  current_password_hash: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  new_settings: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_confirmPhone(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_confirmPhone");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_code_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_code: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_deleteContacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_deleteContacts");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_block(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_block");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_unblock(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_unblock");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_resetTopPeerRating(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_resetTopPeerRating");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  category: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_setTyping(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_setTyping");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  action: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_reportSpam(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_reportSpam");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_hideReportSpam(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_hideReportSpam");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_discardEncryption(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_discardEncryption");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_setEncryptedTyping(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_setEncryptedTyping");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  typing: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_readEncryptedHistory(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_readEncryptedHistory");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_reportEncryptedSpam(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_reportEncryptedSpam");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_uninstallStickerSet(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_uninstallStickerSet");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  stickerset: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_editChatAdmin(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_editChatAdmin");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  is_admin: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_reorderStickerSets(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_reorderStickerSets::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_reorderStickerSets");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  masks: "); ++stages.back(); if (flag & MTPmessages_reorderStickerSets::Flag::f_masks) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  order: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_saveGif(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_saveGif");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  unsave: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_setInlineBotResults(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_setInlineBotResults::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_setInlineBotResults");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  gallery: "); ++stages.back(); if (flag & MTPmessages_setInlineBotResults::Flag::f_gallery) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  private: "); ++stages.back(); if (flag & MTPmessages_setInlineBotResults::Flag::f_private) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  results: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  cache_time: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  next_offset: "); ++stages.back(); if (flag & MTPmessages_setInlineBotResults::Flag::f_next_offset) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 7: to.add("  switch_pm: "); ++stages.back(); if (flag & MTPmessages_setInlineBotResults::Flag::f_switch_pm) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_editInlineBotMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_editInlineBotMessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_editInlineBotMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  no_webpage: "); ++stages.back(); if (flag & MTPmessages_editInlineBotMessage::Flag::f_no_webpage) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  message: "); ++stages.back(); if (flag & MTPmessages_editInlineBotMessage::Flag::f_message) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 11 IN FIELD flags ]"); } break;
	case 4: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPmessages_editInlineBotMessage::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 5: to.add("  entities: "); ++stages.back(); if (flag & MTPmessages_editInlineBotMessage::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_setBotCallbackAnswer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_setBotCallbackAnswer::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_setBotCallbackAnswer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  alert: "); ++stages.back(); if (flag & MTPmessages_setBotCallbackAnswer::Flag::f_alert) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  message: "); ++stages.back(); if (flag & MTPmessages_setBotCallbackAnswer::Flag::f_message) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  url: "); ++stages.back(); if (flag & MTPmessages_setBotCallbackAnswer::Flag::f_url) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 5: to.add("  cache_time: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_saveDraft(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_saveDraft::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_saveDraft");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  no_webpage: "); ++stages.back(); if (flag & MTPmessages_saveDraft::Flag::f_no_webpage) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPmessages_saveDraft::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 3: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  entities: "); ++stages.back(); if (flag & MTPmessages_saveDraft::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_readFeaturedStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_readFeaturedStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_saveRecentSticker(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_saveRecentSticker::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_saveRecentSticker");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  attached: "); ++stages.back(); if (flag & MTPmessages_saveRecentSticker::Flag::f_attached) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  unsave: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_clearRecentStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_clearRecentStickers::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_clearRecentStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  attached: "); ++stages.back(); if (flag & MTPmessages_clearRecentStickers::Flag::f_attached) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_setInlineGameScore(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_setInlineGameScore::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_setInlineGameScore");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  edit_message: "); ++stages.back(); if (flag & MTPmessages_setInlineGameScore::Flag::f_edit_message) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  force: "); ++stages.back(); if (flag & MTPmessages_setInlineGameScore::Flag::f_force) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  score: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_toggleDialogPin(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_toggleDialogPin::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_toggleDialogPin");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pinned: "); ++stages.back(); if (flag & MTPmessages_toggleDialogPin::Flag::f_pinned) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_reorderPinnedDialogs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_reorderPinnedDialogs::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_reorderPinnedDialogs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  force: "); ++stages.back(); if (flag & MTPmessages_reorderPinnedDialogs::Flag::f_force) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  order: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_setBotShippingResults(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_setBotShippingResults::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_setBotShippingResults");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  error: "); ++stages.back(); if (flag & MTPmessages_setBotShippingResults::Flag::f_error) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 3: to.add("  shipping_options: "); ++stages.back(); if (flag & MTPmessages_setBotShippingResults::Flag::f_shipping_options) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_setBotPrecheckoutResults(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_setBotPrecheckoutResults::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_setBotPrecheckoutResults");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  success: "); ++stages.back(); if (flag & MTPmessages_setBotPrecheckoutResults::Flag::f_success) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  error: "); ++stages.back(); if (flag & MTPmessages_setBotPrecheckoutResults::Flag::f_error) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_saveFilePart(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_saveFilePart");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  file_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  file_part: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_saveBigFilePart(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_saveBigFilePart");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  file_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  file_part: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  file_total_parts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_reuploadCdnFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_reuploadCdnFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  file_token: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  request_token: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_help_saveAppLog(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ help_saveAppLog");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  events: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_help_setBotUpdatesStatus(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ help_setBotUpdatesStatus");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  pending_updates_count: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_readHistory(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_readHistory");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_reportSpam(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_reportSpam");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_editAbout(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_editAbout");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  about: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_checkUsername(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_checkUsername");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  username: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_updateUsername(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_updateUsername");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  username: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_bots_answerWebhookJSONQuery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ bots_answerWebhookJSONQuery");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  data: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_clearSavedInfo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPpayments_clearSavedInfo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_clearSavedInfo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  credentials: "); ++stages.back(); if (flag & MTPpayments_clearSavedInfo::Flag::f_credentials) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  info: "); ++stages.back(); if (flag & MTPpayments_clearSavedInfo::Flag::f_info) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phone_receivedCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phone_receivedCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phone_saveCallDebug(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phone_saveCallDebug");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  debug: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_invokeAfterMsg(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ invokeAfterMsg");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  query: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_invokeAfterMsgs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ invokeAfterMsgs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_ids: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  query: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_initConnection(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ initConnection");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  api_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  device_model: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  system_version: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  app_version: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  lang_code: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  query: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_invokeWithLayer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ invokeWithLayer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  layer: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  query: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_invokeWithoutUpdates(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ invokeWithoutUpdates");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  query: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_checkPhone(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_checkPhone");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_sendCode(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPauth_sendCode::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_sendCode");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  allow_flashcall: "); ++stages.back(); if (flag & MTPauth_sendCode::Flag::f_allow_flashcall) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  current_number: "); ++stages.back(); if (flag & MTPauth_sendCode::Flag::f_current_number) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  api_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  api_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_resendCode(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_resendCode");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_code_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_sendChangePhoneCode(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPaccount_sendChangePhoneCode::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_sendChangePhoneCode");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  allow_flashcall: "); ++stages.back(); if (flag & MTPaccount_sendChangePhoneCode::Flag::f_allow_flashcall) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  current_number: "); ++stages.back(); if (flag & MTPaccount_sendChangePhoneCode::Flag::f_current_number) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_sendConfirmPhoneCode(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPaccount_sendConfirmPhoneCode::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_sendConfirmPhoneCode");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  allow_flashcall: "); ++stages.back(); if (flag & MTPaccount_sendConfirmPhoneCode::Flag::f_allow_flashcall) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  current_number: "); ++stages.back(); if (flag & MTPaccount_sendConfirmPhoneCode::Flag::f_current_number) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_signUp(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_signUp");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_code_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  phone_code: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  first_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  last_name: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_signIn(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_signIn");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_code_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  phone_code: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_importAuthorization(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_importAuthorization");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_importBotAuthorization(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_importBotAuthorization");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  api_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  api_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  bot_auth_token: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_checkPassword(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_checkPassword");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  password_hash: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_recoverPassword(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_recoverPassword");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  code: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_exportAuthorization(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ auth_exportAuthorization");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  dc_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_auth_requestPasswordRecovery(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ auth_requestPasswordRecovery }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_account_getNotifySettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_getNotifySettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_updateProfile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPaccount_updateProfile::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_updateProfile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  first_name: "); ++stages.back(); if (flag & MTPaccount_updateProfile::Flag::f_first_name) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  last_name: "); ++stages.back(); if (flag & MTPaccount_updateProfile::Flag::f_last_name) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  about: "); ++stages.back(); if (flag & MTPaccount_updateProfile::Flag::f_about) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_updateUsername(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_updateUsername");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  username: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_changePhone(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_changePhone");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  phone_number: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  phone_code_hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  phone_code: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_importCard(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_importCard");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  export_card: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_getWallPapers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ account_getWallPapers }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_account_getPrivacy(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_getPrivacy");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  key: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_setPrivacy(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_setPrivacy");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  key: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  rules: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_getAccountTTL(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ account_getAccountTTL }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_account_getAuthorizations(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ account_getAuthorizations }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_account_getPassword(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ account_getPassword }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_account_getPasswordSettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_getPasswordSettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  current_password_hash: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_account_getTmpPassword(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ account_getTmpPassword");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  password_hash: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  period: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_users_getUsers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ users_getUsers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_users_getFullUser(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ users_getFullUser");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_getStatuses(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ contacts_getStatuses }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_contacts_getContacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_getContacts");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_importContacts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_importContacts");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  contacts: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  replace: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_deleteContact(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_deleteContact");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_getBlocked(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_getBlocked");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_exportCard(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ contacts_exportCard }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_getMessagesViews(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getMessagesViews");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  increment: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_search(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_search");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  q: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_resolveUsername(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_resolveUsername");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  username: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_contacts_getTopPeers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPcontacts_getTopPeers::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ contacts_getTopPeers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  correspondents: "); ++stages.back(); if (flag & MTPcontacts_getTopPeers::Flag::f_correspondents) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  bots_pm: "); ++stages.back(); if (flag & MTPcontacts_getTopPeers::Flag::f_bots_pm) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  bots_inline: "); ++stages.back(); if (flag & MTPcontacts_getTopPeers::Flag::f_bots_inline) { to.add("YES [ BY BIT 2 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 4: to.add("  groups: "); ++stages.back(); if (flag & MTPcontacts_getTopPeers::Flag::f_groups) { to.add("YES [ BY BIT 10 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 10 IN FIELD flags ]"); } break;
	case 5: to.add("  channels: "); ++stages.back(); if (flag & MTPcontacts_getTopPeers::Flag::f_channels) { to.add("YES [ BY BIT 15 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 15 IN FIELD flags ]"); } break;
	case 6: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getHistory(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getHistory");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  offset_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  offset_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  add_offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  min_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_search(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_search");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  q: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  filter: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  min_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  max_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_searchGlobal(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_searchGlobal");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  q: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  offset_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  offset_peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  offset_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_getMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_getMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getDialogs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_getDialogs::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getDialogs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  exclude_pinned: "); ++stages.back(); if (flag & MTPmessages_getDialogs::Flag::f_exclude_pinned) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  offset_date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  offset_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  offset_peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_readHistory(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_readHistory");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_deleteMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_deleteMessages::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_deleteMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  revoke: "); ++stages.back(); if (flag & MTPmessages_deleteMessages::Flag::f_revoke) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_readMessageContents(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_readMessageContents");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_deleteMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_deleteMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_deleteHistory(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_deleteHistory::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_deleteHistory");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  just_clear: "); ++stages.back(); if (flag & MTPmessages_deleteHistory::Flag::f_just_clear) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_deleteUserHistory(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_deleteUserHistory");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_receivedMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_receivedMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_sendMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_sendMessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_sendMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  no_webpage: "); ++stages.back(); if (flag & MTPmessages_sendMessage::Flag::f_no_webpage) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  silent: "); ++stages.back(); if (flag & MTPmessages_sendMessage::Flag::f_silent) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 3: to.add("  background: "); ++stages.back(); if (flag & MTPmessages_sendMessage::Flag::f_background) { to.add("YES [ BY BIT 6 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 4: to.add("  clear_draft: "); ++stages.back(); if (flag & MTPmessages_sendMessage::Flag::f_clear_draft) { to.add("YES [ BY BIT 7 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	case 5: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPmessages_sendMessage::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 7: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 9: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPmessages_sendMessage::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 10: to.add("  entities: "); ++stages.back(); if (flag & MTPmessages_sendMessage::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_sendMedia(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_sendMedia::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_sendMedia");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  silent: "); ++stages.back(); if (flag & MTPmessages_sendMedia::Flag::f_silent) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 2: to.add("  background: "); ++stages.back(); if (flag & MTPmessages_sendMedia::Flag::f_background) { to.add("YES [ BY BIT 6 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 3: to.add("  clear_draft: "); ++stages.back(); if (flag & MTPmessages_sendMedia::Flag::f_clear_draft) { to.add("YES [ BY BIT 7 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	case 4: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPmessages_sendMedia::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 6: to.add("  media: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPmessages_sendMedia::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_forwardMessages(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_forwardMessages::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_forwardMessages");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  silent: "); ++stages.back(); if (flag & MTPmessages_forwardMessages::Flag::f_silent) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 2: to.add("  background: "); ++stages.back(); if (flag & MTPmessages_forwardMessages::Flag::f_background) { to.add("YES [ BY BIT 6 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 3: to.add("  with_my_score: "); ++stages.back(); if (flag & MTPmessages_forwardMessages::Flag::f_with_my_score) { to.add("YES [ BY BIT 8 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 8 IN FIELD flags ]"); } break;
	case 4: to.add("  from_peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  random_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_long+0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  to_peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_editChatTitle(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_editChatTitle");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_editChatPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_editChatPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_addChatUser(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_addChatUser");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  fwd_limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_deleteChatUser(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_deleteChatUser");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_createChat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_createChat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_forwardMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_forwardMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_importChatInvite(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_importChatInvite");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_startBot(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_startBot");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  bot: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  start_param: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_toggleChatAdmins(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_toggleChatAdmins");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  enabled: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_migrateChat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_migrateChat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_sendInlineBotResult(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_sendInlineBotResult::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_sendInlineBotResult");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  silent: "); ++stages.back(); if (flag & MTPmessages_sendInlineBotResult::Flag::f_silent) { to.add("YES [ BY BIT 5 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 5 IN FIELD flags ]"); } break;
	case 2: to.add("  background: "); ++stages.back(); if (flag & MTPmessages_sendInlineBotResult::Flag::f_background) { to.add("YES [ BY BIT 6 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 6 IN FIELD flags ]"); } break;
	case 3: to.add("  clear_draft: "); ++stages.back(); if (flag & MTPmessages_sendInlineBotResult::Flag::f_clear_draft) { to.add("YES [ BY BIT 7 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 7 IN FIELD flags ]"); } break;
	case 4: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  reply_to_msg_id: "); ++stages.back(); if (flag & MTPmessages_sendInlineBotResult::Flag::f_reply_to_msg_id) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 6: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 7: to.add("  query_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 8: to.add("  id: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_editMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_editMessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_editMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  no_webpage: "); ++stages.back(); if (flag & MTPmessages_editMessage::Flag::f_no_webpage) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  message: "); ++stages.back(); if (flag & MTPmessages_editMessage::Flag::f_message) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 11 IN FIELD flags ]"); } break;
	case 5: to.add("  reply_markup: "); ++stages.back(); if (flag & MTPmessages_editMessage::Flag::f_reply_markup) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 2 IN FIELD flags ]"); } break;
	case 6: to.add("  entities: "); ++stages.back(); if (flag & MTPmessages_editMessage::Flag::f_entities) { types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 3 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getAllDrafts(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messages_getAllDrafts }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_setGameScore(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_setGameScore::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_setGameScore");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  edit_message: "); ++stages.back(); if (flag & MTPmessages_setGameScore::Flag::f_edit_message) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  force: "); ++stages.back(); if (flag & MTPmessages_setGameScore::Flag::f_force) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 6: to.add("  score: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_help_getAppChangelog(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ help_getAppChangelog");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  prev_app_version: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_createChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPchannels_createChannel::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_createChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  broadcast: "); ++stages.back(); if (flag & MTPchannels_createChannel::Flag::f_broadcast) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  megagroup: "); ++stages.back(); if (flag & MTPchannels_createChannel::Flag::f_megagroup) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 3: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  about: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_editAdmin(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_editAdmin");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  role: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_editTitle(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_editTitle");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  title: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_editPhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_editPhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  photo: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_joinChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_joinChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_leaveChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_leaveChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_inviteToChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_inviteToChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  users: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_kickFromChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_kickFromChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  kicked: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_deleteChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_deleteChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_toggleInvites(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_toggleInvites");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  enabled: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_toggleSignatures(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_toggleSignatures");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  enabled: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_updatePinnedMessage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPchannels_updatePinnedMessage::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_updatePinnedMessage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  silent: "); ++stages.back(); if (flag & MTPchannels_updatePinnedMessage::Flag::f_silent) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phone_discardCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phone_discardCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  duration: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  reason: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  connection_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phone_setCallRating(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phone_setCallRating");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  rating: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  comment: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getPeerSettings(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getPeerSettings");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getChats(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getChats");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getCommonChats(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getCommonChats");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getAllChats(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getAllChats");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  except_ids: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_getChannels(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_getChannels");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_getAdminedPublicChannels(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ channels_getAdminedPublicChannels }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_getFullChat(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getFullChat");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_getFullChannel(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_getFullChannel");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getDhConfig(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getDhConfig");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  version: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  random_length: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_requestEncryption(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_requestEncryption");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  g_a: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_acceptEncryption(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_acceptEncryption");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  g_b: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  key_fingerprint: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_sendEncrypted(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_sendEncrypted");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  data: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_sendEncryptedFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_sendEncryptedFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  data: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  file: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_sendEncryptedService(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_sendEncryptedService");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  data: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_receivedQueue(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_receivedQueue");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  max_qts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photos_deletePhotos(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photos_deletePhotos");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getAllStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getAllStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getMaskStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getMaskStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getWebPagePreview(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getWebPagePreview");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  message: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_exportChatInvite(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_exportChatInvite");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  chat_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_exportInvite(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_exportInvite");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_checkChatInvite(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_checkChatInvite");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getStickerSet(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getStickerSet");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  stickerset: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_installStickerSet(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_installStickerSet");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  stickerset: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  archived: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getDocumentByHash(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getDocumentByHash");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  sha256: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  size: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  mime_type: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_searchGifs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_searchGifs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  q: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getSavedGifs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getSavedGifs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getInlineBotResults(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_getInlineBotResults::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getInlineBotResults");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  bot: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  geo_point: "); ++stages.back(); if (flag & MTPmessages_getInlineBotResults::Flag::f_geo_point) { types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 4: to.add("  query: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getMessageEditData(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getMessageEditData");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getBotCallbackAnswer(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_getBotCallbackAnswer::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getBotCallbackAnswer");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  game: "); ++stages.back(); if (flag & MTPmessages_getBotCallbackAnswer::Flag::f_game) { to.add("YES [ BY BIT 1 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 2: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  data: "); ++stages.back(); if (flag & MTPmessages_getBotCallbackAnswer::Flag::f_data) { types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getPeerDialogs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getPeerDialogs");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peers: "); ++stages.back(); types.push_back(00); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getPinnedDialogs(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ messages_getPinnedDialogs }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_messages_getFeaturedStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getFeaturedStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getRecentStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_getRecentStickers::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getRecentStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  attached: "); ++stages.back(); if (flag & MTPmessages_getRecentStickers::Flag::f_attached) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getArchivedStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPmessages_getArchivedStickers::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getArchivedStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  masks: "); ++stages.back(); if (flag & MTPmessages_getArchivedStickers::Flag::f_masks) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  offset_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getAttachedStickers(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getAttachedStickers");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  media: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getGameHighScores(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getGameHighScores");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getInlineGameHighScores(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getInlineGameHighScores");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_messages_getWebPage(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ messages_getWebPage");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  url: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  hash: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_getState(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ updates_getState }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_updates_getDifference(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPupdates_getDifference::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_getDifference");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  pts_total_limit: "); ++stages.back(); if (flag & MTPupdates_getDifference::Flag::f_pts_total_limit) { types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 3: to.add("  date: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  qts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_updates_getChannelDifference(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPupdates_getChannelDifference::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ updates_getChannelDifference");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  force: "); ++stages.back(); if (flag & MTPupdates_getChannelDifference::Flag::f_force) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  filter: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 4: to.add("  pts: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 5: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photos_updateProfilePhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photos_updateProfilePhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photos_uploadProfilePhoto(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photos_uploadProfilePhoto");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  file: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_photos_getUserPhotos(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ photos_getUserPhotos");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  max_id: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_getFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_getFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  location: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_getWebFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_getWebFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  location: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_upload_getCdnFile(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ upload_getCdnFile");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  file_token: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_help_getConfig(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ help_getConfig }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_help_getNearestDc(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ help_getNearestDc }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_help_getAppUpdate(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ help_getAppUpdate }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_help_getInviteText(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ help_getInviteText }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_help_getSupport(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ help_getSupport }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_help_getTermsOfService(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ help_getTermsOfService }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_help_getCdnConfig(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ help_getCdnConfig }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_channels_getParticipants(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_getParticipants");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  filter: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  offset: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  limit: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_getParticipant(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_getParticipant");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_channels_exportMessageLink(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ channels_exportMessageLink");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_bots_sendCustomRequest(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ bots_sendCustomRequest");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  custom_method: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  params: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phone_getCallConfig(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ phone_getCallConfig }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_payments_getPaymentForm(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_getPaymentForm");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_getPaymentReceipt(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_getPaymentReceipt");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_validateRequestedInfo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPpayments_validateRequestedInfo::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_validateRequestedInfo");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  save: "); ++stages.back(); if (flag & MTPpayments_validateRequestedInfo::Flag::f_save) { to.add("YES [ BY BIT 0 IN FIELD flags ]"); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 2: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  info: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_sendPaymentForm(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	MTPpayments_sendPaymentForm::Flags flag(iflag);

	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ payments_sendPaymentForm");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  flags: "); ++stages.back(); if (start >= end) throw Exception("start >= end in flags"); else flags.back() = *start; types.push_back(mtpc_flags); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  requested_info_id: "); ++stages.back(); if (flag & MTPpayments_sendPaymentForm::Flag::f_requested_info_id) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 0 IN FIELD flags ]"); } break;
	case 3: to.add("  shipping_option_id: "); ++stages.back(); if (flag & MTPpayments_sendPaymentForm::Flag::f_shipping_option_id) { types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); } else { to.add("[ SKIPPED BY BIT 1 IN FIELD flags ]"); } break;
	case 4: to.add("  credentials: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_payments_getSavedInfo(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	to.add("{ payments_getSavedInfo }"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
}

void Serialize_phone_requestCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phone_requestCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  user_id: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  random_id: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  g_a_hash: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  protocol: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phone_acceptCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phone_acceptCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  g_b: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  protocol: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void Serialize_phone_confirmCall(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ phone_confirmCall");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  peer: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  g_a: "); ++stages.back(); types.push_back(mtpc_bytes+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  key_fingerprint: "); ++stages.back(); types.push_back(mtpc_long+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  protocol: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void _serialize_rpc_result(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ rpc_result");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  req_msg_id: "); ++stages.back(); types.push_back(mtpc_long); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  result: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void _serialize_msg_container(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ msg_container");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  messages: "); ++stages.back(); types.push_back(mtpc_vector); vtypes.push_back(mtpc_core_message); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}

void _serialize_core_message(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag) {
	if (stage) {
		to.add(",\n").addSpaces(lev);
	} else {
		to.add("{ core_message");
		to.add("\n").addSpaces(lev);
	}
	switch (stage) {
	case 0: to.add("  msg_id: "); ++stages.back(); types.push_back(mtpc_long); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 1: to.add("  seq_no: "); ++stages.back(); types.push_back(mtpc_int); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 2: to.add("  bytes: "); ++stages.back(); types.push_back(mtpc_int); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	case 3: to.add("  body: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
	default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
	}
}


namespace {

using TextSerializer = void (*)(MTPStringLogger &to, int32 stage, int32 lev, Types &types, Types &vtypes, StagesFlags &stages, StagesFlags &flags, const mtpPrime *start, const mtpPrime *end, int32 iflag);
using TextSerializers = QMap<mtpTypeId, TextSerializer>;

QMap<mtpTypeId, TextSerializer> createTextSerializers() {
	auto result = QMap<mtpTypeId, TextSerializer>();

	result.insert(mtpc_resPQ, Serialize_resPQ);
	result.insert(mtpc_p_q_inner_data, Serialize_p_q_inner_data);
	result.insert(mtpc_server_DH_params_fail, Serialize_server_DH_params_fail);
	result.insert(mtpc_server_DH_params_ok, Serialize_server_DH_params_ok);
	result.insert(mtpc_server_DH_inner_data, Serialize_server_DH_inner_data);
	result.insert(mtpc_client_DH_inner_data, Serialize_client_DH_inner_data);
	result.insert(mtpc_dh_gen_ok, Serialize_dh_gen_ok);
	result.insert(mtpc_dh_gen_retry, Serialize_dh_gen_retry);
	result.insert(mtpc_dh_gen_fail, Serialize_dh_gen_fail);
	result.insert(mtpc_destroy_auth_key_ok, Serialize_destroy_auth_key_ok);
	result.insert(mtpc_destroy_auth_key_none, Serialize_destroy_auth_key_none);
	result.insert(mtpc_destroy_auth_key_fail, Serialize_destroy_auth_key_fail);
	result.insert(mtpc_msgs_ack, Serialize_msgs_ack);
	result.insert(mtpc_bad_msg_notification, Serialize_bad_msg_notification);
	result.insert(mtpc_bad_server_salt, Serialize_bad_server_salt);
	result.insert(mtpc_msgs_state_req, Serialize_msgs_state_req);
	result.insert(mtpc_msgs_state_info, Serialize_msgs_state_info);
	result.insert(mtpc_msgs_all_info, Serialize_msgs_all_info);
	result.insert(mtpc_msg_detailed_info, Serialize_msg_detailed_info);
	result.insert(mtpc_msg_new_detailed_info, Serialize_msg_new_detailed_info);
	result.insert(mtpc_msg_resend_req, Serialize_msg_resend_req);
	result.insert(mtpc_rpc_error, Serialize_rpc_error);
	result.insert(mtpc_rpc_answer_unknown, Serialize_rpc_answer_unknown);
	result.insert(mtpc_rpc_answer_dropped_running, Serialize_rpc_answer_dropped_running);
	result.insert(mtpc_rpc_answer_dropped, Serialize_rpc_answer_dropped);
	result.insert(mtpc_future_salt, Serialize_future_salt);
	result.insert(mtpc_future_salts, Serialize_future_salts);
	result.insert(mtpc_pong, Serialize_pong);
	result.insert(mtpc_destroy_session_ok, Serialize_destroy_session_ok);
	result.insert(mtpc_destroy_session_none, Serialize_destroy_session_none);
	result.insert(mtpc_new_session_created, Serialize_new_session_created);
	result.insert(mtpc_http_wait, Serialize_http_wait);
	result.insert(mtpc_boolFalse, Serialize_boolFalse);
	result.insert(mtpc_boolTrue, Serialize_boolTrue);
	result.insert(mtpc_true, Serialize_true);
	result.insert(mtpc_error, Serialize_error);
	result.insert(mtpc_null, Serialize_null);
	result.insert(mtpc_inputPeerEmpty, Serialize_inputPeerEmpty);
	result.insert(mtpc_inputPeerSelf, Serialize_inputPeerSelf);
	result.insert(mtpc_inputPeerChat, Serialize_inputPeerChat);
	result.insert(mtpc_inputPeerUser, Serialize_inputPeerUser);
	result.insert(mtpc_inputPeerChannel, Serialize_inputPeerChannel);
	result.insert(mtpc_inputUserEmpty, Serialize_inputUserEmpty);
	result.insert(mtpc_inputUserSelf, Serialize_inputUserSelf);
	result.insert(mtpc_inputUser, Serialize_inputUser);
	result.insert(mtpc_inputPhoneContact, Serialize_inputPhoneContact);
	result.insert(mtpc_inputFile, Serialize_inputFile);
	result.insert(mtpc_inputFileBig, Serialize_inputFileBig);
	result.insert(mtpc_inputMediaEmpty, Serialize_inputMediaEmpty);
	result.insert(mtpc_inputMediaUploadedPhoto, Serialize_inputMediaUploadedPhoto);
	result.insert(mtpc_inputMediaPhoto, Serialize_inputMediaPhoto);
	result.insert(mtpc_inputMediaGeoPoint, Serialize_inputMediaGeoPoint);
	result.insert(mtpc_inputMediaContact, Serialize_inputMediaContact);
	result.insert(mtpc_inputMediaUploadedDocument, Serialize_inputMediaUploadedDocument);
	result.insert(mtpc_inputMediaUploadedThumbDocument, Serialize_inputMediaUploadedThumbDocument);
	result.insert(mtpc_inputMediaDocument, Serialize_inputMediaDocument);
	result.insert(mtpc_inputMediaVenue, Serialize_inputMediaVenue);
	result.insert(mtpc_inputMediaGifExternal, Serialize_inputMediaGifExternal);
	result.insert(mtpc_inputMediaPhotoExternal, Serialize_inputMediaPhotoExternal);
	result.insert(mtpc_inputMediaDocumentExternal, Serialize_inputMediaDocumentExternal);
	result.insert(mtpc_inputMediaGame, Serialize_inputMediaGame);
	result.insert(mtpc_inputMediaInvoice, Serialize_inputMediaInvoice);
	result.insert(mtpc_inputChatPhotoEmpty, Serialize_inputChatPhotoEmpty);
	result.insert(mtpc_inputChatUploadedPhoto, Serialize_inputChatUploadedPhoto);
	result.insert(mtpc_inputChatPhoto, Serialize_inputChatPhoto);
	result.insert(mtpc_inputGeoPointEmpty, Serialize_inputGeoPointEmpty);
	result.insert(mtpc_inputGeoPoint, Serialize_inputGeoPoint);
	result.insert(mtpc_inputPhotoEmpty, Serialize_inputPhotoEmpty);
	result.insert(mtpc_inputPhoto, Serialize_inputPhoto);
	result.insert(mtpc_inputFileLocation, Serialize_inputFileLocation);
	result.insert(mtpc_inputEncryptedFileLocation, Serialize_inputEncryptedFileLocation);
	result.insert(mtpc_inputDocumentFileLocation, Serialize_inputDocumentFileLocation);
	result.insert(mtpc_inputAppEvent, Serialize_inputAppEvent);
	result.insert(mtpc_peerUser, Serialize_peerUser);
	result.insert(mtpc_peerChat, Serialize_peerChat);
	result.insert(mtpc_peerChannel, Serialize_peerChannel);
	result.insert(mtpc_storage_fileUnknown, Serialize_storage_fileUnknown);
	result.insert(mtpc_storage_filePartial, Serialize_storage_filePartial);
	result.insert(mtpc_storage_fileJpeg, Serialize_storage_fileJpeg);
	result.insert(mtpc_storage_fileGif, Serialize_storage_fileGif);
	result.insert(mtpc_storage_filePng, Serialize_storage_filePng);
	result.insert(mtpc_storage_filePdf, Serialize_storage_filePdf);
	result.insert(mtpc_storage_fileMp3, Serialize_storage_fileMp3);
	result.insert(mtpc_storage_fileMov, Serialize_storage_fileMov);
	result.insert(mtpc_storage_fileMp4, Serialize_storage_fileMp4);
	result.insert(mtpc_storage_fileWebp, Serialize_storage_fileWebp);
	result.insert(mtpc_fileLocationUnavailable, Serialize_fileLocationUnavailable);
	result.insert(mtpc_fileLocation, Serialize_fileLocation);
	result.insert(mtpc_userEmpty, Serialize_userEmpty);
	result.insert(mtpc_user, Serialize_user);
	result.insert(mtpc_userProfilePhotoEmpty, Serialize_userProfilePhotoEmpty);
	result.insert(mtpc_userProfilePhoto, Serialize_userProfilePhoto);
	result.insert(mtpc_userStatusEmpty, Serialize_userStatusEmpty);
	result.insert(mtpc_userStatusOnline, Serialize_userStatusOnline);
	result.insert(mtpc_userStatusOffline, Serialize_userStatusOffline);
	result.insert(mtpc_userStatusRecently, Serialize_userStatusRecently);
	result.insert(mtpc_userStatusLastWeek, Serialize_userStatusLastWeek);
	result.insert(mtpc_userStatusLastMonth, Serialize_userStatusLastMonth);
	result.insert(mtpc_chatEmpty, Serialize_chatEmpty);
	result.insert(mtpc_chat, Serialize_chat);
	result.insert(mtpc_chatForbidden, Serialize_chatForbidden);
	result.insert(mtpc_channel, Serialize_channel);
	result.insert(mtpc_channelForbidden, Serialize_channelForbidden);
	result.insert(mtpc_chatFull, Serialize_chatFull);
	result.insert(mtpc_channelFull, Serialize_channelFull);
	result.insert(mtpc_chatParticipant, Serialize_chatParticipant);
	result.insert(mtpc_chatParticipantCreator, Serialize_chatParticipantCreator);
	result.insert(mtpc_chatParticipantAdmin, Serialize_chatParticipantAdmin);
	result.insert(mtpc_chatParticipantsForbidden, Serialize_chatParticipantsForbidden);
	result.insert(mtpc_chatParticipants, Serialize_chatParticipants);
	result.insert(mtpc_chatPhotoEmpty, Serialize_chatPhotoEmpty);
	result.insert(mtpc_chatPhoto, Serialize_chatPhoto);
	result.insert(mtpc_messageEmpty, Serialize_messageEmpty);
	result.insert(mtpc_message, Serialize_message);
	result.insert(mtpc_messageService, Serialize_messageService);
	result.insert(mtpc_messageMediaEmpty, Serialize_messageMediaEmpty);
	result.insert(mtpc_messageMediaPhoto, Serialize_messageMediaPhoto);
	result.insert(mtpc_messageMediaGeo, Serialize_messageMediaGeo);
	result.insert(mtpc_messageMediaContact, Serialize_messageMediaContact);
	result.insert(mtpc_messageMediaUnsupported, Serialize_messageMediaUnsupported);
	result.insert(mtpc_messageMediaDocument, Serialize_messageMediaDocument);
	result.insert(mtpc_messageMediaWebPage, Serialize_messageMediaWebPage);
	result.insert(mtpc_messageMediaVenue, Serialize_messageMediaVenue);
	result.insert(mtpc_messageMediaGame, Serialize_messageMediaGame);
	result.insert(mtpc_messageMediaInvoice, Serialize_messageMediaInvoice);
	result.insert(mtpc_messageActionEmpty, Serialize_messageActionEmpty);
	result.insert(mtpc_messageActionChatCreate, Serialize_messageActionChatCreate);
	result.insert(mtpc_messageActionChatEditTitle, Serialize_messageActionChatEditTitle);
	result.insert(mtpc_messageActionChatEditPhoto, Serialize_messageActionChatEditPhoto);
	result.insert(mtpc_messageActionChatDeletePhoto, Serialize_messageActionChatDeletePhoto);
	result.insert(mtpc_messageActionChatAddUser, Serialize_messageActionChatAddUser);
	result.insert(mtpc_messageActionChatDeleteUser, Serialize_messageActionChatDeleteUser);
	result.insert(mtpc_messageActionChatJoinedByLink, Serialize_messageActionChatJoinedByLink);
	result.insert(mtpc_messageActionChannelCreate, Serialize_messageActionChannelCreate);
	result.insert(mtpc_messageActionChatMigrateTo, Serialize_messageActionChatMigrateTo);
	result.insert(mtpc_messageActionChannelMigrateFrom, Serialize_messageActionChannelMigrateFrom);
	result.insert(mtpc_messageActionPinMessage, Serialize_messageActionPinMessage);
	result.insert(mtpc_messageActionHistoryClear, Serialize_messageActionHistoryClear);
	result.insert(mtpc_messageActionGameScore, Serialize_messageActionGameScore);
	result.insert(mtpc_messageActionPaymentSentMe, Serialize_messageActionPaymentSentMe);
	result.insert(mtpc_messageActionPaymentSent, Serialize_messageActionPaymentSent);
	result.insert(mtpc_messageActionPhoneCall, Serialize_messageActionPhoneCall);
	result.insert(mtpc_dialog, Serialize_dialog);
	result.insert(mtpc_photoEmpty, Serialize_photoEmpty);
	result.insert(mtpc_photo, Serialize_photo);
	result.insert(mtpc_photoSizeEmpty, Serialize_photoSizeEmpty);
	result.insert(mtpc_photoSize, Serialize_photoSize);
	result.insert(mtpc_photoCachedSize, Serialize_photoCachedSize);
	result.insert(mtpc_geoPointEmpty, Serialize_geoPointEmpty);
	result.insert(mtpc_geoPoint, Serialize_geoPoint);
	result.insert(mtpc_auth_checkedPhone, Serialize_auth_checkedPhone);
	result.insert(mtpc_auth_sentCode, Serialize_auth_sentCode);
	result.insert(mtpc_auth_authorization, Serialize_auth_authorization);
	result.insert(mtpc_auth_exportedAuthorization, Serialize_auth_exportedAuthorization);
	result.insert(mtpc_inputNotifyPeer, Serialize_inputNotifyPeer);
	result.insert(mtpc_inputNotifyUsers, Serialize_inputNotifyUsers);
	result.insert(mtpc_inputNotifyChats, Serialize_inputNotifyChats);
	result.insert(mtpc_inputNotifyAll, Serialize_inputNotifyAll);
	result.insert(mtpc_inputPeerNotifyEventsEmpty, Serialize_inputPeerNotifyEventsEmpty);
	result.insert(mtpc_inputPeerNotifyEventsAll, Serialize_inputPeerNotifyEventsAll);
	result.insert(mtpc_inputPeerNotifySettings, Serialize_inputPeerNotifySettings);
	result.insert(mtpc_peerNotifyEventsEmpty, Serialize_peerNotifyEventsEmpty);
	result.insert(mtpc_peerNotifyEventsAll, Serialize_peerNotifyEventsAll);
	result.insert(mtpc_peerNotifySettingsEmpty, Serialize_peerNotifySettingsEmpty);
	result.insert(mtpc_peerNotifySettings, Serialize_peerNotifySettings);
	result.insert(mtpc_peerSettings, Serialize_peerSettings);
	result.insert(mtpc_wallPaper, Serialize_wallPaper);
	result.insert(mtpc_wallPaperSolid, Serialize_wallPaperSolid);
	result.insert(mtpc_inputReportReasonSpam, Serialize_inputReportReasonSpam);
	result.insert(mtpc_inputReportReasonViolence, Serialize_inputReportReasonViolence);
	result.insert(mtpc_inputReportReasonPornography, Serialize_inputReportReasonPornography);
	result.insert(mtpc_inputReportReasonOther, Serialize_inputReportReasonOther);
	result.insert(mtpc_userFull, Serialize_userFull);
	result.insert(mtpc_contact, Serialize_contact);
	result.insert(mtpc_importedContact, Serialize_importedContact);
	result.insert(mtpc_contactBlocked, Serialize_contactBlocked);
	result.insert(mtpc_contactStatus, Serialize_contactStatus);
	result.insert(mtpc_contacts_link, Serialize_contacts_link);
	result.insert(mtpc_contacts_contactsNotModified, Serialize_contacts_contactsNotModified);
	result.insert(mtpc_contacts_contacts, Serialize_contacts_contacts);
	result.insert(mtpc_contacts_importedContacts, Serialize_contacts_importedContacts);
	result.insert(mtpc_contacts_blocked, Serialize_contacts_blocked);
	result.insert(mtpc_contacts_blockedSlice, Serialize_contacts_blockedSlice);
	result.insert(mtpc_messages_dialogs, Serialize_messages_dialogs);
	result.insert(mtpc_messages_dialogsSlice, Serialize_messages_dialogsSlice);
	result.insert(mtpc_messages_messages, Serialize_messages_messages);
	result.insert(mtpc_messages_messagesSlice, Serialize_messages_messagesSlice);
	result.insert(mtpc_messages_channelMessages, Serialize_messages_channelMessages);
	result.insert(mtpc_messages_chats, Serialize_messages_chats);
	result.insert(mtpc_messages_chatsSlice, Serialize_messages_chatsSlice);
	result.insert(mtpc_messages_chatFull, Serialize_messages_chatFull);
	result.insert(mtpc_messages_affectedHistory, Serialize_messages_affectedHistory);
	result.insert(mtpc_inputMessagesFilterEmpty, Serialize_inputMessagesFilterEmpty);
	result.insert(mtpc_inputMessagesFilterPhotos, Serialize_inputMessagesFilterPhotos);
	result.insert(mtpc_inputMessagesFilterVideo, Serialize_inputMessagesFilterVideo);
	result.insert(mtpc_inputMessagesFilterPhotoVideo, Serialize_inputMessagesFilterPhotoVideo);
	result.insert(mtpc_inputMessagesFilterPhotoVideoDocuments, Serialize_inputMessagesFilterPhotoVideoDocuments);
	result.insert(mtpc_inputMessagesFilterDocument, Serialize_inputMessagesFilterDocument);
	result.insert(mtpc_inputMessagesFilterUrl, Serialize_inputMessagesFilterUrl);
	result.insert(mtpc_inputMessagesFilterGif, Serialize_inputMessagesFilterGif);
	result.insert(mtpc_inputMessagesFilterVoice, Serialize_inputMessagesFilterVoice);
	result.insert(mtpc_inputMessagesFilterMusic, Serialize_inputMessagesFilterMusic);
	result.insert(mtpc_inputMessagesFilterChatPhotos, Serialize_inputMessagesFilterChatPhotos);
	result.insert(mtpc_inputMessagesFilterPhoneCalls, Serialize_inputMessagesFilterPhoneCalls);
	result.insert(mtpc_inputMessagesFilterRoundVoice, Serialize_inputMessagesFilterRoundVoice);
	result.insert(mtpc_inputMessagesFilterRoundVideo, Serialize_inputMessagesFilterRoundVideo);
	result.insert(mtpc_updateNewMessage, Serialize_updateNewMessage);
	result.insert(mtpc_updateMessageID, Serialize_updateMessageID);
	result.insert(mtpc_updateDeleteMessages, Serialize_updateDeleteMessages);
	result.insert(mtpc_updateUserTyping, Serialize_updateUserTyping);
	result.insert(mtpc_updateChatUserTyping, Serialize_updateChatUserTyping);
	result.insert(mtpc_updateChatParticipants, Serialize_updateChatParticipants);
	result.insert(mtpc_updateUserStatus, Serialize_updateUserStatus);
	result.insert(mtpc_updateUserName, Serialize_updateUserName);
	result.insert(mtpc_updateUserPhoto, Serialize_updateUserPhoto);
	result.insert(mtpc_updateContactRegistered, Serialize_updateContactRegistered);
	result.insert(mtpc_updateContactLink, Serialize_updateContactLink);
	result.insert(mtpc_updateNewEncryptedMessage, Serialize_updateNewEncryptedMessage);
	result.insert(mtpc_updateEncryptedChatTyping, Serialize_updateEncryptedChatTyping);
	result.insert(mtpc_updateEncryption, Serialize_updateEncryption);
	result.insert(mtpc_updateEncryptedMessagesRead, Serialize_updateEncryptedMessagesRead);
	result.insert(mtpc_updateChatParticipantAdd, Serialize_updateChatParticipantAdd);
	result.insert(mtpc_updateChatParticipantDelete, Serialize_updateChatParticipantDelete);
	result.insert(mtpc_updateDcOptions, Serialize_updateDcOptions);
	result.insert(mtpc_updateUserBlocked, Serialize_updateUserBlocked);
	result.insert(mtpc_updateNotifySettings, Serialize_updateNotifySettings);
	result.insert(mtpc_updateServiceNotification, Serialize_updateServiceNotification);
	result.insert(mtpc_updatePrivacy, Serialize_updatePrivacy);
	result.insert(mtpc_updateUserPhone, Serialize_updateUserPhone);
	result.insert(mtpc_updateReadHistoryInbox, Serialize_updateReadHistoryInbox);
	result.insert(mtpc_updateReadHistoryOutbox, Serialize_updateReadHistoryOutbox);
	result.insert(mtpc_updateWebPage, Serialize_updateWebPage);
	result.insert(mtpc_updateReadMessagesContents, Serialize_updateReadMessagesContents);
	result.insert(mtpc_updateChannelTooLong, Serialize_updateChannelTooLong);
	result.insert(mtpc_updateChannel, Serialize_updateChannel);
	result.insert(mtpc_updateNewChannelMessage, Serialize_updateNewChannelMessage);
	result.insert(mtpc_updateReadChannelInbox, Serialize_updateReadChannelInbox);
	result.insert(mtpc_updateDeleteChannelMessages, Serialize_updateDeleteChannelMessages);
	result.insert(mtpc_updateChannelMessageViews, Serialize_updateChannelMessageViews);
	result.insert(mtpc_updateChatAdmins, Serialize_updateChatAdmins);
	result.insert(mtpc_updateChatParticipantAdmin, Serialize_updateChatParticipantAdmin);
	result.insert(mtpc_updateNewStickerSet, Serialize_updateNewStickerSet);
	result.insert(mtpc_updateStickerSetsOrder, Serialize_updateStickerSetsOrder);
	result.insert(mtpc_updateStickerSets, Serialize_updateStickerSets);
	result.insert(mtpc_updateSavedGifs, Serialize_updateSavedGifs);
	result.insert(mtpc_updateBotInlineQuery, Serialize_updateBotInlineQuery);
	result.insert(mtpc_updateBotInlineSend, Serialize_updateBotInlineSend);
	result.insert(mtpc_updateEditChannelMessage, Serialize_updateEditChannelMessage);
	result.insert(mtpc_updateChannelPinnedMessage, Serialize_updateChannelPinnedMessage);
	result.insert(mtpc_updateBotCallbackQuery, Serialize_updateBotCallbackQuery);
	result.insert(mtpc_updateEditMessage, Serialize_updateEditMessage);
	result.insert(mtpc_updateInlineBotCallbackQuery, Serialize_updateInlineBotCallbackQuery);
	result.insert(mtpc_updateReadChannelOutbox, Serialize_updateReadChannelOutbox);
	result.insert(mtpc_updateDraftMessage, Serialize_updateDraftMessage);
	result.insert(mtpc_updateReadFeaturedStickers, Serialize_updateReadFeaturedStickers);
	result.insert(mtpc_updateRecentStickers, Serialize_updateRecentStickers);
	result.insert(mtpc_updateConfig, Serialize_updateConfig);
	result.insert(mtpc_updatePtsChanged, Serialize_updatePtsChanged);
	result.insert(mtpc_updateChannelWebPage, Serialize_updateChannelWebPage);
	result.insert(mtpc_updateDialogPinned, Serialize_updateDialogPinned);
	result.insert(mtpc_updatePinnedDialogs, Serialize_updatePinnedDialogs);
	result.insert(mtpc_updateBotWebhookJSON, Serialize_updateBotWebhookJSON);
	result.insert(mtpc_updateBotWebhookJSONQuery, Serialize_updateBotWebhookJSONQuery);
	result.insert(mtpc_updateBotShippingQuery, Serialize_updateBotShippingQuery);
	result.insert(mtpc_updateBotPrecheckoutQuery, Serialize_updateBotPrecheckoutQuery);
	result.insert(mtpc_updatePhoneCall, Serialize_updatePhoneCall);
	result.insert(mtpc_updates_state, Serialize_updates_state);
	result.insert(mtpc_updates_differenceEmpty, Serialize_updates_differenceEmpty);
	result.insert(mtpc_updates_difference, Serialize_updates_difference);
	result.insert(mtpc_updates_differenceSlice, Serialize_updates_differenceSlice);
	result.insert(mtpc_updates_differenceTooLong, Serialize_updates_differenceTooLong);
	result.insert(mtpc_updatesTooLong, Serialize_updatesTooLong);
	result.insert(mtpc_updateShortMessage, Serialize_updateShortMessage);
	result.insert(mtpc_updateShortChatMessage, Serialize_updateShortChatMessage);
	result.insert(mtpc_updateShort, Serialize_updateShort);
	result.insert(mtpc_updatesCombined, Serialize_updatesCombined);
	result.insert(mtpc_updates, Serialize_updates);
	result.insert(mtpc_updateShortSentMessage, Serialize_updateShortSentMessage);
	result.insert(mtpc_photos_photos, Serialize_photos_photos);
	result.insert(mtpc_photos_photosSlice, Serialize_photos_photosSlice);
	result.insert(mtpc_photos_photo, Serialize_photos_photo);
	result.insert(mtpc_upload_file, Serialize_upload_file);
	result.insert(mtpc_upload_fileCdnRedirect, Serialize_upload_fileCdnRedirect);
	result.insert(mtpc_dcOption, Serialize_dcOption);
	result.insert(mtpc_config, Serialize_config);
	result.insert(mtpc_nearestDc, Serialize_nearestDc);
	result.insert(mtpc_help_appUpdate, Serialize_help_appUpdate);
	result.insert(mtpc_help_noAppUpdate, Serialize_help_noAppUpdate);
	result.insert(mtpc_help_inviteText, Serialize_help_inviteText);
	result.insert(mtpc_encryptedChatEmpty, Serialize_encryptedChatEmpty);
	result.insert(mtpc_encryptedChatWaiting, Serialize_encryptedChatWaiting);
	result.insert(mtpc_encryptedChatRequested, Serialize_encryptedChatRequested);
	result.insert(mtpc_encryptedChat, Serialize_encryptedChat);
	result.insert(mtpc_encryptedChatDiscarded, Serialize_encryptedChatDiscarded);
	result.insert(mtpc_inputEncryptedChat, Serialize_inputEncryptedChat);
	result.insert(mtpc_encryptedFileEmpty, Serialize_encryptedFileEmpty);
	result.insert(mtpc_encryptedFile, Serialize_encryptedFile);
	result.insert(mtpc_inputEncryptedFileEmpty, Serialize_inputEncryptedFileEmpty);
	result.insert(mtpc_inputEncryptedFileUploaded, Serialize_inputEncryptedFileUploaded);
	result.insert(mtpc_inputEncryptedFile, Serialize_inputEncryptedFile);
	result.insert(mtpc_inputEncryptedFileBigUploaded, Serialize_inputEncryptedFileBigUploaded);
	result.insert(mtpc_encryptedMessage, Serialize_encryptedMessage);
	result.insert(mtpc_encryptedMessageService, Serialize_encryptedMessageService);
	result.insert(mtpc_messages_dhConfigNotModified, Serialize_messages_dhConfigNotModified);
	result.insert(mtpc_messages_dhConfig, Serialize_messages_dhConfig);
	result.insert(mtpc_messages_sentEncryptedMessage, Serialize_messages_sentEncryptedMessage);
	result.insert(mtpc_messages_sentEncryptedFile, Serialize_messages_sentEncryptedFile);
	result.insert(mtpc_inputDocumentEmpty, Serialize_inputDocumentEmpty);
	result.insert(mtpc_inputDocument, Serialize_inputDocument);
	result.insert(mtpc_documentEmpty, Serialize_documentEmpty);
	result.insert(mtpc_document, Serialize_document);
	result.insert(mtpc_help_support, Serialize_help_support);
	result.insert(mtpc_notifyPeer, Serialize_notifyPeer);
	result.insert(mtpc_notifyUsers, Serialize_notifyUsers);
	result.insert(mtpc_notifyChats, Serialize_notifyChats);
	result.insert(mtpc_notifyAll, Serialize_notifyAll);
	result.insert(mtpc_sendMessageTypingAction, Serialize_sendMessageTypingAction);
	result.insert(mtpc_sendMessageCancelAction, Serialize_sendMessageCancelAction);
	result.insert(mtpc_sendMessageRecordVideoAction, Serialize_sendMessageRecordVideoAction);
	result.insert(mtpc_sendMessageUploadVideoAction, Serialize_sendMessageUploadVideoAction);
	result.insert(mtpc_sendMessageRecordAudioAction, Serialize_sendMessageRecordAudioAction);
	result.insert(mtpc_sendMessageUploadAudioAction, Serialize_sendMessageUploadAudioAction);
	result.insert(mtpc_sendMessageUploadPhotoAction, Serialize_sendMessageUploadPhotoAction);
	result.insert(mtpc_sendMessageUploadDocumentAction, Serialize_sendMessageUploadDocumentAction);
	result.insert(mtpc_sendMessageGeoLocationAction, Serialize_sendMessageGeoLocationAction);
	result.insert(mtpc_sendMessageChooseContactAction, Serialize_sendMessageChooseContactAction);
	result.insert(mtpc_sendMessageGamePlayAction, Serialize_sendMessageGamePlayAction);
	result.insert(mtpc_sendMessageRecordRoundAction, Serialize_sendMessageRecordRoundAction);
	result.insert(mtpc_sendMessageUploadRoundAction, Serialize_sendMessageUploadRoundAction);
	result.insert(mtpc_contacts_found, Serialize_contacts_found);
	result.insert(mtpc_inputPrivacyKeyStatusTimestamp, Serialize_inputPrivacyKeyStatusTimestamp);
	result.insert(mtpc_inputPrivacyKeyChatInvite, Serialize_inputPrivacyKeyChatInvite);
	result.insert(mtpc_inputPrivacyKeyPhoneCall, Serialize_inputPrivacyKeyPhoneCall);
	result.insert(mtpc_privacyKeyStatusTimestamp, Serialize_privacyKeyStatusTimestamp);
	result.insert(mtpc_privacyKeyChatInvite, Serialize_privacyKeyChatInvite);
	result.insert(mtpc_privacyKeyPhoneCall, Serialize_privacyKeyPhoneCall);
	result.insert(mtpc_inputPrivacyValueAllowContacts, Serialize_inputPrivacyValueAllowContacts);
	result.insert(mtpc_inputPrivacyValueAllowAll, Serialize_inputPrivacyValueAllowAll);
	result.insert(mtpc_inputPrivacyValueAllowUsers, Serialize_inputPrivacyValueAllowUsers);
	result.insert(mtpc_inputPrivacyValueDisallowContacts, Serialize_inputPrivacyValueDisallowContacts);
	result.insert(mtpc_inputPrivacyValueDisallowAll, Serialize_inputPrivacyValueDisallowAll);
	result.insert(mtpc_inputPrivacyValueDisallowUsers, Serialize_inputPrivacyValueDisallowUsers);
	result.insert(mtpc_privacyValueAllowContacts, Serialize_privacyValueAllowContacts);
	result.insert(mtpc_privacyValueAllowAll, Serialize_privacyValueAllowAll);
	result.insert(mtpc_privacyValueAllowUsers, Serialize_privacyValueAllowUsers);
	result.insert(mtpc_privacyValueDisallowContacts, Serialize_privacyValueDisallowContacts);
	result.insert(mtpc_privacyValueDisallowAll, Serialize_privacyValueDisallowAll);
	result.insert(mtpc_privacyValueDisallowUsers, Serialize_privacyValueDisallowUsers);
	result.insert(mtpc_account_privacyRules, Serialize_account_privacyRules);
	result.insert(mtpc_accountDaysTTL, Serialize_accountDaysTTL);
	result.insert(mtpc_documentAttributeImageSize, Serialize_documentAttributeImageSize);
	result.insert(mtpc_documentAttributeAnimated, Serialize_documentAttributeAnimated);
	result.insert(mtpc_documentAttributeSticker, Serialize_documentAttributeSticker);
	result.insert(mtpc_documentAttributeVideo, Serialize_documentAttributeVideo);
	result.insert(mtpc_documentAttributeAudio, Serialize_documentAttributeAudio);
	result.insert(mtpc_documentAttributeFilename, Serialize_documentAttributeFilename);
	result.insert(mtpc_documentAttributeHasStickers, Serialize_documentAttributeHasStickers);
	result.insert(mtpc_messages_stickersNotModified, Serialize_messages_stickersNotModified);
	result.insert(mtpc_messages_stickers, Serialize_messages_stickers);
	result.insert(mtpc_stickerPack, Serialize_stickerPack);
	result.insert(mtpc_messages_allStickersNotModified, Serialize_messages_allStickersNotModified);
	result.insert(mtpc_messages_allStickers, Serialize_messages_allStickers);
	result.insert(mtpc_disabledFeature, Serialize_disabledFeature);
	result.insert(mtpc_messages_affectedMessages, Serialize_messages_affectedMessages);
	result.insert(mtpc_contactLinkUnknown, Serialize_contactLinkUnknown);
	result.insert(mtpc_contactLinkNone, Serialize_contactLinkNone);
	result.insert(mtpc_contactLinkHasPhone, Serialize_contactLinkHasPhone);
	result.insert(mtpc_contactLinkContact, Serialize_contactLinkContact);
	result.insert(mtpc_webPageEmpty, Serialize_webPageEmpty);
	result.insert(mtpc_webPagePending, Serialize_webPagePending);
	result.insert(mtpc_webPage, Serialize_webPage);
	result.insert(mtpc_webPageNotModified, Serialize_webPageNotModified);
	result.insert(mtpc_authorization, Serialize_authorization);
	result.insert(mtpc_account_authorizations, Serialize_account_authorizations);
	result.insert(mtpc_account_noPassword, Serialize_account_noPassword);
	result.insert(mtpc_account_password, Serialize_account_password);
	result.insert(mtpc_account_passwordSettings, Serialize_account_passwordSettings);
	result.insert(mtpc_account_passwordInputSettings, Serialize_account_passwordInputSettings);
	result.insert(mtpc_auth_passwordRecovery, Serialize_auth_passwordRecovery);
	result.insert(mtpc_receivedNotifyMessage, Serialize_receivedNotifyMessage);
	result.insert(mtpc_chatInviteEmpty, Serialize_chatInviteEmpty);
	result.insert(mtpc_chatInviteExported, Serialize_chatInviteExported);
	result.insert(mtpc_chatInviteAlready, Serialize_chatInviteAlready);
	result.insert(mtpc_chatInvite, Serialize_chatInvite);
	result.insert(mtpc_inputStickerSetEmpty, Serialize_inputStickerSetEmpty);
	result.insert(mtpc_inputStickerSetID, Serialize_inputStickerSetID);
	result.insert(mtpc_inputStickerSetShortName, Serialize_inputStickerSetShortName);
	result.insert(mtpc_stickerSet, Serialize_stickerSet);
	result.insert(mtpc_messages_stickerSet, Serialize_messages_stickerSet);
	result.insert(mtpc_botCommand, Serialize_botCommand);
	result.insert(mtpc_botInfo, Serialize_botInfo);
	result.insert(mtpc_keyboardButton, Serialize_keyboardButton);
	result.insert(mtpc_keyboardButtonUrl, Serialize_keyboardButtonUrl);
	result.insert(mtpc_keyboardButtonCallback, Serialize_keyboardButtonCallback);
	result.insert(mtpc_keyboardButtonRequestPhone, Serialize_keyboardButtonRequestPhone);
	result.insert(mtpc_keyboardButtonRequestGeoLocation, Serialize_keyboardButtonRequestGeoLocation);
	result.insert(mtpc_keyboardButtonSwitchInline, Serialize_keyboardButtonSwitchInline);
	result.insert(mtpc_keyboardButtonGame, Serialize_keyboardButtonGame);
	result.insert(mtpc_keyboardButtonBuy, Serialize_keyboardButtonBuy);
	result.insert(mtpc_keyboardButtonRow, Serialize_keyboardButtonRow);
	result.insert(mtpc_replyKeyboardHide, Serialize_replyKeyboardHide);
	result.insert(mtpc_replyKeyboardForceReply, Serialize_replyKeyboardForceReply);
	result.insert(mtpc_replyKeyboardMarkup, Serialize_replyKeyboardMarkup);
	result.insert(mtpc_replyInlineMarkup, Serialize_replyInlineMarkup);
	result.insert(mtpc_messageEntityUnknown, Serialize_messageEntityUnknown);
	result.insert(mtpc_messageEntityMention, Serialize_messageEntityMention);
	result.insert(mtpc_messageEntityHashtag, Serialize_messageEntityHashtag);
	result.insert(mtpc_messageEntityBotCommand, Serialize_messageEntityBotCommand);
	result.insert(mtpc_messageEntityUrl, Serialize_messageEntityUrl);
	result.insert(mtpc_messageEntityEmail, Serialize_messageEntityEmail);
	result.insert(mtpc_messageEntityBold, Serialize_messageEntityBold);
	result.insert(mtpc_messageEntityItalic, Serialize_messageEntityItalic);
	result.insert(mtpc_messageEntityCode, Serialize_messageEntityCode);
	result.insert(mtpc_messageEntityPre, Serialize_messageEntityPre);
	result.insert(mtpc_messageEntityTextUrl, Serialize_messageEntityTextUrl);
	result.insert(mtpc_messageEntityMentionName, Serialize_messageEntityMentionName);
	result.insert(mtpc_inputMessageEntityMentionName, Serialize_inputMessageEntityMentionName);
	result.insert(mtpc_inputChannelEmpty, Serialize_inputChannelEmpty);
	result.insert(mtpc_inputChannel, Serialize_inputChannel);
	result.insert(mtpc_contacts_resolvedPeer, Serialize_contacts_resolvedPeer);
	result.insert(mtpc_messageRange, Serialize_messageRange);
	result.insert(mtpc_updates_channelDifferenceEmpty, Serialize_updates_channelDifferenceEmpty);
	result.insert(mtpc_updates_channelDifferenceTooLong, Serialize_updates_channelDifferenceTooLong);
	result.insert(mtpc_updates_channelDifference, Serialize_updates_channelDifference);
	result.insert(mtpc_channelMessagesFilterEmpty, Serialize_channelMessagesFilterEmpty);
	result.insert(mtpc_channelMessagesFilter, Serialize_channelMessagesFilter);
	result.insert(mtpc_channelParticipant, Serialize_channelParticipant);
	result.insert(mtpc_channelParticipantSelf, Serialize_channelParticipantSelf);
	result.insert(mtpc_channelParticipantModerator, Serialize_channelParticipantModerator);
	result.insert(mtpc_channelParticipantEditor, Serialize_channelParticipantEditor);
	result.insert(mtpc_channelParticipantKicked, Serialize_channelParticipantKicked);
	result.insert(mtpc_channelParticipantCreator, Serialize_channelParticipantCreator);
	result.insert(mtpc_channelParticipantsRecent, Serialize_channelParticipantsRecent);
	result.insert(mtpc_channelParticipantsAdmins, Serialize_channelParticipantsAdmins);
	result.insert(mtpc_channelParticipantsKicked, Serialize_channelParticipantsKicked);
	result.insert(mtpc_channelParticipantsBots, Serialize_channelParticipantsBots);
	result.insert(mtpc_channelRoleEmpty, Serialize_channelRoleEmpty);
	result.insert(mtpc_channelRoleModerator, Serialize_channelRoleModerator);
	result.insert(mtpc_channelRoleEditor, Serialize_channelRoleEditor);
	result.insert(mtpc_channels_channelParticipants, Serialize_channels_channelParticipants);
	result.insert(mtpc_channels_channelParticipant, Serialize_channels_channelParticipant);
	result.insert(mtpc_help_termsOfService, Serialize_help_termsOfService);
	result.insert(mtpc_foundGif, Serialize_foundGif);
	result.insert(mtpc_foundGifCached, Serialize_foundGifCached);
	result.insert(mtpc_messages_foundGifs, Serialize_messages_foundGifs);
	result.insert(mtpc_messages_savedGifsNotModified, Serialize_messages_savedGifsNotModified);
	result.insert(mtpc_messages_savedGifs, Serialize_messages_savedGifs);
	result.insert(mtpc_inputBotInlineMessageMediaAuto, Serialize_inputBotInlineMessageMediaAuto);
	result.insert(mtpc_inputBotInlineMessageText, Serialize_inputBotInlineMessageText);
	result.insert(mtpc_inputBotInlineMessageMediaGeo, Serialize_inputBotInlineMessageMediaGeo);
	result.insert(mtpc_inputBotInlineMessageMediaVenue, Serialize_inputBotInlineMessageMediaVenue);
	result.insert(mtpc_inputBotInlineMessageMediaContact, Serialize_inputBotInlineMessageMediaContact);
	result.insert(mtpc_inputBotInlineMessageGame, Serialize_inputBotInlineMessageGame);
	result.insert(mtpc_inputBotInlineResult, Serialize_inputBotInlineResult);
	result.insert(mtpc_inputBotInlineResultPhoto, Serialize_inputBotInlineResultPhoto);
	result.insert(mtpc_inputBotInlineResultDocument, Serialize_inputBotInlineResultDocument);
	result.insert(mtpc_inputBotInlineResultGame, Serialize_inputBotInlineResultGame);
	result.insert(mtpc_botInlineMessageMediaAuto, Serialize_botInlineMessageMediaAuto);
	result.insert(mtpc_botInlineMessageText, Serialize_botInlineMessageText);
	result.insert(mtpc_botInlineMessageMediaGeo, Serialize_botInlineMessageMediaGeo);
	result.insert(mtpc_botInlineMessageMediaVenue, Serialize_botInlineMessageMediaVenue);
	result.insert(mtpc_botInlineMessageMediaContact, Serialize_botInlineMessageMediaContact);
	result.insert(mtpc_botInlineResult, Serialize_botInlineResult);
	result.insert(mtpc_botInlineMediaResult, Serialize_botInlineMediaResult);
	result.insert(mtpc_messages_botResults, Serialize_messages_botResults);
	result.insert(mtpc_exportedMessageLink, Serialize_exportedMessageLink);
	result.insert(mtpc_messageFwdHeader, Serialize_messageFwdHeader);
	result.insert(mtpc_auth_codeTypeSms, Serialize_auth_codeTypeSms);
	result.insert(mtpc_auth_codeTypeCall, Serialize_auth_codeTypeCall);
	result.insert(mtpc_auth_codeTypeFlashCall, Serialize_auth_codeTypeFlashCall);
	result.insert(mtpc_auth_sentCodeTypeApp, Serialize_auth_sentCodeTypeApp);
	result.insert(mtpc_auth_sentCodeTypeSms, Serialize_auth_sentCodeTypeSms);
	result.insert(mtpc_auth_sentCodeTypeCall, Serialize_auth_sentCodeTypeCall);
	result.insert(mtpc_auth_sentCodeTypeFlashCall, Serialize_auth_sentCodeTypeFlashCall);
	result.insert(mtpc_messages_botCallbackAnswer, Serialize_messages_botCallbackAnswer);
	result.insert(mtpc_messages_messageEditData, Serialize_messages_messageEditData);
	result.insert(mtpc_inputBotInlineMessageID, Serialize_inputBotInlineMessageID);
	result.insert(mtpc_inlineBotSwitchPM, Serialize_inlineBotSwitchPM);
	result.insert(mtpc_messages_peerDialogs, Serialize_messages_peerDialogs);
	result.insert(mtpc_topPeer, Serialize_topPeer);
	result.insert(mtpc_topPeerCategoryBotsPM, Serialize_topPeerCategoryBotsPM);
	result.insert(mtpc_topPeerCategoryBotsInline, Serialize_topPeerCategoryBotsInline);
	result.insert(mtpc_topPeerCategoryCorrespondents, Serialize_topPeerCategoryCorrespondents);
	result.insert(mtpc_topPeerCategoryGroups, Serialize_topPeerCategoryGroups);
	result.insert(mtpc_topPeerCategoryChannels, Serialize_topPeerCategoryChannels);
	result.insert(mtpc_topPeerCategoryPeers, Serialize_topPeerCategoryPeers);
	result.insert(mtpc_contacts_topPeersNotModified, Serialize_contacts_topPeersNotModified);
	result.insert(mtpc_contacts_topPeers, Serialize_contacts_topPeers);
	result.insert(mtpc_draftMessageEmpty, Serialize_draftMessageEmpty);
	result.insert(mtpc_draftMessage, Serialize_draftMessage);
	result.insert(mtpc_messages_featuredStickersNotModified, Serialize_messages_featuredStickersNotModified);
	result.insert(mtpc_messages_featuredStickers, Serialize_messages_featuredStickers);
	result.insert(mtpc_messages_recentStickersNotModified, Serialize_messages_recentStickersNotModified);
	result.insert(mtpc_messages_recentStickers, Serialize_messages_recentStickers);
	result.insert(mtpc_messages_archivedStickers, Serialize_messages_archivedStickers);
	result.insert(mtpc_messages_stickerSetInstallResultSuccess, Serialize_messages_stickerSetInstallResultSuccess);
	result.insert(mtpc_messages_stickerSetInstallResultArchive, Serialize_messages_stickerSetInstallResultArchive);
	result.insert(mtpc_stickerSetCovered, Serialize_stickerSetCovered);
	result.insert(mtpc_stickerSetMultiCovered, Serialize_stickerSetMultiCovered);
	result.insert(mtpc_maskCoords, Serialize_maskCoords);
	result.insert(mtpc_inputStickeredMediaPhoto, Serialize_inputStickeredMediaPhoto);
	result.insert(mtpc_inputStickeredMediaDocument, Serialize_inputStickeredMediaDocument);
	result.insert(mtpc_game, Serialize_game);
	result.insert(mtpc_inputGameID, Serialize_inputGameID);
	result.insert(mtpc_inputGameShortName, Serialize_inputGameShortName);
	result.insert(mtpc_highScore, Serialize_highScore);
	result.insert(mtpc_messages_highScores, Serialize_messages_highScores);
	result.insert(mtpc_textEmpty, Serialize_textEmpty);
	result.insert(mtpc_textPlain, Serialize_textPlain);
	result.insert(mtpc_textBold, Serialize_textBold);
	result.insert(mtpc_textItalic, Serialize_textItalic);
	result.insert(mtpc_textUnderline, Serialize_textUnderline);
	result.insert(mtpc_textStrike, Serialize_textStrike);
	result.insert(mtpc_textFixed, Serialize_textFixed);
	result.insert(mtpc_textUrl, Serialize_textUrl);
	result.insert(mtpc_textEmail, Serialize_textEmail);
	result.insert(mtpc_textConcat, Serialize_textConcat);
	result.insert(mtpc_pageBlockUnsupported, Serialize_pageBlockUnsupported);
	result.insert(mtpc_pageBlockTitle, Serialize_pageBlockTitle);
	result.insert(mtpc_pageBlockSubtitle, Serialize_pageBlockSubtitle);
	result.insert(mtpc_pageBlockAuthorDate, Serialize_pageBlockAuthorDate);
	result.insert(mtpc_pageBlockHeader, Serialize_pageBlockHeader);
	result.insert(mtpc_pageBlockSubheader, Serialize_pageBlockSubheader);
	result.insert(mtpc_pageBlockParagraph, Serialize_pageBlockParagraph);
	result.insert(mtpc_pageBlockPreformatted, Serialize_pageBlockPreformatted);
	result.insert(mtpc_pageBlockFooter, Serialize_pageBlockFooter);
	result.insert(mtpc_pageBlockDivider, Serialize_pageBlockDivider);
	result.insert(mtpc_pageBlockAnchor, Serialize_pageBlockAnchor);
	result.insert(mtpc_pageBlockList, Serialize_pageBlockList);
	result.insert(mtpc_pageBlockBlockquote, Serialize_pageBlockBlockquote);
	result.insert(mtpc_pageBlockPullquote, Serialize_pageBlockPullquote);
	result.insert(mtpc_pageBlockPhoto, Serialize_pageBlockPhoto);
	result.insert(mtpc_pageBlockVideo, Serialize_pageBlockVideo);
	result.insert(mtpc_pageBlockCover, Serialize_pageBlockCover);
	result.insert(mtpc_pageBlockEmbed, Serialize_pageBlockEmbed);
	result.insert(mtpc_pageBlockEmbedPost, Serialize_pageBlockEmbedPost);
	result.insert(mtpc_pageBlockCollage, Serialize_pageBlockCollage);
	result.insert(mtpc_pageBlockSlideshow, Serialize_pageBlockSlideshow);
	result.insert(mtpc_pageBlockChannel, Serialize_pageBlockChannel);
	result.insert(mtpc_pagePart, Serialize_pagePart);
	result.insert(mtpc_pageFull, Serialize_pageFull);
	result.insert(mtpc_phoneCallDiscardReasonMissed, Serialize_phoneCallDiscardReasonMissed);
	result.insert(mtpc_phoneCallDiscardReasonDisconnect, Serialize_phoneCallDiscardReasonDisconnect);
	result.insert(mtpc_phoneCallDiscardReasonHangup, Serialize_phoneCallDiscardReasonHangup);
	result.insert(mtpc_phoneCallDiscardReasonBusy, Serialize_phoneCallDiscardReasonBusy);
	result.insert(mtpc_dataJSON, Serialize_dataJSON);
	result.insert(mtpc_labeledPrice, Serialize_labeledPrice);
	result.insert(mtpc_invoice, Serialize_invoice);
	result.insert(mtpc_paymentCharge, Serialize_paymentCharge);
	result.insert(mtpc_postAddress, Serialize_postAddress);
	result.insert(mtpc_paymentRequestedInfo, Serialize_paymentRequestedInfo);
	result.insert(mtpc_paymentSavedCredentialsCard, Serialize_paymentSavedCredentialsCard);
	result.insert(mtpc_webDocument, Serialize_webDocument);
	result.insert(mtpc_inputWebDocument, Serialize_inputWebDocument);
	result.insert(mtpc_inputWebFileLocation, Serialize_inputWebFileLocation);
	result.insert(mtpc_upload_webFile, Serialize_upload_webFile);
	result.insert(mtpc_payments_paymentForm, Serialize_payments_paymentForm);
	result.insert(mtpc_payments_validatedRequestedInfo, Serialize_payments_validatedRequestedInfo);
	result.insert(mtpc_payments_paymentResult, Serialize_payments_paymentResult);
	result.insert(mtpc_payments_paymentVerficationNeeded, Serialize_payments_paymentVerficationNeeded);
	result.insert(mtpc_payments_paymentReceipt, Serialize_payments_paymentReceipt);
	result.insert(mtpc_payments_savedInfo, Serialize_payments_savedInfo);
	result.insert(mtpc_inputPaymentCredentialsSaved, Serialize_inputPaymentCredentialsSaved);
	result.insert(mtpc_inputPaymentCredentials, Serialize_inputPaymentCredentials);
	result.insert(mtpc_account_tmpPassword, Serialize_account_tmpPassword);
	result.insert(mtpc_shippingOption, Serialize_shippingOption);
	result.insert(mtpc_inputPhoneCall, Serialize_inputPhoneCall);
	result.insert(mtpc_phoneCallEmpty, Serialize_phoneCallEmpty);
	result.insert(mtpc_phoneCallWaiting, Serialize_phoneCallWaiting);
	result.insert(mtpc_phoneCallRequested, Serialize_phoneCallRequested);
	result.insert(mtpc_phoneCallAccepted, Serialize_phoneCallAccepted);
	result.insert(mtpc_phoneCall, Serialize_phoneCall);
	result.insert(mtpc_phoneCallDiscarded, Serialize_phoneCallDiscarded);
	result.insert(mtpc_phoneConnection, Serialize_phoneConnection);
	result.insert(mtpc_phoneCallProtocol, Serialize_phoneCallProtocol);
	result.insert(mtpc_phone_phoneCall, Serialize_phone_phoneCall);
	result.insert(mtpc_upload_cdnFileReuploadNeeded, Serialize_upload_cdnFileReuploadNeeded);
	result.insert(mtpc_upload_cdnFile, Serialize_upload_cdnFile);
	result.insert(mtpc_cdnPublicKey, Serialize_cdnPublicKey);
	result.insert(mtpc_cdnConfig, Serialize_cdnConfig);

	result.insert(mtpc_req_pq, Serialize_req_pq);
	result.insert(mtpc_req_DH_params, Serialize_req_DH_params);
	result.insert(mtpc_set_client_DH_params, Serialize_set_client_DH_params);
	result.insert(mtpc_destroy_auth_key, Serialize_destroy_auth_key);
	result.insert(mtpc_rpc_drop_answer, Serialize_rpc_drop_answer);
	result.insert(mtpc_get_future_salts, Serialize_get_future_salts);
	result.insert(mtpc_ping, Serialize_ping);
	result.insert(mtpc_ping_delay_disconnect, Serialize_ping_delay_disconnect);
	result.insert(mtpc_destroy_session, Serialize_destroy_session);
	result.insert(mtpc_contest_saveDeveloperInfo, Serialize_contest_saveDeveloperInfo);
	result.insert(mtpc_auth_logOut, Serialize_auth_logOut);
	result.insert(mtpc_auth_resetAuthorizations, Serialize_auth_resetAuthorizations);
	result.insert(mtpc_auth_sendInvites, Serialize_auth_sendInvites);
	result.insert(mtpc_auth_bindTempAuthKey, Serialize_auth_bindTempAuthKey);
	result.insert(mtpc_auth_cancelCode, Serialize_auth_cancelCode);
	result.insert(mtpc_auth_dropTempAuthKeys, Serialize_auth_dropTempAuthKeys);
	result.insert(mtpc_account_registerDevice, Serialize_account_registerDevice);
	result.insert(mtpc_account_unregisterDevice, Serialize_account_unregisterDevice);
	result.insert(mtpc_account_updateNotifySettings, Serialize_account_updateNotifySettings);
	result.insert(mtpc_account_resetNotifySettings, Serialize_account_resetNotifySettings);
	result.insert(mtpc_account_updateStatus, Serialize_account_updateStatus);
	result.insert(mtpc_account_reportPeer, Serialize_account_reportPeer);
	result.insert(mtpc_account_checkUsername, Serialize_account_checkUsername);
	result.insert(mtpc_account_deleteAccount, Serialize_account_deleteAccount);
	result.insert(mtpc_account_setAccountTTL, Serialize_account_setAccountTTL);
	result.insert(mtpc_account_updateDeviceLocked, Serialize_account_updateDeviceLocked);
	result.insert(mtpc_account_resetAuthorization, Serialize_account_resetAuthorization);
	result.insert(mtpc_account_updatePasswordSettings, Serialize_account_updatePasswordSettings);
	result.insert(mtpc_account_confirmPhone, Serialize_account_confirmPhone);
	result.insert(mtpc_contacts_deleteContacts, Serialize_contacts_deleteContacts);
	result.insert(mtpc_contacts_block, Serialize_contacts_block);
	result.insert(mtpc_contacts_unblock, Serialize_contacts_unblock);
	result.insert(mtpc_contacts_resetTopPeerRating, Serialize_contacts_resetTopPeerRating);
	result.insert(mtpc_messages_setTyping, Serialize_messages_setTyping);
	result.insert(mtpc_messages_reportSpam, Serialize_messages_reportSpam);
	result.insert(mtpc_messages_hideReportSpam, Serialize_messages_hideReportSpam);
	result.insert(mtpc_messages_discardEncryption, Serialize_messages_discardEncryption);
	result.insert(mtpc_messages_setEncryptedTyping, Serialize_messages_setEncryptedTyping);
	result.insert(mtpc_messages_readEncryptedHistory, Serialize_messages_readEncryptedHistory);
	result.insert(mtpc_messages_reportEncryptedSpam, Serialize_messages_reportEncryptedSpam);
	result.insert(mtpc_messages_uninstallStickerSet, Serialize_messages_uninstallStickerSet);
	result.insert(mtpc_messages_editChatAdmin, Serialize_messages_editChatAdmin);
	result.insert(mtpc_messages_reorderStickerSets, Serialize_messages_reorderStickerSets);
	result.insert(mtpc_messages_saveGif, Serialize_messages_saveGif);
	result.insert(mtpc_messages_setInlineBotResults, Serialize_messages_setInlineBotResults);
	result.insert(mtpc_messages_editInlineBotMessage, Serialize_messages_editInlineBotMessage);
	result.insert(mtpc_messages_setBotCallbackAnswer, Serialize_messages_setBotCallbackAnswer);
	result.insert(mtpc_messages_saveDraft, Serialize_messages_saveDraft);
	result.insert(mtpc_messages_readFeaturedStickers, Serialize_messages_readFeaturedStickers);
	result.insert(mtpc_messages_saveRecentSticker, Serialize_messages_saveRecentSticker);
	result.insert(mtpc_messages_clearRecentStickers, Serialize_messages_clearRecentStickers);
	result.insert(mtpc_messages_setInlineGameScore, Serialize_messages_setInlineGameScore);
	result.insert(mtpc_messages_toggleDialogPin, Serialize_messages_toggleDialogPin);
	result.insert(mtpc_messages_reorderPinnedDialogs, Serialize_messages_reorderPinnedDialogs);
	result.insert(mtpc_messages_setBotShippingResults, Serialize_messages_setBotShippingResults);
	result.insert(mtpc_messages_setBotPrecheckoutResults, Serialize_messages_setBotPrecheckoutResults);
	result.insert(mtpc_upload_saveFilePart, Serialize_upload_saveFilePart);
	result.insert(mtpc_upload_saveBigFilePart, Serialize_upload_saveBigFilePart);
	result.insert(mtpc_upload_reuploadCdnFile, Serialize_upload_reuploadCdnFile);
	result.insert(mtpc_help_saveAppLog, Serialize_help_saveAppLog);
	result.insert(mtpc_help_setBotUpdatesStatus, Serialize_help_setBotUpdatesStatus);
	result.insert(mtpc_channels_readHistory, Serialize_channels_readHistory);
	result.insert(mtpc_channels_reportSpam, Serialize_channels_reportSpam);
	result.insert(mtpc_channels_editAbout, Serialize_channels_editAbout);
	result.insert(mtpc_channels_checkUsername, Serialize_channels_checkUsername);
	result.insert(mtpc_channels_updateUsername, Serialize_channels_updateUsername);
	result.insert(mtpc_bots_answerWebhookJSONQuery, Serialize_bots_answerWebhookJSONQuery);
	result.insert(mtpc_payments_clearSavedInfo, Serialize_payments_clearSavedInfo);
	result.insert(mtpc_phone_receivedCall, Serialize_phone_receivedCall);
	result.insert(mtpc_phone_saveCallDebug, Serialize_phone_saveCallDebug);
	result.insert(mtpc_invokeAfterMsg, Serialize_invokeAfterMsg);
	result.insert(mtpc_invokeAfterMsgs, Serialize_invokeAfterMsgs);
	result.insert(mtpc_initConnection, Serialize_initConnection);
	result.insert(mtpc_invokeWithLayer, Serialize_invokeWithLayer);
	result.insert(mtpc_invokeWithoutUpdates, Serialize_invokeWithoutUpdates);
	result.insert(mtpc_auth_checkPhone, Serialize_auth_checkPhone);
	result.insert(mtpc_auth_sendCode, Serialize_auth_sendCode);
	result.insert(mtpc_auth_resendCode, Serialize_auth_resendCode);
	result.insert(mtpc_account_sendChangePhoneCode, Serialize_account_sendChangePhoneCode);
	result.insert(mtpc_account_sendConfirmPhoneCode, Serialize_account_sendConfirmPhoneCode);
	result.insert(mtpc_auth_signUp, Serialize_auth_signUp);
	result.insert(mtpc_auth_signIn, Serialize_auth_signIn);
	result.insert(mtpc_auth_importAuthorization, Serialize_auth_importAuthorization);
	result.insert(mtpc_auth_importBotAuthorization, Serialize_auth_importBotAuthorization);
	result.insert(mtpc_auth_checkPassword, Serialize_auth_checkPassword);
	result.insert(mtpc_auth_recoverPassword, Serialize_auth_recoverPassword);
	result.insert(mtpc_auth_exportAuthorization, Serialize_auth_exportAuthorization);
	result.insert(mtpc_auth_requestPasswordRecovery, Serialize_auth_requestPasswordRecovery);
	result.insert(mtpc_account_getNotifySettings, Serialize_account_getNotifySettings);
	result.insert(mtpc_account_updateProfile, Serialize_account_updateProfile);
	result.insert(mtpc_account_updateUsername, Serialize_account_updateUsername);
	result.insert(mtpc_account_changePhone, Serialize_account_changePhone);
	result.insert(mtpc_contacts_importCard, Serialize_contacts_importCard);
	result.insert(mtpc_account_getWallPapers, Serialize_account_getWallPapers);
	result.insert(mtpc_account_getPrivacy, Serialize_account_getPrivacy);
	result.insert(mtpc_account_setPrivacy, Serialize_account_setPrivacy);
	result.insert(mtpc_account_getAccountTTL, Serialize_account_getAccountTTL);
	result.insert(mtpc_account_getAuthorizations, Serialize_account_getAuthorizations);
	result.insert(mtpc_account_getPassword, Serialize_account_getPassword);
	result.insert(mtpc_account_getPasswordSettings, Serialize_account_getPasswordSettings);
	result.insert(mtpc_account_getTmpPassword, Serialize_account_getTmpPassword);
	result.insert(mtpc_users_getUsers, Serialize_users_getUsers);
	result.insert(mtpc_users_getFullUser, Serialize_users_getFullUser);
	result.insert(mtpc_contacts_getStatuses, Serialize_contacts_getStatuses);
	result.insert(mtpc_contacts_getContacts, Serialize_contacts_getContacts);
	result.insert(mtpc_contacts_importContacts, Serialize_contacts_importContacts);
	result.insert(mtpc_contacts_deleteContact, Serialize_contacts_deleteContact);
	result.insert(mtpc_contacts_getBlocked, Serialize_contacts_getBlocked);
	result.insert(mtpc_contacts_exportCard, Serialize_contacts_exportCard);
	result.insert(mtpc_messages_getMessagesViews, Serialize_messages_getMessagesViews);
	result.insert(mtpc_contacts_search, Serialize_contacts_search);
	result.insert(mtpc_contacts_resolveUsername, Serialize_contacts_resolveUsername);
	result.insert(mtpc_contacts_getTopPeers, Serialize_contacts_getTopPeers);
	result.insert(mtpc_messages_getMessages, Serialize_messages_getMessages);
	result.insert(mtpc_messages_getHistory, Serialize_messages_getHistory);
	result.insert(mtpc_messages_search, Serialize_messages_search);
	result.insert(mtpc_messages_searchGlobal, Serialize_messages_searchGlobal);
	result.insert(mtpc_channels_getMessages, Serialize_channels_getMessages);
	result.insert(mtpc_messages_getDialogs, Serialize_messages_getDialogs);
	result.insert(mtpc_messages_readHistory, Serialize_messages_readHistory);
	result.insert(mtpc_messages_deleteMessages, Serialize_messages_deleteMessages);
	result.insert(mtpc_messages_readMessageContents, Serialize_messages_readMessageContents);
	result.insert(mtpc_channels_deleteMessages, Serialize_channels_deleteMessages);
	result.insert(mtpc_messages_deleteHistory, Serialize_messages_deleteHistory);
	result.insert(mtpc_channels_deleteUserHistory, Serialize_channels_deleteUserHistory);
	result.insert(mtpc_messages_receivedMessages, Serialize_messages_receivedMessages);
	result.insert(mtpc_messages_sendMessage, Serialize_messages_sendMessage);
	result.insert(mtpc_messages_sendMedia, Serialize_messages_sendMedia);
	result.insert(mtpc_messages_forwardMessages, Serialize_messages_forwardMessages);
	result.insert(mtpc_messages_editChatTitle, Serialize_messages_editChatTitle);
	result.insert(mtpc_messages_editChatPhoto, Serialize_messages_editChatPhoto);
	result.insert(mtpc_messages_addChatUser, Serialize_messages_addChatUser);
	result.insert(mtpc_messages_deleteChatUser, Serialize_messages_deleteChatUser);
	result.insert(mtpc_messages_createChat, Serialize_messages_createChat);
	result.insert(mtpc_messages_forwardMessage, Serialize_messages_forwardMessage);
	result.insert(mtpc_messages_importChatInvite, Serialize_messages_importChatInvite);
	result.insert(mtpc_messages_startBot, Serialize_messages_startBot);
	result.insert(mtpc_messages_toggleChatAdmins, Serialize_messages_toggleChatAdmins);
	result.insert(mtpc_messages_migrateChat, Serialize_messages_migrateChat);
	result.insert(mtpc_messages_sendInlineBotResult, Serialize_messages_sendInlineBotResult);
	result.insert(mtpc_messages_editMessage, Serialize_messages_editMessage);
	result.insert(mtpc_messages_getAllDrafts, Serialize_messages_getAllDrafts);
	result.insert(mtpc_messages_setGameScore, Serialize_messages_setGameScore);
	result.insert(mtpc_help_getAppChangelog, Serialize_help_getAppChangelog);
	result.insert(mtpc_channels_createChannel, Serialize_channels_createChannel);
	result.insert(mtpc_channels_editAdmin, Serialize_channels_editAdmin);
	result.insert(mtpc_channels_editTitle, Serialize_channels_editTitle);
	result.insert(mtpc_channels_editPhoto, Serialize_channels_editPhoto);
	result.insert(mtpc_channels_joinChannel, Serialize_channels_joinChannel);
	result.insert(mtpc_channels_leaveChannel, Serialize_channels_leaveChannel);
	result.insert(mtpc_channels_inviteToChannel, Serialize_channels_inviteToChannel);
	result.insert(mtpc_channels_kickFromChannel, Serialize_channels_kickFromChannel);
	result.insert(mtpc_channels_deleteChannel, Serialize_channels_deleteChannel);
	result.insert(mtpc_channels_toggleInvites, Serialize_channels_toggleInvites);
	result.insert(mtpc_channels_toggleSignatures, Serialize_channels_toggleSignatures);
	result.insert(mtpc_channels_updatePinnedMessage, Serialize_channels_updatePinnedMessage);
	result.insert(mtpc_phone_discardCall, Serialize_phone_discardCall);
	result.insert(mtpc_phone_setCallRating, Serialize_phone_setCallRating);
	result.insert(mtpc_messages_getPeerSettings, Serialize_messages_getPeerSettings);
	result.insert(mtpc_messages_getChats, Serialize_messages_getChats);
	result.insert(mtpc_messages_getCommonChats, Serialize_messages_getCommonChats);
	result.insert(mtpc_messages_getAllChats, Serialize_messages_getAllChats);
	result.insert(mtpc_channels_getChannels, Serialize_channels_getChannels);
	result.insert(mtpc_channels_getAdminedPublicChannels, Serialize_channels_getAdminedPublicChannels);
	result.insert(mtpc_messages_getFullChat, Serialize_messages_getFullChat);
	result.insert(mtpc_channels_getFullChannel, Serialize_channels_getFullChannel);
	result.insert(mtpc_messages_getDhConfig, Serialize_messages_getDhConfig);
	result.insert(mtpc_messages_requestEncryption, Serialize_messages_requestEncryption);
	result.insert(mtpc_messages_acceptEncryption, Serialize_messages_acceptEncryption);
	result.insert(mtpc_messages_sendEncrypted, Serialize_messages_sendEncrypted);
	result.insert(mtpc_messages_sendEncryptedFile, Serialize_messages_sendEncryptedFile);
	result.insert(mtpc_messages_sendEncryptedService, Serialize_messages_sendEncryptedService);
	result.insert(mtpc_messages_receivedQueue, Serialize_messages_receivedQueue);
	result.insert(mtpc_photos_deletePhotos, Serialize_photos_deletePhotos);
	result.insert(mtpc_messages_getAllStickers, Serialize_messages_getAllStickers);
	result.insert(mtpc_messages_getMaskStickers, Serialize_messages_getMaskStickers);
	result.insert(mtpc_messages_getWebPagePreview, Serialize_messages_getWebPagePreview);
	result.insert(mtpc_messages_exportChatInvite, Serialize_messages_exportChatInvite);
	result.insert(mtpc_channels_exportInvite, Serialize_channels_exportInvite);
	result.insert(mtpc_messages_checkChatInvite, Serialize_messages_checkChatInvite);
	result.insert(mtpc_messages_getStickerSet, Serialize_messages_getStickerSet);
	result.insert(mtpc_messages_installStickerSet, Serialize_messages_installStickerSet);
	result.insert(mtpc_messages_getDocumentByHash, Serialize_messages_getDocumentByHash);
	result.insert(mtpc_messages_searchGifs, Serialize_messages_searchGifs);
	result.insert(mtpc_messages_getSavedGifs, Serialize_messages_getSavedGifs);
	result.insert(mtpc_messages_getInlineBotResults, Serialize_messages_getInlineBotResults);
	result.insert(mtpc_messages_getMessageEditData, Serialize_messages_getMessageEditData);
	result.insert(mtpc_messages_getBotCallbackAnswer, Serialize_messages_getBotCallbackAnswer);
	result.insert(mtpc_messages_getPeerDialogs, Serialize_messages_getPeerDialogs);
	result.insert(mtpc_messages_getPinnedDialogs, Serialize_messages_getPinnedDialogs);
	result.insert(mtpc_messages_getFeaturedStickers, Serialize_messages_getFeaturedStickers);
	result.insert(mtpc_messages_getRecentStickers, Serialize_messages_getRecentStickers);
	result.insert(mtpc_messages_getArchivedStickers, Serialize_messages_getArchivedStickers);
	result.insert(mtpc_messages_getAttachedStickers, Serialize_messages_getAttachedStickers);
	result.insert(mtpc_messages_getGameHighScores, Serialize_messages_getGameHighScores);
	result.insert(mtpc_messages_getInlineGameHighScores, Serialize_messages_getInlineGameHighScores);
	result.insert(mtpc_messages_getWebPage, Serialize_messages_getWebPage);
	result.insert(mtpc_updates_getState, Serialize_updates_getState);
	result.insert(mtpc_updates_getDifference, Serialize_updates_getDifference);
	result.insert(mtpc_updates_getChannelDifference, Serialize_updates_getChannelDifference);
	result.insert(mtpc_photos_updateProfilePhoto, Serialize_photos_updateProfilePhoto);
	result.insert(mtpc_photos_uploadProfilePhoto, Serialize_photos_uploadProfilePhoto);
	result.insert(mtpc_photos_getUserPhotos, Serialize_photos_getUserPhotos);
	result.insert(mtpc_upload_getFile, Serialize_upload_getFile);
	result.insert(mtpc_upload_getWebFile, Serialize_upload_getWebFile);
	result.insert(mtpc_upload_getCdnFile, Serialize_upload_getCdnFile);
	result.insert(mtpc_help_getConfig, Serialize_help_getConfig);
	result.insert(mtpc_help_getNearestDc, Serialize_help_getNearestDc);
	result.insert(mtpc_help_getAppUpdate, Serialize_help_getAppUpdate);
	result.insert(mtpc_help_getInviteText, Serialize_help_getInviteText);
	result.insert(mtpc_help_getSupport, Serialize_help_getSupport);
	result.insert(mtpc_help_getTermsOfService, Serialize_help_getTermsOfService);
	result.insert(mtpc_help_getCdnConfig, Serialize_help_getCdnConfig);
	result.insert(mtpc_channels_getParticipants, Serialize_channels_getParticipants);
	result.insert(mtpc_channels_getParticipant, Serialize_channels_getParticipant);
	result.insert(mtpc_channels_exportMessageLink, Serialize_channels_exportMessageLink);
	result.insert(mtpc_bots_sendCustomRequest, Serialize_bots_sendCustomRequest);
	result.insert(mtpc_phone_getCallConfig, Serialize_phone_getCallConfig);
	result.insert(mtpc_payments_getPaymentForm, Serialize_payments_getPaymentForm);
	result.insert(mtpc_payments_getPaymentReceipt, Serialize_payments_getPaymentReceipt);
	result.insert(mtpc_payments_validateRequestedInfo, Serialize_payments_validateRequestedInfo);
	result.insert(mtpc_payments_sendPaymentForm, Serialize_payments_sendPaymentForm);
	result.insert(mtpc_payments_getSavedInfo, Serialize_payments_getSavedInfo);
	result.insert(mtpc_phone_requestCall, Serialize_phone_requestCall);
	result.insert(mtpc_phone_acceptCall, Serialize_phone_acceptCall);
	result.insert(mtpc_phone_confirmCall, Serialize_phone_confirmCall);

	result.insert(mtpc_rpc_result, _serialize_rpc_result);
	result.insert(mtpc_msg_container, _serialize_msg_container);
	result.insert(mtpc_core_message, _serialize_core_message);


	return result;
}

} // namespace

void mtpTextSerializeType(MTPStringLogger &to, const mtpPrime *&from, const mtpPrime *end, mtpPrime cons, uint32 level, mtpPrime vcons) {
	static auto serializers = createTextSerializers();

	QVector<mtpTypeId> types, vtypes;
	QVector<int32> stages, flags;
	types.reserve(20); vtypes.reserve(20); stages.reserve(20); flags.reserve(20);
	types.push_back(mtpTypeId(cons)); vtypes.push_back(mtpTypeId(vcons)); stages.push_back(0); flags.push_back(0);

	const mtpPrime *start = from;
	mtpTypeId type = cons, vtype = vcons;
	int32 stage = 0, flag = 0;

	while (!types.isEmpty()) {
		type = types.back();
		vtype = vtypes.back();
		stage = stages.back();
		flag = flags.back();
		if (!type) {
			if (from >= end) {
				throw Exception("from >= end");
			} else if (stage) {
				throw Exception("unknown type on stage > 0");
			}
			types.back() = type = *from;
			start = ++from;
		}

		int32 lev = level + types.size() - 1;
		auto it = serializers.constFind(type);
		if (it != serializers.cend()) {
			(*it.value())(to, stage, lev, types, vtypes, stages, flags, start, end, flag);
		} else {
			mtpTextSerializeCore(to, from, end, type, lev, vtype);
			types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back();
		}
	}
}
