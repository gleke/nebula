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

REGISTER_TLOBJECT(TL_resPQ);
REGISTER_TLOBJECT(TL_p_q_inner_data);
REGISTER_TLOBJECT(TL_server_DH_params_fail);
REGISTER_TLOBJECT(TL_server_DH_params_ok);
REGISTER_TLOBJECT(TL_server_DH_inner_data);
REGISTER_TLOBJECT(TL_client_DH_inner_data);
REGISTER_TLOBJECT(TL_dh_gen_ok);
REGISTER_TLOBJECT(TL_dh_gen_retry);
REGISTER_TLOBJECT(TL_dh_gen_fail);
REGISTER_TLOBJECT(TL_destroy_auth_key_ok);
REGISTER_TLOBJECT(TL_destroy_auth_key_none);
REGISTER_TLOBJECT(TL_destroy_auth_key_fail);
REGISTER_TLOBJECT(TL_req_pq);
REGISTER_TLOBJECT(TL_req_DH_params);
REGISTER_TLOBJECT(TL_set_client_DH_params);
REGISTER_TLOBJECT(TL_destroy_auth_key);
REGISTER_TLOBJECT(TL_msgs_ack);
REGISTER_TLOBJECT(TL_bad_msg_notification);
REGISTER_TLOBJECT(TL_bad_server_salt);
REGISTER_TLOBJECT(TL_msgs_state_req);
REGISTER_TLOBJECT(TL_msgs_state_info);
REGISTER_TLOBJECT(TL_msgs_all_info);
REGISTER_TLOBJECT(TL_msg_detailed_info);
REGISTER_TLOBJECT(TL_msg_new_detailed_info);
REGISTER_TLOBJECT(TL_msg_resend_req);
REGISTER_TLOBJECT(TL_rpc_error);
REGISTER_TLOBJECT(TL_rpc_answer_unknown);
REGISTER_TLOBJECT(TL_rpc_answer_dropped_running);
REGISTER_TLOBJECT(TL_rpc_answer_dropped);
REGISTER_TLOBJECT(TL_future_salt);
REGISTER_TLOBJECT(TL_future_salts);
REGISTER_TLOBJECT(TL_pong);
REGISTER_TLOBJECT(TL_destroy_session_ok);
REGISTER_TLOBJECT(TL_destroy_session_none);
REGISTER_TLOBJECT(TL_new_session_created);
REGISTER_TLOBJECT(TL_http_wait);
REGISTER_TLOBJECT(TL_rpc_drop_answer);
REGISTER_TLOBJECT(TL_get_future_salts);
REGISTER_TLOBJECT(TL_ping);
REGISTER_TLOBJECT(TL_ping_delay_disconnect);
REGISTER_TLOBJECT(TL_destroy_session);
REGISTER_TLOBJECT(TL_contest_saveDeveloperInfo);
REGISTER_TLOBJECT(TL_boolFalse);
REGISTER_TLOBJECT(TL_boolTrue);
REGISTER_TLOBJECT(TL_true);
REGISTER_TLOBJECT(TL_error);
REGISTER_TLOBJECT(TL_null);
REGISTER_TLOBJECT(TL_inputPeerEmpty);
REGISTER_TLOBJECT(TL_inputPeerSelf);
REGISTER_TLOBJECT(TL_inputPeerChat);
REGISTER_TLOBJECT(TL_inputPeerUser);
REGISTER_TLOBJECT(TL_inputPeerChannel);
REGISTER_TLOBJECT(TL_inputUserEmpty);
REGISTER_TLOBJECT(TL_inputUserSelf);
REGISTER_TLOBJECT(TL_inputUser);
REGISTER_TLOBJECT(TL_inputPhoneContact);
REGISTER_TLOBJECT(TL_inputFile);
REGISTER_TLOBJECT(TL_inputFileBig);
REGISTER_TLOBJECT(TL_inputMediaEmpty);
REGISTER_TLOBJECT(TL_inputMediaUploadedPhoto);
REGISTER_TLOBJECT(TL_inputMediaPhoto);
REGISTER_TLOBJECT(TL_inputMediaGeoPoint);
REGISTER_TLOBJECT(TL_inputMediaContact);
REGISTER_TLOBJECT(TL_inputMediaUploadedDocument);
REGISTER_TLOBJECT(TL_inputMediaUploadedThumbDocument);
REGISTER_TLOBJECT(TL_inputMediaDocument);
REGISTER_TLOBJECT(TL_inputMediaVenue);
REGISTER_TLOBJECT(TL_inputMediaGifExternal);
REGISTER_TLOBJECT(TL_inputMediaPhotoExternal);
REGISTER_TLOBJECT(TL_inputMediaDocumentExternal);
REGISTER_TLOBJECT(TL_inputMediaGame);
REGISTER_TLOBJECT(TL_inputMediaInvoice);
REGISTER_TLOBJECT(TL_inputChatPhotoEmpty);
REGISTER_TLOBJECT(TL_inputChatUploadedPhoto);
REGISTER_TLOBJECT(TL_inputChatPhoto);
REGISTER_TLOBJECT(TL_inputGeoPointEmpty);
REGISTER_TLOBJECT(TL_inputGeoPoint);
REGISTER_TLOBJECT(TL_inputPhotoEmpty);
REGISTER_TLOBJECT(TL_inputPhoto);
REGISTER_TLOBJECT(TL_inputFileLocation);
REGISTER_TLOBJECT(TL_inputEncryptedFileLocation);
REGISTER_TLOBJECT(TL_inputDocumentFileLocation);
REGISTER_TLOBJECT(TL_inputAppEvent);
REGISTER_TLOBJECT(TL_peerUser);
REGISTER_TLOBJECT(TL_peerChat);
REGISTER_TLOBJECT(TL_peerChannel);
REGISTER_TLOBJECT(TL_storage_fileUnknown);
REGISTER_TLOBJECT(TL_storage_filePartial);
REGISTER_TLOBJECT(TL_storage_fileJpeg);
REGISTER_TLOBJECT(TL_storage_fileGif);
REGISTER_TLOBJECT(TL_storage_filePng);
REGISTER_TLOBJECT(TL_storage_filePdf);
REGISTER_TLOBJECT(TL_storage_fileMp3);
REGISTER_TLOBJECT(TL_storage_fileMov);
REGISTER_TLOBJECT(TL_storage_fileMp4);
REGISTER_TLOBJECT(TL_storage_fileWebp);
REGISTER_TLOBJECT(TL_fileLocationUnavailable);
REGISTER_TLOBJECT(TL_fileLocation);
REGISTER_TLOBJECT(TL_userEmpty);
REGISTER_TLOBJECT(TL_user);
REGISTER_TLOBJECT(TL_userProfilePhotoEmpty);
REGISTER_TLOBJECT(TL_userProfilePhoto);
REGISTER_TLOBJECT(TL_userStatusEmpty);
REGISTER_TLOBJECT(TL_userStatusOnline);
REGISTER_TLOBJECT(TL_userStatusOffline);
REGISTER_TLOBJECT(TL_userStatusRecently);
REGISTER_TLOBJECT(TL_userStatusLastWeek);
REGISTER_TLOBJECT(TL_userStatusLastMonth);
REGISTER_TLOBJECT(TL_chatEmpty);
REGISTER_TLOBJECT(TL_chat);
REGISTER_TLOBJECT(TL_chatForbidden);
REGISTER_TLOBJECT(TL_channel);
REGISTER_TLOBJECT(TL_channelForbidden);
REGISTER_TLOBJECT(TL_chatFull);
REGISTER_TLOBJECT(TL_channelFull);
REGISTER_TLOBJECT(TL_chatParticipant);
REGISTER_TLOBJECT(TL_chatParticipantCreator);
REGISTER_TLOBJECT(TL_chatParticipantAdmin);
REGISTER_TLOBJECT(TL_chatParticipantsForbidden);
REGISTER_TLOBJECT(TL_chatParticipants);
REGISTER_TLOBJECT(TL_chatPhotoEmpty);
REGISTER_TLOBJECT(TL_chatPhoto);
REGISTER_TLOBJECT(TL_messageEmpty);
REGISTER_TLOBJECT(TL_message);
REGISTER_TLOBJECT(TL_messageService);
REGISTER_TLOBJECT(TL_messageMediaEmpty);
REGISTER_TLOBJECT(TL_messageMediaPhoto);
REGISTER_TLOBJECT(TL_messageMediaGeo);
REGISTER_TLOBJECT(TL_messageMediaContact);
REGISTER_TLOBJECT(TL_messageMediaUnsupported);
REGISTER_TLOBJECT(TL_messageMediaDocument);
REGISTER_TLOBJECT(TL_messageMediaWebPage);
REGISTER_TLOBJECT(TL_messageMediaVenue);
REGISTER_TLOBJECT(TL_messageMediaGame);
REGISTER_TLOBJECT(TL_messageMediaInvoice);
REGISTER_TLOBJECT(TL_messageActionEmpty);
REGISTER_TLOBJECT(TL_messageActionChatCreate);
REGISTER_TLOBJECT(TL_messageActionChatEditTitle);
REGISTER_TLOBJECT(TL_messageActionChatEditPhoto);
REGISTER_TLOBJECT(TL_messageActionChatDeletePhoto);
REGISTER_TLOBJECT(TL_messageActionChatAddUser);
REGISTER_TLOBJECT(TL_messageActionChatDeleteUser);
REGISTER_TLOBJECT(TL_messageActionChatJoinedByLink);
REGISTER_TLOBJECT(TL_messageActionChannelCreate);
REGISTER_TLOBJECT(TL_messageActionChatMigrateTo);
REGISTER_TLOBJECT(TL_messageActionChannelMigrateFrom);
REGISTER_TLOBJECT(TL_messageActionPinMessage);
REGISTER_TLOBJECT(TL_messageActionHistoryClear);
REGISTER_TLOBJECT(TL_messageActionGameScore);
REGISTER_TLOBJECT(TL_messageActionPaymentSentMe);
REGISTER_TLOBJECT(TL_messageActionPaymentSent);
REGISTER_TLOBJECT(TL_messageActionPhoneCall);
REGISTER_TLOBJECT(TL_dialog);
REGISTER_TLOBJECT(TL_photoEmpty);
REGISTER_TLOBJECT(TL_photo);
REGISTER_TLOBJECT(TL_photoSizeEmpty);
REGISTER_TLOBJECT(TL_photoSize);
REGISTER_TLOBJECT(TL_photoCachedSize);
REGISTER_TLOBJECT(TL_geoPointEmpty);
REGISTER_TLOBJECT(TL_geoPoint);
REGISTER_TLOBJECT(TL_auth_checkedPhone);
REGISTER_TLOBJECT(TL_auth_sentCode);
REGISTER_TLOBJECT(TL_auth_authorization);
REGISTER_TLOBJECT(TL_auth_exportedAuthorization);
REGISTER_TLOBJECT(TL_inputNotifyPeer);
REGISTER_TLOBJECT(TL_inputNotifyUsers);
REGISTER_TLOBJECT(TL_inputNotifyChats);
REGISTER_TLOBJECT(TL_inputNotifyAll);
REGISTER_TLOBJECT(TL_inputPeerNotifyEventsEmpty);
REGISTER_TLOBJECT(TL_inputPeerNotifyEventsAll);
REGISTER_TLOBJECT(TL_inputPeerNotifySettings);
REGISTER_TLOBJECT(TL_peerNotifyEventsEmpty);
REGISTER_TLOBJECT(TL_peerNotifyEventsAll);
REGISTER_TLOBJECT(TL_peerNotifySettingsEmpty);
REGISTER_TLOBJECT(TL_peerNotifySettings);
REGISTER_TLOBJECT(TL_peerSettings);
REGISTER_TLOBJECT(TL_wallPaper);
REGISTER_TLOBJECT(TL_wallPaperSolid);
REGISTER_TLOBJECT(TL_inputReportReasonSpam);
REGISTER_TLOBJECT(TL_inputReportReasonViolence);
REGISTER_TLOBJECT(TL_inputReportReasonPornography);
REGISTER_TLOBJECT(TL_inputReportReasonOther);
REGISTER_TLOBJECT(TL_userFull);
REGISTER_TLOBJECT(TL_contact);
REGISTER_TLOBJECT(TL_importedContact);
REGISTER_TLOBJECT(TL_contactBlocked);
REGISTER_TLOBJECT(TL_contactStatus);
REGISTER_TLOBJECT(TL_contacts_link);
REGISTER_TLOBJECT(TL_contacts_contactsNotModified);
REGISTER_TLOBJECT(TL_contacts_contacts);
REGISTER_TLOBJECT(TL_contacts_importedContacts);
REGISTER_TLOBJECT(TL_contacts_blocked);
REGISTER_TLOBJECT(TL_contacts_blockedSlice);
REGISTER_TLOBJECT(TL_messages_dialogs);
REGISTER_TLOBJECT(TL_messages_dialogsSlice);
REGISTER_TLOBJECT(TL_messages_messages);
REGISTER_TLOBJECT(TL_messages_messagesSlice);
REGISTER_TLOBJECT(TL_messages_channelMessages);
REGISTER_TLOBJECT(TL_messages_chats);
REGISTER_TLOBJECT(TL_messages_chatsSlice);
REGISTER_TLOBJECT(TL_messages_chatFull);
REGISTER_TLOBJECT(TL_messages_affectedHistory);
REGISTER_TLOBJECT(TL_inputMessagesFilterEmpty);
REGISTER_TLOBJECT(TL_inputMessagesFilterPhotos);
REGISTER_TLOBJECT(TL_inputMessagesFilterVideo);
REGISTER_TLOBJECT(TL_inputMessagesFilterPhotoVideo);
REGISTER_TLOBJECT(TL_inputMessagesFilterPhotoVideoDocuments);
REGISTER_TLOBJECT(TL_inputMessagesFilterDocument);
REGISTER_TLOBJECT(TL_inputMessagesFilterUrl);
REGISTER_TLOBJECT(TL_inputMessagesFilterGif);
REGISTER_TLOBJECT(TL_inputMessagesFilterVoice);
REGISTER_TLOBJECT(TL_inputMessagesFilterMusic);
REGISTER_TLOBJECT(TL_inputMessagesFilterChatPhotos);
REGISTER_TLOBJECT(TL_inputMessagesFilterPhoneCalls);
REGISTER_TLOBJECT(TL_inputMessagesFilterRoundVoice);
REGISTER_TLOBJECT(TL_inputMessagesFilterRoundVideo);
REGISTER_TLOBJECT(TL_updateNewMessage);
REGISTER_TLOBJECT(TL_updateMessageID);
REGISTER_TLOBJECT(TL_updateDeleteMessages);
REGISTER_TLOBJECT(TL_updateUserTyping);
REGISTER_TLOBJECT(TL_updateChatUserTyping);
REGISTER_TLOBJECT(TL_updateChatParticipants);
REGISTER_TLOBJECT(TL_updateUserStatus);
REGISTER_TLOBJECT(TL_updateUserName);
REGISTER_TLOBJECT(TL_updateUserPhoto);
REGISTER_TLOBJECT(TL_updateContactRegistered);
REGISTER_TLOBJECT(TL_updateContactLink);
REGISTER_TLOBJECT(TL_updateNewEncryptedMessage);
REGISTER_TLOBJECT(TL_updateEncryptedChatTyping);
REGISTER_TLOBJECT(TL_updateEncryption);
REGISTER_TLOBJECT(TL_updateEncryptedMessagesRead);
REGISTER_TLOBJECT(TL_updateChatParticipantAdd);
REGISTER_TLOBJECT(TL_updateChatParticipantDelete);
REGISTER_TLOBJECT(TL_updateDcOptions);
REGISTER_TLOBJECT(TL_updateUserBlocked);
REGISTER_TLOBJECT(TL_updateNotifySettings);
REGISTER_TLOBJECT(TL_updateServiceNotification);
REGISTER_TLOBJECT(TL_updatePrivacy);
REGISTER_TLOBJECT(TL_updateUserPhone);
REGISTER_TLOBJECT(TL_updateReadHistoryInbox);
REGISTER_TLOBJECT(TL_updateReadHistoryOutbox);
REGISTER_TLOBJECT(TL_updateWebPage);
REGISTER_TLOBJECT(TL_updateReadMessagesContents);
REGISTER_TLOBJECT(TL_updateChannelTooLong);
REGISTER_TLOBJECT(TL_updateChannel);
REGISTER_TLOBJECT(TL_updateNewChannelMessage);
REGISTER_TLOBJECT(TL_updateReadChannelInbox);
REGISTER_TLOBJECT(TL_updateDeleteChannelMessages);
REGISTER_TLOBJECT(TL_updateChannelMessageViews);
REGISTER_TLOBJECT(TL_updateChatAdmins);
REGISTER_TLOBJECT(TL_updateChatParticipantAdmin);
REGISTER_TLOBJECT(TL_updateNewStickerSet);
REGISTER_TLOBJECT(TL_updateStickerSetsOrder);
REGISTER_TLOBJECT(TL_updateStickerSets);
REGISTER_TLOBJECT(TL_updateSavedGifs);
REGISTER_TLOBJECT(TL_updateBotInlineQuery);
REGISTER_TLOBJECT(TL_updateBotInlineSend);
REGISTER_TLOBJECT(TL_updateEditChannelMessage);
REGISTER_TLOBJECT(TL_updateChannelPinnedMessage);
REGISTER_TLOBJECT(TL_updateBotCallbackQuery);
REGISTER_TLOBJECT(TL_updateEditMessage);
REGISTER_TLOBJECT(TL_updateInlineBotCallbackQuery);
REGISTER_TLOBJECT(TL_updateReadChannelOutbox);
REGISTER_TLOBJECT(TL_updateDraftMessage);
REGISTER_TLOBJECT(TL_updateReadFeaturedStickers);
REGISTER_TLOBJECT(TL_updateRecentStickers);
REGISTER_TLOBJECT(TL_updateConfig);
REGISTER_TLOBJECT(TL_updatePtsChanged);
REGISTER_TLOBJECT(TL_updateChannelWebPage);
REGISTER_TLOBJECT(TL_updateDialogPinned);
REGISTER_TLOBJECT(TL_updatePinnedDialogs);
REGISTER_TLOBJECT(TL_updateBotWebhookJSON);
REGISTER_TLOBJECT(TL_updateBotWebhookJSONQuery);
REGISTER_TLOBJECT(TL_updateBotShippingQuery);
REGISTER_TLOBJECT(TL_updateBotPrecheckoutQuery);
REGISTER_TLOBJECT(TL_updatePhoneCall);
REGISTER_TLOBJECT(TL_updates_state);
REGISTER_TLOBJECT(TL_updates_differenceEmpty);
REGISTER_TLOBJECT(TL_updates_difference);
REGISTER_TLOBJECT(TL_updates_differenceSlice);
REGISTER_TLOBJECT(TL_updates_differenceTooLong);
REGISTER_TLOBJECT(TL_updatesTooLong);
REGISTER_TLOBJECT(TL_updateShortMessage);
REGISTER_TLOBJECT(TL_updateShortChatMessage);
REGISTER_TLOBJECT(TL_updateShort);
REGISTER_TLOBJECT(TL_updatesCombined);
REGISTER_TLOBJECT(TL_updates);
REGISTER_TLOBJECT(TL_updateShortSentMessage);
REGISTER_TLOBJECT(TL_photos_photos);
REGISTER_TLOBJECT(TL_photos_photosSlice);
REGISTER_TLOBJECT(TL_photos_photo);
REGISTER_TLOBJECT(TL_upload_file);
REGISTER_TLOBJECT(TL_upload_fileCdnRedirect);
REGISTER_TLOBJECT(TL_dcOption);
REGISTER_TLOBJECT(TL_config);
REGISTER_TLOBJECT(TL_nearestDc);
REGISTER_TLOBJECT(TL_help_appUpdate);
REGISTER_TLOBJECT(TL_help_noAppUpdate);
REGISTER_TLOBJECT(TL_help_inviteText);
REGISTER_TLOBJECT(TL_encryptedChatEmpty);
REGISTER_TLOBJECT(TL_encryptedChatWaiting);
REGISTER_TLOBJECT(TL_encryptedChatRequested);
REGISTER_TLOBJECT(TL_encryptedChat);
REGISTER_TLOBJECT(TL_encryptedChatDiscarded);
REGISTER_TLOBJECT(TL_inputEncryptedChat);
REGISTER_TLOBJECT(TL_encryptedFileEmpty);
REGISTER_TLOBJECT(TL_encryptedFile);
REGISTER_TLOBJECT(TL_inputEncryptedFileEmpty);
REGISTER_TLOBJECT(TL_inputEncryptedFileUploaded);
REGISTER_TLOBJECT(TL_inputEncryptedFile);
REGISTER_TLOBJECT(TL_inputEncryptedFileBigUploaded);
REGISTER_TLOBJECT(TL_encryptedMessage);
REGISTER_TLOBJECT(TL_encryptedMessageService);
REGISTER_TLOBJECT(TL_messages_dhConfigNotModified);
REGISTER_TLOBJECT(TL_messages_dhConfig);
REGISTER_TLOBJECT(TL_messages_sentEncryptedMessage);
REGISTER_TLOBJECT(TL_messages_sentEncryptedFile);
REGISTER_TLOBJECT(TL_inputDocumentEmpty);
REGISTER_TLOBJECT(TL_inputDocument);
REGISTER_TLOBJECT(TL_documentEmpty);
REGISTER_TLOBJECT(TL_document);
REGISTER_TLOBJECT(TL_help_support);
REGISTER_TLOBJECT(TL_notifyPeer);
REGISTER_TLOBJECT(TL_notifyUsers);
REGISTER_TLOBJECT(TL_notifyChats);
REGISTER_TLOBJECT(TL_notifyAll);
REGISTER_TLOBJECT(TL_sendMessageTypingAction);
REGISTER_TLOBJECT(TL_sendMessageCancelAction);
REGISTER_TLOBJECT(TL_sendMessageRecordVideoAction);
REGISTER_TLOBJECT(TL_sendMessageUploadVideoAction);
REGISTER_TLOBJECT(TL_sendMessageRecordAudioAction);
REGISTER_TLOBJECT(TL_sendMessageUploadAudioAction);
REGISTER_TLOBJECT(TL_sendMessageUploadPhotoAction);
REGISTER_TLOBJECT(TL_sendMessageUploadDocumentAction);
REGISTER_TLOBJECT(TL_sendMessageGeoLocationAction);
REGISTER_TLOBJECT(TL_sendMessageChooseContactAction);
REGISTER_TLOBJECT(TL_sendMessageGamePlayAction);
REGISTER_TLOBJECT(TL_sendMessageRecordRoundAction);
REGISTER_TLOBJECT(TL_sendMessageUploadRoundAction);
REGISTER_TLOBJECT(TL_contacts_found);
REGISTER_TLOBJECT(TL_inputPrivacyKeyStatusTimestamp);
REGISTER_TLOBJECT(TL_inputPrivacyKeyChatInvite);
REGISTER_TLOBJECT(TL_inputPrivacyKeyPhoneCall);
REGISTER_TLOBJECT(TL_privacyKeyStatusTimestamp);
REGISTER_TLOBJECT(TL_privacyKeyChatInvite);
REGISTER_TLOBJECT(TL_privacyKeyPhoneCall);
REGISTER_TLOBJECT(TL_inputPrivacyValueAllowContacts);
REGISTER_TLOBJECT(TL_inputPrivacyValueAllowAll);
REGISTER_TLOBJECT(TL_inputPrivacyValueAllowUsers);
REGISTER_TLOBJECT(TL_inputPrivacyValueDisallowContacts);
REGISTER_TLOBJECT(TL_inputPrivacyValueDisallowAll);
REGISTER_TLOBJECT(TL_inputPrivacyValueDisallowUsers);
REGISTER_TLOBJECT(TL_privacyValueAllowContacts);
REGISTER_TLOBJECT(TL_privacyValueAllowAll);
REGISTER_TLOBJECT(TL_privacyValueAllowUsers);
REGISTER_TLOBJECT(TL_privacyValueDisallowContacts);
REGISTER_TLOBJECT(TL_privacyValueDisallowAll);
REGISTER_TLOBJECT(TL_privacyValueDisallowUsers);
REGISTER_TLOBJECT(TL_account_privacyRules);
REGISTER_TLOBJECT(TL_accountDaysTTL);
REGISTER_TLOBJECT(TL_documentAttributeImageSize);
REGISTER_TLOBJECT(TL_documentAttributeAnimated);
REGISTER_TLOBJECT(TL_documentAttributeSticker);
REGISTER_TLOBJECT(TL_documentAttributeVideo);
REGISTER_TLOBJECT(TL_documentAttributeAudio);
REGISTER_TLOBJECT(TL_documentAttributeFilename);
REGISTER_TLOBJECT(TL_documentAttributeHasStickers);
REGISTER_TLOBJECT(TL_messages_stickersNotModified);
REGISTER_TLOBJECT(TL_messages_stickers);
REGISTER_TLOBJECT(TL_stickerPack);
REGISTER_TLOBJECT(TL_messages_allStickersNotModified);
REGISTER_TLOBJECT(TL_messages_allStickers);
REGISTER_TLOBJECT(TL_disabledFeature);
REGISTER_TLOBJECT(TL_messages_affectedMessages);
REGISTER_TLOBJECT(TL_contactLinkUnknown);
REGISTER_TLOBJECT(TL_contactLinkNone);
REGISTER_TLOBJECT(TL_contactLinkHasPhone);
REGISTER_TLOBJECT(TL_contactLinkContact);
REGISTER_TLOBJECT(TL_webPageEmpty);
REGISTER_TLOBJECT(TL_webPagePending);
REGISTER_TLOBJECT(TL_webPage);
REGISTER_TLOBJECT(TL_webPageNotModified);
REGISTER_TLOBJECT(TL_authorization);
REGISTER_TLOBJECT(TL_account_authorizations);
REGISTER_TLOBJECT(TL_account_noPassword);
REGISTER_TLOBJECT(TL_account_password);
REGISTER_TLOBJECT(TL_account_passwordSettings);
REGISTER_TLOBJECT(TL_account_passwordInputSettings);
REGISTER_TLOBJECT(TL_auth_passwordRecovery);
REGISTER_TLOBJECT(TL_receivedNotifyMessage);
REGISTER_TLOBJECT(TL_chatInviteEmpty);
REGISTER_TLOBJECT(TL_chatInviteExported);
REGISTER_TLOBJECT(TL_chatInviteAlready);
REGISTER_TLOBJECT(TL_chatInvite);
REGISTER_TLOBJECT(TL_inputStickerSetEmpty);
REGISTER_TLOBJECT(TL_inputStickerSetID);
REGISTER_TLOBJECT(TL_inputStickerSetShortName);
REGISTER_TLOBJECT(TL_stickerSet);
REGISTER_TLOBJECT(TL_messages_stickerSet);
REGISTER_TLOBJECT(TL_botCommand);
REGISTER_TLOBJECT(TL_botInfo);
REGISTER_TLOBJECT(TL_keyboardButton);
REGISTER_TLOBJECT(TL_keyboardButtonUrl);
REGISTER_TLOBJECT(TL_keyboardButtonCallback);
REGISTER_TLOBJECT(TL_keyboardButtonRequestPhone);
REGISTER_TLOBJECT(TL_keyboardButtonRequestGeoLocation);
REGISTER_TLOBJECT(TL_keyboardButtonSwitchInline);
REGISTER_TLOBJECT(TL_keyboardButtonGame);
REGISTER_TLOBJECT(TL_keyboardButtonBuy);
REGISTER_TLOBJECT(TL_keyboardButtonRow);
REGISTER_TLOBJECT(TL_replyKeyboardHide);
REGISTER_TLOBJECT(TL_replyKeyboardForceReply);
REGISTER_TLOBJECT(TL_replyKeyboardMarkup);
REGISTER_TLOBJECT(TL_replyInlineMarkup);
REGISTER_TLOBJECT(TL_messageEntityUnknown);
REGISTER_TLOBJECT(TL_messageEntityMention);
REGISTER_TLOBJECT(TL_messageEntityHashtag);
REGISTER_TLOBJECT(TL_messageEntityBotCommand);
REGISTER_TLOBJECT(TL_messageEntityUrl);
REGISTER_TLOBJECT(TL_messageEntityEmail);
REGISTER_TLOBJECT(TL_messageEntityBold);
REGISTER_TLOBJECT(TL_messageEntityItalic);
REGISTER_TLOBJECT(TL_messageEntityCode);
REGISTER_TLOBJECT(TL_messageEntityPre);
REGISTER_TLOBJECT(TL_messageEntityTextUrl);
REGISTER_TLOBJECT(TL_messageEntityMentionName);
REGISTER_TLOBJECT(TL_inputMessageEntityMentionName);
REGISTER_TLOBJECT(TL_inputChannelEmpty);
REGISTER_TLOBJECT(TL_inputChannel);
REGISTER_TLOBJECT(TL_contacts_resolvedPeer);
REGISTER_TLOBJECT(TL_messageRange);
REGISTER_TLOBJECT(TL_updates_channelDifferenceEmpty);
REGISTER_TLOBJECT(TL_updates_channelDifferenceTooLong);
REGISTER_TLOBJECT(TL_updates_channelDifference);
REGISTER_TLOBJECT(TL_channelMessagesFilterEmpty);
REGISTER_TLOBJECT(TL_channelMessagesFilter);
REGISTER_TLOBJECT(TL_channelParticipant);
REGISTER_TLOBJECT(TL_channelParticipantSelf);
REGISTER_TLOBJECT(TL_channelParticipantModerator);
REGISTER_TLOBJECT(TL_channelParticipantEditor);
REGISTER_TLOBJECT(TL_channelParticipantKicked);
REGISTER_TLOBJECT(TL_channelParticipantCreator);
REGISTER_TLOBJECT(TL_channelParticipantsRecent);
REGISTER_TLOBJECT(TL_channelParticipantsAdmins);
REGISTER_TLOBJECT(TL_channelParticipantsKicked);
REGISTER_TLOBJECT(TL_channelParticipantsBots);
REGISTER_TLOBJECT(TL_channelRoleEmpty);
REGISTER_TLOBJECT(TL_channelRoleModerator);
REGISTER_TLOBJECT(TL_channelRoleEditor);
REGISTER_TLOBJECT(TL_channels_channelParticipants);
REGISTER_TLOBJECT(TL_channels_channelParticipant);
REGISTER_TLOBJECT(TL_help_termsOfService);
REGISTER_TLOBJECT(TL_foundGif);
REGISTER_TLOBJECT(TL_foundGifCached);
REGISTER_TLOBJECT(TL_messages_foundGifs);
REGISTER_TLOBJECT(TL_messages_savedGifsNotModified);
REGISTER_TLOBJECT(TL_messages_savedGifs);
REGISTER_TLOBJECT(TL_inputBotInlineMessageMediaAuto);
REGISTER_TLOBJECT(TL_inputBotInlineMessageText);
REGISTER_TLOBJECT(TL_inputBotInlineMessageMediaGeo);
REGISTER_TLOBJECT(TL_inputBotInlineMessageMediaVenue);
REGISTER_TLOBJECT(TL_inputBotInlineMessageMediaContact);
REGISTER_TLOBJECT(TL_inputBotInlineMessageGame);
REGISTER_TLOBJECT(TL_inputBotInlineResult);
REGISTER_TLOBJECT(TL_inputBotInlineResultPhoto);
REGISTER_TLOBJECT(TL_inputBotInlineResultDocument);
REGISTER_TLOBJECT(TL_inputBotInlineResultGame);
REGISTER_TLOBJECT(TL_botInlineMessageMediaAuto);
REGISTER_TLOBJECT(TL_botInlineMessageText);
REGISTER_TLOBJECT(TL_botInlineMessageMediaGeo);
REGISTER_TLOBJECT(TL_botInlineMessageMediaVenue);
REGISTER_TLOBJECT(TL_botInlineMessageMediaContact);
REGISTER_TLOBJECT(TL_botInlineResult);
REGISTER_TLOBJECT(TL_botInlineMediaResult);
REGISTER_TLOBJECT(TL_messages_botResults);
REGISTER_TLOBJECT(TL_exportedMessageLink);
REGISTER_TLOBJECT(TL_messageFwdHeader);
REGISTER_TLOBJECT(TL_auth_codeTypeSms);
REGISTER_TLOBJECT(TL_auth_codeTypeCall);
REGISTER_TLOBJECT(TL_auth_codeTypeFlashCall);
REGISTER_TLOBJECT(TL_auth_sentCodeTypeApp);
REGISTER_TLOBJECT(TL_auth_sentCodeTypeSms);
REGISTER_TLOBJECT(TL_auth_sentCodeTypeCall);
REGISTER_TLOBJECT(TL_auth_sentCodeTypeFlashCall);
REGISTER_TLOBJECT(TL_messages_botCallbackAnswer);
REGISTER_TLOBJECT(TL_messages_messageEditData);
REGISTER_TLOBJECT(TL_inputBotInlineMessageID);
REGISTER_TLOBJECT(TL_inlineBotSwitchPM);
REGISTER_TLOBJECT(TL_messages_peerDialogs);
REGISTER_TLOBJECT(TL_topPeer);
REGISTER_TLOBJECT(TL_topPeerCategoryBotsPM);
REGISTER_TLOBJECT(TL_topPeerCategoryBotsInline);
REGISTER_TLOBJECT(TL_topPeerCategoryCorrespondents);
REGISTER_TLOBJECT(TL_topPeerCategoryGroups);
REGISTER_TLOBJECT(TL_topPeerCategoryChannels);
REGISTER_TLOBJECT(TL_topPeerCategoryPeers);
REGISTER_TLOBJECT(TL_contacts_topPeersNotModified);
REGISTER_TLOBJECT(TL_contacts_topPeers);
REGISTER_TLOBJECT(TL_draftMessageEmpty);
REGISTER_TLOBJECT(TL_draftMessage);
REGISTER_TLOBJECT(TL_messages_featuredStickersNotModified);
REGISTER_TLOBJECT(TL_messages_featuredStickers);
REGISTER_TLOBJECT(TL_messages_recentStickersNotModified);
REGISTER_TLOBJECT(TL_messages_recentStickers);
REGISTER_TLOBJECT(TL_messages_archivedStickers);
REGISTER_TLOBJECT(TL_messages_stickerSetInstallResultSuccess);
REGISTER_TLOBJECT(TL_messages_stickerSetInstallResultArchive);
REGISTER_TLOBJECT(TL_stickerSetCovered);
REGISTER_TLOBJECT(TL_stickerSetMultiCovered);
REGISTER_TLOBJECT(TL_maskCoords);
REGISTER_TLOBJECT(TL_inputStickeredMediaPhoto);
REGISTER_TLOBJECT(TL_inputStickeredMediaDocument);
REGISTER_TLOBJECT(TL_game);
REGISTER_TLOBJECT(TL_inputGameID);
REGISTER_TLOBJECT(TL_inputGameShortName);
REGISTER_TLOBJECT(TL_highScore);
REGISTER_TLOBJECT(TL_messages_highScores);
REGISTER_TLOBJECT(TL_textEmpty);
REGISTER_TLOBJECT(TL_textPlain);
REGISTER_TLOBJECT(TL_textBold);
REGISTER_TLOBJECT(TL_textItalic);
REGISTER_TLOBJECT(TL_textUnderline);
REGISTER_TLOBJECT(TL_textStrike);
REGISTER_TLOBJECT(TL_textFixed);
REGISTER_TLOBJECT(TL_textUrl);
REGISTER_TLOBJECT(TL_textEmail);
REGISTER_TLOBJECT(TL_textConcat);
REGISTER_TLOBJECT(TL_pageBlockUnsupported);
REGISTER_TLOBJECT(TL_pageBlockTitle);
REGISTER_TLOBJECT(TL_pageBlockSubtitle);
REGISTER_TLOBJECT(TL_pageBlockAuthorDate);
REGISTER_TLOBJECT(TL_pageBlockHeader);
REGISTER_TLOBJECT(TL_pageBlockSubheader);
REGISTER_TLOBJECT(TL_pageBlockParagraph);
REGISTER_TLOBJECT(TL_pageBlockPreformatted);
REGISTER_TLOBJECT(TL_pageBlockFooter);
REGISTER_TLOBJECT(TL_pageBlockDivider);
REGISTER_TLOBJECT(TL_pageBlockAnchor);
REGISTER_TLOBJECT(TL_pageBlockList);
REGISTER_TLOBJECT(TL_pageBlockBlockquote);
REGISTER_TLOBJECT(TL_pageBlockPullquote);
REGISTER_TLOBJECT(TL_pageBlockPhoto);
REGISTER_TLOBJECT(TL_pageBlockVideo);
REGISTER_TLOBJECT(TL_pageBlockCover);
REGISTER_TLOBJECT(TL_pageBlockEmbed);
REGISTER_TLOBJECT(TL_pageBlockEmbedPost);
REGISTER_TLOBJECT(TL_pageBlockCollage);
REGISTER_TLOBJECT(TL_pageBlockSlideshow);
REGISTER_TLOBJECT(TL_pageBlockChannel);
REGISTER_TLOBJECT(TL_pagePart);
REGISTER_TLOBJECT(TL_pageFull);
REGISTER_TLOBJECT(TL_phoneCallDiscardReasonMissed);
REGISTER_TLOBJECT(TL_phoneCallDiscardReasonDisconnect);
REGISTER_TLOBJECT(TL_phoneCallDiscardReasonHangup);
REGISTER_TLOBJECT(TL_phoneCallDiscardReasonBusy);
REGISTER_TLOBJECT(TL_dataJSON);
REGISTER_TLOBJECT(TL_labeledPrice);
REGISTER_TLOBJECT(TL_invoice);
REGISTER_TLOBJECT(TL_paymentCharge);
REGISTER_TLOBJECT(TL_postAddress);
REGISTER_TLOBJECT(TL_paymentRequestedInfo);
REGISTER_TLOBJECT(TL_paymentSavedCredentialsCard);
REGISTER_TLOBJECT(TL_webDocument);
REGISTER_TLOBJECT(TL_inputWebDocument);
REGISTER_TLOBJECT(TL_inputWebFileLocation);
REGISTER_TLOBJECT(TL_upload_webFile);
REGISTER_TLOBJECT(TL_payments_paymentForm);
REGISTER_TLOBJECT(TL_payments_validatedRequestedInfo);
REGISTER_TLOBJECT(TL_payments_paymentResult);
REGISTER_TLOBJECT(TL_payments_paymentVerficationNeeded);
REGISTER_TLOBJECT(TL_payments_paymentReceipt);
REGISTER_TLOBJECT(TL_payments_savedInfo);
REGISTER_TLOBJECT(TL_inputPaymentCredentialsSaved);
REGISTER_TLOBJECT(TL_inputPaymentCredentials);
REGISTER_TLOBJECT(TL_account_tmpPassword);
REGISTER_TLOBJECT(TL_shippingOption);
REGISTER_TLOBJECT(TL_inputPhoneCall);
REGISTER_TLOBJECT(TL_phoneCallEmpty);
REGISTER_TLOBJECT(TL_phoneCallWaiting);
REGISTER_TLOBJECT(TL_phoneCallRequested);
REGISTER_TLOBJECT(TL_phoneCallAccepted);
REGISTER_TLOBJECT(TL_phoneCall);
REGISTER_TLOBJECT(TL_phoneCallDiscarded);
REGISTER_TLOBJECT(TL_phoneConnection);
REGISTER_TLOBJECT(TL_phoneCallProtocol);
REGISTER_TLOBJECT(TL_phone_phoneCall);
REGISTER_TLOBJECT(TL_upload_cdnFileReuploadNeeded);
REGISTER_TLOBJECT(TL_upload_cdnFile);
REGISTER_TLOBJECT(TL_cdnPublicKey);
REGISTER_TLOBJECT(TL_cdnConfig);
REGISTER_TLOBJECT(TL_invokeAfterMsg);
REGISTER_TLOBJECT(TL_invokeAfterMsgs);
REGISTER_TLOBJECT(TL_initConnection);
REGISTER_TLOBJECT(TL_invokeWithLayer);
REGISTER_TLOBJECT(TL_invokeWithoutUpdates);
REGISTER_TLOBJECT(TL_auth_checkPhone);
REGISTER_TLOBJECT(TL_auth_sendCode);
REGISTER_TLOBJECT(TL_auth_signUp);
REGISTER_TLOBJECT(TL_auth_signIn);
REGISTER_TLOBJECT(TL_auth_logOut);
REGISTER_TLOBJECT(TL_auth_resetAuthorizations);
REGISTER_TLOBJECT(TL_auth_sendInvites);
REGISTER_TLOBJECT(TL_auth_exportAuthorization);
REGISTER_TLOBJECT(TL_auth_importAuthorization);
REGISTER_TLOBJECT(TL_auth_bindTempAuthKey);
REGISTER_TLOBJECT(TL_auth_importBotAuthorization);
REGISTER_TLOBJECT(TL_auth_checkPassword);
REGISTER_TLOBJECT(TL_auth_requestPasswordRecovery);
REGISTER_TLOBJECT(TL_auth_recoverPassword);
REGISTER_TLOBJECT(TL_auth_resendCode);
REGISTER_TLOBJECT(TL_auth_cancelCode);
REGISTER_TLOBJECT(TL_auth_dropTempAuthKeys);
REGISTER_TLOBJECT(TL_account_registerDevice);
REGISTER_TLOBJECT(TL_account_unregisterDevice);
REGISTER_TLOBJECT(TL_account_updateNotifySettings);
REGISTER_TLOBJECT(TL_account_getNotifySettings);
REGISTER_TLOBJECT(TL_account_resetNotifySettings);
REGISTER_TLOBJECT(TL_account_updateProfile);
REGISTER_TLOBJECT(TL_account_updateStatus);
REGISTER_TLOBJECT(TL_account_getWallPapers);
REGISTER_TLOBJECT(TL_account_reportPeer);
REGISTER_TLOBJECT(TL_account_checkUsername);
REGISTER_TLOBJECT(TL_account_updateUsername);
REGISTER_TLOBJECT(TL_account_getPrivacy);
REGISTER_TLOBJECT(TL_account_setPrivacy);
REGISTER_TLOBJECT(TL_account_deleteAccount);
REGISTER_TLOBJECT(TL_account_getAccountTTL);
REGISTER_TLOBJECT(TL_account_setAccountTTL);
REGISTER_TLOBJECT(TL_account_sendChangePhoneCode);
REGISTER_TLOBJECT(TL_account_changePhone);
REGISTER_TLOBJECT(TL_account_updateDeviceLocked);
REGISTER_TLOBJECT(TL_account_getAuthorizations);
REGISTER_TLOBJECT(TL_account_resetAuthorization);
REGISTER_TLOBJECT(TL_account_getPassword);
REGISTER_TLOBJECT(TL_account_getPasswordSettings);
REGISTER_TLOBJECT(TL_account_updatePasswordSettings);
REGISTER_TLOBJECT(TL_account_sendConfirmPhoneCode);
REGISTER_TLOBJECT(TL_account_confirmPhone);
REGISTER_TLOBJECT(TL_account_getTmpPassword);
REGISTER_TLOBJECT(TL_users_getUsers);
REGISTER_TLOBJECT(TL_users_getFullUser);
REGISTER_TLOBJECT(TL_contacts_getStatuses);
REGISTER_TLOBJECT(TL_contacts_getContacts);
REGISTER_TLOBJECT(TL_contacts_importContacts);
REGISTER_TLOBJECT(TL_contacts_deleteContact);
REGISTER_TLOBJECT(TL_contacts_deleteContacts);
REGISTER_TLOBJECT(TL_contacts_block);
REGISTER_TLOBJECT(TL_contacts_unblock);
REGISTER_TLOBJECT(TL_contacts_getBlocked);
REGISTER_TLOBJECT(TL_contacts_exportCard);
REGISTER_TLOBJECT(TL_contacts_importCard);
REGISTER_TLOBJECT(TL_contacts_search);
REGISTER_TLOBJECT(TL_contacts_resolveUsername);
REGISTER_TLOBJECT(TL_contacts_getTopPeers);
REGISTER_TLOBJECT(TL_contacts_resetTopPeerRating);
REGISTER_TLOBJECT(TL_messages_getMessages);
REGISTER_TLOBJECT(TL_messages_getDialogs);
REGISTER_TLOBJECT(TL_messages_getHistory);
REGISTER_TLOBJECT(TL_messages_search);
REGISTER_TLOBJECT(TL_messages_readHistory);
REGISTER_TLOBJECT(TL_messages_deleteHistory);
REGISTER_TLOBJECT(TL_messages_deleteMessages);
REGISTER_TLOBJECT(TL_messages_receivedMessages);
REGISTER_TLOBJECT(TL_messages_setTyping);
REGISTER_TLOBJECT(TL_messages_sendMessage);
REGISTER_TLOBJECT(TL_messages_sendMedia);
REGISTER_TLOBJECT(TL_messages_forwardMessages);
REGISTER_TLOBJECT(TL_messages_reportSpam);
REGISTER_TLOBJECT(TL_messages_hideReportSpam);
REGISTER_TLOBJECT(TL_messages_getPeerSettings);
REGISTER_TLOBJECT(TL_messages_getChats);
REGISTER_TLOBJECT(TL_messages_getFullChat);
REGISTER_TLOBJECT(TL_messages_editChatTitle);
REGISTER_TLOBJECT(TL_messages_editChatPhoto);
REGISTER_TLOBJECT(TL_messages_addChatUser);
REGISTER_TLOBJECT(TL_messages_deleteChatUser);
REGISTER_TLOBJECT(TL_messages_createChat);
REGISTER_TLOBJECT(TL_messages_forwardMessage);
REGISTER_TLOBJECT(TL_messages_getDhConfig);
REGISTER_TLOBJECT(TL_messages_requestEncryption);
REGISTER_TLOBJECT(TL_messages_acceptEncryption);
REGISTER_TLOBJECT(TL_messages_discardEncryption);
REGISTER_TLOBJECT(TL_messages_setEncryptedTyping);
REGISTER_TLOBJECT(TL_messages_readEncryptedHistory);
REGISTER_TLOBJECT(TL_messages_sendEncrypted);
REGISTER_TLOBJECT(TL_messages_sendEncryptedFile);
REGISTER_TLOBJECT(TL_messages_sendEncryptedService);
REGISTER_TLOBJECT(TL_messages_receivedQueue);
REGISTER_TLOBJECT(TL_messages_reportEncryptedSpam);
REGISTER_TLOBJECT(TL_messages_readMessageContents);
REGISTER_TLOBJECT(TL_messages_getAllStickers);
REGISTER_TLOBJECT(TL_messages_getWebPagePreview);
REGISTER_TLOBJECT(TL_messages_exportChatInvite);
REGISTER_TLOBJECT(TL_messages_checkChatInvite);
REGISTER_TLOBJECT(TL_messages_importChatInvite);
REGISTER_TLOBJECT(TL_messages_getStickerSet);
REGISTER_TLOBJECT(TL_messages_installStickerSet);
REGISTER_TLOBJECT(TL_messages_uninstallStickerSet);
REGISTER_TLOBJECT(TL_messages_startBot);
REGISTER_TLOBJECT(TL_messages_getMessagesViews);
REGISTER_TLOBJECT(TL_messages_toggleChatAdmins);
REGISTER_TLOBJECT(TL_messages_editChatAdmin);
REGISTER_TLOBJECT(TL_messages_migrateChat);
REGISTER_TLOBJECT(TL_messages_searchGlobal);
REGISTER_TLOBJECT(TL_messages_reorderStickerSets);
REGISTER_TLOBJECT(TL_messages_getDocumentByHash);
REGISTER_TLOBJECT(TL_messages_searchGifs);
REGISTER_TLOBJECT(TL_messages_getSavedGifs);
REGISTER_TLOBJECT(TL_messages_saveGif);
REGISTER_TLOBJECT(TL_messages_getInlineBotResults);
REGISTER_TLOBJECT(TL_messages_setInlineBotResults);
REGISTER_TLOBJECT(TL_messages_sendInlineBotResult);
REGISTER_TLOBJECT(TL_messages_getMessageEditData);
REGISTER_TLOBJECT(TL_messages_editMessage);
REGISTER_TLOBJECT(TL_messages_editInlineBotMessage);
REGISTER_TLOBJECT(TL_messages_getBotCallbackAnswer);
REGISTER_TLOBJECT(TL_messages_setBotCallbackAnswer);
REGISTER_TLOBJECT(TL_messages_getPeerDialogs);
REGISTER_TLOBJECT(TL_messages_saveDraft);
REGISTER_TLOBJECT(TL_messages_getAllDrafts);
REGISTER_TLOBJECT(TL_messages_getFeaturedStickers);
REGISTER_TLOBJECT(TL_messages_readFeaturedStickers);
REGISTER_TLOBJECT(TL_messages_getRecentStickers);
REGISTER_TLOBJECT(TL_messages_saveRecentSticker);
REGISTER_TLOBJECT(TL_messages_clearRecentStickers);
REGISTER_TLOBJECT(TL_messages_getArchivedStickers);
REGISTER_TLOBJECT(TL_messages_getMaskStickers);
REGISTER_TLOBJECT(TL_messages_getAttachedStickers);
REGISTER_TLOBJECT(TL_messages_setGameScore);
REGISTER_TLOBJECT(TL_messages_setInlineGameScore);
REGISTER_TLOBJECT(TL_messages_getGameHighScores);
REGISTER_TLOBJECT(TL_messages_getInlineGameHighScores);
REGISTER_TLOBJECT(TL_messages_getCommonChats);
REGISTER_TLOBJECT(TL_messages_getAllChats);
REGISTER_TLOBJECT(TL_messages_getWebPage);
REGISTER_TLOBJECT(TL_messages_toggleDialogPin);
REGISTER_TLOBJECT(TL_messages_reorderPinnedDialogs);
REGISTER_TLOBJECT(TL_messages_getPinnedDialogs);
REGISTER_TLOBJECT(TL_messages_setBotShippingResults);
REGISTER_TLOBJECT(TL_messages_setBotPrecheckoutResults);
REGISTER_TLOBJECT(TL_updates_getState);
REGISTER_TLOBJECT(TL_updates_getDifference);
REGISTER_TLOBJECT(TL_updates_getChannelDifference);
REGISTER_TLOBJECT(TL_photos_updateProfilePhoto);
REGISTER_TLOBJECT(TL_photos_uploadProfilePhoto);
REGISTER_TLOBJECT(TL_photos_deletePhotos);
REGISTER_TLOBJECT(TL_photos_getUserPhotos);
REGISTER_TLOBJECT(TL_upload_saveFilePart);
REGISTER_TLOBJECT(TL_upload_getFile);
REGISTER_TLOBJECT(TL_upload_saveBigFilePart);
REGISTER_TLOBJECT(TL_upload_getWebFile);
REGISTER_TLOBJECT(TL_upload_getCdnFile);
REGISTER_TLOBJECT(TL_upload_reuploadCdnFile);
REGISTER_TLOBJECT(TL_help_getConfig);
REGISTER_TLOBJECT(TL_help_getNearestDc);
REGISTER_TLOBJECT(TL_help_getAppUpdate);
REGISTER_TLOBJECT(TL_help_saveAppLog);
REGISTER_TLOBJECT(TL_help_getInviteText);
REGISTER_TLOBJECT(TL_help_getSupport);
REGISTER_TLOBJECT(TL_help_getAppChangelog);
REGISTER_TLOBJECT(TL_help_getTermsOfService);
REGISTER_TLOBJECT(TL_help_setBotUpdatesStatus);
REGISTER_TLOBJECT(TL_help_getCdnConfig);
REGISTER_TLOBJECT(TL_channels_readHistory);
REGISTER_TLOBJECT(TL_channels_deleteMessages);
REGISTER_TLOBJECT(TL_channels_deleteUserHistory);
REGISTER_TLOBJECT(TL_channels_reportSpam);
REGISTER_TLOBJECT(TL_channels_getMessages);
REGISTER_TLOBJECT(TL_channels_getParticipants);
REGISTER_TLOBJECT(TL_channels_getParticipant);
REGISTER_TLOBJECT(TL_channels_getChannels);
REGISTER_TLOBJECT(TL_channels_getFullChannel);
REGISTER_TLOBJECT(TL_channels_createChannel);
REGISTER_TLOBJECT(TL_channels_editAbout);
REGISTER_TLOBJECT(TL_channels_editAdmin);
REGISTER_TLOBJECT(TL_channels_editTitle);
REGISTER_TLOBJECT(TL_channels_editPhoto);
REGISTER_TLOBJECT(TL_channels_checkUsername);
REGISTER_TLOBJECT(TL_channels_updateUsername);
REGISTER_TLOBJECT(TL_channels_joinChannel);
REGISTER_TLOBJECT(TL_channels_leaveChannel);
REGISTER_TLOBJECT(TL_channels_inviteToChannel);
REGISTER_TLOBJECT(TL_channels_kickFromChannel);
REGISTER_TLOBJECT(TL_channels_exportInvite);
REGISTER_TLOBJECT(TL_channels_deleteChannel);
REGISTER_TLOBJECT(TL_channels_toggleInvites);
REGISTER_TLOBJECT(TL_channels_exportMessageLink);
REGISTER_TLOBJECT(TL_channels_toggleSignatures);
REGISTER_TLOBJECT(TL_channels_updatePinnedMessage);
REGISTER_TLOBJECT(TL_channels_getAdminedPublicChannels);
REGISTER_TLOBJECT(TL_bots_sendCustomRequest);
REGISTER_TLOBJECT(TL_bots_answerWebhookJSONQuery);
REGISTER_TLOBJECT(TL_payments_getPaymentForm);
REGISTER_TLOBJECT(TL_payments_getPaymentReceipt);
REGISTER_TLOBJECT(TL_payments_validateRequestedInfo);
REGISTER_TLOBJECT(TL_payments_sendPaymentForm);
REGISTER_TLOBJECT(TL_payments_getSavedInfo);
REGISTER_TLOBJECT(TL_payments_clearSavedInfo);
REGISTER_TLOBJECT(TL_phone_getCallConfig);
REGISTER_TLOBJECT(TL_phone_requestCall);
REGISTER_TLOBJECT(TL_phone_acceptCall);
REGISTER_TLOBJECT(TL_phone_confirmCall);
REGISTER_TLOBJECT(TL_phone_receivedCall);
REGISTER_TLOBJECT(TL_phone_discardCall);
REGISTER_TLOBJECT(TL_phone_setCallRating);
REGISTER_TLOBJECT(TL_phone_saveCallDebug);


