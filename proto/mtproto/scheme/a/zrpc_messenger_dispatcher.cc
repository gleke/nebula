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

ZRpcMessengerDispatcher::ZRpcMessengerDispatcher() { 
  ZRpcUtil::Register(mtproto::TL_account_changePhone::CLASS_ID, account_changePhone);
  ZRpcUtil::Register(mtproto::TL_account_checkUsername::CLASS_ID, account_checkUsername);
  ZRpcUtil::Register(mtproto::TL_account_confirmPhone::CLASS_ID, account_confirmPhone);
  ZRpcUtil::Register(mtproto::TL_account_deleteAccount::CLASS_ID, account_deleteAccount);
  ZRpcUtil::Register(mtproto::TL_account_getAccountTTL::CLASS_ID, account_getAccountTTL);
  ZRpcUtil::Register(mtproto::TL_account_getAuthorizations::CLASS_ID, account_getAuthorizations);
  ZRpcUtil::Register(mtproto::TL_account_getNotifySettings::CLASS_ID, account_getNotifySettings);
  ZRpcUtil::Register(mtproto::TL_account_getPassword::CLASS_ID, account_getPassword);
  ZRpcUtil::Register(mtproto::TL_account_getPasswordSettings::CLASS_ID, account_getPasswordSettings);
  ZRpcUtil::Register(mtproto::TL_account_getPrivacy::CLASS_ID, account_getPrivacy);
  ZRpcUtil::Register(mtproto::TL_account_getTmpPassword::CLASS_ID, account_getTmpPassword);
  ZRpcUtil::Register(mtproto::TL_account_getWallPapers::CLASS_ID, account_getWallPapers);
  ZRpcUtil::Register(mtproto::TL_account_registerDevice::CLASS_ID, account_registerDevice);
  ZRpcUtil::Register(mtproto::TL_account_reportPeer::CLASS_ID, account_reportPeer);
  ZRpcUtil::Register(mtproto::TL_account_resetAuthorization::CLASS_ID, account_resetAuthorization);
  ZRpcUtil::Register(mtproto::TL_account_resetNotifySettings::CLASS_ID, account_resetNotifySettings);
  ZRpcUtil::Register(mtproto::TL_account_sendChangePhoneCode::CLASS_ID, account_sendChangePhoneCode);
  ZRpcUtil::Register(mtproto::TL_account_sendConfirmPhoneCode::CLASS_ID, account_sendConfirmPhoneCode);
  ZRpcUtil::Register(mtproto::TL_account_setAccountTTL::CLASS_ID, account_setAccountTTL);
  ZRpcUtil::Register(mtproto::TL_account_setPrivacy::CLASS_ID, account_setPrivacy);
  ZRpcUtil::Register(mtproto::TL_account_unregisterDevice::CLASS_ID, account_unregisterDevice);
  ZRpcUtil::Register(mtproto::TL_account_updateDeviceLocked::CLASS_ID, account_updateDeviceLocked);
  ZRpcUtil::Register(mtproto::TL_account_updateNotifySettings::CLASS_ID, account_updateNotifySettings);
  ZRpcUtil::Register(mtproto::TL_account_updatePasswordSettings::CLASS_ID, account_updatePasswordSettings);
  ZRpcUtil::Register(mtproto::TL_account_updateProfile::CLASS_ID, account_updateProfile);
  ZRpcUtil::Register(mtproto::TL_account_updateStatus::CLASS_ID, account_updateStatus);
  ZRpcUtil::Register(mtproto::TL_account_updateUsername::CLASS_ID, account_updateUsername);
  ZRpcUtil::Register(mtproto::TL_auth_bindTempAuthKey::CLASS_ID, auth_bindTempAuthKey);
  ZRpcUtil::Register(mtproto::TL_auth_cancelCode::CLASS_ID, auth_cancelCode);
  ZRpcUtil::Register(mtproto::TL_auth_checkPassword::CLASS_ID, auth_checkPassword);
  ZRpcUtil::Register(mtproto::TL_auth_checkPhone::CLASS_ID, auth_checkPhone);
  ZRpcUtil::Register(mtproto::TL_auth_dropTempAuthKeys::CLASS_ID, auth_dropTempAuthKeys);
  ZRpcUtil::Register(mtproto::TL_auth_exportAuthorization::CLASS_ID, auth_exportAuthorization);
  ZRpcUtil::Register(mtproto::TL_auth_importAuthorization::CLASS_ID, auth_importAuthorization);
  ZRpcUtil::Register(mtproto::TL_auth_importBotAuthorization::CLASS_ID, auth_importBotAuthorization);
  ZRpcUtil::Register(mtproto::TL_auth_logOut::CLASS_ID, auth_logOut);
  ZRpcUtil::Register(mtproto::TL_auth_recoverPassword::CLASS_ID, auth_recoverPassword);
  ZRpcUtil::Register(mtproto::TL_auth_requestPasswordRecovery::CLASS_ID, auth_requestPasswordRecovery);
  ZRpcUtil::Register(mtproto::TL_auth_resendCode::CLASS_ID, auth_resendCode);
  ZRpcUtil::Register(mtproto::TL_auth_resetAuthorizations::CLASS_ID, auth_resetAuthorizations);
  ZRpcUtil::Register(mtproto::TL_auth_sendCode::CLASS_ID, auth_sendCode);
  ZRpcUtil::Register(mtproto::TL_auth_sendInvites::CLASS_ID, auth_sendInvites);
  ZRpcUtil::Register(mtproto::TL_auth_signIn::CLASS_ID, auth_signIn);
  ZRpcUtil::Register(mtproto::TL_auth_signUp::CLASS_ID, auth_signUp);
  ZRpcUtil::Register(mtproto::TL_bots_answerWebhookJSONQuery::CLASS_ID, bots_answerWebhookJSONQuery);
  ZRpcUtil::Register(mtproto::TL_bots_sendCustomRequest::CLASS_ID, bots_sendCustomRequest);
  ZRpcUtil::Register(mtproto::TL_channels_checkUsername::CLASS_ID, channels_checkUsername);
  ZRpcUtil::Register(mtproto::TL_channels_createChannel::CLASS_ID, channels_createChannel);
  ZRpcUtil::Register(mtproto::TL_channels_deleteChannel::CLASS_ID, channels_deleteChannel);
  ZRpcUtil::Register(mtproto::TL_channels_deleteMessages::CLASS_ID, channels_deleteMessages);
  ZRpcUtil::Register(mtproto::TL_channels_deleteUserHistory::CLASS_ID, channels_deleteUserHistory);
  ZRpcUtil::Register(mtproto::TL_channels_editAbout::CLASS_ID, channels_editAbout);
  ZRpcUtil::Register(mtproto::TL_channels_editAdmin::CLASS_ID, channels_editAdmin);
  ZRpcUtil::Register(mtproto::TL_channels_editPhoto::CLASS_ID, channels_editPhoto);
  ZRpcUtil::Register(mtproto::TL_channels_editTitle::CLASS_ID, channels_editTitle);
  ZRpcUtil::Register(mtproto::TL_channels_exportInvite::CLASS_ID, channels_exportInvite);
  ZRpcUtil::Register(mtproto::TL_channels_exportMessageLink::CLASS_ID, channels_exportMessageLink);
  ZRpcUtil::Register(mtproto::TL_channels_getAdminedPublicChannels::CLASS_ID, channels_getAdminedPublicChannels);
  ZRpcUtil::Register(mtproto::TL_channels_getChannels::CLASS_ID, channels_getChannels);
  ZRpcUtil::Register(mtproto::TL_channels_getFullChannel::CLASS_ID, channels_getFullChannel);
  ZRpcUtil::Register(mtproto::TL_channels_getMessages::CLASS_ID, channels_getMessages);
  ZRpcUtil::Register(mtproto::TL_channels_getParticipant::CLASS_ID, channels_getParticipant);
  ZRpcUtil::Register(mtproto::TL_channels_getParticipants::CLASS_ID, channels_getParticipants);
  ZRpcUtil::Register(mtproto::TL_channels_inviteToChannel::CLASS_ID, channels_inviteToChannel);
  ZRpcUtil::Register(mtproto::TL_channels_joinChannel::CLASS_ID, channels_joinChannel);
  ZRpcUtil::Register(mtproto::TL_channels_kickFromChannel::CLASS_ID, channels_kickFromChannel);
  ZRpcUtil::Register(mtproto::TL_channels_leaveChannel::CLASS_ID, channels_leaveChannel);
  ZRpcUtil::Register(mtproto::TL_channels_readHistory::CLASS_ID, channels_readHistory);
  ZRpcUtil::Register(mtproto::TL_channels_reportSpam::CLASS_ID, channels_reportSpam);
  ZRpcUtil::Register(mtproto::TL_channels_toggleInvites::CLASS_ID, channels_toggleInvites);
  ZRpcUtil::Register(mtproto::TL_channels_toggleSignatures::CLASS_ID, channels_toggleSignatures);
  ZRpcUtil::Register(mtproto::TL_channels_updatePinnedMessage::CLASS_ID, channels_updatePinnedMessage);
  ZRpcUtil::Register(mtproto::TL_channels_updateUsername::CLASS_ID, channels_updateUsername);
  ZRpcUtil::Register(mtproto::TL_contacts_block::CLASS_ID, contacts_block);
  ZRpcUtil::Register(mtproto::TL_contacts_deleteContact::CLASS_ID, contacts_deleteContact);
  ZRpcUtil::Register(mtproto::TL_contacts_deleteContacts::CLASS_ID, contacts_deleteContacts);
  ZRpcUtil::Register(mtproto::TL_contacts_exportCard::CLASS_ID, contacts_exportCard);
  ZRpcUtil::Register(mtproto::TL_contacts_getBlocked::CLASS_ID, contacts_getBlocked);
  ZRpcUtil::Register(mtproto::TL_contacts_getContacts::CLASS_ID, contacts_getContacts);
  ZRpcUtil::Register(mtproto::TL_contacts_getStatuses::CLASS_ID, contacts_getStatuses);
  ZRpcUtil::Register(mtproto::TL_contacts_getTopPeers::CLASS_ID, contacts_getTopPeers);
  ZRpcUtil::Register(mtproto::TL_contacts_importCard::CLASS_ID, contacts_importCard);
  ZRpcUtil::Register(mtproto::TL_contacts_importContacts::CLASS_ID, contacts_importContacts);
  ZRpcUtil::Register(mtproto::TL_contacts_resetTopPeerRating::CLASS_ID, contacts_resetTopPeerRating);
  ZRpcUtil::Register(mtproto::TL_contacts_resolveUsername::CLASS_ID, contacts_resolveUsername);
  ZRpcUtil::Register(mtproto::TL_contacts_search::CLASS_ID, contacts_search);
  ZRpcUtil::Register(mtproto::TL_contacts_unblock::CLASS_ID, contacts_unblock);
  ZRpcUtil::Register(mtproto::TL_help_getAppChangelog::CLASS_ID, help_getAppChangelog);
  ZRpcUtil::Register(mtproto::TL_help_getAppUpdate::CLASS_ID, help_getAppUpdate);
  ZRpcUtil::Register(mtproto::TL_help_getCdnConfig::CLASS_ID, help_getCdnConfig);
  ZRpcUtil::Register(mtproto::TL_help_getConfig::CLASS_ID, help_getConfig);
  ZRpcUtil::Register(mtproto::TL_help_getInviteText::CLASS_ID, help_getInviteText);
  ZRpcUtil::Register(mtproto::TL_help_getNearestDc::CLASS_ID, help_getNearestDc);
  ZRpcUtil::Register(mtproto::TL_help_getSupport::CLASS_ID, help_getSupport);
  ZRpcUtil::Register(mtproto::TL_help_getTermsOfService::CLASS_ID, help_getTermsOfService);
  ZRpcUtil::Register(mtproto::TL_help_saveAppLog::CLASS_ID, help_saveAppLog);
  ZRpcUtil::Register(mtproto::TL_help_setBotUpdatesStatus::CLASS_ID, help_setBotUpdatesStatus);
  ZRpcUtil::Register(mtproto::TL_messages_acceptEncryption::CLASS_ID, messages_acceptEncryption);
  ZRpcUtil::Register(mtproto::TL_messages_addChatUser::CLASS_ID, messages_addChatUser);
  ZRpcUtil::Register(mtproto::TL_messages_checkChatInvite::CLASS_ID, messages_checkChatInvite);
  ZRpcUtil::Register(mtproto::TL_messages_clearRecentStickers::CLASS_ID, messages_clearRecentStickers);
  ZRpcUtil::Register(mtproto::TL_messages_createChat::CLASS_ID, messages_createChat);
  ZRpcUtil::Register(mtproto::TL_messages_deleteChatUser::CLASS_ID, messages_deleteChatUser);
  ZRpcUtil::Register(mtproto::TL_messages_deleteHistory::CLASS_ID, messages_deleteHistory);
  ZRpcUtil::Register(mtproto::TL_messages_deleteMessages::CLASS_ID, messages_deleteMessages);
  ZRpcUtil::Register(mtproto::TL_messages_discardEncryption::CLASS_ID, messages_discardEncryption);
  ZRpcUtil::Register(mtproto::TL_messages_editChatAdmin::CLASS_ID, messages_editChatAdmin);
  ZRpcUtil::Register(mtproto::TL_messages_editChatPhoto::CLASS_ID, messages_editChatPhoto);
  ZRpcUtil::Register(mtproto::TL_messages_editChatTitle::CLASS_ID, messages_editChatTitle);
  ZRpcUtil::Register(mtproto::TL_messages_editInlineBotMessage::CLASS_ID, messages_editInlineBotMessage);
  ZRpcUtil::Register(mtproto::TL_messages_editMessage::CLASS_ID, messages_editMessage);
  ZRpcUtil::Register(mtproto::TL_messages_exportChatInvite::CLASS_ID, messages_exportChatInvite);
  ZRpcUtil::Register(mtproto::TL_messages_forwardMessage::CLASS_ID, messages_forwardMessage);
  ZRpcUtil::Register(mtproto::TL_messages_forwardMessages::CLASS_ID, messages_forwardMessages);
  ZRpcUtil::Register(mtproto::TL_messages_getAllChats::CLASS_ID, messages_getAllChats);
  ZRpcUtil::Register(mtproto::TL_messages_getAllDrafts::CLASS_ID, messages_getAllDrafts);
  ZRpcUtil::Register(mtproto::TL_messages_getAllStickers::CLASS_ID, messages_getAllStickers);
  ZRpcUtil::Register(mtproto::TL_messages_getArchivedStickers::CLASS_ID, messages_getArchivedStickers);
  ZRpcUtil::Register(mtproto::TL_messages_getAttachedStickers::CLASS_ID, messages_getAttachedStickers);
  ZRpcUtil::Register(mtproto::TL_messages_getBotCallbackAnswer::CLASS_ID, messages_getBotCallbackAnswer);
  ZRpcUtil::Register(mtproto::TL_messages_getChats::CLASS_ID, messages_getChats);
  ZRpcUtil::Register(mtproto::TL_messages_getCommonChats::CLASS_ID, messages_getCommonChats);
  ZRpcUtil::Register(mtproto::TL_messages_getDhConfig::CLASS_ID, messages_getDhConfig);
  ZRpcUtil::Register(mtproto::TL_messages_getDialogs::CLASS_ID, messages_getDialogs);
  ZRpcUtil::Register(mtproto::TL_messages_getDocumentByHash::CLASS_ID, messages_getDocumentByHash);
  ZRpcUtil::Register(mtproto::TL_messages_getFeaturedStickers::CLASS_ID, messages_getFeaturedStickers);
  ZRpcUtil::Register(mtproto::TL_messages_getFullChat::CLASS_ID, messages_getFullChat);
  ZRpcUtil::Register(mtproto::TL_messages_getGameHighScores::CLASS_ID, messages_getGameHighScores);
  ZRpcUtil::Register(mtproto::TL_messages_getHistory::CLASS_ID, messages_getHistory);
  ZRpcUtil::Register(mtproto::TL_messages_getInlineBotResults::CLASS_ID, messages_getInlineBotResults);
  ZRpcUtil::Register(mtproto::TL_messages_getInlineGameHighScores::CLASS_ID, messages_getInlineGameHighScores);
  ZRpcUtil::Register(mtproto::TL_messages_getMaskStickers::CLASS_ID, messages_getMaskStickers);
  ZRpcUtil::Register(mtproto::TL_messages_getMessageEditData::CLASS_ID, messages_getMessageEditData);
  ZRpcUtil::Register(mtproto::TL_messages_getMessages::CLASS_ID, messages_getMessages);
  ZRpcUtil::Register(mtproto::TL_messages_getMessagesViews::CLASS_ID, messages_getMessagesViews);
  ZRpcUtil::Register(mtproto::TL_messages_getPeerDialogs::CLASS_ID, messages_getPeerDialogs);
  ZRpcUtil::Register(mtproto::TL_messages_getPeerSettings::CLASS_ID, messages_getPeerSettings);
  ZRpcUtil::Register(mtproto::TL_messages_getPinnedDialogs::CLASS_ID, messages_getPinnedDialogs);
  ZRpcUtil::Register(mtproto::TL_messages_getRecentStickers::CLASS_ID, messages_getRecentStickers);
  ZRpcUtil::Register(mtproto::TL_messages_getSavedGifs::CLASS_ID, messages_getSavedGifs);
  ZRpcUtil::Register(mtproto::TL_messages_getStickerSet::CLASS_ID, messages_getStickerSet);
  ZRpcUtil::Register(mtproto::TL_messages_getWebPage::CLASS_ID, messages_getWebPage);
  ZRpcUtil::Register(mtproto::TL_messages_getWebPagePreview::CLASS_ID, messages_getWebPagePreview);
  ZRpcUtil::Register(mtproto::TL_messages_hideReportSpam::CLASS_ID, messages_hideReportSpam);
  ZRpcUtil::Register(mtproto::TL_messages_importChatInvite::CLASS_ID, messages_importChatInvite);
  ZRpcUtil::Register(mtproto::TL_messages_installStickerSet::CLASS_ID, messages_installStickerSet);
  ZRpcUtil::Register(mtproto::TL_messages_migrateChat::CLASS_ID, messages_migrateChat);
  ZRpcUtil::Register(mtproto::TL_messages_readEncryptedHistory::CLASS_ID, messages_readEncryptedHistory);
  ZRpcUtil::Register(mtproto::TL_messages_readFeaturedStickers::CLASS_ID, messages_readFeaturedStickers);
  ZRpcUtil::Register(mtproto::TL_messages_readHistory::CLASS_ID, messages_readHistory);
  ZRpcUtil::Register(mtproto::TL_messages_readMessageContents::CLASS_ID, messages_readMessageContents);
  ZRpcUtil::Register(mtproto::TL_messages_receivedMessages::CLASS_ID, messages_receivedMessages);
  ZRpcUtil::Register(mtproto::TL_messages_receivedQueue::CLASS_ID, messages_receivedQueue);
  ZRpcUtil::Register(mtproto::TL_messages_reorderPinnedDialogs::CLASS_ID, messages_reorderPinnedDialogs);
  ZRpcUtil::Register(mtproto::TL_messages_reorderStickerSets::CLASS_ID, messages_reorderStickerSets);
  ZRpcUtil::Register(mtproto::TL_messages_reportEncryptedSpam::CLASS_ID, messages_reportEncryptedSpam);
  ZRpcUtil::Register(mtproto::TL_messages_reportSpam::CLASS_ID, messages_reportSpam);
  ZRpcUtil::Register(mtproto::TL_messages_requestEncryption::CLASS_ID, messages_requestEncryption);
  ZRpcUtil::Register(mtproto::TL_messages_saveDraft::CLASS_ID, messages_saveDraft);
  ZRpcUtil::Register(mtproto::TL_messages_saveGif::CLASS_ID, messages_saveGif);
  ZRpcUtil::Register(mtproto::TL_messages_saveRecentSticker::CLASS_ID, messages_saveRecentSticker);
  ZRpcUtil::Register(mtproto::TL_messages_search::CLASS_ID, messages_search);
  ZRpcUtil::Register(mtproto::TL_messages_searchGifs::CLASS_ID, messages_searchGifs);
  ZRpcUtil::Register(mtproto::TL_messages_searchGlobal::CLASS_ID, messages_searchGlobal);
  ZRpcUtil::Register(mtproto::TL_messages_sendEncrypted::CLASS_ID, messages_sendEncrypted);
  ZRpcUtil::Register(mtproto::TL_messages_sendEncryptedFile::CLASS_ID, messages_sendEncryptedFile);
  ZRpcUtil::Register(mtproto::TL_messages_sendEncryptedService::CLASS_ID, messages_sendEncryptedService);
  ZRpcUtil::Register(mtproto::TL_messages_sendInlineBotResult::CLASS_ID, messages_sendInlineBotResult);
  ZRpcUtil::Register(mtproto::TL_messages_sendMedia::CLASS_ID, messages_sendMedia);
  ZRpcUtil::Register(mtproto::TL_messages_sendMessage::CLASS_ID, messages_sendMessage);
  ZRpcUtil::Register(mtproto::TL_messages_setBotCallbackAnswer::CLASS_ID, messages_setBotCallbackAnswer);
  ZRpcUtil::Register(mtproto::TL_messages_setBotPrecheckoutResults::CLASS_ID, messages_setBotPrecheckoutResults);
  ZRpcUtil::Register(mtproto::TL_messages_setBotShippingResults::CLASS_ID, messages_setBotShippingResults);
  ZRpcUtil::Register(mtproto::TL_messages_setEncryptedTyping::CLASS_ID, messages_setEncryptedTyping);
  ZRpcUtil::Register(mtproto::TL_messages_setGameScore::CLASS_ID, messages_setGameScore);
  ZRpcUtil::Register(mtproto::TL_messages_setInlineBotResults::CLASS_ID, messages_setInlineBotResults);
  ZRpcUtil::Register(mtproto::TL_messages_setInlineGameScore::CLASS_ID, messages_setInlineGameScore);
  ZRpcUtil::Register(mtproto::TL_messages_setTyping::CLASS_ID, messages_setTyping);
  ZRpcUtil::Register(mtproto::TL_messages_startBot::CLASS_ID, messages_startBot);
  ZRpcUtil::Register(mtproto::TL_messages_toggleChatAdmins::CLASS_ID, messages_toggleChatAdmins);
  ZRpcUtil::Register(mtproto::TL_messages_toggleDialogPin::CLASS_ID, messages_toggleDialogPin);
  ZRpcUtil::Register(mtproto::TL_messages_uninstallStickerSet::CLASS_ID, messages_uninstallStickerSet);
  ZRpcUtil::Register(mtproto::TL_payments_clearSavedInfo::CLASS_ID, payments_clearSavedInfo);
  ZRpcUtil::Register(mtproto::TL_payments_getPaymentForm::CLASS_ID, payments_getPaymentForm);
  ZRpcUtil::Register(mtproto::TL_payments_getPaymentReceipt::CLASS_ID, payments_getPaymentReceipt);
  ZRpcUtil::Register(mtproto::TL_payments_getSavedInfo::CLASS_ID, payments_getSavedInfo);
  ZRpcUtil::Register(mtproto::TL_payments_sendPaymentForm::CLASS_ID, payments_sendPaymentForm);
  ZRpcUtil::Register(mtproto::TL_payments_validateRequestedInfo::CLASS_ID, payments_validateRequestedInfo);
  ZRpcUtil::Register(mtproto::TL_phone_acceptCall::CLASS_ID, phone_acceptCall);
  ZRpcUtil::Register(mtproto::TL_phone_confirmCall::CLASS_ID, phone_confirmCall);
  ZRpcUtil::Register(mtproto::TL_phone_discardCall::CLASS_ID, phone_discardCall);
  ZRpcUtil::Register(mtproto::TL_phone_getCallConfig::CLASS_ID, phone_getCallConfig);
  ZRpcUtil::Register(mtproto::TL_phone_receivedCall::CLASS_ID, phone_receivedCall);
  ZRpcUtil::Register(mtproto::TL_phone_requestCall::CLASS_ID, phone_requestCall);
  ZRpcUtil::Register(mtproto::TL_phone_saveCallDebug::CLASS_ID, phone_saveCallDebug);
  ZRpcUtil::Register(mtproto::TL_phone_setCallRating::CLASS_ID, phone_setCallRating);
  ZRpcUtil::Register(mtproto::TL_photos_deletePhotos::CLASS_ID, photos_deletePhotos);
  ZRpcUtil::Register(mtproto::TL_photos_getUserPhotos::CLASS_ID, photos_getUserPhotos);
  ZRpcUtil::Register(mtproto::TL_photos_updateProfilePhoto::CLASS_ID, photos_updateProfilePhoto);
  ZRpcUtil::Register(mtproto::TL_photos_uploadProfilePhoto::CLASS_ID, photos_uploadProfilePhoto);
  ZRpcUtil::Register(mtproto::TL_updates_getChannelDifference::CLASS_ID, updates_getChannelDifference);
  ZRpcUtil::Register(mtproto::TL_updates_getDifference::CLASS_ID, updates_getDifference);
  ZRpcUtil::Register(mtproto::TL_updates_getState::CLASS_ID, updates_getState);
  ZRpcUtil::Register(mtproto::TL_upload_getCdnFile::CLASS_ID, upload_getCdnFile);
  ZRpcUtil::Register(mtproto::TL_upload_getFile::CLASS_ID, upload_getFile);
  ZRpcUtil::Register(mtproto::TL_upload_getWebFile::CLASS_ID, upload_getWebFile);
  ZRpcUtil::Register(mtproto::TL_upload_reuploadCdnFile::CLASS_ID, upload_reuploadCdnFile);
  ZRpcUtil::Register(mtproto::TL_upload_saveBigFilePart::CLASS_ID, upload_saveBigFilePart);
  ZRpcUtil::Register(mtproto::TL_upload_saveFilePart::CLASS_ID, upload_saveFilePart);
  ZRpcUtil::Register(mtproto::TL_users_getFullUser::CLASS_ID, users_getFullUser);
  ZRpcUtil::Register(mtproto::TL_users_getUsers::CLASS_ID, users_getUsers);
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_changePhone(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_changePhone, req);
  LOG(INFO) << "account_changePhone - req: " << req.ToString();

  std::shared_ptr<mtproto::User> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_changePhone(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_checkUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_checkUsername, req);
  LOG(INFO) << "account_checkUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_checkUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_confirmPhone(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_confirmPhone, req);
  LOG(INFO) << "account_confirmPhone - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_confirmPhone(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_deleteAccount(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_deleteAccount, req);
  LOG(INFO) << "account_deleteAccount - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_deleteAccount(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getAccountTTL(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getAccountTTL, req);
  LOG(INFO) << "account_getAccountTTL - req: " << req.ToString();

  std::shared_ptr<mtproto::AccountDaysTTL> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_getAccountTTL(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getAuthorizations(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getAuthorizations, req);
  LOG(INFO) << "account_getAuthorizations - req: " << req.ToString();

  std::shared_ptr<mtproto::account_Authorizations> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_getAuthorizations(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getNotifySettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getNotifySettings, req);
  LOG(INFO) << "account_getNotifySettings - req: " << req.ToString();

  std::shared_ptr<mtproto::PeerNotifySettings> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_getNotifySettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getPassword(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getPassword, req);
  LOG(INFO) << "account_getPassword - req: " << req.ToString();

  std::shared_ptr<mtproto::account_Password> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_getPassword(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getPasswordSettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getPasswordSettings, req);
  LOG(INFO) << "account_getPasswordSettings - req: " << req.ToString();

  std::shared_ptr<mtproto::account_PasswordSettings> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_getPasswordSettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getPrivacy(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getPrivacy, req);
  LOG(INFO) << "account_getPrivacy - req: " << req.ToString();

  std::shared_ptr<mtproto::account_PrivacyRules> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_getPrivacy(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getTmpPassword(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getTmpPassword, req);
  LOG(INFO) << "account_getTmpPassword - req: " << req.ToString();

  std::shared_ptr<mtproto::account_TmpPassword> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_getTmpPassword(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_getWallPapers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_getWallPapers, req);
  LOG(INFO) << "account_getWallPapers - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<WallPaper>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_getWallPapers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_registerDevice(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_registerDevice, req);
  LOG(INFO) << "account_registerDevice - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_registerDevice(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_reportPeer(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_reportPeer, req);
  LOG(INFO) << "account_reportPeer - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_reportPeer(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_resetAuthorization(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_resetAuthorization, req);
  LOG(INFO) << "account_resetAuthorization - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_resetAuthorization(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_resetNotifySettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_resetNotifySettings, req);
  LOG(INFO) << "account_resetNotifySettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_resetNotifySettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_sendChangePhoneCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_sendChangePhoneCode, req);
  LOG(INFO) << "account_sendChangePhoneCode - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_SentCode> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_sendChangePhoneCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_sendConfirmPhoneCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_sendConfirmPhoneCode, req);
  LOG(INFO) << "account_sendConfirmPhoneCode - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_SentCode> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_sendConfirmPhoneCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_setAccountTTL(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_setAccountTTL, req);
  LOG(INFO) << "account_setAccountTTL - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_setAccountTTL(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_setPrivacy(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_setPrivacy, req);
  LOG(INFO) << "account_setPrivacy - req: " << req.ToString();

  std::shared_ptr<mtproto::account_PrivacyRules> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_setPrivacy(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_unregisterDevice(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_unregisterDevice, req);
  LOG(INFO) << "account_unregisterDevice - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_unregisterDevice(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateDeviceLocked(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateDeviceLocked, req);
  LOG(INFO) << "account_updateDeviceLocked - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_updateDeviceLocked(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateNotifySettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateNotifySettings, req);
  LOG(INFO) << "account_updateNotifySettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_updateNotifySettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updatePasswordSettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updatePasswordSettings, req);
  LOG(INFO) << "account_updatePasswordSettings - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_updatePasswordSettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateProfile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateProfile, req);
  LOG(INFO) << "account_updateProfile - req: " << req.ToString();

  std::shared_ptr<mtproto::User> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_updateProfile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateStatus(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateStatus, req);
  LOG(INFO) << "account_updateStatus - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_updateStatus(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::account_updateUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_account_updateUsername, req);
  LOG(INFO) << "account_updateUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::User> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.account_updateUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_bindTempAuthKey(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_bindTempAuthKey, req);
  LOG(INFO) << "auth_bindTempAuthKey - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_bindTempAuthKey(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_cancelCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_cancelCode, req);
  LOG(INFO) << "auth_cancelCode - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_cancelCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_checkPassword(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_checkPassword, req);
  LOG(INFO) << "auth_checkPassword - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_Authorization> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_checkPassword(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_checkPhone(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_checkPhone, req);
  LOG(INFO) << "auth_checkPhone - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_CheckedPhone> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_checkPhone(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_dropTempAuthKeys(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_dropTempAuthKeys, req);
  LOG(INFO) << "auth_dropTempAuthKeys - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_dropTempAuthKeys(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_exportAuthorization(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_exportAuthorization, req);
  LOG(INFO) << "auth_exportAuthorization - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_ExportedAuthorization> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_exportAuthorization(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_importAuthorization(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_importAuthorization, req);
  LOG(INFO) << "auth_importAuthorization - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_Authorization> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_importAuthorization(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_importBotAuthorization(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_importBotAuthorization, req);
  LOG(INFO) << "auth_importBotAuthorization - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_Authorization> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_importBotAuthorization(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_logOut(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_logOut, req);
  LOG(INFO) << "auth_logOut - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_logOut(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_recoverPassword(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_recoverPassword, req);
  LOG(INFO) << "auth_recoverPassword - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_Authorization> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_recoverPassword(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_requestPasswordRecovery(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_requestPasswordRecovery, req);
  LOG(INFO) << "auth_requestPasswordRecovery - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_PasswordRecovery> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_requestPasswordRecovery(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_resendCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_resendCode, req);
  LOG(INFO) << "auth_resendCode - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_SentCode> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_resendCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_resetAuthorizations(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_resetAuthorizations, req);
  LOG(INFO) << "auth_resetAuthorizations - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_resetAuthorizations(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_sendCode(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_sendCode, req);
  LOG(INFO) << "auth_sendCode - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_SentCode> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_sendCode(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_sendInvites(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_sendInvites, req);
  LOG(INFO) << "auth_sendInvites - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_sendInvites(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_signIn(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_signIn, req);
  LOG(INFO) << "auth_signIn - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_Authorization> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_signIn(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::auth_signUp(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_auth_signUp, req);
  LOG(INFO) << "auth_signUp - req: " << req.ToString();

  std::shared_ptr<mtproto::auth_Authorization> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.auth_signUp(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::bots_answerWebhookJSONQuery(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_bots_answerWebhookJSONQuery, req);
  LOG(INFO) << "bots_answerWebhookJSONQuery - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.bots_answerWebhookJSONQuery(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::bots_sendCustomRequest(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_bots_sendCustomRequest, req);
  LOG(INFO) << "bots_sendCustomRequest - req: " << req.ToString();

  std::shared_ptr<mtproto::DataJSON> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.bots_sendCustomRequest(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_checkUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_checkUsername, req);
  LOG(INFO) << "channels_checkUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_checkUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_createChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_createChannel, req);
  LOG(INFO) << "channels_createChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_createChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_deleteChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_deleteChannel, req);
  LOG(INFO) << "channels_deleteChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_deleteChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_deleteMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_deleteMessages, req);
  LOG(INFO) << "channels_deleteMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_AffectedMessages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_deleteMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_deleteUserHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_deleteUserHistory, req);
  LOG(INFO) << "channels_deleteUserHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_AffectedHistory> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_deleteUserHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_editAbout(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_editAbout, req);
  LOG(INFO) << "channels_editAbout - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_editAbout(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_editAdmin(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_editAdmin, req);
  LOG(INFO) << "channels_editAdmin - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_editAdmin(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_editPhoto(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_editPhoto, req);
  LOG(INFO) << "channels_editPhoto - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_editPhoto(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_editTitle(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_editTitle, req);
  LOG(INFO) << "channels_editTitle - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_editTitle(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_exportInvite(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_exportInvite, req);
  LOG(INFO) << "channels_exportInvite - req: " << req.ToString();

  std::shared_ptr<mtproto::ExportedChatInvite> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_exportInvite(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_exportMessageLink(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_exportMessageLink, req);
  LOG(INFO) << "channels_exportMessageLink - req: " << req.ToString();

  std::shared_ptr<mtproto::ExportedMessageLink> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_exportMessageLink(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getAdminedPublicChannels(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getAdminedPublicChannels, req);
  LOG(INFO) << "channels_getAdminedPublicChannels - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Chats> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_getAdminedPublicChannels(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getChannels(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getChannels, req);
  LOG(INFO) << "channels_getChannels - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Chats> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_getChannels(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getFullChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getFullChannel, req);
  LOG(INFO) << "channels_getFullChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_ChatFull> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_getFullChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getMessages, req);
  LOG(INFO) << "channels_getMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Messages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_getMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getParticipant(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getParticipant, req);
  LOG(INFO) << "channels_getParticipant - req: " << req.ToString();

  std::shared_ptr<mtproto::channels_ChannelParticipant> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_getParticipant(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_getParticipants(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_getParticipants, req);
  LOG(INFO) << "channels_getParticipants - req: " << req.ToString();

  std::shared_ptr<mtproto::channels_ChannelParticipants> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_getParticipants(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_inviteToChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_inviteToChannel, req);
  LOG(INFO) << "channels_inviteToChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_inviteToChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_joinChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_joinChannel, req);
  LOG(INFO) << "channels_joinChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_joinChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_kickFromChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_kickFromChannel, req);
  LOG(INFO) << "channels_kickFromChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_kickFromChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_leaveChannel(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_leaveChannel, req);
  LOG(INFO) << "channels_leaveChannel - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_leaveChannel(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_readHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_readHistory, req);
  LOG(INFO) << "channels_readHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_readHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_reportSpam(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_reportSpam, req);
  LOG(INFO) << "channels_reportSpam - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_reportSpam(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_toggleInvites(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_toggleInvites, req);
  LOG(INFO) << "channels_toggleInvites - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_toggleInvites(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_toggleSignatures(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_toggleSignatures, req);
  LOG(INFO) << "channels_toggleSignatures - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_toggleSignatures(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_updatePinnedMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_updatePinnedMessage, req);
  LOG(INFO) << "channels_updatePinnedMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_updatePinnedMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::channels_updateUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_channels_updateUsername, req);
  LOG(INFO) << "channels_updateUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.channels_updateUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_block(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_block, req);
  LOG(INFO) << "contacts_block - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_block(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_deleteContact(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_deleteContact, req);
  LOG(INFO) << "contacts_deleteContact - req: " << req.ToString();

  std::shared_ptr<mtproto::contacts_Link> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_deleteContact(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_deleteContacts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_deleteContacts, req);
  LOG(INFO) << "contacts_deleteContacts - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_deleteContacts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_exportCard(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_exportCard, req);
  LOG(INFO) << "contacts_exportCard - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<int32_t>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_exportCard(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_getBlocked(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_getBlocked, req);
  LOG(INFO) << "contacts_getBlocked - req: " << req.ToString();

  std::shared_ptr<mtproto::contacts_Blocked> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_getBlocked(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_getContacts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_getContacts, req);
  LOG(INFO) << "contacts_getContacts - req: " << req.ToString();

  std::shared_ptr<mtproto::contacts_Contacts> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_getContacts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_getStatuses(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_getStatuses, req);
  LOG(INFO) << "contacts_getStatuses - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<ContactStatus>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_getStatuses(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_getTopPeers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_getTopPeers, req);
  LOG(INFO) << "contacts_getTopPeers - req: " << req.ToString();

  std::shared_ptr<mtproto::contacts_TopPeers> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_getTopPeers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_importCard(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_importCard, req);
  LOG(INFO) << "contacts_importCard - req: " << req.ToString();

  std::shared_ptr<mtproto::User> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_importCard(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_importContacts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_importContacts, req);
  LOG(INFO) << "contacts_importContacts - req: " << req.ToString();

  std::shared_ptr<mtproto::contacts_ImportedContacts> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_importContacts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_resetTopPeerRating(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_resetTopPeerRating, req);
  LOG(INFO) << "contacts_resetTopPeerRating - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_resetTopPeerRating(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_resolveUsername(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_resolveUsername, req);
  LOG(INFO) << "contacts_resolveUsername - req: " << req.ToString();

  std::shared_ptr<mtproto::contacts_ResolvedPeer> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_resolveUsername(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_search(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_search, req);
  LOG(INFO) << "contacts_search - req: " << req.ToString();

  std::shared_ptr<mtproto::contacts_Found> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_search(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::contacts_unblock(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_contacts_unblock, req);
  LOG(INFO) << "contacts_unblock - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.contacts_unblock(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getAppChangelog(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getAppChangelog, req);
  LOG(INFO) << "help_getAppChangelog - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_getAppChangelog(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getAppUpdate(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getAppUpdate, req);
  LOG(INFO) << "help_getAppUpdate - req: " << req.ToString();

  std::shared_ptr<mtproto::help_AppUpdate> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_getAppUpdate(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getCdnConfig(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getCdnConfig, req);
  LOG(INFO) << "help_getCdnConfig - req: " << req.ToString();

  std::shared_ptr<mtproto::CdnConfig> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_getCdnConfig(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getConfig(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getConfig, req);
  LOG(INFO) << "help_getConfig - req: " << req.ToString();

  std::shared_ptr<mtproto::Config> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_getConfig(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getInviteText(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getInviteText, req);
  LOG(INFO) << "help_getInviteText - req: " << req.ToString();

  std::shared_ptr<mtproto::help_InviteText> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_getInviteText(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getNearestDc(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getNearestDc, req);
  LOG(INFO) << "help_getNearestDc - req: " << req.ToString();

  std::shared_ptr<mtproto::NearestDc> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_getNearestDc(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getSupport(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getSupport, req);
  LOG(INFO) << "help_getSupport - req: " << req.ToString();

  std::shared_ptr<mtproto::help_Support> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_getSupport(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_getTermsOfService(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_getTermsOfService, req);
  LOG(INFO) << "help_getTermsOfService - req: " << req.ToString();

  std::shared_ptr<mtproto::help_TermsOfService> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_getTermsOfService(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_saveAppLog(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_saveAppLog, req);
  LOG(INFO) << "help_saveAppLog - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_saveAppLog(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::help_setBotUpdatesStatus(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_help_setBotUpdatesStatus, req);
  LOG(INFO) << "help_setBotUpdatesStatus - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.help_setBotUpdatesStatus(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_acceptEncryption(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_acceptEncryption, req);
  LOG(INFO) << "messages_acceptEncryption - req: " << req.ToString();

  std::shared_ptr<mtproto::EncryptedChat> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_acceptEncryption(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_addChatUser(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_addChatUser, req);
  LOG(INFO) << "messages_addChatUser - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_addChatUser(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_checkChatInvite(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_checkChatInvite, req);
  LOG(INFO) << "messages_checkChatInvite - req: " << req.ToString();

  std::shared_ptr<mtproto::ChatInvite> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_checkChatInvite(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_clearRecentStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_clearRecentStickers, req);
  LOG(INFO) << "messages_clearRecentStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_clearRecentStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_createChat(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_createChat, req);
  LOG(INFO) << "messages_createChat - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_createChat(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_deleteChatUser(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_deleteChatUser, req);
  LOG(INFO) << "messages_deleteChatUser - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_deleteChatUser(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_deleteHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_deleteHistory, req);
  LOG(INFO) << "messages_deleteHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_AffectedHistory> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_deleteHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_deleteMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_deleteMessages, req);
  LOG(INFO) << "messages_deleteMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_AffectedMessages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_deleteMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_discardEncryption(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_discardEncryption, req);
  LOG(INFO) << "messages_discardEncryption - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_discardEncryption(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editChatAdmin(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editChatAdmin, req);
  LOG(INFO) << "messages_editChatAdmin - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_editChatAdmin(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editChatPhoto(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editChatPhoto, req);
  LOG(INFO) << "messages_editChatPhoto - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_editChatPhoto(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editChatTitle(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editChatTitle, req);
  LOG(INFO) << "messages_editChatTitle - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_editChatTitle(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editInlineBotMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editInlineBotMessage, req);
  LOG(INFO) << "messages_editInlineBotMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_editInlineBotMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_editMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_editMessage, req);
  LOG(INFO) << "messages_editMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_editMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_exportChatInvite(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_exportChatInvite, req);
  LOG(INFO) << "messages_exportChatInvite - req: " << req.ToString();

  std::shared_ptr<mtproto::ExportedChatInvite> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_exportChatInvite(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_forwardMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_forwardMessage, req);
  LOG(INFO) << "messages_forwardMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_forwardMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_forwardMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_forwardMessages, req);
  LOG(INFO) << "messages_forwardMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_forwardMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getAllChats(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getAllChats, req);
  LOG(INFO) << "messages_getAllChats - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Chats> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getAllChats(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getAllDrafts(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getAllDrafts, req);
  LOG(INFO) << "messages_getAllDrafts - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getAllDrafts(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getAllStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getAllStickers, req);
  LOG(INFO) << "messages_getAllStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_AllStickers> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getAllStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getArchivedStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getArchivedStickers, req);
  LOG(INFO) << "messages_getArchivedStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_ArchivedStickers> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getArchivedStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getAttachedStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getAttachedStickers, req);
  LOG(INFO) << "messages_getAttachedStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<StickerSetCovered>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getAttachedStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getBotCallbackAnswer(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getBotCallbackAnswer, req);
  LOG(INFO) << "messages_getBotCallbackAnswer - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_BotCallbackAnswer> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getBotCallbackAnswer(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getChats(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getChats, req);
  LOG(INFO) << "messages_getChats - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Chats> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getChats(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getCommonChats(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getCommonChats, req);
  LOG(INFO) << "messages_getCommonChats - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Chats> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getCommonChats(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getDhConfig(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getDhConfig, req);
  LOG(INFO) << "messages_getDhConfig - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_DhConfig> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getDhConfig(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getDialogs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getDialogs, req);
  LOG(INFO) << "messages_getDialogs - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Dialogs> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getDialogs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getDocumentByHash(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getDocumentByHash, req);
  LOG(INFO) << "messages_getDocumentByHash - req: " << req.ToString();

  std::shared_ptr<mtproto::Document> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getDocumentByHash(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getFeaturedStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getFeaturedStickers, req);
  LOG(INFO) << "messages_getFeaturedStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_FeaturedStickers> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getFeaturedStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getFullChat(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getFullChat, req);
  LOG(INFO) << "messages_getFullChat - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_ChatFull> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getFullChat(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getGameHighScores(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getGameHighScores, req);
  LOG(INFO) << "messages_getGameHighScores - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_HighScores> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getGameHighScores(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getHistory, req);
  LOG(INFO) << "messages_getHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Messages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getInlineBotResults(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getInlineBotResults, req);
  LOG(INFO) << "messages_getInlineBotResults - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_BotResults> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getInlineBotResults(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getInlineGameHighScores(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getInlineGameHighScores, req);
  LOG(INFO) << "messages_getInlineGameHighScores - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_HighScores> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getInlineGameHighScores(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getMaskStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getMaskStickers, req);
  LOG(INFO) << "messages_getMaskStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_AllStickers> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getMaskStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getMessageEditData(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getMessageEditData, req);
  LOG(INFO) << "messages_getMessageEditData - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_MessageEditData> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getMessageEditData(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getMessages, req);
  LOG(INFO) << "messages_getMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Messages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getMessagesViews(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getMessagesViews, req);
  LOG(INFO) << "messages_getMessagesViews - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<int32_t>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getMessagesViews(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getPeerDialogs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getPeerDialogs, req);
  LOG(INFO) << "messages_getPeerDialogs - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_PeerDialogs> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getPeerDialogs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getPeerSettings(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getPeerSettings, req);
  LOG(INFO) << "messages_getPeerSettings - req: " << req.ToString();

  std::shared_ptr<mtproto::PeerSettings> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getPeerSettings(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getPinnedDialogs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getPinnedDialogs, req);
  LOG(INFO) << "messages_getPinnedDialogs - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_PeerDialogs> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getPinnedDialogs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getRecentStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getRecentStickers, req);
  LOG(INFO) << "messages_getRecentStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_RecentStickers> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getRecentStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getSavedGifs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getSavedGifs, req);
  LOG(INFO) << "messages_getSavedGifs - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_SavedGifs> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getSavedGifs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getStickerSet(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getStickerSet, req);
  LOG(INFO) << "messages_getStickerSet - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_StickerSet> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getStickerSet(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getWebPage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getWebPage, req);
  LOG(INFO) << "messages_getWebPage - req: " << req.ToString();

  std::shared_ptr<mtproto::WebPage> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getWebPage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_getWebPagePreview(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_getWebPagePreview, req);
  LOG(INFO) << "messages_getWebPagePreview - req: " << req.ToString();

  std::shared_ptr<mtproto::MessageMedia> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_getWebPagePreview(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_hideReportSpam(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_hideReportSpam, req);
  LOG(INFO) << "messages_hideReportSpam - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_hideReportSpam(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_importChatInvite(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_importChatInvite, req);
  LOG(INFO) << "messages_importChatInvite - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_importChatInvite(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_installStickerSet(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_installStickerSet, req);
  LOG(INFO) << "messages_installStickerSet - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_StickerSetInstallResult> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_installStickerSet(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_migrateChat(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_migrateChat, req);
  LOG(INFO) << "messages_migrateChat - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_migrateChat(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_readEncryptedHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_readEncryptedHistory, req);
  LOG(INFO) << "messages_readEncryptedHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_readEncryptedHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_readFeaturedStickers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_readFeaturedStickers, req);
  LOG(INFO) << "messages_readFeaturedStickers - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_readFeaturedStickers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_readHistory(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_readHistory, req);
  LOG(INFO) << "messages_readHistory - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_AffectedMessages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_readHistory(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_readMessageContents(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_readMessageContents, req);
  LOG(INFO) << "messages_readMessageContents - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_AffectedMessages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_readMessageContents(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_receivedMessages(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_receivedMessages, req);
  LOG(INFO) << "messages_receivedMessages - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<ReceivedNotifyMessage>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_receivedMessages(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_receivedQueue(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_receivedQueue, req);
  LOG(INFO) << "messages_receivedQueue - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<int64_t>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_receivedQueue(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_reorderPinnedDialogs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_reorderPinnedDialogs, req);
  LOG(INFO) << "messages_reorderPinnedDialogs - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_reorderPinnedDialogs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_reorderStickerSets(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_reorderStickerSets, req);
  LOG(INFO) << "messages_reorderStickerSets - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_reorderStickerSets(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_reportEncryptedSpam(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_reportEncryptedSpam, req);
  LOG(INFO) << "messages_reportEncryptedSpam - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_reportEncryptedSpam(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_reportSpam(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_reportSpam, req);
  LOG(INFO) << "messages_reportSpam - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_reportSpam(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_requestEncryption(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_requestEncryption, req);
  LOG(INFO) << "messages_requestEncryption - req: " << req.ToString();

  std::shared_ptr<mtproto::EncryptedChat> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_requestEncryption(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_saveDraft(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_saveDraft, req);
  LOG(INFO) << "messages_saveDraft - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_saveDraft(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_saveGif(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_saveGif, req);
  LOG(INFO) << "messages_saveGif - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_saveGif(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_saveRecentSticker(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_saveRecentSticker, req);
  LOG(INFO) << "messages_saveRecentSticker - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_saveRecentSticker(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_search(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_search, req);
  LOG(INFO) << "messages_search - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Messages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_search(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_searchGifs(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_searchGifs, req);
  LOG(INFO) << "messages_searchGifs - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_FoundGifs> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_searchGifs(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_searchGlobal(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_searchGlobal, req);
  LOG(INFO) << "messages_searchGlobal - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_Messages> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_searchGlobal(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendEncrypted(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendEncrypted, req);
  LOG(INFO) << "messages_sendEncrypted - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_SentEncryptedMessage> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_sendEncrypted(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendEncryptedFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendEncryptedFile, req);
  LOG(INFO) << "messages_sendEncryptedFile - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_SentEncryptedMessage> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_sendEncryptedFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendEncryptedService(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendEncryptedService, req);
  LOG(INFO) << "messages_sendEncryptedService - req: " << req.ToString();

  std::shared_ptr<mtproto::messages_SentEncryptedMessage> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_sendEncryptedService(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendInlineBotResult(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendInlineBotResult, req);
  LOG(INFO) << "messages_sendInlineBotResult - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_sendInlineBotResult(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendMedia(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendMedia, req);
  LOG(INFO) << "messages_sendMedia - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_sendMedia(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_sendMessage(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_sendMessage, req);
  LOG(INFO) << "messages_sendMessage - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_sendMessage(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setBotCallbackAnswer(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setBotCallbackAnswer, req);
  LOG(INFO) << "messages_setBotCallbackAnswer - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_setBotCallbackAnswer(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setBotPrecheckoutResults(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setBotPrecheckoutResults, req);
  LOG(INFO) << "messages_setBotPrecheckoutResults - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_setBotPrecheckoutResults(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setBotShippingResults(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setBotShippingResults, req);
  LOG(INFO) << "messages_setBotShippingResults - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_setBotShippingResults(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setEncryptedTyping(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setEncryptedTyping, req);
  LOG(INFO) << "messages_setEncryptedTyping - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_setEncryptedTyping(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setGameScore(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setGameScore, req);
  LOG(INFO) << "messages_setGameScore - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_setGameScore(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setInlineBotResults(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setInlineBotResults, req);
  LOG(INFO) << "messages_setInlineBotResults - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_setInlineBotResults(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setInlineGameScore(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setInlineGameScore, req);
  LOG(INFO) << "messages_setInlineGameScore - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_setInlineGameScore(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_setTyping(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_setTyping, req);
  LOG(INFO) << "messages_setTyping - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_setTyping(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_startBot(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_startBot, req);
  LOG(INFO) << "messages_startBot - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_startBot(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_toggleChatAdmins(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_toggleChatAdmins, req);
  LOG(INFO) << "messages_toggleChatAdmins - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_toggleChatAdmins(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_toggleDialogPin(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_toggleDialogPin, req);
  LOG(INFO) << "messages_toggleDialogPin - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_toggleDialogPin(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::messages_uninstallStickerSet(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_messages_uninstallStickerSet, req);
  LOG(INFO) << "messages_uninstallStickerSet - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.messages_uninstallStickerSet(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_clearSavedInfo(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_clearSavedInfo, req);
  LOG(INFO) << "payments_clearSavedInfo - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.payments_clearSavedInfo(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_getPaymentForm(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_getPaymentForm, req);
  LOG(INFO) << "payments_getPaymentForm - req: " << req.ToString();

  std::shared_ptr<mtproto::payments_PaymentForm> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.payments_getPaymentForm(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_getPaymentReceipt(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_getPaymentReceipt, req);
  LOG(INFO) << "payments_getPaymentReceipt - req: " << req.ToString();

  std::shared_ptr<mtproto::payments_PaymentReceipt> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.payments_getPaymentReceipt(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_getSavedInfo(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_getSavedInfo, req);
  LOG(INFO) << "payments_getSavedInfo - req: " << req.ToString();

  std::shared_ptr<mtproto::payments_SavedInfo> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.payments_getSavedInfo(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_sendPaymentForm(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_sendPaymentForm, req);
  LOG(INFO) << "payments_sendPaymentForm - req: " << req.ToString();

  std::shared_ptr<mtproto::payments_PaymentResult> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.payments_sendPaymentForm(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::payments_validateRequestedInfo(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_payments_validateRequestedInfo, req);
  LOG(INFO) << "payments_validateRequestedInfo - req: " << req.ToString();

  std::shared_ptr<mtproto::payments_ValidatedRequestedInfo> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.payments_validateRequestedInfo(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_acceptCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_acceptCall, req);
  LOG(INFO) << "phone_acceptCall - req: " << req.ToString();

  std::shared_ptr<mtproto::phone_PhoneCall> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.phone_acceptCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_confirmCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_confirmCall, req);
  LOG(INFO) << "phone_confirmCall - req: " << req.ToString();

  std::shared_ptr<mtproto::phone_PhoneCall> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.phone_confirmCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_discardCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_discardCall, req);
  LOG(INFO) << "phone_discardCall - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.phone_discardCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_getCallConfig(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_getCallConfig, req);
  LOG(INFO) << "phone_getCallConfig - req: " << req.ToString();

  std::shared_ptr<mtproto::DataJSON> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.phone_getCallConfig(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_receivedCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_receivedCall, req);
  LOG(INFO) << "phone_receivedCall - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.phone_receivedCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_requestCall(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_requestCall, req);
  LOG(INFO) << "phone_requestCall - req: " << req.ToString();

  std::shared_ptr<mtproto::phone_PhoneCall> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.phone_requestCall(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_saveCallDebug(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_saveCallDebug, req);
  LOG(INFO) << "phone_saveCallDebug - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.phone_saveCallDebug(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::phone_setCallRating(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_phone_setCallRating, req);
  LOG(INFO) << "phone_setCallRating - req: " << req.ToString();

  std::shared_ptr<mtproto::Updates> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.phone_setCallRating(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::photos_deletePhotos(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_photos_deletePhotos, req);
  LOG(INFO) << "photos_deletePhotos - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<int64_t>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.photos_deletePhotos(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::photos_getUserPhotos(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_photos_getUserPhotos, req);
  LOG(INFO) << "photos_getUserPhotos - req: " << req.ToString();

  std::shared_ptr<mtproto::photos_Photos> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.photos_getUserPhotos(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::photos_updateProfilePhoto(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_photos_updateProfilePhoto, req);
  LOG(INFO) << "photos_updateProfilePhoto - req: " << req.ToString();

  std::shared_ptr<mtproto::UserProfilePhoto> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.photos_updateProfilePhoto(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::photos_uploadProfilePhoto(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_photos_uploadProfilePhoto, req);
  LOG(INFO) << "photos_uploadProfilePhoto - req: " << req.ToString();

  std::shared_ptr<mtproto::photos_Photo> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.photos_uploadProfilePhoto(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::updates_getChannelDifference(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_updates_getChannelDifference, req);
  LOG(INFO) << "updates_getChannelDifference - req: " << req.ToString();

  std::shared_ptr<mtproto::updates_ChannelDifference> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.updates_getChannelDifference(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::updates_getDifference(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_updates_getDifference, req);
  LOG(INFO) << "updates_getDifference - req: " << req.ToString();

  std::shared_ptr<mtproto::updates_Difference> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.updates_getDifference(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::updates_getState(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_updates_getState, req);
  LOG(INFO) << "updates_getState - req: " << req.ToString();

  std::shared_ptr<mtproto::updates_State> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.updates_getState(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_getCdnFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_getCdnFile, req);
  LOG(INFO) << "upload_getCdnFile - req: " << req.ToString();

  std::shared_ptr<mtproto::upload_CdnFile> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.upload_getCdnFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_getFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_getFile, req);
  LOG(INFO) << "upload_getFile - req: " << req.ToString();

  std::shared_ptr<mtproto::upload_File> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.upload_getFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_getWebFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_getWebFile, req);
  LOG(INFO) << "upload_getWebFile - req: " << req.ToString();

  std::shared_ptr<mtproto::upload_WebFile> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.upload_getWebFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_reuploadCdnFile(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_reuploadCdnFile, req);
  LOG(INFO) << "upload_reuploadCdnFile - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.upload_reuploadCdnFile(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_saveBigFilePart(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_saveBigFilePart, req);
  LOG(INFO) << "upload_saveBigFilePart - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.upload_saveBigFilePart(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::upload_saveFilePart(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_upload_saveFilePart, req);
  LOG(INFO) << "upload_saveFilePart - req: " << req.ToString();

  std::shared_ptr<mtproto::Bool> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.upload_saveFilePart(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::users_getFullUser(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_users_getFullUser, req);
  LOG(INFO) << "users_getFullUser - req: " << req.ToString();

  std::shared_ptr<mtproto::UserFull> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.users_getFullUser(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}

zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::users_getUsers(zproto::RpcRequestPtr request) {
  CAST_RPC_REQUEST(mtproto::TL_users_getUsers, req);
  LOG(INFO) << "users_getUsers - req: " << req.ToString();

  std::shared_ptr<mtproto::Vector<User>> rsp;
  AuthServiceImpl impl;
  impl.Initialize(request);
  impl.users_getUsers(req, rsp);
  return mtproto::MakeRpcOK(rsp.get());
}



