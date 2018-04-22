/*
 * WARNING! All changes made in this file will be lost!
 * Created from 'scheme.tl' by 'codegen'
 *
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

template <class T> 
using TLObjectRegister = nebula::SelfRegisterFactoryManager<TLObject, uint32_t>::RegisterTemplate<T>;
#define REGISTER_TLOBJECT(T) \
static TLObjectRegister<T> g_reg_tl_obejct_##T(T::CLASS_ID)



zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::req_pq(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_req_pqauth_recoverPassword, req);
  LOG(INFO) << "req_pq - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.req_pq(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::req_DH_params(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_req_DH_paramsauth_recoverPassword, req);
  LOG(INFO) << "req_DH_params - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.req_DH_params(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::set_client_DH_params(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_set_client_DH_paramsauth_recoverPassword, req);
  LOG(INFO) << "set_client_DH_params - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.set_client_DH_params(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::destroy_auth_key(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_destroy_auth_keyauth_recoverPassword, req);
  LOG(INFO) << "destroy_auth_key - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.destroy_auth_key(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::rpc_drop_answer(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_rpc_drop_answerauth_recoverPassword, req);
  LOG(INFO) << "rpc_drop_answer - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.rpc_drop_answer(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::get_future_salts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_get_future_saltsauth_recoverPassword, req);
  LOG(INFO) << "get_future_salts - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.get_future_salts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::ping(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_pingauth_recoverPassword, req);
  LOG(INFO) << "ping - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.ping(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::ping_delay_disconnect(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_ping_delay_disconnectauth_recoverPassword, req);
  LOG(INFO) << "ping_delay_disconnect - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.ping_delay_disconnect(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::destroy_session(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_destroy_sessionauth_recoverPassword, req);
  LOG(INFO) << "destroy_session - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.destroy_session(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contest_saveDeveloperInfo(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contest_saveDeveloperInfoauth_recoverPassword, req);
  LOG(INFO) << "contest_saveDeveloperInfo - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contest_saveDeveloperInfo(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_logOut(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_logOutauth_recoverPassword, req);
  LOG(INFO) << "auth_logOut - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_logOut(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_resetAuthorizations(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_resetAuthorizationsauth_recoverPassword, req);
  LOG(INFO) << "auth_resetAuthorizations - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_resetAuthorizations(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_sendInvites(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_sendInvitesauth_recoverPassword, req);
  LOG(INFO) << "auth_sendInvites - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_sendInvites(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_bindTempAuthKey(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_bindTempAuthKeyauth_recoverPassword, req);
  LOG(INFO) << "auth_bindTempAuthKey - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_bindTempAuthKey(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_cancelCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_cancelCodeauth_recoverPassword, req);
  LOG(INFO) << "auth_cancelCode - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_cancelCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_dropTempAuthKeys(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_dropTempAuthKeysauth_recoverPassword, req);
  LOG(INFO) << "auth_dropTempAuthKeys - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_dropTempAuthKeys(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_registerDevice(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_registerDeviceauth_recoverPassword, req);
  LOG(INFO) << "account_registerDevice - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_registerDevice(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_unregisterDevice(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_unregisterDeviceauth_recoverPassword, req);
  LOG(INFO) << "account_unregisterDevice - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_unregisterDevice(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateNotifySettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateNotifySettingsauth_recoverPassword, req);
  LOG(INFO) << "account_updateNotifySettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_updateNotifySettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_resetNotifySettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_resetNotifySettingsauth_recoverPassword, req);
  LOG(INFO) << "account_resetNotifySettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_resetNotifySettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateStatus(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateStatusauth_recoverPassword, req);
  LOG(INFO) << "account_updateStatus - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_updateStatus(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_reportPeer(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_reportPeerauth_recoverPassword, req);
  LOG(INFO) << "account_reportPeer - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_reportPeer(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_checkUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_checkUsernameauth_recoverPassword, req);
  LOG(INFO) << "account_checkUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_checkUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_deleteAccount(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_deleteAccountauth_recoverPassword, req);
  LOG(INFO) << "account_deleteAccount - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_deleteAccount(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_setAccountTTL(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_setAccountTTLauth_recoverPassword, req);
  LOG(INFO) << "account_setAccountTTL - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_setAccountTTL(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateDeviceLocked(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateDeviceLockedauth_recoverPassword, req);
  LOG(INFO) << "account_updateDeviceLocked - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_updateDeviceLocked(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_resetAuthorization(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_resetAuthorizationauth_recoverPassword, req);
  LOG(INFO) << "account_resetAuthorization - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_resetAuthorization(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updatePasswordSettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updatePasswordSettingsauth_recoverPassword, req);
  LOG(INFO) << "account_updatePasswordSettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_updatePasswordSettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_confirmPhone(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_confirmPhoneauth_recoverPassword, req);
  LOG(INFO) << "account_confirmPhone - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_confirmPhone(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_deleteContacts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_deleteContactsauth_recoverPassword, req);
  LOG(INFO) << "contacts_deleteContacts - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_deleteContacts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_block(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_blockauth_recoverPassword, req);
  LOG(INFO) << "contacts_block - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_block(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_unblock(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_unblockauth_recoverPassword, req);
  LOG(INFO) << "contacts_unblock - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_unblock(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_resetTopPeerRating(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_resetTopPeerRatingauth_recoverPassword, req);
  LOG(INFO) << "contacts_resetTopPeerRating - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_resetTopPeerRating(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setTyping(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setTypingauth_recoverPassword, req);
  LOG(INFO) << "messages_setTyping - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_setTyping(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_reportSpam(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_reportSpamauth_recoverPassword, req);
  LOG(INFO) << "messages_reportSpam - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_reportSpam(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_hideReportSpam(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_hideReportSpamauth_recoverPassword, req);
  LOG(INFO) << "messages_hideReportSpam - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_hideReportSpam(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_discardEncryption(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_discardEncryptionauth_recoverPassword, req);
  LOG(INFO) << "messages_discardEncryption - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_discardEncryption(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setEncryptedTyping(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setEncryptedTypingauth_recoverPassword, req);
  LOG(INFO) << "messages_setEncryptedTyping - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_setEncryptedTyping(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_readEncryptedHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_readEncryptedHistoryauth_recoverPassword, req);
  LOG(INFO) << "messages_readEncryptedHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_readEncryptedHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_reportEncryptedSpam(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_reportEncryptedSpamauth_recoverPassword, req);
  LOG(INFO) << "messages_reportEncryptedSpam - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_reportEncryptedSpam(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_uninstallStickerSet(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_uninstallStickerSetauth_recoverPassword, req);
  LOG(INFO) << "messages_uninstallStickerSet - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_uninstallStickerSet(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editChatAdmin(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editChatAdminauth_recoverPassword, req);
  LOG(INFO) << "messages_editChatAdmin - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_editChatAdmin(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_reorderStickerSets(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_reorderStickerSetsauth_recoverPassword, req);
  LOG(INFO) << "messages_reorderStickerSets - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_reorderStickerSets(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_saveGif(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_saveGifauth_recoverPassword, req);
  LOG(INFO) << "messages_saveGif - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_saveGif(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setInlineBotResults(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setInlineBotResultsauth_recoverPassword, req);
  LOG(INFO) << "messages_setInlineBotResults - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_setInlineBotResults(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editInlineBotMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editInlineBotMessageauth_recoverPassword, req);
  LOG(INFO) << "messages_editInlineBotMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_editInlineBotMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setBotCallbackAnswer(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setBotCallbackAnswerauth_recoverPassword, req);
  LOG(INFO) << "messages_setBotCallbackAnswer - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_setBotCallbackAnswer(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_saveDraft(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_saveDraftauth_recoverPassword, req);
  LOG(INFO) << "messages_saveDraft - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_saveDraft(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_readFeaturedStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_readFeaturedStickersauth_recoverPassword, req);
  LOG(INFO) << "messages_readFeaturedStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_readFeaturedStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_saveRecentSticker(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_saveRecentStickerauth_recoverPassword, req);
  LOG(INFO) << "messages_saveRecentSticker - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_saveRecentSticker(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_clearRecentStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_clearRecentStickersauth_recoverPassword, req);
  LOG(INFO) << "messages_clearRecentStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_clearRecentStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setInlineGameScore(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setInlineGameScoreauth_recoverPassword, req);
  LOG(INFO) << "messages_setInlineGameScore - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_setInlineGameScore(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_toggleDialogPin(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_toggleDialogPinauth_recoverPassword, req);
  LOG(INFO) << "messages_toggleDialogPin - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_toggleDialogPin(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_reorderPinnedDialogs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_reorderPinnedDialogsauth_recoverPassword, req);
  LOG(INFO) << "messages_reorderPinnedDialogs - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_reorderPinnedDialogs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setBotShippingResults(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setBotShippingResultsauth_recoverPassword, req);
  LOG(INFO) << "messages_setBotShippingResults - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_setBotShippingResults(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setBotPrecheckoutResults(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setBotPrecheckoutResultsauth_recoverPassword, req);
  LOG(INFO) << "messages_setBotPrecheckoutResults - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_setBotPrecheckoutResults(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_saveFilePart(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_saveFilePartauth_recoverPassword, req);
  LOG(INFO) << "upload_saveFilePart - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.upload_saveFilePart(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_saveBigFilePart(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_saveBigFilePartauth_recoverPassword, req);
  LOG(INFO) << "upload_saveBigFilePart - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.upload_saveBigFilePart(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_reuploadCdnFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_reuploadCdnFileauth_recoverPassword, req);
  LOG(INFO) << "upload_reuploadCdnFile - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.upload_reuploadCdnFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_saveAppLog(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_saveAppLogauth_recoverPassword, req);
  LOG(INFO) << "help_saveAppLog - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_saveAppLog(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_setBotUpdatesStatus(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_setBotUpdatesStatusauth_recoverPassword, req);
  LOG(INFO) << "help_setBotUpdatesStatus - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_setBotUpdatesStatus(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_readHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_readHistoryauth_recoverPassword, req);
  LOG(INFO) << "channels_readHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_readHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_reportSpam(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_reportSpamauth_recoverPassword, req);
  LOG(INFO) << "channels_reportSpam - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_reportSpam(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_editAbout(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_editAboutauth_recoverPassword, req);
  LOG(INFO) << "channels_editAbout - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_editAbout(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_checkUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_checkUsernameauth_recoverPassword, req);
  LOG(INFO) << "channels_checkUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_checkUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_updateUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_updateUsernameauth_recoverPassword, req);
  LOG(INFO) << "channels_updateUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_updateUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::bots_answerWebhookJSONQuery(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_bots_answerWebhookJSONQueryauth_recoverPassword, req);
  LOG(INFO) << "bots_answerWebhookJSONQuery - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.bots_answerWebhookJSONQuery(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_clearSavedInfo(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_clearSavedInfoauth_recoverPassword, req);
  LOG(INFO) << "payments_clearSavedInfo - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.payments_clearSavedInfo(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_receivedCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_receivedCallauth_recoverPassword, req);
  LOG(INFO) << "phone_receivedCall - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.phone_receivedCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_saveCallDebug(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_saveCallDebugauth_recoverPassword, req);
  LOG(INFO) << "phone_saveCallDebug - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.phone_saveCallDebug(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::invokeAfterMsg(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_invokeAfterMsgauth_recoverPassword, req);
  LOG(INFO) << "invokeAfterMsg - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.invokeAfterMsg(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::invokeAfterMsgs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_invokeAfterMsgsauth_recoverPassword, req);
  LOG(INFO) << "invokeAfterMsgs - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.invokeAfterMsgs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::initConnection(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_initConnectionauth_recoverPassword, req);
  LOG(INFO) << "initConnection - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.initConnection(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::invokeWithLayer(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_invokeWithLayerauth_recoverPassword, req);
  LOG(INFO) << "invokeWithLayer - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.invokeWithLayer(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::invokeWithoutUpdates(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_invokeWithoutUpdatesauth_recoverPassword, req);
  LOG(INFO) << "invokeWithoutUpdates - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.invokeWithoutUpdates(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_checkPhone(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_checkPhoneauth_recoverPassword, req);
  LOG(INFO) << "auth_checkPhone - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_checkPhone(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_sendCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_sendCodeauth_recoverPassword, req);
  LOG(INFO) << "auth_sendCode - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_sendCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_resendCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_resendCodeauth_recoverPassword, req);
  LOG(INFO) << "auth_resendCode - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_resendCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_sendChangePhoneCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_sendChangePhoneCodeauth_recoverPassword, req);
  LOG(INFO) << "account_sendChangePhoneCode - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_sendChangePhoneCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_sendConfirmPhoneCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_sendConfirmPhoneCodeauth_recoverPassword, req);
  LOG(INFO) << "account_sendConfirmPhoneCode - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_sendConfirmPhoneCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_signUp(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_signUpauth_recoverPassword, req);
  LOG(INFO) << "auth_signUp - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_signUp(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_signIn(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_signInauth_recoverPassword, req);
  LOG(INFO) << "auth_signIn - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_signIn(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_importAuthorization(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_importAuthorizationauth_recoverPassword, req);
  LOG(INFO) << "auth_importAuthorization - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_importAuthorization(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_importBotAuthorization(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_importBotAuthorizationauth_recoverPassword, req);
  LOG(INFO) << "auth_importBotAuthorization - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_importBotAuthorization(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_checkPassword(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_checkPasswordauth_recoverPassword, req);
  LOG(INFO) << "auth_checkPassword - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_checkPassword(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_recoverPassword(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_recoverPasswordauth_recoverPassword, req);
  LOG(INFO) << "auth_recoverPassword - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_recoverPassword(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_exportAuthorization(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_exportAuthorizationauth_recoverPassword, req);
  LOG(INFO) << "auth_exportAuthorization - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_exportAuthorization(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_requestPasswordRecovery(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_requestPasswordRecoveryauth_recoverPassword, req);
  LOG(INFO) << "auth_requestPasswordRecovery - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.auth_requestPasswordRecovery(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getNotifySettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getNotifySettingsauth_recoverPassword, req);
  LOG(INFO) << "account_getNotifySettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_getNotifySettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateProfile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateProfileauth_recoverPassword, req);
  LOG(INFO) << "account_updateProfile - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_updateProfile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateUsernameauth_recoverPassword, req);
  LOG(INFO) << "account_updateUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_updateUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_changePhone(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_changePhoneauth_recoverPassword, req);
  LOG(INFO) << "account_changePhone - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_changePhone(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_importCard(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_importCardauth_recoverPassword, req);
  LOG(INFO) << "contacts_importCard - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_importCard(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getWallPapers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getWallPapersauth_recoverPassword, req);
  LOG(INFO) << "account_getWallPapers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_getWallPapers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getPrivacy(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getPrivacyauth_recoverPassword, req);
  LOG(INFO) << "account_getPrivacy - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_getPrivacy(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_setPrivacy(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_setPrivacyauth_recoverPassword, req);
  LOG(INFO) << "account_setPrivacy - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_setPrivacy(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getAccountTTL(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getAccountTTLauth_recoverPassword, req);
  LOG(INFO) << "account_getAccountTTL - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_getAccountTTL(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getAuthorizations(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getAuthorizationsauth_recoverPassword, req);
  LOG(INFO) << "account_getAuthorizations - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_getAuthorizations(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getPassword(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getPasswordauth_recoverPassword, req);
  LOG(INFO) << "account_getPassword - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_getPassword(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getPasswordSettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getPasswordSettingsauth_recoverPassword, req);
  LOG(INFO) << "account_getPasswordSettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_getPasswordSettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getTmpPassword(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getTmpPasswordauth_recoverPassword, req);
  LOG(INFO) << "account_getTmpPassword - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.account_getTmpPassword(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::users_getUsers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_users_getUsersauth_recoverPassword, req);
  LOG(INFO) << "users_getUsers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.users_getUsers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::users_getFullUser(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_users_getFullUserauth_recoverPassword, req);
  LOG(INFO) << "users_getFullUser - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.users_getFullUser(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_getStatuses(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_getStatusesauth_recoverPassword, req);
  LOG(INFO) << "contacts_getStatuses - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_getStatuses(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_getContacts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_getContactsauth_recoverPassword, req);
  LOG(INFO) << "contacts_getContacts - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_getContacts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_importContacts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_importContactsauth_recoverPassword, req);
  LOG(INFO) << "contacts_importContacts - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_importContacts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_deleteContact(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_deleteContactauth_recoverPassword, req);
  LOG(INFO) << "contacts_deleteContact - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_deleteContact(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_getBlocked(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_getBlockedauth_recoverPassword, req);
  LOG(INFO) << "contacts_getBlocked - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_getBlocked(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_exportCard(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_exportCardauth_recoverPassword, req);
  LOG(INFO) << "contacts_exportCard - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_exportCard(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getMessagesViews(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getMessagesViewsauth_recoverPassword, req);
  LOG(INFO) << "messages_getMessagesViews - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getMessagesViews(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_search(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_searchauth_recoverPassword, req);
  LOG(INFO) << "contacts_search - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_search(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_resolveUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_resolveUsernameauth_recoverPassword, req);
  LOG(INFO) << "contacts_resolveUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_resolveUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_getTopPeers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_getTopPeersauth_recoverPassword, req);
  LOG(INFO) << "contacts_getTopPeers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.contacts_getTopPeers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getMessagesauth_recoverPassword, req);
  LOG(INFO) << "messages_getMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getHistoryauth_recoverPassword, req);
  LOG(INFO) << "messages_getHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_search(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_searchauth_recoverPassword, req);
  LOG(INFO) << "messages_search - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_search(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_searchGlobal(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_searchGlobalauth_recoverPassword, req);
  LOG(INFO) << "messages_searchGlobal - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_searchGlobal(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getMessagesauth_recoverPassword, req);
  LOG(INFO) << "channels_getMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_getMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getDialogs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getDialogsauth_recoverPassword, req);
  LOG(INFO) << "messages_getDialogs - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getDialogs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_readHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_readHistoryauth_recoverPassword, req);
  LOG(INFO) << "messages_readHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_readHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_deleteMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_deleteMessagesauth_recoverPassword, req);
  LOG(INFO) << "messages_deleteMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_deleteMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_readMessageContents(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_readMessageContentsauth_recoverPassword, req);
  LOG(INFO) << "messages_readMessageContents - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_readMessageContents(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_deleteMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_deleteMessagesauth_recoverPassword, req);
  LOG(INFO) << "channels_deleteMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_deleteMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_deleteHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_deleteHistoryauth_recoverPassword, req);
  LOG(INFO) << "messages_deleteHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_deleteHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_deleteUserHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_deleteUserHistoryauth_recoverPassword, req);
  LOG(INFO) << "channels_deleteUserHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_deleteUserHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_receivedMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_receivedMessagesauth_recoverPassword, req);
  LOG(INFO) << "messages_receivedMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_receivedMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendMessageauth_recoverPassword, req);
  LOG(INFO) << "messages_sendMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_sendMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendMedia(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendMediaauth_recoverPassword, req);
  LOG(INFO) << "messages_sendMedia - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_sendMedia(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_forwardMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_forwardMessagesauth_recoverPassword, req);
  LOG(INFO) << "messages_forwardMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_forwardMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editChatTitle(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editChatTitleauth_recoverPassword, req);
  LOG(INFO) << "messages_editChatTitle - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_editChatTitle(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editChatPhoto(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editChatPhotoauth_recoverPassword, req);
  LOG(INFO) << "messages_editChatPhoto - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_editChatPhoto(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_addChatUser(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_addChatUserauth_recoverPassword, req);
  LOG(INFO) << "messages_addChatUser - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_addChatUser(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_deleteChatUser(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_deleteChatUserauth_recoverPassword, req);
  LOG(INFO) << "messages_deleteChatUser - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_deleteChatUser(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_createChat(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_createChatauth_recoverPassword, req);
  LOG(INFO) << "messages_createChat - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_createChat(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_forwardMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_forwardMessageauth_recoverPassword, req);
  LOG(INFO) << "messages_forwardMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_forwardMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_importChatInvite(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_importChatInviteauth_recoverPassword, req);
  LOG(INFO) << "messages_importChatInvite - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_importChatInvite(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_startBot(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_startBotauth_recoverPassword, req);
  LOG(INFO) << "messages_startBot - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_startBot(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_toggleChatAdmins(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_toggleChatAdminsauth_recoverPassword, req);
  LOG(INFO) << "messages_toggleChatAdmins - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_toggleChatAdmins(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_migrateChat(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_migrateChatauth_recoverPassword, req);
  LOG(INFO) << "messages_migrateChat - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_migrateChat(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendInlineBotResult(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendInlineBotResultauth_recoverPassword, req);
  LOG(INFO) << "messages_sendInlineBotResult - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_sendInlineBotResult(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editMessageauth_recoverPassword, req);
  LOG(INFO) << "messages_editMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_editMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getAllDrafts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getAllDraftsauth_recoverPassword, req);
  LOG(INFO) << "messages_getAllDrafts - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getAllDrafts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setGameScore(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setGameScoreauth_recoverPassword, req);
  LOG(INFO) << "messages_setGameScore - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_setGameScore(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getAppChangelog(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getAppChangelogauth_recoverPassword, req);
  LOG(INFO) << "help_getAppChangelog - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_getAppChangelog(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_createChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_createChannelauth_recoverPassword, req);
  LOG(INFO) << "channels_createChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_createChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_editAdmin(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_editAdminauth_recoverPassword, req);
  LOG(INFO) << "channels_editAdmin - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_editAdmin(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_editTitle(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_editTitleauth_recoverPassword, req);
  LOG(INFO) << "channels_editTitle - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_editTitle(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_editPhoto(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_editPhotoauth_recoverPassword, req);
  LOG(INFO) << "channels_editPhoto - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_editPhoto(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_joinChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_joinChannelauth_recoverPassword, req);
  LOG(INFO) << "channels_joinChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_joinChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_leaveChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_leaveChannelauth_recoverPassword, req);
  LOG(INFO) << "channels_leaveChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_leaveChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_inviteToChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_inviteToChannelauth_recoverPassword, req);
  LOG(INFO) << "channels_inviteToChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_inviteToChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_kickFromChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_kickFromChannelauth_recoverPassword, req);
  LOG(INFO) << "channels_kickFromChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_kickFromChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_deleteChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_deleteChannelauth_recoverPassword, req);
  LOG(INFO) << "channels_deleteChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_deleteChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_toggleInvites(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_toggleInvitesauth_recoverPassword, req);
  LOG(INFO) << "channels_toggleInvites - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_toggleInvites(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_toggleSignatures(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_toggleSignaturesauth_recoverPassword, req);
  LOG(INFO) << "channels_toggleSignatures - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_toggleSignatures(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_updatePinnedMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_updatePinnedMessageauth_recoverPassword, req);
  LOG(INFO) << "channels_updatePinnedMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_updatePinnedMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_discardCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_discardCallauth_recoverPassword, req);
  LOG(INFO) << "phone_discardCall - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.phone_discardCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_setCallRating(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_setCallRatingauth_recoverPassword, req);
  LOG(INFO) << "phone_setCallRating - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.phone_setCallRating(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getPeerSettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getPeerSettingsauth_recoverPassword, req);
  LOG(INFO) << "messages_getPeerSettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getPeerSettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getChats(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getChatsauth_recoverPassword, req);
  LOG(INFO) << "messages_getChats - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getChats(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getCommonChats(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getCommonChatsauth_recoverPassword, req);
  LOG(INFO) << "messages_getCommonChats - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getCommonChats(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getAllChats(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getAllChatsauth_recoverPassword, req);
  LOG(INFO) << "messages_getAllChats - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getAllChats(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getChannels(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getChannelsauth_recoverPassword, req);
  LOG(INFO) << "channels_getChannels - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_getChannels(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getAdminedPublicChannels(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getAdminedPublicChannelsauth_recoverPassword, req);
  LOG(INFO) << "channels_getAdminedPublicChannels - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_getAdminedPublicChannels(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getFullChat(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getFullChatauth_recoverPassword, req);
  LOG(INFO) << "messages_getFullChat - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getFullChat(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getFullChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getFullChannelauth_recoverPassword, req);
  LOG(INFO) << "channels_getFullChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_getFullChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getDhConfig(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getDhConfigauth_recoverPassword, req);
  LOG(INFO) << "messages_getDhConfig - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getDhConfig(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_requestEncryption(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_requestEncryptionauth_recoverPassword, req);
  LOG(INFO) << "messages_requestEncryption - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_requestEncryption(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_acceptEncryption(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_acceptEncryptionauth_recoverPassword, req);
  LOG(INFO) << "messages_acceptEncryption - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_acceptEncryption(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendEncrypted(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendEncryptedauth_recoverPassword, req);
  LOG(INFO) << "messages_sendEncrypted - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_sendEncrypted(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendEncryptedFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendEncryptedFileauth_recoverPassword, req);
  LOG(INFO) << "messages_sendEncryptedFile - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_sendEncryptedFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendEncryptedService(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendEncryptedServiceauth_recoverPassword, req);
  LOG(INFO) << "messages_sendEncryptedService - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_sendEncryptedService(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_receivedQueue(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_receivedQueueauth_recoverPassword, req);
  LOG(INFO) << "messages_receivedQueue - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_receivedQueue(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::photos_deletePhotos(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_photos_deletePhotosauth_recoverPassword, req);
  LOG(INFO) << "photos_deletePhotos - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.photos_deletePhotos(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getAllStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getAllStickersauth_recoverPassword, req);
  LOG(INFO) << "messages_getAllStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getAllStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getMaskStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getMaskStickersauth_recoverPassword, req);
  LOG(INFO) << "messages_getMaskStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getMaskStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getWebPagePreview(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getWebPagePreviewauth_recoverPassword, req);
  LOG(INFO) << "messages_getWebPagePreview - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getWebPagePreview(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_exportChatInvite(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_exportChatInviteauth_recoverPassword, req);
  LOG(INFO) << "messages_exportChatInvite - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_exportChatInvite(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_exportInvite(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_exportInviteauth_recoverPassword, req);
  LOG(INFO) << "channels_exportInvite - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_exportInvite(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_checkChatInvite(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_checkChatInviteauth_recoverPassword, req);
  LOG(INFO) << "messages_checkChatInvite - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_checkChatInvite(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getStickerSet(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getStickerSetauth_recoverPassword, req);
  LOG(INFO) << "messages_getStickerSet - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getStickerSet(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_installStickerSet(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_installStickerSetauth_recoverPassword, req);
  LOG(INFO) << "messages_installStickerSet - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_installStickerSet(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getDocumentByHash(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getDocumentByHashauth_recoverPassword, req);
  LOG(INFO) << "messages_getDocumentByHash - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getDocumentByHash(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_searchGifs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_searchGifsauth_recoverPassword, req);
  LOG(INFO) << "messages_searchGifs - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_searchGifs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getSavedGifs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getSavedGifsauth_recoverPassword, req);
  LOG(INFO) << "messages_getSavedGifs - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getSavedGifs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getInlineBotResults(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getInlineBotResultsauth_recoverPassword, req);
  LOG(INFO) << "messages_getInlineBotResults - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getInlineBotResults(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getMessageEditData(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getMessageEditDataauth_recoverPassword, req);
  LOG(INFO) << "messages_getMessageEditData - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getMessageEditData(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getBotCallbackAnswer(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getBotCallbackAnswerauth_recoverPassword, req);
  LOG(INFO) << "messages_getBotCallbackAnswer - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getBotCallbackAnswer(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getPeerDialogs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getPeerDialogsauth_recoverPassword, req);
  LOG(INFO) << "messages_getPeerDialogs - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getPeerDialogs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getPinnedDialogs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getPinnedDialogsauth_recoverPassword, req);
  LOG(INFO) << "messages_getPinnedDialogs - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getPinnedDialogs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getFeaturedStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getFeaturedStickersauth_recoverPassword, req);
  LOG(INFO) << "messages_getFeaturedStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getFeaturedStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getRecentStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getRecentStickersauth_recoverPassword, req);
  LOG(INFO) << "messages_getRecentStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getRecentStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getArchivedStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getArchivedStickersauth_recoverPassword, req);
  LOG(INFO) << "messages_getArchivedStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getArchivedStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getAttachedStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getAttachedStickersauth_recoverPassword, req);
  LOG(INFO) << "messages_getAttachedStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getAttachedStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getGameHighScores(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getGameHighScoresauth_recoverPassword, req);
  LOG(INFO) << "messages_getGameHighScores - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getGameHighScores(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getInlineGameHighScores(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getInlineGameHighScoresauth_recoverPassword, req);
  LOG(INFO) << "messages_getInlineGameHighScores - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getInlineGameHighScores(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getWebPage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getWebPageauth_recoverPassword, req);
  LOG(INFO) << "messages_getWebPage - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.messages_getWebPage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::updates_getState(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_updates_getStateauth_recoverPassword, req);
  LOG(INFO) << "updates_getState - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.updates_getState(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::updates_getDifference(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_updates_getDifferenceauth_recoverPassword, req);
  LOG(INFO) << "updates_getDifference - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.updates_getDifference(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::updates_getChannelDifference(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_updates_getChannelDifferenceauth_recoverPassword, req);
  LOG(INFO) << "updates_getChannelDifference - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.updates_getChannelDifference(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::photos_updateProfilePhoto(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_photos_updateProfilePhotoauth_recoverPassword, req);
  LOG(INFO) << "photos_updateProfilePhoto - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.photos_updateProfilePhoto(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::photos_uploadProfilePhoto(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_photos_uploadProfilePhotoauth_recoverPassword, req);
  LOG(INFO) << "photos_uploadProfilePhoto - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.photos_uploadProfilePhoto(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::photos_getUserPhotos(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_photos_getUserPhotosauth_recoverPassword, req);
  LOG(INFO) << "photos_getUserPhotos - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.photos_getUserPhotos(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_getFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_getFileauth_recoverPassword, req);
  LOG(INFO) << "upload_getFile - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.upload_getFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_getWebFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_getWebFileauth_recoverPassword, req);
  LOG(INFO) << "upload_getWebFile - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.upload_getWebFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_getCdnFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_getCdnFileauth_recoverPassword, req);
  LOG(INFO) << "upload_getCdnFile - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.upload_getCdnFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getConfig(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getConfigauth_recoverPassword, req);
  LOG(INFO) << "help_getConfig - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_getConfig(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getNearestDc(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getNearestDcauth_recoverPassword, req);
  LOG(INFO) << "help_getNearestDc - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_getNearestDc(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getAppUpdate(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getAppUpdateauth_recoverPassword, req);
  LOG(INFO) << "help_getAppUpdate - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_getAppUpdate(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getInviteText(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getInviteTextauth_recoverPassword, req);
  LOG(INFO) << "help_getInviteText - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_getInviteText(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getSupport(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getSupportauth_recoverPassword, req);
  LOG(INFO) << "help_getSupport - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_getSupport(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getTermsOfService(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getTermsOfServiceauth_recoverPassword, req);
  LOG(INFO) << "help_getTermsOfService - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_getTermsOfService(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getCdnConfig(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getCdnConfigauth_recoverPassword, req);
  LOG(INFO) << "help_getCdnConfig - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.help_getCdnConfig(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getParticipants(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getParticipantsauth_recoverPassword, req);
  LOG(INFO) << "channels_getParticipants - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_getParticipants(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getParticipant(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getParticipantauth_recoverPassword, req);
  LOG(INFO) << "channels_getParticipant - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_getParticipant(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_exportMessageLink(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_exportMessageLinkauth_recoverPassword, req);
  LOG(INFO) << "channels_exportMessageLink - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.channels_exportMessageLink(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::bots_sendCustomRequest(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_bots_sendCustomRequestauth_recoverPassword, req);
  LOG(INFO) << "bots_sendCustomRequest - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.bots_sendCustomRequest(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_getCallConfig(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_getCallConfigauth_recoverPassword, req);
  LOG(INFO) << "phone_getCallConfig - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.phone_getCallConfig(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_getPaymentForm(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_getPaymentFormauth_recoverPassword, req);
  LOG(INFO) << "payments_getPaymentForm - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.payments_getPaymentForm(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_getPaymentReceipt(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_getPaymentReceiptauth_recoverPassword, req);
  LOG(INFO) << "payments_getPaymentReceipt - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.payments_getPaymentReceipt(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_validateRequestedInfo(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_validateRequestedInfoauth_recoverPassword, req);
  LOG(INFO) << "payments_validateRequestedInfo - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.payments_validateRequestedInfo(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_sendPaymentForm(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_sendPaymentFormauth_recoverPassword, req);
  LOG(INFO) << "payments_sendPaymentForm - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.payments_sendPaymentForm(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_getSavedInfo(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_getSavedInfoauth_recoverPassword, req);
  LOG(INFO) << "payments_getSavedInfo - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.payments_getSavedInfo(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_requestCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_requestCallauth_recoverPassword, req);
  LOG(INFO) << "phone_requestCall - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.phone_requestCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_acceptCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_acceptCallauth_recoverPassword, req);
  LOG(INFO) << "phone_acceptCall - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.phone_acceptCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_confirmCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_confirmCallauth_recoverPassword, req);
  LOG(INFO) << "phone_confirmCall - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request)  impl.phone_confirmCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}