//////////////////////////////////////////////////////////////////////////////
// resPQ
bool TL_resPQ::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  ReadTLIntN(iobr, &server_nonce_);
  ReadString(iobr, &pq_);
  server_public_key_fingerprints_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_resPQ::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  WriteTLIntN(iobw, server_nonce_);
  WriteString(iobw, pq_);
  server_public_key_fingerprints_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// p_q_inner_data
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
// server_DH_params_fail
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
// server_DH_params_ok
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
// server_DH_inner_data
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
// client_DH_inner_data
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
  iobw.writeLE(retry_id_);
  WriteString(iobw, g_b_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// dh_gen_ok
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

//////////////////////////////////////////////////////////////////////////////
// dh_gen_retry
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
// dh_gen_fail
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
// destroy_auth_key_ok
bool TL_destroy_auth_key_ok::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_destroy_auth_key_ok::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// destroy_auth_key_none
bool TL_destroy_auth_key_none::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_destroy_auth_key_none::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// destroy_auth_key_fail
bool TL_destroy_auth_key_fail::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_destroy_auth_key_fail::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// msgs_ack
bool TL_msgs_ack::Decode(IOBufReader& iobr) {
  msg_ids_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_msgs_ack::Encode(IOBufWriter& iobw) const {
  msg_ids_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// bad_msg_notification
bool TL_bad_msg_notification::Decode(IOBufReader& iobr) {
  bad_msg_id_ = iobr.readLE<int64_t>();
  bad_msg_seqno_ = iobr.readLE<int32_t>();
  error_code_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_bad_msg_notification::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(bad_msg_id_);
  iobw.writeLE(bad_msg_seqno_);
  iobw.writeLE(error_code_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// bad_server_salt
bool TL_bad_server_salt::Decode(IOBufReader& iobr) {
  bad_msg_id_ = iobr.readLE<int64_t>();
  bad_msg_seqno_ = iobr.readLE<int32_t>();
  error_code_ = iobr.readLE<int32_t>();
  new_server_salt_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_bad_server_salt::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(bad_msg_id_);
  iobw.writeLE(bad_msg_seqno_);
  iobw.writeLE(error_code_);
  iobw.writeLE(new_server_salt_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// msgs_state_req
bool TL_msgs_state_req::Decode(IOBufReader& iobr) {
  msg_ids_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_msgs_state_req::Encode(IOBufWriter& iobw) const {
  msg_ids_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// msgs_state_info
bool TL_msgs_state_info::Decode(IOBufReader& iobr) {
  req_msg_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &info_);
  return true;
}
bool TL_msgs_state_info::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(req_msg_id_);
  WriteString(iobw, info_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// msgs_all_info
bool TL_msgs_all_info::Decode(IOBufReader& iobr) {
  msg_ids_.ParseFromIOBuf(iobr);
  ReadString(iobr, &info_);
  return true;
}
bool TL_msgs_all_info::Encode(IOBufWriter& iobw) const {
  msg_ids_.SerializeToIOBuf(iobw);
  WriteString(iobw, info_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// msg_detailed_info
bool TL_msg_detailed_info::Decode(IOBufReader& iobr) {
  msg_id_ = iobr.readLE<int64_t>();
  answer_msg_id_ = iobr.readLE<int64_t>();
  bytes_ = iobr.readLE<int32_t>();
  status_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_msg_detailed_info::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(msg_id_);
  iobw.writeLE(answer_msg_id_);
  iobw.writeLE(bytes_);
  iobw.writeLE(status_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// msg_new_detailed_info
bool TL_msg_new_detailed_info::Decode(IOBufReader& iobr) {
  answer_msg_id_ = iobr.readLE<int64_t>();
  bytes_ = iobr.readLE<int32_t>();
  status_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_msg_new_detailed_info::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(answer_msg_id_);
  iobw.writeLE(bytes_);
  iobw.writeLE(status_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// msg_resend_req
bool TL_msg_resend_req::Decode(IOBufReader& iobr) {
  msg_ids_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_msg_resend_req::Encode(IOBufWriter& iobw) const {
  msg_ids_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// rpc_error
bool TL_rpc_error::Decode(IOBufReader& iobr) {
  error_code_ = iobr.readLE<int32_t>();
  ReadString(iobr, &error_message_);
  return true;
}
bool TL_rpc_error::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(error_code_);
  WriteString(iobw, error_message_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// rpc_answer_unknown
bool TL_rpc_answer_unknown::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_rpc_answer_unknown::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// rpc_answer_dropped_running
bool TL_rpc_answer_dropped_running::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_rpc_answer_dropped_running::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// rpc_answer_dropped
bool TL_rpc_answer_dropped::Decode(IOBufReader& iobr) {
  msg_id_ = iobr.readLE<int64_t>();
  seq_no_ = iobr.readLE<int32_t>();
  bytes_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_rpc_answer_dropped::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(msg_id_);
  iobw.writeLE(seq_no_);
  iobw.writeLE(bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// future_salt
bool TL_future_salt::Decode(IOBufReader& iobr) {
  valid_since_ = iobr.readLE<int32_t>();
  valid_until_ = iobr.readLE<int32_t>();
  salt_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_future_salt::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(valid_since_);
  iobw.writeLE(valid_until_);
  iobw.writeLE(salt_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// future_salts
bool TL_future_salts::Decode(IOBufReader& iobr) {
  req_msg_id_ = iobr.readLE<int64_t>();
  now_ = iobr.readLE<int32_t>();
  auto sz = iobr.readLE<uint32_t>();
  for (uint32_t i=0; i<sz; ++i) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o->GetClassID() != TL_future_salt::CLASS_ID) {
      delete o;
      return false;
    }
    salts_.push_back(std::unique_ptr<TL_future_salt>(reinterpret_cast<TL_future_salt*>(o)));
  }
  return true;
}
bool TL_future_salts::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(req_msg_id_);
  iobw.writeLE(now_);
  iobw.writeLE(salts_.size());
  for (size_t i=0; i<salts_.size(); ++i) {
    salts_[i]->SerializeToIOBuf(iobw);
;  }
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pong
bool TL_pong::Decode(IOBufReader& iobr) {
  msg_id_ = iobr.readLE<int64_t>();
  ping_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_pong::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(msg_id_);
  iobw.writeLE(ping_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// destroy_session_ok
bool TL_destroy_session_ok::Decode(IOBufReader& iobr) {
  session_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_destroy_session_ok::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(session_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// destroy_session_none
bool TL_destroy_session_none::Decode(IOBufReader& iobr) {
  session_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_destroy_session_none::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(session_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// new_session_created
bool TL_new_session_created::Decode(IOBufReader& iobr) {
  first_msg_id_ = iobr.readLE<int64_t>();
  unique_id_ = iobr.readLE<int64_t>();
  server_salt_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_new_session_created::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(first_msg_id_);
  iobw.writeLE(unique_id_);
  iobw.writeLE(server_salt_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// http_wait
bool TL_http_wait::Decode(IOBufReader& iobr) {
  max_delay_ = iobr.readLE<int32_t>();
  wait_after_ = iobr.readLE<int32_t>();
  max_wait_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_http_wait::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(max_delay_);
  iobw.writeLE(wait_after_);
  iobw.writeLE(max_wait_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// boolFalse
bool TL_boolFalse::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_boolFalse::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// boolTrue
bool TL_boolTrue::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_boolTrue::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// true
bool TL_true::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_true::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// error
bool TL_error::Decode(IOBufReader& iobr) {
  code_ = iobr.readLE<int32_t>();
  ReadString(iobr, &text_);
  return true;
}
bool TL_error::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(code_);
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// null
bool TL_null::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_null::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPeerEmpty
bool TL_inputPeerEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPeerEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPeerSelf
bool TL_inputPeerSelf::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPeerSelf::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPeerChat
bool TL_inputPeerChat::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_inputPeerChat::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPeerUser
bool TL_inputPeerUser::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputPeerUser::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPeerChannel
bool TL_inputPeerChannel::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputPeerChannel::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputUserEmpty
bool TL_inputUserEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputUserEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputUserSelf
bool TL_inputUserSelf::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputUserSelf::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputUser
bool TL_inputUser::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputUser::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPhoneContact
bool TL_inputPhoneContact::Decode(IOBufReader& iobr) {
  client_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &phone_);
  ReadString(iobr, &first_name_);
  ReadString(iobr, &last_name_);
  return true;
}
bool TL_inputPhoneContact::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(client_id_);
  WriteString(iobw, phone_);
  WriteString(iobw, first_name_);
  WriteString(iobw, last_name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputFile
bool TL_inputFile::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  parts_ = iobr.readLE<int32_t>();
  ReadString(iobr, &name_);
  ReadString(iobr, &md5_checksum_);
  return true;
}
bool TL_inputFile::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(parts_);
  WriteString(iobw, name_);
  WriteString(iobw, md5_checksum_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputFileBig
bool TL_inputFileBig::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  parts_ = iobr.readLE<int32_t>();
  ReadString(iobr, &name_);
  return true;
}
bool TL_inputFileBig::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(parts_);
  WriteString(iobw, name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaEmpty
bool TL_inputMediaEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMediaEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaUploadedPhoto
bool TL_inputMediaUploadedPhoto::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_ = std::unique_ptr<InputFile>(o2);
  }
  ReadString(iobr, &caption_);
  if (has_stickers()) {
    stickers_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_inputMediaUploadedPhoto::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!file_) return false;
  file_-> SerializeToIOBuf(iobw);
  WriteString(iobw, caption_);
  if (has_stickers()) stickers_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaPhoto
bool TL_inputMediaPhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputPhoto>(o2);
  }
  ReadString(iobr, &caption_);
  return true;
}
bool TL_inputMediaPhoto::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  WriteString(iobw, caption_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaGeoPoint
bool TL_inputMediaGeoPoint::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputGeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_point_ = std::unique_ptr<InputGeoPoint>(o2);
  }
  return true;
}
bool TL_inputMediaGeoPoint::Encode(IOBufWriter& iobw) const {
  if (!geo_point_) return false;
  geo_point_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaContact
bool TL_inputMediaContact::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &first_name_);
  ReadString(iobr, &last_name_);
  return true;
}
bool TL_inputMediaContact::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  WriteString(iobw, first_name_);
  WriteString(iobw, last_name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaUploadedDocument
bool TL_inputMediaUploadedDocument::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_ = std::unique_ptr<InputFile>(o2);
  }
  ReadString(iobr, &mime_type_);
  attributes_.ParseFromIOBuf(iobr);
  ReadString(iobr, &caption_);
  if (has_stickers()) {
    stickers_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_inputMediaUploadedDocument::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!file_) return false;
  file_-> SerializeToIOBuf(iobw);
  WriteString(iobw, mime_type_);
  attributes_.SerializeToIOBuf(iobw);
  WriteString(iobw, caption_);
  if (has_stickers()) stickers_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaUploadedThumbDocument
bool TL_inputMediaUploadedThumbDocument::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_ = std::unique_ptr<InputFile>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    thumb_ = std::unique_ptr<InputFile>(o2);
  }
  ReadString(iobr, &mime_type_);
  attributes_.ParseFromIOBuf(iobr);
  ReadString(iobr, &caption_);
  if (has_stickers()) {
    stickers_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_inputMediaUploadedThumbDocument::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!file_) return false;
  file_-> SerializeToIOBuf(iobw);
  if (!thumb_) return false;
  thumb_-> SerializeToIOBuf(iobw);
  WriteString(iobw, mime_type_);
  attributes_.SerializeToIOBuf(iobw);
  WriteString(iobw, caption_);
  if (has_stickers()) stickers_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaDocument
bool TL_inputMediaDocument::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputDocument*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputDocument>(o2);
  }
  ReadString(iobr, &caption_);
  return true;
}
bool TL_inputMediaDocument::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  WriteString(iobw, caption_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaVenue
bool TL_inputMediaVenue::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputGeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_point_ = std::unique_ptr<InputGeoPoint>(o2);
  }
  ReadString(iobr, &title_);
  ReadString(iobr, &address_);
  ReadString(iobr, &provider_);
  ReadString(iobr, &venue_id_);
  return true;
}
bool TL_inputMediaVenue::Encode(IOBufWriter& iobw) const {
  if (!geo_point_) return false;
  geo_point_-> SerializeToIOBuf(iobw);
  WriteString(iobw, title_);
  WriteString(iobw, address_);
  WriteString(iobw, provider_);
  WriteString(iobw, venue_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaGifExternal
bool TL_inputMediaGifExternal::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  ReadString(iobr, &q_);
  return true;
}
bool TL_inputMediaGifExternal::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  WriteString(iobw, q_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaPhotoExternal
bool TL_inputMediaPhotoExternal::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  ReadString(iobr, &caption_);
  return true;
}
bool TL_inputMediaPhotoExternal::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  WriteString(iobw, caption_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaDocumentExternal
bool TL_inputMediaDocumentExternal::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  ReadString(iobr, &caption_);
  return true;
}
bool TL_inputMediaDocumentExternal::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  WriteString(iobw, caption_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaGame
bool TL_inputMediaGame::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputGame*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputGame>(o2);
  }
  return true;
}
bool TL_inputMediaGame::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMediaInvoice
bool TL_inputMediaInvoice::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  ReadString(iobr, &description_);
  if (has_photo()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputWebDocument*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<InputWebDocument>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Invoice*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    invoice_ = std::unique_ptr<Invoice>(o2);
  }
  ReadString(iobr, &payload_);
  ReadString(iobr, &provider_);
  ReadString(iobr, &start_param_);
  return true;
}
bool TL_inputMediaInvoice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, title_);
  WriteString(iobw, description_);
  if (has_photo()) photo_->SerializeToIOBuf(iobw);
  if (!invoice_) return false;
  invoice_-> SerializeToIOBuf(iobw);
  WriteString(iobw, payload_);
  WriteString(iobw, provider_);
  WriteString(iobw, start_param_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputChatPhotoEmpty
bool TL_inputChatPhotoEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputChatPhotoEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputChatUploadedPhoto
bool TL_inputChatUploadedPhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_ = std::unique_ptr<InputFile>(o2);
  }
  return true;
}
bool TL_inputChatUploadedPhoto::Encode(IOBufWriter& iobw) const {
  if (!file_) return false;
  file_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputChatPhoto
bool TL_inputChatPhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputPhoto>(o2);
  }
  return true;
}
bool TL_inputChatPhoto::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputGeoPointEmpty
bool TL_inputGeoPointEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputGeoPointEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputGeoPoint
bool TL_inputGeoPoint::Decode(IOBufReader& iobr) {
  lat_ = iobr.readLE<double>();
  long_ = iobr.readLE<double>();
  return true;
}
bool TL_inputGeoPoint::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(lat_);
  iobw.writeLE(long_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPhotoEmpty
bool TL_inputPhotoEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPhotoEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPhoto
bool TL_inputPhoto::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputPhoto::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputFileLocation
bool TL_inputFileLocation::Decode(IOBufReader& iobr) {
  volume_id_ = iobr.readLE<int64_t>();
  local_id_ = iobr.readLE<int32_t>();
  secret_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputFileLocation::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(volume_id_);
  iobw.writeLE(local_id_);
  iobw.writeLE(secret_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputEncryptedFileLocation
bool TL_inputEncryptedFileLocation::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputEncryptedFileLocation::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputDocumentFileLocation
bool TL_inputDocumentFileLocation::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  version_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_inputDocumentFileLocation::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(version_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputAppEvent
bool TL_inputAppEvent::Decode(IOBufReader& iobr) {
  time_ = iobr.readLE<double>();
  ReadString(iobr, &type_);
  peer_ = iobr.readLE<int64_t>();
  ReadString(iobr, &data_);
  return true;
}
bool TL_inputAppEvent::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(time_);
  WriteString(iobw, type_);
  iobw.writeLE(peer_);
  WriteString(iobw, data_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// peerUser
bool TL_peerUser::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_peerUser::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// peerChat
bool TL_peerChat::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_peerChat::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// peerChannel
bool TL_peerChannel::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_peerChannel::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_fileUnknown
bool TL_storage_fileUnknown::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_fileUnknown::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_filePartial
bool TL_storage_filePartial::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_filePartial::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_fileJpeg
bool TL_storage_fileJpeg::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_fileJpeg::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_fileGif
bool TL_storage_fileGif::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_fileGif::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_filePng
bool TL_storage_filePng::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_filePng::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_filePdf
bool TL_storage_filePdf::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_filePdf::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_fileMp3
bool TL_storage_fileMp3::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_fileMp3::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_fileMov
bool TL_storage_fileMov::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_fileMov::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_fileMp4
bool TL_storage_fileMp4::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_fileMp4::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// storage_fileWebp
bool TL_storage_fileWebp::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_storage_fileWebp::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// fileLocationUnavailable
bool TL_fileLocationUnavailable::Decode(IOBufReader& iobr) {
  volume_id_ = iobr.readLE<int64_t>();
  local_id_ = iobr.readLE<int32_t>();
  secret_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_fileLocationUnavailable::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(volume_id_);
  iobw.writeLE(local_id_);
  iobw.writeLE(secret_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// fileLocation
bool TL_fileLocation::Decode(IOBufReader& iobr) {
  dc_id_ = iobr.readLE<int32_t>();
  volume_id_ = iobr.readLE<int64_t>();
  local_id_ = iobr.readLE<int32_t>();
  secret_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_fileLocation::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(dc_id_);
  iobw.writeLE(volume_id_);
  iobw.writeLE(local_id_);
  iobw.writeLE(secret_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userEmpty
bool TL_userEmpty::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_userEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// user
bool TL_user::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  if (has_access_hash()) {
    access_hash_ = iobr.readLE<int64_t>();
  }
  if (has_first_name()) {
    ReadString(iobr, &first_name_);
  }
  if (has_last_name()) {
    ReadString(iobr, &last_name_);
  }
  if (has_username()) {
    ReadString(iobr, &username_);
  }
  if (has_phone()) {
    ReadString(iobr, &phone_);
  }
  if (has_photo()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<UserProfilePhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<UserProfilePhoto>(o2);
  }
  if (has_status()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<UserStatus*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    status_ = std::unique_ptr<UserStatus>(o2);
  }
  if (has_bot_info_version()) {
    bot_info_version_ = iobr.readLE<int32_t>();
  }
  if (has_restriction_reason()) {
    ReadString(iobr, &restriction_reason_);
  }
  if (has_bot_inline_placeholder()) {
    ReadString(iobr, &bot_inline_placeholder_);
  }
  if (has_lang_code()) {
    ReadString(iobr, &lang_code_);
  }
  return true;
}
bool TL_user::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  if (has_access_hash()) iobw.writeLE(access_hash_);
  if (has_first_name()) WriteString(iobw, first_name_);
  if (has_last_name()) WriteString(iobw, last_name_);
  if (has_username()) WriteString(iobw, username_);
  if (has_phone()) WriteString(iobw, phone_);
  if (has_photo()) photo_->SerializeToIOBuf(iobw);
  if (has_status()) status_->SerializeToIOBuf(iobw);
  if (has_bot_info_version()) iobw.writeLE(bot_info_version_);
  if (has_restriction_reason()) WriteString(iobw, restriction_reason_);
  if (has_bot_inline_placeholder()) WriteString(iobw, bot_inline_placeholder_);
  if (has_lang_code()) WriteString(iobw, lang_code_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userProfilePhotoEmpty
bool TL_userProfilePhotoEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_userProfilePhotoEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userProfilePhoto
bool TL_userProfilePhoto::Decode(IOBufReader& iobr) {
  photo_id_ = iobr.readLE<int64_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<FileLocation*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_small_ = std::unique_ptr<FileLocation>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<FileLocation*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_big_ = std::unique_ptr<FileLocation>(o2);
  }
  return true;
}
bool TL_userProfilePhoto::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(photo_id_);
  if (!photo_small_) return false;
  photo_small_-> SerializeToIOBuf(iobw);
  if (!photo_big_) return false;
  photo_big_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userStatusEmpty
bool TL_userStatusEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_userStatusEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userStatusOnline
bool TL_userStatusOnline::Decode(IOBufReader& iobr) {
  expires_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_userStatusOnline::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(expires_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userStatusOffline
bool TL_userStatusOffline::Decode(IOBufReader& iobr) {
  was_online_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_userStatusOffline::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(was_online_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userStatusRecently
bool TL_userStatusRecently::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_userStatusRecently::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userStatusLastWeek
bool TL_userStatusLastWeek::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_userStatusLastWeek::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userStatusLastMonth
bool TL_userStatusLastMonth::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_userStatusLastMonth::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatEmpty
bool TL_chatEmpty::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_chatEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chat
bool TL_chat::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChatPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<ChatPhoto>(o2);
  }
  participants_count_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  version_ = iobr.readLE<int32_t>();
  if (has_migrated_to()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    migrated_to_ = std::unique_ptr<InputChannel>(o2);
  }
  return true;
}
bool TL_chat::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  WriteString(iobw, title_);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  iobw.writeLE(participants_count_);
  iobw.writeLE(date_);
  iobw.writeLE(version_);
  if (has_migrated_to()) migrated_to_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatForbidden
bool TL_chatForbidden::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  return true;
}
bool TL_chatForbidden::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  WriteString(iobw, title_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channel
bool TL_channel::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  if (has_access_hash()) {
    access_hash_ = iobr.readLE<int64_t>();
  }
  ReadString(iobr, &title_);
  if (has_username()) {
    ReadString(iobr, &username_);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChatPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<ChatPhoto>(o2);
  }
  date_ = iobr.readLE<int32_t>();
  version_ = iobr.readLE<int32_t>();
  if (has_restriction_reason()) {
    ReadString(iobr, &restriction_reason_);
  }
  return true;
}
bool TL_channel::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  if (has_access_hash()) iobw.writeLE(access_hash_);
  WriteString(iobw, title_);
  if (has_username()) WriteString(iobw, username_);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  iobw.writeLE(date_);
  iobw.writeLE(version_);
  if (has_restriction_reason()) WriteString(iobw, restriction_reason_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelForbidden
bool TL_channelForbidden::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  ReadString(iobr, &title_);
  return true;
}
bool TL_channelForbidden::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  WriteString(iobw, title_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatFull
bool TL_chatFull::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChatParticipants*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    participants_ = std::unique_ptr<ChatParticipants>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    chat_photo_ = std::unique_ptr<Photo>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PeerNotifySettings*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    notify_settings_ = std::unique_ptr<PeerNotifySettings>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ExportedChatInvite*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    exported_invite_ = std::unique_ptr<ExportedChatInvite>(o2);
  }
  bot_info_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_chatFull::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  if (!participants_) return false;
  participants_-> SerializeToIOBuf(iobw);
  if (!chat_photo_) return false;
  chat_photo_-> SerializeToIOBuf(iobw);
  if (!notify_settings_) return false;
  notify_settings_-> SerializeToIOBuf(iobw);
  if (!exported_invite_) return false;
  exported_invite_-> SerializeToIOBuf(iobw);
  bot_info_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelFull
bool TL_channelFull::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &about_);
  if (has_participants_count()) {
    participants_count_ = iobr.readLE<int32_t>();
  }
  if (has_admins_count()) {
    admins_count_ = iobr.readLE<int32_t>();
  }
  if (has_kicked_count()) {
    kicked_count_ = iobr.readLE<int32_t>();
  }
  read_inbox_max_id_ = iobr.readLE<int32_t>();
  read_outbox_max_id_ = iobr.readLE<int32_t>();
  unread_count_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    chat_photo_ = std::unique_ptr<Photo>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PeerNotifySettings*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    notify_settings_ = std::unique_ptr<PeerNotifySettings>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ExportedChatInvite*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    exported_invite_ = std::unique_ptr<ExportedChatInvite>(o2);
  }
  bot_info_.ParseFromIOBuf(iobr);
  if (has_migrated_from_chat_id()) {
    migrated_from_chat_id_ = iobr.readLE<int32_t>();
  }
  if (has_migrated_from_max_id()) {
    migrated_from_max_id_ = iobr.readLE<int32_t>();
  }
  if (has_pinned_msg_id()) {
    pinned_msg_id_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_channelFull::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  WriteString(iobw, about_);
  if (has_participants_count()) iobw.writeLE(participants_count_);
  if (has_admins_count()) iobw.writeLE(admins_count_);
  if (has_kicked_count()) iobw.writeLE(kicked_count_);
  iobw.writeLE(read_inbox_max_id_);
  iobw.writeLE(read_outbox_max_id_);
  iobw.writeLE(unread_count_);
  if (!chat_photo_) return false;
  chat_photo_-> SerializeToIOBuf(iobw);
  if (!notify_settings_) return false;
  notify_settings_-> SerializeToIOBuf(iobw);
  if (!exported_invite_) return false;
  exported_invite_-> SerializeToIOBuf(iobw);
  bot_info_.SerializeToIOBuf(iobw);
  if (has_migrated_from_chat_id()) iobw.writeLE(migrated_from_chat_id_);
  if (has_migrated_from_max_id()) iobw.writeLE(migrated_from_max_id_);
  if (has_pinned_msg_id()) iobw.writeLE(pinned_msg_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatParticipant
bool TL_chatParticipant::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  inviter_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_chatParticipant::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(inviter_id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatParticipantCreator
bool TL_chatParticipantCreator::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_chatParticipantCreator::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatParticipantAdmin
bool TL_chatParticipantAdmin::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  inviter_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_chatParticipantAdmin::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(inviter_id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatParticipantsForbidden
bool TL_chatParticipantsForbidden::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  chat_id_ = iobr.readLE<int32_t>();
  if (has_self_participant()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChatParticipant*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    self_participant_ = std::unique_ptr<ChatParticipant>(o2);
  }
  return true;
}
bool TL_chatParticipantsForbidden::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(chat_id_);
  if (has_self_participant()) self_participant_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatParticipants
bool TL_chatParticipants::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  participants_.ParseFromIOBuf(iobr);
  version_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_chatParticipants::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  participants_.SerializeToIOBuf(iobw);
  iobw.writeLE(version_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatPhotoEmpty
bool TL_chatPhotoEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_chatPhotoEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatPhoto
bool TL_chatPhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<FileLocation*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_small_ = std::unique_ptr<FileLocation>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<FileLocation*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_big_ = std::unique_ptr<FileLocation>(o2);
  }
  return true;
}
bool TL_chatPhoto::Encode(IOBufWriter& iobw) const {
  if (!photo_small_) return false;
  photo_small_-> SerializeToIOBuf(iobw);
  if (!photo_big_) return false;
  photo_big_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEmpty
bool TL_messageEmpty::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// message
bool TL_message::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  if (has_from_id()) {
    from_id_ = iobr.readLE<int32_t>();
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    to_id_ = std::unique_ptr<Peer>(o2);
  }
  if (has_fwd_from()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MessageFwdHeader*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    fwd_from_ = std::unique_ptr<MessageFwdHeader>(o2);
  }
  if (has_via_bot_id()) {
    via_bot_id_ = iobr.readLE<int32_t>();
  }
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  date_ = iobr.readLE<int32_t>();
  ReadString(iobr, &message_);
  if (has_media()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MessageMedia*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    media_ = std::unique_ptr<MessageMedia>(o2);
  }
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  if (has_views()) {
    views_ = iobr.readLE<int32_t>();
  }
  if (has_edit_date()) {
    edit_date_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_message::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  if (has_from_id()) iobw.writeLE(from_id_);
  if (!to_id_) return false;
  to_id_-> SerializeToIOBuf(iobw);
  if (has_fwd_from()) fwd_from_->SerializeToIOBuf(iobw);
  if (has_via_bot_id()) iobw.writeLE(via_bot_id_);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  iobw.writeLE(date_);
  WriteString(iobw, message_);
  if (has_media()) media_->SerializeToIOBuf(iobw);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  if (has_views()) iobw.writeLE(views_);
  if (has_edit_date()) iobw.writeLE(edit_date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageService
bool TL_messageService::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  if (has_from_id()) {
    from_id_ = iobr.readLE<int32_t>();
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    to_id_ = std::unique_ptr<Peer>(o2);
  }
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  date_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MessageAction*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    action_ = std::unique_ptr<MessageAction>(o2);
  }
  return true;
}
bool TL_messageService::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  if (has_from_id()) iobw.writeLE(from_id_);
  if (!to_id_) return false;
  to_id_-> SerializeToIOBuf(iobw);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  iobw.writeLE(date_);
  if (!action_) return false;
  action_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaEmpty
bool TL_messageMediaEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messageMediaEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaPhoto
bool TL_messageMediaPhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<Photo>(o2);
  }
  ReadString(iobr, &caption_);
  return true;
}
bool TL_messageMediaPhoto::Encode(IOBufWriter& iobw) const {
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  WriteString(iobw, caption_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaGeo
bool TL_messageMediaGeo::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<GeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_ = std::unique_ptr<GeoPoint>(o2);
  }
  return true;
}
bool TL_messageMediaGeo::Encode(IOBufWriter& iobw) const {
  if (!geo_) return false;
  geo_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaContact
bool TL_messageMediaContact::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &first_name_);
  ReadString(iobr, &last_name_);
  user_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageMediaContact::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  WriteString(iobw, first_name_);
  WriteString(iobw, last_name_);
  iobw.writeLE(user_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaUnsupported
bool TL_messageMediaUnsupported::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messageMediaUnsupported::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaDocument
bool TL_messageMediaDocument::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Document*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    document_ = std::unique_ptr<Document>(o2);
  }
  ReadString(iobr, &caption_);
  return true;
}
bool TL_messageMediaDocument::Encode(IOBufWriter& iobw) const {
  if (!document_) return false;
  document_-> SerializeToIOBuf(iobw);
  WriteString(iobw, caption_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaWebPage
bool TL_messageMediaWebPage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<WebPage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    webpage_ = std::unique_ptr<WebPage>(o2);
  }
  return true;
}
bool TL_messageMediaWebPage::Encode(IOBufWriter& iobw) const {
  if (!webpage_) return false;
  webpage_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaVenue
bool TL_messageMediaVenue::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<GeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_ = std::unique_ptr<GeoPoint>(o2);
  }
  ReadString(iobr, &title_);
  ReadString(iobr, &address_);
  ReadString(iobr, &provider_);
  ReadString(iobr, &venue_id_);
  return true;
}
bool TL_messageMediaVenue::Encode(IOBufWriter& iobw) const {
  if (!geo_) return false;
  geo_-> SerializeToIOBuf(iobw);
  WriteString(iobw, title_);
  WriteString(iobw, address_);
  WriteString(iobw, provider_);
  WriteString(iobw, venue_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaGame
bool TL_messageMediaGame::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Game*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    game_ = std::unique_ptr<Game>(o2);
  }
  return true;
}
bool TL_messageMediaGame::Encode(IOBufWriter& iobw) const {
  if (!game_) return false;
  game_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageMediaInvoice
bool TL_messageMediaInvoice::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  ReadString(iobr, &description_);
  if (has_photo()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<WebDocument*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<WebDocument>(o2);
  }
  if (has_receipt_msg_id()) {
    receipt_msg_id_ = iobr.readLE<int32_t>();
  }
  ReadString(iobr, &currency_);
  total_amount_ = iobr.readLE<int64_t>();
  ReadString(iobr, &start_param_);
  return true;
}
bool TL_messageMediaInvoice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, title_);
  WriteString(iobw, description_);
  if (has_photo()) photo_->SerializeToIOBuf(iobw);
  if (has_receipt_msg_id()) iobw.writeLE(receipt_msg_id_);
  WriteString(iobw, currency_);
  iobw.writeLE(total_amount_);
  WriteString(iobw, start_param_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionEmpty
bool TL_messageActionEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messageActionEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChatCreate
bool TL_messageActionChatCreate::Decode(IOBufReader& iobr) {
  ReadString(iobr, &title_);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messageActionChatCreate::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, title_);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChatEditTitle
bool TL_messageActionChatEditTitle::Decode(IOBufReader& iobr) {
  ReadString(iobr, &title_);
  return true;
}
bool TL_messageActionChatEditTitle::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, title_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChatEditPhoto
bool TL_messageActionChatEditPhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<Photo>(o2);
  }
  return true;
}
bool TL_messageActionChatEditPhoto::Encode(IOBufWriter& iobw) const {
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChatDeletePhoto
bool TL_messageActionChatDeletePhoto::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messageActionChatDeletePhoto::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChatAddUser
bool TL_messageActionChatAddUser::Decode(IOBufReader& iobr) {
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messageActionChatAddUser::Encode(IOBufWriter& iobw) const {
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChatDeleteUser
bool TL_messageActionChatDeleteUser::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageActionChatDeleteUser::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChatJoinedByLink
bool TL_messageActionChatJoinedByLink::Decode(IOBufReader& iobr) {
  inviter_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageActionChatJoinedByLink::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(inviter_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChannelCreate
bool TL_messageActionChannelCreate::Decode(IOBufReader& iobr) {
  ReadString(iobr, &title_);
  return true;
}
bool TL_messageActionChannelCreate::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, title_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChatMigrateTo
bool TL_messageActionChatMigrateTo::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageActionChatMigrateTo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionChannelMigrateFrom
bool TL_messageActionChannelMigrateFrom::Decode(IOBufReader& iobr) {
  ReadString(iobr, &title_);
  chat_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageActionChannelMigrateFrom::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, title_);
  iobw.writeLE(chat_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionPinMessage
bool TL_messageActionPinMessage::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messageActionPinMessage::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionHistoryClear
bool TL_messageActionHistoryClear::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messageActionHistoryClear::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionGameScore
bool TL_messageActionGameScore::Decode(IOBufReader& iobr) {
  game_id_ = iobr.readLE<int64_t>();
  score_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageActionGameScore::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(game_id_);
  iobw.writeLE(score_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionPaymentSentMe
bool TL_messageActionPaymentSentMe::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &currency_);
  total_amount_ = iobr.readLE<int64_t>();
  ReadString(iobr, &payload_);
  if (has_info()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PaymentRequestedInfo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    info_ = std::unique_ptr<PaymentRequestedInfo>(o2);
  }
  if (has_shipping_option_id()) {
    ReadString(iobr, &shipping_option_id_);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PaymentCharge*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    charge_ = std::unique_ptr<PaymentCharge>(o2);
  }
  return true;
}
bool TL_messageActionPaymentSentMe::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, currency_);
  iobw.writeLE(total_amount_);
  WriteString(iobw, payload_);
  if (has_info()) info_->SerializeToIOBuf(iobw);
  if (has_shipping_option_id()) WriteString(iobw, shipping_option_id_);
  if (!charge_) return false;
  charge_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionPaymentSent
bool TL_messageActionPaymentSent::Decode(IOBufReader& iobr) {
  ReadString(iobr, &currency_);
  total_amount_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_messageActionPaymentSent::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, currency_);
  iobw.writeLE(total_amount_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageActionPhoneCall
bool TL_messageActionPhoneCall::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  call_id_ = iobr.readLE<int64_t>();
  if (has_reason()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallDiscardReason*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reason_ = std::unique_ptr<PhoneCallDiscardReason>(o2);
  }
  if (has_duration()) {
    duration_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_messageActionPhoneCall::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(call_id_);
  if (has_reason()) reason_->SerializeToIOBuf(iobw);
  if (has_duration()) iobw.writeLE(duration_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// dialog
bool TL_dialog::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  top_message_ = iobr.readLE<int32_t>();
  read_inbox_max_id_ = iobr.readLE<int32_t>();
  read_outbox_max_id_ = iobr.readLE<int32_t>();
  unread_count_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PeerNotifySettings*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    notify_settings_ = std::unique_ptr<PeerNotifySettings>(o2);
  }
  if (has_pts()) {
    pts_ = iobr.readLE<int32_t>();
  }
  if (has_draft()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DraftMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    draft_ = std::unique_ptr<DraftMessage>(o2);
  }
  return true;
}
bool TL_dialog::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(top_message_);
  iobw.writeLE(read_inbox_max_id_);
  iobw.writeLE(read_outbox_max_id_);
  iobw.writeLE(unread_count_);
  if (!notify_settings_) return false;
  notify_settings_-> SerializeToIOBuf(iobw);
  if (has_pts()) iobw.writeLE(pts_);
  if (has_draft()) draft_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photoEmpty
bool TL_photoEmpty::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_photoEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photo
bool TL_photo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  sizes_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_photo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  sizes_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photoSizeEmpty
bool TL_photoSizeEmpty::Decode(IOBufReader& iobr) {
  ReadString(iobr, &type_);
  return true;
}
bool TL_photoSizeEmpty::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, type_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photoSize
bool TL_photoSize::Decode(IOBufReader& iobr) {
  ReadString(iobr, &type_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<FileLocation*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    location_ = std::unique_ptr<FileLocation>(o2);
  }
  w_ = iobr.readLE<int32_t>();
  h_ = iobr.readLE<int32_t>();
  size_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_photoSize::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, type_);
  if (!location_) return false;
  location_-> SerializeToIOBuf(iobw);
  iobw.writeLE(w_);
  iobw.writeLE(h_);
  iobw.writeLE(size_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photoCachedSize
bool TL_photoCachedSize::Decode(IOBufReader& iobr) {
  ReadString(iobr, &type_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<FileLocation*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    location_ = std::unique_ptr<FileLocation>(o2);
  }
  w_ = iobr.readLE<int32_t>();
  h_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_photoCachedSize::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, type_);
  if (!location_) return false;
  location_-> SerializeToIOBuf(iobw);
  iobw.writeLE(w_);
  iobw.writeLE(h_);
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// geoPointEmpty
bool TL_geoPointEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_geoPointEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// geoPoint
bool TL_geoPoint::Decode(IOBufReader& iobr) {
  long_ = iobr.readLE<double>();
  lat_ = iobr.readLE<double>();
  return true;
}
bool TL_geoPoint::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(long_);
  iobw.writeLE(lat_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_checkedPhone
bool TL_auth_checkedPhone::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    phone_registered_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_auth_checkedPhone::Encode(IOBufWriter& iobw) const {
  if (!phone_registered_) return false;
  phone_registered_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_sentCode
bool TL_auth_sentCode::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<auth_SentCodeType*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    type_ = std::unique_ptr<auth_SentCodeType>(o2);
  }
  ReadString(iobr, &phone_code_hash_);
  if (has_next_type()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<auth_CodeType*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    next_type_ = std::unique_ptr<auth_CodeType>(o2);
  }
  if (has_timeout()) {
    timeout_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_auth_sentCode::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!type_) return false;
  type_-> SerializeToIOBuf(iobw);
  WriteString(iobw, phone_code_hash_);
  if (has_next_type()) next_type_->SerializeToIOBuf(iobw);
  if (has_timeout()) iobw.writeLE(timeout_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_authorization
bool TL_auth_authorization::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_tmp_sessions()) {
    tmp_sessions_ = iobr.readLE<int32_t>();
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<User*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_ = std::unique_ptr<User>(o2);
  }
  return true;
}
bool TL_auth_authorization::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_tmp_sessions()) iobw.writeLE(tmp_sessions_);
  if (!user_) return false;
  user_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_exportedAuthorization
bool TL_auth_exportedAuthorization::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_auth_exportedAuthorization::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputNotifyPeer
bool TL_inputNotifyPeer::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  return true;
}
bool TL_inputNotifyPeer::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputNotifyUsers
bool TL_inputNotifyUsers::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputNotifyUsers::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputNotifyChats
bool TL_inputNotifyChats::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputNotifyChats::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputNotifyAll
bool TL_inputNotifyAll::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputNotifyAll::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPeerNotifyEventsEmpty
bool TL_inputPeerNotifyEventsEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPeerNotifyEventsEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPeerNotifyEventsAll
bool TL_inputPeerNotifyEventsAll::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPeerNotifyEventsAll::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPeerNotifySettings
bool TL_inputPeerNotifySettings::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  mute_until_ = iobr.readLE<int32_t>();
  ReadString(iobr, &sound_);
  return true;
}
bool TL_inputPeerNotifySettings::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(mute_until_);
  WriteString(iobw, sound_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// peerNotifyEventsEmpty
bool TL_peerNotifyEventsEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_peerNotifyEventsEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// peerNotifyEventsAll
bool TL_peerNotifyEventsAll::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_peerNotifyEventsAll::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// peerNotifySettingsEmpty
bool TL_peerNotifySettingsEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_peerNotifySettingsEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// peerNotifySettings
bool TL_peerNotifySettings::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  mute_until_ = iobr.readLE<int32_t>();
  ReadString(iobr, &sound_);
  return true;
}
bool TL_peerNotifySettings::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(mute_until_);
  WriteString(iobw, sound_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// peerSettings
bool TL_peerSettings::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_peerSettings::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// wallPaper
bool TL_wallPaper::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  sizes_.ParseFromIOBuf(iobr);
  color_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_wallPaper::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  WriteString(iobw, title_);
  sizes_.SerializeToIOBuf(iobw);
  iobw.writeLE(color_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// wallPaperSolid
bool TL_wallPaperSolid::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  bg_color_ = iobr.readLE<int32_t>();
  color_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_wallPaperSolid::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  WriteString(iobw, title_);
  iobw.writeLE(bg_color_);
  iobw.writeLE(color_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputReportReasonSpam
bool TL_inputReportReasonSpam::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputReportReasonSpam::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputReportReasonViolence
bool TL_inputReportReasonViolence::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputReportReasonViolence::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputReportReasonPornography
bool TL_inputReportReasonPornography::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputReportReasonPornography::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputReportReasonOther
bool TL_inputReportReasonOther::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  return true;
}
bool TL_inputReportReasonOther::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// userFull
bool TL_userFull::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<User*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_ = std::unique_ptr<User>(o2);
  }
  if (has_about()) {
    ReadString(iobr, &about_);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<contacts_Link*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    link_ = std::unique_ptr<contacts_Link>(o2);
  }
  if (has_profile_photo()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    profile_photo_ = std::unique_ptr<Photo>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PeerNotifySettings*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    notify_settings_ = std::unique_ptr<PeerNotifySettings>(o2);
  }
  if (has_bot_info()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<BotInfo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    bot_info_ = std::unique_ptr<BotInfo>(o2);
  }
  common_chats_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_userFull::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!user_) return false;
  user_-> SerializeToIOBuf(iobw);
  if (has_about()) WriteString(iobw, about_);
  if (!link_) return false;
  link_-> SerializeToIOBuf(iobw);
  if (has_profile_photo()) profile_photo_->SerializeToIOBuf(iobw);
  if (!notify_settings_) return false;
  notify_settings_-> SerializeToIOBuf(iobw);
  if (has_bot_info()) bot_info_->SerializeToIOBuf(iobw);
  iobw.writeLE(common_chats_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contact
bool TL_contact::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    mutual_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_contact::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  if (!mutual_) return false;
  mutual_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// importedContact
bool TL_importedContact::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  client_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_importedContact::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(client_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contactBlocked
bool TL_contactBlocked::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_contactBlocked::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contactStatus
bool TL_contactStatus::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<UserStatus*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    status_ = std::unique_ptr<UserStatus>(o2);
  }
  return true;
}
bool TL_contactStatus::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  if (!status_) return false;
  status_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_link
bool TL_contacts_link::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ContactLink*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    my_link_ = std::unique_ptr<ContactLink>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ContactLink*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    foreign_link_ = std::unique_ptr<ContactLink>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<User*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_ = std::unique_ptr<User>(o2);
  }
  return true;
}
bool TL_contacts_link::Encode(IOBufWriter& iobw) const {
  if (!my_link_) return false;
  my_link_-> SerializeToIOBuf(iobw);
  if (!foreign_link_) return false;
  foreign_link_-> SerializeToIOBuf(iobw);
  if (!user_) return false;
  user_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_contactsNotModified
bool TL_contacts_contactsNotModified::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_contacts_contactsNotModified::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_contacts
bool TL_contacts_contacts::Decode(IOBufReader& iobr) {
  contacts_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_contacts::Encode(IOBufWriter& iobw) const {
  contacts_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_importedContacts
bool TL_contacts_importedContacts::Decode(IOBufReader& iobr) {
  imported_.ParseFromIOBuf(iobr);
  retry_contacts_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_importedContacts::Encode(IOBufWriter& iobw) const {
  imported_.SerializeToIOBuf(iobw);
  retry_contacts_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_blocked
bool TL_contacts_blocked::Decode(IOBufReader& iobr) {
  blocked_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_blocked::Encode(IOBufWriter& iobw) const {
  blocked_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_blockedSlice
bool TL_contacts_blockedSlice::Decode(IOBufReader& iobr) {
  count_ = iobr.readLE<int32_t>();
  blocked_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_blockedSlice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(count_);
  blocked_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_dialogs
bool TL_messages_dialogs::Decode(IOBufReader& iobr) {
  dialogs_.ParseFromIOBuf(iobr);
  messages_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_dialogs::Encode(IOBufWriter& iobw) const {
  dialogs_.SerializeToIOBuf(iobw);
  messages_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_dialogsSlice
bool TL_messages_dialogsSlice::Decode(IOBufReader& iobr) {
  count_ = iobr.readLE<int32_t>();
  dialogs_.ParseFromIOBuf(iobr);
  messages_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_dialogsSlice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(count_);
  dialogs_.SerializeToIOBuf(iobw);
  messages_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_messages
bool TL_messages_messages::Decode(IOBufReader& iobr) {
  messages_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_messages::Encode(IOBufWriter& iobw) const {
  messages_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_messagesSlice
bool TL_messages_messagesSlice::Decode(IOBufReader& iobr) {
  count_ = iobr.readLE<int32_t>();
  messages_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_messagesSlice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(count_);
  messages_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_channelMessages
bool TL_messages_channelMessages::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  pts_ = iobr.readLE<int32_t>();
  count_ = iobr.readLE<int32_t>();
  messages_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_channelMessages::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(pts_);
  iobw.writeLE(count_);
  messages_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_chats
bool TL_messages_chats::Decode(IOBufReader& iobr) {
  chats_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_chats::Encode(IOBufWriter& iobw) const {
  chats_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_chatsSlice
bool TL_messages_chatsSlice::Decode(IOBufReader& iobr) {
  count_ = iobr.readLE<int32_t>();
  chats_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_chatsSlice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(count_);
  chats_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_chatFull
bool TL_messages_chatFull::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChatFull*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    full_chat_ = std::unique_ptr<ChatFull>(o2);
  }
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_chatFull::Encode(IOBufWriter& iobw) const {
  if (!full_chat_) return false;
  full_chat_-> SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_affectedHistory
bool TL_messages_affectedHistory::Decode(IOBufReader& iobr) {
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  offset_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_affectedHistory::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  iobw.writeLE(offset_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterEmpty
bool TL_inputMessagesFilterEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterPhotos
bool TL_inputMessagesFilterPhotos::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterPhotos::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterVideo
bool TL_inputMessagesFilterVideo::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterVideo::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterPhotoVideo
bool TL_inputMessagesFilterPhotoVideo::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterPhotoVideo::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterPhotoVideoDocuments
bool TL_inputMessagesFilterPhotoVideoDocuments::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterPhotoVideoDocuments::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterDocument
bool TL_inputMessagesFilterDocument::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterDocument::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterUrl
bool TL_inputMessagesFilterUrl::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterUrl::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterGif
bool TL_inputMessagesFilterGif::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterGif::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterVoice
bool TL_inputMessagesFilterVoice::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterVoice::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterMusic
bool TL_inputMessagesFilterMusic::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterMusic::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterChatPhotos
bool TL_inputMessagesFilterChatPhotos::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterChatPhotos::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterPhoneCalls
bool TL_inputMessagesFilterPhoneCalls::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_inputMessagesFilterPhoneCalls::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterRoundVoice
bool TL_inputMessagesFilterRoundVoice::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterRoundVoice::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessagesFilterRoundVideo
bool TL_inputMessagesFilterRoundVideo::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputMessagesFilterRoundVideo::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateNewMessage
bool TL_updateNewMessage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Message*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    message_ = std::unique_ptr<Message>(o2);
  }
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateNewMessage::Encode(IOBufWriter& iobw) const {
  if (!message_) return false;
  message_-> SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateMessageID
bool TL_updateMessageID::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  random_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_updateMessageID::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(random_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateDeleteMessages
bool TL_updateDeleteMessages::Decode(IOBufReader& iobr) {
  messages_.ParseFromIOBuf(iobr);
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateDeleteMessages::Encode(IOBufWriter& iobw) const {
  messages_.SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateUserTyping
bool TL_updateUserTyping::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<SendMessageAction*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    action_ = std::unique_ptr<SendMessageAction>(o2);
  }
  return true;
}
bool TL_updateUserTyping::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  if (!action_) return false;
  action_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChatUserTyping
bool TL_updateChatUserTyping::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<SendMessageAction*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    action_ = std::unique_ptr<SendMessageAction>(o2);
  }
  return true;
}
bool TL_updateChatUserTyping::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  iobw.writeLE(user_id_);
  if (!action_) return false;
  action_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChatParticipants
bool TL_updateChatParticipants::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChatParticipants*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    participants_ = std::unique_ptr<ChatParticipants>(o2);
  }
  return true;
}
bool TL_updateChatParticipants::Encode(IOBufWriter& iobw) const {
  if (!participants_) return false;
  participants_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateUserStatus
bool TL_updateUserStatus::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<UserStatus*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    status_ = std::unique_ptr<UserStatus>(o2);
  }
  return true;
}
bool TL_updateUserStatus::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  if (!status_) return false;
  status_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateUserName
bool TL_updateUserName::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &first_name_);
  ReadString(iobr, &last_name_);
  ReadString(iobr, &username_);
  return true;
}
bool TL_updateUserName::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  WriteString(iobw, first_name_);
  WriteString(iobw, last_name_);
  WriteString(iobw, username_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateUserPhoto
bool TL_updateUserPhoto::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<UserProfilePhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<UserProfilePhoto>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    previous_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_updateUserPhoto::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(date_);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  if (!previous_) return false;
  previous_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateContactRegistered
bool TL_updateContactRegistered::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateContactRegistered::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateContactLink
bool TL_updateContactLink::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ContactLink*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    my_link_ = std::unique_ptr<ContactLink>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ContactLink*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    foreign_link_ = std::unique_ptr<ContactLink>(o2);
  }
  return true;
}
bool TL_updateContactLink::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  if (!my_link_) return false;
  my_link_-> SerializeToIOBuf(iobw);
  if (!foreign_link_) return false;
  foreign_link_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateNewEncryptedMessage
bool TL_updateNewEncryptedMessage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<EncryptedMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    message_ = std::unique_ptr<EncryptedMessage>(o2);
  }
  qts_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateNewEncryptedMessage::Encode(IOBufWriter& iobw) const {
  if (!message_) return false;
  message_-> SerializeToIOBuf(iobw);
  iobw.writeLE(qts_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateEncryptedChatTyping
bool TL_updateEncryptedChatTyping::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateEncryptedChatTyping::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateEncryption
bool TL_updateEncryption::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<EncryptedChat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    chat_ = std::unique_ptr<EncryptedChat>(o2);
  }
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateEncryption::Encode(IOBufWriter& iobw) const {
  if (!chat_) return false;
  chat_-> SerializeToIOBuf(iobw);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateEncryptedMessagesRead
bool TL_updateEncryptedMessagesRead::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  max_date_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateEncryptedMessagesRead::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  iobw.writeLE(max_date_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChatParticipantAdd
bool TL_updateChatParticipantAdd::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  user_id_ = iobr.readLE<int32_t>();
  inviter_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  version_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateChatParticipantAdd::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  iobw.writeLE(user_id_);
  iobw.writeLE(inviter_id_);
  iobw.writeLE(date_);
  iobw.writeLE(version_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChatParticipantDelete
bool TL_updateChatParticipantDelete::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  user_id_ = iobr.readLE<int32_t>();
  version_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateChatParticipantDelete::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  iobw.writeLE(user_id_);
  iobw.writeLE(version_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateDcOptions
bool TL_updateDcOptions::Decode(IOBufReader& iobr) {
  dc_options_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_updateDcOptions::Encode(IOBufWriter& iobw) const {
  dc_options_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateUserBlocked
bool TL_updateUserBlocked::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    blocked_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_updateUserBlocked::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  if (!blocked_) return false;
  blocked_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateNotifySettings
bool TL_updateNotifySettings::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<NotifyPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<NotifyPeer>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PeerNotifySettings*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    notify_settings_ = std::unique_ptr<PeerNotifySettings>(o2);
  }
  return true;
}
bool TL_updateNotifySettings::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (!notify_settings_) return false;
  notify_settings_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateServiceNotification
bool TL_updateServiceNotification::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_inbox_date()) {
    inbox_date_ = iobr.readLE<int32_t>();
  }
  ReadString(iobr, &type_);
  ReadString(iobr, &message_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MessageMedia*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    media_ = std::unique_ptr<MessageMedia>(o2);
  }
  entities_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_updateServiceNotification::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_inbox_date()) iobw.writeLE(inbox_date_);
  WriteString(iobw, type_);
  WriteString(iobw, message_);
  if (!media_) return false;
  media_-> SerializeToIOBuf(iobw);
  entities_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updatePrivacy
bool TL_updatePrivacy::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PrivacyKey*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    key_ = std::unique_ptr<PrivacyKey>(o2);
  }
  rules_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_updatePrivacy::Encode(IOBufWriter& iobw) const {
  if (!key_) return false;
  key_-> SerializeToIOBuf(iobw);
  rules_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateUserPhone
bool TL_updateUserPhone::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &phone_);
  return true;
}
bool TL_updateUserPhone::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  WriteString(iobw, phone_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateReadHistoryInbox
bool TL_updateReadHistoryInbox::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  max_id_ = iobr.readLE<int32_t>();
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateReadHistoryInbox::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(max_id_);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateReadHistoryOutbox
bool TL_updateReadHistoryOutbox::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  max_id_ = iobr.readLE<int32_t>();
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateReadHistoryOutbox::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(max_id_);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateWebPage
bool TL_updateWebPage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<WebPage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    webpage_ = std::unique_ptr<WebPage>(o2);
  }
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateWebPage::Encode(IOBufWriter& iobw) const {
  if (!webpage_) return false;
  webpage_-> SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateReadMessagesContents
bool TL_updateReadMessagesContents::Decode(IOBufReader& iobr) {
  messages_.ParseFromIOBuf(iobr);
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateReadMessagesContents::Encode(IOBufWriter& iobw) const {
  messages_.SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChannelTooLong
bool TL_updateChannelTooLong::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  channel_id_ = iobr.readLE<int32_t>();
  if (has_pts()) {
    pts_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_updateChannelTooLong::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(channel_id_);
  if (has_pts()) iobw.writeLE(pts_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChannel
bool TL_updateChannel::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateChannel::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateNewChannelMessage
bool TL_updateNewChannelMessage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Message*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    message_ = std::unique_ptr<Message>(o2);
  }
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateNewChannelMessage::Encode(IOBufWriter& iobw) const {
  if (!message_) return false;
  message_-> SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateReadChannelInbox
bool TL_updateReadChannelInbox::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  max_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateReadChannelInbox::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  iobw.writeLE(max_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateDeleteChannelMessages
bool TL_updateDeleteChannelMessages::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  messages_.ParseFromIOBuf(iobr);
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateDeleteChannelMessages::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  messages_.SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChannelMessageViews
bool TL_updateChannelMessageViews::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  views_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateChannelMessageViews::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  iobw.writeLE(id_);
  iobw.writeLE(views_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChatAdmins
bool TL_updateChatAdmins::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    enabled_ = std::unique_ptr<Bool>(o2);
  }
  version_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateChatAdmins::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  if (!enabled_) return false;
  enabled_-> SerializeToIOBuf(iobw);
  iobw.writeLE(version_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChatParticipantAdmin
bool TL_updateChatParticipantAdmin::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    is_admin_ = std::unique_ptr<Bool>(o2);
  }
  version_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateChatParticipantAdmin::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  iobw.writeLE(user_id_);
  if (!is_admin_) return false;
  is_admin_-> SerializeToIOBuf(iobw);
  iobw.writeLE(version_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateNewStickerSet
bool TL_updateNewStickerSet::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<messages_StickerSet*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    stickerset_ = std::unique_ptr<messages_StickerSet>(o2);
  }
  return true;
}
bool TL_updateNewStickerSet::Encode(IOBufWriter& iobw) const {
  if (!stickerset_) return false;
  stickerset_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateStickerSetsOrder
bool TL_updateStickerSetsOrder::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  order_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_updateStickerSetsOrder::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  order_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateStickerSets
bool TL_updateStickerSets::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_updateStickerSets::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateSavedGifs
bool TL_updateSavedGifs::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_updateSavedGifs::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateBotInlineQuery
bool TL_updateBotInlineQuery::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  user_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &query_);
  if (has_geo()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<GeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_ = std::unique_ptr<GeoPoint>(o2);
  }
  ReadString(iobr, &offset_);
  return true;
}
bool TL_updateBotInlineQuery::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  iobw.writeLE(user_id_);
  WriteString(iobw, query_);
  if (has_geo()) geo_->SerializeToIOBuf(iobw);
  WriteString(iobw, offset_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateBotInlineSend
bool TL_updateBotInlineSend::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  user_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &query_);
  if (has_geo()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<GeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_ = std::unique_ptr<GeoPoint>(o2);
  }
  ReadString(iobr, &id_);
  if (has_msg_id()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessageID*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    msg_id_ = std::unique_ptr<InputBotInlineMessageID>(o2);
  }
  return true;
}
bool TL_updateBotInlineSend::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(user_id_);
  WriteString(iobw, query_);
  if (has_geo()) geo_->SerializeToIOBuf(iobw);
  WriteString(iobw, id_);
  if (has_msg_id()) msg_id_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateEditChannelMessage
bool TL_updateEditChannelMessage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Message*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    message_ = std::unique_ptr<Message>(o2);
  }
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateEditChannelMessage::Encode(IOBufWriter& iobw) const {
  if (!message_) return false;
  message_-> SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChannelPinnedMessage
bool TL_updateChannelPinnedMessage::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateChannelPinnedMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateBotCallbackQuery
bool TL_updateBotCallbackQuery::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  msg_id_ = iobr.readLE<int32_t>();
  chat_instance_ = iobr.readLE<int64_t>();
  if (has_data()) {
    ReadString(iobr, &data_);
  }
  if (has_game_short_name()) {
    ReadString(iobr, &game_short_name_);
  }
  return true;
}
bool TL_updateBotCallbackQuery::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  iobw.writeLE(user_id_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(msg_id_);
  iobw.writeLE(chat_instance_);
  if (has_data()) WriteString(iobw, data_);
  if (has_game_short_name()) WriteString(iobw, game_short_name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateEditMessage
bool TL_updateEditMessage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Message*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    message_ = std::unique_ptr<Message>(o2);
  }
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateEditMessage::Encode(IOBufWriter& iobw) const {
  if (!message_) return false;
  message_-> SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateInlineBotCallbackQuery
bool TL_updateInlineBotCallbackQuery::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  user_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessageID*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    msg_id_ = std::unique_ptr<InputBotInlineMessageID>(o2);
  }
  chat_instance_ = iobr.readLE<int64_t>();
  if (has_data()) {
    ReadString(iobr, &data_);
  }
  if (has_game_short_name()) {
    ReadString(iobr, &game_short_name_);
  }
  return true;
}
bool TL_updateInlineBotCallbackQuery::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  iobw.writeLE(user_id_);
  if (!msg_id_) return false;
  msg_id_-> SerializeToIOBuf(iobw);
  iobw.writeLE(chat_instance_);
  if (has_data()) WriteString(iobw, data_);
  if (has_game_short_name()) WriteString(iobw, game_short_name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateReadChannelOutbox
bool TL_updateReadChannelOutbox::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  max_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateReadChannelOutbox::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  iobw.writeLE(max_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateDraftMessage
bool TL_updateDraftMessage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DraftMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    draft_ = std::unique_ptr<DraftMessage>(o2);
  }
  return true;
}
bool TL_updateDraftMessage::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (!draft_) return false;
  draft_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateReadFeaturedStickers
bool TL_updateReadFeaturedStickers::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_updateReadFeaturedStickers::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateRecentStickers
bool TL_updateRecentStickers::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_updateRecentStickers::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateConfig
bool TL_updateConfig::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_updateConfig::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updatePtsChanged
bool TL_updatePtsChanged::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_updatePtsChanged::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateChannelWebPage
bool TL_updateChannelWebPage::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<WebPage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    webpage_ = std::unique_ptr<WebPage>(o2);
  }
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateChannelWebPage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  if (!webpage_) return false;
  webpage_-> SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateDialogPinned
bool TL_updateDialogPinned::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  return true;
}
bool TL_updateDialogPinned::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updatePinnedDialogs
bool TL_updatePinnedDialogs::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_order()) {
    order_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_updatePinnedDialogs::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_order()) order_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateBotWebhookJSON
bool TL_updateBotWebhookJSON::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DataJSON*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    data_ = std::unique_ptr<DataJSON>(o2);
  }
  return true;
}
bool TL_updateBotWebhookJSON::Encode(IOBufWriter& iobw) const {
  if (!data_) return false;
  data_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateBotWebhookJSONQuery
bool TL_updateBotWebhookJSONQuery::Decode(IOBufReader& iobr) {
  query_id_ = iobr.readLE<int64_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DataJSON*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    data_ = std::unique_ptr<DataJSON>(o2);
  }
  timeout_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateBotWebhookJSONQuery::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(query_id_);
  if (!data_) return false;
  data_-> SerializeToIOBuf(iobw);
  iobw.writeLE(timeout_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateBotShippingQuery
bool TL_updateBotShippingQuery::Decode(IOBufReader& iobr) {
  query_id_ = iobr.readLE<int64_t>();
  user_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &payload_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PostAddress*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    shipping_address_ = std::unique_ptr<PostAddress>(o2);
  }
  return true;
}
bool TL_updateBotShippingQuery::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(query_id_);
  iobw.writeLE(user_id_);
  WriteString(iobw, payload_);
  if (!shipping_address_) return false;
  shipping_address_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateBotPrecheckoutQuery
bool TL_updateBotPrecheckoutQuery::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  user_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &payload_);
  if (has_info()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PaymentRequestedInfo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    info_ = std::unique_ptr<PaymentRequestedInfo>(o2);
  }
  if (has_shipping_option_id()) {
    ReadString(iobr, &shipping_option_id_);
  }
  ReadString(iobr, &currency_);
  total_amount_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_updateBotPrecheckoutQuery::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  iobw.writeLE(user_id_);
  WriteString(iobw, payload_);
  if (has_info()) info_->SerializeToIOBuf(iobw);
  if (has_shipping_option_id()) WriteString(iobw, shipping_option_id_);
  WriteString(iobw, currency_);
  iobw.writeLE(total_amount_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updatePhoneCall
bool TL_updatePhoneCall::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCall*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    phone_call_ = std::unique_ptr<PhoneCall>(o2);
  }
  return true;
}
bool TL_updatePhoneCall::Encode(IOBufWriter& iobw) const {
  if (!phone_call_) return false;
  phone_call_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_state
bool TL_updates_state::Decode(IOBufReader& iobr) {
  pts_ = iobr.readLE<int32_t>();
  qts_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  seq_ = iobr.readLE<int32_t>();
  unread_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updates_state::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(pts_);
  iobw.writeLE(qts_);
  iobw.writeLE(date_);
  iobw.writeLE(seq_);
  iobw.writeLE(unread_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_differenceEmpty
bool TL_updates_differenceEmpty::Decode(IOBufReader& iobr) {
  date_ = iobr.readLE<int32_t>();
  seq_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updates_differenceEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(date_);
  iobw.writeLE(seq_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_difference
bool TL_updates_difference::Decode(IOBufReader& iobr) {
  new_messages_.ParseFromIOBuf(iobr);
  new_encrypted_messages_.ParseFromIOBuf(iobr);
  other_updates_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<updates_State*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    state_ = std::unique_ptr<updates_State>(o2);
  }
  return true;
}
bool TL_updates_difference::Encode(IOBufWriter& iobw) const {
  new_messages_.SerializeToIOBuf(iobw);
  new_encrypted_messages_.SerializeToIOBuf(iobw);
  other_updates_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  if (!state_) return false;
  state_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_differenceSlice
bool TL_updates_differenceSlice::Decode(IOBufReader& iobr) {
  new_messages_.ParseFromIOBuf(iobr);
  new_encrypted_messages_.ParseFromIOBuf(iobr);
  other_updates_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<updates_State*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    intermediate_state_ = std::unique_ptr<updates_State>(o2);
  }
  return true;
}
bool TL_updates_differenceSlice::Encode(IOBufWriter& iobw) const {
  new_messages_.SerializeToIOBuf(iobw);
  new_encrypted_messages_.SerializeToIOBuf(iobw);
  other_updates_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  if (!intermediate_state_) return false;
  intermediate_state_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_differenceTooLong
bool TL_updates_differenceTooLong::Decode(IOBufReader& iobr) {
  pts_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updates_differenceTooLong::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(pts_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updatesTooLong
bool TL_updatesTooLong::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_updatesTooLong::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateShortMessage
bool TL_updateShortMessage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  user_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &message_);
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  if (has_fwd_from()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MessageFwdHeader*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    fwd_from_ = std::unique_ptr<MessageFwdHeader>(o2);
  }
  if (has_via_bot_id()) {
    via_bot_id_ = iobr.readLE<int32_t>();
  }
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_updateShortMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  iobw.writeLE(user_id_);
  WriteString(iobw, message_);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  iobw.writeLE(date_);
  if (has_fwd_from()) fwd_from_->SerializeToIOBuf(iobw);
  if (has_via_bot_id()) iobw.writeLE(via_bot_id_);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateShortChatMessage
bool TL_updateShortChatMessage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  from_id_ = iobr.readLE<int32_t>();
  chat_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &message_);
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  if (has_fwd_from()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MessageFwdHeader*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    fwd_from_ = std::unique_ptr<MessageFwdHeader>(o2);
  }
  if (has_via_bot_id()) {
    via_bot_id_ = iobr.readLE<int32_t>();
  }
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_updateShortChatMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  iobw.writeLE(from_id_);
  iobw.writeLE(chat_id_);
  WriteString(iobw, message_);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  iobw.writeLE(date_);
  if (has_fwd_from()) fwd_from_->SerializeToIOBuf(iobw);
  if (has_via_bot_id()) iobw.writeLE(via_bot_id_);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateShort
bool TL_updateShort::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Update*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    update_ = std::unique_ptr<Update>(o2);
  }
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updateShort::Encode(IOBufWriter& iobw) const {
  if (!update_) return false;
  update_-> SerializeToIOBuf(iobw);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updatesCombined
bool TL_updatesCombined::Decode(IOBufReader& iobr) {
  updates_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  date_ = iobr.readLE<int32_t>();
  seq_start_ = iobr.readLE<int32_t>();
  seq_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updatesCombined::Encode(IOBufWriter& iobw) const {
  updates_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  iobw.writeLE(date_);
  iobw.writeLE(seq_start_);
  iobw.writeLE(seq_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates
bool TL_updates::Decode(IOBufReader& iobr) {
  updates_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  date_ = iobr.readLE<int32_t>();
  seq_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updates::Encode(IOBufWriter& iobw) const {
  updates_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  iobw.writeLE(date_);
  iobw.writeLE(seq_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updateShortSentMessage
bool TL_updateShortSentMessage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  if (has_media()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MessageMedia*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    media_ = std::unique_ptr<MessageMedia>(o2);
  }
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_updateShortSentMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  iobw.writeLE(date_);
  if (has_media()) media_->SerializeToIOBuf(iobw);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photos_photos
bool TL_photos_photos::Decode(IOBufReader& iobr) {
  photos_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_photos_photos::Encode(IOBufWriter& iobw) const {
  photos_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photos_photosSlice
bool TL_photos_photosSlice::Decode(IOBufReader& iobr) {
  count_ = iobr.readLE<int32_t>();
  photos_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_photos_photosSlice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(count_);
  photos_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photos_photo
bool TL_photos_photo::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<Photo>(o2);
  }
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_photos_photo::Encode(IOBufWriter& iobw) const {
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_file
bool TL_upload_file::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<storage_FileType*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    type_ = std::unique_ptr<storage_FileType>(o2);
  }
  mtime_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_upload_file::Encode(IOBufWriter& iobw) const {
  if (!type_) return false;
  type_-> SerializeToIOBuf(iobw);
  iobw.writeLE(mtime_);
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_fileCdnRedirect
bool TL_upload_fileCdnRedirect::Decode(IOBufReader& iobr) {
  dc_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &file_token_);
  ReadString(iobr, &encryption_key_);
  ReadString(iobr, &encryption_iv_);
  return true;
}
bool TL_upload_fileCdnRedirect::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(dc_id_);
  WriteString(iobw, file_token_);
  WriteString(iobw, encryption_key_);
  WriteString(iobw, encryption_iv_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// dcOption
bool TL_dcOption::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &ip_address_);
  port_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_dcOption::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  WriteString(iobw, ip_address_);
  iobw.writeLE(port_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// config
bool TL_config::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  expires_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    test_mode_ = std::unique_ptr<Bool>(o2);
  }
  this_dc_ = iobr.readLE<int32_t>();
  dc_options_.ParseFromIOBuf(iobr);
  chat_size_max_ = iobr.readLE<int32_t>();
  megagroup_size_max_ = iobr.readLE<int32_t>();
  forwarded_count_max_ = iobr.readLE<int32_t>();
  online_update_period_ms_ = iobr.readLE<int32_t>();
  offline_blur_timeout_ms_ = iobr.readLE<int32_t>();
  offline_idle_timeout_ms_ = iobr.readLE<int32_t>();
  online_cloud_timeout_ms_ = iobr.readLE<int32_t>();
  notify_cloud_delay_ms_ = iobr.readLE<int32_t>();
  notify_default_delay_ms_ = iobr.readLE<int32_t>();
  chat_big_size_ = iobr.readLE<int32_t>();
  push_chat_period_ms_ = iobr.readLE<int32_t>();
  push_chat_limit_ = iobr.readLE<int32_t>();
  saved_gifs_limit_ = iobr.readLE<int32_t>();
  edit_time_limit_ = iobr.readLE<int32_t>();
  rating_e_decay_ = iobr.readLE<int32_t>();
  stickers_recent_limit_ = iobr.readLE<int32_t>();
  if (has_tmp_sessions()) {
    tmp_sessions_ = iobr.readLE<int32_t>();
  }
  pinned_dialogs_count_max_ = iobr.readLE<int32_t>();
  call_receive_timeout_ms_ = iobr.readLE<int32_t>();
  call_ring_timeout_ms_ = iobr.readLE<int32_t>();
  call_connect_timeout_ms_ = iobr.readLE<int32_t>();
  call_packet_timeout_ms_ = iobr.readLE<int32_t>();
  ReadString(iobr, &me_url_prefix_);
  disabled_features_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_config::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(date_);
  iobw.writeLE(expires_);
  if (!test_mode_) return false;
  test_mode_-> SerializeToIOBuf(iobw);
  iobw.writeLE(this_dc_);
  dc_options_.SerializeToIOBuf(iobw);
  iobw.writeLE(chat_size_max_);
  iobw.writeLE(megagroup_size_max_);
  iobw.writeLE(forwarded_count_max_);
  iobw.writeLE(online_update_period_ms_);
  iobw.writeLE(offline_blur_timeout_ms_);
  iobw.writeLE(offline_idle_timeout_ms_);
  iobw.writeLE(online_cloud_timeout_ms_);
  iobw.writeLE(notify_cloud_delay_ms_);
  iobw.writeLE(notify_default_delay_ms_);
  iobw.writeLE(chat_big_size_);
  iobw.writeLE(push_chat_period_ms_);
  iobw.writeLE(push_chat_limit_);
  iobw.writeLE(saved_gifs_limit_);
  iobw.writeLE(edit_time_limit_);
  iobw.writeLE(rating_e_decay_);
  iobw.writeLE(stickers_recent_limit_);
  if (has_tmp_sessions()) iobw.writeLE(tmp_sessions_);
  iobw.writeLE(pinned_dialogs_count_max_);
  iobw.writeLE(call_receive_timeout_ms_);
  iobw.writeLE(call_ring_timeout_ms_);
  iobw.writeLE(call_connect_timeout_ms_);
  iobw.writeLE(call_packet_timeout_ms_);
  WriteString(iobw, me_url_prefix_);
  disabled_features_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// nearestDc
bool TL_nearestDc::Decode(IOBufReader& iobr) {
  ReadString(iobr, &country_);
  this_dc_ = iobr.readLE<int32_t>();
  nearest_dc_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_nearestDc::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, country_);
  iobw.writeLE(this_dc_);
  iobw.writeLE(nearest_dc_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_appUpdate
bool TL_help_appUpdate::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    critical_ = std::unique_ptr<Bool>(o2);
  }
  ReadString(iobr, &url_);
  ReadString(iobr, &text_);
  return true;
}
bool TL_help_appUpdate::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  if (!critical_) return false;
  critical_-> SerializeToIOBuf(iobw);
  WriteString(iobw, url_);
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_noAppUpdate
bool TL_help_noAppUpdate::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_help_noAppUpdate::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_inviteText
bool TL_help_inviteText::Decode(IOBufReader& iobr) {
  ReadString(iobr, &message_);
  return true;
}
bool TL_help_inviteText::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, message_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedChatEmpty
bool TL_encryptedChatEmpty::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_encryptedChatEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedChatWaiting
bool TL_encryptedChatWaiting::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  admin_id_ = iobr.readLE<int32_t>();
  participant_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_encryptedChatWaiting::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  iobw.writeLE(admin_id_);
  iobw.writeLE(participant_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedChatRequested
bool TL_encryptedChatRequested::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  admin_id_ = iobr.readLE<int32_t>();
  participant_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &g_a_);
  return true;
}
bool TL_encryptedChatRequested::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  iobw.writeLE(admin_id_);
  iobw.writeLE(participant_id_);
  WriteString(iobw, g_a_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedChat
bool TL_encryptedChat::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  admin_id_ = iobr.readLE<int32_t>();
  participant_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &g_a_or_b_);
  key_fingerprint_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_encryptedChat::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  iobw.writeLE(admin_id_);
  iobw.writeLE(participant_id_);
  WriteString(iobw, g_a_or_b_);
  iobw.writeLE(key_fingerprint_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedChatDiscarded
bool TL_encryptedChatDiscarded::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_encryptedChatDiscarded::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputEncryptedChat
bool TL_inputEncryptedChat::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputEncryptedChat::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedFileEmpty
bool TL_encryptedFileEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_encryptedFileEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedFile
bool TL_encryptedFile::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  size_ = iobr.readLE<int32_t>();
  dc_id_ = iobr.readLE<int32_t>();
  key_fingerprint_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_encryptedFile::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(size_);
  iobw.writeLE(dc_id_);
  iobw.writeLE(key_fingerprint_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputEncryptedFileEmpty
bool TL_inputEncryptedFileEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputEncryptedFileEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputEncryptedFileUploaded
bool TL_inputEncryptedFileUploaded::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  parts_ = iobr.readLE<int32_t>();
  ReadString(iobr, &md5_checksum_);
  key_fingerprint_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_inputEncryptedFileUploaded::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(parts_);
  WriteString(iobw, md5_checksum_);
  iobw.writeLE(key_fingerprint_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputEncryptedFile
bool TL_inputEncryptedFile::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputEncryptedFile::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputEncryptedFileBigUploaded
bool TL_inputEncryptedFileBigUploaded::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  parts_ = iobr.readLE<int32_t>();
  key_fingerprint_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_inputEncryptedFileBigUploaded::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(parts_);
  iobw.writeLE(key_fingerprint_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedMessage
bool TL_encryptedMessage::Decode(IOBufReader& iobr) {
  random_id_ = iobr.readLE<int64_t>();
  chat_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<EncryptedFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_ = std::unique_ptr<EncryptedFile>(o2);
  }
  return true;
}
bool TL_encryptedMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(random_id_);
  iobw.writeLE(chat_id_);
  iobw.writeLE(date_);
  WriteString(iobw, bytes_);
  if (!file_) return false;
  file_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// encryptedMessageService
bool TL_encryptedMessageService::Decode(IOBufReader& iobr) {
  random_id_ = iobr.readLE<int64_t>();
  chat_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_encryptedMessageService::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(random_id_);
  iobw.writeLE(chat_id_);
  iobw.writeLE(date_);
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_dhConfigNotModified
bool TL_messages_dhConfigNotModified::Decode(IOBufReader& iobr) {
  ReadString(iobr, &random_);
  return true;
}
bool TL_messages_dhConfigNotModified::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, random_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_dhConfig
bool TL_messages_dhConfig::Decode(IOBufReader& iobr) {
  g_ = iobr.readLE<int32_t>();
  ReadString(iobr, &p_);
  version_ = iobr.readLE<int32_t>();
  ReadString(iobr, &random_);
  return true;
}
bool TL_messages_dhConfig::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(g_);
  WriteString(iobw, p_);
  iobw.writeLE(version_);
  WriteString(iobw, random_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_sentEncryptedMessage
bool TL_messages_sentEncryptedMessage::Decode(IOBufReader& iobr) {
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_sentEncryptedMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_sentEncryptedFile
bool TL_messages_sentEncryptedFile::Decode(IOBufReader& iobr) {
  date_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<EncryptedFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_ = std::unique_ptr<EncryptedFile>(o2);
  }
  return true;
}
bool TL_messages_sentEncryptedFile::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(date_);
  if (!file_) return false;
  file_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputDocumentEmpty
bool TL_inputDocumentEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputDocumentEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputDocument
bool TL_inputDocument::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputDocument::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// documentEmpty
bool TL_documentEmpty::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_documentEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// document
bool TL_document::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  ReadString(iobr, &mime_type_);
  size_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhotoSize*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    thumb_ = std::unique_ptr<PhotoSize>(o2);
  }
  dc_id_ = iobr.readLE<int32_t>();
  version_ = iobr.readLE<int32_t>();
  attributes_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_document::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  WriteString(iobw, mime_type_);
  iobw.writeLE(size_);
  if (!thumb_) return false;
  thumb_-> SerializeToIOBuf(iobw);
  iobw.writeLE(dc_id_);
  iobw.writeLE(version_);
  attributes_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_support
bool TL_help_support::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<User*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_ = std::unique_ptr<User>(o2);
  }
  return true;
}
bool TL_help_support::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  if (!user_) return false;
  user_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// notifyPeer
bool TL_notifyPeer::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  return true;
}
bool TL_notifyPeer::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// notifyUsers
bool TL_notifyUsers::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_notifyUsers::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// notifyChats
bool TL_notifyChats::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_notifyChats::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// notifyAll
bool TL_notifyAll::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_notifyAll::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageTypingAction
bool TL_sendMessageTypingAction::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_sendMessageTypingAction::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageCancelAction
bool TL_sendMessageCancelAction::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_sendMessageCancelAction::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageRecordVideoAction
bool TL_sendMessageRecordVideoAction::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_sendMessageRecordVideoAction::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageUploadVideoAction
bool TL_sendMessageUploadVideoAction::Decode(IOBufReader& iobr) {
  progress_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_sendMessageUploadVideoAction::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(progress_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageRecordAudioAction
bool TL_sendMessageRecordAudioAction::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_sendMessageRecordAudioAction::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageUploadAudioAction
bool TL_sendMessageUploadAudioAction::Decode(IOBufReader& iobr) {
  progress_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_sendMessageUploadAudioAction::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(progress_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageUploadPhotoAction
bool TL_sendMessageUploadPhotoAction::Decode(IOBufReader& iobr) {
  progress_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_sendMessageUploadPhotoAction::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(progress_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageUploadDocumentAction
bool TL_sendMessageUploadDocumentAction::Decode(IOBufReader& iobr) {
  progress_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_sendMessageUploadDocumentAction::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(progress_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageGeoLocationAction
bool TL_sendMessageGeoLocationAction::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_sendMessageGeoLocationAction::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageChooseContactAction
bool TL_sendMessageChooseContactAction::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_sendMessageChooseContactAction::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageGamePlayAction
bool TL_sendMessageGamePlayAction::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_sendMessageGamePlayAction::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageRecordRoundAction
bool TL_sendMessageRecordRoundAction::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_sendMessageRecordRoundAction::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// sendMessageUploadRoundAction
bool TL_sendMessageUploadRoundAction::Decode(IOBufReader& iobr) {
  progress_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_sendMessageUploadRoundAction::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(progress_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_found
bool TL_contacts_found::Decode(IOBufReader& iobr) {
  results_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_found::Encode(IOBufWriter& iobw) const {
  results_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyKeyStatusTimestamp
bool TL_inputPrivacyKeyStatusTimestamp::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPrivacyKeyStatusTimestamp::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyKeyChatInvite
bool TL_inputPrivacyKeyChatInvite::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPrivacyKeyChatInvite::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyKeyPhoneCall
bool TL_inputPrivacyKeyPhoneCall::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPrivacyKeyPhoneCall::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyKeyStatusTimestamp
bool TL_privacyKeyStatusTimestamp::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_privacyKeyStatusTimestamp::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyKeyChatInvite
bool TL_privacyKeyChatInvite::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_privacyKeyChatInvite::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyKeyPhoneCall
bool TL_privacyKeyPhoneCall::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_privacyKeyPhoneCall::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyValueAllowContacts
bool TL_inputPrivacyValueAllowContacts::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPrivacyValueAllowContacts::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyValueAllowAll
bool TL_inputPrivacyValueAllowAll::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPrivacyValueAllowAll::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyValueAllowUsers
bool TL_inputPrivacyValueAllowUsers::Decode(IOBufReader& iobr) {
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_inputPrivacyValueAllowUsers::Encode(IOBufWriter& iobw) const {
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyValueDisallowContacts
bool TL_inputPrivacyValueDisallowContacts::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPrivacyValueDisallowContacts::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyValueDisallowAll
bool TL_inputPrivacyValueDisallowAll::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputPrivacyValueDisallowAll::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPrivacyValueDisallowUsers
bool TL_inputPrivacyValueDisallowUsers::Decode(IOBufReader& iobr) {
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_inputPrivacyValueDisallowUsers::Encode(IOBufWriter& iobw) const {
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyValueAllowContacts
bool TL_privacyValueAllowContacts::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_privacyValueAllowContacts::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyValueAllowAll
bool TL_privacyValueAllowAll::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_privacyValueAllowAll::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyValueAllowUsers
bool TL_privacyValueAllowUsers::Decode(IOBufReader& iobr) {
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_privacyValueAllowUsers::Encode(IOBufWriter& iobw) const {
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyValueDisallowContacts
bool TL_privacyValueDisallowContacts::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_privacyValueDisallowContacts::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyValueDisallowAll
bool TL_privacyValueDisallowAll::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_privacyValueDisallowAll::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// privacyValueDisallowUsers
bool TL_privacyValueDisallowUsers::Decode(IOBufReader& iobr) {
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_privacyValueDisallowUsers::Encode(IOBufWriter& iobw) const {
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_privacyRules
bool TL_account_privacyRules::Decode(IOBufReader& iobr) {
  rules_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_account_privacyRules::Encode(IOBufWriter& iobw) const {
  rules_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// accountDaysTTL
bool TL_accountDaysTTL::Decode(IOBufReader& iobr) {
  days_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_accountDaysTTL::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(days_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// documentAttributeImageSize
bool TL_documentAttributeImageSize::Decode(IOBufReader& iobr) {
  w_ = iobr.readLE<int32_t>();
  h_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_documentAttributeImageSize::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(w_);
  iobw.writeLE(h_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// documentAttributeAnimated
bool TL_documentAttributeAnimated::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_documentAttributeAnimated::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// documentAttributeSticker
bool TL_documentAttributeSticker::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &alt_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputStickerSet*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    stickerset_ = std::unique_ptr<InputStickerSet>(o2);
  }
  if (has_mask_coords()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MaskCoords*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    mask_coords_ = std::unique_ptr<MaskCoords>(o2);
  }
  return true;
}
bool TL_documentAttributeSticker::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, alt_);
  if (!stickerset_) return false;
  stickerset_-> SerializeToIOBuf(iobw);
  if (has_mask_coords()) mask_coords_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// documentAttributeVideo
bool TL_documentAttributeVideo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  duration_ = iobr.readLE<int32_t>();
  w_ = iobr.readLE<int32_t>();
  h_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_documentAttributeVideo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(duration_);
  iobw.writeLE(w_);
  iobw.writeLE(h_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// documentAttributeAudio
bool TL_documentAttributeAudio::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  duration_ = iobr.readLE<int32_t>();
  if (has_title()) {
    ReadString(iobr, &title_);
  }
  if (has_performer()) {
    ReadString(iobr, &performer_);
  }
  if (has_waveform()) {
    ReadString(iobr, &waveform_);
  }
  return true;
}
bool TL_documentAttributeAudio::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(duration_);
  if (has_title()) WriteString(iobw, title_);
  if (has_performer()) WriteString(iobw, performer_);
  if (has_waveform()) WriteString(iobw, waveform_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// documentAttributeFilename
bool TL_documentAttributeFilename::Decode(IOBufReader& iobr) {
  ReadString(iobr, &file_name_);
  return true;
}
bool TL_documentAttributeFilename::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, file_name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// documentAttributeHasStickers
bool TL_documentAttributeHasStickers::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_documentAttributeHasStickers::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_stickersNotModified
bool TL_messages_stickersNotModified::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messages_stickersNotModified::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_stickers
bool TL_messages_stickers::Decode(IOBufReader& iobr) {
  ReadString(iobr, &hash_);
  stickers_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_stickers::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, hash_);
  stickers_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// stickerPack
bool TL_stickerPack::Decode(IOBufReader& iobr) {
  ReadString(iobr, &emoticon_);
  documents_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_stickerPack::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, emoticon_);
  documents_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_allStickersNotModified
bool TL_messages_allStickersNotModified::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messages_allStickersNotModified::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_allStickers
bool TL_messages_allStickers::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int32_t>();
  sets_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_allStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  sets_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// disabledFeature
bool TL_disabledFeature::Decode(IOBufReader& iobr) {
  ReadString(iobr, &feature_);
  ReadString(iobr, &description_);
  return true;
}
bool TL_disabledFeature::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, feature_);
  WriteString(iobw, description_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_affectedMessages
bool TL_messages_affectedMessages::Decode(IOBufReader& iobr) {
  pts_ = iobr.readLE<int32_t>();
  pts_count_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_affectedMessages::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(pts_);
  iobw.writeLE(pts_count_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contactLinkUnknown
bool TL_contactLinkUnknown::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_contactLinkUnknown::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contactLinkNone
bool TL_contactLinkNone::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_contactLinkNone::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contactLinkHasPhone
bool TL_contactLinkHasPhone::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_contactLinkHasPhone::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contactLinkContact
bool TL_contactLinkContact::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_contactLinkContact::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// webPageEmpty
bool TL_webPageEmpty::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_webPageEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// webPagePending
bool TL_webPagePending::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_webPagePending::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// webPage
bool TL_webPage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &url_);
  ReadString(iobr, &display_url_);
  hash_ = iobr.readLE<int32_t>();
  if (has_type()) {
    ReadString(iobr, &type_);
  }
  if (has_site_name()) {
    ReadString(iobr, &site_name_);
  }
  if (has_title()) {
    ReadString(iobr, &title_);
  }
  if (has_description()) {
    ReadString(iobr, &description_);
  }
  if (has_photo()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<Photo>(o2);
  }
  if (has_embed_url()) {
    ReadString(iobr, &embed_url_);
  }
  if (has_embed_type()) {
    ReadString(iobr, &embed_type_);
  }
  if (has_embed_width()) {
    embed_width_ = iobr.readLE<int32_t>();
  }
  if (has_embed_height()) {
    embed_height_ = iobr.readLE<int32_t>();
  }
  if (has_duration()) {
    duration_ = iobr.readLE<int32_t>();
  }
  if (has_author()) {
    ReadString(iobr, &author_);
  }
  if (has_document()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Document*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    document_ = std::unique_ptr<Document>(o2);
  }
  if (has_cached_page()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Page*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    cached_page_ = std::unique_ptr<Page>(o2);
  }
  return true;
}
bool TL_webPage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  WriteString(iobw, url_);
  WriteString(iobw, display_url_);
  iobw.writeLE(hash_);
  if (has_type()) WriteString(iobw, type_);
  if (has_site_name()) WriteString(iobw, site_name_);
  if (has_title()) WriteString(iobw, title_);
  if (has_description()) WriteString(iobw, description_);
  if (has_photo()) photo_->SerializeToIOBuf(iobw);
  if (has_embed_url()) WriteString(iobw, embed_url_);
  if (has_embed_type()) WriteString(iobw, embed_type_);
  if (has_embed_width()) iobw.writeLE(embed_width_);
  if (has_embed_height()) iobw.writeLE(embed_height_);
  if (has_duration()) iobw.writeLE(duration_);
  if (has_author()) WriteString(iobw, author_);
  if (has_document()) document_->SerializeToIOBuf(iobw);
  if (has_cached_page()) cached_page_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// webPageNotModified
bool TL_webPageNotModified::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_webPageNotModified::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// authorization
bool TL_authorization::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int64_t>();
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &device_model_);
  ReadString(iobr, &platform_);
  ReadString(iobr, &system_version_);
  api_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &app_name_);
  ReadString(iobr, &app_version_);
  date_created_ = iobr.readLE<int32_t>();
  date_active_ = iobr.readLE<int32_t>();
  ReadString(iobr, &ip_);
  ReadString(iobr, &country_);
  ReadString(iobr, &region_);
  return true;
}
bool TL_authorization::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  iobw.writeLE(flags_);
  WriteString(iobw, device_model_);
  WriteString(iobw, platform_);
  WriteString(iobw, system_version_);
  iobw.writeLE(api_id_);
  WriteString(iobw, app_name_);
  WriteString(iobw, app_version_);
  iobw.writeLE(date_created_);
  iobw.writeLE(date_active_);
  WriteString(iobw, ip_);
  WriteString(iobw, country_);
  WriteString(iobw, region_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_authorizations
bool TL_account_authorizations::Decode(IOBufReader& iobr) {
  authorizations_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_account_authorizations::Encode(IOBufWriter& iobw) const {
  authorizations_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_noPassword
bool TL_account_noPassword::Decode(IOBufReader& iobr) {
  ReadString(iobr, &new_salt_);
  ReadString(iobr, &email_unconfirmed_pattern_);
  return true;
}
bool TL_account_noPassword::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, new_salt_);
  WriteString(iobw, email_unconfirmed_pattern_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_password
bool TL_account_password::Decode(IOBufReader& iobr) {
  ReadString(iobr, &current_salt_);
  ReadString(iobr, &new_salt_);
  ReadString(iobr, &hint_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    has_recovery_ = std::unique_ptr<Bool>(o2);
  }
  ReadString(iobr, &email_unconfirmed_pattern_);
  return true;
}
bool TL_account_password::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, current_salt_);
  WriteString(iobw, new_salt_);
  WriteString(iobw, hint_);
  if (!has_recovery_) return false;
  has_recovery_-> SerializeToIOBuf(iobw);
  WriteString(iobw, email_unconfirmed_pattern_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_passwordSettings
bool TL_account_passwordSettings::Decode(IOBufReader& iobr) {
  ReadString(iobr, &email_);
  return true;
}
bool TL_account_passwordSettings::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, email_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_passwordInputSettings
bool TL_account_passwordInputSettings::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_new_salt()) {
    ReadString(iobr, &new_salt_);
  }
  if (has_new_password_hash()) {
    ReadString(iobr, &new_password_hash_);
  }
  if (has_hint()) {
    ReadString(iobr, &hint_);
  }
  if (has_email()) {
    ReadString(iobr, &email_);
  }
  return true;
}
bool TL_account_passwordInputSettings::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_new_salt()) WriteString(iobw, new_salt_);
  if (has_new_password_hash()) WriteString(iobw, new_password_hash_);
  if (has_hint()) WriteString(iobw, hint_);
  if (has_email()) WriteString(iobw, email_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_passwordRecovery
bool TL_auth_passwordRecovery::Decode(IOBufReader& iobr) {
  ReadString(iobr, &email_pattern_);
  return true;
}
bool TL_auth_passwordRecovery::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, email_pattern_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// receivedNotifyMessage
bool TL_receivedNotifyMessage::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  flags_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_receivedNotifyMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(flags_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatInviteEmpty
bool TL_chatInviteEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_chatInviteEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatInviteExported
bool TL_chatInviteExported::Decode(IOBufReader& iobr) {
  ReadString(iobr, &link_);
  return true;
}
bool TL_chatInviteExported::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, link_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatInviteAlready
bool TL_chatInviteAlready::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Chat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    chat_ = std::unique_ptr<Chat>(o2);
  }
  return true;
}
bool TL_chatInviteAlready::Encode(IOBufWriter& iobw) const {
  if (!chat_) return false;
  chat_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// chatInvite
bool TL_chatInvite::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChatPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<ChatPhoto>(o2);
  }
  participants_count_ = iobr.readLE<int32_t>();
  if (has_participants()) {
    participants_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_chatInvite::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, title_);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  iobw.writeLE(participants_count_);
  if (has_participants()) participants_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputStickerSetEmpty
bool TL_inputStickerSetEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputStickerSetEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputStickerSetID
bool TL_inputStickerSetID::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputStickerSetID::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputStickerSetShortName
bool TL_inputStickerSetShortName::Decode(IOBufReader& iobr) {
  ReadString(iobr, &short_name_);
  return true;
}
bool TL_inputStickerSetShortName::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, short_name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// stickerSet
bool TL_stickerSet::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  ReadString(iobr, &title_);
  ReadString(iobr, &short_name_);
  count_ = iobr.readLE<int32_t>();
  hash_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_stickerSet::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  WriteString(iobw, title_);
  WriteString(iobw, short_name_);
  iobw.writeLE(count_);
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_stickerSet
bool TL_messages_stickerSet::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<StickerSet*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    set_ = std::unique_ptr<StickerSet>(o2);
  }
  packs_.ParseFromIOBuf(iobr);
  documents_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_stickerSet::Encode(IOBufWriter& iobw) const {
  if (!set_) return false;
  set_-> SerializeToIOBuf(iobw);
  packs_.SerializeToIOBuf(iobw);
  documents_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botCommand
bool TL_botCommand::Decode(IOBufReader& iobr) {
  ReadString(iobr, &command_);
  ReadString(iobr, &description_);
  return true;
}
bool TL_botCommand::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, command_);
  WriteString(iobw, description_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botInfo
bool TL_botInfo::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &description_);
  commands_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_botInfo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  WriteString(iobw, description_);
  commands_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButton
bool TL_keyboardButton::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  return true;
}
bool TL_keyboardButton::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButtonUrl
bool TL_keyboardButtonUrl::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  ReadString(iobr, &url_);
  return true;
}
bool TL_keyboardButtonUrl::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  WriteString(iobw, url_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButtonCallback
bool TL_keyboardButtonCallback::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  ReadString(iobr, &data_);
  return true;
}
bool TL_keyboardButtonCallback::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  WriteString(iobw, data_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButtonRequestPhone
bool TL_keyboardButtonRequestPhone::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  return true;
}
bool TL_keyboardButtonRequestPhone::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButtonRequestGeoLocation
bool TL_keyboardButtonRequestGeoLocation::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  return true;
}
bool TL_keyboardButtonRequestGeoLocation::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButtonSwitchInline
bool TL_keyboardButtonSwitchInline::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &text_);
  ReadString(iobr, &query_);
  return true;
}
bool TL_keyboardButtonSwitchInline::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, text_);
  WriteString(iobw, query_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButtonGame
bool TL_keyboardButtonGame::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  return true;
}
bool TL_keyboardButtonGame::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButtonBuy
bool TL_keyboardButtonBuy::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  return true;
}
bool TL_keyboardButtonBuy::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// keyboardButtonRow
bool TL_keyboardButtonRow::Decode(IOBufReader& iobr) {
  buttons_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_keyboardButtonRow::Encode(IOBufWriter& iobw) const {
  buttons_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// replyKeyboardHide
bool TL_replyKeyboardHide::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_replyKeyboardHide::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// replyKeyboardForceReply
bool TL_replyKeyboardForceReply::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_replyKeyboardForceReply::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// replyKeyboardMarkup
bool TL_replyKeyboardMarkup::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  rows_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_replyKeyboardMarkup::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  rows_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// replyInlineMarkup
bool TL_replyInlineMarkup::Decode(IOBufReader& iobr) {
  rows_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_replyInlineMarkup::Encode(IOBufWriter& iobw) const {
  rows_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityUnknown
bool TL_messageEntityUnknown::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityUnknown::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityMention
bool TL_messageEntityMention::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityMention::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityHashtag
bool TL_messageEntityHashtag::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityHashtag::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityBotCommand
bool TL_messageEntityBotCommand::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityBotCommand::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityUrl
bool TL_messageEntityUrl::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityUrl::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityEmail
bool TL_messageEntityEmail::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityEmail::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityBold
bool TL_messageEntityBold::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityBold::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityItalic
bool TL_messageEntityItalic::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityItalic::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityCode
bool TL_messageEntityCode::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityCode::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityPre
bool TL_messageEntityPre::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  ReadString(iobr, &language_);
  return true;
}
bool TL_messageEntityPre::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  WriteString(iobw, language_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityTextUrl
bool TL_messageEntityTextUrl::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  ReadString(iobr, &url_);
  return true;
}
bool TL_messageEntityTextUrl::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  WriteString(iobw, url_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageEntityMentionName
bool TL_messageEntityMentionName::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  user_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageEntityMentionName::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  iobw.writeLE(user_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputMessageEntityMentionName
bool TL_inputMessageEntityMentionName::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  length_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_inputMessageEntityMentionName::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(length_);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputChannelEmpty
bool TL_inputChannelEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_inputChannelEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputChannel
bool TL_inputChannel::Decode(IOBufReader& iobr) {
  channel_id_ = iobr.readLE<int32_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputChannel::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(channel_id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_resolvedPeer
bool TL_contacts_resolvedPeer::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_resolvedPeer::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageRange
bool TL_messageRange::Decode(IOBufReader& iobr) {
  min_id_ = iobr.readLE<int32_t>();
  max_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messageRange::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(min_id_);
  iobw.writeLE(max_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_channelDifferenceEmpty
bool TL_updates_channelDifferenceEmpty::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  pts_ = iobr.readLE<int32_t>();
  if (has_timeout()) {
    timeout_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_updates_channelDifferenceEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(pts_);
  if (has_timeout()) iobw.writeLE(timeout_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_channelDifferenceTooLong
bool TL_updates_channelDifferenceTooLong::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  pts_ = iobr.readLE<int32_t>();
  if (has_timeout()) {
    timeout_ = iobr.readLE<int32_t>();
  }
  top_message_ = iobr.readLE<int32_t>();
  read_inbox_max_id_ = iobr.readLE<int32_t>();
  read_outbox_max_id_ = iobr.readLE<int32_t>();
  unread_count_ = iobr.readLE<int32_t>();
  messages_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_updates_channelDifferenceTooLong::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(pts_);
  if (has_timeout()) iobw.writeLE(timeout_);
  iobw.writeLE(top_message_);
  iobw.writeLE(read_inbox_max_id_);
  iobw.writeLE(read_outbox_max_id_);
  iobw.writeLE(unread_count_);
  messages_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_channelDifference
bool TL_updates_channelDifference::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  pts_ = iobr.readLE<int32_t>();
  if (has_timeout()) {
    timeout_ = iobr.readLE<int32_t>();
  }
  new_messages_.ParseFromIOBuf(iobr);
  other_updates_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_updates_channelDifference::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(pts_);
  if (has_timeout()) iobw.writeLE(timeout_);
  new_messages_.SerializeToIOBuf(iobw);
  other_updates_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelMessagesFilterEmpty
bool TL_channelMessagesFilterEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channelMessagesFilterEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelMessagesFilter
bool TL_channelMessagesFilter::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ranges_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_channelMessagesFilter::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  ranges_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipant
bool TL_channelParticipant::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channelParticipant::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantSelf
bool TL_channelParticipantSelf::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  inviter_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channelParticipantSelf::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(inviter_id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantModerator
bool TL_channelParticipantModerator::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  inviter_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channelParticipantModerator::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(inviter_id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantEditor
bool TL_channelParticipantEditor::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  inviter_id_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channelParticipantEditor::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(inviter_id_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantKicked
bool TL_channelParticipantKicked::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  kicked_by_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channelParticipantKicked::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  iobw.writeLE(kicked_by_);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantCreator
bool TL_channelParticipantCreator::Decode(IOBufReader& iobr) {
  user_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channelParticipantCreator::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(user_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantsRecent
bool TL_channelParticipantsRecent::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channelParticipantsRecent::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantsAdmins
bool TL_channelParticipantsAdmins::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channelParticipantsAdmins::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantsKicked
bool TL_channelParticipantsKicked::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channelParticipantsKicked::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelParticipantsBots
bool TL_channelParticipantsBots::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channelParticipantsBots::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelRoleEmpty
bool TL_channelRoleEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channelRoleEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelRoleModerator
bool TL_channelRoleModerator::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channelRoleModerator::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channelRoleEditor
bool TL_channelRoleEditor::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channelRoleEditor::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_channelParticipants
bool TL_channels_channelParticipants::Decode(IOBufReader& iobr) {
  count_ = iobr.readLE<int32_t>();
  participants_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_channels_channelParticipants::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(count_);
  participants_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_channelParticipant
bool TL_channels_channelParticipant::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChannelParticipant*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    participant_ = std::unique_ptr<ChannelParticipant>(o2);
  }
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_channels_channelParticipant::Encode(IOBufWriter& iobw) const {
  if (!participant_) return false;
  participant_-> SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_termsOfService
bool TL_help_termsOfService::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  return true;
}
bool TL_help_termsOfService::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// foundGif
bool TL_foundGif::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  ReadString(iobr, &thumb_url_);
  ReadString(iobr, &content_url_);
  ReadString(iobr, &content_type_);
  w_ = iobr.readLE<int32_t>();
  h_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_foundGif::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  WriteString(iobw, thumb_url_);
  WriteString(iobw, content_url_);
  WriteString(iobw, content_type_);
  iobw.writeLE(w_);
  iobw.writeLE(h_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// foundGifCached
bool TL_foundGifCached::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<Photo>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Document*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    document_ = std::unique_ptr<Document>(o2);
  }
  return true;
}
bool TL_foundGifCached::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  if (!document_) return false;
  document_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_foundGifs
bool TL_messages_foundGifs::Decode(IOBufReader& iobr) {
  next_offset_ = iobr.readLE<int32_t>();
  results_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_foundGifs::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(next_offset_);
  results_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_savedGifsNotModified
bool TL_messages_savedGifsNotModified::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messages_savedGifsNotModified::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_savedGifs
bool TL_messages_savedGifs::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int32_t>();
  gifs_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_savedGifs::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  gifs_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineMessageMediaAuto
bool TL_inputBotInlineMessageMediaAuto::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &caption_);
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_inputBotInlineMessageMediaAuto::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, caption_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineMessageText
bool TL_inputBotInlineMessageText::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &message_);
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_inputBotInlineMessageText::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, message_);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineMessageMediaGeo
bool TL_inputBotInlineMessageMediaGeo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputGeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_point_ = std::unique_ptr<InputGeoPoint>(o2);
  }
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_inputBotInlineMessageMediaGeo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!geo_point_) return false;
  geo_point_-> SerializeToIOBuf(iobw);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineMessageMediaVenue
bool TL_inputBotInlineMessageMediaVenue::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputGeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_point_ = std::unique_ptr<InputGeoPoint>(o2);
  }
  ReadString(iobr, &title_);
  ReadString(iobr, &address_);
  ReadString(iobr, &provider_);
  ReadString(iobr, &venue_id_);
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_inputBotInlineMessageMediaVenue::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!geo_point_) return false;
  geo_point_-> SerializeToIOBuf(iobw);
  WriteString(iobw, title_);
  WriteString(iobw, address_);
  WriteString(iobw, provider_);
  WriteString(iobw, venue_id_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineMessageMediaContact
bool TL_inputBotInlineMessageMediaContact::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &first_name_);
  ReadString(iobr, &last_name_);
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_inputBotInlineMessageMediaContact::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, phone_number_);
  WriteString(iobw, first_name_);
  WriteString(iobw, last_name_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineMessageGame
bool TL_inputBotInlineMessageGame::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_inputBotInlineMessageGame::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineResult
bool TL_inputBotInlineResult::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &id_);
  ReadString(iobr, &type_);
  if (has_title()) {
    ReadString(iobr, &title_);
  }
  if (has_description()) {
    ReadString(iobr, &description_);
  }
  if (has_url()) {
    ReadString(iobr, &url_);
  }
  if (has_thumb_url()) {
    ReadString(iobr, &thumb_url_);
  }
  if (has_content_url()) {
    ReadString(iobr, &content_url_);
  }
  if (has_content_type()) {
    ReadString(iobr, &content_type_);
  }
  if (has_w()) {
    w_ = iobr.readLE<int32_t>();
  }
  if (has_h()) {
    h_ = iobr.readLE<int32_t>();
  }
  if (has_duration()) {
    duration_ = iobr.readLE<int32_t>();
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    send_message_ = std::unique_ptr<InputBotInlineMessage>(o2);
  }
  return true;
}
bool TL_inputBotInlineResult::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, id_);
  WriteString(iobw, type_);
  if (has_title()) WriteString(iobw, title_);
  if (has_description()) WriteString(iobw, description_);
  if (has_url()) WriteString(iobw, url_);
  if (has_thumb_url()) WriteString(iobw, thumb_url_);
  if (has_content_url()) WriteString(iobw, content_url_);
  if (has_content_type()) WriteString(iobw, content_type_);
  if (has_w()) iobw.writeLE(w_);
  if (has_h()) iobw.writeLE(h_);
  if (has_duration()) iobw.writeLE(duration_);
  if (!send_message_) return false;
  send_message_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineResultPhoto
bool TL_inputBotInlineResultPhoto::Decode(IOBufReader& iobr) {
  ReadString(iobr, &id_);
  ReadString(iobr, &type_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<InputPhoto>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    send_message_ = std::unique_ptr<InputBotInlineMessage>(o2);
  }
  return true;
}
bool TL_inputBotInlineResultPhoto::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, id_);
  WriteString(iobw, type_);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  if (!send_message_) return false;
  send_message_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineResultDocument
bool TL_inputBotInlineResultDocument::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &id_);
  ReadString(iobr, &type_);
  if (has_title()) {
    ReadString(iobr, &title_);
  }
  if (has_description()) {
    ReadString(iobr, &description_);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputDocument*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    document_ = std::unique_ptr<InputDocument>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    send_message_ = std::unique_ptr<InputBotInlineMessage>(o2);
  }
  return true;
}
bool TL_inputBotInlineResultDocument::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, id_);
  WriteString(iobw, type_);
  if (has_title()) WriteString(iobw, title_);
  if (has_description()) WriteString(iobw, description_);
  if (!document_) return false;
  document_-> SerializeToIOBuf(iobw);
  if (!send_message_) return false;
  send_message_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineResultGame
bool TL_inputBotInlineResultGame::Decode(IOBufReader& iobr) {
  ReadString(iobr, &id_);
  ReadString(iobr, &short_name_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    send_message_ = std::unique_ptr<InputBotInlineMessage>(o2);
  }
  return true;
}
bool TL_inputBotInlineResultGame::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, id_);
  WriteString(iobw, short_name_);
  if (!send_message_) return false;
  send_message_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botInlineMessageMediaAuto
bool TL_botInlineMessageMediaAuto::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &caption_);
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_botInlineMessageMediaAuto::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, caption_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botInlineMessageText
bool TL_botInlineMessageText::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &message_);
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_botInlineMessageText::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, message_);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botInlineMessageMediaGeo
bool TL_botInlineMessageMediaGeo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<GeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_ = std::unique_ptr<GeoPoint>(o2);
  }
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_botInlineMessageMediaGeo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!geo_) return false;
  geo_-> SerializeToIOBuf(iobw);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botInlineMessageMediaVenue
bool TL_botInlineMessageMediaVenue::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<GeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_ = std::unique_ptr<GeoPoint>(o2);
  }
  ReadString(iobr, &title_);
  ReadString(iobr, &address_);
  ReadString(iobr, &provider_);
  ReadString(iobr, &venue_id_);
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_botInlineMessageMediaVenue::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!geo_) return false;
  geo_-> SerializeToIOBuf(iobw);
  WriteString(iobw, title_);
  WriteString(iobw, address_);
  WriteString(iobw, provider_);
  WriteString(iobw, venue_id_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botInlineMessageMediaContact
bool TL_botInlineMessageMediaContact::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &first_name_);
  ReadString(iobr, &last_name_);
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_botInlineMessageMediaContact::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, phone_number_);
  WriteString(iobw, first_name_);
  WriteString(iobw, last_name_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botInlineResult
bool TL_botInlineResult::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &id_);
  ReadString(iobr, &type_);
  if (has_title()) {
    ReadString(iobr, &title_);
  }
  if (has_description()) {
    ReadString(iobr, &description_);
  }
  if (has_url()) {
    ReadString(iobr, &url_);
  }
  if (has_thumb_url()) {
    ReadString(iobr, &thumb_url_);
  }
  if (has_content_url()) {
    ReadString(iobr, &content_url_);
  }
  if (has_content_type()) {
    ReadString(iobr, &content_type_);
  }
  if (has_w()) {
    w_ = iobr.readLE<int32_t>();
  }
  if (has_h()) {
    h_ = iobr.readLE<int32_t>();
  }
  if (has_duration()) {
    duration_ = iobr.readLE<int32_t>();
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<BotInlineMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    send_message_ = std::unique_ptr<BotInlineMessage>(o2);
  }
  return true;
}
bool TL_botInlineResult::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, id_);
  WriteString(iobw, type_);
  if (has_title()) WriteString(iobw, title_);
  if (has_description()) WriteString(iobw, description_);
  if (has_url()) WriteString(iobw, url_);
  if (has_thumb_url()) WriteString(iobw, thumb_url_);
  if (has_content_url()) WriteString(iobw, content_url_);
  if (has_content_type()) WriteString(iobw, content_type_);
  if (has_w()) iobw.writeLE(w_);
  if (has_h()) iobw.writeLE(h_);
  if (has_duration()) iobw.writeLE(duration_);
  if (!send_message_) return false;
  send_message_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// botInlineMediaResult
bool TL_botInlineMediaResult::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &id_);
  ReadString(iobr, &type_);
  if (has_photo()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<Photo>(o2);
  }
  if (has_document()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Document*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    document_ = std::unique_ptr<Document>(o2);
  }
  if (has_title()) {
    ReadString(iobr, &title_);
  }
  if (has_description()) {
    ReadString(iobr, &description_);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<BotInlineMessage*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    send_message_ = std::unique_ptr<BotInlineMessage>(o2);
  }
  return true;
}
bool TL_botInlineMediaResult::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, id_);
  WriteString(iobw, type_);
  if (has_photo()) photo_->SerializeToIOBuf(iobw);
  if (has_document()) document_->SerializeToIOBuf(iobw);
  if (has_title()) WriteString(iobw, title_);
  if (has_description()) WriteString(iobw, description_);
  if (!send_message_) return false;
  send_message_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_botResults
bool TL_messages_botResults::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  if (has_next_offset()) {
    ReadString(iobr, &next_offset_);
  }
  if (has_switch_pm()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InlineBotSwitchPM*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    switch_pm_ = std::unique_ptr<InlineBotSwitchPM>(o2);
  }
  results_.ParseFromIOBuf(iobr);
  cache_time_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_botResults::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  if (has_next_offset()) WriteString(iobw, next_offset_);
  if (has_switch_pm()) switch_pm_->SerializeToIOBuf(iobw);
  results_.SerializeToIOBuf(iobw);
  iobw.writeLE(cache_time_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// exportedMessageLink
bool TL_exportedMessageLink::Decode(IOBufReader& iobr) {
  ReadString(iobr, &link_);
  return true;
}
bool TL_exportedMessageLink::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, link_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messageFwdHeader
bool TL_messageFwdHeader::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_from_id()) {
    from_id_ = iobr.readLE<int32_t>();
  }
  date_ = iobr.readLE<int32_t>();
  if (has_channel_id()) {
    channel_id_ = iobr.readLE<int32_t>();
  }
  if (has_channel_post()) {
    channel_post_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_messageFwdHeader::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_from_id()) iobw.writeLE(from_id_);
  iobw.writeLE(date_);
  if (has_channel_id()) iobw.writeLE(channel_id_);
  if (has_channel_post()) iobw.writeLE(channel_post_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_codeTypeSms
bool TL_auth_codeTypeSms::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_auth_codeTypeSms::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_codeTypeCall
bool TL_auth_codeTypeCall::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_auth_codeTypeCall::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_codeTypeFlashCall
bool TL_auth_codeTypeFlashCall::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_auth_codeTypeFlashCall::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_sentCodeTypeApp
bool TL_auth_sentCodeTypeApp::Decode(IOBufReader& iobr) {
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_auth_sentCodeTypeApp::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_sentCodeTypeSms
bool TL_auth_sentCodeTypeSms::Decode(IOBufReader& iobr) {
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_auth_sentCodeTypeSms::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_sentCodeTypeCall
bool TL_auth_sentCodeTypeCall::Decode(IOBufReader& iobr) {
  length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_auth_sentCodeTypeCall::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_sentCodeTypeFlashCall
bool TL_auth_sentCodeTypeFlashCall::Decode(IOBufReader& iobr) {
  ReadString(iobr, &pattern_);
  return true;
}
bool TL_auth_sentCodeTypeFlashCall::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, pattern_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_botCallbackAnswer
bool TL_messages_botCallbackAnswer::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_message()) {
    ReadString(iobr, &message_);
  }
  if (has_url()) {
    ReadString(iobr, &url_);
  }
  cache_time_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_botCallbackAnswer::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_message()) WriteString(iobw, message_);
  if (has_url()) WriteString(iobw, url_);
  iobw.writeLE(cache_time_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_messageEditData
bool TL_messages_messageEditData::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_messageEditData::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputBotInlineMessageID
bool TL_inputBotInlineMessageID::Decode(IOBufReader& iobr) {
  dc_id_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputBotInlineMessageID::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(dc_id_);
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inlineBotSwitchPM
bool TL_inlineBotSwitchPM::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  ReadString(iobr, &start_param_);
  return true;
}
bool TL_inlineBotSwitchPM::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  WriteString(iobw, start_param_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_peerDialogs
bool TL_messages_peerDialogs::Decode(IOBufReader& iobr) {
  dialogs_.ParseFromIOBuf(iobr);
  messages_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<updates_State*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    state_ = std::unique_ptr<updates_State>(o2);
  }
  return true;
}
bool TL_messages_peerDialogs::Encode(IOBufWriter& iobw) const {
  dialogs_.SerializeToIOBuf(iobw);
  messages_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  if (!state_) return false;
  state_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// topPeer
bool TL_topPeer::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Peer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<Peer>(o2);
  }
  rating_ = iobr.readLE<double>();
  return true;
}
bool TL_topPeer::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(rating_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// topPeerCategoryBotsPM
bool TL_topPeerCategoryBotsPM::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_topPeerCategoryBotsPM::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// topPeerCategoryBotsInline
bool TL_topPeerCategoryBotsInline::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_topPeerCategoryBotsInline::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// topPeerCategoryCorrespondents
bool TL_topPeerCategoryCorrespondents::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_topPeerCategoryCorrespondents::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// topPeerCategoryGroups
bool TL_topPeerCategoryGroups::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_topPeerCategoryGroups::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// topPeerCategoryChannels
bool TL_topPeerCategoryChannels::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_topPeerCategoryChannels::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// topPeerCategoryPeers
bool TL_topPeerCategoryPeers::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<TopPeerCategory*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    category_ = std::unique_ptr<TopPeerCategory>(o2);
  }
  count_ = iobr.readLE<int32_t>();
  peers_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_topPeerCategoryPeers::Encode(IOBufWriter& iobw) const {
  if (!category_) return false;
  category_-> SerializeToIOBuf(iobw);
  iobw.writeLE(count_);
  peers_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_topPeersNotModified
bool TL_contacts_topPeersNotModified::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_contacts_topPeersNotModified::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_topPeers
bool TL_contacts_topPeers::Decode(IOBufReader& iobr) {
  categories_.ParseFromIOBuf(iobr);
  chats_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_topPeers::Encode(IOBufWriter& iobw) const {
  categories_.SerializeToIOBuf(iobw);
  chats_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// draftMessageEmpty
bool TL_draftMessageEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_draftMessageEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// draftMessage
bool TL_draftMessage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  ReadString(iobr, &message_);
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_draftMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  WriteString(iobw, message_);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  iobw.writeLE(date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_featuredStickersNotModified
bool TL_messages_featuredStickersNotModified::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messages_featuredStickersNotModified::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_featuredStickers
bool TL_messages_featuredStickers::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int32_t>();
  sets_.ParseFromIOBuf(iobr);
  unread_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_featuredStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  sets_.SerializeToIOBuf(iobw);
  unread_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_recentStickersNotModified
bool TL_messages_recentStickersNotModified::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messages_recentStickersNotModified::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_recentStickers
bool TL_messages_recentStickers::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int32_t>();
  stickers_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_recentStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  stickers_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_archivedStickers
bool TL_messages_archivedStickers::Decode(IOBufReader& iobr) {
  count_ = iobr.readLE<int32_t>();
  sets_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_archivedStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(count_);
  sets_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_stickerSetInstallResultSuccess
bool TL_messages_stickerSetInstallResultSuccess::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messages_stickerSetInstallResultSuccess::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_stickerSetInstallResultArchive
bool TL_messages_stickerSetInstallResultArchive::Decode(IOBufReader& iobr) {
  sets_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_stickerSetInstallResultArchive::Encode(IOBufWriter& iobw) const {
  sets_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// stickerSetCovered
bool TL_stickerSetCovered::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<StickerSet*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    set_ = std::unique_ptr<StickerSet>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Document*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    cover_ = std::unique_ptr<Document>(o2);
  }
  return true;
}
bool TL_stickerSetCovered::Encode(IOBufWriter& iobw) const {
  if (!set_) return false;
  set_-> SerializeToIOBuf(iobw);
  if (!cover_) return false;
  cover_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// stickerSetMultiCovered
bool TL_stickerSetMultiCovered::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<StickerSet*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    set_ = std::unique_ptr<StickerSet>(o2);
  }
  covers_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_stickerSetMultiCovered::Encode(IOBufWriter& iobw) const {
  if (!set_) return false;
  set_-> SerializeToIOBuf(iobw);
  covers_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// maskCoords
bool TL_maskCoords::Decode(IOBufReader& iobr) {
  n_ = iobr.readLE<int32_t>();
  x_ = iobr.readLE<double>();
  y_ = iobr.readLE<double>();
  zoom_ = iobr.readLE<double>();
  return true;
}
bool TL_maskCoords::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(n_);
  iobw.writeLE(x_);
  iobw.writeLE(y_);
  iobw.writeLE(zoom_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputStickeredMediaPhoto
bool TL_inputStickeredMediaPhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputPhoto>(o2);
  }
  return true;
}
bool TL_inputStickeredMediaPhoto::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputStickeredMediaDocument
bool TL_inputStickeredMediaDocument::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputDocument*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputDocument>(o2);
  }
  return true;
}
bool TL_inputStickeredMediaDocument::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// game
bool TL_game::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  ReadString(iobr, &short_name_);
  ReadString(iobr, &title_);
  ReadString(iobr, &description_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Photo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<Photo>(o2);
  }
  if (has_document()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Document*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    document_ = std::unique_ptr<Document>(o2);
  }
  return true;
}
bool TL_game::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  WriteString(iobw, short_name_);
  WriteString(iobw, title_);
  WriteString(iobw, description_);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  if (has_document()) document_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputGameID
bool TL_inputGameID::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputGameID::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputGameShortName
bool TL_inputGameShortName::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    bot_id_ = std::unique_ptr<InputUser>(o2);
  }
  ReadString(iobr, &short_name_);
  return true;
}
bool TL_inputGameShortName::Encode(IOBufWriter& iobw) const {
  if (!bot_id_) return false;
  bot_id_-> SerializeToIOBuf(iobw);
  WriteString(iobw, short_name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// highScore
bool TL_highScore::Decode(IOBufReader& iobr) {
  pos_ = iobr.readLE<int32_t>();
  user_id_ = iobr.readLE<int32_t>();
  score_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_highScore::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(pos_);
  iobw.writeLE(user_id_);
  iobw.writeLE(score_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_highScores
bool TL_messages_highScores::Decode(IOBufReader& iobr) {
  scores_.ParseFromIOBuf(iobr);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_highScores::Encode(IOBufWriter& iobw) const {
  scores_.SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textEmpty
bool TL_textEmpty::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_textEmpty::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textPlain
bool TL_textPlain::Decode(IOBufReader& iobr) {
  ReadString(iobr, &text_);
  return true;
}
bool TL_textPlain::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, text_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textBold
bool TL_textBold::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_textBold::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textItalic
bool TL_textItalic::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_textItalic::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textUnderline
bool TL_textUnderline::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_textUnderline::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textStrike
bool TL_textStrike::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_textStrike::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textFixed
bool TL_textFixed::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_textFixed::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textUrl
bool TL_textUrl::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  ReadString(iobr, &url_);
  webpage_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_textUrl::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  WriteString(iobw, url_);
  iobw.writeLE(webpage_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textEmail
bool TL_textEmail::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  ReadString(iobr, &email_);
  return true;
}
bool TL_textEmail::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  WriteString(iobw, email_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// textConcat
bool TL_textConcat::Decode(IOBufReader& iobr) {
  texts_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_textConcat::Encode(IOBufWriter& iobw) const {
  texts_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockUnsupported
bool TL_pageBlockUnsupported::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_pageBlockUnsupported::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockTitle
bool TL_pageBlockTitle::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockTitle::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockSubtitle
bool TL_pageBlockSubtitle::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockSubtitle::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockAuthorDate
bool TL_pageBlockAuthorDate::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    author_ = std::unique_ptr<RichText>(o2);
  }
  published_date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_pageBlockAuthorDate::Encode(IOBufWriter& iobw) const {
  if (!author_) return false;
  author_-> SerializeToIOBuf(iobw);
  iobw.writeLE(published_date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockHeader
bool TL_pageBlockHeader::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockHeader::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockSubheader
bool TL_pageBlockSubheader::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockSubheader::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockParagraph
bool TL_pageBlockParagraph::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockParagraph::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockPreformatted
bool TL_pageBlockPreformatted::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  ReadString(iobr, &language_);
  return true;
}
bool TL_pageBlockPreformatted::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  WriteString(iobw, language_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockFooter
bool TL_pageBlockFooter::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockFooter::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockDivider
bool TL_pageBlockDivider::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_pageBlockDivider::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockAnchor
bool TL_pageBlockAnchor::Decode(IOBufReader& iobr) {
  ReadString(iobr, &name_);
  return true;
}
bool TL_pageBlockAnchor::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockList
bool TL_pageBlockList::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    ordered_ = std::unique_ptr<Bool>(o2);
  }
  items_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_pageBlockList::Encode(IOBufWriter& iobw) const {
  if (!ordered_) return false;
  ordered_-> SerializeToIOBuf(iobw);
  items_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockBlockquote
bool TL_pageBlockBlockquote::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    caption_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockBlockquote::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  if (!caption_) return false;
  caption_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockPullquote
bool TL_pageBlockPullquote::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    text_ = std::unique_ptr<RichText>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    caption_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockPullquote::Encode(IOBufWriter& iobw) const {
  if (!text_) return false;
  text_-> SerializeToIOBuf(iobw);
  if (!caption_) return false;
  caption_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockPhoto
bool TL_pageBlockPhoto::Decode(IOBufReader& iobr) {
  photo_id_ = iobr.readLE<int64_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    caption_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockPhoto::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(photo_id_);
  if (!caption_) return false;
  caption_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockVideo
bool TL_pageBlockVideo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  video_id_ = iobr.readLE<int64_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    caption_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockVideo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(video_id_);
  if (!caption_) return false;
  caption_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockCover
bool TL_pageBlockCover::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PageBlock*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    cover_ = std::unique_ptr<PageBlock>(o2);
  }
  return true;
}
bool TL_pageBlockCover::Encode(IOBufWriter& iobw) const {
  if (!cover_) return false;
  cover_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockEmbed
bool TL_pageBlockEmbed::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_url()) {
    ReadString(iobr, &url_);
  }
  if (has_html()) {
    ReadString(iobr, &html_);
  }
  if (has_poster_photo_id()) {
    poster_photo_id_ = iobr.readLE<int64_t>();
  }
  w_ = iobr.readLE<int32_t>();
  h_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    caption_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockEmbed::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_url()) WriteString(iobw, url_);
  if (has_html()) WriteString(iobw, html_);
  if (has_poster_photo_id()) iobw.writeLE(poster_photo_id_);
  iobw.writeLE(w_);
  iobw.writeLE(h_);
  if (!caption_) return false;
  caption_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockEmbedPost
bool TL_pageBlockEmbedPost::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  webpage_id_ = iobr.readLE<int64_t>();
  author_photo_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &author_);
  date_ = iobr.readLE<int32_t>();
  blocks_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    caption_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockEmbedPost::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  iobw.writeLE(webpage_id_);
  iobw.writeLE(author_photo_id_);
  WriteString(iobw, author_);
  iobw.writeLE(date_);
  blocks_.SerializeToIOBuf(iobw);
  if (!caption_) return false;
  caption_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockCollage
bool TL_pageBlockCollage::Decode(IOBufReader& iobr) {
  items_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    caption_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockCollage::Encode(IOBufWriter& iobw) const {
  items_.SerializeToIOBuf(iobw);
  if (!caption_) return false;
  caption_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockSlideshow
bool TL_pageBlockSlideshow::Decode(IOBufReader& iobr) {
  items_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<RichText*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    caption_ = std::unique_ptr<RichText>(o2);
  }
  return true;
}
bool TL_pageBlockSlideshow::Encode(IOBufWriter& iobw) const {
  items_.SerializeToIOBuf(iobw);
  if (!caption_) return false;
  caption_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageBlockChannel
bool TL_pageBlockChannel::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Chat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<Chat>(o2);
  }
  return true;
}
bool TL_pageBlockChannel::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pagePart
bool TL_pagePart::Decode(IOBufReader& iobr) {
  blocks_.ParseFromIOBuf(iobr);
  photos_.ParseFromIOBuf(iobr);
  videos_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_pagePart::Encode(IOBufWriter& iobw) const {
  blocks_.SerializeToIOBuf(iobw);
  photos_.SerializeToIOBuf(iobw);
  videos_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// pageFull
bool TL_pageFull::Decode(IOBufReader& iobr) {
  blocks_.ParseFromIOBuf(iobr);
  photos_.ParseFromIOBuf(iobr);
  videos_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_pageFull::Encode(IOBufWriter& iobw) const {
  blocks_.SerializeToIOBuf(iobw);
  photos_.SerializeToIOBuf(iobw);
  videos_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallDiscardReasonMissed
bool TL_phoneCallDiscardReasonMissed::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_phoneCallDiscardReasonMissed::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallDiscardReasonDisconnect
bool TL_phoneCallDiscardReasonDisconnect::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_phoneCallDiscardReasonDisconnect::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallDiscardReasonHangup
bool TL_phoneCallDiscardReasonHangup::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_phoneCallDiscardReasonHangup::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallDiscardReasonBusy
bool TL_phoneCallDiscardReasonBusy::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_phoneCallDiscardReasonBusy::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// dataJSON
bool TL_dataJSON::Decode(IOBufReader& iobr) {
  ReadString(iobr, &data_);
  return true;
}
bool TL_dataJSON::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, data_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// labeledPrice
bool TL_labeledPrice::Decode(IOBufReader& iobr) {
  ReadString(iobr, &label_);
  amount_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_labeledPrice::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, label_);
  iobw.writeLE(amount_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// invoice
bool TL_invoice::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &currency_);
  prices_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_invoice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, currency_);
  prices_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// paymentCharge
bool TL_paymentCharge::Decode(IOBufReader& iobr) {
  ReadString(iobr, &id_);
  ReadString(iobr, &provider_charge_id_);
  return true;
}
bool TL_paymentCharge::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, id_);
  WriteString(iobw, provider_charge_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// postAddress
bool TL_postAddress::Decode(IOBufReader& iobr) {
  ReadString(iobr, &street_line1_);
  ReadString(iobr, &street_line2_);
  ReadString(iobr, &city_);
  ReadString(iobr, &state_);
  ReadString(iobr, &country_iso2_);
  ReadString(iobr, &post_code_);
  return true;
}
bool TL_postAddress::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, street_line1_);
  WriteString(iobw, street_line2_);
  WriteString(iobw, city_);
  WriteString(iobw, state_);
  WriteString(iobw, country_iso2_);
  WriteString(iobw, post_code_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// paymentRequestedInfo
bool TL_paymentRequestedInfo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_name()) {
    ReadString(iobr, &name_);
  }
  if (has_phone()) {
    ReadString(iobr, &phone_);
  }
  if (has_email()) {
    ReadString(iobr, &email_);
  }
  if (has_shipping_address()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PostAddress*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    shipping_address_ = std::unique_ptr<PostAddress>(o2);
  }
  return true;
}
bool TL_paymentRequestedInfo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_name()) WriteString(iobw, name_);
  if (has_phone()) WriteString(iobw, phone_);
  if (has_email()) WriteString(iobw, email_);
  if (has_shipping_address()) shipping_address_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// paymentSavedCredentialsCard
bool TL_paymentSavedCredentialsCard::Decode(IOBufReader& iobr) {
  ReadString(iobr, &id_);
  ReadString(iobr, &title_);
  return true;
}
bool TL_paymentSavedCredentialsCard::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, id_);
  WriteString(iobw, title_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// webDocument
bool TL_webDocument::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  access_hash_ = iobr.readLE<int64_t>();
  size_ = iobr.readLE<int32_t>();
  ReadString(iobr, &mime_type_);
  attributes_.ParseFromIOBuf(iobr);
  dc_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_webDocument::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(size_);
  WriteString(iobw, mime_type_);
  attributes_.SerializeToIOBuf(iobw);
  iobw.writeLE(dc_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputWebDocument
bool TL_inputWebDocument::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  size_ = iobr.readLE<int32_t>();
  ReadString(iobr, &mime_type_);
  attributes_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_inputWebDocument::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  iobw.writeLE(size_);
  WriteString(iobw, mime_type_);
  attributes_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputWebFileLocation
bool TL_inputWebFileLocation::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputWebFileLocation::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_webFile
bool TL_upload_webFile::Decode(IOBufReader& iobr) {
  size_ = iobr.readLE<int32_t>();
  ReadString(iobr, &mime_type_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<storage_FileType*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_type_ = std::unique_ptr<storage_FileType>(o2);
  }
  mtime_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_upload_webFile::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(size_);
  WriteString(iobw, mime_type_);
  if (!file_type_) return false;
  file_type_-> SerializeToIOBuf(iobw);
  iobw.writeLE(mtime_);
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_paymentForm
bool TL_payments_paymentForm::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  bot_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Invoice*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    invoice_ = std::unique_ptr<Invoice>(o2);
  }
  provider_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &url_);
  if (has_native_provider()) {
    ReadString(iobr, &native_provider_);
  }
  if (has_native_params()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DataJSON*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    native_params_ = std::unique_ptr<DataJSON>(o2);
  }
  if (has_saved_info()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PaymentRequestedInfo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    saved_info_ = std::unique_ptr<PaymentRequestedInfo>(o2);
  }
  if (has_saved_credentials()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PaymentSavedCredentials*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    saved_credentials_ = std::unique_ptr<PaymentSavedCredentials>(o2);
  }
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_payments_paymentForm::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(bot_id_);
  if (!invoice_) return false;
  invoice_-> SerializeToIOBuf(iobw);
  iobw.writeLE(provider_id_);
  WriteString(iobw, url_);
  if (has_native_provider()) WriteString(iobw, native_provider_);
  if (has_native_params()) native_params_->SerializeToIOBuf(iobw);
  if (has_saved_info()) saved_info_->SerializeToIOBuf(iobw);
  if (has_saved_credentials()) saved_credentials_->SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_validatedRequestedInfo
bool TL_payments_validatedRequestedInfo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_id()) {
    ReadString(iobr, &id_);
  }
  if (has_shipping_options()) {
    shipping_options_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_payments_validatedRequestedInfo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_id()) WriteString(iobw, id_);
  if (has_shipping_options()) shipping_options_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_paymentResult
bool TL_payments_paymentResult::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Updates*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    updates_ = std::unique_ptr<Updates>(o2);
  }
  return true;
}
bool TL_payments_paymentResult::Encode(IOBufWriter& iobw) const {
  if (!updates_) return false;
  updates_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_paymentVerficationNeeded
bool TL_payments_paymentVerficationNeeded::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  return true;
}
bool TL_payments_paymentVerficationNeeded::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_paymentReceipt
bool TL_payments_paymentReceipt::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  date_ = iobr.readLE<int32_t>();
  bot_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Invoice*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    invoice_ = std::unique_ptr<Invoice>(o2);
  }
  provider_id_ = iobr.readLE<int32_t>();
  if (has_info()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PaymentRequestedInfo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    info_ = std::unique_ptr<PaymentRequestedInfo>(o2);
  }
  if (has_shipping()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ShippingOption*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    shipping_ = std::unique_ptr<ShippingOption>(o2);
  }
  ReadString(iobr, &currency_);
  total_amount_ = iobr.readLE<int64_t>();
  ReadString(iobr, &credentials_title_);
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_payments_paymentReceipt::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(date_);
  iobw.writeLE(bot_id_);
  if (!invoice_) return false;
  invoice_-> SerializeToIOBuf(iobw);
  iobw.writeLE(provider_id_);
  if (has_info()) info_->SerializeToIOBuf(iobw);
  if (has_shipping()) shipping_->SerializeToIOBuf(iobw);
  WriteString(iobw, currency_);
  iobw.writeLE(total_amount_);
  WriteString(iobw, credentials_title_);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_savedInfo
bool TL_payments_savedInfo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_saved_info()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PaymentRequestedInfo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    saved_info_ = std::unique_ptr<PaymentRequestedInfo>(o2);
  }
  return true;
}
bool TL_payments_savedInfo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_saved_info()) saved_info_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPaymentCredentialsSaved
bool TL_inputPaymentCredentialsSaved::Decode(IOBufReader& iobr) {
  ReadString(iobr, &id_);
  ReadString(iobr, &tmp_password_);
  return true;
}
bool TL_inputPaymentCredentialsSaved::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, id_);
  WriteString(iobw, tmp_password_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPaymentCredentials
bool TL_inputPaymentCredentials::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DataJSON*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    data_ = std::unique_ptr<DataJSON>(o2);
  }
  return true;
}
bool TL_inputPaymentCredentials::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!data_) return false;
  data_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_tmpPassword
bool TL_account_tmpPassword::Decode(IOBufReader& iobr) {
  ReadString(iobr, &tmp_password_);
  valid_until_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_account_tmpPassword::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, tmp_password_);
  iobw.writeLE(valid_until_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// shippingOption
bool TL_shippingOption::Decode(IOBufReader& iobr) {
  ReadString(iobr, &id_);
  ReadString(iobr, &title_);
  prices_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_shippingOption::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, id_);
  WriteString(iobw, title_);
  prices_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// inputPhoneCall
bool TL_inputPhoneCall::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_inputPhoneCall::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallEmpty
bool TL_phoneCallEmpty::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_phoneCallEmpty::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallWaiting
bool TL_phoneCallWaiting::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  admin_id_ = iobr.readLE<int32_t>();
  participant_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallProtocol*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    protocol_ = std::unique_ptr<PhoneCallProtocol>(o2);
  }
  if (has_receive_date()) {
    receive_date_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_phoneCallWaiting::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  iobw.writeLE(admin_id_);
  iobw.writeLE(participant_id_);
  if (!protocol_) return false;
  protocol_-> SerializeToIOBuf(iobw);
  if (has_receive_date()) iobw.writeLE(receive_date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallRequested
bool TL_phoneCallRequested::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  admin_id_ = iobr.readLE<int32_t>();
  participant_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &g_a_hash_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallProtocol*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    protocol_ = std::unique_ptr<PhoneCallProtocol>(o2);
  }
  return true;
}
bool TL_phoneCallRequested::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  iobw.writeLE(admin_id_);
  iobw.writeLE(participant_id_);
  WriteString(iobw, g_a_hash_);
  if (!protocol_) return false;
  protocol_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallAccepted
bool TL_phoneCallAccepted::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  admin_id_ = iobr.readLE<int32_t>();
  participant_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &g_b_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallProtocol*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    protocol_ = std::unique_ptr<PhoneCallProtocol>(o2);
  }
  return true;
}
bool TL_phoneCallAccepted::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  iobw.writeLE(admin_id_);
  iobw.writeLE(participant_id_);
  WriteString(iobw, g_b_);
  if (!protocol_) return false;
  protocol_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCall
bool TL_phoneCall::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  access_hash_ = iobr.readLE<int64_t>();
  date_ = iobr.readLE<int32_t>();
  admin_id_ = iobr.readLE<int32_t>();
  participant_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &g_a_or_b_);
  key_fingerprint_ = iobr.readLE<int64_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallProtocol*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    protocol_ = std::unique_ptr<PhoneCallProtocol>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneConnection*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    connection_ = std::unique_ptr<PhoneConnection>(o2);
  }
  alternative_connections_.ParseFromIOBuf(iobr);
  start_date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_phoneCall::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  iobw.writeLE(access_hash_);
  iobw.writeLE(date_);
  iobw.writeLE(admin_id_);
  iobw.writeLE(participant_id_);
  WriteString(iobw, g_a_or_b_);
  iobw.writeLE(key_fingerprint_);
  if (!protocol_) return false;
  protocol_-> SerializeToIOBuf(iobw);
  if (!connection_) return false;
  connection_-> SerializeToIOBuf(iobw);
  alternative_connections_.SerializeToIOBuf(iobw);
  iobw.writeLE(start_date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallDiscarded
bool TL_phoneCallDiscarded::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_ = iobr.readLE<int64_t>();
  if (has_reason()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallDiscardReason*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reason_ = std::unique_ptr<PhoneCallDiscardReason>(o2);
  }
  if (has_duration()) {
    duration_ = iobr.readLE<int32_t>();
  }
  return true;
}
bool TL_phoneCallDiscarded::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(id_);
  if (has_reason()) reason_->SerializeToIOBuf(iobw);
  if (has_duration()) iobw.writeLE(duration_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneConnection
bool TL_phoneConnection::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &ip_);
  ReadString(iobr, &ipv6_);
  port_ = iobr.readLE<int32_t>();
  ReadString(iobr, &peer_tag_);
  return true;
}
bool TL_phoneConnection::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  WriteString(iobw, ip_);
  WriteString(iobw, ipv6_);
  iobw.writeLE(port_);
  WriteString(iobw, peer_tag_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phoneCallProtocol
bool TL_phoneCallProtocol::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  min_layer_ = iobr.readLE<int32_t>();
  max_layer_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_phoneCallProtocol::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(min_layer_);
  iobw.writeLE(max_layer_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_phoneCall
bool TL_phone_phoneCall::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCall*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    phone_call_ = std::unique_ptr<PhoneCall>(o2);
  }
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_phone_phoneCall::Encode(IOBufWriter& iobw) const {
  if (!phone_call_) return false;
  phone_call_-> SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_cdnFileReuploadNeeded
bool TL_upload_cdnFileReuploadNeeded::Decode(IOBufReader& iobr) {
  ReadString(iobr, &request_token_);
  return true;
}
bool TL_upload_cdnFileReuploadNeeded::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, request_token_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_cdnFile
bool TL_upload_cdnFile::Decode(IOBufReader& iobr) {
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_upload_cdnFile::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// cdnPublicKey
bool TL_cdnPublicKey::Decode(IOBufReader& iobr) {
  dc_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &public_key_);
  return true;
}
bool TL_cdnPublicKey::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(dc_id_);
  WriteString(iobw, public_key_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// cdnConfig
bool TL_cdnConfig::Decode(IOBufReader& iobr) {
  public_keys_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_cdnConfig::Encode(IOBufWriter& iobw) const {
  public_keys_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// req_pq
bool TL_req_pq::Decode(IOBufReader& iobr) {
  ReadTLIntN(iobr, &nonce_);
  return true;
}
bool TL_req_pq::Encode(IOBufWriter& iobw) const {
  WriteTLIntN(iobw, nonce_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// req_DH_params
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
// set_client_DH_params
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
// destroy_auth_key
bool TL_destroy_auth_key::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_destroy_auth_key::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// rpc_drop_answer
bool TL_rpc_drop_answer::Decode(IOBufReader& iobr) {
  req_msg_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_rpc_drop_answer::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(req_msg_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// get_future_salts
bool TL_get_future_salts::Decode(IOBufReader& iobr) {
  num_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_get_future_salts::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(num_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// ping
bool TL_ping::Decode(IOBufReader& iobr) {
  ping_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_ping::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(ping_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// ping_delay_disconnect
bool TL_ping_delay_disconnect::Decode(IOBufReader& iobr) {
  ping_id_ = iobr.readLE<int64_t>();
  disconnect_delay_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_ping_delay_disconnect::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(ping_id_);
  iobw.writeLE(disconnect_delay_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// destroy_session
bool TL_destroy_session::Decode(IOBufReader& iobr) {
  session_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_destroy_session::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(session_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contest_saveDeveloperInfo
bool TL_contest_saveDeveloperInfo::Decode(IOBufReader& iobr) {
  vk_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &name_);
  ReadString(iobr, &phone_number_);
  age_ = iobr.readLE<int32_t>();
  ReadString(iobr, &city_);
  return true;
}
bool TL_contest_saveDeveloperInfo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(vk_id_);
  WriteString(iobw, name_);
  WriteString(iobw, phone_number_);
  iobw.writeLE(age_);
  WriteString(iobw, city_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_logOut
bool TL_auth_logOut::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_auth_logOut::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_resetAuthorizations
bool TL_auth_resetAuthorizations::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_auth_resetAuthorizations::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_sendInvites
bool TL_auth_sendInvites::Decode(IOBufReader& iobr) {
  phone_numbers_.ParseFromIOBuf(iobr);
  ReadString(iobr, &message_);
  return true;
}
bool TL_auth_sendInvites::Encode(IOBufWriter& iobw) const {
  phone_numbers_.SerializeToIOBuf(iobw);
  WriteString(iobw, message_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_bindTempAuthKey
bool TL_auth_bindTempAuthKey::Decode(IOBufReader& iobr) {
  perm_auth_key_id_ = iobr.readLE<int64_t>();
  nonce_ = iobr.readLE<int64_t>();
  expires_at_ = iobr.readLE<int32_t>();
  ReadString(iobr, &encrypted_message_);
  return true;
}
bool TL_auth_bindTempAuthKey::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(perm_auth_key_id_);
  iobw.writeLE(nonce_);
  iobw.writeLE(expires_at_);
  WriteString(iobw, encrypted_message_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_cancelCode
bool TL_auth_cancelCode::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &phone_code_hash_);
  return true;
}
bool TL_auth_cancelCode::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  WriteString(iobw, phone_code_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_dropTempAuthKeys
bool TL_auth_dropTempAuthKeys::Decode(IOBufReader& iobr) {
  except_auth_keys_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_auth_dropTempAuthKeys::Encode(IOBufWriter& iobw) const {
  except_auth_keys_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_registerDevice
bool TL_account_registerDevice::Decode(IOBufReader& iobr) {
  token_type_ = iobr.readLE<int32_t>();
  ReadString(iobr, &token_);
  return true;
}
bool TL_account_registerDevice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(token_type_);
  WriteString(iobw, token_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_unregisterDevice
bool TL_account_unregisterDevice::Decode(IOBufReader& iobr) {
  token_type_ = iobr.readLE<int32_t>();
  ReadString(iobr, &token_);
  return true;
}
bool TL_account_unregisterDevice::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(token_type_);
  WriteString(iobw, token_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_updateNotifySettings
bool TL_account_updateNotifySettings::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputNotifyPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputNotifyPeer>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeerNotifySettings*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    settings_ = std::unique_ptr<InputPeerNotifySettings>(o2);
  }
  return true;
}
bool TL_account_updateNotifySettings::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (!settings_) return false;
  settings_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_resetNotifySettings
bool TL_account_resetNotifySettings::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_account_resetNotifySettings::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_updateStatus
bool TL_account_updateStatus::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    offline_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_account_updateStatus::Encode(IOBufWriter& iobw) const {
  if (!offline_) return false;
  offline_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_reportPeer
bool TL_account_reportPeer::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReportReason*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reason_ = std::unique_ptr<ReportReason>(o2);
  }
  return true;
}
bool TL_account_reportPeer::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (!reason_) return false;
  reason_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_checkUsername
bool TL_account_checkUsername::Decode(IOBufReader& iobr) {
  ReadString(iobr, &username_);
  return true;
}
bool TL_account_checkUsername::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, username_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_deleteAccount
bool TL_account_deleteAccount::Decode(IOBufReader& iobr) {
  ReadString(iobr, &reason_);
  return true;
}
bool TL_account_deleteAccount::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, reason_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_setAccountTTL
bool TL_account_setAccountTTL::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<AccountDaysTTL*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    ttl_ = std::unique_ptr<AccountDaysTTL>(o2);
  }
  return true;
}
bool TL_account_setAccountTTL::Encode(IOBufWriter& iobw) const {
  if (!ttl_) return false;
  ttl_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_updateDeviceLocked
bool TL_account_updateDeviceLocked::Decode(IOBufReader& iobr) {
  period_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_account_updateDeviceLocked::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(period_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_resetAuthorization
bool TL_account_resetAuthorization::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_account_resetAuthorization::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_updatePasswordSettings
bool TL_account_updatePasswordSettings::Decode(IOBufReader& iobr) {
  ReadString(iobr, &current_password_hash_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<account_PasswordInputSettings*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    new_settings_ = std::unique_ptr<account_PasswordInputSettings>(o2);
  }
  return true;
}
bool TL_account_updatePasswordSettings::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, current_password_hash_);
  if (!new_settings_) return false;
  new_settings_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_confirmPhone
bool TL_account_confirmPhone::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_code_hash_);
  ReadString(iobr, &phone_code_);
  return true;
}
bool TL_account_confirmPhone::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_code_hash_);
  WriteString(iobw, phone_code_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_deleteContacts
bool TL_contacts_deleteContacts::Decode(IOBufReader& iobr) {
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_deleteContacts::Encode(IOBufWriter& iobw) const {
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_block
bool TL_contacts_block::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_contacts_block::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_unblock
bool TL_contacts_unblock::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_contacts_unblock::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_resetTopPeerRating
bool TL_contacts_resetTopPeerRating::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<TopPeerCategory*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    category_ = std::unique_ptr<TopPeerCategory>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  return true;
}
bool TL_contacts_resetTopPeerRating::Encode(IOBufWriter& iobw) const {
  if (!category_) return false;
  category_-> SerializeToIOBuf(iobw);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_setTyping
bool TL_messages_setTyping::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<SendMessageAction*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    action_ = std::unique_ptr<SendMessageAction>(o2);
  }
  return true;
}
bool TL_messages_setTyping::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (!action_) return false;
  action_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_reportSpam
bool TL_messages_reportSpam::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  return true;
}
bool TL_messages_reportSpam::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_hideReportSpam
bool TL_messages_hideReportSpam::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  return true;
}
bool TL_messages_hideReportSpam::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_discardEncryption
bool TL_messages_discardEncryption::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_discardEncryption::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_setEncryptedTyping
bool TL_messages_setEncryptedTyping::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputEncryptedChat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputEncryptedChat>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    typing_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_messages_setEncryptedTyping::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (!typing_) return false;
  typing_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_readEncryptedHistory
bool TL_messages_readEncryptedHistory::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputEncryptedChat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputEncryptedChat>(o2);
  }
  max_date_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_readEncryptedHistory::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(max_date_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_reportEncryptedSpam
bool TL_messages_reportEncryptedSpam::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputEncryptedChat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputEncryptedChat>(o2);
  }
  return true;
}
bool TL_messages_reportEncryptedSpam::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_uninstallStickerSet
bool TL_messages_uninstallStickerSet::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputStickerSet*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    stickerset_ = std::unique_ptr<InputStickerSet>(o2);
  }
  return true;
}
bool TL_messages_uninstallStickerSet::Encode(IOBufWriter& iobw) const {
  if (!stickerset_) return false;
  stickerset_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_editChatAdmin
bool TL_messages_editChatAdmin::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    is_admin_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_messages_editChatAdmin::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  if (!is_admin_) return false;
  is_admin_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_reorderStickerSets
bool TL_messages_reorderStickerSets::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  order_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_reorderStickerSets::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  order_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_saveGif
bool TL_messages_saveGif::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputDocument*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputDocument>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    unsave_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_messages_saveGif::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  if (!unsave_) return false;
  unsave_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_setInlineBotResults
bool TL_messages_setInlineBotResults::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  results_.ParseFromIOBuf(iobr);
  cache_time_ = iobr.readLE<int32_t>();
  if (has_next_offset()) {
    ReadString(iobr, &next_offset_);
  }
  if (has_switch_pm()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InlineBotSwitchPM*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    switch_pm_ = std::unique_ptr<InlineBotSwitchPM>(o2);
  }
  return true;
}
bool TL_messages_setInlineBotResults::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  results_.SerializeToIOBuf(iobw);
  iobw.writeLE(cache_time_);
  if (has_next_offset()) WriteString(iobw, next_offset_);
  if (has_switch_pm()) switch_pm_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_editInlineBotMessage
bool TL_messages_editInlineBotMessage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessageID*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputBotInlineMessageID>(o2);
  }
  if (has_message()) {
    ReadString(iobr, &message_);
  }
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_messages_editInlineBotMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  if (has_message()) WriteString(iobw, message_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_setBotCallbackAnswer
bool TL_messages_setBotCallbackAnswer::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  if (has_message()) {
    ReadString(iobr, &message_);
  }
  if (has_url()) {
    ReadString(iobr, &url_);
  }
  cache_time_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_setBotCallbackAnswer::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  if (has_message()) WriteString(iobw, message_);
  if (has_url()) WriteString(iobw, url_);
  iobw.writeLE(cache_time_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_saveDraft
bool TL_messages_saveDraft::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  ReadString(iobr, &message_);
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_messages_saveDraft::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  WriteString(iobw, message_);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_readFeaturedStickers
bool TL_messages_readFeaturedStickers::Decode(IOBufReader& iobr) {
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_readFeaturedStickers::Encode(IOBufWriter& iobw) const {
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_saveRecentSticker
bool TL_messages_saveRecentSticker::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputDocument*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputDocument>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    unsave_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_messages_saveRecentSticker::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  if (!unsave_) return false;
  unsave_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_clearRecentStickers
bool TL_messages_clearRecentStickers::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_clearRecentStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_setInlineGameScore
bool TL_messages_setInlineGameScore::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessageID*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputBotInlineMessageID>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  score_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_setInlineGameScore::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  iobw.writeLE(score_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_toggleDialogPin
bool TL_messages_toggleDialogPin::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  return true;
}
bool TL_messages_toggleDialogPin::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_reorderPinnedDialogs
bool TL_messages_reorderPinnedDialogs::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  order_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_reorderPinnedDialogs::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  order_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_setBotShippingResults
bool TL_messages_setBotShippingResults::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  if (has_error()) {
    ReadString(iobr, &error_);
  }
  if (has_shipping_options()) {
    shipping_options_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_messages_setBotShippingResults::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  if (has_error()) WriteString(iobw, error_);
  if (has_shipping_options()) shipping_options_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_setBotPrecheckoutResults
bool TL_messages_setBotPrecheckoutResults::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  query_id_ = iobr.readLE<int64_t>();
  if (has_error()) {
    ReadString(iobr, &error_);
  }
  return true;
}
bool TL_messages_setBotPrecheckoutResults::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(query_id_);
  if (has_error()) WriteString(iobw, error_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_saveFilePart
bool TL_upload_saveFilePart::Decode(IOBufReader& iobr) {
  file_id_ = iobr.readLE<int64_t>();
  file_part_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_upload_saveFilePart::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(file_id_);
  iobw.writeLE(file_part_);
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_saveBigFilePart
bool TL_upload_saveBigFilePart::Decode(IOBufReader& iobr) {
  file_id_ = iobr.readLE<int64_t>();
  file_part_ = iobr.readLE<int32_t>();
  file_total_parts_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_upload_saveBigFilePart::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(file_id_);
  iobw.writeLE(file_part_);
  iobw.writeLE(file_total_parts_);
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_reuploadCdnFile
bool TL_upload_reuploadCdnFile::Decode(IOBufReader& iobr) {
  ReadString(iobr, &file_token_);
  ReadString(iobr, &request_token_);
  return true;
}
bool TL_upload_reuploadCdnFile::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, file_token_);
  WriteString(iobw, request_token_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_saveAppLog
bool TL_help_saveAppLog::Decode(IOBufReader& iobr) {
  events_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_help_saveAppLog::Encode(IOBufWriter& iobw) const {
  events_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_setBotUpdatesStatus
bool TL_help_setBotUpdatesStatus::Decode(IOBufReader& iobr) {
  pending_updates_count_ = iobr.readLE<int32_t>();
  ReadString(iobr, &message_);
  return true;
}
bool TL_help_setBotUpdatesStatus::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(pending_updates_count_);
  WriteString(iobw, message_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_readHistory
bool TL_channels_readHistory::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  max_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channels_readHistory::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  iobw.writeLE(max_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_reportSpam
bool TL_channels_reportSpam::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_channels_reportSpam::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_editAbout
bool TL_channels_editAbout::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  ReadString(iobr, &about_);
  return true;
}
bool TL_channels_editAbout::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  WriteString(iobw, about_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_checkUsername
bool TL_channels_checkUsername::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  ReadString(iobr, &username_);
  return true;
}
bool TL_channels_checkUsername::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  WriteString(iobw, username_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_updateUsername
bool TL_channels_updateUsername::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  ReadString(iobr, &username_);
  return true;
}
bool TL_channels_updateUsername::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  WriteString(iobw, username_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// bots_answerWebhookJSONQuery
bool TL_bots_answerWebhookJSONQuery::Decode(IOBufReader& iobr) {
  query_id_ = iobr.readLE<int64_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DataJSON*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    data_ = std::unique_ptr<DataJSON>(o2);
  }
  return true;
}
bool TL_bots_answerWebhookJSONQuery::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(query_id_);
  if (!data_) return false;
  data_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_clearSavedInfo
bool TL_payments_clearSavedInfo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_payments_clearSavedInfo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_receivedCall
bool TL_phone_receivedCall::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoneCall*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPhoneCall>(o2);
  }
  return true;
}
bool TL_phone_receivedCall::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_saveCallDebug
bool TL_phone_saveCallDebug::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoneCall*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPhoneCall>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DataJSON*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    debug_ = std::unique_ptr<DataJSON>(o2);
  }
  return true;
}
bool TL_phone_saveCallDebug::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (!debug_) return false;
  debug_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// invokeAfterMsg
bool TL_invokeAfterMsg::Decode(IOBufReader& iobr) {
  msg_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_invokeAfterMsg::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(msg_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// invokeAfterMsgs
bool TL_invokeAfterMsgs::Decode(IOBufReader& iobr) {
  msg_ids_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_invokeAfterMsgs::Encode(IOBufWriter& iobw) const {
  msg_ids_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// initConnection
bool TL_initConnection::Decode(IOBufReader& iobr) {
  api_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &device_model_);
  ReadString(iobr, &system_version_);
  ReadString(iobr, &app_version_);
  ReadString(iobr, &lang_code_);
  return true;
}
bool TL_initConnection::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(api_id_);
  WriteString(iobw, device_model_);
  WriteString(iobw, system_version_);
  WriteString(iobw, app_version_);
  WriteString(iobw, lang_code_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// invokeWithLayer
bool TL_invokeWithLayer::Decode(IOBufReader& iobr) {
  layer_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_invokeWithLayer::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(layer_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// invokeWithoutUpdates
bool TL_invokeWithoutUpdates::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_invokeWithoutUpdates::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_checkPhone
bool TL_auth_checkPhone::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  return true;
}
bool TL_auth_checkPhone::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_sendCode
bool TL_auth_sendCode::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &phone_number_);
  if (has_current_number()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    current_number_ = std::unique_ptr<Bool>(o2);
  }
  api_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &api_hash_);
  return true;
}
bool TL_auth_sendCode::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, phone_number_);
  if (has_current_number()) current_number_->SerializeToIOBuf(iobw);
  iobw.writeLE(api_id_);
  WriteString(iobw, api_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_resendCode
bool TL_auth_resendCode::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &phone_code_hash_);
  return true;
}
bool TL_auth_resendCode::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  WriteString(iobw, phone_code_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_sendChangePhoneCode
bool TL_account_sendChangePhoneCode::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &phone_number_);
  if (has_current_number()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    current_number_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_account_sendChangePhoneCode::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, phone_number_);
  if (has_current_number()) current_number_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_sendConfirmPhoneCode
bool TL_account_sendConfirmPhoneCode::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &hash_);
  if (has_current_number()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    current_number_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_account_sendConfirmPhoneCode::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, hash_);
  if (has_current_number()) current_number_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_signUp
bool TL_auth_signUp::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &phone_code_hash_);
  ReadString(iobr, &phone_code_);
  ReadString(iobr, &first_name_);
  ReadString(iobr, &last_name_);
  return true;
}
bool TL_auth_signUp::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  WriteString(iobw, phone_code_hash_);
  WriteString(iobw, phone_code_);
  WriteString(iobw, first_name_);
  WriteString(iobw, last_name_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_signIn
bool TL_auth_signIn::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &phone_code_hash_);
  ReadString(iobr, &phone_code_);
  return true;
}
bool TL_auth_signIn::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  WriteString(iobw, phone_code_hash_);
  WriteString(iobw, phone_code_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_importAuthorization
bool TL_auth_importAuthorization::Decode(IOBufReader& iobr) {
  id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &bytes_);
  return true;
}
bool TL_auth_importAuthorization::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(id_);
  WriteString(iobw, bytes_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_importBotAuthorization
bool TL_auth_importBotAuthorization::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  api_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &api_hash_);
  ReadString(iobr, &bot_auth_token_);
  return true;
}
bool TL_auth_importBotAuthorization::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(api_id_);
  WriteString(iobw, api_hash_);
  WriteString(iobw, bot_auth_token_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_checkPassword
bool TL_auth_checkPassword::Decode(IOBufReader& iobr) {
  ReadString(iobr, &password_hash_);
  return true;
}
bool TL_auth_checkPassword::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, password_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_recoverPassword
bool TL_auth_recoverPassword::Decode(IOBufReader& iobr) {
  ReadString(iobr, &code_);
  return true;
}
bool TL_auth_recoverPassword::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, code_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_exportAuthorization
bool TL_auth_exportAuthorization::Decode(IOBufReader& iobr) {
  dc_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_auth_exportAuthorization::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(dc_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// auth_requestPasswordRecovery
bool TL_auth_requestPasswordRecovery::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_auth_requestPasswordRecovery::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_getNotifySettings
bool TL_account_getNotifySettings::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputNotifyPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputNotifyPeer>(o2);
  }
  return true;
}
bool TL_account_getNotifySettings::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_updateProfile
bool TL_account_updateProfile::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (has_first_name()) {
    ReadString(iobr, &first_name_);
  }
  if (has_last_name()) {
    ReadString(iobr, &last_name_);
  }
  if (has_about()) {
    ReadString(iobr, &about_);
  }
  return true;
}
bool TL_account_updateProfile::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (has_first_name()) WriteString(iobw, first_name_);
  if (has_last_name()) WriteString(iobw, last_name_);
  if (has_about()) WriteString(iobw, about_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_updateUsername
bool TL_account_updateUsername::Decode(IOBufReader& iobr) {
  ReadString(iobr, &username_);
  return true;
}
bool TL_account_updateUsername::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, username_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_changePhone
bool TL_account_changePhone::Decode(IOBufReader& iobr) {
  ReadString(iobr, &phone_number_);
  ReadString(iobr, &phone_code_hash_);
  ReadString(iobr, &phone_code_);
  return true;
}
bool TL_account_changePhone::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, phone_number_);
  WriteString(iobw, phone_code_hash_);
  WriteString(iobw, phone_code_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_importCard
bool TL_contacts_importCard::Decode(IOBufReader& iobr) {
  export_card_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_contacts_importCard::Encode(IOBufWriter& iobw) const {
  export_card_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_getWallPapers
bool TL_account_getWallPapers::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_account_getWallPapers::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_getPrivacy
bool TL_account_getPrivacy::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPrivacyKey*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    key_ = std::unique_ptr<InputPrivacyKey>(o2);
  }
  return true;
}
bool TL_account_getPrivacy::Encode(IOBufWriter& iobw) const {
  if (!key_) return false;
  key_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_setPrivacy
bool TL_account_setPrivacy::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPrivacyKey*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    key_ = std::unique_ptr<InputPrivacyKey>(o2);
  }
  rules_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_account_setPrivacy::Encode(IOBufWriter& iobw) const {
  if (!key_) return false;
  key_-> SerializeToIOBuf(iobw);
  rules_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_getAccountTTL
bool TL_account_getAccountTTL::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_account_getAccountTTL::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_getAuthorizations
bool TL_account_getAuthorizations::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_account_getAuthorizations::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_getPassword
bool TL_account_getPassword::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_account_getPassword::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_getPasswordSettings
bool TL_account_getPasswordSettings::Decode(IOBufReader& iobr) {
  ReadString(iobr, &current_password_hash_);
  return true;
}
bool TL_account_getPasswordSettings::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, current_password_hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// account_getTmpPassword
bool TL_account_getTmpPassword::Decode(IOBufReader& iobr) {
  ReadString(iobr, &password_hash_);
  period_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_account_getTmpPassword::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, password_hash_);
  iobw.writeLE(period_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// users_getUsers
bool TL_users_getUsers::Decode(IOBufReader& iobr) {
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_users_getUsers::Encode(IOBufWriter& iobw) const {
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// users_getFullUser
bool TL_users_getFullUser::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_users_getFullUser::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_getStatuses
bool TL_contacts_getStatuses::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_contacts_getStatuses::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_getContacts
bool TL_contacts_getContacts::Decode(IOBufReader& iobr) {
  ReadString(iobr, &hash_);
  return true;
}
bool TL_contacts_getContacts::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_importContacts
bool TL_contacts_importContacts::Decode(IOBufReader& iobr) {
  contacts_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    replace_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_contacts_importContacts::Encode(IOBufWriter& iobw) const {
  contacts_.SerializeToIOBuf(iobw);
  if (!replace_) return false;
  replace_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_deleteContact
bool TL_contacts_deleteContact::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_contacts_deleteContact::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_getBlocked
bool TL_contacts_getBlocked::Decode(IOBufReader& iobr) {
  offset_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_contacts_getBlocked::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(offset_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_exportCard
bool TL_contacts_exportCard::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_contacts_exportCard::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getMessagesViews
bool TL_messages_getMessagesViews::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  id_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    increment_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_messages_getMessagesViews::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  id_.SerializeToIOBuf(iobw);
  if (!increment_) return false;
  increment_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_search
bool TL_contacts_search::Decode(IOBufReader& iobr) {
  ReadString(iobr, &q_);
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_contacts_search::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, q_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_resolveUsername
bool TL_contacts_resolveUsername::Decode(IOBufReader& iobr) {
  ReadString(iobr, &username_);
  return true;
}
bool TL_contacts_resolveUsername::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, username_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// contacts_getTopPeers
bool TL_contacts_getTopPeers::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  offset_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  hash_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_contacts_getTopPeers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(offset_);
  iobw.writeLE(limit_);
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getMessages
bool TL_messages_getMessages::Decode(IOBufReader& iobr) {
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_getMessages::Encode(IOBufWriter& iobw) const {
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getHistory
bool TL_messages_getHistory::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  offset_id_ = iobr.readLE<int32_t>();
  offset_date_ = iobr.readLE<int32_t>();
  add_offset_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  max_id_ = iobr.readLE<int32_t>();
  min_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getHistory::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(offset_id_);
  iobw.writeLE(offset_date_);
  iobw.writeLE(add_offset_);
  iobw.writeLE(limit_);
  iobw.writeLE(max_id_);
  iobw.writeLE(min_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_search
bool TL_messages_search::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  ReadString(iobr, &q_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<MessagesFilter*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    filter_ = std::unique_ptr<MessagesFilter>(o2);
  }
  min_date_ = iobr.readLE<int32_t>();
  max_date_ = iobr.readLE<int32_t>();
  offset_ = iobr.readLE<int32_t>();
  max_id_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_search::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  WriteString(iobw, q_);
  if (!filter_) return false;
  filter_-> SerializeToIOBuf(iobw);
  iobw.writeLE(min_date_);
  iobw.writeLE(max_date_);
  iobw.writeLE(offset_);
  iobw.writeLE(max_id_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_searchGlobal
bool TL_messages_searchGlobal::Decode(IOBufReader& iobr) {
  ReadString(iobr, &q_);
  offset_date_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    offset_peer_ = std::unique_ptr<InputPeer>(o2);
  }
  offset_id_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_searchGlobal::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, q_);
  iobw.writeLE(offset_date_);
  if (!offset_peer_) return false;
  offset_peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(offset_id_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_getMessages
bool TL_channels_getMessages::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_channels_getMessages::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getDialogs
bool TL_messages_getDialogs::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  offset_date_ = iobr.readLE<int32_t>();
  offset_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    offset_peer_ = std::unique_ptr<InputPeer>(o2);
  }
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getDialogs::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(offset_date_);
  iobw.writeLE(offset_id_);
  if (!offset_peer_) return false;
  offset_peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_readHistory
bool TL_messages_readHistory::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  max_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_readHistory::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(max_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_deleteMessages
bool TL_messages_deleteMessages::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_deleteMessages::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_readMessageContents
bool TL_messages_readMessageContents::Decode(IOBufReader& iobr) {
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_readMessageContents::Encode(IOBufWriter& iobw) const {
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_deleteMessages
bool TL_channels_deleteMessages::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_channels_deleteMessages::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_deleteHistory
bool TL_messages_deleteHistory::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  max_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_deleteHistory::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(max_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_deleteUserHistory
bool TL_channels_deleteUserHistory::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_channels_deleteUserHistory::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_receivedMessages
bool TL_messages_receivedMessages::Decode(IOBufReader& iobr) {
  max_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_receivedMessages::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(max_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_sendMessage
bool TL_messages_sendMessage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  ReadString(iobr, &message_);
  random_id_ = iobr.readLE<int64_t>();
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_messages_sendMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  WriteString(iobw, message_);
  iobw.writeLE(random_id_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_sendMedia
bool TL_messages_sendMedia::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputMedia*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    media_ = std::unique_ptr<InputMedia>(o2);
  }
  random_id_ = iobr.readLE<int64_t>();
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  return true;
}
bool TL_messages_sendMedia::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  if (!media_) return false;
  media_-> SerializeToIOBuf(iobw);
  iobw.writeLE(random_id_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_forwardMessages
bool TL_messages_forwardMessages::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    from_peer_ = std::unique_ptr<InputPeer>(o2);
  }
  id_.ParseFromIOBuf(iobr);
  random_id_.ParseFromIOBuf(iobr);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    to_peer_ = std::unique_ptr<InputPeer>(o2);
  }
  return true;
}
bool TL_messages_forwardMessages::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!from_peer_) return false;
  from_peer_-> SerializeToIOBuf(iobw);
  id_.SerializeToIOBuf(iobw);
  random_id_.SerializeToIOBuf(iobw);
  if (!to_peer_) return false;
  to_peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_editChatTitle
bool TL_messages_editChatTitle::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  return true;
}
bool TL_messages_editChatTitle::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  WriteString(iobw, title_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_editChatPhoto
bool TL_messages_editChatPhoto::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChatPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<InputChatPhoto>(o2);
  }
  return true;
}
bool TL_messages_editChatPhoto::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_addChatUser
bool TL_messages_addChatUser::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  fwd_limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_addChatUser::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  iobw.writeLE(fwd_limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_deleteChatUser
bool TL_messages_deleteChatUser::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_messages_deleteChatUser::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_createChat
bool TL_messages_createChat::Decode(IOBufReader& iobr) {
  users_.ParseFromIOBuf(iobr);
  ReadString(iobr, &title_);
  return true;
}
bool TL_messages_createChat::Encode(IOBufWriter& iobw) const {
  users_.SerializeToIOBuf(iobw);
  WriteString(iobw, title_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_forwardMessage
bool TL_messages_forwardMessage::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  id_ = iobr.readLE<int32_t>();
  random_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_messages_forwardMessage::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(id_);
  iobw.writeLE(random_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_importChatInvite
bool TL_messages_importChatInvite::Decode(IOBufReader& iobr) {
  ReadString(iobr, &hash_);
  return true;
}
bool TL_messages_importChatInvite::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_startBot
bool TL_messages_startBot::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    bot_ = std::unique_ptr<InputUser>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  random_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &start_param_);
  return true;
}
bool TL_messages_startBot::Encode(IOBufWriter& iobw) const {
  if (!bot_) return false;
  bot_-> SerializeToIOBuf(iobw);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(random_id_);
  WriteString(iobw, start_param_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_toggleChatAdmins
bool TL_messages_toggleChatAdmins::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    enabled_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_messages_toggleChatAdmins::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  if (!enabled_) return false;
  enabled_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_migrateChat
bool TL_messages_migrateChat::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_migrateChat::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_sendInlineBotResult
bool TL_messages_sendInlineBotResult::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  if (has_reply_to_msg_id()) {
    reply_to_msg_id_ = iobr.readLE<int32_t>();
  }
  random_id_ = iobr.readLE<int64_t>();
  query_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &id_);
  return true;
}
bool TL_messages_sendInlineBotResult::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (has_reply_to_msg_id()) iobw.writeLE(reply_to_msg_id_);
  iobw.writeLE(random_id_);
  iobw.writeLE(query_id_);
  WriteString(iobw, id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_editMessage
bool TL_messages_editMessage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  id_ = iobr.readLE<int32_t>();
  if (has_message()) {
    ReadString(iobr, &message_);
  }
  if (has_reply_markup()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ReplyMarkup*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reply_markup_ = std::unique_ptr<ReplyMarkup>(o2);
  }
  if (has_entities()) {
    entities_.ParseFromIOBuf(iobr);
  }
  return true;
}
bool TL_messages_editMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(id_);
  if (has_message()) WriteString(iobw, message_);
  if (has_reply_markup()) reply_markup_->SerializeToIOBuf(iobw);
  if (has_entities()) entities_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getAllDrafts
bool TL_messages_getAllDrafts::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messages_getAllDrafts::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_setGameScore
bool TL_messages_setGameScore::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  score_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_setGameScore::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(id_);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  iobw.writeLE(score_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_getAppChangelog
bool TL_help_getAppChangelog::Decode(IOBufReader& iobr) {
  ReadString(iobr, &prev_app_version_);
  return true;
}
bool TL_help_getAppChangelog::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, prev_app_version_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_createChannel
bool TL_channels_createChannel::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  ReadString(iobr, &title_);
  ReadString(iobr, &about_);
  return true;
}
bool TL_channels_createChannel::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  WriteString(iobw, title_);
  WriteString(iobw, about_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_editAdmin
bool TL_channels_editAdmin::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChannelParticipantRole*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    role_ = std::unique_ptr<ChannelParticipantRole>(o2);
  }
  return true;
}
bool TL_channels_editAdmin::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  if (!role_) return false;
  role_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_editTitle
bool TL_channels_editTitle::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  ReadString(iobr, &title_);
  return true;
}
bool TL_channels_editTitle::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  WriteString(iobw, title_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_editPhoto
bool TL_channels_editPhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChatPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    photo_ = std::unique_ptr<InputChatPhoto>(o2);
  }
  return true;
}
bool TL_channels_editPhoto::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!photo_) return false;
  photo_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_joinChannel
bool TL_channels_joinChannel::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  return true;
}
bool TL_channels_joinChannel::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_leaveChannel
bool TL_channels_leaveChannel::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  return true;
}
bool TL_channels_leaveChannel::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_inviteToChannel
bool TL_channels_inviteToChannel::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  users_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_channels_inviteToChannel::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  users_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_kickFromChannel
bool TL_channels_kickFromChannel::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    kicked_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_channels_kickFromChannel::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  if (!kicked_) return false;
  kicked_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_deleteChannel
bool TL_channels_deleteChannel::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  return true;
}
bool TL_channels_deleteChannel::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_toggleInvites
bool TL_channels_toggleInvites::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    enabled_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_channels_toggleInvites::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!enabled_) return false;
  enabled_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_toggleSignatures
bool TL_channels_toggleSignatures::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    enabled_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_channels_toggleSignatures::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!enabled_) return false;
  enabled_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_updatePinnedMessage
bool TL_channels_updatePinnedMessage::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channels_updatePinnedMessage::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_discardCall
bool TL_phone_discardCall::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoneCall*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPhoneCall>(o2);
  }
  duration_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallDiscardReason*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    reason_ = std::unique_ptr<PhoneCallDiscardReason>(o2);
  }
  connection_id_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_phone_discardCall::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(duration_);
  if (!reason_) return false;
  reason_-> SerializeToIOBuf(iobw);
  iobw.writeLE(connection_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_setCallRating
bool TL_phone_setCallRating::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoneCall*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPhoneCall>(o2);
  }
  rating_ = iobr.readLE<int32_t>();
  ReadString(iobr, &comment_);
  return true;
}
bool TL_phone_setCallRating::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(rating_);
  WriteString(iobw, comment_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getPeerSettings
bool TL_messages_getPeerSettings::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  return true;
}
bool TL_messages_getPeerSettings::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getChats
bool TL_messages_getChats::Decode(IOBufReader& iobr) {
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_getChats::Encode(IOBufWriter& iobw) const {
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getCommonChats
bool TL_messages_getCommonChats::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  max_id_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getCommonChats::Encode(IOBufWriter& iobw) const {
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  iobw.writeLE(max_id_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getAllChats
bool TL_messages_getAllChats::Decode(IOBufReader& iobr) {
  except_ids_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_getAllChats::Encode(IOBufWriter& iobw) const {
  except_ids_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_getChannels
bool TL_channels_getChannels::Decode(IOBufReader& iobr) {
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_channels_getChannels::Encode(IOBufWriter& iobw) const {
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_getAdminedPublicChannels
bool TL_channels_getAdminedPublicChannels::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_channels_getAdminedPublicChannels::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getFullChat
bool TL_messages_getFullChat::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getFullChat::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_getFullChannel
bool TL_channels_getFullChannel::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  return true;
}
bool TL_channels_getFullChannel::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getDhConfig
bool TL_messages_getDhConfig::Decode(IOBufReader& iobr) {
  version_ = iobr.readLE<int32_t>();
  random_length_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getDhConfig::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(version_);
  iobw.writeLE(random_length_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_requestEncryption
bool TL_messages_requestEncryption::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  random_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &g_a_);
  return true;
}
bool TL_messages_requestEncryption::Encode(IOBufWriter& iobw) const {
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  iobw.writeLE(random_id_);
  WriteString(iobw, g_a_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_acceptEncryption
bool TL_messages_acceptEncryption::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputEncryptedChat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputEncryptedChat>(o2);
  }
  ReadString(iobr, &g_b_);
  key_fingerprint_ = iobr.readLE<int64_t>();
  return true;
}
bool TL_messages_acceptEncryption::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  WriteString(iobw, g_b_);
  iobw.writeLE(key_fingerprint_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_sendEncrypted
bool TL_messages_sendEncrypted::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputEncryptedChat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputEncryptedChat>(o2);
  }
  random_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &data_);
  return true;
}
bool TL_messages_sendEncrypted::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(random_id_);
  WriteString(iobw, data_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_sendEncryptedFile
bool TL_messages_sendEncryptedFile::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputEncryptedChat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputEncryptedChat>(o2);
  }
  random_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &data_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputEncryptedFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_ = std::unique_ptr<InputEncryptedFile>(o2);
  }
  return true;
}
bool TL_messages_sendEncryptedFile::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(random_id_);
  WriteString(iobw, data_);
  if (!file_) return false;
  file_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_sendEncryptedService
bool TL_messages_sendEncryptedService::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputEncryptedChat*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputEncryptedChat>(o2);
  }
  random_id_ = iobr.readLE<int64_t>();
  ReadString(iobr, &data_);
  return true;
}
bool TL_messages_sendEncryptedService::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(random_id_);
  WriteString(iobw, data_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_receivedQueue
bool TL_messages_receivedQueue::Decode(IOBufReader& iobr) {
  max_qts_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_receivedQueue::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(max_qts_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photos_deletePhotos
bool TL_photos_deletePhotos::Decode(IOBufReader& iobr) {
  id_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_photos_deletePhotos::Encode(IOBufWriter& iobw) const {
  id_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getAllStickers
bool TL_messages_getAllStickers::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getAllStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getMaskStickers
bool TL_messages_getMaskStickers::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getMaskStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getWebPagePreview
bool TL_messages_getWebPagePreview::Decode(IOBufReader& iobr) {
  ReadString(iobr, &message_);
  return true;
}
bool TL_messages_getWebPagePreview::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, message_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_exportChatInvite
bool TL_messages_exportChatInvite::Decode(IOBufReader& iobr) {
  chat_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_exportChatInvite::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(chat_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_exportInvite
bool TL_channels_exportInvite::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  return true;
}
bool TL_channels_exportInvite::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_checkChatInvite
bool TL_messages_checkChatInvite::Decode(IOBufReader& iobr) {
  ReadString(iobr, &hash_);
  return true;
}
bool TL_messages_checkChatInvite::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getStickerSet
bool TL_messages_getStickerSet::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputStickerSet*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    stickerset_ = std::unique_ptr<InputStickerSet>(o2);
  }
  return true;
}
bool TL_messages_getStickerSet::Encode(IOBufWriter& iobw) const {
  if (!stickerset_) return false;
  stickerset_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_installStickerSet
bool TL_messages_installStickerSet::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputStickerSet*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    stickerset_ = std::unique_ptr<InputStickerSet>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<Bool*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    archived_ = std::unique_ptr<Bool>(o2);
  }
  return true;
}
bool TL_messages_installStickerSet::Encode(IOBufWriter& iobw) const {
  if (!stickerset_) return false;
  stickerset_-> SerializeToIOBuf(iobw);
  if (!archived_) return false;
  archived_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getDocumentByHash
bool TL_messages_getDocumentByHash::Decode(IOBufReader& iobr) {
  ReadString(iobr, &sha256_);
  size_ = iobr.readLE<int32_t>();
  ReadString(iobr, &mime_type_);
  return true;
}
bool TL_messages_getDocumentByHash::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, sha256_);
  iobw.writeLE(size_);
  WriteString(iobw, mime_type_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_searchGifs
bool TL_messages_searchGifs::Decode(IOBufReader& iobr) {
  ReadString(iobr, &q_);
  offset_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_searchGifs::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, q_);
  iobw.writeLE(offset_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getSavedGifs
bool TL_messages_getSavedGifs::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getSavedGifs::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getInlineBotResults
bool TL_messages_getInlineBotResults::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    bot_ = std::unique_ptr<InputUser>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  if (has_geo_point()) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputGeoPoint*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    geo_point_ = std::unique_ptr<InputGeoPoint>(o2);
  }
  ReadString(iobr, &query_);
  ReadString(iobr, &offset_);
  return true;
}
bool TL_messages_getInlineBotResults::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!bot_) return false;
  bot_-> SerializeToIOBuf(iobw);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  if (has_geo_point()) geo_point_->SerializeToIOBuf(iobw);
  WriteString(iobw, query_);
  WriteString(iobw, offset_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getMessageEditData
bool TL_messages_getMessageEditData::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getMessageEditData::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getBotCallbackAnswer
bool TL_messages_getBotCallbackAnswer::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  msg_id_ = iobr.readLE<int32_t>();
  if (has_data()) {
    ReadString(iobr, &data_);
  }
  return true;
}
bool TL_messages_getBotCallbackAnswer::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(msg_id_);
  if (has_data()) WriteString(iobw, data_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getPeerDialogs
bool TL_messages_getPeerDialogs::Decode(IOBufReader& iobr) {
  peers_.ParseFromIOBuf(iobr);
  return true;
}
bool TL_messages_getPeerDialogs::Encode(IOBufWriter& iobw) const {
  peers_.SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getPinnedDialogs
bool TL_messages_getPinnedDialogs::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_messages_getPinnedDialogs::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getFeaturedStickers
bool TL_messages_getFeaturedStickers::Decode(IOBufReader& iobr) {
  hash_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getFeaturedStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getRecentStickers
bool TL_messages_getRecentStickers::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  hash_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getRecentStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getArchivedStickers
bool TL_messages_getArchivedStickers::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  offset_id_ = iobr.readLE<int64_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getArchivedStickers::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(offset_id_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getAttachedStickers
bool TL_messages_getAttachedStickers::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputStickeredMedia*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    media_ = std::unique_ptr<InputStickeredMedia>(o2);
  }
  return true;
}
bool TL_messages_getAttachedStickers::Encode(IOBufWriter& iobw) const {
  if (!media_) return false;
  media_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getGameHighScores
bool TL_messages_getGameHighScores::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPeer*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPeer>(o2);
  }
  id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_messages_getGameHighScores::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  iobw.writeLE(id_);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getInlineGameHighScores
bool TL_messages_getInlineGameHighScores::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputBotInlineMessageID*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputBotInlineMessageID>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_messages_getInlineGameHighScores::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// messages_getWebPage
bool TL_messages_getWebPage::Decode(IOBufReader& iobr) {
  ReadString(iobr, &url_);
  hash_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_messages_getWebPage::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, url_);
  iobw.writeLE(hash_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_getState
bool TL_updates_getState::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_updates_getState::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_getDifference
bool TL_updates_getDifference::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  pts_ = iobr.readLE<int32_t>();
  if (has_pts_total_limit()) {
    pts_total_limit_ = iobr.readLE<int32_t>();
  }
  date_ = iobr.readLE<int32_t>();
  qts_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updates_getDifference::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(pts_);
  if (has_pts_total_limit()) iobw.writeLE(pts_total_limit_);
  iobw.writeLE(date_);
  iobw.writeLE(qts_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// updates_getChannelDifference
bool TL_updates_getChannelDifference::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChannelMessagesFilter*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    filter_ = std::unique_ptr<ChannelMessagesFilter>(o2);
  }
  pts_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_updates_getChannelDifference::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!filter_) return false;
  filter_-> SerializeToIOBuf(iobw);
  iobw.writeLE(pts_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photos_updateProfilePhoto
bool TL_photos_updateProfilePhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoto*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    id_ = std::unique_ptr<InputPhoto>(o2);
  }
  return true;
}
bool TL_photos_updateProfilePhoto::Encode(IOBufWriter& iobw) const {
  if (!id_) return false;
  id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photos_uploadProfilePhoto
bool TL_photos_uploadProfilePhoto::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputFile*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    file_ = std::unique_ptr<InputFile>(o2);
  }
  return true;
}
bool TL_photos_uploadProfilePhoto::Encode(IOBufWriter& iobw) const {
  if (!file_) return false;
  file_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// photos_getUserPhotos
bool TL_photos_getUserPhotos::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  offset_ = iobr.readLE<int32_t>();
  max_id_ = iobr.readLE<int64_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_photos_getUserPhotos::Encode(IOBufWriter& iobw) const {
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  iobw.writeLE(offset_);
  iobw.writeLE(max_id_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_getFile
bool TL_upload_getFile::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputFileLocation*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    location_ = std::unique_ptr<InputFileLocation>(o2);
  }
  offset_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_upload_getFile::Encode(IOBufWriter& iobw) const {
  if (!location_) return false;
  location_-> SerializeToIOBuf(iobw);
  iobw.writeLE(offset_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_getWebFile
bool TL_upload_getWebFile::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputWebFileLocation*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    location_ = std::unique_ptr<InputWebFileLocation>(o2);
  }
  offset_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_upload_getWebFile::Encode(IOBufWriter& iobw) const {
  if (!location_) return false;
  location_-> SerializeToIOBuf(iobw);
  iobw.writeLE(offset_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// upload_getCdnFile
bool TL_upload_getCdnFile::Decode(IOBufReader& iobr) {
  ReadString(iobr, &file_token_);
  offset_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_upload_getCdnFile::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, file_token_);
  iobw.writeLE(offset_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_getConfig
bool TL_help_getConfig::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_help_getConfig::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_getNearestDc
bool TL_help_getNearestDc::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_help_getNearestDc::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_getAppUpdate
bool TL_help_getAppUpdate::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_help_getAppUpdate::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_getInviteText
bool TL_help_getInviteText::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_help_getInviteText::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_getSupport
bool TL_help_getSupport::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_help_getSupport::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_getTermsOfService
bool TL_help_getTermsOfService::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_help_getTermsOfService::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// help_getCdnConfig
bool TL_help_getCdnConfig::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_help_getCdnConfig::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_getParticipants
bool TL_channels_getParticipants::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<ChannelParticipantsFilter*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    filter_ = std::unique_ptr<ChannelParticipantsFilter>(o2);
  }
  offset_ = iobr.readLE<int32_t>();
  limit_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channels_getParticipants::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!filter_) return false;
  filter_-> SerializeToIOBuf(iobw);
  iobw.writeLE(offset_);
  iobw.writeLE(limit_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_getParticipant
bool TL_channels_getParticipant::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  return true;
}
bool TL_channels_getParticipant::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// channels_exportMessageLink
bool TL_channels_exportMessageLink::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputChannel*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    channel_ = std::unique_ptr<InputChannel>(o2);
  }
  id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_channels_exportMessageLink::Encode(IOBufWriter& iobw) const {
  if (!channel_) return false;
  channel_-> SerializeToIOBuf(iobw);
  iobw.writeLE(id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// bots_sendCustomRequest
bool TL_bots_sendCustomRequest::Decode(IOBufReader& iobr) {
  ReadString(iobr, &custom_method_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<DataJSON*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    params_ = std::unique_ptr<DataJSON>(o2);
  }
  return true;
}
bool TL_bots_sendCustomRequest::Encode(IOBufWriter& iobw) const {
  WriteString(iobw, custom_method_);
  if (!params_) return false;
  params_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_getCallConfig
bool TL_phone_getCallConfig::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_phone_getCallConfig::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_getPaymentForm
bool TL_payments_getPaymentForm::Decode(IOBufReader& iobr) {
  msg_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_payments_getPaymentForm::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(msg_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_getPaymentReceipt
bool TL_payments_getPaymentReceipt::Decode(IOBufReader& iobr) {
  msg_id_ = iobr.readLE<int32_t>();
  return true;
}
bool TL_payments_getPaymentReceipt::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(msg_id_);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_validateRequestedInfo
bool TL_payments_validateRequestedInfo::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  msg_id_ = iobr.readLE<int32_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PaymentRequestedInfo*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    info_ = std::unique_ptr<PaymentRequestedInfo>(o2);
  }
  return true;
}
bool TL_payments_validateRequestedInfo::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(msg_id_);
  if (!info_) return false;
  info_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_sendPaymentForm
bool TL_payments_sendPaymentForm::Decode(IOBufReader& iobr) {
  flags_ = iobr.readLE<int32_t>();
  msg_id_ = iobr.readLE<int32_t>();
  if (has_requested_info_id()) {
    ReadString(iobr, &requested_info_id_);
  }
  if (has_shipping_option_id()) {
    ReadString(iobr, &shipping_option_id_);
  }
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPaymentCredentials*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    credentials_ = std::unique_ptr<InputPaymentCredentials>(o2);
  }
  return true;
}
bool TL_payments_sendPaymentForm::Encode(IOBufWriter& iobw) const {
  iobw.writeLE(flags_);
  iobw.writeLE(msg_id_);
  if (has_requested_info_id()) WriteString(iobw, requested_info_id_);
  if (has_shipping_option_id()) WriteString(iobw, shipping_option_id_);
  if (!credentials_) return false;
  credentials_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// payments_getSavedInfo
bool TL_payments_getSavedInfo::Decode(IOBufReader& iobr) {
  return true;
}
bool TL_payments_getSavedInfo::Encode(IOBufWriter& iobw) const {
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_requestCall
bool TL_phone_requestCall::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputUser*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    user_id_ = std::unique_ptr<InputUser>(o2);
  }
  random_id_ = iobr.readLE<int32_t>();
  ReadString(iobr, &g_a_hash_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallProtocol*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    protocol_ = std::unique_ptr<PhoneCallProtocol>(o2);
  }
  return true;
}
bool TL_phone_requestCall::Encode(IOBufWriter& iobw) const {
  if (!user_id_) return false;
  user_id_-> SerializeToIOBuf(iobw);
  iobw.writeLE(random_id_);
  WriteString(iobw, g_a_hash_);
  if (!protocol_) return false;
  protocol_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_acceptCall
bool TL_phone_acceptCall::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoneCall*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPhoneCall>(o2);
  }
  ReadString(iobr, &g_b_);
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallProtocol*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    protocol_ = std::unique_ptr<PhoneCallProtocol>(o2);
  }
  return true;
}
bool TL_phone_acceptCall::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  WriteString(iobw, g_b_);
  if (!protocol_) return false;
  protocol_-> SerializeToIOBuf(iobw);
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// phone_confirmCall
bool TL_phone_confirmCall::Decode(IOBufReader& iobr) {
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<InputPhoneCall*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    peer_ = std::unique_ptr<InputPhoneCall>(o2);
  }
  ReadString(iobr, &g_a_);
  key_fingerprint_ = iobr.readLE<int64_t>();
  if (true) {
    auto o = TLObject::CreateObjectByIOBuf(iobr);
    if (o == nullptr) return false;
    auto o2 = reinterpret_cast<PhoneCallProtocol*>(o);
    if (o2 == nullptr) {
      delete o;
      return false;
    }
    protocol_ = std::unique_ptr<PhoneCallProtocol>(o2);
  }
  return true;
}
bool TL_phone_confirmCall::Encode(IOBufWriter& iobw) const {
  if (!peer_) return false;
  peer_-> SerializeToIOBuf(iobw);
  WriteString(iobw, g_a_);
  iobw.writeLE(key_fingerprint_);
  if (!protocol_) return false;
  protocol_-> SerializeToIOBuf(iobw);
  return true;
}



