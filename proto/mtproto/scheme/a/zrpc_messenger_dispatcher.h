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

#ifndef TELEGRAM_CORE_SCHME_TL_H_
#define TELEGRAM_CORE_SCHME_TL_H_

#include "nebula/base/crypto_util/crypto_util.h"
#include "nebula/net/telegram/core/tl_object.h"
#include "nebula/net/telegram/core/tl_vector.h"
// Type forward declarations




static zproto::ProtoRpcResponsePtr account_changePhone(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_checkUsername(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_confirmPhone(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_deleteAccount(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_getAccountTTL(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_getAuthorizations(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_getNotifySettings(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_getPassword(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_getPasswordSettings(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_getPrivacy(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_getTmpPassword(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_getWallPapers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_registerDevice(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_reportPeer(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_resetAuthorization(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_resetNotifySettings(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_sendChangePhoneCode(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_sendConfirmPhoneCode(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_setAccountTTL(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_setPrivacy(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_unregisterDevice(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_updateDeviceLocked(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_updateNotifySettings(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_updatePasswordSettings(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_updateProfile(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_updateStatus(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr account_updateUsername(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_bindTempAuthKey(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_cancelCode(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_checkPassword(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_checkPhone(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_dropTempAuthKeys(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_exportAuthorization(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_importAuthorization(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_importBotAuthorization(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_logOut(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_recoverPassword(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_requestPasswordRecovery(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_resendCode(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_resetAuthorizations(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_sendCode(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_sendInvites(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_signIn(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr auth_signUp(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr bots_answerWebhookJSONQuery(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr bots_sendCustomRequest(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_checkUsername(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_createChannel(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_deleteChannel(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_deleteMessages(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_deleteUserHistory(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_editAbout(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_editAdmin(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_editPhoto(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_editTitle(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_exportInvite(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_exportMessageLink(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_getAdminedPublicChannels(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_getChannels(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_getFullChannel(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_getMessages(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_getParticipant(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_getParticipants(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_inviteToChannel(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_joinChannel(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_kickFromChannel(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_leaveChannel(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_readHistory(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_reportSpam(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_toggleInvites(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_toggleSignatures(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_updatePinnedMessage(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr channels_updateUsername(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_block(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_deleteContact(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_deleteContacts(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_exportCard(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_getBlocked(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_getContacts(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_getStatuses(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_getTopPeers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_importCard(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_importContacts(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_resetTopPeerRating(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_resolveUsername(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_search(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr contacts_unblock(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_getAppChangelog(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_getAppUpdate(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_getCdnConfig(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_getConfig(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_getInviteText(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_getNearestDc(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_getSupport(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_getTermsOfService(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_saveAppLog(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr help_setBotUpdatesStatus(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_acceptEncryption(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_addChatUser(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_checkChatInvite(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_clearRecentStickers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_createChat(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_deleteChatUser(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_deleteHistory(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_deleteMessages(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_discardEncryption(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_editChatAdmin(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_editChatPhoto(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_editChatTitle(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_editInlineBotMessage(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_editMessage(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_exportChatInvite(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_forwardMessage(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_forwardMessages(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getAllChats(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getAllDrafts(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getAllStickers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getArchivedStickers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getAttachedStickers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getBotCallbackAnswer(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getChats(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getCommonChats(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getDhConfig(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getDialogs(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getDocumentByHash(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getFeaturedStickers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getFullChat(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getGameHighScores(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getHistory(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getInlineBotResults(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getInlineGameHighScores(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getMaskStickers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getMessageEditData(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getMessages(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getMessagesViews(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getPeerDialogs(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getPeerSettings(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getPinnedDialogs(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getRecentStickers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getSavedGifs(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getStickerSet(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getWebPage(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_getWebPagePreview(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_hideReportSpam(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_importChatInvite(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_installStickerSet(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_migrateChat(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_readEncryptedHistory(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_readFeaturedStickers(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_readHistory(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_readMessageContents(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_receivedMessages(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_receivedQueue(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_reorderPinnedDialogs(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_reorderStickerSets(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_reportEncryptedSpam(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_reportSpam(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_requestEncryption(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_saveDraft(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_saveGif(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_saveRecentSticker(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_search(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_searchGifs(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_searchGlobal(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_sendEncrypted(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_sendEncryptedFile(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_sendEncryptedService(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_sendInlineBotResult(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_sendMedia(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_sendMessage(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_setBotCallbackAnswer(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_setBotPrecheckoutResults(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_setBotShippingResults(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_setEncryptedTyping(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_setGameScore(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_setInlineBotResults(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_setInlineGameScore(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_setTyping(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_startBot(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_toggleChatAdmins(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_toggleDialogPin(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr messages_uninstallStickerSet(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr payments_clearSavedInfo(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr payments_getPaymentForm(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr payments_getPaymentReceipt(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr payments_getSavedInfo(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr payments_sendPaymentForm(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr payments_validateRequestedInfo(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr phone_acceptCall(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr phone_confirmCall(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr phone_discardCall(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr phone_getCallConfig(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr phone_receivedCall(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr phone_requestCall(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr phone_saveCallDebug(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr phone_setCallRating(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr photos_deletePhotos(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr photos_getUserPhotos(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr photos_updateProfilePhoto(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr photos_uploadProfilePhoto(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr updates_getChannelDifference(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr updates_getDifference(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr updates_getState(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr upload_getCdnFile(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr upload_getFile(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr upload_getWebFile(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr upload_reuploadCdnFile(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr upload_saveBigFilePart(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr upload_saveFilePart(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr users_getFullUser(zproto::RpcRequestPtr request);
static zproto::ProtoRpcResponsePtr users_getUsers(zproto::RpcRequestPtr request);


#endif
