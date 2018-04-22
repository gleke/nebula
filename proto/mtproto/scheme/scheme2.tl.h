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
#include "nebula/base/self_register_factory_manager.h"

// Type forward declarations
class ResPQ;
class TL_resPQ;

class P_Q_inner_data;
class TL_p_q_inner_data;

class Server_DH_Params;
class TL_server_DH_params_fail;
class TL_server_DH_params_ok;

class Server_DH_inner_data;
class TL_server_DH_inner_data;

class Client_DH_Inner_Data;
class TL_client_DH_inner_data;

class Set_client_DH_params_answer;
class TL_dh_gen_ok;
class TL_dh_gen_retry;
class TL_dh_gen_fail;

class DestroyAuthKeyRes;
class TL_destroy_auth_key_ok;
class TL_destroy_auth_key_none;
class TL_destroy_auth_key_fail;

class MsgsAck;
class TL_msgs_ack;

class BadMsgNotification;
class TL_bad_msg_notification;
class TL_bad_server_salt;

class MsgsStateReq;
class TL_msgs_state_req;

class MsgsStateInfo;
class TL_msgs_state_info;

class MsgsAllInfo;
class TL_msgs_all_info;

class MsgDetailedInfo;
class TL_msg_detailed_info;
class TL_msg_new_detailed_info;

class MsgResendReq;
class TL_msg_resend_req;

class RpcError;
class TL_rpc_error;

class RpcDropAnswer;
class TL_rpc_answer_unknown;
class TL_rpc_answer_dropped_running;
class TL_rpc_answer_dropped;

class FutureSalt;
class TL_future_salt;

class FutureSalts;
class TL_future_salts;

class Pong;
class TL_pong;

class DestroySessionRes;
class TL_destroy_session_ok;
class TL_destroy_session_none;

class NewSession;
class TL_new_session_created;

class HttpWait;
class TL_http_wait;

class Bool;
class TL_boolFalse;
class TL_boolTrue;

class True;
class TL_true;

class Error;
class TL_error;

class Null;
class TL_null;

class InputPeer;
class TL_inputPeerEmpty;
class TL_inputPeerSelf;
class TL_inputPeerChat;
class TL_inputPeerUser;
class TL_inputPeerChannel;

class InputUser;
class TL_inputUserEmpty;
class TL_inputUserSelf;
class TL_inputUser;

class InputContact;
class TL_inputPhoneContact;

class InputFile;
class TL_inputFile;
class TL_inputFileBig;

class InputMedia;
class TL_inputMediaEmpty;
class TL_inputMediaUploadedPhoto;
class TL_inputMediaPhoto;
class TL_inputMediaGeoPoint;
class TL_inputMediaContact;
class TL_inputMediaUploadedDocument;
class TL_inputMediaUploadedThumbDocument;
class TL_inputMediaDocument;
class TL_inputMediaVenue;
class TL_inputMediaGifExternal;
class TL_inputMediaPhotoExternal;
class TL_inputMediaDocumentExternal;
class TL_inputMediaGame;
class TL_inputMediaInvoice;

class InputChatPhoto;
class TL_inputChatPhotoEmpty;
class TL_inputChatUploadedPhoto;
class TL_inputChatPhoto;

class InputGeoPoint;
class TL_inputGeoPointEmpty;
class TL_inputGeoPoint;

class InputPhoto;
class TL_inputPhotoEmpty;
class TL_inputPhoto;

class InputFileLocation;
class TL_inputFileLocation;
class TL_inputEncryptedFileLocation;
class TL_inputDocumentFileLocation;

class InputAppEvent;
class TL_inputAppEvent;

class Peer;
class TL_peerUser;
class TL_peerChat;
class TL_peerChannel;

class storage_FileType;
class TL_storage_fileUnknown;
class TL_storage_filePartial;
class TL_storage_fileJpeg;
class TL_storage_fileGif;
class TL_storage_filePng;
class TL_storage_filePdf;
class TL_storage_fileMp3;
class TL_storage_fileMov;
class TL_storage_fileMp4;
class TL_storage_fileWebp;

class FileLocation;
class TL_fileLocationUnavailable;
class TL_fileLocation;

class User;
class TL_userEmpty;
class TL_user;

class UserProfilePhoto;
class TL_userProfilePhotoEmpty;
class TL_userProfilePhoto;

class UserStatus;
class TL_userStatusEmpty;
class TL_userStatusOnline;
class TL_userStatusOffline;
class TL_userStatusRecently;
class TL_userStatusLastWeek;
class TL_userStatusLastMonth;

class Chat;
class TL_chatEmpty;
class TL_chat;
class TL_chatForbidden;
class TL_channel;
class TL_channelForbidden;

class ChatFull;
class TL_chatFull;
class TL_channelFull;

class ChatParticipant;
class TL_chatParticipant;
class TL_chatParticipantCreator;
class TL_chatParticipantAdmin;

class ChatParticipants;
class TL_chatParticipantsForbidden;
class TL_chatParticipants;

class ChatPhoto;
class TL_chatPhotoEmpty;
class TL_chatPhoto;

class Message;
class TL_messageEmpty;
class TL_message;
class TL_messageService;

class MessageMedia;
class TL_messageMediaEmpty;
class TL_messageMediaPhoto;
class TL_messageMediaGeo;
class TL_messageMediaContact;
class TL_messageMediaUnsupported;
class TL_messageMediaDocument;
class TL_messageMediaWebPage;
class TL_messageMediaVenue;
class TL_messageMediaGame;
class TL_messageMediaInvoice;

class MessageAction;
class TL_messageActionEmpty;
class TL_messageActionChatCreate;
class TL_messageActionChatEditTitle;
class TL_messageActionChatEditPhoto;
class TL_messageActionChatDeletePhoto;
class TL_messageActionChatAddUser;
class TL_messageActionChatDeleteUser;
class TL_messageActionChatJoinedByLink;
class TL_messageActionChannelCreate;
class TL_messageActionChatMigrateTo;
class TL_messageActionChannelMigrateFrom;
class TL_messageActionPinMessage;
class TL_messageActionHistoryClear;
class TL_messageActionGameScore;
class TL_messageActionPaymentSentMe;
class TL_messageActionPaymentSent;
class TL_messageActionPhoneCall;

class Dialog;
class TL_dialog;

class Photo;
class TL_photoEmpty;
class TL_photo;

class PhotoSize;
class TL_photoSizeEmpty;
class TL_photoSize;
class TL_photoCachedSize;

class GeoPoint;
class TL_geoPointEmpty;
class TL_geoPoint;

class auth_CheckedPhone;
class TL_auth_checkedPhone;

class auth_SentCode;
class TL_auth_sentCode;

class auth_Authorization;
class TL_auth_authorization;

class auth_ExportedAuthorization;
class TL_auth_exportedAuthorization;

class InputNotifyPeer;
class TL_inputNotifyPeer;
class TL_inputNotifyUsers;
class TL_inputNotifyChats;
class TL_inputNotifyAll;

class InputPeerNotifyEvents;
class TL_inputPeerNotifyEventsEmpty;
class TL_inputPeerNotifyEventsAll;

class InputPeerNotifySettings;
class TL_inputPeerNotifySettings;

class PeerNotifyEvents;
class TL_peerNotifyEventsEmpty;
class TL_peerNotifyEventsAll;

class PeerNotifySettings;
class TL_peerNotifySettingsEmpty;
class TL_peerNotifySettings;

class PeerSettings;
class TL_peerSettings;

class WallPaper;
class TL_wallPaper;
class TL_wallPaperSolid;

class ReportReason;
class TL_inputReportReasonSpam;
class TL_inputReportReasonViolence;
class TL_inputReportReasonPornography;
class TL_inputReportReasonOther;

class UserFull;
class TL_userFull;

class Contact;
class TL_contact;

class ImportedContact;
class TL_importedContact;

class ContactBlocked;
class TL_contactBlocked;

class ContactStatus;
class TL_contactStatus;

class contacts_Link;
class TL_contacts_link;

class contacts_Contacts;
class TL_contacts_contactsNotModified;
class TL_contacts_contacts;

class contacts_ImportedContacts;
class TL_contacts_importedContacts;

class contacts_Blocked;
class TL_contacts_blocked;
class TL_contacts_blockedSlice;

class messages_Dialogs;
class TL_messages_dialogs;
class TL_messages_dialogsSlice;

class messages_Messages;
class TL_messages_messages;
class TL_messages_messagesSlice;
class TL_messages_channelMessages;

class messages_Chats;
class TL_messages_chats;
class TL_messages_chatsSlice;

class messages_ChatFull;
class TL_messages_chatFull;

class messages_AffectedHistory;
class TL_messages_affectedHistory;

class MessagesFilter;
class TL_inputMessagesFilterEmpty;
class TL_inputMessagesFilterPhotos;
class TL_inputMessagesFilterVideo;
class TL_inputMessagesFilterPhotoVideo;
class TL_inputMessagesFilterPhotoVideoDocuments;
class TL_inputMessagesFilterDocument;
class TL_inputMessagesFilterUrl;
class TL_inputMessagesFilterGif;
class TL_inputMessagesFilterVoice;
class TL_inputMessagesFilterMusic;
class TL_inputMessagesFilterChatPhotos;
class TL_inputMessagesFilterPhoneCalls;
class TL_inputMessagesFilterRoundVoice;
class TL_inputMessagesFilterRoundVideo;

class Update;
class TL_updateNewMessage;
class TL_updateMessageID;
class TL_updateDeleteMessages;
class TL_updateUserTyping;
class TL_updateChatUserTyping;
class TL_updateChatParticipants;
class TL_updateUserStatus;
class TL_updateUserName;
class TL_updateUserPhoto;
class TL_updateContactRegistered;
class TL_updateContactLink;
class TL_updateNewEncryptedMessage;
class TL_updateEncryptedChatTyping;
class TL_updateEncryption;
class TL_updateEncryptedMessagesRead;
class TL_updateChatParticipantAdd;
class TL_updateChatParticipantDelete;
class TL_updateDcOptions;
class TL_updateUserBlocked;
class TL_updateNotifySettings;
class TL_updateServiceNotification;
class TL_updatePrivacy;
class TL_updateUserPhone;
class TL_updateReadHistoryInbox;
class TL_updateReadHistoryOutbox;
class TL_updateWebPage;
class TL_updateReadMessagesContents;
class TL_updateChannelTooLong;
class TL_updateChannel;
class TL_updateNewChannelMessage;
class TL_updateReadChannelInbox;
class TL_updateDeleteChannelMessages;
class TL_updateChannelMessageViews;
class TL_updateChatAdmins;
class TL_updateChatParticipantAdmin;
class TL_updateNewStickerSet;
class TL_updateStickerSetsOrder;
class TL_updateStickerSets;
class TL_updateSavedGifs;
class TL_updateBotInlineQuery;
class TL_updateBotInlineSend;
class TL_updateEditChannelMessage;
class TL_updateChannelPinnedMessage;
class TL_updateBotCallbackQuery;
class TL_updateEditMessage;
class TL_updateInlineBotCallbackQuery;
class TL_updateReadChannelOutbox;
class TL_updateDraftMessage;
class TL_updateReadFeaturedStickers;
class TL_updateRecentStickers;
class TL_updateConfig;
class TL_updatePtsChanged;
class TL_updateChannelWebPage;
class TL_updateDialogPinned;
class TL_updatePinnedDialogs;
class TL_updateBotWebhookJSON;
class TL_updateBotWebhookJSONQuery;
class TL_updateBotShippingQuery;
class TL_updateBotPrecheckoutQuery;
class TL_updatePhoneCall;

class updates_State;
class TL_updates_state;

class updates_Difference;
class TL_updates_differenceEmpty;
class TL_updates_difference;
class TL_updates_differenceSlice;
class TL_updates_differenceTooLong;

class Updates;
class TL_updatesTooLong;
class TL_updateShortMessage;
class TL_updateShortChatMessage;
class TL_updateShort;
class TL_updatesCombined;
class TL_updates;
class TL_updateShortSentMessage;

class photos_Photos;
class TL_photos_photos;
class TL_photos_photosSlice;

class photos_Photo;
class TL_photos_photo;

class upload_File;
class TL_upload_file;
class TL_upload_fileCdnRedirect;

class DcOption;
class TL_dcOption;

class Config;
class TL_config;

class NearestDc;
class TL_nearestDc;

class help_AppUpdate;
class TL_help_appUpdate;
class TL_help_noAppUpdate;

class help_InviteText;
class TL_help_inviteText;

class EncryptedChat;
class TL_encryptedChatEmpty;
class TL_encryptedChatWaiting;
class TL_encryptedChatRequested;
class TL_encryptedChat;
class TL_encryptedChatDiscarded;

class InputEncryptedChat;
class TL_inputEncryptedChat;

class EncryptedFile;
class TL_encryptedFileEmpty;
class TL_encryptedFile;

class InputEncryptedFile;
class TL_inputEncryptedFileEmpty;
class TL_inputEncryptedFileUploaded;
class TL_inputEncryptedFile;
class TL_inputEncryptedFileBigUploaded;

class EncryptedMessage;
class TL_encryptedMessage;
class TL_encryptedMessageService;

class messages_DhConfig;
class TL_messages_dhConfigNotModified;
class TL_messages_dhConfig;

class messages_SentEncryptedMessage;
class TL_messages_sentEncryptedMessage;
class TL_messages_sentEncryptedFile;

class InputDocument;
class TL_inputDocumentEmpty;
class TL_inputDocument;

class Document;
class TL_documentEmpty;
class TL_document;

class help_Support;
class TL_help_support;

class NotifyPeer;
class TL_notifyPeer;
class TL_notifyUsers;
class TL_notifyChats;
class TL_notifyAll;

class SendMessageAction;
class TL_sendMessageTypingAction;
class TL_sendMessageCancelAction;
class TL_sendMessageRecordVideoAction;
class TL_sendMessageUploadVideoAction;
class TL_sendMessageRecordAudioAction;
class TL_sendMessageUploadAudioAction;
class TL_sendMessageUploadPhotoAction;
class TL_sendMessageUploadDocumentAction;
class TL_sendMessageGeoLocationAction;
class TL_sendMessageChooseContactAction;
class TL_sendMessageGamePlayAction;
class TL_sendMessageRecordRoundAction;
class TL_sendMessageUploadRoundAction;

class contacts_Found;
class TL_contacts_found;

class InputPrivacyKey;
class TL_inputPrivacyKeyStatusTimestamp;
class TL_inputPrivacyKeyChatInvite;
class TL_inputPrivacyKeyPhoneCall;

class PrivacyKey;
class TL_privacyKeyStatusTimestamp;
class TL_privacyKeyChatInvite;
class TL_privacyKeyPhoneCall;

class InputPrivacyRule;
class TL_inputPrivacyValueAllowContacts;
class TL_inputPrivacyValueAllowAll;
class TL_inputPrivacyValueAllowUsers;
class TL_inputPrivacyValueDisallowContacts;
class TL_inputPrivacyValueDisallowAll;
class TL_inputPrivacyValueDisallowUsers;

class PrivacyRule;
class TL_privacyValueAllowContacts;
class TL_privacyValueAllowAll;
class TL_privacyValueAllowUsers;
class TL_privacyValueDisallowContacts;
class TL_privacyValueDisallowAll;
class TL_privacyValueDisallowUsers;

class account_PrivacyRules;
class TL_account_privacyRules;

class AccountDaysTTL;
class TL_accountDaysTTL;

class DocumentAttribute;
class TL_documentAttributeImageSize;
class TL_documentAttributeAnimated;
class TL_documentAttributeSticker;
class TL_documentAttributeVideo;
class TL_documentAttributeAudio;
class TL_documentAttributeFilename;
class TL_documentAttributeHasStickers;

class messages_Stickers;
class TL_messages_stickersNotModified;
class TL_messages_stickers;

class StickerPack;
class TL_stickerPack;

class messages_AllStickers;
class TL_messages_allStickersNotModified;
class TL_messages_allStickers;

class DisabledFeature;
class TL_disabledFeature;

class messages_AffectedMessages;
class TL_messages_affectedMessages;

class ContactLink;
class TL_contactLinkUnknown;
class TL_contactLinkNone;
class TL_contactLinkHasPhone;
class TL_contactLinkContact;

class WebPage;
class TL_webPageEmpty;
class TL_webPagePending;
class TL_webPage;
class TL_webPageNotModified;

class Authorization;
class TL_authorization;

class account_Authorizations;
class TL_account_authorizations;

class account_Password;
class TL_account_noPassword;
class TL_account_password;

class account_PasswordSettings;
class TL_account_passwordSettings;

class account_PasswordInputSettings;
class TL_account_passwordInputSettings;

class auth_PasswordRecovery;
class TL_auth_passwordRecovery;

class ReceivedNotifyMessage;
class TL_receivedNotifyMessage;

class ExportedChatInvite;
class TL_chatInviteEmpty;
class TL_chatInviteExported;

class ChatInvite;
class TL_chatInviteAlready;
class TL_chatInvite;

class InputStickerSet;
class TL_inputStickerSetEmpty;
class TL_inputStickerSetID;
class TL_inputStickerSetShortName;

class StickerSet;
class TL_stickerSet;

class messages_StickerSet;
class TL_messages_stickerSet;

class BotCommand;
class TL_botCommand;

class BotInfo;
class TL_botInfo;

class KeyboardButton;
class TL_keyboardButton;
class TL_keyboardButtonUrl;
class TL_keyboardButtonCallback;
class TL_keyboardButtonRequestPhone;
class TL_keyboardButtonRequestGeoLocation;
class TL_keyboardButtonSwitchInline;
class TL_keyboardButtonGame;
class TL_keyboardButtonBuy;

class KeyboardButtonRow;
class TL_keyboardButtonRow;

class ReplyMarkup;
class TL_replyKeyboardHide;
class TL_replyKeyboardForceReply;
class TL_replyKeyboardMarkup;
class TL_replyInlineMarkup;

class MessageEntity;
class TL_messageEntityUnknown;
class TL_messageEntityMention;
class TL_messageEntityHashtag;
class TL_messageEntityBotCommand;
class TL_messageEntityUrl;
class TL_messageEntityEmail;
class TL_messageEntityBold;
class TL_messageEntityItalic;
class TL_messageEntityCode;
class TL_messageEntityPre;
class TL_messageEntityTextUrl;
class TL_messageEntityMentionName;
class TL_inputMessageEntityMentionName;

class InputChannel;
class TL_inputChannelEmpty;
class TL_inputChannel;

class contacts_ResolvedPeer;
class TL_contacts_resolvedPeer;

class MessageRange;
class TL_messageRange;

class updates_ChannelDifference;
class TL_updates_channelDifferenceEmpty;
class TL_updates_channelDifferenceTooLong;
class TL_updates_channelDifference;

class ChannelMessagesFilter;
class TL_channelMessagesFilterEmpty;
class TL_channelMessagesFilter;

class ChannelParticipant;
class TL_channelParticipant;
class TL_channelParticipantSelf;
class TL_channelParticipantModerator;
class TL_channelParticipantEditor;
class TL_channelParticipantKicked;
class TL_channelParticipantCreator;

class ChannelParticipantsFilter;
class TL_channelParticipantsRecent;
class TL_channelParticipantsAdmins;
class TL_channelParticipantsKicked;
class TL_channelParticipantsBots;

class ChannelParticipantRole;
class TL_channelRoleEmpty;
class TL_channelRoleModerator;
class TL_channelRoleEditor;

class channels_ChannelParticipants;
class TL_channels_channelParticipants;

class channels_ChannelParticipant;
class TL_channels_channelParticipant;

class help_TermsOfService;
class TL_help_termsOfService;

class FoundGif;
class TL_foundGif;
class TL_foundGifCached;

class messages_FoundGifs;
class TL_messages_foundGifs;

class messages_SavedGifs;
class TL_messages_savedGifsNotModified;
class TL_messages_savedGifs;

class InputBotInlineMessage;
class TL_inputBotInlineMessageMediaAuto;
class TL_inputBotInlineMessageText;
class TL_inputBotInlineMessageMediaGeo;
class TL_inputBotInlineMessageMediaVenue;
class TL_inputBotInlineMessageMediaContact;
class TL_inputBotInlineMessageGame;

class InputBotInlineResult;
class TL_inputBotInlineResult;
class TL_inputBotInlineResultPhoto;
class TL_inputBotInlineResultDocument;
class TL_inputBotInlineResultGame;

class BotInlineMessage;
class TL_botInlineMessageMediaAuto;
class TL_botInlineMessageText;
class TL_botInlineMessageMediaGeo;
class TL_botInlineMessageMediaVenue;
class TL_botInlineMessageMediaContact;

class BotInlineResult;
class TL_botInlineResult;
class TL_botInlineMediaResult;

class messages_BotResults;
class TL_messages_botResults;

class ExportedMessageLink;
class TL_exportedMessageLink;

class MessageFwdHeader;
class TL_messageFwdHeader;

class auth_CodeType;
class TL_auth_codeTypeSms;
class TL_auth_codeTypeCall;
class TL_auth_codeTypeFlashCall;

class auth_SentCodeType;
class TL_auth_sentCodeTypeApp;
class TL_auth_sentCodeTypeSms;
class TL_auth_sentCodeTypeCall;
class TL_auth_sentCodeTypeFlashCall;

class messages_BotCallbackAnswer;
class TL_messages_botCallbackAnswer;

class messages_MessageEditData;
class TL_messages_messageEditData;

class InputBotInlineMessageID;
class TL_inputBotInlineMessageID;

class InlineBotSwitchPM;
class TL_inlineBotSwitchPM;

class messages_PeerDialogs;
class TL_messages_peerDialogs;

class TopPeer;
class TL_topPeer;

class TopPeerCategory;
class TL_topPeerCategoryBotsPM;
class TL_topPeerCategoryBotsInline;
class TL_topPeerCategoryCorrespondents;
class TL_topPeerCategoryGroups;
class TL_topPeerCategoryChannels;

class TopPeerCategoryPeers;
class TL_topPeerCategoryPeers;

class contacts_TopPeers;
class TL_contacts_topPeersNotModified;
class TL_contacts_topPeers;

class DraftMessage;
class TL_draftMessageEmpty;
class TL_draftMessage;

class messages_FeaturedStickers;
class TL_messages_featuredStickersNotModified;
class TL_messages_featuredStickers;

class messages_RecentStickers;
class TL_messages_recentStickersNotModified;
class TL_messages_recentStickers;

class messages_ArchivedStickers;
class TL_messages_archivedStickers;

class messages_StickerSetInstallResult;
class TL_messages_stickerSetInstallResultSuccess;
class TL_messages_stickerSetInstallResultArchive;

class StickerSetCovered;
class TL_stickerSetCovered;
class TL_stickerSetMultiCovered;

class MaskCoords;
class TL_maskCoords;

class InputStickeredMedia;
class TL_inputStickeredMediaPhoto;
class TL_inputStickeredMediaDocument;

class Game;
class TL_game;

class InputGame;
class TL_inputGameID;
class TL_inputGameShortName;

class HighScore;
class TL_highScore;

class messages_HighScores;
class TL_messages_highScores;

class RichText;
class TL_textEmpty;
class TL_textPlain;
class TL_textBold;
class TL_textItalic;
class TL_textUnderline;
class TL_textStrike;
class TL_textFixed;
class TL_textUrl;
class TL_textEmail;
class TL_textConcat;

class PageBlock;
class TL_pageBlockUnsupported;
class TL_pageBlockTitle;
class TL_pageBlockSubtitle;
class TL_pageBlockAuthorDate;
class TL_pageBlockHeader;
class TL_pageBlockSubheader;
class TL_pageBlockParagraph;
class TL_pageBlockPreformatted;
class TL_pageBlockFooter;
class TL_pageBlockDivider;
class TL_pageBlockAnchor;
class TL_pageBlockList;
class TL_pageBlockBlockquote;
class TL_pageBlockPullquote;
class TL_pageBlockPhoto;
class TL_pageBlockVideo;
class TL_pageBlockCover;
class TL_pageBlockEmbed;
class TL_pageBlockEmbedPost;
class TL_pageBlockCollage;
class TL_pageBlockSlideshow;
class TL_pageBlockChannel;

class Page;
class TL_pagePart;
class TL_pageFull;

class PhoneCallDiscardReason;
class TL_phoneCallDiscardReasonMissed;
class TL_phoneCallDiscardReasonDisconnect;
class TL_phoneCallDiscardReasonHangup;
class TL_phoneCallDiscardReasonBusy;

class DataJSON;
class TL_dataJSON;

class LabeledPrice;
class TL_labeledPrice;

class Invoice;
class TL_invoice;

class PaymentCharge;
class TL_paymentCharge;

class PostAddress;
class TL_postAddress;

class PaymentRequestedInfo;
class TL_paymentRequestedInfo;

class PaymentSavedCredentials;
class TL_paymentSavedCredentialsCard;

class WebDocument;
class TL_webDocument;

class InputWebDocument;
class TL_inputWebDocument;

class InputWebFileLocation;
class TL_inputWebFileLocation;

class upload_WebFile;
class TL_upload_webFile;

class payments_PaymentForm;
class TL_payments_paymentForm;

class payments_ValidatedRequestedInfo;
class TL_payments_validatedRequestedInfo;

class payments_PaymentResult;
class TL_payments_paymentResult;
class TL_payments_paymentVerficationNeeded;

class payments_PaymentReceipt;
class TL_payments_paymentReceipt;

class payments_SavedInfo;
class TL_payments_savedInfo;

class InputPaymentCredentials;
class TL_inputPaymentCredentialsSaved;
class TL_inputPaymentCredentials;

class account_TmpPassword;
class TL_account_tmpPassword;

class ShippingOption;
class TL_shippingOption;

class InputPhoneCall;
class TL_inputPhoneCall;

class PhoneCall;
class TL_phoneCallEmpty;
class TL_phoneCallWaiting;
class TL_phoneCallRequested;
class TL_phoneCallAccepted;
class TL_phoneCall;
class TL_phoneCallDiscarded;

class PhoneConnection;
class TL_phoneConnection;

class PhoneCallProtocol;
class TL_phoneCallProtocol;

class phone_PhoneCall;
class TL_phone_phoneCall;

class upload_CdnFile;
class TL_upload_cdnFileReuploadNeeded;
class TL_upload_cdnFile;

class CdnPublicKey;
class TL_cdnPublicKey;

class CdnConfig;
class TL_cdnConfig;



class ResPQ : public TLObject {
public:
  virtual ~ResPQ() override = default;
};

class P_Q_inner_data : public TLObject {
public:
  virtual ~P_Q_inner_data() override = default;
};

class Server_DH_Params : public TLObject {
public:
  virtual ~Server_DH_Params() override = default;
};

class Server_DH_inner_data : public TLObject {
public:
  virtual ~Server_DH_inner_data() override = default;
};

class Client_DH_Inner_Data : public TLObject {
public:
  virtual ~Client_DH_Inner_Data() override = default;
};

class Set_client_DH_params_answer : public TLObject {
public:
  virtual ~Set_client_DH_params_answer() override = default;
};

class DestroyAuthKeyRes : public TLObject {
public:
  virtual ~DestroyAuthKeyRes() override = default;
};

class MsgsAck : public TLObject {
public:
  virtual ~MsgsAck() override = default;
};

class BadMsgNotification : public TLObject {
public:
  virtual ~BadMsgNotification() override = default;
};

class MsgsStateReq : public TLObject {
public:
  virtual ~MsgsStateReq() override = default;
};

class MsgsStateInfo : public TLObject {
public:
  virtual ~MsgsStateInfo() override = default;
};

class MsgsAllInfo : public TLObject {
public:
  virtual ~MsgsAllInfo() override = default;
};

class MsgDetailedInfo : public TLObject {
public:
  virtual ~MsgDetailedInfo() override = default;
};

class MsgResendReq : public TLObject {
public:
  virtual ~MsgResendReq() override = default;
};

class RpcError : public TLObject {
public:
  virtual ~RpcError() override = default;
};

class RpcDropAnswer : public TLObject {
public:
  virtual ~RpcDropAnswer() override = default;
};

class FutureSalt : public TLObject {
public:
  virtual ~FutureSalt() override = default;
};

class FutureSalts : public TLObject {
public:
  virtual ~FutureSalts() override = default;
};

class Pong : public TLObject {
public:
  virtual ~Pong() override = default;
};

class DestroySessionRes : public TLObject {
public:
  virtual ~DestroySessionRes() override = default;
};

class NewSession : public TLObject {
public:
  virtual ~NewSession() override = default;
};

class HttpWait : public TLObject {
public:
  virtual ~HttpWait() override = default;
};

class Bool : public TLObject {
public:
  virtual ~Bool() override = default;
};

class True : public TLObject {
public:
  virtual ~True() override = default;
};

class Error : public TLObject {
public:
  virtual ~Error() override = default;
};

class Null : public TLObject {
public:
  virtual ~Null() override = default;
};

class InputPeer : public TLObject {
public:
  virtual ~InputPeer() override = default;
};

class InputUser : public TLObject {
public:
  virtual ~InputUser() override = default;
};

class InputContact : public TLObject {
public:
  virtual ~InputContact() override = default;
};

class InputFile : public TLObject {
public:
  virtual ~InputFile() override = default;
};

class InputMedia : public TLObject {
public:
  virtual ~InputMedia() override = default;
};

class InputChatPhoto : public TLObject {
public:
  virtual ~InputChatPhoto() override = default;
};

class InputGeoPoint : public TLObject {
public:
  virtual ~InputGeoPoint() override = default;
};

class InputPhoto : public TLObject {
public:
  virtual ~InputPhoto() override = default;
};

class InputFileLocation : public TLObject {
public:
  virtual ~InputFileLocation() override = default;
};

class InputAppEvent : public TLObject {
public:
  virtual ~InputAppEvent() override = default;
};

class Peer : public TLObject {
public:
  virtual ~Peer() override = default;
};

class storage_FileType : public TLObject {
public:
  virtual ~storage_FileType() override = default;
};

class FileLocation : public TLObject {
public:
  virtual ~FileLocation() override = default;
};

class User : public TLObject {
public:
  virtual ~User() override = default;
};

class UserProfilePhoto : public TLObject {
public:
  virtual ~UserProfilePhoto() override = default;
};

class UserStatus : public TLObject {
public:
  virtual ~UserStatus() override = default;
};

class Chat : public TLObject {
public:
  virtual ~Chat() override = default;
};

class ChatFull : public TLObject {
public:
  virtual ~ChatFull() override = default;
};

class ChatParticipant : public TLObject {
public:
  virtual ~ChatParticipant() override = default;
};

class ChatParticipants : public TLObject {
public:
  virtual ~ChatParticipants() override = default;
};

class ChatPhoto : public TLObject {
public:
  virtual ~ChatPhoto() override = default;
};

class Message : public TLObject {
public:
  virtual ~Message() override = default;
};

class MessageMedia : public TLObject {
public:
  virtual ~MessageMedia() override = default;
};

class MessageAction : public TLObject {
public:
  virtual ~MessageAction() override = default;
};

class Dialog : public TLObject {
public:
  virtual ~Dialog() override = default;
};

class Photo : public TLObject {
public:
  virtual ~Photo() override = default;
};

class PhotoSize : public TLObject {
public:
  virtual ~PhotoSize() override = default;
};

class GeoPoint : public TLObject {
public:
  virtual ~GeoPoint() override = default;
};

class auth_CheckedPhone : public TLObject {
public:
  virtual ~auth_CheckedPhone() override = default;
};

class auth_SentCode : public TLObject {
public:
  virtual ~auth_SentCode() override = default;
};

class auth_Authorization : public TLObject {
public:
  virtual ~auth_Authorization() override = default;
};

class auth_ExportedAuthorization : public TLObject {
public:
  virtual ~auth_ExportedAuthorization() override = default;
};

class InputNotifyPeer : public TLObject {
public:
  virtual ~InputNotifyPeer() override = default;
};

class InputPeerNotifyEvents : public TLObject {
public:
  virtual ~InputPeerNotifyEvents() override = default;
};

class InputPeerNotifySettings : public TLObject {
public:
  virtual ~InputPeerNotifySettings() override = default;
};

class PeerNotifyEvents : public TLObject {
public:
  virtual ~PeerNotifyEvents() override = default;
};

class PeerNotifySettings : public TLObject {
public:
  virtual ~PeerNotifySettings() override = default;
};

class PeerSettings : public TLObject {
public:
  virtual ~PeerSettings() override = default;
};

class WallPaper : public TLObject {
public:
  virtual ~WallPaper() override = default;
};

class ReportReason : public TLObject {
public:
  virtual ~ReportReason() override = default;
};

class UserFull : public TLObject {
public:
  virtual ~UserFull() override = default;
};

class Contact : public TLObject {
public:
  virtual ~Contact() override = default;
};

class ImportedContact : public TLObject {
public:
  virtual ~ImportedContact() override = default;
};

class ContactBlocked : public TLObject {
public:
  virtual ~ContactBlocked() override = default;
};

class ContactStatus : public TLObject {
public:
  virtual ~ContactStatus() override = default;
};

class contacts_Link : public TLObject {
public:
  virtual ~contacts_Link() override = default;
};

class contacts_Contacts : public TLObject {
public:
  virtual ~contacts_Contacts() override = default;
};

class contacts_ImportedContacts : public TLObject {
public:
  virtual ~contacts_ImportedContacts() override = default;
};

class contacts_Blocked : public TLObject {
public:
  virtual ~contacts_Blocked() override = default;
};

class messages_Dialogs : public TLObject {
public:
  virtual ~messages_Dialogs() override = default;
};

class messages_Messages : public TLObject {
public:
  virtual ~messages_Messages() override = default;
};

class messages_Chats : public TLObject {
public:
  virtual ~messages_Chats() override = default;
};

class messages_ChatFull : public TLObject {
public:
  virtual ~messages_ChatFull() override = default;
};

class messages_AffectedHistory : public TLObject {
public:
  virtual ~messages_AffectedHistory() override = default;
};

class MessagesFilter : public TLObject {
public:
  virtual ~MessagesFilter() override = default;
};

class Update : public TLObject {
public:
  virtual ~Update() override = default;
};

class updates_State : public TLObject {
public:
  virtual ~updates_State() override = default;
};

class updates_Difference : public TLObject {
public:
  virtual ~updates_Difference() override = default;
};

class Updates : public TLObject {
public:
  virtual ~Updates() override = default;
};

class photos_Photos : public TLObject {
public:
  virtual ~photos_Photos() override = default;
};

class photos_Photo : public TLObject {
public:
  virtual ~photos_Photo() override = default;
};

class upload_File : public TLObject {
public:
  virtual ~upload_File() override = default;
};

class DcOption : public TLObject {
public:
  virtual ~DcOption() override = default;
};

class Config : public TLObject {
public:
  virtual ~Config() override = default;
};

class NearestDc : public TLObject {
public:
  virtual ~NearestDc() override = default;
};

class help_AppUpdate : public TLObject {
public:
  virtual ~help_AppUpdate() override = default;
};

class help_InviteText : public TLObject {
public:
  virtual ~help_InviteText() override = default;
};

class EncryptedChat : public TLObject {
public:
  virtual ~EncryptedChat() override = default;
};

class InputEncryptedChat : public TLObject {
public:
  virtual ~InputEncryptedChat() override = default;
};

class EncryptedFile : public TLObject {
public:
  virtual ~EncryptedFile() override = default;
};

class InputEncryptedFile : public TLObject {
public:
  virtual ~InputEncryptedFile() override = default;
};

class EncryptedMessage : public TLObject {
public:
  virtual ~EncryptedMessage() override = default;
};

class messages_DhConfig : public TLObject {
public:
  virtual ~messages_DhConfig() override = default;
};

class messages_SentEncryptedMessage : public TLObject {
public:
  virtual ~messages_SentEncryptedMessage() override = default;
};

class InputDocument : public TLObject {
public:
  virtual ~InputDocument() override = default;
};

class Document : public TLObject {
public:
  virtual ~Document() override = default;
};

class help_Support : public TLObject {
public:
  virtual ~help_Support() override = default;
};

class NotifyPeer : public TLObject {
public:
  virtual ~NotifyPeer() override = default;
};

class SendMessageAction : public TLObject {
public:
  virtual ~SendMessageAction() override = default;
};

class contacts_Found : public TLObject {
public:
  virtual ~contacts_Found() override = default;
};

class InputPrivacyKey : public TLObject {
public:
  virtual ~InputPrivacyKey() override = default;
};

class PrivacyKey : public TLObject {
public:
  virtual ~PrivacyKey() override = default;
};

class InputPrivacyRule : public TLObject {
public:
  virtual ~InputPrivacyRule() override = default;
};

class PrivacyRule : public TLObject {
public:
  virtual ~PrivacyRule() override = default;
};

class account_PrivacyRules : public TLObject {
public:
  virtual ~account_PrivacyRules() override = default;
};

class AccountDaysTTL : public TLObject {
public:
  virtual ~AccountDaysTTL() override = default;
};

class DocumentAttribute : public TLObject {
public:
  virtual ~DocumentAttribute() override = default;
};

class messages_Stickers : public TLObject {
public:
  virtual ~messages_Stickers() override = default;
};

class StickerPack : public TLObject {
public:
  virtual ~StickerPack() override = default;
};

class messages_AllStickers : public TLObject {
public:
  virtual ~messages_AllStickers() override = default;
};

class DisabledFeature : public TLObject {
public:
  virtual ~DisabledFeature() override = default;
};

class messages_AffectedMessages : public TLObject {
public:
  virtual ~messages_AffectedMessages() override = default;
};

class ContactLink : public TLObject {
public:
  virtual ~ContactLink() override = default;
};

class WebPage : public TLObject {
public:
  virtual ~WebPage() override = default;
};

class Authorization : public TLObject {
public:
  virtual ~Authorization() override = default;
};

class account_Authorizations : public TLObject {
public:
  virtual ~account_Authorizations() override = default;
};

class account_Password : public TLObject {
public:
  virtual ~account_Password() override = default;
};

class account_PasswordSettings : public TLObject {
public:
  virtual ~account_PasswordSettings() override = default;
};

class account_PasswordInputSettings : public TLObject {
public:
  virtual ~account_PasswordInputSettings() override = default;
};

class auth_PasswordRecovery : public TLObject {
public:
  virtual ~auth_PasswordRecovery() override = default;
};

class ReceivedNotifyMessage : public TLObject {
public:
  virtual ~ReceivedNotifyMessage() override = default;
};

class ExportedChatInvite : public TLObject {
public:
  virtual ~ExportedChatInvite() override = default;
};

class ChatInvite : public TLObject {
public:
  virtual ~ChatInvite() override = default;
};

class InputStickerSet : public TLObject {
public:
  virtual ~InputStickerSet() override = default;
};

class StickerSet : public TLObject {
public:
  virtual ~StickerSet() override = default;
};

class messages_StickerSet : public TLObject {
public:
  virtual ~messages_StickerSet() override = default;
};

class BotCommand : public TLObject {
public:
  virtual ~BotCommand() override = default;
};

class BotInfo : public TLObject {
public:
  virtual ~BotInfo() override = default;
};

class KeyboardButton : public TLObject {
public:
  virtual ~KeyboardButton() override = default;
};

class KeyboardButtonRow : public TLObject {
public:
  virtual ~KeyboardButtonRow() override = default;
};

class ReplyMarkup : public TLObject {
public:
  virtual ~ReplyMarkup() override = default;
};

class MessageEntity : public TLObject {
public:
  virtual ~MessageEntity() override = default;
};

class InputChannel : public TLObject {
public:
  virtual ~InputChannel() override = default;
};

class contacts_ResolvedPeer : public TLObject {
public:
  virtual ~contacts_ResolvedPeer() override = default;
};

class MessageRange : public TLObject {
public:
  virtual ~MessageRange() override = default;
};

class updates_ChannelDifference : public TLObject {
public:
  virtual ~updates_ChannelDifference() override = default;
};

class ChannelMessagesFilter : public TLObject {
public:
  virtual ~ChannelMessagesFilter() override = default;
};

class ChannelParticipant : public TLObject {
public:
  virtual ~ChannelParticipant() override = default;
};

class ChannelParticipantsFilter : public TLObject {
public:
  virtual ~ChannelParticipantsFilter() override = default;
};

class ChannelParticipantRole : public TLObject {
public:
  virtual ~ChannelParticipantRole() override = default;
};

class channels_ChannelParticipants : public TLObject {
public:
  virtual ~channels_ChannelParticipants() override = default;
};

class channels_ChannelParticipant : public TLObject {
public:
  virtual ~channels_ChannelParticipant() override = default;
};

class help_TermsOfService : public TLObject {
public:
  virtual ~help_TermsOfService() override = default;
};

class FoundGif : public TLObject {
public:
  virtual ~FoundGif() override = default;
};

class messages_FoundGifs : public TLObject {
public:
  virtual ~messages_FoundGifs() override = default;
};

class messages_SavedGifs : public TLObject {
public:
  virtual ~messages_SavedGifs() override = default;
};

class InputBotInlineMessage : public TLObject {
public:
  virtual ~InputBotInlineMessage() override = default;
};

class InputBotInlineResult : public TLObject {
public:
  virtual ~InputBotInlineResult() override = default;
};

class BotInlineMessage : public TLObject {
public:
  virtual ~BotInlineMessage() override = default;
};

class BotInlineResult : public TLObject {
public:
  virtual ~BotInlineResult() override = default;
};

class messages_BotResults : public TLObject {
public:
  virtual ~messages_BotResults() override = default;
};

class ExportedMessageLink : public TLObject {
public:
  virtual ~ExportedMessageLink() override = default;
};

class MessageFwdHeader : public TLObject {
public:
  virtual ~MessageFwdHeader() override = default;
};

class auth_CodeType : public TLObject {
public:
  virtual ~auth_CodeType() override = default;
};

class auth_SentCodeType : public TLObject {
public:
  virtual ~auth_SentCodeType() override = default;
};

class messages_BotCallbackAnswer : public TLObject {
public:
  virtual ~messages_BotCallbackAnswer() override = default;
};

class messages_MessageEditData : public TLObject {
public:
  virtual ~messages_MessageEditData() override = default;
};

class InputBotInlineMessageID : public TLObject {
public:
  virtual ~InputBotInlineMessageID() override = default;
};

class InlineBotSwitchPM : public TLObject {
public:
  virtual ~InlineBotSwitchPM() override = default;
};

class messages_PeerDialogs : public TLObject {
public:
  virtual ~messages_PeerDialogs() override = default;
};

class TopPeer : public TLObject {
public:
  virtual ~TopPeer() override = default;
};

class TopPeerCategory : public TLObject {
public:
  virtual ~TopPeerCategory() override = default;
};

class TopPeerCategoryPeers : public TLObject {
public:
  virtual ~TopPeerCategoryPeers() override = default;
};

class contacts_TopPeers : public TLObject {
public:
  virtual ~contacts_TopPeers() override = default;
};

class DraftMessage : public TLObject {
public:
  virtual ~DraftMessage() override = default;
};

class messages_FeaturedStickers : public TLObject {
public:
  virtual ~messages_FeaturedStickers() override = default;
};

class messages_RecentStickers : public TLObject {
public:
  virtual ~messages_RecentStickers() override = default;
};

class messages_ArchivedStickers : public TLObject {
public:
  virtual ~messages_ArchivedStickers() override = default;
};

class messages_StickerSetInstallResult : public TLObject {
public:
  virtual ~messages_StickerSetInstallResult() override = default;
};

class StickerSetCovered : public TLObject {
public:
  virtual ~StickerSetCovered() override = default;
};

class MaskCoords : public TLObject {
public:
  virtual ~MaskCoords() override = default;
};

class InputStickeredMedia : public TLObject {
public:
  virtual ~InputStickeredMedia() override = default;
};

class Game : public TLObject {
public:
  virtual ~Game() override = default;
};

class InputGame : public TLObject {
public:
  virtual ~InputGame() override = default;
};

class HighScore : public TLObject {
public:
  virtual ~HighScore() override = default;
};

class messages_HighScores : public TLObject {
public:
  virtual ~messages_HighScores() override = default;
};

class RichText : public TLObject {
public:
  virtual ~RichText() override = default;
};

class PageBlock : public TLObject {
public:
  virtual ~PageBlock() override = default;
};

class Page : public TLObject {
public:
  virtual ~Page() override = default;
};

class PhoneCallDiscardReason : public TLObject {
public:
  virtual ~PhoneCallDiscardReason() override = default;
};

class DataJSON : public TLObject {
public:
  virtual ~DataJSON() override = default;
};

class LabeledPrice : public TLObject {
public:
  virtual ~LabeledPrice() override = default;
};

class Invoice : public TLObject {
public:
  virtual ~Invoice() override = default;
};

class PaymentCharge : public TLObject {
public:
  virtual ~PaymentCharge() override = default;
};

class PostAddress : public TLObject {
public:
  virtual ~PostAddress() override = default;
};

class PaymentRequestedInfo : public TLObject {
public:
  virtual ~PaymentRequestedInfo() override = default;
};

class PaymentSavedCredentials : public TLObject {
public:
  virtual ~PaymentSavedCredentials() override = default;
};

class WebDocument : public TLObject {
public:
  virtual ~WebDocument() override = default;
};

class InputWebDocument : public TLObject {
public:
  virtual ~InputWebDocument() override = default;
};

class InputWebFileLocation : public TLObject {
public:
  virtual ~InputWebFileLocation() override = default;
};

class upload_WebFile : public TLObject {
public:
  virtual ~upload_WebFile() override = default;
};

class payments_PaymentForm : public TLObject {
public:
  virtual ~payments_PaymentForm() override = default;
};

class payments_ValidatedRequestedInfo : public TLObject {
public:
  virtual ~payments_ValidatedRequestedInfo() override = default;
};

class payments_PaymentResult : public TLObject {
public:
  virtual ~payments_PaymentResult() override = default;
};

class payments_PaymentReceipt : public TLObject {
public:
  virtual ~payments_PaymentReceipt() override = default;
};

class payments_SavedInfo : public TLObject {
public:
  virtual ~payments_SavedInfo() override = default;
};

class InputPaymentCredentials : public TLObject {
public:
  virtual ~InputPaymentCredentials() override = default;
};

class account_TmpPassword : public TLObject {
public:
  virtual ~account_TmpPassword() override = default;
};

class ShippingOption : public TLObject {
public:
  virtual ~ShippingOption() override = default;
};

class InputPhoneCall : public TLObject {
public:
  virtual ~InputPhoneCall() override = default;
};

class PhoneCall : public TLObject {
public:
  virtual ~PhoneCall() override = default;
};

class PhoneConnection : public TLObject {
public:
  virtual ~PhoneConnection() override = default;
};

class PhoneCallProtocol : public TLObject {
public:
  virtual ~PhoneCallProtocol() override = default;
};

class phone_PhoneCall : public TLObject {
public:
  virtual ~phone_PhoneCall() override = default;
};

class upload_CdnFile : public TLObject {
public:
  virtual ~upload_CdnFile() override = default;
};

class CdnPublicKey : public TLObject {
public:
  virtual ~CdnPublicKey() override = default;
};

class CdnConfig : public TLObject {
public:
  virtual ~CdnConfig() override = default;
};



// resPQ#05162463 nonce:int128 server_nonce:int128 pq:string server_public_key_fingerprints:Vector<long> = ResPQ;
class TL_resPQ : public ResPQ {
public:
  enum {
    CLASS_ID = 0x5162463
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "resPQ#0x5162463";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  std::string* mutable_pq() { return &pq_; } 
  const std::string& pq() const { return pq_; } 
  void set_pq(const std::string& v) { pq_ = v; } 
  void set_pq(const char* v, size_t n) { pq_.assign(v, n); } 
  void set_pq(const char* v) { pq_ = v; } 

  size_t server_public_key_fingerprints_size() const { return server_public_key_fingerprints_.size(); } 
  const TLInt64Vector& server_public_key_fingerprints() const { return server_public_key_fingerprints_; } 
  int64_t server_public_key_fingerprints(int idx) const { return server_public_key_fingerprints_.vector()[idx]; } 
  void add_server_public_key_fingerprints(int64_t v) {server_public_key_fingerprints_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_server_public_key_fingerprints() { return &server_public_key_fingerprints_; } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  std::string pq_;
  TLInt64Vector server_public_key_fingerprints_;
};

// p_q_inner_data#83c95aec pq:string p:string q:string nonce:int128 server_nonce:int128 new_nonce:int256 = P_Q_inner_data;
class TL_p_q_inner_data : public P_Q_inner_data {
public:
  enum {
    CLASS_ID = 0x83c95aec
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "p_q_inner_data#0x83c95aec";
  }

  std::string* mutable_pq() { return &pq_; } 
  const std::string& pq() const { return pq_; } 
  void set_pq(const std::string& v) { pq_ = v; } 
  void set_pq(const char* v, size_t n) { pq_.assign(v, n); } 
  void set_pq(const char* v) { pq_ = v; } 

  std::string* mutable_p() { return &p_; } 
  const std::string& p() const { return p_; } 
  void set_p(const std::string& v) { p_ = v; } 
  void set_p(const char* v, size_t n) { p_.assign(v, n); } 
  void set_p(const char* v) { p_ = v; } 

  std::string* mutable_q() { return &q_; } 
  const std::string& q() const { return q_; } 
  void set_q(const std::string& v) { q_ = v; } 
  void set_q(const char* v, size_t n) { q_.assign(v, n); } 
  void set_q(const char* v) { q_ = v; } 

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  TLInt256* mutable_new_nonce() { return &new_nonce_; } 
  const TLInt256& new_nonce() const { return new_nonce_; } 
  void set_new_nonce(const TLInt256& v) { new_nonce_.Copy(v); } 

private:
  std::string pq_;
  std::string p_;
  std::string q_;
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt256 new_nonce_;
};

// server_DH_params_fail#79cb045d nonce:int128 server_nonce:int128 new_nonce_hash:int128 = Server_DH_Params;
class TL_server_DH_params_fail : public Server_DH_Params {
public:
  enum {
    CLASS_ID = 0x79cb045d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "server_DH_params_fail#0x79cb045d";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  TLInt128* mutable_new_nonce_hash() { return &new_nonce_hash_; } 
  const TLInt128& new_nonce_hash() const { return new_nonce_hash_; } 
  void set_new_nonce_hash(const TLInt128& v) { new_nonce_hash_.Copy(v); } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt128 new_nonce_hash_;
};

// server_DH_params_ok#d0e8075c nonce:int128 server_nonce:int128 encrypted_answer:string = Server_DH_Params;
class TL_server_DH_params_ok : public Server_DH_Params {
public:
  enum {
    CLASS_ID = 0xd0e8075c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "server_DH_params_ok#0xd0e8075c";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  std::string* mutable_encrypted_answer() { return &encrypted_answer_; } 
  const std::string& encrypted_answer() const { return encrypted_answer_; } 
  void set_encrypted_answer(const std::string& v) { encrypted_answer_ = v; } 
  void set_encrypted_answer(const char* v, size_t n) { encrypted_answer_.assign(v, n); } 
  void set_encrypted_answer(const char* v) { encrypted_answer_ = v; } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  std::string encrypted_answer_;
};

// server_DH_inner_data#b5890dba nonce:int128 server_nonce:int128 g:int dh_prime:string g_a:string server_time:int = Server_DH_inner_data;
class TL_server_DH_inner_data : public Server_DH_inner_data {
public:
  enum {
    CLASS_ID = 0xb5890dba
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "server_DH_inner_data#0xb5890dba";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  int32_t g() const { return g_; } 
  void set_g(int32_t v) { g_ = v; } 

  std::string* mutable_dh_prime() { return &dh_prime_; } 
  const std::string& dh_prime() const { return dh_prime_; } 
  void set_dh_prime(const std::string& v) { dh_prime_ = v; } 
  void set_dh_prime(const char* v, size_t n) { dh_prime_.assign(v, n); } 
  void set_dh_prime(const char* v) { dh_prime_ = v; } 

  std::string* mutable_g_a() { return &g_a_; } 
  const std::string& g_a() const { return g_a_; } 
  void set_g_a(const std::string& v) { g_a_ = v; } 
  void set_g_a(const char* v, size_t n) { g_a_.assign(v, n); } 
  void set_g_a(const char* v) { g_a_ = v; } 

  int32_t server_time() const { return server_time_; } 
  void set_server_time(int32_t v) { server_time_ = v; } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  int32_t g_;
  std::string dh_prime_;
  std::string g_a_;
  int32_t server_time_;
};

// client_DH_inner_data#6643b654 nonce:int128 server_nonce:int128 retry_id:long g_b:string = Client_DH_Inner_Data;
class TL_client_DH_inner_data : public Client_DH_Inner_Data {
public:
  enum {
    CLASS_ID = 0x6643b654
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "client_DH_inner_data#0x6643b654";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  int64_t retry_id() const { return retry_id_; } 
  void set_retry_id(int64_t v) { retry_id_ = v; } 

  std::string* mutable_g_b() { return &g_b_; } 
  const std::string& g_b() const { return g_b_; } 
  void set_g_b(const std::string& v) { g_b_ = v; } 
  void set_g_b(const char* v, size_t n) { g_b_.assign(v, n); } 
  void set_g_b(const char* v) { g_b_ = v; } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  int64_t retry_id_;
  std::string g_b_;
};

// dh_gen_ok#3bcbf734 nonce:int128 server_nonce:int128 new_nonce_hash1:int128 = Set_client_DH_params_answer;
class TL_dh_gen_ok : public Set_client_DH_params_answer {
public:
  enum {
    CLASS_ID = 0x3bcbf734
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "dh_gen_ok#0x3bcbf734";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  TLInt128* mutable_new_nonce_hash1() { return &new_nonce_hash1_; } 
  const TLInt128& new_nonce_hash1() const { return new_nonce_hash1_; } 
  void set_new_nonce_hash1(const TLInt128& v) { new_nonce_hash1_.Copy(v); } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt128 new_nonce_hash1_;
};

// dh_gen_retry#46dc1fb9 nonce:int128 server_nonce:int128 new_nonce_hash2:int128 = Set_client_DH_params_answer;
class TL_dh_gen_retry : public Set_client_DH_params_answer {
public:
  enum {
    CLASS_ID = 0x46dc1fb9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "dh_gen_retry#0x46dc1fb9";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  TLInt128* mutable_new_nonce_hash2() { return &new_nonce_hash2_; } 
  const TLInt128& new_nonce_hash2() const { return new_nonce_hash2_; } 
  void set_new_nonce_hash2(const TLInt128& v) { new_nonce_hash2_.Copy(v); } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt128 new_nonce_hash2_;
};

// dh_gen_fail#a69dae02 nonce:int128 server_nonce:int128 new_nonce_hash3:int128 = Set_client_DH_params_answer;
class TL_dh_gen_fail : public Set_client_DH_params_answer {
public:
  enum {
    CLASS_ID = 0xa69dae02
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "dh_gen_fail#0xa69dae02";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  TLInt128* mutable_new_nonce_hash3() { return &new_nonce_hash3_; } 
  const TLInt128& new_nonce_hash3() const { return new_nonce_hash3_; } 
  void set_new_nonce_hash3(const TLInt128& v) { new_nonce_hash3_.Copy(v); } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  TLInt128 new_nonce_hash3_;
};

// destroy_auth_key_ok#f660e1d4 = DestroyAuthKeyRes;
class TL_destroy_auth_key_ok : public DestroyAuthKeyRes {
public:
  enum {
    CLASS_ID = 0xf660e1d4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "destroy_auth_key_ok#0xf660e1d4";
  }

private:
};

// destroy_auth_key_none#0a9f2259 = DestroyAuthKeyRes;
class TL_destroy_auth_key_none : public DestroyAuthKeyRes {
public:
  enum {
    CLASS_ID = 0xa9f2259
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "destroy_auth_key_none#0xa9f2259";
  }

private:
};

// destroy_auth_key_fail#ea109b13 = DestroyAuthKeyRes;
class TL_destroy_auth_key_fail : public DestroyAuthKeyRes {
public:
  enum {
    CLASS_ID = 0xea109b13
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "destroy_auth_key_fail#0xea109b13";
  }

private:
};

// msgs_ack#62d6b459 msg_ids:Vector<long> = MsgsAck;
class TL_msgs_ack : public MsgsAck {
public:
  enum {
    CLASS_ID = 0x62d6b459
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "msgs_ack#0x62d6b459";
  }

  size_t msg_ids_size() const { return msg_ids_.size(); } 
  const TLInt64Vector& msg_ids() const { return msg_ids_; } 
  int64_t msg_ids(int idx) const { return msg_ids_.vector()[idx]; } 
  void add_msg_ids(int64_t v) {msg_ids_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_msg_ids() { return &msg_ids_; } 

private:
  TLInt64Vector msg_ids_;
};

// bad_msg_notification#a7eff811 bad_msg_id:long bad_msg_seqno:int error_code:int = BadMsgNotification;
class TL_bad_msg_notification : public BadMsgNotification {
public:
  enum {
    CLASS_ID = 0xa7eff811
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "bad_msg_notification#0xa7eff811";
  }

  int64_t bad_msg_id() const { return bad_msg_id_; } 
  void set_bad_msg_id(int64_t v) { bad_msg_id_ = v; } 

  int32_t bad_msg_seqno() const { return bad_msg_seqno_; } 
  void set_bad_msg_seqno(int32_t v) { bad_msg_seqno_ = v; } 

  int32_t error_code() const { return error_code_; } 
  void set_error_code(int32_t v) { error_code_ = v; } 

private:
  int64_t bad_msg_id_;
  int32_t bad_msg_seqno_;
  int32_t error_code_;
};

// bad_server_salt#edab447b bad_msg_id:long bad_msg_seqno:int error_code:int new_server_salt:long = BadMsgNotification;
class TL_bad_server_salt : public BadMsgNotification {
public:
  enum {
    CLASS_ID = 0xedab447b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "bad_server_salt#0xedab447b";
  }

  int64_t bad_msg_id() const { return bad_msg_id_; } 
  void set_bad_msg_id(int64_t v) { bad_msg_id_ = v; } 

  int32_t bad_msg_seqno() const { return bad_msg_seqno_; } 
  void set_bad_msg_seqno(int32_t v) { bad_msg_seqno_ = v; } 

  int32_t error_code() const { return error_code_; } 
  void set_error_code(int32_t v) { error_code_ = v; } 

  int64_t new_server_salt() const { return new_server_salt_; } 
  void set_new_server_salt(int64_t v) { new_server_salt_ = v; } 

private:
  int64_t bad_msg_id_;
  int32_t bad_msg_seqno_;
  int32_t error_code_;
  int64_t new_server_salt_;
};

// msgs_state_req#da69fb52 msg_ids:Vector<long> = MsgsStateReq;
class TL_msgs_state_req : public MsgsStateReq {
public:
  enum {
    CLASS_ID = 0xda69fb52
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "msgs_state_req#0xda69fb52";
  }

  size_t msg_ids_size() const { return msg_ids_.size(); } 
  const TLInt64Vector& msg_ids() const { return msg_ids_; } 
  int64_t msg_ids(int idx) const { return msg_ids_.vector()[idx]; } 
  void add_msg_ids(int64_t v) {msg_ids_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_msg_ids() { return &msg_ids_; } 

private:
  TLInt64Vector msg_ids_;
};

// msgs_state_info#04deb57d req_msg_id:long info:string = MsgsStateInfo;
class TL_msgs_state_info : public MsgsStateInfo {
public:
  enum {
    CLASS_ID = 0x4deb57d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "msgs_state_info#0x4deb57d";
  }

  int64_t req_msg_id() const { return req_msg_id_; } 
  void set_req_msg_id(int64_t v) { req_msg_id_ = v; } 

  std::string* mutable_info() { return &info_; } 
  const std::string& info() const { return info_; } 
  void set_info(const std::string& v) { info_ = v; } 
  void set_info(const char* v, size_t n) { info_.assign(v, n); } 
  void set_info(const char* v) { info_ = v; } 

private:
  int64_t req_msg_id_;
  std::string info_;
};

// msgs_all_info#8cc0d131 msg_ids:Vector<long> info:string = MsgsAllInfo;
class TL_msgs_all_info : public MsgsAllInfo {
public:
  enum {
    CLASS_ID = 0x8cc0d131
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "msgs_all_info#0x8cc0d131";
  }

  size_t msg_ids_size() const { return msg_ids_.size(); } 
  const TLInt64Vector& msg_ids() const { return msg_ids_; } 
  int64_t msg_ids(int idx) const { return msg_ids_.vector()[idx]; } 
  void add_msg_ids(int64_t v) {msg_ids_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_msg_ids() { return &msg_ids_; } 

  std::string* mutable_info() { return &info_; } 
  const std::string& info() const { return info_; } 
  void set_info(const std::string& v) { info_ = v; } 
  void set_info(const char* v, size_t n) { info_.assign(v, n); } 
  void set_info(const char* v) { info_ = v; } 

private:
  TLInt64Vector msg_ids_;
  std::string info_;
};

// msg_detailed_info#276d3ec6 msg_id:long answer_msg_id:long bytes:int status:int = MsgDetailedInfo;
class TL_msg_detailed_info : public MsgDetailedInfo {
public:
  enum {
    CLASS_ID = 0x276d3ec6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "msg_detailed_info#0x276d3ec6";
  }

  int64_t msg_id() const { return msg_id_; } 
  void set_msg_id(int64_t v) { msg_id_ = v; } 

  int64_t answer_msg_id() const { return answer_msg_id_; } 
  void set_answer_msg_id(int64_t v) { answer_msg_id_ = v; } 

  int32_t bytes() const { return bytes_; } 
  void set_bytes(int32_t v) { bytes_ = v; } 

  int32_t status() const { return status_; } 
  void set_status(int32_t v) { status_ = v; } 

private:
  int64_t msg_id_;
  int64_t answer_msg_id_;
  int32_t bytes_;
  int32_t status_;
};

// msg_new_detailed_info#809db6df answer_msg_id:long bytes:int status:int = MsgDetailedInfo;
class TL_msg_new_detailed_info : public MsgDetailedInfo {
public:
  enum {
    CLASS_ID = 0x809db6df
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "msg_new_detailed_info#0x809db6df";
  }

  int64_t answer_msg_id() const { return answer_msg_id_; } 
  void set_answer_msg_id(int64_t v) { answer_msg_id_ = v; } 

  int32_t bytes() const { return bytes_; } 
  void set_bytes(int32_t v) { bytes_ = v; } 

  int32_t status() const { return status_; } 
  void set_status(int32_t v) { status_ = v; } 

private:
  int64_t answer_msg_id_;
  int32_t bytes_;
  int32_t status_;
};

// msg_resend_req#7d861a08 msg_ids:Vector<long> = MsgResendReq;
class TL_msg_resend_req : public MsgResendReq {
public:
  enum {
    CLASS_ID = 0x7d861a08
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "msg_resend_req#0x7d861a08";
  }

  size_t msg_ids_size() const { return msg_ids_.size(); } 
  const TLInt64Vector& msg_ids() const { return msg_ids_; } 
  int64_t msg_ids(int idx) const { return msg_ids_.vector()[idx]; } 
  void add_msg_ids(int64_t v) {msg_ids_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_msg_ids() { return &msg_ids_; } 

private:
  TLInt64Vector msg_ids_;
};

// rpc_error#2144ca19 error_code:int error_message:string = RpcError;
class TL_rpc_error : public RpcError {
public:
  enum {
    CLASS_ID = 0x2144ca19
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "rpc_error#0x2144ca19";
  }

  int32_t error_code() const { return error_code_; } 
  void set_error_code(int32_t v) { error_code_ = v; } 

  std::string* mutable_error_message() { return &error_message_; } 
  const std::string& error_message() const { return error_message_; } 
  void set_error_message(const std::string& v) { error_message_ = v; } 
  void set_error_message(const char* v, size_t n) { error_message_.assign(v, n); } 
  void set_error_message(const char* v) { error_message_ = v; } 

private:
  int32_t error_code_;
  std::string error_message_;
};

// rpc_answer_unknown#5e2ad36e = RpcDropAnswer;
class TL_rpc_answer_unknown : public RpcDropAnswer {
public:
  enum {
    CLASS_ID = 0x5e2ad36e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "rpc_answer_unknown#0x5e2ad36e";
  }

private:
};

// rpc_answer_dropped_running#cd78e586 = RpcDropAnswer;
class TL_rpc_answer_dropped_running : public RpcDropAnswer {
public:
  enum {
    CLASS_ID = 0xcd78e586
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "rpc_answer_dropped_running#0xcd78e586";
  }

private:
};

// rpc_answer_dropped#a43ad8b7 msg_id:long seq_no:int bytes:int = RpcDropAnswer;
class TL_rpc_answer_dropped : public RpcDropAnswer {
public:
  enum {
    CLASS_ID = 0xa43ad8b7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "rpc_answer_dropped#0xa43ad8b7";
  }

  int64_t msg_id() const { return msg_id_; } 
  void set_msg_id(int64_t v) { msg_id_ = v; } 

  int32_t seq_no() const { return seq_no_; } 
  void set_seq_no(int32_t v) { seq_no_ = v; } 

  int32_t bytes() const { return bytes_; } 
  void set_bytes(int32_t v) { bytes_ = v; } 

private:
  int64_t msg_id_;
  int32_t seq_no_;
  int32_t bytes_;
};

// future_salt#0949d9dc valid_since:int valid_until:int salt:long = FutureSalt;
class TL_future_salt : public FutureSalt {
public:
  enum {
    CLASS_ID = 0x949d9dc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "future_salt#0x949d9dc";
  }

  int32_t valid_since() const { return valid_since_; } 
  void set_valid_since(int32_t v) { valid_since_ = v; } 

  int32_t valid_until() const { return valid_until_; } 
  void set_valid_until(int32_t v) { valid_until_ = v; } 

  int64_t salt() const { return salt_; } 
  void set_salt(int64_t v) { salt_ = v; } 

private:
  int32_t valid_since_;
  int32_t valid_until_;
  int64_t salt_;
};

// future_salts#ae500895 req_msg_id:long now:int salts:vector<future_salt> = FutureSalts;
class TL_future_salts : public FutureSalts {
public:
  enum {
    CLASS_ID = 0xae500895
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "future_salts#0xae500895";
  }

  int64_t req_msg_id() const { return req_msg_id_; } 
  void set_req_msg_id(int64_t v) { req_msg_id_ = v; } 

  int32_t now() const { return now_; } 
  void set_now(int32_t v) { now_ = v; } 

private:
  int64_t req_msg_id_;
  int32_t now_;
  std::vector<std::unique_ptr<TL_future_salt>> salts_;
};

// pong#347773c5 msg_id:long ping_id:long = Pong;
class TL_pong : public Pong {
public:
  enum {
    CLASS_ID = 0x347773c5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pong#0x347773c5";
  }

  int64_t msg_id() const { return msg_id_; } 
  void set_msg_id(int64_t v) { msg_id_ = v; } 

  int64_t ping_id() const { return ping_id_; } 
  void set_ping_id(int64_t v) { ping_id_ = v; } 

private:
  int64_t msg_id_;
  int64_t ping_id_;
};

// destroy_session_ok#e22045fc session_id:long = DestroySessionRes;
class TL_destroy_session_ok : public DestroySessionRes {
public:
  enum {
    CLASS_ID = 0xe22045fc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "destroy_session_ok#0xe22045fc";
  }

  int64_t session_id() const { return session_id_; } 
  void set_session_id(int64_t v) { session_id_ = v; } 

private:
  int64_t session_id_;
};

// destroy_session_none#62d350c9 session_id:long = DestroySessionRes;
class TL_destroy_session_none : public DestroySessionRes {
public:
  enum {
    CLASS_ID = 0x62d350c9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "destroy_session_none#0x62d350c9";
  }

  int64_t session_id() const { return session_id_; } 
  void set_session_id(int64_t v) { session_id_ = v; } 

private:
  int64_t session_id_;
};

// new_session_created#9ec20908 first_msg_id:long unique_id:long server_salt:long = NewSession;
class TL_new_session_created : public NewSession {
public:
  enum {
    CLASS_ID = 0x9ec20908
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "new_session_created#0x9ec20908";
  }

  int64_t first_msg_id() const { return first_msg_id_; } 
  void set_first_msg_id(int64_t v) { first_msg_id_ = v; } 

  int64_t unique_id() const { return unique_id_; } 
  void set_unique_id(int64_t v) { unique_id_ = v; } 

  int64_t server_salt() const { return server_salt_; } 
  void set_server_salt(int64_t v) { server_salt_ = v; } 

private:
  int64_t first_msg_id_;
  int64_t unique_id_;
  int64_t server_salt_;
};

// http_wait#9299359f max_delay:int wait_after:int max_wait:int = HttpWait;
class TL_http_wait : public HttpWait {
public:
  enum {
    CLASS_ID = 0x9299359f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "http_wait#0x9299359f";
  }

  int32_t max_delay() const { return max_delay_; } 
  void set_max_delay(int32_t v) { max_delay_ = v; } 

  int32_t wait_after() const { return wait_after_; } 
  void set_wait_after(int32_t v) { wait_after_ = v; } 

  int32_t max_wait() const { return max_wait_; } 
  void set_max_wait(int32_t v) { max_wait_ = v; } 

private:
  int32_t max_delay_;
  int32_t wait_after_;
  int32_t max_wait_;
};

// boolFalse#bc799737 = Bool;
class TL_boolFalse : public Bool {
public:
  enum {
    CLASS_ID = 0xbc799737
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "boolFalse#0xbc799737";
  }

private:
};

// boolTrue#997275b5 = Bool;
class TL_boolTrue : public Bool {
public:
  enum {
    CLASS_ID = 0x997275b5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "boolTrue#0x997275b5";
  }

private:
};

// true#3fedd339 = True;
class TL_true : public True {
public:
  enum {
    CLASS_ID = 0x3fedd339
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "true#0x3fedd339";
  }

private:
};

// error#c4b9f9bb code:int text:string = Error;
class TL_error : public Error {
public:
  enum {
    CLASS_ID = 0xc4b9f9bb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "error#0xc4b9f9bb";
  }

  int32_t code() const { return code_; } 
  void set_code(int32_t v) { code_ = v; } 

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  int32_t code_;
  std::string text_;
};

// null#56730bcc = Null;
class TL_null : public Null {
public:
  enum {
    CLASS_ID = 0x56730bcc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "null#0x56730bcc";
  }

private:
};

// inputPeerEmpty#7f3b18ea = InputPeer;
class TL_inputPeerEmpty : public InputPeer {
public:
  enum {
    CLASS_ID = 0x7f3b18ea
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPeerEmpty#0x7f3b18ea";
  }

private:
};

// inputPeerSelf#7da07ec9 = InputPeer;
class TL_inputPeerSelf : public InputPeer {
public:
  enum {
    CLASS_ID = 0x7da07ec9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPeerSelf#0x7da07ec9";
  }

private:
};

// inputPeerChat#179be863 chat_id:int = InputPeer;
class TL_inputPeerChat : public InputPeer {
public:
  enum {
    CLASS_ID = 0x179be863
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPeerChat#0x179be863";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
};

// inputPeerUser#7b8e7de6 user_id:int access_hash:long = InputPeer;
class TL_inputPeerUser : public InputPeer {
public:
  enum {
    CLASS_ID = 0x7b8e7de6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPeerUser#0x7b8e7de6";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int32_t user_id_;
  int64_t access_hash_;
};

// inputPeerChannel#20adaef8 channel_id:int access_hash:long = InputPeer;
class TL_inputPeerChannel : public InputPeer {
public:
  enum {
    CLASS_ID = 0x20adaef8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPeerChannel#0x20adaef8";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int32_t channel_id_;
  int64_t access_hash_;
};

// inputUserEmpty#b98886cf = InputUser;
class TL_inputUserEmpty : public InputUser {
public:
  enum {
    CLASS_ID = 0xb98886cf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputUserEmpty#0xb98886cf";
  }

private:
};

// inputUserSelf#f7c1b13f = InputUser;
class TL_inputUserSelf : public InputUser {
public:
  enum {
    CLASS_ID = 0xf7c1b13f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputUserSelf#0xf7c1b13f";
  }

private:
};

// inputUser#d8292816 user_id:int access_hash:long = InputUser;
class TL_inputUser : public InputUser {
public:
  enum {
    CLASS_ID = 0xd8292816
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputUser#0xd8292816";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int32_t user_id_;
  int64_t access_hash_;
};

// inputPhoneContact#f392b7f4 client_id:long phone:string first_name:string last_name:string = InputContact;
class TL_inputPhoneContact : public InputContact {
public:
  enum {
    CLASS_ID = 0xf392b7f4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPhoneContact#0xf392b7f4";
  }

  int64_t client_id() const { return client_id_; } 
  void set_client_id(int64_t v) { client_id_ = v; } 

  std::string* mutable_phone() { return &phone_; } 
  const std::string& phone() const { return phone_; } 
  void set_phone(const std::string& v) { phone_ = v; } 
  void set_phone(const char* v, size_t n) { phone_.assign(v, n); } 
  void set_phone(const char* v) { phone_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

private:
  int64_t client_id_;
  std::string phone_;
  std::string first_name_;
  std::string last_name_;
};

// inputFile#f52ff27f id:long parts:int name:string md5_checksum:string = InputFile;
class TL_inputFile : public InputFile {
public:
  enum {
    CLASS_ID = 0xf52ff27f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputFile#0xf52ff27f";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int32_t parts() const { return parts_; } 
  void set_parts(int32_t v) { parts_ = v; } 

  std::string* mutable_name() { return &name_; } 
  const std::string& name() const { return name_; } 
  void set_name(const std::string& v) { name_ = v; } 
  void set_name(const char* v, size_t n) { name_.assign(v, n); } 
  void set_name(const char* v) { name_ = v; } 

  std::string* mutable_md5_checksum() { return &md5_checksum_; } 
  const std::string& md5_checksum() const { return md5_checksum_; } 
  void set_md5_checksum(const std::string& v) { md5_checksum_ = v; } 
  void set_md5_checksum(const char* v, size_t n) { md5_checksum_.assign(v, n); } 
  void set_md5_checksum(const char* v) { md5_checksum_ = v; } 

private:
  int64_t id_;
  int32_t parts_;
  std::string name_;
  std::string md5_checksum_;
};

// inputFileBig#fa4f0bb5 id:long parts:int name:string = InputFile;
class TL_inputFileBig : public InputFile {
public:
  enum {
    CLASS_ID = 0xfa4f0bb5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputFileBig#0xfa4f0bb5";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int32_t parts() const { return parts_; } 
  void set_parts(int32_t v) { parts_ = v; } 

  std::string* mutable_name() { return &name_; } 
  const std::string& name() const { return name_; } 
  void set_name(const std::string& v) { name_ = v; } 
  void set_name(const char* v, size_t n) { name_.assign(v, n); } 
  void set_name(const char* v) { name_ = v; } 

private:
  int64_t id_;
  int32_t parts_;
  std::string name_;
};

// inputMediaEmpty#9664f57f = InputMedia;
class TL_inputMediaEmpty : public InputMedia {
public:
  enum {
    CLASS_ID = 0x9664f57f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaEmpty#0x9664f57f";
  }

private:
};

// inputMediaUploadedPhoto#630c9af1 flags:# file:InputFile caption:string stickers:flags.0?Vector<InputDocument> = InputMedia;
class TL_inputMediaUploadedPhoto : public InputMedia {
public:
  enum {
    CLASS_ID = 0x630c9af1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaUploadedPhoto#0x630c9af1";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<InputFile> file_;
  std::string caption_;
  TLObjectVector<InputDocument> stickers_;
};

// inputMediaPhoto#e9bfb4f3 id:InputPhoto caption:string = InputMedia;
class TL_inputMediaPhoto : public InputMedia {
public:
  enum {
    CLASS_ID = 0xe9bfb4f3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaPhoto#0xe9bfb4f3";
  }

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  std::unique_ptr<InputPhoto> id_;
  std::string caption_;
};

// inputMediaGeoPoint#f9c44144 geo_point:InputGeoPoint = InputMedia;
class TL_inputMediaGeoPoint : public InputMedia {
public:
  enum {
    CLASS_ID = 0xf9c44144
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaGeoPoint#0xf9c44144";
  }

private:
  std::unique_ptr<InputGeoPoint> geo_point_;
};

// inputMediaContact#a6e45987 phone_number:string first_name:string last_name:string = InputMedia;
class TL_inputMediaContact : public InputMedia {
public:
  enum {
    CLASS_ID = 0xa6e45987
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaContact#0xa6e45987";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

private:
  std::string phone_number_;
  std::string first_name_;
  std::string last_name_;
};

// inputMediaUploadedDocument#d070f1e9 flags:# file:InputFile mime_type:string attributes:Vector<DocumentAttribute> caption:string stickers:flags.0?Vector<InputDocument> = InputMedia;
class TL_inputMediaUploadedDocument : public InputMedia {
public:
  enum {
    CLASS_ID = 0xd070f1e9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaUploadedDocument#0xd070f1e9";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_mime_type() { return &mime_type_; } 
  const std::string& mime_type() const { return mime_type_; } 
  void set_mime_type(const std::string& v) { mime_type_ = v; } 
  void set_mime_type(const char* v, size_t n) { mime_type_.assign(v, n); } 
  void set_mime_type(const char* v) { mime_type_ = v; } 

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<InputFile> file_;
  std::string mime_type_;
  TLObjectVector<DocumentAttribute> attributes_;
  std::string caption_;
  TLObjectVector<InputDocument> stickers_;
};

// inputMediaUploadedThumbDocument#50d88cae flags:# file:InputFile thumb:InputFile mime_type:string attributes:Vector<DocumentAttribute> caption:string stickers:flags.0?Vector<InputDocument> = InputMedia;
class TL_inputMediaUploadedThumbDocument : public InputMedia {
public:
  enum {
    CLASS_ID = 0x50d88cae
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaUploadedThumbDocument#0x50d88cae";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_mime_type() { return &mime_type_; } 
  const std::string& mime_type() const { return mime_type_; } 
  void set_mime_type(const std::string& v) { mime_type_ = v; } 
  void set_mime_type(const char* v, size_t n) { mime_type_.assign(v, n); } 
  void set_mime_type(const char* v) { mime_type_ = v; } 

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<InputFile> file_;
  std::unique_ptr<InputFile> thumb_;
  std::string mime_type_;
  TLObjectVector<DocumentAttribute> attributes_;
  std::string caption_;
  TLObjectVector<InputDocument> stickers_;
};

// inputMediaDocument#1a77f29c id:InputDocument caption:string = InputMedia;
class TL_inputMediaDocument : public InputMedia {
public:
  enum {
    CLASS_ID = 0x1a77f29c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaDocument#0x1a77f29c";
  }

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  std::unique_ptr<InputDocument> id_;
  std::string caption_;
};

// inputMediaVenue#2827a81a geo_point:InputGeoPoint title:string address:string provider:string venue_id:string = InputMedia;
class TL_inputMediaVenue : public InputMedia {
public:
  enum {
    CLASS_ID = 0x2827a81a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaVenue#0x2827a81a";
  }

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_address() { return &address_; } 
  const std::string& address() const { return address_; } 
  void set_address(const std::string& v) { address_ = v; } 
  void set_address(const char* v, size_t n) { address_.assign(v, n); } 
  void set_address(const char* v) { address_ = v; } 

  std::string* mutable_provider() { return &provider_; } 
  const std::string& provider() const { return provider_; } 
  void set_provider(const std::string& v) { provider_ = v; } 
  void set_provider(const char* v, size_t n) { provider_.assign(v, n); } 
  void set_provider(const char* v) { provider_ = v; } 

  std::string* mutable_venue_id() { return &venue_id_; } 
  const std::string& venue_id() const { return venue_id_; } 
  void set_venue_id(const std::string& v) { venue_id_ = v; } 
  void set_venue_id(const char* v, size_t n) { venue_id_.assign(v, n); } 
  void set_venue_id(const char* v) { venue_id_ = v; } 

private:
  std::unique_ptr<InputGeoPoint> geo_point_;
  std::string title_;
  std::string address_;
  std::string provider_;
  std::string venue_id_;
};

// inputMediaGifExternal#4843b0fd url:string q:string = InputMedia;
class TL_inputMediaGifExternal : public InputMedia {
public:
  enum {
    CLASS_ID = 0x4843b0fd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaGifExternal#0x4843b0fd";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_q() { return &q_; } 
  const std::string& q() const { return q_; } 
  void set_q(const std::string& v) { q_ = v; } 
  void set_q(const char* v, size_t n) { q_.assign(v, n); } 
  void set_q(const char* v) { q_ = v; } 

private:
  std::string url_;
  std::string q_;
};

// inputMediaPhotoExternal#b55f4f18 url:string caption:string = InputMedia;
class TL_inputMediaPhotoExternal : public InputMedia {
public:
  enum {
    CLASS_ID = 0xb55f4f18
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaPhotoExternal#0xb55f4f18";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  std::string url_;
  std::string caption_;
};

// inputMediaDocumentExternal#e5e9607c url:string caption:string = InputMedia;
class TL_inputMediaDocumentExternal : public InputMedia {
public:
  enum {
    CLASS_ID = 0xe5e9607c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaDocumentExternal#0xe5e9607c";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  std::string url_;
  std::string caption_;
};

// inputMediaGame#d33f43f3 id:InputGame = InputMedia;
class TL_inputMediaGame : public InputMedia {
public:
  enum {
    CLASS_ID = 0xd33f43f3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaGame#0xd33f43f3";
  }

private:
  std::unique_ptr<InputGame> id_;
};

// inputMediaInvoice#92153685 flags:# title:string description:string photo:flags.0?InputWebDocument invoice:Invoice payload:bytes provider:string start_param:string = InputMedia;
class TL_inputMediaInvoice : public InputMedia {
public:
  enum {
    CLASS_ID = 0x92153685
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMediaInvoice#0x92153685";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

  std::string* mutable_payload() { return &payload_; } 
  const std::string& payload() const { return payload_; } 
  void set_payload(const std::string& v) { payload_ = v; } 
  void set_payload(const char* v, size_t n) { payload_.assign(v, n); } 
  void set_payload(const char* v) { payload_ = v; } 

  std::string* mutable_provider() { return &provider_; } 
  const std::string& provider() const { return provider_; } 
  void set_provider(const std::string& v) { provider_ = v; } 
  void set_provider(const char* v, size_t n) { provider_.assign(v, n); } 
  void set_provider(const char* v) { provider_ = v; } 

  std::string* mutable_start_param() { return &start_param_; } 
  const std::string& start_param() const { return start_param_; } 
  void set_start_param(const std::string& v) { start_param_ = v; } 
  void set_start_param(const char* v, size_t n) { start_param_.assign(v, n); } 
  void set_start_param(const char* v) { start_param_ = v; } 

private:
  int32_t flags_;
  std::string title_;
  std::string description_;
  std::unique_ptr<InputWebDocument> photo_;
  std::unique_ptr<Invoice> invoice_;
  std::string payload_;
  std::string provider_;
  std::string start_param_;
};

// inputChatPhotoEmpty#1ca48f57 = InputChatPhoto;
class TL_inputChatPhotoEmpty : public InputChatPhoto {
public:
  enum {
    CLASS_ID = 0x1ca48f57
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputChatPhotoEmpty#0x1ca48f57";
  }

private:
};

// inputChatUploadedPhoto#927c55b4 file:InputFile = InputChatPhoto;
class TL_inputChatUploadedPhoto : public InputChatPhoto {
public:
  enum {
    CLASS_ID = 0x927c55b4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputChatUploadedPhoto#0x927c55b4";
  }

private:
  std::unique_ptr<InputFile> file_;
};

// inputChatPhoto#8953ad37 id:InputPhoto = InputChatPhoto;
class TL_inputChatPhoto : public InputChatPhoto {
public:
  enum {
    CLASS_ID = 0x8953ad37
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputChatPhoto#0x8953ad37";
  }

private:
  std::unique_ptr<InputPhoto> id_;
};

// inputGeoPointEmpty#e4c123d6 = InputGeoPoint;
class TL_inputGeoPointEmpty : public InputGeoPoint {
public:
  enum {
    CLASS_ID = 0xe4c123d6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputGeoPointEmpty#0xe4c123d6";
  }

private:
};

// inputGeoPoint#f3b7acc9 lat:double long:double = InputGeoPoint;
class TL_inputGeoPoint : public InputGeoPoint {
public:
  enum {
    CLASS_ID = 0xf3b7acc9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputGeoPoint#0xf3b7acc9";
  }

private:
  double lat_;
  double long_;
};

// inputPhotoEmpty#1cd7bf0d = InputPhoto;
class TL_inputPhotoEmpty : public InputPhoto {
public:
  enum {
    CLASS_ID = 0x1cd7bf0d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPhotoEmpty#0x1cd7bf0d";
  }

private:
};

// inputPhoto#fb95c6c4 id:long access_hash:long = InputPhoto;
class TL_inputPhoto : public InputPhoto {
public:
  enum {
    CLASS_ID = 0xfb95c6c4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPhoto#0xfb95c6c4";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
};

// inputFileLocation#14637196 volume_id:long local_id:int secret:long = InputFileLocation;
class TL_inputFileLocation : public InputFileLocation {
public:
  enum {
    CLASS_ID = 0x14637196
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputFileLocation#0x14637196";
  }

  int64_t volume_id() const { return volume_id_; } 
  void set_volume_id(int64_t v) { volume_id_ = v; } 

  int32_t local_id() const { return local_id_; } 
  void set_local_id(int32_t v) { local_id_ = v; } 

  int64_t secret() const { return secret_; } 
  void set_secret(int64_t v) { secret_ = v; } 

private:
  int64_t volume_id_;
  int32_t local_id_;
  int64_t secret_;
};

// inputEncryptedFileLocation#f5235d55 id:long access_hash:long = InputFileLocation;
class TL_inputEncryptedFileLocation : public InputFileLocation {
public:
  enum {
    CLASS_ID = 0xf5235d55
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputEncryptedFileLocation#0xf5235d55";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
};

// inputDocumentFileLocation#430f0724 id:long access_hash:long version:int = InputFileLocation;
class TL_inputDocumentFileLocation : public InputFileLocation {
public:
  enum {
    CLASS_ID = 0x430f0724
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputDocumentFileLocation#0x430f0724";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
  int32_t version_;
};

// inputAppEvent#770656a8 time:double type:string peer:long data:string = InputAppEvent;
class TL_inputAppEvent : public InputAppEvent {
public:
  enum {
    CLASS_ID = 0x770656a8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputAppEvent#0x770656a8";
  }

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  int64_t peer() const { return peer_; } 
  void set_peer(int64_t v) { peer_ = v; } 

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

private:
  double time_;
  std::string type_;
  int64_t peer_;
  std::string data_;
};

// peerUser#9db1bc6d user_id:int = Peer;
class TL_peerUser : public Peer {
public:
  enum {
    CLASS_ID = 0x9db1bc6d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "peerUser#0x9db1bc6d";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
};

// peerChat#bad0e5bb chat_id:int = Peer;
class TL_peerChat : public Peer {
public:
  enum {
    CLASS_ID = 0xbad0e5bb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "peerChat#0xbad0e5bb";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
};

// peerChannel#bddde532 channel_id:int = Peer;
class TL_peerChannel : public Peer {
public:
  enum {
    CLASS_ID = 0xbddde532
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "peerChannel#0xbddde532";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

private:
  int32_t channel_id_;
};

// storage.fileUnknown#aa963b05 = storage.FileType;
class TL_storage_fileUnknown : public storage_FileType {
public:
  enum {
    CLASS_ID = 0xaa963b05
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_fileUnknown#0xaa963b05";
  }

private:
};

// storage.filePartial#40bc6f52 = storage.FileType;
class TL_storage_filePartial : public storage_FileType {
public:
  enum {
    CLASS_ID = 0x40bc6f52
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_filePartial#0x40bc6f52";
  }

private:
};

// storage.fileJpeg#7efe0e = storage.FileType;
class TL_storage_fileJpeg : public storage_FileType {
public:
  enum {
    CLASS_ID = 0x7efe0e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_fileJpeg#0x7efe0e";
  }

private:
};

// storage.fileGif#cae1aadf = storage.FileType;
class TL_storage_fileGif : public storage_FileType {
public:
  enum {
    CLASS_ID = 0xcae1aadf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_fileGif#0xcae1aadf";
  }

private:
};

// storage.filePng#a4f63c0 = storage.FileType;
class TL_storage_filePng : public storage_FileType {
public:
  enum {
    CLASS_ID = 0xa4f63c0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_filePng#0xa4f63c0";
  }

private:
};

// storage.filePdf#ae1e508d = storage.FileType;
class TL_storage_filePdf : public storage_FileType {
public:
  enum {
    CLASS_ID = 0xae1e508d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_filePdf#0xae1e508d";
  }

private:
};

// storage.fileMp3#528a0677 = storage.FileType;
class TL_storage_fileMp3 : public storage_FileType {
public:
  enum {
    CLASS_ID = 0x528a0677
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_fileMp3#0x528a0677";
  }

private:
};

// storage.fileMov#4b09ebbc = storage.FileType;
class TL_storage_fileMov : public storage_FileType {
public:
  enum {
    CLASS_ID = 0x4b09ebbc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_fileMov#0x4b09ebbc";
  }

private:
};

// storage.fileMp4#b3cea0e4 = storage.FileType;
class TL_storage_fileMp4 : public storage_FileType {
public:
  enum {
    CLASS_ID = 0xb3cea0e4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_fileMp4#0xb3cea0e4";
  }

private:
};

// storage.fileWebp#1081464c = storage.FileType;
class TL_storage_fileWebp : public storage_FileType {
public:
  enum {
    CLASS_ID = 0x1081464c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "storage_fileWebp#0x1081464c";
  }

private:
};

// fileLocationUnavailable#7c596b46 volume_id:long local_id:int secret:long = FileLocation;
class TL_fileLocationUnavailable : public FileLocation {
public:
  enum {
    CLASS_ID = 0x7c596b46
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "fileLocationUnavailable#0x7c596b46";
  }

  int64_t volume_id() const { return volume_id_; } 
  void set_volume_id(int64_t v) { volume_id_ = v; } 

  int32_t local_id() const { return local_id_; } 
  void set_local_id(int32_t v) { local_id_ = v; } 

  int64_t secret() const { return secret_; } 
  void set_secret(int64_t v) { secret_ = v; } 

private:
  int64_t volume_id_;
  int32_t local_id_;
  int64_t secret_;
};

// fileLocation#53d69076 dc_id:int volume_id:long local_id:int secret:long = FileLocation;
class TL_fileLocation : public FileLocation {
public:
  enum {
    CLASS_ID = 0x53d69076
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "fileLocation#0x53d69076";
  }

  int32_t dc_id() const { return dc_id_; } 
  void set_dc_id(int32_t v) { dc_id_ = v; } 

  int64_t volume_id() const { return volume_id_; } 
  void set_volume_id(int64_t v) { volume_id_ = v; } 

  int32_t local_id() const { return local_id_; } 
  void set_local_id(int32_t v) { local_id_ = v; } 

  int64_t secret() const { return secret_; } 
  void set_secret(int64_t v) { secret_ = v; } 

private:
  int32_t dc_id_;
  int64_t volume_id_;
  int32_t local_id_;
  int64_t secret_;
};

// userEmpty#200250ba id:int = User;
class TL_userEmpty : public User {
public:
  enum {
    CLASS_ID = 0x200250ba
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userEmpty#0x200250ba";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  int32_t id_;
};

// user#2e13f4c3 flags:# self:flags.10?true contact:flags.11?true mutual_contact:flags.12?true deleted:flags.13?true bot:flags.14?true bot_chat_history:flags.15?true bot_nochats:flags.16?true verified:flags.17?true restricted:flags.18?true min:flags.20?true bot_inline_geo:flags.21?true id:int access_hash:flags.0?long first_name:flags.1?string last_name:flags.2?string username:flags.3?string phone:flags.4?string photo:flags.5?UserProfilePhoto status:flags.6?UserStatus bot_info_version:flags.14?int restriction_reason:flags.18?string bot_inline_placeholder:flags.19?string lang_code:flags.22?string = User;
class TL_user : public User {
public:
  enum {
    CLASS_ID = 0x2e13f4c3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "user#0x2e13f4c3";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

  std::string* mutable_username() { return &username_; } 
  const std::string& username() const { return username_; } 
  void set_username(const std::string& v) { username_ = v; } 
  void set_username(const char* v, size_t n) { username_.assign(v, n); } 
  void set_username(const char* v) { username_ = v; } 

  std::string* mutable_phone() { return &phone_; } 
  const std::string& phone() const { return phone_; } 
  void set_phone(const std::string& v) { phone_ = v; } 
  void set_phone(const char* v, size_t n) { phone_.assign(v, n); } 
  void set_phone(const char* v) { phone_ = v; } 

  int32_t bot_info_version() const { return bot_info_version_; } 
  void set_bot_info_version(int32_t v) { bot_info_version_ = v; } 

  std::string* mutable_restriction_reason() { return &restriction_reason_; } 
  const std::string& restriction_reason() const { return restriction_reason_; } 
  void set_restriction_reason(const std::string& v) { restriction_reason_ = v; } 
  void set_restriction_reason(const char* v, size_t n) { restriction_reason_.assign(v, n); } 
  void set_restriction_reason(const char* v) { restriction_reason_ = v; } 

  std::string* mutable_bot_inline_placeholder() { return &bot_inline_placeholder_; } 
  const std::string& bot_inline_placeholder() const { return bot_inline_placeholder_; } 
  void set_bot_inline_placeholder(const std::string& v) { bot_inline_placeholder_ = v; } 
  void set_bot_inline_placeholder(const char* v, size_t n) { bot_inline_placeholder_.assign(v, n); } 
  void set_bot_inline_placeholder(const char* v) { bot_inline_placeholder_ = v; } 

  std::string* mutable_lang_code() { return &lang_code_; } 
  const std::string& lang_code() const { return lang_code_; } 
  void set_lang_code(const std::string& v) { lang_code_ = v; } 
  void set_lang_code(const char* v, size_t n) { lang_code_.assign(v, n); } 
  void set_lang_code(const char* v) { lang_code_ = v; } 

private:
  int32_t flags_;
  bool self_ {false};
  bool contact_ {false};
  bool mutual_contact_ {false};
  bool deleted_ {false};
  bool bot_ {false};
  bool bot_chat_history_ {false};
  bool bot_nochats_ {false};
  bool verified_ {false};
  bool restricted_ {false};
  bool min_ {false};
  bool bot_inline_geo_ {false};
  int32_t id_;
  int64_t access_hash_;
  std::string first_name_;
  std::string last_name_;
  std::string username_;
  std::string phone_;
  std::unique_ptr<UserProfilePhoto> photo_;
  std::unique_ptr<UserStatus> status_;
  int32_t bot_info_version_;
  std::string restriction_reason_;
  std::string bot_inline_placeholder_;
  std::string lang_code_;
};

// userProfilePhotoEmpty#4f11bae1 = UserProfilePhoto;
class TL_userProfilePhotoEmpty : public UserProfilePhoto {
public:
  enum {
    CLASS_ID = 0x4f11bae1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userProfilePhotoEmpty#0x4f11bae1";
  }

private:
};

// userProfilePhoto#d559d8c8 photo_id:long photo_small:FileLocation photo_big:FileLocation = UserProfilePhoto;
class TL_userProfilePhoto : public UserProfilePhoto {
public:
  enum {
    CLASS_ID = 0xd559d8c8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userProfilePhoto#0xd559d8c8";
  }

  int64_t photo_id() const { return photo_id_; } 
  void set_photo_id(int64_t v) { photo_id_ = v; } 

private:
  int64_t photo_id_;
  std::unique_ptr<FileLocation> photo_small_;
  std::unique_ptr<FileLocation> photo_big_;
};

// userStatusEmpty#9d05049 = UserStatus;
class TL_userStatusEmpty : public UserStatus {
public:
  enum {
    CLASS_ID = 0x9d05049
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userStatusEmpty#0x9d05049";
  }

private:
};

// userStatusOnline#edb93949 expires:int = UserStatus;
class TL_userStatusOnline : public UserStatus {
public:
  enum {
    CLASS_ID = 0xedb93949
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userStatusOnline#0xedb93949";
  }

  int32_t expires() const { return expires_; } 
  void set_expires(int32_t v) { expires_ = v; } 

private:
  int32_t expires_;
};

// userStatusOffline#8c703f was_online:int = UserStatus;
class TL_userStatusOffline : public UserStatus {
public:
  enum {
    CLASS_ID = 0x8c703f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userStatusOffline#0x8c703f";
  }

  int32_t was_online() const { return was_online_; } 
  void set_was_online(int32_t v) { was_online_ = v; } 

private:
  int32_t was_online_;
};

// userStatusRecently#e26f42f1 = UserStatus;
class TL_userStatusRecently : public UserStatus {
public:
  enum {
    CLASS_ID = 0xe26f42f1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userStatusRecently#0xe26f42f1";
  }

private:
};

// userStatusLastWeek#7bf09fc = UserStatus;
class TL_userStatusLastWeek : public UserStatus {
public:
  enum {
    CLASS_ID = 0x7bf09fc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userStatusLastWeek#0x7bf09fc";
  }

private:
};

// userStatusLastMonth#77ebc742 = UserStatus;
class TL_userStatusLastMonth : public UserStatus {
public:
  enum {
    CLASS_ID = 0x77ebc742
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userStatusLastMonth#0x77ebc742";
  }

private:
};

// chatEmpty#9ba2d800 id:int = Chat;
class TL_chatEmpty : public Chat {
public:
  enum {
    CLASS_ID = 0x9ba2d800
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatEmpty#0x9ba2d800";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  int32_t id_;
};

// chat#d91cdd54 flags:# creator:flags.0?true kicked:flags.1?true left:flags.2?true admins_enabled:flags.3?true admin:flags.4?true deactivated:flags.5?true id:int title:string photo:ChatPhoto participants_count:int date:int version:int migrated_to:flags.6?InputChannel = Chat;
class TL_chat : public Chat {
public:
  enum {
    CLASS_ID = 0xd91cdd54
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chat#0xd91cdd54";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  int32_t participants_count() const { return participants_count_; } 
  void set_participants_count(int32_t v) { participants_count_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

private:
  int32_t flags_;
  bool creator_ {false};
  bool kicked_ {false};
  bool left_ {false};
  bool admins_enabled_ {false};
  bool admin_ {false};
  bool deactivated_ {false};
  int32_t id_;
  std::string title_;
  std::unique_ptr<ChatPhoto> photo_;
  int32_t participants_count_;
  int32_t date_;
  int32_t version_;
  std::unique_ptr<InputChannel> migrated_to_;
};

// chatForbidden#7328bdb id:int title:string = Chat;
class TL_chatForbidden : public Chat {
public:
  enum {
    CLASS_ID = 0x7328bdb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatForbidden#0x7328bdb";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  int32_t id_;
  std::string title_;
};

// channel#a14dca52 flags:# creator:flags.0?true kicked:flags.1?true left:flags.2?true editor:flags.3?true moderator:flags.4?true broadcast:flags.5?true verified:flags.7?true megagroup:flags.8?true restricted:flags.9?true democracy:flags.10?true signatures:flags.11?true min:flags.12?true id:int access_hash:flags.13?long title:string username:flags.6?string photo:ChatPhoto date:int version:int restriction_reason:flags.9?string = Chat;
class TL_channel : public Chat {
public:
  enum {
    CLASS_ID = 0xa14dca52
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channel#0xa14dca52";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_username() { return &username_; } 
  const std::string& username() const { return username_; } 
  void set_username(const std::string& v) { username_ = v; } 
  void set_username(const char* v, size_t n) { username_.assign(v, n); } 
  void set_username(const char* v) { username_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

  std::string* mutable_restriction_reason() { return &restriction_reason_; } 
  const std::string& restriction_reason() const { return restriction_reason_; } 
  void set_restriction_reason(const std::string& v) { restriction_reason_ = v; } 
  void set_restriction_reason(const char* v, size_t n) { restriction_reason_.assign(v, n); } 
  void set_restriction_reason(const char* v) { restriction_reason_ = v; } 

private:
  int32_t flags_;
  bool creator_ {false};
  bool kicked_ {false};
  bool left_ {false};
  bool editor_ {false};
  bool moderator_ {false};
  bool broadcast_ {false};
  bool verified_ {false};
  bool megagroup_ {false};
  bool restricted_ {false};
  bool democracy_ {false};
  bool signatures_ {false};
  bool min_ {false};
  int32_t id_;
  int64_t access_hash_;
  std::string title_;
  std::string username_;
  std::unique_ptr<ChatPhoto> photo_;
  int32_t date_;
  int32_t version_;
  std::string restriction_reason_;
};

// channelForbidden#8537784f flags:# broadcast:flags.5?true megagroup:flags.8?true id:int access_hash:long title:string = Chat;
class TL_channelForbidden : public Chat {
public:
  enum {
    CLASS_ID = 0x8537784f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelForbidden#0x8537784f";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  int32_t flags_;
  bool broadcast_ {false};
  bool megagroup_ {false};
  int32_t id_;
  int64_t access_hash_;
  std::string title_;
};

// chatFull#2e02a614 id:int participants:ChatParticipants chat_photo:Photo notify_settings:PeerNotifySettings exported_invite:ExportedChatInvite bot_info:Vector<BotInfo> = ChatFull;
class TL_chatFull : public ChatFull {
public:
  enum {
    CLASS_ID = 0x2e02a614
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatFull#0x2e02a614";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  int32_t id_;
  std::unique_ptr<ChatParticipants> participants_;
  std::unique_ptr<Photo> chat_photo_;
  std::unique_ptr<PeerNotifySettings> notify_settings_;
  std::unique_ptr<ExportedChatInvite> exported_invite_;
  TLObjectVector<BotInfo> bot_info_;
};

// channelFull#c3d5512f flags:# can_view_participants:flags.3?true can_set_username:flags.6?true id:int about:string participants_count:flags.0?int admins_count:flags.1?int kicked_count:flags.2?int read_inbox_max_id:int read_outbox_max_id:int unread_count:int chat_photo:Photo notify_settings:PeerNotifySettings exported_invite:ExportedChatInvite bot_info:Vector<BotInfo> migrated_from_chat_id:flags.4?int migrated_from_max_id:flags.4?int pinned_msg_id:flags.5?int = ChatFull;
class TL_channelFull : public ChatFull {
public:
  enum {
    CLASS_ID = 0xc3d5512f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelFull#0xc3d5512f";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_about() { return &about_; } 
  const std::string& about() const { return about_; } 
  void set_about(const std::string& v) { about_ = v; } 
  void set_about(const char* v, size_t n) { about_.assign(v, n); } 
  void set_about(const char* v) { about_ = v; } 

  int32_t participants_count() const { return participants_count_; } 
  void set_participants_count(int32_t v) { participants_count_ = v; } 

  int32_t admins_count() const { return admins_count_; } 
  void set_admins_count(int32_t v) { admins_count_ = v; } 

  int32_t kicked_count() const { return kicked_count_; } 
  void set_kicked_count(int32_t v) { kicked_count_ = v; } 

  int32_t read_inbox_max_id() const { return read_inbox_max_id_; } 
  void set_read_inbox_max_id(int32_t v) { read_inbox_max_id_ = v; } 

  int32_t read_outbox_max_id() const { return read_outbox_max_id_; } 
  void set_read_outbox_max_id(int32_t v) { read_outbox_max_id_ = v; } 

  int32_t unread_count() const { return unread_count_; } 
  void set_unread_count(int32_t v) { unread_count_ = v; } 

  int32_t migrated_from_chat_id() const { return migrated_from_chat_id_; } 
  void set_migrated_from_chat_id(int32_t v) { migrated_from_chat_id_ = v; } 

  int32_t migrated_from_max_id() const { return migrated_from_max_id_; } 
  void set_migrated_from_max_id(int32_t v) { migrated_from_max_id_ = v; } 

  int32_t pinned_msg_id() const { return pinned_msg_id_; } 
  void set_pinned_msg_id(int32_t v) { pinned_msg_id_ = v; } 

private:
  int32_t flags_;
  bool can_view_participants_ {false};
  bool can_set_username_ {false};
  int32_t id_;
  std::string about_;
  int32_t participants_count_;
  int32_t admins_count_;
  int32_t kicked_count_;
  int32_t read_inbox_max_id_;
  int32_t read_outbox_max_id_;
  int32_t unread_count_;
  std::unique_ptr<Photo> chat_photo_;
  std::unique_ptr<PeerNotifySettings> notify_settings_;
  std::unique_ptr<ExportedChatInvite> exported_invite_;
  TLObjectVector<BotInfo> bot_info_;
  int32_t migrated_from_chat_id_;
  int32_t migrated_from_max_id_;
  int32_t pinned_msg_id_;
};

// chatParticipant#c8d7493e user_id:int inviter_id:int date:int = ChatParticipant;
class TL_chatParticipant : public ChatParticipant {
public:
  enum {
    CLASS_ID = 0xc8d7493e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatParticipant#0xc8d7493e";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t inviter_id() const { return inviter_id_; } 
  void set_inviter_id(int32_t v) { inviter_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t inviter_id_;
  int32_t date_;
};

// chatParticipantCreator#da13538a user_id:int = ChatParticipant;
class TL_chatParticipantCreator : public ChatParticipant {
public:
  enum {
    CLASS_ID = 0xda13538a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatParticipantCreator#0xda13538a";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
};

// chatParticipantAdmin#e2d6e436 user_id:int inviter_id:int date:int = ChatParticipant;
class TL_chatParticipantAdmin : public ChatParticipant {
public:
  enum {
    CLASS_ID = 0xe2d6e436
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatParticipantAdmin#0xe2d6e436";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t inviter_id() const { return inviter_id_; } 
  void set_inviter_id(int32_t v) { inviter_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t inviter_id_;
  int32_t date_;
};

// chatParticipantsForbidden#fc900c2b flags:# chat_id:int self_participant:flags.0?ChatParticipant = ChatParticipants;
class TL_chatParticipantsForbidden : public ChatParticipants {
public:
  enum {
    CLASS_ID = 0xfc900c2b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatParticipantsForbidden#0xfc900c2b";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t flags_;
  int32_t chat_id_;
  std::unique_ptr<ChatParticipant> self_participant_;
};

// chatParticipants#3f460fed chat_id:int participants:Vector<ChatParticipant> version:int = ChatParticipants;
class TL_chatParticipants : public ChatParticipants {
public:
  enum {
    CLASS_ID = 0x3f460fed
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatParticipants#0x3f460fed";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

private:
  int32_t chat_id_;
  TLObjectVector<ChatParticipant> participants_;
  int32_t version_;
};

// chatPhotoEmpty#37c1011c = ChatPhoto;
class TL_chatPhotoEmpty : public ChatPhoto {
public:
  enum {
    CLASS_ID = 0x37c1011c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatPhotoEmpty#0x37c1011c";
  }

private:
};

// chatPhoto#6153276a photo_small:FileLocation photo_big:FileLocation = ChatPhoto;
class TL_chatPhoto : public ChatPhoto {
public:
  enum {
    CLASS_ID = 0x6153276a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatPhoto#0x6153276a";
  }

private:
  std::unique_ptr<FileLocation> photo_small_;
  std::unique_ptr<FileLocation> photo_big_;
};

// messageEmpty#83e5de54 id:int = Message;
class TL_messageEmpty : public Message {
public:
  enum {
    CLASS_ID = 0x83e5de54
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEmpty#0x83e5de54";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  int32_t id_;
};

// message#c09be45f flags:# out:flags.1?true mentioned:flags.4?true media_unread:flags.5?true silent:flags.13?true post:flags.14?true id:int from_id:flags.8?int to_id:Peer fwd_from:flags.2?MessageFwdHeader via_bot_id:flags.11?int reply_to_msg_id:flags.3?int date:int message:string media:flags.9?MessageMedia reply_markup:flags.6?ReplyMarkup entities:flags.7?Vector<MessageEntity> views:flags.10?int edit_date:flags.15?int = Message;
class TL_message : public Message {
public:
  enum {
    CLASS_ID = 0xc09be45f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "message#0xc09be45f";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int32_t from_id() const { return from_id_; } 
  void set_from_id(int32_t v) { from_id_ = v; } 

  int32_t via_bot_id() const { return via_bot_id_; } 
  void set_via_bot_id(int32_t v) { via_bot_id_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

  int32_t views() const { return views_; } 
  void set_views(int32_t v) { views_ = v; } 

  int32_t edit_date() const { return edit_date_; } 
  void set_edit_date(int32_t v) { edit_date_ = v; } 

private:
  int32_t flags_;
  bool out_ {false};
  bool mentioned_ {false};
  bool media_unread_ {false};
  bool silent_ {false};
  bool post_ {false};
  int32_t id_;
  int32_t from_id_;
  std::unique_ptr<Peer> to_id_;
  std::unique_ptr<MessageFwdHeader> fwd_from_;
  int32_t via_bot_id_;
  int32_t reply_to_msg_id_;
  int32_t date_;
  std::string message_;
  std::unique_ptr<MessageMedia> media_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
  TLObjectVector<MessageEntity> entities_;
  int32_t views_;
  int32_t edit_date_;
};

// messageService#9e19a1f6 flags:# out:flags.1?true mentioned:flags.4?true media_unread:flags.5?true silent:flags.13?true post:flags.14?true id:int from_id:flags.8?int to_id:Peer reply_to_msg_id:flags.3?int date:int action:MessageAction = Message;
class TL_messageService : public Message {
public:
  enum {
    CLASS_ID = 0x9e19a1f6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageService#0x9e19a1f6";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int32_t from_id() const { return from_id_; } 
  void set_from_id(int32_t v) { from_id_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t flags_;
  bool out_ {false};
  bool mentioned_ {false};
  bool media_unread_ {false};
  bool silent_ {false};
  bool post_ {false};
  int32_t id_;
  int32_t from_id_;
  std::unique_ptr<Peer> to_id_;
  int32_t reply_to_msg_id_;
  int32_t date_;
  std::unique_ptr<MessageAction> action_;
};

// messageMediaEmpty#3ded6320 = MessageMedia;
class TL_messageMediaEmpty : public MessageMedia {
public:
  enum {
    CLASS_ID = 0x3ded6320
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaEmpty#0x3ded6320";
  }

private:
};

// messageMediaPhoto#3d8ce53d photo:Photo caption:string = MessageMedia;
class TL_messageMediaPhoto : public MessageMedia {
public:
  enum {
    CLASS_ID = 0x3d8ce53d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaPhoto#0x3d8ce53d";
  }

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  std::unique_ptr<Photo> photo_;
  std::string caption_;
};

// messageMediaGeo#56e0d474 geo:GeoPoint = MessageMedia;
class TL_messageMediaGeo : public MessageMedia {
public:
  enum {
    CLASS_ID = 0x56e0d474
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaGeo#0x56e0d474";
  }

private:
  std::unique_ptr<GeoPoint> geo_;
};

// messageMediaContact#5e7d2f39 phone_number:string first_name:string last_name:string user_id:int = MessageMedia;
class TL_messageMediaContact : public MessageMedia {
public:
  enum {
    CLASS_ID = 0x5e7d2f39
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaContact#0x5e7d2f39";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  std::string phone_number_;
  std::string first_name_;
  std::string last_name_;
  int32_t user_id_;
};

// messageMediaUnsupported#9f84f49e = MessageMedia;
class TL_messageMediaUnsupported : public MessageMedia {
public:
  enum {
    CLASS_ID = 0x9f84f49e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaUnsupported#0x9f84f49e";
  }

private:
};

// messageMediaDocument#f3e02ea8 document:Document caption:string = MessageMedia;
class TL_messageMediaDocument : public MessageMedia {
public:
  enum {
    CLASS_ID = 0xf3e02ea8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaDocument#0xf3e02ea8";
  }

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  std::unique_ptr<Document> document_;
  std::string caption_;
};

// messageMediaWebPage#a32dd600 webpage:WebPage = MessageMedia;
class TL_messageMediaWebPage : public MessageMedia {
public:
  enum {
    CLASS_ID = 0xa32dd600
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaWebPage#0xa32dd600";
  }

private:
  std::unique_ptr<WebPage> webpage_;
};

// messageMediaVenue#7912b71f geo:GeoPoint title:string address:string provider:string venue_id:string = MessageMedia;
class TL_messageMediaVenue : public MessageMedia {
public:
  enum {
    CLASS_ID = 0x7912b71f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaVenue#0x7912b71f";
  }

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_address() { return &address_; } 
  const std::string& address() const { return address_; } 
  void set_address(const std::string& v) { address_ = v; } 
  void set_address(const char* v, size_t n) { address_.assign(v, n); } 
  void set_address(const char* v) { address_ = v; } 

  std::string* mutable_provider() { return &provider_; } 
  const std::string& provider() const { return provider_; } 
  void set_provider(const std::string& v) { provider_ = v; } 
  void set_provider(const char* v, size_t n) { provider_.assign(v, n); } 
  void set_provider(const char* v) { provider_ = v; } 

  std::string* mutable_venue_id() { return &venue_id_; } 
  const std::string& venue_id() const { return venue_id_; } 
  void set_venue_id(const std::string& v) { venue_id_ = v; } 
  void set_venue_id(const char* v, size_t n) { venue_id_.assign(v, n); } 
  void set_venue_id(const char* v) { venue_id_ = v; } 

private:
  std::unique_ptr<GeoPoint> geo_;
  std::string title_;
  std::string address_;
  std::string provider_;
  std::string venue_id_;
};

// messageMediaGame#fdb19008 game:Game = MessageMedia;
class TL_messageMediaGame : public MessageMedia {
public:
  enum {
    CLASS_ID = 0xfdb19008
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaGame#0xfdb19008";
  }

private:
  std::unique_ptr<Game> game_;
};

// messageMediaInvoice#84551347 flags:# shipping_address_requested:flags.1?true test:flags.3?true title:string description:string photo:flags.0?WebDocument receipt_msg_id:flags.2?int currency:string total_amount:long start_param:string = MessageMedia;
class TL_messageMediaInvoice : public MessageMedia {
public:
  enum {
    CLASS_ID = 0x84551347
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageMediaInvoice#0x84551347";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

  int32_t receipt_msg_id() const { return receipt_msg_id_; } 
  void set_receipt_msg_id(int32_t v) { receipt_msg_id_ = v; } 

  std::string* mutable_currency() { return &currency_; } 
  const std::string& currency() const { return currency_; } 
  void set_currency(const std::string& v) { currency_ = v; } 
  void set_currency(const char* v, size_t n) { currency_.assign(v, n); } 
  void set_currency(const char* v) { currency_ = v; } 

  int64_t total_amount() const { return total_amount_; } 
  void set_total_amount(int64_t v) { total_amount_ = v; } 

  std::string* mutable_start_param() { return &start_param_; } 
  const std::string& start_param() const { return start_param_; } 
  void set_start_param(const std::string& v) { start_param_ = v; } 
  void set_start_param(const char* v, size_t n) { start_param_.assign(v, n); } 
  void set_start_param(const char* v) { start_param_ = v; } 

private:
  int32_t flags_;
  bool shipping_address_requested_ {false};
  bool test_ {false};
  std::string title_;
  std::string description_;
  std::unique_ptr<WebDocument> photo_;
  int32_t receipt_msg_id_;
  std::string currency_;
  int64_t total_amount_;
  std::string start_param_;
};

// messageActionEmpty#b6aef7b0 = MessageAction;
class TL_messageActionEmpty : public MessageAction {
public:
  enum {
    CLASS_ID = 0xb6aef7b0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionEmpty#0xb6aef7b0";
  }

private:
};

// messageActionChatCreate#a6638b9a title:string users:Vector<int> = MessageAction;
class TL_messageActionChatCreate : public MessageAction {
public:
  enum {
    CLASS_ID = 0xa6638b9a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChatCreate#0xa6638b9a";
  }

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  size_t users_size() const { return users_.size(); } 
  const TLInt32Vector& users() const { return users_; } 
  int32_t users(int idx) const { return users_.vector()[idx]; } 
  void add_users(int32_t v) {users_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_users() { return &users_; } 

private:
  std::string title_;
  TLInt32Vector users_;
};

// messageActionChatEditTitle#b5a1ce5a title:string = MessageAction;
class TL_messageActionChatEditTitle : public MessageAction {
public:
  enum {
    CLASS_ID = 0xb5a1ce5a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChatEditTitle#0xb5a1ce5a";
  }

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  std::string title_;
};

// messageActionChatEditPhoto#7fcb13a8 photo:Photo = MessageAction;
class TL_messageActionChatEditPhoto : public MessageAction {
public:
  enum {
    CLASS_ID = 0x7fcb13a8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChatEditPhoto#0x7fcb13a8";
  }

private:
  std::unique_ptr<Photo> photo_;
};

// messageActionChatDeletePhoto#95e3fbef = MessageAction;
class TL_messageActionChatDeletePhoto : public MessageAction {
public:
  enum {
    CLASS_ID = 0x95e3fbef
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChatDeletePhoto#0x95e3fbef";
  }

private:
};

// messageActionChatAddUser#488a7337 users:Vector<int> = MessageAction;
class TL_messageActionChatAddUser : public MessageAction {
public:
  enum {
    CLASS_ID = 0x488a7337
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChatAddUser#0x488a7337";
  }

  size_t users_size() const { return users_.size(); } 
  const TLInt32Vector& users() const { return users_; } 
  int32_t users(int idx) const { return users_.vector()[idx]; } 
  void add_users(int32_t v) {users_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_users() { return &users_; } 

private:
  TLInt32Vector users_;
};

// messageActionChatDeleteUser#b2ae9b0c user_id:int = MessageAction;
class TL_messageActionChatDeleteUser : public MessageAction {
public:
  enum {
    CLASS_ID = 0xb2ae9b0c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChatDeleteUser#0xb2ae9b0c";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
};

// messageActionChatJoinedByLink#f89cf5e8 inviter_id:int = MessageAction;
class TL_messageActionChatJoinedByLink : public MessageAction {
public:
  enum {
    CLASS_ID = 0xf89cf5e8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChatJoinedByLink#0xf89cf5e8";
  }

  int32_t inviter_id() const { return inviter_id_; } 
  void set_inviter_id(int32_t v) { inviter_id_ = v; } 

private:
  int32_t inviter_id_;
};

// messageActionChannelCreate#95d2ac92 title:string = MessageAction;
class TL_messageActionChannelCreate : public MessageAction {
public:
  enum {
    CLASS_ID = 0x95d2ac92
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChannelCreate#0x95d2ac92";
  }

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  std::string title_;
};

// messageActionChatMigrateTo#51bdb021 channel_id:int = MessageAction;
class TL_messageActionChatMigrateTo : public MessageAction {
public:
  enum {
    CLASS_ID = 0x51bdb021
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChatMigrateTo#0x51bdb021";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

private:
  int32_t channel_id_;
};

// messageActionChannelMigrateFrom#b055eaee title:string chat_id:int = MessageAction;
class TL_messageActionChannelMigrateFrom : public MessageAction {
public:
  enum {
    CLASS_ID = 0xb055eaee
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionChannelMigrateFrom#0xb055eaee";
  }

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  std::string title_;
  int32_t chat_id_;
};

// messageActionPinMessage#94bd38ed = MessageAction;
class TL_messageActionPinMessage : public MessageAction {
public:
  enum {
    CLASS_ID = 0x94bd38ed
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionPinMessage#0x94bd38ed";
  }

private:
};

// messageActionHistoryClear#9fbab604 = MessageAction;
class TL_messageActionHistoryClear : public MessageAction {
public:
  enum {
    CLASS_ID = 0x9fbab604
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionHistoryClear#0x9fbab604";
  }

private:
};

// messageActionGameScore#92a72876 game_id:long score:int = MessageAction;
class TL_messageActionGameScore : public MessageAction {
public:
  enum {
    CLASS_ID = 0x92a72876
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionGameScore#0x92a72876";
  }

  int64_t game_id() const { return game_id_; } 
  void set_game_id(int64_t v) { game_id_ = v; } 

  int32_t score() const { return score_; } 
  void set_score(int32_t v) { score_ = v; } 

private:
  int64_t game_id_;
  int32_t score_;
};

// messageActionPaymentSentMe#8f31b327 flags:# currency:string total_amount:long payload:bytes info:flags.0?PaymentRequestedInfo shipping_option_id:flags.1?string charge:PaymentCharge = MessageAction;
class TL_messageActionPaymentSentMe : public MessageAction {
public:
  enum {
    CLASS_ID = 0x8f31b327
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionPaymentSentMe#0x8f31b327";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_currency() { return &currency_; } 
  const std::string& currency() const { return currency_; } 
  void set_currency(const std::string& v) { currency_ = v; } 
  void set_currency(const char* v, size_t n) { currency_.assign(v, n); } 
  void set_currency(const char* v) { currency_ = v; } 

  int64_t total_amount() const { return total_amount_; } 
  void set_total_amount(int64_t v) { total_amount_ = v; } 

  std::string* mutable_payload() { return &payload_; } 
  const std::string& payload() const { return payload_; } 
  void set_payload(const std::string& v) { payload_ = v; } 
  void set_payload(const char* v, size_t n) { payload_.assign(v, n); } 
  void set_payload(const char* v) { payload_ = v; } 

  std::string* mutable_shipping_option_id() { return &shipping_option_id_; } 
  const std::string& shipping_option_id() const { return shipping_option_id_; } 
  void set_shipping_option_id(const std::string& v) { shipping_option_id_ = v; } 
  void set_shipping_option_id(const char* v, size_t n) { shipping_option_id_.assign(v, n); } 
  void set_shipping_option_id(const char* v) { shipping_option_id_ = v; } 

private:
  int32_t flags_;
  std::string currency_;
  int64_t total_amount_;
  std::string payload_;
  std::unique_ptr<PaymentRequestedInfo> info_;
  std::string shipping_option_id_;
  std::unique_ptr<PaymentCharge> charge_;
};

// messageActionPaymentSent#40699cd0 currency:string total_amount:long = MessageAction;
class TL_messageActionPaymentSent : public MessageAction {
public:
  enum {
    CLASS_ID = 0x40699cd0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionPaymentSent#0x40699cd0";
  }

  std::string* mutable_currency() { return &currency_; } 
  const std::string& currency() const { return currency_; } 
  void set_currency(const std::string& v) { currency_ = v; } 
  void set_currency(const char* v, size_t n) { currency_.assign(v, n); } 
  void set_currency(const char* v) { currency_ = v; } 

  int64_t total_amount() const { return total_amount_; } 
  void set_total_amount(int64_t v) { total_amount_ = v; } 

private:
  std::string currency_;
  int64_t total_amount_;
};

// messageActionPhoneCall#80e11a7f flags:# call_id:long reason:flags.0?PhoneCallDiscardReason duration:flags.1?int = MessageAction;
class TL_messageActionPhoneCall : public MessageAction {
public:
  enum {
    CLASS_ID = 0x80e11a7f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageActionPhoneCall#0x80e11a7f";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t call_id() const { return call_id_; } 
  void set_call_id(int64_t v) { call_id_ = v; } 

  int32_t duration() const { return duration_; } 
  void set_duration(int32_t v) { duration_ = v; } 

private:
  int32_t flags_;
  int64_t call_id_;
  std::unique_ptr<PhoneCallDiscardReason> reason_;
  int32_t duration_;
};

// dialog#66ffba14 flags:# pinned:flags.2?true peer:Peer top_message:int read_inbox_max_id:int read_outbox_max_id:int unread_count:int notify_settings:PeerNotifySettings pts:flags.0?int draft:flags.1?DraftMessage = Dialog;
class TL_dialog : public Dialog {
public:
  enum {
    CLASS_ID = 0x66ffba14
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "dialog#0x66ffba14";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t top_message() const { return top_message_; } 
  void set_top_message(int32_t v) { top_message_ = v; } 

  int32_t read_inbox_max_id() const { return read_inbox_max_id_; } 
  void set_read_inbox_max_id(int32_t v) { read_inbox_max_id_ = v; } 

  int32_t read_outbox_max_id() const { return read_outbox_max_id_; } 
  void set_read_outbox_max_id(int32_t v) { read_outbox_max_id_ = v; } 

  int32_t unread_count() const { return unread_count_; } 
  void set_unread_count(int32_t v) { unread_count_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

private:
  int32_t flags_;
  bool pinned_ {false};
  std::unique_ptr<Peer> peer_;
  int32_t top_message_;
  int32_t read_inbox_max_id_;
  int32_t read_outbox_max_id_;
  int32_t unread_count_;
  std::unique_ptr<PeerNotifySettings> notify_settings_;
  int32_t pts_;
  std::unique_ptr<DraftMessage> draft_;
};

// photoEmpty#2331b22d id:long = Photo;
class TL_photoEmpty : public Photo {
public:
  enum {
    CLASS_ID = 0x2331b22d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photoEmpty#0x2331b22d";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

private:
  int64_t id_;
};

// photo#9288dd29 flags:# has_stickers:flags.0?true id:long access_hash:long date:int sizes:Vector<PhotoSize> = Photo;
class TL_photo : public Photo {
public:
  enum {
    CLASS_ID = 0x9288dd29
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photo#0x9288dd29";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t flags_;
  bool has_stickers_ {false};
  int64_t id_;
  int64_t access_hash_;
  int32_t date_;
  TLObjectVector<PhotoSize> sizes_;
};

// photoSizeEmpty#e17e23c type:string = PhotoSize;
class TL_photoSizeEmpty : public PhotoSize {
public:
  enum {
    CLASS_ID = 0xe17e23c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photoSizeEmpty#0xe17e23c";
  }

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

private:
  std::string type_;
};

// photoSize#77bfb61b type:string location:FileLocation w:int h:int size:int = PhotoSize;
class TL_photoSize : public PhotoSize {
public:
  enum {
    CLASS_ID = 0x77bfb61b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photoSize#0x77bfb61b";
  }

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  int32_t w() const { return w_; } 
  void set_w(int32_t v) { w_ = v; } 

  int32_t h() const { return h_; } 
  void set_h(int32_t v) { h_ = v; } 

  int32_t size() const { return size_; } 
  void set_size(int32_t v) { size_ = v; } 

private:
  std::string type_;
  std::unique_ptr<FileLocation> location_;
  int32_t w_;
  int32_t h_;
  int32_t size_;
};

// photoCachedSize#e9a734fa type:string location:FileLocation w:int h:int bytes:bytes = PhotoSize;
class TL_photoCachedSize : public PhotoSize {
public:
  enum {
    CLASS_ID = 0xe9a734fa
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photoCachedSize#0xe9a734fa";
  }

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  int32_t w() const { return w_; } 
  void set_w(int32_t v) { w_ = v; } 

  int32_t h() const { return h_; } 
  void set_h(int32_t v) { h_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  std::string type_;
  std::unique_ptr<FileLocation> location_;
  int32_t w_;
  int32_t h_;
  std::string bytes_;
};

// geoPointEmpty#1117dd5f = GeoPoint;
class TL_geoPointEmpty : public GeoPoint {
public:
  enum {
    CLASS_ID = 0x1117dd5f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "geoPointEmpty#0x1117dd5f";
  }

private:
};

// geoPoint#2049d70c long:double lat:double = GeoPoint;
class TL_geoPoint : public GeoPoint {
public:
  enum {
    CLASS_ID = 0x2049d70c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "geoPoint#0x2049d70c";
  }

private:
  double long_;
  double lat_;
};

// auth.checkedPhone#811ea28e phone_registered:Bool = auth.CheckedPhone;
class TL_auth_checkedPhone : public auth_CheckedPhone {
public:
  enum {
    CLASS_ID = 0x811ea28e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_checkedPhone#0x811ea28e";
  }

private:
  std::unique_ptr<Bool> phone_registered_;
};

// auth.sentCode#5e002502 flags:# phone_registered:flags.0?true type:auth.SentCodeType phone_code_hash:string next_type:flags.1?auth.CodeType timeout:flags.2?int = auth.SentCode;
class TL_auth_sentCode : public auth_SentCode {
public:
  enum {
    CLASS_ID = 0x5e002502
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_sentCode#0x5e002502";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_phone_code_hash() { return &phone_code_hash_; } 
  const std::string& phone_code_hash() const { return phone_code_hash_; } 
  void set_phone_code_hash(const std::string& v) { phone_code_hash_ = v; } 
  void set_phone_code_hash(const char* v, size_t n) { phone_code_hash_.assign(v, n); } 
  void set_phone_code_hash(const char* v) { phone_code_hash_ = v; } 

  int32_t timeout() const { return timeout_; } 
  void set_timeout(int32_t v) { timeout_ = v; } 

private:
  int32_t flags_;
  bool phone_registered_ {false};
  std::unique_ptr<auth_SentCodeType> type_;
  std::string phone_code_hash_;
  std::unique_ptr<auth_CodeType> next_type_;
  int32_t timeout_;
};

// auth.authorization#cd050916 flags:# tmp_sessions:flags.0?int user:User = auth.Authorization;
class TL_auth_authorization : public auth_Authorization {
public:
  enum {
    CLASS_ID = 0xcd050916
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_authorization#0xcd050916";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t tmp_sessions() const { return tmp_sessions_; } 
  void set_tmp_sessions(int32_t v) { tmp_sessions_ = v; } 

private:
  int32_t flags_;
  int32_t tmp_sessions_;
  std::unique_ptr<User> user_;
};

// auth.exportedAuthorization#df969c2d id:int bytes:bytes = auth.ExportedAuthorization;
class TL_auth_exportedAuthorization : public auth_ExportedAuthorization {
public:
  enum {
    CLASS_ID = 0xdf969c2d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_exportedAuthorization#0xdf969c2d";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  int32_t id_;
  std::string bytes_;
};

// inputNotifyPeer#b8bc5b0c peer:InputPeer = InputNotifyPeer;
class TL_inputNotifyPeer : public InputNotifyPeer {
public:
  enum {
    CLASS_ID = 0xb8bc5b0c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputNotifyPeer#0xb8bc5b0c";
  }

private:
  std::unique_ptr<InputPeer> peer_;
};

// inputNotifyUsers#193b4417 = InputNotifyPeer;
class TL_inputNotifyUsers : public InputNotifyPeer {
public:
  enum {
    CLASS_ID = 0x193b4417
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputNotifyUsers#0x193b4417";
  }

private:
};

// inputNotifyChats#4a95e84e = InputNotifyPeer;
class TL_inputNotifyChats : public InputNotifyPeer {
public:
  enum {
    CLASS_ID = 0x4a95e84e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputNotifyChats#0x4a95e84e";
  }

private:
};

// inputNotifyAll#a429b886 = InputNotifyPeer;
class TL_inputNotifyAll : public InputNotifyPeer {
public:
  enum {
    CLASS_ID = 0xa429b886
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputNotifyAll#0xa429b886";
  }

private:
};

// inputPeerNotifyEventsEmpty#f03064d8 = InputPeerNotifyEvents;
class TL_inputPeerNotifyEventsEmpty : public InputPeerNotifyEvents {
public:
  enum {
    CLASS_ID = 0xf03064d8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPeerNotifyEventsEmpty#0xf03064d8";
  }

private:
};

// inputPeerNotifyEventsAll#e86a2c74 = InputPeerNotifyEvents;
class TL_inputPeerNotifyEventsAll : public InputPeerNotifyEvents {
public:
  enum {
    CLASS_ID = 0xe86a2c74
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPeerNotifyEventsAll#0xe86a2c74";
  }

private:
};

// inputPeerNotifySettings#38935eb2 flags:# show_previews:flags.0?true silent:flags.1?true mute_until:int sound:string = InputPeerNotifySettings;
class TL_inputPeerNotifySettings : public InputPeerNotifySettings {
public:
  enum {
    CLASS_ID = 0x38935eb2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPeerNotifySettings#0x38935eb2";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t mute_until() const { return mute_until_; } 
  void set_mute_until(int32_t v) { mute_until_ = v; } 

  std::string* mutable_sound() { return &sound_; } 
  const std::string& sound() const { return sound_; } 
  void set_sound(const std::string& v) { sound_ = v; } 
  void set_sound(const char* v, size_t n) { sound_.assign(v, n); } 
  void set_sound(const char* v) { sound_ = v; } 

private:
  int32_t flags_;
  bool show_previews_ {false};
  bool silent_ {false};
  int32_t mute_until_;
  std::string sound_;
};

// peerNotifyEventsEmpty#add53cb3 = PeerNotifyEvents;
class TL_peerNotifyEventsEmpty : public PeerNotifyEvents {
public:
  enum {
    CLASS_ID = 0xadd53cb3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "peerNotifyEventsEmpty#0xadd53cb3";
  }

private:
};

// peerNotifyEventsAll#6d1ded88 = PeerNotifyEvents;
class TL_peerNotifyEventsAll : public PeerNotifyEvents {
public:
  enum {
    CLASS_ID = 0x6d1ded88
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "peerNotifyEventsAll#0x6d1ded88";
  }

private:
};

// peerNotifySettingsEmpty#70a68512 = PeerNotifySettings;
class TL_peerNotifySettingsEmpty : public PeerNotifySettings {
public:
  enum {
    CLASS_ID = 0x70a68512
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "peerNotifySettingsEmpty#0x70a68512";
  }

private:
};

// peerNotifySettings#9acda4c0 flags:# show_previews:flags.0?true silent:flags.1?true mute_until:int sound:string = PeerNotifySettings;
class TL_peerNotifySettings : public PeerNotifySettings {
public:
  enum {
    CLASS_ID = 0x9acda4c0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "peerNotifySettings#0x9acda4c0";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t mute_until() const { return mute_until_; } 
  void set_mute_until(int32_t v) { mute_until_ = v; } 

  std::string* mutable_sound() { return &sound_; } 
  const std::string& sound() const { return sound_; } 
  void set_sound(const std::string& v) { sound_ = v; } 
  void set_sound(const char* v, size_t n) { sound_.assign(v, n); } 
  void set_sound(const char* v) { sound_ = v; } 

private:
  int32_t flags_;
  bool show_previews_ {false};
  bool silent_ {false};
  int32_t mute_until_;
  std::string sound_;
};

// peerSettings#818426cd flags:# report_spam:flags.0?true = PeerSettings;
class TL_peerSettings : public PeerSettings {
public:
  enum {
    CLASS_ID = 0x818426cd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "peerSettings#0x818426cd";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool report_spam_ {false};
};

// wallPaper#ccb03657 id:int title:string sizes:Vector<PhotoSize> color:int = WallPaper;
class TL_wallPaper : public WallPaper {
public:
  enum {
    CLASS_ID = 0xccb03657
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "wallPaper#0xccb03657";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  int32_t color() const { return color_; } 
  void set_color(int32_t v) { color_ = v; } 

private:
  int32_t id_;
  std::string title_;
  TLObjectVector<PhotoSize> sizes_;
  int32_t color_;
};

// wallPaperSolid#63117f24 id:int title:string bg_color:int color:int = WallPaper;
class TL_wallPaperSolid : public WallPaper {
public:
  enum {
    CLASS_ID = 0x63117f24
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "wallPaperSolid#0x63117f24";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  int32_t bg_color() const { return bg_color_; } 
  void set_bg_color(int32_t v) { bg_color_ = v; } 

  int32_t color() const { return color_; } 
  void set_color(int32_t v) { color_ = v; } 

private:
  int32_t id_;
  std::string title_;
  int32_t bg_color_;
  int32_t color_;
};

// inputReportReasonSpam#58dbcab8 = ReportReason;
class TL_inputReportReasonSpam : public ReportReason {
public:
  enum {
    CLASS_ID = 0x58dbcab8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputReportReasonSpam#0x58dbcab8";
  }

private:
};

// inputReportReasonViolence#1e22c78d = ReportReason;
class TL_inputReportReasonViolence : public ReportReason {
public:
  enum {
    CLASS_ID = 0x1e22c78d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputReportReasonViolence#0x1e22c78d";
  }

private:
};

// inputReportReasonPornography#2e59d922 = ReportReason;
class TL_inputReportReasonPornography : public ReportReason {
public:
  enum {
    CLASS_ID = 0x2e59d922
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputReportReasonPornography#0x2e59d922";
  }

private:
};

// inputReportReasonOther#e1746d0a text:string = ReportReason;
class TL_inputReportReasonOther : public ReportReason {
public:
  enum {
    CLASS_ID = 0xe1746d0a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputReportReasonOther#0xe1746d0a";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  std::string text_;
};

// userFull#f220f3f flags:# blocked:flags.0?true phone_calls_available:flags.4?true phone_calls_private:flags.5?true user:User about:flags.1?string link:contacts.Link profile_photo:flags.2?Photo notify_settings:PeerNotifySettings bot_info:flags.3?BotInfo common_chats_count:int = UserFull;
class TL_userFull : public UserFull {
public:
  enum {
    CLASS_ID = 0xf220f3f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "userFull#0xf220f3f";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_about() { return &about_; } 
  const std::string& about() const { return about_; } 
  void set_about(const std::string& v) { about_ = v; } 
  void set_about(const char* v, size_t n) { about_.assign(v, n); } 
  void set_about(const char* v) { about_ = v; } 

  int32_t common_chats_count() const { return common_chats_count_; } 
  void set_common_chats_count(int32_t v) { common_chats_count_ = v; } 

private:
  int32_t flags_;
  bool blocked_ {false};
  bool phone_calls_available_ {false};
  bool phone_calls_private_ {false};
  std::unique_ptr<User> user_;
  std::string about_;
  std::unique_ptr<contacts_Link> link_;
  std::unique_ptr<Photo> profile_photo_;
  std::unique_ptr<PeerNotifySettings> notify_settings_;
  std::unique_ptr<BotInfo> bot_info_;
  int32_t common_chats_count_;
};

// contact#f911c994 user_id:int mutual:Bool = Contact;
class TL_contact : public Contact {
public:
  enum {
    CLASS_ID = 0xf911c994
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contact#0xf911c994";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
  std::unique_ptr<Bool> mutual_;
};

// importedContact#d0028438 user_id:int client_id:long = ImportedContact;
class TL_importedContact : public ImportedContact {
public:
  enum {
    CLASS_ID = 0xd0028438
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "importedContact#0xd0028438";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int64_t client_id() const { return client_id_; } 
  void set_client_id(int64_t v) { client_id_ = v; } 

private:
  int32_t user_id_;
  int64_t client_id_;
};

// contactBlocked#561bc879 user_id:int date:int = ContactBlocked;
class TL_contactBlocked : public ContactBlocked {
public:
  enum {
    CLASS_ID = 0x561bc879
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contactBlocked#0x561bc879";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t date_;
};

// contactStatus#d3680c61 user_id:int status:UserStatus = ContactStatus;
class TL_contactStatus : public ContactStatus {
public:
  enum {
    CLASS_ID = 0xd3680c61
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contactStatus#0xd3680c61";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
  std::unique_ptr<UserStatus> status_;
};

// contacts.link#3ace484c my_link:ContactLink foreign_link:ContactLink user:User = contacts.Link;
class TL_contacts_link : public contacts_Link {
public:
  enum {
    CLASS_ID = 0x3ace484c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_link#0x3ace484c";
  }

private:
  std::unique_ptr<ContactLink> my_link_;
  std::unique_ptr<ContactLink> foreign_link_;
  std::unique_ptr<User> user_;
};

// contacts.contactsNotModified#b74ba9d2 = contacts.Contacts;
class TL_contacts_contactsNotModified : public contacts_Contacts {
public:
  enum {
    CLASS_ID = 0xb74ba9d2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_contactsNotModified#0xb74ba9d2";
  }

private:
};

// contacts.contacts#6f8b8cb2 contacts:Vector<Contact> users:Vector<User> = contacts.Contacts;
class TL_contacts_contacts : public contacts_Contacts {
public:
  enum {
    CLASS_ID = 0x6f8b8cb2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_contacts#0x6f8b8cb2";
  }

private:
  TLObjectVector<Contact> contacts_;
  TLObjectVector<User> users_;
};

// contacts.importedContacts#ad524315 imported:Vector<ImportedContact> retry_contacts:Vector<long> users:Vector<User> = contacts.ImportedContacts;
class TL_contacts_importedContacts : public contacts_ImportedContacts {
public:
  enum {
    CLASS_ID = 0xad524315
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_importedContacts#0xad524315";
  }

  size_t retry_contacts_size() const { return retry_contacts_.size(); } 
  const TLInt64Vector& retry_contacts() const { return retry_contacts_; } 
  int64_t retry_contacts(int idx) const { return retry_contacts_.vector()[idx]; } 
  void add_retry_contacts(int64_t v) {retry_contacts_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_retry_contacts() { return &retry_contacts_; } 

private:
  TLObjectVector<ImportedContact> imported_;
  TLInt64Vector retry_contacts_;
  TLObjectVector<User> users_;
};

// contacts.blocked#1c138d15 blocked:Vector<ContactBlocked> users:Vector<User> = contacts.Blocked;
class TL_contacts_blocked : public contacts_Blocked {
public:
  enum {
    CLASS_ID = 0x1c138d15
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_blocked#0x1c138d15";
  }

private:
  TLObjectVector<ContactBlocked> blocked_;
  TLObjectVector<User> users_;
};

// contacts.blockedSlice#900802a1 count:int blocked:Vector<ContactBlocked> users:Vector<User> = contacts.Blocked;
class TL_contacts_blockedSlice : public contacts_Blocked {
public:
  enum {
    CLASS_ID = 0x900802a1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_blockedSlice#0x900802a1";
  }

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  int32_t count_;
  TLObjectVector<ContactBlocked> blocked_;
  TLObjectVector<User> users_;
};

// messages.dialogs#15ba6c40 dialogs:Vector<Dialog> messages:Vector<Message> chats:Vector<Chat> users:Vector<User> = messages.Dialogs;
class TL_messages_dialogs : public messages_Dialogs {
public:
  enum {
    CLASS_ID = 0x15ba6c40
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_dialogs#0x15ba6c40";
  }

private:
  TLObjectVector<Dialog> dialogs_;
  TLObjectVector<Message> messages_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// messages.dialogsSlice#71e094f3 count:int dialogs:Vector<Dialog> messages:Vector<Message> chats:Vector<Chat> users:Vector<User> = messages.Dialogs;
class TL_messages_dialogsSlice : public messages_Dialogs {
public:
  enum {
    CLASS_ID = 0x71e094f3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_dialogsSlice#0x71e094f3";
  }

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  int32_t count_;
  TLObjectVector<Dialog> dialogs_;
  TLObjectVector<Message> messages_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// messages.messages#8c718e87 messages:Vector<Message> chats:Vector<Chat> users:Vector<User> = messages.Messages;
class TL_messages_messages : public messages_Messages {
public:
  enum {
    CLASS_ID = 0x8c718e87
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_messages#0x8c718e87";
  }

private:
  TLObjectVector<Message> messages_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// messages.messagesSlice#b446ae3 count:int messages:Vector<Message> chats:Vector<Chat> users:Vector<User> = messages.Messages;
class TL_messages_messagesSlice : public messages_Messages {
public:
  enum {
    CLASS_ID = 0xb446ae3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_messagesSlice#0xb446ae3";
  }

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  int32_t count_;
  TLObjectVector<Message> messages_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// messages.channelMessages#99262e37 flags:# pts:int count:int messages:Vector<Message> chats:Vector<Chat> users:Vector<User> = messages.Messages;
class TL_messages_channelMessages : public messages_Messages {
public:
  enum {
    CLASS_ID = 0x99262e37
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_channelMessages#0x99262e37";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  int32_t flags_;
  int32_t pts_;
  int32_t count_;
  TLObjectVector<Message> messages_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// messages.chats#64ff9fd5 chats:Vector<Chat> = messages.Chats;
class TL_messages_chats : public messages_Chats {
public:
  enum {
    CLASS_ID = 0x64ff9fd5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_chats#0x64ff9fd5";
  }

private:
  TLObjectVector<Chat> chats_;
};

// messages.chatsSlice#9cd81144 count:int chats:Vector<Chat> = messages.Chats;
class TL_messages_chatsSlice : public messages_Chats {
public:
  enum {
    CLASS_ID = 0x9cd81144
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_chatsSlice#0x9cd81144";
  }

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  int32_t count_;
  TLObjectVector<Chat> chats_;
};

// messages.chatFull#e5d7d19c full_chat:ChatFull chats:Vector<Chat> users:Vector<User> = messages.ChatFull;
class TL_messages_chatFull : public messages_ChatFull {
public:
  enum {
    CLASS_ID = 0xe5d7d19c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_chatFull#0xe5d7d19c";
  }

private:
  std::unique_ptr<ChatFull> full_chat_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// messages.affectedHistory#b45c69d1 pts:int pts_count:int offset:int = messages.AffectedHistory;
class TL_messages_affectedHistory : public messages_AffectedHistory {
public:
  enum {
    CLASS_ID = 0xb45c69d1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_affectedHistory#0xb45c69d1";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

private:
  int32_t pts_;
  int32_t pts_count_;
  int32_t offset_;
};

// inputMessagesFilterEmpty#57e2f66c = MessagesFilter;
class TL_inputMessagesFilterEmpty : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x57e2f66c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterEmpty#0x57e2f66c";
  }

private:
};

// inputMessagesFilterPhotos#9609a51c = MessagesFilter;
class TL_inputMessagesFilterPhotos : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x9609a51c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterPhotos#0x9609a51c";
  }

private:
};

// inputMessagesFilterVideo#9fc00e65 = MessagesFilter;
class TL_inputMessagesFilterVideo : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x9fc00e65
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterVideo#0x9fc00e65";
  }

private:
};

// inputMessagesFilterPhotoVideo#56e9f0e4 = MessagesFilter;
class TL_inputMessagesFilterPhotoVideo : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x56e9f0e4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterPhotoVideo#0x56e9f0e4";
  }

private:
};

// inputMessagesFilterPhotoVideoDocuments#d95e73bb = MessagesFilter;
class TL_inputMessagesFilterPhotoVideoDocuments : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0xd95e73bb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterPhotoVideoDocuments#0xd95e73bb";
  }

private:
};

// inputMessagesFilterDocument#9eddf188 = MessagesFilter;
class TL_inputMessagesFilterDocument : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x9eddf188
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterDocument#0x9eddf188";
  }

private:
};

// inputMessagesFilterUrl#7ef0dd87 = MessagesFilter;
class TL_inputMessagesFilterUrl : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x7ef0dd87
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterUrl#0x7ef0dd87";
  }

private:
};

// inputMessagesFilterGif#ffc86587 = MessagesFilter;
class TL_inputMessagesFilterGif : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0xffc86587
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterGif#0xffc86587";
  }

private:
};

// inputMessagesFilterVoice#50f5c392 = MessagesFilter;
class TL_inputMessagesFilterVoice : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x50f5c392
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterVoice#0x50f5c392";
  }

private:
};

// inputMessagesFilterMusic#3751b49e = MessagesFilter;
class TL_inputMessagesFilterMusic : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x3751b49e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterMusic#0x3751b49e";
  }

private:
};

// inputMessagesFilterChatPhotos#3a20ecb8 = MessagesFilter;
class TL_inputMessagesFilterChatPhotos : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x3a20ecb8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterChatPhotos#0x3a20ecb8";
  }

private:
};

// inputMessagesFilterPhoneCalls#80c99768 flags:# missed:flags.0?true = MessagesFilter;
class TL_inputMessagesFilterPhoneCalls : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x80c99768
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterPhoneCalls#0x80c99768";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool missed_ {false};
};

// inputMessagesFilterRoundVoice#7a7c17a4 = MessagesFilter;
class TL_inputMessagesFilterRoundVoice : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0x7a7c17a4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterRoundVoice#0x7a7c17a4";
  }

private:
};

// inputMessagesFilterRoundVideo#b549da53 = MessagesFilter;
class TL_inputMessagesFilterRoundVideo : public MessagesFilter {
public:
  enum {
    CLASS_ID = 0xb549da53
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessagesFilterRoundVideo#0xb549da53";
  }

private:
};

// updateNewMessage#1f2b0afd message:Message pts:int pts_count:int = Update;
class TL_updateNewMessage : public Update {
public:
  enum {
    CLASS_ID = 0x1f2b0afd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateNewMessage#0x1f2b0afd";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  std::unique_ptr<Message> message_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateMessageID#4e90bfd6 id:int random_id:long = Update;
class TL_updateMessageID : public Update {
public:
  enum {
    CLASS_ID = 0x4e90bfd6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateMessageID#0x4e90bfd6";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

private:
  int32_t id_;
  int64_t random_id_;
};

// updateDeleteMessages#a20db0e5 messages:Vector<int> pts:int pts_count:int = Update;
class TL_updateDeleteMessages : public Update {
public:
  enum {
    CLASS_ID = 0xa20db0e5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateDeleteMessages#0xa20db0e5";
  }

  size_t messages_size() const { return messages_.size(); } 
  const TLInt32Vector& messages() const { return messages_; } 
  int32_t messages(int idx) const { return messages_.vector()[idx]; } 
  void add_messages(int32_t v) {messages_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_messages() { return &messages_; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  TLInt32Vector messages_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateUserTyping#5c486927 user_id:int action:SendMessageAction = Update;
class TL_updateUserTyping : public Update {
public:
  enum {
    CLASS_ID = 0x5c486927
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateUserTyping#0x5c486927";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
  std::unique_ptr<SendMessageAction> action_;
};

// updateChatUserTyping#9a65ea1f chat_id:int user_id:int action:SendMessageAction = Update;
class TL_updateChatUserTyping : public Update {
public:
  enum {
    CLASS_ID = 0x9a65ea1f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChatUserTyping#0x9a65ea1f";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t chat_id_;
  int32_t user_id_;
  std::unique_ptr<SendMessageAction> action_;
};

// updateChatParticipants#7761198 participants:ChatParticipants = Update;
class TL_updateChatParticipants : public Update {
public:
  enum {
    CLASS_ID = 0x7761198
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChatParticipants#0x7761198";
  }

private:
  std::unique_ptr<ChatParticipants> participants_;
};

// updateUserStatus#1bfbd823 user_id:int status:UserStatus = Update;
class TL_updateUserStatus : public Update {
public:
  enum {
    CLASS_ID = 0x1bfbd823
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateUserStatus#0x1bfbd823";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
  std::unique_ptr<UserStatus> status_;
};

// updateUserName#a7332b73 user_id:int first_name:string last_name:string username:string = Update;
class TL_updateUserName : public Update {
public:
  enum {
    CLASS_ID = 0xa7332b73
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateUserName#0xa7332b73";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

  std::string* mutable_username() { return &username_; } 
  const std::string& username() const { return username_; } 
  void set_username(const std::string& v) { username_ = v; } 
  void set_username(const char* v, size_t n) { username_.assign(v, n); } 
  void set_username(const char* v) { username_ = v; } 

private:
  int32_t user_id_;
  std::string first_name_;
  std::string last_name_;
  std::string username_;
};

// updateUserPhoto#95313b0c user_id:int date:int photo:UserProfilePhoto previous:Bool = Update;
class TL_updateUserPhoto : public Update {
public:
  enum {
    CLASS_ID = 0x95313b0c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateUserPhoto#0x95313b0c";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t date_;
  std::unique_ptr<UserProfilePhoto> photo_;
  std::unique_ptr<Bool> previous_;
};

// updateContactRegistered#2575bbb9 user_id:int date:int = Update;
class TL_updateContactRegistered : public Update {
public:
  enum {
    CLASS_ID = 0x2575bbb9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateContactRegistered#0x2575bbb9";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t date_;
};

// updateContactLink#9d2e67c5 user_id:int my_link:ContactLink foreign_link:ContactLink = Update;
class TL_updateContactLink : public Update {
public:
  enum {
    CLASS_ID = 0x9d2e67c5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateContactLink#0x9d2e67c5";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
  std::unique_ptr<ContactLink> my_link_;
  std::unique_ptr<ContactLink> foreign_link_;
};

// updateNewEncryptedMessage#12bcbd9a message:EncryptedMessage qts:int = Update;
class TL_updateNewEncryptedMessage : public Update {
public:
  enum {
    CLASS_ID = 0x12bcbd9a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateNewEncryptedMessage#0x12bcbd9a";
  }

  int32_t qts() const { return qts_; } 
  void set_qts(int32_t v) { qts_ = v; } 

private:
  std::unique_ptr<EncryptedMessage> message_;
  int32_t qts_;
};

// updateEncryptedChatTyping#1710f156 chat_id:int = Update;
class TL_updateEncryptedChatTyping : public Update {
public:
  enum {
    CLASS_ID = 0x1710f156
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateEncryptedChatTyping#0x1710f156";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
};

// updateEncryption#b4a2e88d chat:EncryptedChat date:int = Update;
class TL_updateEncryption : public Update {
public:
  enum {
    CLASS_ID = 0xb4a2e88d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateEncryption#0xb4a2e88d";
  }

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  std::unique_ptr<EncryptedChat> chat_;
  int32_t date_;
};

// updateEncryptedMessagesRead#38fe25b7 chat_id:int max_date:int date:int = Update;
class TL_updateEncryptedMessagesRead : public Update {
public:
  enum {
    CLASS_ID = 0x38fe25b7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateEncryptedMessagesRead#0x38fe25b7";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t max_date() const { return max_date_; } 
  void set_max_date(int32_t v) { max_date_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t chat_id_;
  int32_t max_date_;
  int32_t date_;
};

// updateChatParticipantAdd#ea4b0e5c chat_id:int user_id:int inviter_id:int date:int version:int = Update;
class TL_updateChatParticipantAdd : public Update {
public:
  enum {
    CLASS_ID = 0xea4b0e5c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChatParticipantAdd#0xea4b0e5c";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t inviter_id() const { return inviter_id_; } 
  void set_inviter_id(int32_t v) { inviter_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

private:
  int32_t chat_id_;
  int32_t user_id_;
  int32_t inviter_id_;
  int32_t date_;
  int32_t version_;
};

// updateChatParticipantDelete#6e5f8c22 chat_id:int user_id:int version:int = Update;
class TL_updateChatParticipantDelete : public Update {
public:
  enum {
    CLASS_ID = 0x6e5f8c22
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChatParticipantDelete#0x6e5f8c22";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

private:
  int32_t chat_id_;
  int32_t user_id_;
  int32_t version_;
};

// updateDcOptions#8e5e9873 dc_options:Vector<DcOption> = Update;
class TL_updateDcOptions : public Update {
public:
  enum {
    CLASS_ID = 0x8e5e9873
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateDcOptions#0x8e5e9873";
  }

private:
  TLObjectVector<DcOption> dc_options_;
};

// updateUserBlocked#80ece81a user_id:int blocked:Bool = Update;
class TL_updateUserBlocked : public Update {
public:
  enum {
    CLASS_ID = 0x80ece81a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateUserBlocked#0x80ece81a";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
  std::unique_ptr<Bool> blocked_;
};

// updateNotifySettings#bec268ef peer:NotifyPeer notify_settings:PeerNotifySettings = Update;
class TL_updateNotifySettings : public Update {
public:
  enum {
    CLASS_ID = 0xbec268ef
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateNotifySettings#0xbec268ef";
  }

private:
  std::unique_ptr<NotifyPeer> peer_;
  std::unique_ptr<PeerNotifySettings> notify_settings_;
};

// updateServiceNotification#ebe46819 flags:# popup:flags.0?true inbox_date:flags.1?int type:string message:string media:MessageMedia entities:Vector<MessageEntity> = Update;
class TL_updateServiceNotification : public Update {
public:
  enum {
    CLASS_ID = 0xebe46819
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateServiceNotification#0xebe46819";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t inbox_date() const { return inbox_date_; } 
  void set_inbox_date(int32_t v) { inbox_date_ = v; } 

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  int32_t flags_;
  bool popup_ {false};
  int32_t inbox_date_;
  std::string type_;
  std::string message_;
  std::unique_ptr<MessageMedia> media_;
  TLObjectVector<MessageEntity> entities_;
};

// updatePrivacy#ee3b272a key:PrivacyKey rules:Vector<PrivacyRule> = Update;
class TL_updatePrivacy : public Update {
public:
  enum {
    CLASS_ID = 0xee3b272a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updatePrivacy#0xee3b272a";
  }

private:
  std::unique_ptr<PrivacyKey> key_;
  TLObjectVector<PrivacyRule> rules_;
};

// updateUserPhone#12b9417b user_id:int phone:string = Update;
class TL_updateUserPhone : public Update {
public:
  enum {
    CLASS_ID = 0x12b9417b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateUserPhone#0x12b9417b";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  std::string* mutable_phone() { return &phone_; } 
  const std::string& phone() const { return phone_; } 
  void set_phone(const std::string& v) { phone_ = v; } 
  void set_phone(const char* v, size_t n) { phone_.assign(v, n); } 
  void set_phone(const char* v) { phone_ = v; } 

private:
  int32_t user_id_;
  std::string phone_;
};

// updateReadHistoryInbox#9961fd5c peer:Peer max_id:int pts:int pts_count:int = Update;
class TL_updateReadHistoryInbox : public Update {
public:
  enum {
    CLASS_ID = 0x9961fd5c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateReadHistoryInbox#0x9961fd5c";
  }

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  std::unique_ptr<Peer> peer_;
  int32_t max_id_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateReadHistoryOutbox#2f2f21bf peer:Peer max_id:int pts:int pts_count:int = Update;
class TL_updateReadHistoryOutbox : public Update {
public:
  enum {
    CLASS_ID = 0x2f2f21bf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateReadHistoryOutbox#0x2f2f21bf";
  }

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  std::unique_ptr<Peer> peer_;
  int32_t max_id_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateWebPage#7f891213 webpage:WebPage pts:int pts_count:int = Update;
class TL_updateWebPage : public Update {
public:
  enum {
    CLASS_ID = 0x7f891213
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateWebPage#0x7f891213";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  std::unique_ptr<WebPage> webpage_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateReadMessagesContents#68c13933 messages:Vector<int> pts:int pts_count:int = Update;
class TL_updateReadMessagesContents : public Update {
public:
  enum {
    CLASS_ID = 0x68c13933
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateReadMessagesContents#0x68c13933";
  }

  size_t messages_size() const { return messages_.size(); } 
  const TLInt32Vector& messages() const { return messages_; } 
  int32_t messages(int idx) const { return messages_.vector()[idx]; } 
  void add_messages(int32_t v) {messages_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_messages() { return &messages_; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  TLInt32Vector messages_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateChannelTooLong#eb0467fb flags:# channel_id:int pts:flags.0?int = Update;
class TL_updateChannelTooLong : public Update {
public:
  enum {
    CLASS_ID = 0xeb0467fb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChannelTooLong#0xeb0467fb";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

private:
  int32_t flags_;
  int32_t channel_id_;
  int32_t pts_;
};

// updateChannel#b6d45656 channel_id:int = Update;
class TL_updateChannel : public Update {
public:
  enum {
    CLASS_ID = 0xb6d45656
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChannel#0xb6d45656";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

private:
  int32_t channel_id_;
};

// updateNewChannelMessage#62ba04d9 message:Message pts:int pts_count:int = Update;
class TL_updateNewChannelMessage : public Update {
public:
  enum {
    CLASS_ID = 0x62ba04d9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateNewChannelMessage#0x62ba04d9";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  std::unique_ptr<Message> message_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateReadChannelInbox#4214f37f channel_id:int max_id:int = Update;
class TL_updateReadChannelInbox : public Update {
public:
  enum {
    CLASS_ID = 0x4214f37f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateReadChannelInbox#0x4214f37f";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

private:
  int32_t channel_id_;
  int32_t max_id_;
};

// updateDeleteChannelMessages#c37521c9 channel_id:int messages:Vector<int> pts:int pts_count:int = Update;
class TL_updateDeleteChannelMessages : public Update {
public:
  enum {
    CLASS_ID = 0xc37521c9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateDeleteChannelMessages#0xc37521c9";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  size_t messages_size() const { return messages_.size(); } 
  const TLInt32Vector& messages() const { return messages_; } 
  int32_t messages(int idx) const { return messages_.vector()[idx]; } 
  void add_messages(int32_t v) {messages_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_messages() { return &messages_; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  int32_t channel_id_;
  TLInt32Vector messages_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateChannelMessageViews#98a12b4b channel_id:int id:int views:int = Update;
class TL_updateChannelMessageViews : public Update {
public:
  enum {
    CLASS_ID = 0x98a12b4b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChannelMessageViews#0x98a12b4b";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int32_t views() const { return views_; } 
  void set_views(int32_t v) { views_ = v; } 

private:
  int32_t channel_id_;
  int32_t id_;
  int32_t views_;
};

// updateChatAdmins#6e947941 chat_id:int enabled:Bool version:int = Update;
class TL_updateChatAdmins : public Update {
public:
  enum {
    CLASS_ID = 0x6e947941
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChatAdmins#0x6e947941";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

private:
  int32_t chat_id_;
  std::unique_ptr<Bool> enabled_;
  int32_t version_;
};

// updateChatParticipantAdmin#b6901959 chat_id:int user_id:int is_admin:Bool version:int = Update;
class TL_updateChatParticipantAdmin : public Update {
public:
  enum {
    CLASS_ID = 0xb6901959
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChatParticipantAdmin#0xb6901959";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

private:
  int32_t chat_id_;
  int32_t user_id_;
  std::unique_ptr<Bool> is_admin_;
  int32_t version_;
};

// updateNewStickerSet#688a30aa stickerset:messages.StickerSet = Update;
class TL_updateNewStickerSet : public Update {
public:
  enum {
    CLASS_ID = 0x688a30aa
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateNewStickerSet#0x688a30aa";
  }

private:
  std::unique_ptr<messages_StickerSet> stickerset_;
};

// updateStickerSetsOrder#bb2d201 flags:# masks:flags.0?true order:Vector<long> = Update;
class TL_updateStickerSetsOrder : public Update {
public:
  enum {
    CLASS_ID = 0xbb2d201
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateStickerSetsOrder#0xbb2d201";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  size_t order_size() const { return order_.size(); } 
  const TLInt64Vector& order() const { return order_; } 
  int64_t order(int idx) const { return order_.vector()[idx]; } 
  void add_order(int64_t v) {order_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_order() { return &order_; } 

private:
  int32_t flags_;
  bool masks_ {false};
  TLInt64Vector order_;
};

// updateStickerSets#43ae3dec = Update;
class TL_updateStickerSets : public Update {
public:
  enum {
    CLASS_ID = 0x43ae3dec
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateStickerSets#0x43ae3dec";
  }

private:
};

// updateSavedGifs#9375341e = Update;
class TL_updateSavedGifs : public Update {
public:
  enum {
    CLASS_ID = 0x9375341e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateSavedGifs#0x9375341e";
  }

private:
};

// updateBotInlineQuery#54826690 flags:# query_id:long user_id:int query:string geo:flags.0?GeoPoint offset:string = Update;
class TL_updateBotInlineQuery : public Update {
public:
  enum {
    CLASS_ID = 0x54826690
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateBotInlineQuery#0x54826690";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  std::string* mutable_query() { return &query_; } 
  const std::string& query() const { return query_; } 
  void set_query(const std::string& v) { query_ = v; } 
  void set_query(const char* v, size_t n) { query_.assign(v, n); } 
  void set_query(const char* v) { query_ = v; } 

  std::string* mutable_offset() { return &offset_; } 
  const std::string& offset() const { return offset_; } 
  void set_offset(const std::string& v) { offset_ = v; } 
  void set_offset(const char* v, size_t n) { offset_.assign(v, n); } 
  void set_offset(const char* v) { offset_ = v; } 

private:
  int32_t flags_;
  int64_t query_id_;
  int32_t user_id_;
  std::string query_;
  std::unique_ptr<GeoPoint> geo_;
  std::string offset_;
};

// updateBotInlineSend#e48f964 flags:# user_id:int query:string geo:flags.0?GeoPoint id:string msg_id:flags.1?InputBotInlineMessageID = Update;
class TL_updateBotInlineSend : public Update {
public:
  enum {
    CLASS_ID = 0xe48f964
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateBotInlineSend#0xe48f964";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  std::string* mutable_query() { return &query_; } 
  const std::string& query() const { return query_; } 
  void set_query(const std::string& v) { query_ = v; } 
  void set_query(const char* v, size_t n) { query_.assign(v, n); } 
  void set_query(const char* v) { query_ = v; } 

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

private:
  int32_t flags_;
  int32_t user_id_;
  std::string query_;
  std::unique_ptr<GeoPoint> geo_;
  std::string id_;
  std::unique_ptr<InputBotInlineMessageID> msg_id_;
};

// updateEditChannelMessage#1b3f4df7 message:Message pts:int pts_count:int = Update;
class TL_updateEditChannelMessage : public Update {
public:
  enum {
    CLASS_ID = 0x1b3f4df7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateEditChannelMessage#0x1b3f4df7";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  std::unique_ptr<Message> message_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateChannelPinnedMessage#98592475 channel_id:int id:int = Update;
class TL_updateChannelPinnedMessage : public Update {
public:
  enum {
    CLASS_ID = 0x98592475
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChannelPinnedMessage#0x98592475";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  int32_t channel_id_;
  int32_t id_;
};

// updateBotCallbackQuery#e73547e1 flags:# query_id:long user_id:int peer:Peer msg_id:int chat_instance:long data:flags.0?bytes game_short_name:flags.1?string = Update;
class TL_updateBotCallbackQuery : public Update {
public:
  enum {
    CLASS_ID = 0xe73547e1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateBotCallbackQuery#0xe73547e1";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t msg_id() const { return msg_id_; } 
  void set_msg_id(int32_t v) { msg_id_ = v; } 

  int64_t chat_instance() const { return chat_instance_; } 
  void set_chat_instance(int64_t v) { chat_instance_ = v; } 

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

  std::string* mutable_game_short_name() { return &game_short_name_; } 
  const std::string& game_short_name() const { return game_short_name_; } 
  void set_game_short_name(const std::string& v) { game_short_name_ = v; } 
  void set_game_short_name(const char* v, size_t n) { game_short_name_.assign(v, n); } 
  void set_game_short_name(const char* v) { game_short_name_ = v; } 

private:
  int32_t flags_;
  int64_t query_id_;
  int32_t user_id_;
  std::unique_ptr<Peer> peer_;
  int32_t msg_id_;
  int64_t chat_instance_;
  std::string data_;
  std::string game_short_name_;
};

// updateEditMessage#e40370a3 message:Message pts:int pts_count:int = Update;
class TL_updateEditMessage : public Update {
public:
  enum {
    CLASS_ID = 0xe40370a3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateEditMessage#0xe40370a3";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  std::unique_ptr<Message> message_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateInlineBotCallbackQuery#f9d27a5a flags:# query_id:long user_id:int msg_id:InputBotInlineMessageID chat_instance:long data:flags.0?bytes game_short_name:flags.1?string = Update;
class TL_updateInlineBotCallbackQuery : public Update {
public:
  enum {
    CLASS_ID = 0xf9d27a5a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateInlineBotCallbackQuery#0xf9d27a5a";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int64_t chat_instance() const { return chat_instance_; } 
  void set_chat_instance(int64_t v) { chat_instance_ = v; } 

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

  std::string* mutable_game_short_name() { return &game_short_name_; } 
  const std::string& game_short_name() const { return game_short_name_; } 
  void set_game_short_name(const std::string& v) { game_short_name_ = v; } 
  void set_game_short_name(const char* v, size_t n) { game_short_name_.assign(v, n); } 
  void set_game_short_name(const char* v) { game_short_name_ = v; } 

private:
  int32_t flags_;
  int64_t query_id_;
  int32_t user_id_;
  std::unique_ptr<InputBotInlineMessageID> msg_id_;
  int64_t chat_instance_;
  std::string data_;
  std::string game_short_name_;
};

// updateReadChannelOutbox#25d6c9c7 channel_id:int max_id:int = Update;
class TL_updateReadChannelOutbox : public Update {
public:
  enum {
    CLASS_ID = 0x25d6c9c7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateReadChannelOutbox#0x25d6c9c7";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

private:
  int32_t channel_id_;
  int32_t max_id_;
};

// updateDraftMessage#ee2bb969 peer:Peer draft:DraftMessage = Update;
class TL_updateDraftMessage : public Update {
public:
  enum {
    CLASS_ID = 0xee2bb969
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateDraftMessage#0xee2bb969";
  }

private:
  std::unique_ptr<Peer> peer_;
  std::unique_ptr<DraftMessage> draft_;
};

// updateReadFeaturedStickers#571d2742 = Update;
class TL_updateReadFeaturedStickers : public Update {
public:
  enum {
    CLASS_ID = 0x571d2742
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateReadFeaturedStickers#0x571d2742";
  }

private:
};

// updateRecentStickers#9a422c20 = Update;
class TL_updateRecentStickers : public Update {
public:
  enum {
    CLASS_ID = 0x9a422c20
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateRecentStickers#0x9a422c20";
  }

private:
};

// updateConfig#a229dd06 = Update;
class TL_updateConfig : public Update {
public:
  enum {
    CLASS_ID = 0xa229dd06
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateConfig#0xa229dd06";
  }

private:
};

// updatePtsChanged#3354678f = Update;
class TL_updatePtsChanged : public Update {
public:
  enum {
    CLASS_ID = 0x3354678f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updatePtsChanged#0x3354678f";
  }

private:
};

// updateChannelWebPage#40771900 channel_id:int webpage:WebPage pts:int pts_count:int = Update;
class TL_updateChannelWebPage : public Update {
public:
  enum {
    CLASS_ID = 0x40771900
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateChannelWebPage#0x40771900";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  int32_t channel_id_;
  std::unique_ptr<WebPage> webpage_;
  int32_t pts_;
  int32_t pts_count_;
};

// updateDialogPinned#d711a2cc flags:# pinned:flags.0?true peer:Peer = Update;
class TL_updateDialogPinned : public Update {
public:
  enum {
    CLASS_ID = 0xd711a2cc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateDialogPinned#0xd711a2cc";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool pinned_ {false};
  std::unique_ptr<Peer> peer_;
};

// updatePinnedDialogs#d8caf68d flags:# order:flags.0?Vector<Peer> = Update;
class TL_updatePinnedDialogs : public Update {
public:
  enum {
    CLASS_ID = 0xd8caf68d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updatePinnedDialogs#0xd8caf68d";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  TLObjectVector<Peer> order_;
};

// updateBotWebhookJSON#8317c0c3 data:DataJSON = Update;
class TL_updateBotWebhookJSON : public Update {
public:
  enum {
    CLASS_ID = 0x8317c0c3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateBotWebhookJSON#0x8317c0c3";
  }

private:
  std::unique_ptr<DataJSON> data_;
};

// updateBotWebhookJSONQuery#9b9240a6 query_id:long data:DataJSON timeout:int = Update;
class TL_updateBotWebhookJSONQuery : public Update {
public:
  enum {
    CLASS_ID = 0x9b9240a6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateBotWebhookJSONQuery#0x9b9240a6";
  }

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  int32_t timeout() const { return timeout_; } 
  void set_timeout(int32_t v) { timeout_ = v; } 

private:
  int64_t query_id_;
  std::unique_ptr<DataJSON> data_;
  int32_t timeout_;
};

// updateBotShippingQuery#e0cdc940 query_id:long user_id:int payload:bytes shipping_address:PostAddress = Update;
class TL_updateBotShippingQuery : public Update {
public:
  enum {
    CLASS_ID = 0xe0cdc940
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateBotShippingQuery#0xe0cdc940";
  }

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  std::string* mutable_payload() { return &payload_; } 
  const std::string& payload() const { return payload_; } 
  void set_payload(const std::string& v) { payload_ = v; } 
  void set_payload(const char* v, size_t n) { payload_.assign(v, n); } 
  void set_payload(const char* v) { payload_ = v; } 

private:
  int64_t query_id_;
  int32_t user_id_;
  std::string payload_;
  std::unique_ptr<PostAddress> shipping_address_;
};

// updateBotPrecheckoutQuery#5d2f3aa9 flags:# query_id:long user_id:int payload:bytes info:flags.0?PaymentRequestedInfo shipping_option_id:flags.1?string currency:string total_amount:long = Update;
class TL_updateBotPrecheckoutQuery : public Update {
public:
  enum {
    CLASS_ID = 0x5d2f3aa9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateBotPrecheckoutQuery#0x5d2f3aa9";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  std::string* mutable_payload() { return &payload_; } 
  const std::string& payload() const { return payload_; } 
  void set_payload(const std::string& v) { payload_ = v; } 
  void set_payload(const char* v, size_t n) { payload_.assign(v, n); } 
  void set_payload(const char* v) { payload_ = v; } 

  std::string* mutable_shipping_option_id() { return &shipping_option_id_; } 
  const std::string& shipping_option_id() const { return shipping_option_id_; } 
  void set_shipping_option_id(const std::string& v) { shipping_option_id_ = v; } 
  void set_shipping_option_id(const char* v, size_t n) { shipping_option_id_.assign(v, n); } 
  void set_shipping_option_id(const char* v) { shipping_option_id_ = v; } 

  std::string* mutable_currency() { return &currency_; } 
  const std::string& currency() const { return currency_; } 
  void set_currency(const std::string& v) { currency_ = v; } 
  void set_currency(const char* v, size_t n) { currency_.assign(v, n); } 
  void set_currency(const char* v) { currency_ = v; } 

  int64_t total_amount() const { return total_amount_; } 
  void set_total_amount(int64_t v) { total_amount_ = v; } 

private:
  int32_t flags_;
  int64_t query_id_;
  int32_t user_id_;
  std::string payload_;
  std::unique_ptr<PaymentRequestedInfo> info_;
  std::string shipping_option_id_;
  std::string currency_;
  int64_t total_amount_;
};

// updatePhoneCall#ab0f6b1e phone_call:PhoneCall = Update;
class TL_updatePhoneCall : public Update {
public:
  enum {
    CLASS_ID = 0xab0f6b1e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updatePhoneCall#0xab0f6b1e";
  }

private:
  std::unique_ptr<PhoneCall> phone_call_;
};

// updates.state#a56c2a3e pts:int qts:int date:int seq:int unread_count:int = updates.State;
class TL_updates_state : public updates_State {
public:
  enum {
    CLASS_ID = 0xa56c2a3e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_state#0xa56c2a3e";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t qts() const { return qts_; } 
  void set_qts(int32_t v) { qts_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t seq() const { return seq_; } 
  void set_seq(int32_t v) { seq_ = v; } 

  int32_t unread_count() const { return unread_count_; } 
  void set_unread_count(int32_t v) { unread_count_ = v; } 

private:
  int32_t pts_;
  int32_t qts_;
  int32_t date_;
  int32_t seq_;
  int32_t unread_count_;
};

// updates.differenceEmpty#5d75a138 date:int seq:int = updates.Difference;
class TL_updates_differenceEmpty : public updates_Difference {
public:
  enum {
    CLASS_ID = 0x5d75a138
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_differenceEmpty#0x5d75a138";
  }

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t seq() const { return seq_; } 
  void set_seq(int32_t v) { seq_ = v; } 

private:
  int32_t date_;
  int32_t seq_;
};

// updates.difference#f49ca0 new_messages:Vector<Message> new_encrypted_messages:Vector<EncryptedMessage> other_updates:Vector<Update> chats:Vector<Chat> users:Vector<User> state:updates.State = updates.Difference;
class TL_updates_difference : public updates_Difference {
public:
  enum {
    CLASS_ID = 0xf49ca0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_difference#0xf49ca0";
  }

private:
  TLObjectVector<Message> new_messages_;
  TLObjectVector<EncryptedMessage> new_encrypted_messages_;
  TLObjectVector<Update> other_updates_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
  std::unique_ptr<updates_State> state_;
};

// updates.differenceSlice#a8fb1981 new_messages:Vector<Message> new_encrypted_messages:Vector<EncryptedMessage> other_updates:Vector<Update> chats:Vector<Chat> users:Vector<User> intermediate_state:updates.State = updates.Difference;
class TL_updates_differenceSlice : public updates_Difference {
public:
  enum {
    CLASS_ID = 0xa8fb1981
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_differenceSlice#0xa8fb1981";
  }

private:
  TLObjectVector<Message> new_messages_;
  TLObjectVector<EncryptedMessage> new_encrypted_messages_;
  TLObjectVector<Update> other_updates_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
  std::unique_ptr<updates_State> intermediate_state_;
};

// updates.differenceTooLong#4afe8f6d pts:int = updates.Difference;
class TL_updates_differenceTooLong : public updates_Difference {
public:
  enum {
    CLASS_ID = 0x4afe8f6d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_differenceTooLong#0x4afe8f6d";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

private:
  int32_t pts_;
};

// updatesTooLong#e317af7e = Updates;
class TL_updatesTooLong : public Updates {
public:
  enum {
    CLASS_ID = 0xe317af7e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updatesTooLong#0xe317af7e";
  }

private:
};

// updateShortMessage#914fbf11 flags:# out:flags.1?true mentioned:flags.4?true media_unread:flags.5?true silent:flags.13?true id:int user_id:int message:string pts:int pts_count:int date:int fwd_from:flags.2?MessageFwdHeader via_bot_id:flags.11?int reply_to_msg_id:flags.3?int entities:flags.7?Vector<MessageEntity> = Updates;
class TL_updateShortMessage : public Updates {
public:
  enum {
    CLASS_ID = 0x914fbf11
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateShortMessage#0x914fbf11";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t via_bot_id() const { return via_bot_id_; } 
  void set_via_bot_id(int32_t v) { via_bot_id_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

private:
  int32_t flags_;
  bool out_ {false};
  bool mentioned_ {false};
  bool media_unread_ {false};
  bool silent_ {false};
  int32_t id_;
  int32_t user_id_;
  std::string message_;
  int32_t pts_;
  int32_t pts_count_;
  int32_t date_;
  std::unique_ptr<MessageFwdHeader> fwd_from_;
  int32_t via_bot_id_;
  int32_t reply_to_msg_id_;
  TLObjectVector<MessageEntity> entities_;
};

// updateShortChatMessage#16812688 flags:# out:flags.1?true mentioned:flags.4?true media_unread:flags.5?true silent:flags.13?true id:int from_id:int chat_id:int message:string pts:int pts_count:int date:int fwd_from:flags.2?MessageFwdHeader via_bot_id:flags.11?int reply_to_msg_id:flags.3?int entities:flags.7?Vector<MessageEntity> = Updates;
class TL_updateShortChatMessage : public Updates {
public:
  enum {
    CLASS_ID = 0x16812688
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateShortChatMessage#0x16812688";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int32_t from_id() const { return from_id_; } 
  void set_from_id(int32_t v) { from_id_ = v; } 

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t via_bot_id() const { return via_bot_id_; } 
  void set_via_bot_id(int32_t v) { via_bot_id_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

private:
  int32_t flags_;
  bool out_ {false};
  bool mentioned_ {false};
  bool media_unread_ {false};
  bool silent_ {false};
  int32_t id_;
  int32_t from_id_;
  int32_t chat_id_;
  std::string message_;
  int32_t pts_;
  int32_t pts_count_;
  int32_t date_;
  std::unique_ptr<MessageFwdHeader> fwd_from_;
  int32_t via_bot_id_;
  int32_t reply_to_msg_id_;
  TLObjectVector<MessageEntity> entities_;
};

// updateShort#78d4dec1 update:Update date:int = Updates;
class TL_updateShort : public Updates {
public:
  enum {
    CLASS_ID = 0x78d4dec1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateShort#0x78d4dec1";
  }

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  std::unique_ptr<Update> update_;
  int32_t date_;
};

// updatesCombined#725b04c3 updates:Vector<Update> users:Vector<User> chats:Vector<Chat> date:int seq_start:int seq:int = Updates;
class TL_updatesCombined : public Updates {
public:
  enum {
    CLASS_ID = 0x725b04c3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updatesCombined#0x725b04c3";
  }

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t seq_start() const { return seq_start_; } 
  void set_seq_start(int32_t v) { seq_start_ = v; } 

  int32_t seq() const { return seq_; } 
  void set_seq(int32_t v) { seq_ = v; } 

private:
  TLObjectVector<Update> updates_;
  TLObjectVector<User> users_;
  TLObjectVector<Chat> chats_;
  int32_t date_;
  int32_t seq_start_;
  int32_t seq_;
};

// updates#74ae4240 updates:Vector<Update> users:Vector<User> chats:Vector<Chat> date:int seq:int = Updates;
class TL_updates : public Updates {
public:
  enum {
    CLASS_ID = 0x74ae4240
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates#0x74ae4240";
  }

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t seq() const { return seq_; } 
  void set_seq(int32_t v) { seq_ = v; } 

private:
  TLObjectVector<Update> updates_;
  TLObjectVector<User> users_;
  TLObjectVector<Chat> chats_;
  int32_t date_;
  int32_t seq_;
};

// updateShortSentMessage#11f1331c flags:# out:flags.1?true id:int pts:int pts_count:int date:int media:flags.9?MessageMedia entities:flags.7?Vector<MessageEntity> = Updates;
class TL_updateShortSentMessage : public Updates {
public:
  enum {
    CLASS_ID = 0x11f1331c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updateShortSentMessage#0x11f1331c";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t flags_;
  bool out_ {false};
  int32_t id_;
  int32_t pts_;
  int32_t pts_count_;
  int32_t date_;
  std::unique_ptr<MessageMedia> media_;
  TLObjectVector<MessageEntity> entities_;
};

// photos.photos#8dca6aa5 photos:Vector<Photo> users:Vector<User> = photos.Photos;
class TL_photos_photos : public photos_Photos {
public:
  enum {
    CLASS_ID = 0x8dca6aa5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photos_photos#0x8dca6aa5";
  }

private:
  TLObjectVector<Photo> photos_;
  TLObjectVector<User> users_;
};

// photos.photosSlice#15051f54 count:int photos:Vector<Photo> users:Vector<User> = photos.Photos;
class TL_photos_photosSlice : public photos_Photos {
public:
  enum {
    CLASS_ID = 0x15051f54
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photos_photosSlice#0x15051f54";
  }

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  int32_t count_;
  TLObjectVector<Photo> photos_;
  TLObjectVector<User> users_;
};

// photos.photo#20212ca8 photo:Photo users:Vector<User> = photos.Photo;
class TL_photos_photo : public photos_Photo {
public:
  enum {
    CLASS_ID = 0x20212ca8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photos_photo#0x20212ca8";
  }

private:
  std::unique_ptr<Photo> photo_;
  TLObjectVector<User> users_;
};

// upload.file#96a18d5 type:storage.FileType mtime:int bytes:bytes = upload.File;
class TL_upload_file : public upload_File {
public:
  enum {
    CLASS_ID = 0x96a18d5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_file#0x96a18d5";
  }

  int32_t mtime() const { return mtime_; } 
  void set_mtime(int32_t v) { mtime_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  std::unique_ptr<storage_FileType> type_;
  int32_t mtime_;
  std::string bytes_;
};

// upload.fileCdnRedirect#1508485a dc_id:int file_token:bytes encryption_key:bytes encryption_iv:bytes = upload.File;
class TL_upload_fileCdnRedirect : public upload_File {
public:
  enum {
    CLASS_ID = 0x1508485a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_fileCdnRedirect#0x1508485a";
  }

  int32_t dc_id() const { return dc_id_; } 
  void set_dc_id(int32_t v) { dc_id_ = v; } 

  std::string* mutable_file_token() { return &file_token_; } 
  const std::string& file_token() const { return file_token_; } 
  void set_file_token(const std::string& v) { file_token_ = v; } 
  void set_file_token(const char* v, size_t n) { file_token_.assign(v, n); } 
  void set_file_token(const char* v) { file_token_ = v; } 

  std::string* mutable_encryption_key() { return &encryption_key_; } 
  const std::string& encryption_key() const { return encryption_key_; } 
  void set_encryption_key(const std::string& v) { encryption_key_ = v; } 
  void set_encryption_key(const char* v, size_t n) { encryption_key_.assign(v, n); } 
  void set_encryption_key(const char* v) { encryption_key_ = v; } 

  std::string* mutable_encryption_iv() { return &encryption_iv_; } 
  const std::string& encryption_iv() const { return encryption_iv_; } 
  void set_encryption_iv(const std::string& v) { encryption_iv_ = v; } 
  void set_encryption_iv(const char* v, size_t n) { encryption_iv_.assign(v, n); } 
  void set_encryption_iv(const char* v) { encryption_iv_ = v; } 

private:
  int32_t dc_id_;
  std::string file_token_;
  std::string encryption_key_;
  std::string encryption_iv_;
};

// dcOption#5d8c6cc flags:# ipv6:flags.0?true media_only:flags.1?true tcpo_only:flags.2?true cdn:flags.3?true id:int ip_address:string port:int = DcOption;
class TL_dcOption : public DcOption {
public:
  enum {
    CLASS_ID = 0x5d8c6cc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "dcOption#0x5d8c6cc";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_ip_address() { return &ip_address_; } 
  const std::string& ip_address() const { return ip_address_; } 
  void set_ip_address(const std::string& v) { ip_address_ = v; } 
  void set_ip_address(const char* v, size_t n) { ip_address_.assign(v, n); } 
  void set_ip_address(const char* v) { ip_address_ = v; } 

  int32_t port() const { return port_; } 
  void set_port(int32_t v) { port_ = v; } 

private:
  int32_t flags_;
  bool ipv6_ {false};
  bool media_only_ {false};
  bool tcpo_only_ {false};
  bool cdn_ {false};
  int32_t id_;
  std::string ip_address_;
  int32_t port_;
};

// config#cb601684 flags:# phonecalls_enabled:flags.1?true date:int expires:int test_mode:Bool this_dc:int dc_options:Vector<DcOption> chat_size_max:int megagroup_size_max:int forwarded_count_max:int online_update_period_ms:int offline_blur_timeout_ms:int offline_idle_timeout_ms:int online_cloud_timeout_ms:int notify_cloud_delay_ms:int notify_default_delay_ms:int chat_big_size:int push_chat_period_ms:int push_chat_limit:int saved_gifs_limit:int edit_time_limit:int rating_e_decay:int stickers_recent_limit:int tmp_sessions:flags.0?int pinned_dialogs_count_max:int call_receive_timeout_ms:int call_ring_timeout_ms:int call_connect_timeout_ms:int call_packet_timeout_ms:int me_url_prefix:string disabled_features:Vector<DisabledFeature> = Config;
class TL_config : public Config {
public:
  enum {
    CLASS_ID = 0xcb601684
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "config#0xcb601684";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t expires() const { return expires_; } 
  void set_expires(int32_t v) { expires_ = v; } 

  int32_t this_dc() const { return this_dc_; } 
  void set_this_dc(int32_t v) { this_dc_ = v; } 

  int32_t chat_size_max() const { return chat_size_max_; } 
  void set_chat_size_max(int32_t v) { chat_size_max_ = v; } 

  int32_t megagroup_size_max() const { return megagroup_size_max_; } 
  void set_megagroup_size_max(int32_t v) { megagroup_size_max_ = v; } 

  int32_t forwarded_count_max() const { return forwarded_count_max_; } 
  void set_forwarded_count_max(int32_t v) { forwarded_count_max_ = v; } 

  int32_t online_update_period_ms() const { return online_update_period_ms_; } 
  void set_online_update_period_ms(int32_t v) { online_update_period_ms_ = v; } 

  int32_t offline_blur_timeout_ms() const { return offline_blur_timeout_ms_; } 
  void set_offline_blur_timeout_ms(int32_t v) { offline_blur_timeout_ms_ = v; } 

  int32_t offline_idle_timeout_ms() const { return offline_idle_timeout_ms_; } 
  void set_offline_idle_timeout_ms(int32_t v) { offline_idle_timeout_ms_ = v; } 

  int32_t online_cloud_timeout_ms() const { return online_cloud_timeout_ms_; } 
  void set_online_cloud_timeout_ms(int32_t v) { online_cloud_timeout_ms_ = v; } 

  int32_t notify_cloud_delay_ms() const { return notify_cloud_delay_ms_; } 
  void set_notify_cloud_delay_ms(int32_t v) { notify_cloud_delay_ms_ = v; } 

  int32_t notify_default_delay_ms() const { return notify_default_delay_ms_; } 
  void set_notify_default_delay_ms(int32_t v) { notify_default_delay_ms_ = v; } 

  int32_t chat_big_size() const { return chat_big_size_; } 
  void set_chat_big_size(int32_t v) { chat_big_size_ = v; } 

  int32_t push_chat_period_ms() const { return push_chat_period_ms_; } 
  void set_push_chat_period_ms(int32_t v) { push_chat_period_ms_ = v; } 

  int32_t push_chat_limit() const { return push_chat_limit_; } 
  void set_push_chat_limit(int32_t v) { push_chat_limit_ = v; } 

  int32_t saved_gifs_limit() const { return saved_gifs_limit_; } 
  void set_saved_gifs_limit(int32_t v) { saved_gifs_limit_ = v; } 

  int32_t edit_time_limit() const { return edit_time_limit_; } 
  void set_edit_time_limit(int32_t v) { edit_time_limit_ = v; } 

  int32_t rating_e_decay() const { return rating_e_decay_; } 
  void set_rating_e_decay(int32_t v) { rating_e_decay_ = v; } 

  int32_t stickers_recent_limit() const { return stickers_recent_limit_; } 
  void set_stickers_recent_limit(int32_t v) { stickers_recent_limit_ = v; } 

  int32_t tmp_sessions() const { return tmp_sessions_; } 
  void set_tmp_sessions(int32_t v) { tmp_sessions_ = v; } 

  int32_t pinned_dialogs_count_max() const { return pinned_dialogs_count_max_; } 
  void set_pinned_dialogs_count_max(int32_t v) { pinned_dialogs_count_max_ = v; } 

  int32_t call_receive_timeout_ms() const { return call_receive_timeout_ms_; } 
  void set_call_receive_timeout_ms(int32_t v) { call_receive_timeout_ms_ = v; } 

  int32_t call_ring_timeout_ms() const { return call_ring_timeout_ms_; } 
  void set_call_ring_timeout_ms(int32_t v) { call_ring_timeout_ms_ = v; } 

  int32_t call_connect_timeout_ms() const { return call_connect_timeout_ms_; } 
  void set_call_connect_timeout_ms(int32_t v) { call_connect_timeout_ms_ = v; } 

  int32_t call_packet_timeout_ms() const { return call_packet_timeout_ms_; } 
  void set_call_packet_timeout_ms(int32_t v) { call_packet_timeout_ms_ = v; } 

  std::string* mutable_me_url_prefix() { return &me_url_prefix_; } 
  const std::string& me_url_prefix() const { return me_url_prefix_; } 
  void set_me_url_prefix(const std::string& v) { me_url_prefix_ = v; } 
  void set_me_url_prefix(const char* v, size_t n) { me_url_prefix_.assign(v, n); } 
  void set_me_url_prefix(const char* v) { me_url_prefix_ = v; } 

private:
  int32_t flags_;
  bool phonecalls_enabled_ {false};
  int32_t date_;
  int32_t expires_;
  std::unique_ptr<Bool> test_mode_;
  int32_t this_dc_;
  TLObjectVector<DcOption> dc_options_;
  int32_t chat_size_max_;
  int32_t megagroup_size_max_;
  int32_t forwarded_count_max_;
  int32_t online_update_period_ms_;
  int32_t offline_blur_timeout_ms_;
  int32_t offline_idle_timeout_ms_;
  int32_t online_cloud_timeout_ms_;
  int32_t notify_cloud_delay_ms_;
  int32_t notify_default_delay_ms_;
  int32_t chat_big_size_;
  int32_t push_chat_period_ms_;
  int32_t push_chat_limit_;
  int32_t saved_gifs_limit_;
  int32_t edit_time_limit_;
  int32_t rating_e_decay_;
  int32_t stickers_recent_limit_;
  int32_t tmp_sessions_;
  int32_t pinned_dialogs_count_max_;
  int32_t call_receive_timeout_ms_;
  int32_t call_ring_timeout_ms_;
  int32_t call_connect_timeout_ms_;
  int32_t call_packet_timeout_ms_;
  std::string me_url_prefix_;
  TLObjectVector<DisabledFeature> disabled_features_;
};

// nearestDc#8e1a1775 country:string this_dc:int nearest_dc:int = NearestDc;
class TL_nearestDc : public NearestDc {
public:
  enum {
    CLASS_ID = 0x8e1a1775
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "nearestDc#0x8e1a1775";
  }

  std::string* mutable_country() { return &country_; } 
  const std::string& country() const { return country_; } 
  void set_country(const std::string& v) { country_ = v; } 
  void set_country(const char* v, size_t n) { country_.assign(v, n); } 
  void set_country(const char* v) { country_ = v; } 

  int32_t this_dc() const { return this_dc_; } 
  void set_this_dc(int32_t v) { this_dc_ = v; } 

  int32_t nearest_dc() const { return nearest_dc_; } 
  void set_nearest_dc(int32_t v) { nearest_dc_ = v; } 

private:
  std::string country_;
  int32_t this_dc_;
  int32_t nearest_dc_;
};

// help.appUpdate#8987f311 id:int critical:Bool url:string text:string = help.AppUpdate;
class TL_help_appUpdate : public help_AppUpdate {
public:
  enum {
    CLASS_ID = 0x8987f311
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_appUpdate#0x8987f311";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  int32_t id_;
  std::unique_ptr<Bool> critical_;
  std::string url_;
  std::string text_;
};

// help.noAppUpdate#c45a6536 = help.AppUpdate;
class TL_help_noAppUpdate : public help_AppUpdate {
public:
  enum {
    CLASS_ID = 0xc45a6536
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_noAppUpdate#0xc45a6536";
  }

private:
};

// help.inviteText#18cb9f78 message:string = help.InviteText;
class TL_help_inviteText : public help_InviteText {
public:
  enum {
    CLASS_ID = 0x18cb9f78
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_inviteText#0x18cb9f78";
  }

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  std::string message_;
};

// encryptedChatEmpty#ab7ec0a0 id:int = EncryptedChat;
class TL_encryptedChatEmpty : public EncryptedChat {
public:
  enum {
    CLASS_ID = 0xab7ec0a0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedChatEmpty#0xab7ec0a0";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  int32_t id_;
};

// encryptedChatWaiting#3bf703dc id:int access_hash:long date:int admin_id:int participant_id:int = EncryptedChat;
class TL_encryptedChatWaiting : public EncryptedChat {
public:
  enum {
    CLASS_ID = 0x3bf703dc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedChatWaiting#0x3bf703dc";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t admin_id() const { return admin_id_; } 
  void set_admin_id(int32_t v) { admin_id_ = v; } 

  int32_t participant_id() const { return participant_id_; } 
  void set_participant_id(int32_t v) { participant_id_ = v; } 

private:
  int32_t id_;
  int64_t access_hash_;
  int32_t date_;
  int32_t admin_id_;
  int32_t participant_id_;
};

// encryptedChatRequested#c878527e id:int access_hash:long date:int admin_id:int participant_id:int g_a:bytes = EncryptedChat;
class TL_encryptedChatRequested : public EncryptedChat {
public:
  enum {
    CLASS_ID = 0xc878527e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedChatRequested#0xc878527e";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t admin_id() const { return admin_id_; } 
  void set_admin_id(int32_t v) { admin_id_ = v; } 

  int32_t participant_id() const { return participant_id_; } 
  void set_participant_id(int32_t v) { participant_id_ = v; } 

  std::string* mutable_g_a() { return &g_a_; } 
  const std::string& g_a() const { return g_a_; } 
  void set_g_a(const std::string& v) { g_a_ = v; } 
  void set_g_a(const char* v, size_t n) { g_a_.assign(v, n); } 
  void set_g_a(const char* v) { g_a_ = v; } 

private:
  int32_t id_;
  int64_t access_hash_;
  int32_t date_;
  int32_t admin_id_;
  int32_t participant_id_;
  std::string g_a_;
};

// encryptedChat#fa56ce36 id:int access_hash:long date:int admin_id:int participant_id:int g_a_or_b:bytes key_fingerprint:long = EncryptedChat;
class TL_encryptedChat : public EncryptedChat {
public:
  enum {
    CLASS_ID = 0xfa56ce36
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedChat#0xfa56ce36";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t admin_id() const { return admin_id_; } 
  void set_admin_id(int32_t v) { admin_id_ = v; } 

  int32_t participant_id() const { return participant_id_; } 
  void set_participant_id(int32_t v) { participant_id_ = v; } 

  std::string* mutable_g_a_or_b() { return &g_a_or_b_; } 
  const std::string& g_a_or_b() const { return g_a_or_b_; } 
  void set_g_a_or_b(const std::string& v) { g_a_or_b_ = v; } 
  void set_g_a_or_b(const char* v, size_t n) { g_a_or_b_.assign(v, n); } 
  void set_g_a_or_b(const char* v) { g_a_or_b_ = v; } 

  int64_t key_fingerprint() const { return key_fingerprint_; } 
  void set_key_fingerprint(int64_t v) { key_fingerprint_ = v; } 

private:
  int32_t id_;
  int64_t access_hash_;
  int32_t date_;
  int32_t admin_id_;
  int32_t participant_id_;
  std::string g_a_or_b_;
  int64_t key_fingerprint_;
};

// encryptedChatDiscarded#13d6dd27 id:int = EncryptedChat;
class TL_encryptedChatDiscarded : public EncryptedChat {
public:
  enum {
    CLASS_ID = 0x13d6dd27
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedChatDiscarded#0x13d6dd27";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  int32_t id_;
};

// inputEncryptedChat#f141b5e1 chat_id:int access_hash:long = InputEncryptedChat;
class TL_inputEncryptedChat : public InputEncryptedChat {
public:
  enum {
    CLASS_ID = 0xf141b5e1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputEncryptedChat#0xf141b5e1";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int32_t chat_id_;
  int64_t access_hash_;
};

// encryptedFileEmpty#c21f497e = EncryptedFile;
class TL_encryptedFileEmpty : public EncryptedFile {
public:
  enum {
    CLASS_ID = 0xc21f497e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedFileEmpty#0xc21f497e";
  }

private:
};

// encryptedFile#4a70994c id:long access_hash:long size:int dc_id:int key_fingerprint:int = EncryptedFile;
class TL_encryptedFile : public EncryptedFile {
public:
  enum {
    CLASS_ID = 0x4a70994c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedFile#0x4a70994c";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t size() const { return size_; } 
  void set_size(int32_t v) { size_ = v; } 

  int32_t dc_id() const { return dc_id_; } 
  void set_dc_id(int32_t v) { dc_id_ = v; } 

  int32_t key_fingerprint() const { return key_fingerprint_; } 
  void set_key_fingerprint(int32_t v) { key_fingerprint_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
  int32_t size_;
  int32_t dc_id_;
  int32_t key_fingerprint_;
};

// inputEncryptedFileEmpty#1837c364 = InputEncryptedFile;
class TL_inputEncryptedFileEmpty : public InputEncryptedFile {
public:
  enum {
    CLASS_ID = 0x1837c364
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputEncryptedFileEmpty#0x1837c364";
  }

private:
};

// inputEncryptedFileUploaded#64bd0306 id:long parts:int md5_checksum:string key_fingerprint:int = InputEncryptedFile;
class TL_inputEncryptedFileUploaded : public InputEncryptedFile {
public:
  enum {
    CLASS_ID = 0x64bd0306
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputEncryptedFileUploaded#0x64bd0306";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int32_t parts() const { return parts_; } 
  void set_parts(int32_t v) { parts_ = v; } 

  std::string* mutable_md5_checksum() { return &md5_checksum_; } 
  const std::string& md5_checksum() const { return md5_checksum_; } 
  void set_md5_checksum(const std::string& v) { md5_checksum_ = v; } 
  void set_md5_checksum(const char* v, size_t n) { md5_checksum_.assign(v, n); } 
  void set_md5_checksum(const char* v) { md5_checksum_ = v; } 

  int32_t key_fingerprint() const { return key_fingerprint_; } 
  void set_key_fingerprint(int32_t v) { key_fingerprint_ = v; } 

private:
  int64_t id_;
  int32_t parts_;
  std::string md5_checksum_;
  int32_t key_fingerprint_;
};

// inputEncryptedFile#5a17b5e5 id:long access_hash:long = InputEncryptedFile;
class TL_inputEncryptedFile : public InputEncryptedFile {
public:
  enum {
    CLASS_ID = 0x5a17b5e5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputEncryptedFile#0x5a17b5e5";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
};

// inputEncryptedFileBigUploaded#2dc173c8 id:long parts:int key_fingerprint:int = InputEncryptedFile;
class TL_inputEncryptedFileBigUploaded : public InputEncryptedFile {
public:
  enum {
    CLASS_ID = 0x2dc173c8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputEncryptedFileBigUploaded#0x2dc173c8";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int32_t parts() const { return parts_; } 
  void set_parts(int32_t v) { parts_ = v; } 

  int32_t key_fingerprint() const { return key_fingerprint_; } 
  void set_key_fingerprint(int32_t v) { key_fingerprint_ = v; } 

private:
  int64_t id_;
  int32_t parts_;
  int32_t key_fingerprint_;
};

// encryptedMessage#ed18c118 random_id:long chat_id:int date:int bytes:bytes file:EncryptedFile = EncryptedMessage;
class TL_encryptedMessage : public EncryptedMessage {
public:
  enum {
    CLASS_ID = 0xed18c118
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedMessage#0xed18c118";
  }

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  int64_t random_id_;
  int32_t chat_id_;
  int32_t date_;
  std::string bytes_;
  std::unique_ptr<EncryptedFile> file_;
};

// encryptedMessageService#23734b06 random_id:long chat_id:int date:int bytes:bytes = EncryptedMessage;
class TL_encryptedMessageService : public EncryptedMessage {
public:
  enum {
    CLASS_ID = 0x23734b06
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "encryptedMessageService#0x23734b06";
  }

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  int64_t random_id_;
  int32_t chat_id_;
  int32_t date_;
  std::string bytes_;
};

// messages.dhConfigNotModified#c0e24635 random:bytes = messages.DhConfig;
class TL_messages_dhConfigNotModified : public messages_DhConfig {
public:
  enum {
    CLASS_ID = 0xc0e24635
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_dhConfigNotModified#0xc0e24635";
  }

  std::string* mutable_random() { return &random_; } 
  const std::string& random() const { return random_; } 
  void set_random(const std::string& v) { random_ = v; } 
  void set_random(const char* v, size_t n) { random_.assign(v, n); } 
  void set_random(const char* v) { random_ = v; } 

private:
  std::string random_;
};

// messages.dhConfig#2c221edd g:int p:bytes version:int random:bytes = messages.DhConfig;
class TL_messages_dhConfig : public messages_DhConfig {
public:
  enum {
    CLASS_ID = 0x2c221edd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_dhConfig#0x2c221edd";
  }

  int32_t g() const { return g_; } 
  void set_g(int32_t v) { g_ = v; } 

  std::string* mutable_p() { return &p_; } 
  const std::string& p() const { return p_; } 
  void set_p(const std::string& v) { p_ = v; } 
  void set_p(const char* v, size_t n) { p_.assign(v, n); } 
  void set_p(const char* v) { p_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

  std::string* mutable_random() { return &random_; } 
  const std::string& random() const { return random_; } 
  void set_random(const std::string& v) { random_ = v; } 
  void set_random(const char* v, size_t n) { random_.assign(v, n); } 
  void set_random(const char* v) { random_ = v; } 

private:
  int32_t g_;
  std::string p_;
  int32_t version_;
  std::string random_;
};

// messages.sentEncryptedMessage#560f8935 date:int = messages.SentEncryptedMessage;
class TL_messages_sentEncryptedMessage : public messages_SentEncryptedMessage {
public:
  enum {
    CLASS_ID = 0x560f8935
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_sentEncryptedMessage#0x560f8935";
  }

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t date_;
};

// messages.sentEncryptedFile#9493ff32 date:int file:EncryptedFile = messages.SentEncryptedMessage;
class TL_messages_sentEncryptedFile : public messages_SentEncryptedMessage {
public:
  enum {
    CLASS_ID = 0x9493ff32
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_sentEncryptedFile#0x9493ff32";
  }

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t date_;
  std::unique_ptr<EncryptedFile> file_;
};

// inputDocumentEmpty#72f0eaae = InputDocument;
class TL_inputDocumentEmpty : public InputDocument {
public:
  enum {
    CLASS_ID = 0x72f0eaae
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputDocumentEmpty#0x72f0eaae";
  }

private:
};

// inputDocument#18798952 id:long access_hash:long = InputDocument;
class TL_inputDocument : public InputDocument {
public:
  enum {
    CLASS_ID = 0x18798952
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputDocument#0x18798952";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
};

// documentEmpty#36f8c871 id:long = Document;
class TL_documentEmpty : public Document {
public:
  enum {
    CLASS_ID = 0x36f8c871
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "documentEmpty#0x36f8c871";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

private:
  int64_t id_;
};

// document#87232bc7 id:long access_hash:long date:int mime_type:string size:int thumb:PhotoSize dc_id:int version:int attributes:Vector<DocumentAttribute> = Document;
class TL_document : public Document {
public:
  enum {
    CLASS_ID = 0x87232bc7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "document#0x87232bc7";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  std::string* mutable_mime_type() { return &mime_type_; } 
  const std::string& mime_type() const { return mime_type_; } 
  void set_mime_type(const std::string& v) { mime_type_ = v; } 
  void set_mime_type(const char* v, size_t n) { mime_type_.assign(v, n); } 
  void set_mime_type(const char* v) { mime_type_ = v; } 

  int32_t size() const { return size_; } 
  void set_size(int32_t v) { size_ = v; } 

  int32_t dc_id() const { return dc_id_; } 
  void set_dc_id(int32_t v) { dc_id_ = v; } 

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
  int32_t date_;
  std::string mime_type_;
  int32_t size_;
  std::unique_ptr<PhotoSize> thumb_;
  int32_t dc_id_;
  int32_t version_;
  TLObjectVector<DocumentAttribute> attributes_;
};

// help.support#17c6b5f6 phone_number:string user:User = help.Support;
class TL_help_support : public help_Support {
public:
  enum {
    CLASS_ID = 0x17c6b5f6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_support#0x17c6b5f6";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

private:
  std::string phone_number_;
  std::unique_ptr<User> user_;
};

// notifyPeer#9fd40bd8 peer:Peer = NotifyPeer;
class TL_notifyPeer : public NotifyPeer {
public:
  enum {
    CLASS_ID = 0x9fd40bd8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "notifyPeer#0x9fd40bd8";
  }

private:
  std::unique_ptr<Peer> peer_;
};

// notifyUsers#b4c83b4c = NotifyPeer;
class TL_notifyUsers : public NotifyPeer {
public:
  enum {
    CLASS_ID = 0xb4c83b4c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "notifyUsers#0xb4c83b4c";
  }

private:
};

// notifyChats#c007cec3 = NotifyPeer;
class TL_notifyChats : public NotifyPeer {
public:
  enum {
    CLASS_ID = 0xc007cec3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "notifyChats#0xc007cec3";
  }

private:
};

// notifyAll#74d07c60 = NotifyPeer;
class TL_notifyAll : public NotifyPeer {
public:
  enum {
    CLASS_ID = 0x74d07c60
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "notifyAll#0x74d07c60";
  }

private:
};

// sendMessageTypingAction#16bf744e = SendMessageAction;
class TL_sendMessageTypingAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0x16bf744e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageTypingAction#0x16bf744e";
  }

private:
};

// sendMessageCancelAction#fd5ec8f5 = SendMessageAction;
class TL_sendMessageCancelAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0xfd5ec8f5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageCancelAction#0xfd5ec8f5";
  }

private:
};

// sendMessageRecordVideoAction#a187d66f = SendMessageAction;
class TL_sendMessageRecordVideoAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0xa187d66f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageRecordVideoAction#0xa187d66f";
  }

private:
};

// sendMessageUploadVideoAction#e9763aec progress:int = SendMessageAction;
class TL_sendMessageUploadVideoAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0xe9763aec
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageUploadVideoAction#0xe9763aec";
  }

  int32_t progress() const { return progress_; } 
  void set_progress(int32_t v) { progress_ = v; } 

private:
  int32_t progress_;
};

// sendMessageRecordAudioAction#d52f73f7 = SendMessageAction;
class TL_sendMessageRecordAudioAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0xd52f73f7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageRecordAudioAction#0xd52f73f7";
  }

private:
};

// sendMessageUploadAudioAction#f351d7ab progress:int = SendMessageAction;
class TL_sendMessageUploadAudioAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0xf351d7ab
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageUploadAudioAction#0xf351d7ab";
  }

  int32_t progress() const { return progress_; } 
  void set_progress(int32_t v) { progress_ = v; } 

private:
  int32_t progress_;
};

// sendMessageUploadPhotoAction#d1d34a26 progress:int = SendMessageAction;
class TL_sendMessageUploadPhotoAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0xd1d34a26
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageUploadPhotoAction#0xd1d34a26";
  }

  int32_t progress() const { return progress_; } 
  void set_progress(int32_t v) { progress_ = v; } 

private:
  int32_t progress_;
};

// sendMessageUploadDocumentAction#aa0cd9e4 progress:int = SendMessageAction;
class TL_sendMessageUploadDocumentAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0xaa0cd9e4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageUploadDocumentAction#0xaa0cd9e4";
  }

  int32_t progress() const { return progress_; } 
  void set_progress(int32_t v) { progress_ = v; } 

private:
  int32_t progress_;
};

// sendMessageGeoLocationAction#176f8ba1 = SendMessageAction;
class TL_sendMessageGeoLocationAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0x176f8ba1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageGeoLocationAction#0x176f8ba1";
  }

private:
};

// sendMessageChooseContactAction#628cbc6f = SendMessageAction;
class TL_sendMessageChooseContactAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0x628cbc6f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageChooseContactAction#0x628cbc6f";
  }

private:
};

// sendMessageGamePlayAction#dd6a8f48 = SendMessageAction;
class TL_sendMessageGamePlayAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0xdd6a8f48
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageGamePlayAction#0xdd6a8f48";
  }

private:
};

// sendMessageRecordRoundAction#88f27fbc = SendMessageAction;
class TL_sendMessageRecordRoundAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0x88f27fbc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageRecordRoundAction#0x88f27fbc";
  }

private:
};

// sendMessageUploadRoundAction#243e1c66 progress:int = SendMessageAction;
class TL_sendMessageUploadRoundAction : public SendMessageAction {
public:
  enum {
    CLASS_ID = 0x243e1c66
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "sendMessageUploadRoundAction#0x243e1c66";
  }

  int32_t progress() const { return progress_; } 
  void set_progress(int32_t v) { progress_ = v; } 

private:
  int32_t progress_;
};

// contacts.found#1aa1f784 results:Vector<Peer> chats:Vector<Chat> users:Vector<User> = contacts.Found;
class TL_contacts_found : public contacts_Found {
public:
  enum {
    CLASS_ID = 0x1aa1f784
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_found#0x1aa1f784";
  }

private:
  TLObjectVector<Peer> results_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// inputPrivacyKeyStatusTimestamp#4f96cb18 = InputPrivacyKey;
class TL_inputPrivacyKeyStatusTimestamp : public InputPrivacyKey {
public:
  enum {
    CLASS_ID = 0x4f96cb18
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyKeyStatusTimestamp#0x4f96cb18";
  }

private:
};

// inputPrivacyKeyChatInvite#bdfb0426 = InputPrivacyKey;
class TL_inputPrivacyKeyChatInvite : public InputPrivacyKey {
public:
  enum {
    CLASS_ID = 0xbdfb0426
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyKeyChatInvite#0xbdfb0426";
  }

private:
};

// inputPrivacyKeyPhoneCall#fabadc5f = InputPrivacyKey;
class TL_inputPrivacyKeyPhoneCall : public InputPrivacyKey {
public:
  enum {
    CLASS_ID = 0xfabadc5f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyKeyPhoneCall#0xfabadc5f";
  }

private:
};

// privacyKeyStatusTimestamp#bc2eab30 = PrivacyKey;
class TL_privacyKeyStatusTimestamp : public PrivacyKey {
public:
  enum {
    CLASS_ID = 0xbc2eab30
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyKeyStatusTimestamp#0xbc2eab30";
  }

private:
};

// privacyKeyChatInvite#500e6dfa = PrivacyKey;
class TL_privacyKeyChatInvite : public PrivacyKey {
public:
  enum {
    CLASS_ID = 0x500e6dfa
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyKeyChatInvite#0x500e6dfa";
  }

private:
};

// privacyKeyPhoneCall#3d662b7b = PrivacyKey;
class TL_privacyKeyPhoneCall : public PrivacyKey {
public:
  enum {
    CLASS_ID = 0x3d662b7b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyKeyPhoneCall#0x3d662b7b";
  }

private:
};

// inputPrivacyValueAllowContacts#d09e07b = InputPrivacyRule;
class TL_inputPrivacyValueAllowContacts : public InputPrivacyRule {
public:
  enum {
    CLASS_ID = 0xd09e07b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyValueAllowContacts#0xd09e07b";
  }

private:
};

// inputPrivacyValueAllowAll#184b35ce = InputPrivacyRule;
class TL_inputPrivacyValueAllowAll : public InputPrivacyRule {
public:
  enum {
    CLASS_ID = 0x184b35ce
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyValueAllowAll#0x184b35ce";
  }

private:
};

// inputPrivacyValueAllowUsers#131cc67f users:Vector<InputUser> = InputPrivacyRule;
class TL_inputPrivacyValueAllowUsers : public InputPrivacyRule {
public:
  enum {
    CLASS_ID = 0x131cc67f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyValueAllowUsers#0x131cc67f";
  }

private:
  TLObjectVector<InputUser> users_;
};

// inputPrivacyValueDisallowContacts#ba52007 = InputPrivacyRule;
class TL_inputPrivacyValueDisallowContacts : public InputPrivacyRule {
public:
  enum {
    CLASS_ID = 0xba52007
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyValueDisallowContacts#0xba52007";
  }

private:
};

// inputPrivacyValueDisallowAll#d66b66c9 = InputPrivacyRule;
class TL_inputPrivacyValueDisallowAll : public InputPrivacyRule {
public:
  enum {
    CLASS_ID = 0xd66b66c9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyValueDisallowAll#0xd66b66c9";
  }

private:
};

// inputPrivacyValueDisallowUsers#90110467 users:Vector<InputUser> = InputPrivacyRule;
class TL_inputPrivacyValueDisallowUsers : public InputPrivacyRule {
public:
  enum {
    CLASS_ID = 0x90110467
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPrivacyValueDisallowUsers#0x90110467";
  }

private:
  TLObjectVector<InputUser> users_;
};

// privacyValueAllowContacts#fffe1bac = PrivacyRule;
class TL_privacyValueAllowContacts : public PrivacyRule {
public:
  enum {
    CLASS_ID = 0xfffe1bac
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyValueAllowContacts#0xfffe1bac";
  }

private:
};

// privacyValueAllowAll#65427b82 = PrivacyRule;
class TL_privacyValueAllowAll : public PrivacyRule {
public:
  enum {
    CLASS_ID = 0x65427b82
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyValueAllowAll#0x65427b82";
  }

private:
};

// privacyValueAllowUsers#4d5bbe0c users:Vector<int> = PrivacyRule;
class TL_privacyValueAllowUsers : public PrivacyRule {
public:
  enum {
    CLASS_ID = 0x4d5bbe0c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyValueAllowUsers#0x4d5bbe0c";
  }

  size_t users_size() const { return users_.size(); } 
  const TLInt32Vector& users() const { return users_; } 
  int32_t users(int idx) const { return users_.vector()[idx]; } 
  void add_users(int32_t v) {users_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_users() { return &users_; } 

private:
  TLInt32Vector users_;
};

// privacyValueDisallowContacts#f888fa1a = PrivacyRule;
class TL_privacyValueDisallowContacts : public PrivacyRule {
public:
  enum {
    CLASS_ID = 0xf888fa1a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyValueDisallowContacts#0xf888fa1a";
  }

private:
};

// privacyValueDisallowAll#8b73e763 = PrivacyRule;
class TL_privacyValueDisallowAll : public PrivacyRule {
public:
  enum {
    CLASS_ID = 0x8b73e763
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyValueDisallowAll#0x8b73e763";
  }

private:
};

// privacyValueDisallowUsers#c7f49b7 users:Vector<int> = PrivacyRule;
class TL_privacyValueDisallowUsers : public PrivacyRule {
public:
  enum {
    CLASS_ID = 0xc7f49b7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "privacyValueDisallowUsers#0xc7f49b7";
  }

  size_t users_size() const { return users_.size(); } 
  const TLInt32Vector& users() const { return users_; } 
  int32_t users(int idx) const { return users_.vector()[idx]; } 
  void add_users(int32_t v) {users_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_users() { return &users_; } 

private:
  TLInt32Vector users_;
};

// account.privacyRules#554abb6f rules:Vector<PrivacyRule> users:Vector<User> = account.PrivacyRules;
class TL_account_privacyRules : public account_PrivacyRules {
public:
  enum {
    CLASS_ID = 0x554abb6f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_privacyRules#0x554abb6f";
  }

private:
  TLObjectVector<PrivacyRule> rules_;
  TLObjectVector<User> users_;
};

// accountDaysTTL#b8d0afdf days:int = AccountDaysTTL;
class TL_accountDaysTTL : public AccountDaysTTL {
public:
  enum {
    CLASS_ID = 0xb8d0afdf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "accountDaysTTL#0xb8d0afdf";
  }

  int32_t days() const { return days_; } 
  void set_days(int32_t v) { days_ = v; } 

private:
  int32_t days_;
};

// documentAttributeImageSize#6c37c15c w:int h:int = DocumentAttribute;
class TL_documentAttributeImageSize : public DocumentAttribute {
public:
  enum {
    CLASS_ID = 0x6c37c15c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "documentAttributeImageSize#0x6c37c15c";
  }

  int32_t w() const { return w_; } 
  void set_w(int32_t v) { w_ = v; } 

  int32_t h() const { return h_; } 
  void set_h(int32_t v) { h_ = v; } 

private:
  int32_t w_;
  int32_t h_;
};

// documentAttributeAnimated#11b58939 = DocumentAttribute;
class TL_documentAttributeAnimated : public DocumentAttribute {
public:
  enum {
    CLASS_ID = 0x11b58939
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "documentAttributeAnimated#0x11b58939";
  }

private:
};

// documentAttributeSticker#6319d612 flags:# mask:flags.1?true alt:string stickerset:InputStickerSet mask_coords:flags.0?MaskCoords = DocumentAttribute;
class TL_documentAttributeSticker : public DocumentAttribute {
public:
  enum {
    CLASS_ID = 0x6319d612
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "documentAttributeSticker#0x6319d612";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_alt() { return &alt_; } 
  const std::string& alt() const { return alt_; } 
  void set_alt(const std::string& v) { alt_ = v; } 
  void set_alt(const char* v, size_t n) { alt_.assign(v, n); } 
  void set_alt(const char* v) { alt_ = v; } 

private:
  int32_t flags_;
  bool mask_ {false};
  std::string alt_;
  std::unique_ptr<InputStickerSet> stickerset_;
  std::unique_ptr<MaskCoords> mask_coords_;
};

// documentAttributeVideo#ef02ce6 flags:# round_message:flags.0?true duration:int w:int h:int = DocumentAttribute;
class TL_documentAttributeVideo : public DocumentAttribute {
public:
  enum {
    CLASS_ID = 0xef02ce6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "documentAttributeVideo#0xef02ce6";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t duration() const { return duration_; } 
  void set_duration(int32_t v) { duration_ = v; } 

  int32_t w() const { return w_; } 
  void set_w(int32_t v) { w_ = v; } 

  int32_t h() const { return h_; } 
  void set_h(int32_t v) { h_ = v; } 

private:
  int32_t flags_;
  bool round_message_ {false};
  int32_t duration_;
  int32_t w_;
  int32_t h_;
};

// documentAttributeAudio#9852f9c6 flags:# voice:flags.10?true duration:int title:flags.0?string performer:flags.1?string waveform:flags.2?bytes = DocumentAttribute;
class TL_documentAttributeAudio : public DocumentAttribute {
public:
  enum {
    CLASS_ID = 0x9852f9c6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "documentAttributeAudio#0x9852f9c6";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t duration() const { return duration_; } 
  void set_duration(int32_t v) { duration_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_performer() { return &performer_; } 
  const std::string& performer() const { return performer_; } 
  void set_performer(const std::string& v) { performer_ = v; } 
  void set_performer(const char* v, size_t n) { performer_.assign(v, n); } 
  void set_performer(const char* v) { performer_ = v; } 

  std::string* mutable_waveform() { return &waveform_; } 
  const std::string& waveform() const { return waveform_; } 
  void set_waveform(const std::string& v) { waveform_ = v; } 
  void set_waveform(const char* v, size_t n) { waveform_.assign(v, n); } 
  void set_waveform(const char* v) { waveform_ = v; } 

private:
  int32_t flags_;
  bool voice_ {false};
  int32_t duration_;
  std::string title_;
  std::string performer_;
  std::string waveform_;
};

// documentAttributeFilename#15590068 file_name:string = DocumentAttribute;
class TL_documentAttributeFilename : public DocumentAttribute {
public:
  enum {
    CLASS_ID = 0x15590068
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "documentAttributeFilename#0x15590068";
  }

  std::string* mutable_file_name() { return &file_name_; } 
  const std::string& file_name() const { return file_name_; } 
  void set_file_name(const std::string& v) { file_name_ = v; } 
  void set_file_name(const char* v, size_t n) { file_name_.assign(v, n); } 
  void set_file_name(const char* v) { file_name_ = v; } 

private:
  std::string file_name_;
};

// documentAttributeHasStickers#9801d2f7 = DocumentAttribute;
class TL_documentAttributeHasStickers : public DocumentAttribute {
public:
  enum {
    CLASS_ID = 0x9801d2f7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "documentAttributeHasStickers#0x9801d2f7";
  }

private:
};

// messages.stickersNotModified#f1749a22 = messages.Stickers;
class TL_messages_stickersNotModified : public messages_Stickers {
public:
  enum {
    CLASS_ID = 0xf1749a22
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_stickersNotModified#0xf1749a22";
  }

private:
};

// messages.stickers#8a8ecd32 hash:string stickers:Vector<Document> = messages.Stickers;
class TL_messages_stickers : public messages_Stickers {
public:
  enum {
    CLASS_ID = 0x8a8ecd32
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_stickers#0x8a8ecd32";
  }

  std::string* mutable_hash() { return &hash_; } 
  const std::string& hash() const { return hash_; } 
  void set_hash(const std::string& v) { hash_ = v; } 
  void set_hash(const char* v, size_t n) { hash_.assign(v, n); } 
  void set_hash(const char* v) { hash_ = v; } 

private:
  std::string hash_;
  TLObjectVector<Document> stickers_;
};

// stickerPack#12b299d4 emoticon:string documents:Vector<long> = StickerPack;
class TL_stickerPack : public StickerPack {
public:
  enum {
    CLASS_ID = 0x12b299d4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "stickerPack#0x12b299d4";
  }

  std::string* mutable_emoticon() { return &emoticon_; } 
  const std::string& emoticon() const { return emoticon_; } 
  void set_emoticon(const std::string& v) { emoticon_ = v; } 
  void set_emoticon(const char* v, size_t n) { emoticon_.assign(v, n); } 
  void set_emoticon(const char* v) { emoticon_ = v; } 

  size_t documents_size() const { return documents_.size(); } 
  const TLInt64Vector& documents() const { return documents_; } 
  int64_t documents(int idx) const { return documents_.vector()[idx]; } 
  void add_documents(int64_t v) {documents_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_documents() { return &documents_; } 

private:
  std::string emoticon_;
  TLInt64Vector documents_;
};

// messages.allStickersNotModified#e86602c3 = messages.AllStickers;
class TL_messages_allStickersNotModified : public messages_AllStickers {
public:
  enum {
    CLASS_ID = 0xe86602c3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_allStickersNotModified#0xe86602c3";
  }

private:
};

// messages.allStickers#edfd405f hash:int sets:Vector<StickerSet> = messages.AllStickers;
class TL_messages_allStickers : public messages_AllStickers {
public:
  enum {
    CLASS_ID = 0xedfd405f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_allStickers#0xedfd405f";
  }

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t hash_;
  TLObjectVector<StickerSet> sets_;
};

// disabledFeature#ae636f24 feature:string description:string = DisabledFeature;
class TL_disabledFeature : public DisabledFeature {
public:
  enum {
    CLASS_ID = 0xae636f24
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "disabledFeature#0xae636f24";
  }

  std::string* mutable_feature() { return &feature_; } 
  const std::string& feature() const { return feature_; } 
  void set_feature(const std::string& v) { feature_ = v; } 
  void set_feature(const char* v, size_t n) { feature_.assign(v, n); } 
  void set_feature(const char* v) { feature_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

private:
  std::string feature_;
  std::string description_;
};

// messages.affectedMessages#84d19185 pts:int pts_count:int = messages.AffectedMessages;
class TL_messages_affectedMessages : public messages_AffectedMessages {
public:
  enum {
    CLASS_ID = 0x84d19185
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_affectedMessages#0x84d19185";
  }

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_count() const { return pts_count_; } 
  void set_pts_count(int32_t v) { pts_count_ = v; } 

private:
  int32_t pts_;
  int32_t pts_count_;
};

// contactLinkUnknown#5f4f9247 = ContactLink;
class TL_contactLinkUnknown : public ContactLink {
public:
  enum {
    CLASS_ID = 0x5f4f9247
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contactLinkUnknown#0x5f4f9247";
  }

private:
};

// contactLinkNone#feedd3ad = ContactLink;
class TL_contactLinkNone : public ContactLink {
public:
  enum {
    CLASS_ID = 0xfeedd3ad
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contactLinkNone#0xfeedd3ad";
  }

private:
};

// contactLinkHasPhone#268f3f59 = ContactLink;
class TL_contactLinkHasPhone : public ContactLink {
public:
  enum {
    CLASS_ID = 0x268f3f59
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contactLinkHasPhone#0x268f3f59";
  }

private:
};

// contactLinkContact#d502c2d0 = ContactLink;
class TL_contactLinkContact : public ContactLink {
public:
  enum {
    CLASS_ID = 0xd502c2d0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contactLinkContact#0xd502c2d0";
  }

private:
};

// webPageEmpty#eb1477e8 id:long = WebPage;
class TL_webPageEmpty : public WebPage {
public:
  enum {
    CLASS_ID = 0xeb1477e8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "webPageEmpty#0xeb1477e8";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

private:
  int64_t id_;
};

// webPagePending#c586da1c id:long date:int = WebPage;
class TL_webPagePending : public WebPage {
public:
  enum {
    CLASS_ID = 0xc586da1c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "webPagePending#0xc586da1c";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int64_t id_;
  int32_t date_;
};

// webPage#5f07b4bc flags:# id:long url:string display_url:string hash:int type:flags.0?string site_name:flags.1?string title:flags.2?string description:flags.3?string photo:flags.4?Photo embed_url:flags.5?string embed_type:flags.5?string embed_width:flags.6?int embed_height:flags.6?int duration:flags.7?int author:flags.8?string document:flags.9?Document cached_page:flags.10?Page = WebPage;
class TL_webPage : public WebPage {
public:
  enum {
    CLASS_ID = 0x5f07b4bc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "webPage#0x5f07b4bc";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_display_url() { return &display_url_; } 
  const std::string& display_url() const { return display_url_; } 
  void set_display_url(const std::string& v) { display_url_ = v; } 
  void set_display_url(const char* v, size_t n) { display_url_.assign(v, n); } 
  void set_display_url(const char* v) { display_url_ = v; } 

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  std::string* mutable_site_name() { return &site_name_; } 
  const std::string& site_name() const { return site_name_; } 
  void set_site_name(const std::string& v) { site_name_ = v; } 
  void set_site_name(const char* v, size_t n) { site_name_.assign(v, n); } 
  void set_site_name(const char* v) { site_name_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

  std::string* mutable_embed_url() { return &embed_url_; } 
  const std::string& embed_url() const { return embed_url_; } 
  void set_embed_url(const std::string& v) { embed_url_ = v; } 
  void set_embed_url(const char* v, size_t n) { embed_url_.assign(v, n); } 
  void set_embed_url(const char* v) { embed_url_ = v; } 

  std::string* mutable_embed_type() { return &embed_type_; } 
  const std::string& embed_type() const { return embed_type_; } 
  void set_embed_type(const std::string& v) { embed_type_ = v; } 
  void set_embed_type(const char* v, size_t n) { embed_type_.assign(v, n); } 
  void set_embed_type(const char* v) { embed_type_ = v; } 

  int32_t embed_width() const { return embed_width_; } 
  void set_embed_width(int32_t v) { embed_width_ = v; } 

  int32_t embed_height() const { return embed_height_; } 
  void set_embed_height(int32_t v) { embed_height_ = v; } 

  int32_t duration() const { return duration_; } 
  void set_duration(int32_t v) { duration_ = v; } 

  std::string* mutable_author() { return &author_; } 
  const std::string& author() const { return author_; } 
  void set_author(const std::string& v) { author_ = v; } 
  void set_author(const char* v, size_t n) { author_.assign(v, n); } 
  void set_author(const char* v) { author_ = v; } 

private:
  int32_t flags_;
  int64_t id_;
  std::string url_;
  std::string display_url_;
  int32_t hash_;
  std::string type_;
  std::string site_name_;
  std::string title_;
  std::string description_;
  std::unique_ptr<Photo> photo_;
  std::string embed_url_;
  std::string embed_type_;
  int32_t embed_width_;
  int32_t embed_height_;
  int32_t duration_;
  std::string author_;
  std::unique_ptr<Document> document_;
  std::unique_ptr<Page> cached_page_;
};

// webPageNotModified#85849473 = WebPage;
class TL_webPageNotModified : public WebPage {
public:
  enum {
    CLASS_ID = 0x85849473
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "webPageNotModified#0x85849473";
  }

private:
};

// authorization#7bf2e6f6 hash:long flags:int device_model:string platform:string system_version:string api_id:int app_name:string app_version:string date_created:int date_active:int ip:string country:string region:string = Authorization;
class TL_authorization : public Authorization {
public:
  enum {
    CLASS_ID = 0x7bf2e6f6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "authorization#0x7bf2e6f6";
  }

  int64_t hash() const { return hash_; } 
  void set_hash(int64_t v) { hash_ = v; } 

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_device_model() { return &device_model_; } 
  const std::string& device_model() const { return device_model_; } 
  void set_device_model(const std::string& v) { device_model_ = v; } 
  void set_device_model(const char* v, size_t n) { device_model_.assign(v, n); } 
  void set_device_model(const char* v) { device_model_ = v; } 

  std::string* mutable_platform() { return &platform_; } 
  const std::string& platform() const { return platform_; } 
  void set_platform(const std::string& v) { platform_ = v; } 
  void set_platform(const char* v, size_t n) { platform_.assign(v, n); } 
  void set_platform(const char* v) { platform_ = v; } 

  std::string* mutable_system_version() { return &system_version_; } 
  const std::string& system_version() const { return system_version_; } 
  void set_system_version(const std::string& v) { system_version_ = v; } 
  void set_system_version(const char* v, size_t n) { system_version_.assign(v, n); } 
  void set_system_version(const char* v) { system_version_ = v; } 

  int32_t api_id() const { return api_id_; } 
  void set_api_id(int32_t v) { api_id_ = v; } 

  std::string* mutable_app_name() { return &app_name_; } 
  const std::string& app_name() const { return app_name_; } 
  void set_app_name(const std::string& v) { app_name_ = v; } 
  void set_app_name(const char* v, size_t n) { app_name_.assign(v, n); } 
  void set_app_name(const char* v) { app_name_ = v; } 

  std::string* mutable_app_version() { return &app_version_; } 
  const std::string& app_version() const { return app_version_; } 
  void set_app_version(const std::string& v) { app_version_ = v; } 
  void set_app_version(const char* v, size_t n) { app_version_.assign(v, n); } 
  void set_app_version(const char* v) { app_version_ = v; } 

  int32_t date_created() const { return date_created_; } 
  void set_date_created(int32_t v) { date_created_ = v; } 

  int32_t date_active() const { return date_active_; } 
  void set_date_active(int32_t v) { date_active_ = v; } 

  std::string* mutable_ip() { return &ip_; } 
  const std::string& ip() const { return ip_; } 
  void set_ip(const std::string& v) { ip_ = v; } 
  void set_ip(const char* v, size_t n) { ip_.assign(v, n); } 
  void set_ip(const char* v) { ip_ = v; } 

  std::string* mutable_country() { return &country_; } 
  const std::string& country() const { return country_; } 
  void set_country(const std::string& v) { country_ = v; } 
  void set_country(const char* v, size_t n) { country_.assign(v, n); } 
  void set_country(const char* v) { country_ = v; } 

  std::string* mutable_region() { return &region_; } 
  const std::string& region() const { return region_; } 
  void set_region(const std::string& v) { region_ = v; } 
  void set_region(const char* v, size_t n) { region_.assign(v, n); } 
  void set_region(const char* v) { region_ = v; } 

private:
  int64_t hash_;
  int32_t flags_;
  std::string device_model_;
  std::string platform_;
  std::string system_version_;
  int32_t api_id_;
  std::string app_name_;
  std::string app_version_;
  int32_t date_created_;
  int32_t date_active_;
  std::string ip_;
  std::string country_;
  std::string region_;
};

// account.authorizations#1250abde authorizations:Vector<Authorization> = account.Authorizations;
class TL_account_authorizations : public account_Authorizations {
public:
  enum {
    CLASS_ID = 0x1250abde
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_authorizations#0x1250abde";
  }

private:
  TLObjectVector<Authorization> authorizations_;
};

// account.noPassword#96dabc18 new_salt:bytes email_unconfirmed_pattern:string = account.Password;
class TL_account_noPassword : public account_Password {
public:
  enum {
    CLASS_ID = 0x96dabc18
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_noPassword#0x96dabc18";
  }

  std::string* mutable_new_salt() { return &new_salt_; } 
  const std::string& new_salt() const { return new_salt_; } 
  void set_new_salt(const std::string& v) { new_salt_ = v; } 
  void set_new_salt(const char* v, size_t n) { new_salt_.assign(v, n); } 
  void set_new_salt(const char* v) { new_salt_ = v; } 

  std::string* mutable_email_unconfirmed_pattern() { return &email_unconfirmed_pattern_; } 
  const std::string& email_unconfirmed_pattern() const { return email_unconfirmed_pattern_; } 
  void set_email_unconfirmed_pattern(const std::string& v) { email_unconfirmed_pattern_ = v; } 
  void set_email_unconfirmed_pattern(const char* v, size_t n) { email_unconfirmed_pattern_.assign(v, n); } 
  void set_email_unconfirmed_pattern(const char* v) { email_unconfirmed_pattern_ = v; } 

private:
  std::string new_salt_;
  std::string email_unconfirmed_pattern_;
};

// account.password#7c18141c current_salt:bytes new_salt:bytes hint:string has_recovery:Bool email_unconfirmed_pattern:string = account.Password;
class TL_account_password : public account_Password {
public:
  enum {
    CLASS_ID = 0x7c18141c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_password#0x7c18141c";
  }

  std::string* mutable_current_salt() { return &current_salt_; } 
  const std::string& current_salt() const { return current_salt_; } 
  void set_current_salt(const std::string& v) { current_salt_ = v; } 
  void set_current_salt(const char* v, size_t n) { current_salt_.assign(v, n); } 
  void set_current_salt(const char* v) { current_salt_ = v; } 

  std::string* mutable_new_salt() { return &new_salt_; } 
  const std::string& new_salt() const { return new_salt_; } 
  void set_new_salt(const std::string& v) { new_salt_ = v; } 
  void set_new_salt(const char* v, size_t n) { new_salt_.assign(v, n); } 
  void set_new_salt(const char* v) { new_salt_ = v; } 

  std::string* mutable_hint() { return &hint_; } 
  const std::string& hint() const { return hint_; } 
  void set_hint(const std::string& v) { hint_ = v; } 
  void set_hint(const char* v, size_t n) { hint_.assign(v, n); } 
  void set_hint(const char* v) { hint_ = v; } 

  std::string* mutable_email_unconfirmed_pattern() { return &email_unconfirmed_pattern_; } 
  const std::string& email_unconfirmed_pattern() const { return email_unconfirmed_pattern_; } 
  void set_email_unconfirmed_pattern(const std::string& v) { email_unconfirmed_pattern_ = v; } 
  void set_email_unconfirmed_pattern(const char* v, size_t n) { email_unconfirmed_pattern_.assign(v, n); } 
  void set_email_unconfirmed_pattern(const char* v) { email_unconfirmed_pattern_ = v; } 

private:
  std::string current_salt_;
  std::string new_salt_;
  std::string hint_;
  std::unique_ptr<Bool> has_recovery_;
  std::string email_unconfirmed_pattern_;
};

// account.passwordSettings#b7b72ab3 email:string = account.PasswordSettings;
class TL_account_passwordSettings : public account_PasswordSettings {
public:
  enum {
    CLASS_ID = 0xb7b72ab3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_passwordSettings#0xb7b72ab3";
  }

  std::string* mutable_email() { return &email_; } 
  const std::string& email() const { return email_; } 
  void set_email(const std::string& v) { email_ = v; } 
  void set_email(const char* v, size_t n) { email_.assign(v, n); } 
  void set_email(const char* v) { email_ = v; } 

private:
  std::string email_;
};

// account.passwordInputSettings#86916deb flags:# new_salt:flags.0?bytes new_password_hash:flags.0?bytes hint:flags.0?string email:flags.1?string = account.PasswordInputSettings;
class TL_account_passwordInputSettings : public account_PasswordInputSettings {
public:
  enum {
    CLASS_ID = 0x86916deb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_passwordInputSettings#0x86916deb";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_new_salt() { return &new_salt_; } 
  const std::string& new_salt() const { return new_salt_; } 
  void set_new_salt(const std::string& v) { new_salt_ = v; } 
  void set_new_salt(const char* v, size_t n) { new_salt_.assign(v, n); } 
  void set_new_salt(const char* v) { new_salt_ = v; } 

  std::string* mutable_new_password_hash() { return &new_password_hash_; } 
  const std::string& new_password_hash() const { return new_password_hash_; } 
  void set_new_password_hash(const std::string& v) { new_password_hash_ = v; } 
  void set_new_password_hash(const char* v, size_t n) { new_password_hash_.assign(v, n); } 
  void set_new_password_hash(const char* v) { new_password_hash_ = v; } 

  std::string* mutable_hint() { return &hint_; } 
  const std::string& hint() const { return hint_; } 
  void set_hint(const std::string& v) { hint_ = v; } 
  void set_hint(const char* v, size_t n) { hint_.assign(v, n); } 
  void set_hint(const char* v) { hint_ = v; } 

  std::string* mutable_email() { return &email_; } 
  const std::string& email() const { return email_; } 
  void set_email(const std::string& v) { email_ = v; } 
  void set_email(const char* v, size_t n) { email_.assign(v, n); } 
  void set_email(const char* v) { email_ = v; } 

private:
  int32_t flags_;
  std::string new_salt_;
  std::string new_password_hash_;
  std::string hint_;
  std::string email_;
};

// auth.passwordRecovery#137948a5 email_pattern:string = auth.PasswordRecovery;
class TL_auth_passwordRecovery : public auth_PasswordRecovery {
public:
  enum {
    CLASS_ID = 0x137948a5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_passwordRecovery#0x137948a5";
  }

  std::string* mutable_email_pattern() { return &email_pattern_; } 
  const std::string& email_pattern() const { return email_pattern_; } 
  void set_email_pattern(const std::string& v) { email_pattern_ = v; } 
  void set_email_pattern(const char* v, size_t n) { email_pattern_.assign(v, n); } 
  void set_email_pattern(const char* v) { email_pattern_ = v; } 

private:
  std::string email_pattern_;
};

// receivedNotifyMessage#a384b779 id:int flags:int = ReceivedNotifyMessage;
class TL_receivedNotifyMessage : public ReceivedNotifyMessage {
public:
  enum {
    CLASS_ID = 0xa384b779
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "receivedNotifyMessage#0xa384b779";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t id_;
  int32_t flags_;
};

// chatInviteEmpty#69df3769 = ExportedChatInvite;
class TL_chatInviteEmpty : public ExportedChatInvite {
public:
  enum {
    CLASS_ID = 0x69df3769
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatInviteEmpty#0x69df3769";
  }

private:
};

// chatInviteExported#fc2e05bc link:string = ExportedChatInvite;
class TL_chatInviteExported : public ExportedChatInvite {
public:
  enum {
    CLASS_ID = 0xfc2e05bc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatInviteExported#0xfc2e05bc";
  }

  std::string* mutable_link() { return &link_; } 
  const std::string& link() const { return link_; } 
  void set_link(const std::string& v) { link_ = v; } 
  void set_link(const char* v, size_t n) { link_.assign(v, n); } 
  void set_link(const char* v) { link_ = v; } 

private:
  std::string link_;
};

// chatInviteAlready#5a686d7c chat:Chat = ChatInvite;
class TL_chatInviteAlready : public ChatInvite {
public:
  enum {
    CLASS_ID = 0x5a686d7c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatInviteAlready#0x5a686d7c";
  }

private:
  std::unique_ptr<Chat> chat_;
};

// chatInvite#db74f558 flags:# channel:flags.0?true broadcast:flags.1?true public:flags.2?true megagroup:flags.3?true title:string photo:ChatPhoto participants_count:int participants:flags.4?Vector<User> = ChatInvite;
class TL_chatInvite : public ChatInvite {
public:
  enum {
    CLASS_ID = 0xdb74f558
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "chatInvite#0xdb74f558";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  int32_t participants_count() const { return participants_count_; } 
  void set_participants_count(int32_t v) { participants_count_ = v; } 

private:
  int32_t flags_;
  bool channel_ {false};
  bool broadcast_ {false};
  bool public_ {false};
  bool megagroup_ {false};
  std::string title_;
  std::unique_ptr<ChatPhoto> photo_;
  int32_t participants_count_;
  TLObjectVector<User> participants_;
};

// inputStickerSetEmpty#ffb62b95 = InputStickerSet;
class TL_inputStickerSetEmpty : public InputStickerSet {
public:
  enum {
    CLASS_ID = 0xffb62b95
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputStickerSetEmpty#0xffb62b95";
  }

private:
};

// inputStickerSetID#9de7a269 id:long access_hash:long = InputStickerSet;
class TL_inputStickerSetID : public InputStickerSet {
public:
  enum {
    CLASS_ID = 0x9de7a269
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputStickerSetID#0x9de7a269";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
};

// inputStickerSetShortName#861cc8a0 short_name:string = InputStickerSet;
class TL_inputStickerSetShortName : public InputStickerSet {
public:
  enum {
    CLASS_ID = 0x861cc8a0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputStickerSetShortName#0x861cc8a0";
  }

  std::string* mutable_short_name() { return &short_name_; } 
  const std::string& short_name() const { return short_name_; } 
  void set_short_name(const std::string& v) { short_name_ = v; } 
  void set_short_name(const char* v, size_t n) { short_name_.assign(v, n); } 
  void set_short_name(const char* v) { short_name_ = v; } 

private:
  std::string short_name_;
};

// stickerSet#cd303b41 flags:# installed:flags.0?true archived:flags.1?true official:flags.2?true masks:flags.3?true id:long access_hash:long title:string short_name:string count:int hash:int = StickerSet;
class TL_stickerSet : public StickerSet {
public:
  enum {
    CLASS_ID = 0xcd303b41
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "stickerSet#0xcd303b41";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_short_name() { return &short_name_; } 
  const std::string& short_name() const { return short_name_; } 
  void set_short_name(const std::string& v) { short_name_ = v; } 
  void set_short_name(const char* v, size_t n) { short_name_.assign(v, n); } 
  void set_short_name(const char* v) { short_name_ = v; } 

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t flags_;
  bool installed_ {false};
  bool archived_ {false};
  bool official_ {false};
  bool masks_ {false};
  int64_t id_;
  int64_t access_hash_;
  std::string title_;
  std::string short_name_;
  int32_t count_;
  int32_t hash_;
};

// messages.stickerSet#b60a24a6 set:StickerSet packs:Vector<StickerPack> documents:Vector<Document> = messages.StickerSet;
class TL_messages_stickerSet : public messages_StickerSet {
public:
  enum {
    CLASS_ID = 0xb60a24a6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_stickerSet#0xb60a24a6";
  }

private:
  std::unique_ptr<StickerSet> set_;
  TLObjectVector<StickerPack> packs_;
  TLObjectVector<Document> documents_;
};

// botCommand#c27ac8c7 command:string description:string = BotCommand;
class TL_botCommand : public BotCommand {
public:
  enum {
    CLASS_ID = 0xc27ac8c7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botCommand#0xc27ac8c7";
  }

  std::string* mutable_command() { return &command_; } 
  const std::string& command() const { return command_; } 
  void set_command(const std::string& v) { command_ = v; } 
  void set_command(const char* v, size_t n) { command_.assign(v, n); } 
  void set_command(const char* v) { command_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

private:
  std::string command_;
  std::string description_;
};

// botInfo#98e81d3a user_id:int description:string commands:Vector<BotCommand> = BotInfo;
class TL_botInfo : public BotInfo {
public:
  enum {
    CLASS_ID = 0x98e81d3a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botInfo#0x98e81d3a";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

private:
  int32_t user_id_;
  std::string description_;
  TLObjectVector<BotCommand> commands_;
};

// keyboardButton#a2fa4880 text:string = KeyboardButton;
class TL_keyboardButton : public KeyboardButton {
public:
  enum {
    CLASS_ID = 0xa2fa4880
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButton#0xa2fa4880";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  std::string text_;
};

// keyboardButtonUrl#258aff05 text:string url:string = KeyboardButton;
class TL_keyboardButtonUrl : public KeyboardButton {
public:
  enum {
    CLASS_ID = 0x258aff05
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButtonUrl#0x258aff05";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

private:
  std::string text_;
  std::string url_;
};

// keyboardButtonCallback#683a5e46 text:string data:bytes = KeyboardButton;
class TL_keyboardButtonCallback : public KeyboardButton {
public:
  enum {
    CLASS_ID = 0x683a5e46
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButtonCallback#0x683a5e46";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

private:
  std::string text_;
  std::string data_;
};

// keyboardButtonRequestPhone#b16a6c29 text:string = KeyboardButton;
class TL_keyboardButtonRequestPhone : public KeyboardButton {
public:
  enum {
    CLASS_ID = 0xb16a6c29
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButtonRequestPhone#0xb16a6c29";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  std::string text_;
};

// keyboardButtonRequestGeoLocation#fc796b3f text:string = KeyboardButton;
class TL_keyboardButtonRequestGeoLocation : public KeyboardButton {
public:
  enum {
    CLASS_ID = 0xfc796b3f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButtonRequestGeoLocation#0xfc796b3f";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  std::string text_;
};

// keyboardButtonSwitchInline#568a748 flags:# same_peer:flags.0?true text:string query:string = KeyboardButton;
class TL_keyboardButtonSwitchInline : public KeyboardButton {
public:
  enum {
    CLASS_ID = 0x568a748
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButtonSwitchInline#0x568a748";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

  std::string* mutable_query() { return &query_; } 
  const std::string& query() const { return query_; } 
  void set_query(const std::string& v) { query_ = v; } 
  void set_query(const char* v, size_t n) { query_.assign(v, n); } 
  void set_query(const char* v) { query_ = v; } 

private:
  int32_t flags_;
  bool same_peer_ {false};
  std::string text_;
  std::string query_;
};

// keyboardButtonGame#50f41ccf text:string = KeyboardButton;
class TL_keyboardButtonGame : public KeyboardButton {
public:
  enum {
    CLASS_ID = 0x50f41ccf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButtonGame#0x50f41ccf";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  std::string text_;
};

// keyboardButtonBuy#afd93fbb text:string = KeyboardButton;
class TL_keyboardButtonBuy : public KeyboardButton {
public:
  enum {
    CLASS_ID = 0xafd93fbb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButtonBuy#0xafd93fbb";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  std::string text_;
};

// keyboardButtonRow#77608b83 buttons:Vector<KeyboardButton> = KeyboardButtonRow;
class TL_keyboardButtonRow : public KeyboardButtonRow {
public:
  enum {
    CLASS_ID = 0x77608b83
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "keyboardButtonRow#0x77608b83";
  }

private:
  TLObjectVector<KeyboardButton> buttons_;
};

// replyKeyboardHide#a03e5b85 flags:# selective:flags.2?true = ReplyMarkup;
class TL_replyKeyboardHide : public ReplyMarkup {
public:
  enum {
    CLASS_ID = 0xa03e5b85
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "replyKeyboardHide#0xa03e5b85";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool selective_ {false};
};

// replyKeyboardForceReply#f4108aa0 flags:# single_use:flags.1?true selective:flags.2?true = ReplyMarkup;
class TL_replyKeyboardForceReply : public ReplyMarkup {
public:
  enum {
    CLASS_ID = 0xf4108aa0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "replyKeyboardForceReply#0xf4108aa0";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool single_use_ {false};
  bool selective_ {false};
};

// replyKeyboardMarkup#3502758c flags:# resize:flags.0?true single_use:flags.1?true selective:flags.2?true rows:Vector<KeyboardButtonRow> = ReplyMarkup;
class TL_replyKeyboardMarkup : public ReplyMarkup {
public:
  enum {
    CLASS_ID = 0x3502758c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "replyKeyboardMarkup#0x3502758c";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool resize_ {false};
  bool single_use_ {false};
  bool selective_ {false};
  TLObjectVector<KeyboardButtonRow> rows_;
};

// replyInlineMarkup#48a30254 rows:Vector<KeyboardButtonRow> = ReplyMarkup;
class TL_replyInlineMarkup : public ReplyMarkup {
public:
  enum {
    CLASS_ID = 0x48a30254
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "replyInlineMarkup#0x48a30254";
  }

private:
  TLObjectVector<KeyboardButtonRow> rows_;
};

// messageEntityUnknown#bb92ba95 offset:int length:int = MessageEntity;
class TL_messageEntityUnknown : public MessageEntity {
public:
  enum {
    CLASS_ID = 0xbb92ba95
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityUnknown#0xbb92ba95";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityMention#fa04579d offset:int length:int = MessageEntity;
class TL_messageEntityMention : public MessageEntity {
public:
  enum {
    CLASS_ID = 0xfa04579d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityMention#0xfa04579d";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityHashtag#6f635b0d offset:int length:int = MessageEntity;
class TL_messageEntityHashtag : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x6f635b0d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityHashtag#0x6f635b0d";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityBotCommand#6cef8ac7 offset:int length:int = MessageEntity;
class TL_messageEntityBotCommand : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x6cef8ac7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityBotCommand#0x6cef8ac7";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityUrl#6ed02538 offset:int length:int = MessageEntity;
class TL_messageEntityUrl : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x6ed02538
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityUrl#0x6ed02538";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityEmail#64e475c2 offset:int length:int = MessageEntity;
class TL_messageEntityEmail : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x64e475c2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityEmail#0x64e475c2";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityBold#bd610bc9 offset:int length:int = MessageEntity;
class TL_messageEntityBold : public MessageEntity {
public:
  enum {
    CLASS_ID = 0xbd610bc9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityBold#0xbd610bc9";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityItalic#826f8b60 offset:int length:int = MessageEntity;
class TL_messageEntityItalic : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x826f8b60
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityItalic#0x826f8b60";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityCode#28a20571 offset:int length:int = MessageEntity;
class TL_messageEntityCode : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x28a20571
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityCode#0x28a20571";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
};

// messageEntityPre#73924be0 offset:int length:int language:string = MessageEntity;
class TL_messageEntityPre : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x73924be0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityPre#0x73924be0";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

  std::string* mutable_language() { return &language_; } 
  const std::string& language() const { return language_; } 
  void set_language(const std::string& v) { language_ = v; } 
  void set_language(const char* v, size_t n) { language_.assign(v, n); } 
  void set_language(const char* v) { language_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
  std::string language_;
};

// messageEntityTextUrl#76a6d327 offset:int length:int url:string = MessageEntity;
class TL_messageEntityTextUrl : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x76a6d327
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityTextUrl#0x76a6d327";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
  std::string url_;
};

// messageEntityMentionName#352dca58 offset:int length:int user_id:int = MessageEntity;
class TL_messageEntityMentionName : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x352dca58
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageEntityMentionName#0x352dca58";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
  int32_t user_id_;
};

// inputMessageEntityMentionName#208e68c9 offset:int length:int user_id:InputUser = MessageEntity;
class TL_inputMessageEntityMentionName : public MessageEntity {
public:
  enum {
    CLASS_ID = 0x208e68c9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputMessageEntityMentionName#0x208e68c9";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t offset_;
  int32_t length_;
  std::unique_ptr<InputUser> user_id_;
};

// inputChannelEmpty#ee8c1e86 = InputChannel;
class TL_inputChannelEmpty : public InputChannel {
public:
  enum {
    CLASS_ID = 0xee8c1e86
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputChannelEmpty#0xee8c1e86";
  }

private:
};

// inputChannel#afeb712e channel_id:int access_hash:long = InputChannel;
class TL_inputChannel : public InputChannel {
public:
  enum {
    CLASS_ID = 0xafeb712e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputChannel#0xafeb712e";
  }

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int32_t channel_id_;
  int64_t access_hash_;
};

// contacts.resolvedPeer#7f077ad9 peer:Peer chats:Vector<Chat> users:Vector<User> = contacts.ResolvedPeer;
class TL_contacts_resolvedPeer : public contacts_ResolvedPeer {
public:
  enum {
    CLASS_ID = 0x7f077ad9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_resolvedPeer#0x7f077ad9";
  }

private:
  std::unique_ptr<Peer> peer_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// messageRange#ae30253 min_id:int max_id:int = MessageRange;
class TL_messageRange : public MessageRange {
public:
  enum {
    CLASS_ID = 0xae30253
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageRange#0xae30253";
  }

  int32_t min_id() const { return min_id_; } 
  void set_min_id(int32_t v) { min_id_ = v; } 

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

private:
  int32_t min_id_;
  int32_t max_id_;
};

// updates.channelDifferenceEmpty#3e11affb flags:# final:flags.0?true pts:int timeout:flags.1?int = updates.ChannelDifference;
class TL_updates_channelDifferenceEmpty : public updates_ChannelDifference {
public:
  enum {
    CLASS_ID = 0x3e11affb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_channelDifferenceEmpty#0x3e11affb";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t timeout() const { return timeout_; } 
  void set_timeout(int32_t v) { timeout_ = v; } 

private:
  int32_t flags_;
  bool final_ {false};
  int32_t pts_;
  int32_t timeout_;
};

// updates.channelDifferenceTooLong#410dee07 flags:# final:flags.0?true pts:int timeout:flags.1?int top_message:int read_inbox_max_id:int read_outbox_max_id:int unread_count:int messages:Vector<Message> chats:Vector<Chat> users:Vector<User> = updates.ChannelDifference;
class TL_updates_channelDifferenceTooLong : public updates_ChannelDifference {
public:
  enum {
    CLASS_ID = 0x410dee07
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_channelDifferenceTooLong#0x410dee07";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t timeout() const { return timeout_; } 
  void set_timeout(int32_t v) { timeout_ = v; } 

  int32_t top_message() const { return top_message_; } 
  void set_top_message(int32_t v) { top_message_ = v; } 

  int32_t read_inbox_max_id() const { return read_inbox_max_id_; } 
  void set_read_inbox_max_id(int32_t v) { read_inbox_max_id_ = v; } 

  int32_t read_outbox_max_id() const { return read_outbox_max_id_; } 
  void set_read_outbox_max_id(int32_t v) { read_outbox_max_id_ = v; } 

  int32_t unread_count() const { return unread_count_; } 
  void set_unread_count(int32_t v) { unread_count_ = v; } 

private:
  int32_t flags_;
  bool final_ {false};
  int32_t pts_;
  int32_t timeout_;
  int32_t top_message_;
  int32_t read_inbox_max_id_;
  int32_t read_outbox_max_id_;
  int32_t unread_count_;
  TLObjectVector<Message> messages_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// updates.channelDifference#2064674e flags:# final:flags.0?true pts:int timeout:flags.1?int new_messages:Vector<Message> other_updates:Vector<Update> chats:Vector<Chat> users:Vector<User> = updates.ChannelDifference;
class TL_updates_channelDifference : public updates_ChannelDifference {
public:
  enum {
    CLASS_ID = 0x2064674e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_channelDifference#0x2064674e";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t timeout() const { return timeout_; } 
  void set_timeout(int32_t v) { timeout_ = v; } 

private:
  int32_t flags_;
  bool final_ {false};
  int32_t pts_;
  int32_t timeout_;
  TLObjectVector<Message> new_messages_;
  TLObjectVector<Update> other_updates_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// channelMessagesFilterEmpty#94d42ee7 = ChannelMessagesFilter;
class TL_channelMessagesFilterEmpty : public ChannelMessagesFilter {
public:
  enum {
    CLASS_ID = 0x94d42ee7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelMessagesFilterEmpty#0x94d42ee7";
  }

private:
};

// channelMessagesFilter#cd77d957 flags:# exclude_new_messages:flags.1?true ranges:Vector<MessageRange> = ChannelMessagesFilter;
class TL_channelMessagesFilter : public ChannelMessagesFilter {
public:
  enum {
    CLASS_ID = 0xcd77d957
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelMessagesFilter#0xcd77d957";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool exclude_new_messages_ {false};
  TLObjectVector<MessageRange> ranges_;
};

// channelParticipant#15ebac1d user_id:int date:int = ChannelParticipant;
class TL_channelParticipant : public ChannelParticipant {
public:
  enum {
    CLASS_ID = 0x15ebac1d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipant#0x15ebac1d";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t date_;
};

// channelParticipantSelf#a3289a6d user_id:int inviter_id:int date:int = ChannelParticipant;
class TL_channelParticipantSelf : public ChannelParticipant {
public:
  enum {
    CLASS_ID = 0xa3289a6d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantSelf#0xa3289a6d";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t inviter_id() const { return inviter_id_; } 
  void set_inviter_id(int32_t v) { inviter_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t inviter_id_;
  int32_t date_;
};

// channelParticipantModerator#91057fef user_id:int inviter_id:int date:int = ChannelParticipant;
class TL_channelParticipantModerator : public ChannelParticipant {
public:
  enum {
    CLASS_ID = 0x91057fef
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantModerator#0x91057fef";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t inviter_id() const { return inviter_id_; } 
  void set_inviter_id(int32_t v) { inviter_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t inviter_id_;
  int32_t date_;
};

// channelParticipantEditor#98192d61 user_id:int inviter_id:int date:int = ChannelParticipant;
class TL_channelParticipantEditor : public ChannelParticipant {
public:
  enum {
    CLASS_ID = 0x98192d61
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantEditor#0x98192d61";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t inviter_id() const { return inviter_id_; } 
  void set_inviter_id(int32_t v) { inviter_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t inviter_id_;
  int32_t date_;
};

// channelParticipantKicked#8cc5e69a user_id:int kicked_by:int date:int = ChannelParticipant;
class TL_channelParticipantKicked : public ChannelParticipant {
public:
  enum {
    CLASS_ID = 0x8cc5e69a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantKicked#0x8cc5e69a";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t kicked_by() const { return kicked_by_; } 
  void set_kicked_by(int32_t v) { kicked_by_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t user_id_;
  int32_t kicked_by_;
  int32_t date_;
};

// channelParticipantCreator#e3e2e1f9 user_id:int = ChannelParticipant;
class TL_channelParticipantCreator : public ChannelParticipant {
public:
  enum {
    CLASS_ID = 0xe3e2e1f9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantCreator#0xe3e2e1f9";
  }

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

private:
  int32_t user_id_;
};

// channelParticipantsRecent#de3f3c79 = ChannelParticipantsFilter;
class TL_channelParticipantsRecent : public ChannelParticipantsFilter {
public:
  enum {
    CLASS_ID = 0xde3f3c79
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantsRecent#0xde3f3c79";
  }

private:
};

// channelParticipantsAdmins#b4608969 = ChannelParticipantsFilter;
class TL_channelParticipantsAdmins : public ChannelParticipantsFilter {
public:
  enum {
    CLASS_ID = 0xb4608969
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantsAdmins#0xb4608969";
  }

private:
};

// channelParticipantsKicked#3c37bb7a = ChannelParticipantsFilter;
class TL_channelParticipantsKicked : public ChannelParticipantsFilter {
public:
  enum {
    CLASS_ID = 0x3c37bb7a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantsKicked#0x3c37bb7a";
  }

private:
};

// channelParticipantsBots#b0d1865b = ChannelParticipantsFilter;
class TL_channelParticipantsBots : public ChannelParticipantsFilter {
public:
  enum {
    CLASS_ID = 0xb0d1865b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelParticipantsBots#0xb0d1865b";
  }

private:
};

// channelRoleEmpty#b285a0c6 = ChannelParticipantRole;
class TL_channelRoleEmpty : public ChannelParticipantRole {
public:
  enum {
    CLASS_ID = 0xb285a0c6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelRoleEmpty#0xb285a0c6";
  }

private:
};

// channelRoleModerator#9618d975 = ChannelParticipantRole;
class TL_channelRoleModerator : public ChannelParticipantRole {
public:
  enum {
    CLASS_ID = 0x9618d975
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelRoleModerator#0x9618d975";
  }

private:
};

// channelRoleEditor#820bfe8c = ChannelParticipantRole;
class TL_channelRoleEditor : public ChannelParticipantRole {
public:
  enum {
    CLASS_ID = 0x820bfe8c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channelRoleEditor#0x820bfe8c";
  }

private:
};

// channels.channelParticipants#f56ee2a8 count:int participants:Vector<ChannelParticipant> users:Vector<User> = channels.ChannelParticipants;
class TL_channels_channelParticipants : public channels_ChannelParticipants {
public:
  enum {
    CLASS_ID = 0xf56ee2a8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_channelParticipants#0xf56ee2a8";
  }

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  int32_t count_;
  TLObjectVector<ChannelParticipant> participants_;
  TLObjectVector<User> users_;
};

// channels.channelParticipant#d0d9b163 participant:ChannelParticipant users:Vector<User> = channels.ChannelParticipant;
class TL_channels_channelParticipant : public channels_ChannelParticipant {
public:
  enum {
    CLASS_ID = 0xd0d9b163
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_channelParticipant#0xd0d9b163";
  }

private:
  std::unique_ptr<ChannelParticipant> participant_;
  TLObjectVector<User> users_;
};

// help.termsOfService#f1ee3e90 text:string = help.TermsOfService;
class TL_help_termsOfService : public help_TermsOfService {
public:
  enum {
    CLASS_ID = 0xf1ee3e90
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_termsOfService#0xf1ee3e90";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  std::string text_;
};

// foundGif#162ecc1f url:string thumb_url:string content_url:string content_type:string w:int h:int = FoundGif;
class TL_foundGif : public FoundGif {
public:
  enum {
    CLASS_ID = 0x162ecc1f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "foundGif#0x162ecc1f";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_thumb_url() { return &thumb_url_; } 
  const std::string& thumb_url() const { return thumb_url_; } 
  void set_thumb_url(const std::string& v) { thumb_url_ = v; } 
  void set_thumb_url(const char* v, size_t n) { thumb_url_.assign(v, n); } 
  void set_thumb_url(const char* v) { thumb_url_ = v; } 

  std::string* mutable_content_url() { return &content_url_; } 
  const std::string& content_url() const { return content_url_; } 
  void set_content_url(const std::string& v) { content_url_ = v; } 
  void set_content_url(const char* v, size_t n) { content_url_.assign(v, n); } 
  void set_content_url(const char* v) { content_url_ = v; } 

  std::string* mutable_content_type() { return &content_type_; } 
  const std::string& content_type() const { return content_type_; } 
  void set_content_type(const std::string& v) { content_type_ = v; } 
  void set_content_type(const char* v, size_t n) { content_type_.assign(v, n); } 
  void set_content_type(const char* v) { content_type_ = v; } 

  int32_t w() const { return w_; } 
  void set_w(int32_t v) { w_ = v; } 

  int32_t h() const { return h_; } 
  void set_h(int32_t v) { h_ = v; } 

private:
  std::string url_;
  std::string thumb_url_;
  std::string content_url_;
  std::string content_type_;
  int32_t w_;
  int32_t h_;
};

// foundGifCached#9c750409 url:string photo:Photo document:Document = FoundGif;
class TL_foundGifCached : public FoundGif {
public:
  enum {
    CLASS_ID = 0x9c750409
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "foundGifCached#0x9c750409";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

private:
  std::string url_;
  std::unique_ptr<Photo> photo_;
  std::unique_ptr<Document> document_;
};

// messages.foundGifs#450a1c0a next_offset:int results:Vector<FoundGif> = messages.FoundGifs;
class TL_messages_foundGifs : public messages_FoundGifs {
public:
  enum {
    CLASS_ID = 0x450a1c0a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_foundGifs#0x450a1c0a";
  }

  int32_t next_offset() const { return next_offset_; } 
  void set_next_offset(int32_t v) { next_offset_ = v; } 

private:
  int32_t next_offset_;
  TLObjectVector<FoundGif> results_;
};

// messages.savedGifsNotModified#e8025ca2 = messages.SavedGifs;
class TL_messages_savedGifsNotModified : public messages_SavedGifs {
public:
  enum {
    CLASS_ID = 0xe8025ca2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_savedGifsNotModified#0xe8025ca2";
  }

private:
};

// messages.savedGifs#2e0709a5 hash:int gifs:Vector<Document> = messages.SavedGifs;
class TL_messages_savedGifs : public messages_SavedGifs {
public:
  enum {
    CLASS_ID = 0x2e0709a5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_savedGifs#0x2e0709a5";
  }

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t hash_;
  TLObjectVector<Document> gifs_;
};

// inputBotInlineMessageMediaAuto#292fed13 flags:# caption:string reply_markup:flags.2?ReplyMarkup = InputBotInlineMessage;
class TL_inputBotInlineMessageMediaAuto : public InputBotInlineMessage {
public:
  enum {
    CLASS_ID = 0x292fed13
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineMessageMediaAuto#0x292fed13";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  int32_t flags_;
  std::string caption_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// inputBotInlineMessageText#3dcd7a87 flags:# no_webpage:flags.0?true message:string entities:flags.1?Vector<MessageEntity> reply_markup:flags.2?ReplyMarkup = InputBotInlineMessage;
class TL_inputBotInlineMessageText : public InputBotInlineMessage {
public:
  enum {
    CLASS_ID = 0x3dcd7a87
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineMessageText#0x3dcd7a87";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  int32_t flags_;
  bool no_webpage_ {false};
  std::string message_;
  TLObjectVector<MessageEntity> entities_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// inputBotInlineMessageMediaGeo#f4a59de1 flags:# geo_point:InputGeoPoint reply_markup:flags.2?ReplyMarkup = InputBotInlineMessage;
class TL_inputBotInlineMessageMediaGeo : public InputBotInlineMessage {
public:
  enum {
    CLASS_ID = 0xf4a59de1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineMessageMediaGeo#0xf4a59de1";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<InputGeoPoint> geo_point_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// inputBotInlineMessageMediaVenue#aaafadc8 flags:# geo_point:InputGeoPoint title:string address:string provider:string venue_id:string reply_markup:flags.2?ReplyMarkup = InputBotInlineMessage;
class TL_inputBotInlineMessageMediaVenue : public InputBotInlineMessage {
public:
  enum {
    CLASS_ID = 0xaaafadc8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineMessageMediaVenue#0xaaafadc8";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_address() { return &address_; } 
  const std::string& address() const { return address_; } 
  void set_address(const std::string& v) { address_ = v; } 
  void set_address(const char* v, size_t n) { address_.assign(v, n); } 
  void set_address(const char* v) { address_ = v; } 

  std::string* mutable_provider() { return &provider_; } 
  const std::string& provider() const { return provider_; } 
  void set_provider(const std::string& v) { provider_ = v; } 
  void set_provider(const char* v, size_t n) { provider_.assign(v, n); } 
  void set_provider(const char* v) { provider_ = v; } 

  std::string* mutable_venue_id() { return &venue_id_; } 
  const std::string& venue_id() const { return venue_id_; } 
  void set_venue_id(const std::string& v) { venue_id_ = v; } 
  void set_venue_id(const char* v, size_t n) { venue_id_.assign(v, n); } 
  void set_venue_id(const char* v) { venue_id_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<InputGeoPoint> geo_point_;
  std::string title_;
  std::string address_;
  std::string provider_;
  std::string venue_id_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// inputBotInlineMessageMediaContact#2daf01a7 flags:# phone_number:string first_name:string last_name:string reply_markup:flags.2?ReplyMarkup = InputBotInlineMessage;
class TL_inputBotInlineMessageMediaContact : public InputBotInlineMessage {
public:
  enum {
    CLASS_ID = 0x2daf01a7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineMessageMediaContact#0x2daf01a7";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

private:
  int32_t flags_;
  std::string phone_number_;
  std::string first_name_;
  std::string last_name_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// inputBotInlineMessageGame#4b425864 flags:# reply_markup:flags.2?ReplyMarkup = InputBotInlineMessage;
class TL_inputBotInlineMessageGame : public InputBotInlineMessage {
public:
  enum {
    CLASS_ID = 0x4b425864
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineMessageGame#0x4b425864";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// inputBotInlineResult#2cbbe15a flags:# id:string type:string title:flags.1?string description:flags.2?string url:flags.3?string thumb_url:flags.4?string content_url:flags.5?string content_type:flags.5?string w:flags.6?int h:flags.6?int duration:flags.7?int send_message:InputBotInlineMessage = InputBotInlineResult;
class TL_inputBotInlineResult : public InputBotInlineResult {
public:
  enum {
    CLASS_ID = 0x2cbbe15a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineResult#0x2cbbe15a";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_thumb_url() { return &thumb_url_; } 
  const std::string& thumb_url() const { return thumb_url_; } 
  void set_thumb_url(const std::string& v) { thumb_url_ = v; } 
  void set_thumb_url(const char* v, size_t n) { thumb_url_.assign(v, n); } 
  void set_thumb_url(const char* v) { thumb_url_ = v; } 

  std::string* mutable_content_url() { return &content_url_; } 
  const std::string& content_url() const { return content_url_; } 
  void set_content_url(const std::string& v) { content_url_ = v; } 
  void set_content_url(const char* v, size_t n) { content_url_.assign(v, n); } 
  void set_content_url(const char* v) { content_url_ = v; } 

  std::string* mutable_content_type() { return &content_type_; } 
  const std::string& content_type() const { return content_type_; } 
  void set_content_type(const std::string& v) { content_type_ = v; } 
  void set_content_type(const char* v, size_t n) { content_type_.assign(v, n); } 
  void set_content_type(const char* v) { content_type_ = v; } 

  int32_t w() const { return w_; } 
  void set_w(int32_t v) { w_ = v; } 

  int32_t h() const { return h_; } 
  void set_h(int32_t v) { h_ = v; } 

  int32_t duration() const { return duration_; } 
  void set_duration(int32_t v) { duration_ = v; } 

private:
  int32_t flags_;
  std::string id_;
  std::string type_;
  std::string title_;
  std::string description_;
  std::string url_;
  std::string thumb_url_;
  std::string content_url_;
  std::string content_type_;
  int32_t w_;
  int32_t h_;
  int32_t duration_;
  std::unique_ptr<InputBotInlineMessage> send_message_;
};

// inputBotInlineResultPhoto#a8d864a7 id:string type:string photo:InputPhoto send_message:InputBotInlineMessage = InputBotInlineResult;
class TL_inputBotInlineResultPhoto : public InputBotInlineResult {
public:
  enum {
    CLASS_ID = 0xa8d864a7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineResultPhoto#0xa8d864a7";
  }

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

private:
  std::string id_;
  std::string type_;
  std::unique_ptr<InputPhoto> photo_;
  std::unique_ptr<InputBotInlineMessage> send_message_;
};

// inputBotInlineResultDocument#fff8fdc4 flags:# id:string type:string title:flags.1?string description:flags.2?string document:InputDocument send_message:InputBotInlineMessage = InputBotInlineResult;
class TL_inputBotInlineResultDocument : public InputBotInlineResult {
public:
  enum {
    CLASS_ID = 0xfff8fdc4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineResultDocument#0xfff8fdc4";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

private:
  int32_t flags_;
  std::string id_;
  std::string type_;
  std::string title_;
  std::string description_;
  std::unique_ptr<InputDocument> document_;
  std::unique_ptr<InputBotInlineMessage> send_message_;
};

// inputBotInlineResultGame#4fa417f2 id:string short_name:string send_message:InputBotInlineMessage = InputBotInlineResult;
class TL_inputBotInlineResultGame : public InputBotInlineResult {
public:
  enum {
    CLASS_ID = 0x4fa417f2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineResultGame#0x4fa417f2";
  }

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_short_name() { return &short_name_; } 
  const std::string& short_name() const { return short_name_; } 
  void set_short_name(const std::string& v) { short_name_ = v; } 
  void set_short_name(const char* v, size_t n) { short_name_.assign(v, n); } 
  void set_short_name(const char* v) { short_name_ = v; } 

private:
  std::string id_;
  std::string short_name_;
  std::unique_ptr<InputBotInlineMessage> send_message_;
};

// botInlineMessageMediaAuto#a74b15b flags:# caption:string reply_markup:flags.2?ReplyMarkup = BotInlineMessage;
class TL_botInlineMessageMediaAuto : public BotInlineMessage {
public:
  enum {
    CLASS_ID = 0xa74b15b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botInlineMessageMediaAuto#0xa74b15b";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_caption() { return &caption_; } 
  const std::string& caption() const { return caption_; } 
  void set_caption(const std::string& v) { caption_ = v; } 
  void set_caption(const char* v, size_t n) { caption_.assign(v, n); } 
  void set_caption(const char* v) { caption_ = v; } 

private:
  int32_t flags_;
  std::string caption_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// botInlineMessageText#8c7f65e2 flags:# no_webpage:flags.0?true message:string entities:flags.1?Vector<MessageEntity> reply_markup:flags.2?ReplyMarkup = BotInlineMessage;
class TL_botInlineMessageText : public BotInlineMessage {
public:
  enum {
    CLASS_ID = 0x8c7f65e2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botInlineMessageText#0x8c7f65e2";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  int32_t flags_;
  bool no_webpage_ {false};
  std::string message_;
  TLObjectVector<MessageEntity> entities_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// botInlineMessageMediaGeo#3a8fd8b8 flags:# geo:GeoPoint reply_markup:flags.2?ReplyMarkup = BotInlineMessage;
class TL_botInlineMessageMediaGeo : public BotInlineMessage {
public:
  enum {
    CLASS_ID = 0x3a8fd8b8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botInlineMessageMediaGeo#0x3a8fd8b8";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<GeoPoint> geo_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// botInlineMessageMediaVenue#4366232e flags:# geo:GeoPoint title:string address:string provider:string venue_id:string reply_markup:flags.2?ReplyMarkup = BotInlineMessage;
class TL_botInlineMessageMediaVenue : public BotInlineMessage {
public:
  enum {
    CLASS_ID = 0x4366232e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botInlineMessageMediaVenue#0x4366232e";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_address() { return &address_; } 
  const std::string& address() const { return address_; } 
  void set_address(const std::string& v) { address_ = v; } 
  void set_address(const char* v, size_t n) { address_.assign(v, n); } 
  void set_address(const char* v) { address_ = v; } 

  std::string* mutable_provider() { return &provider_; } 
  const std::string& provider() const { return provider_; } 
  void set_provider(const std::string& v) { provider_ = v; } 
  void set_provider(const char* v, size_t n) { provider_.assign(v, n); } 
  void set_provider(const char* v) { provider_ = v; } 

  std::string* mutable_venue_id() { return &venue_id_; } 
  const std::string& venue_id() const { return venue_id_; } 
  void set_venue_id(const std::string& v) { venue_id_ = v; } 
  void set_venue_id(const char* v, size_t n) { venue_id_.assign(v, n); } 
  void set_venue_id(const char* v) { venue_id_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<GeoPoint> geo_;
  std::string title_;
  std::string address_;
  std::string provider_;
  std::string venue_id_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// botInlineMessageMediaContact#35edb4d4 flags:# phone_number:string first_name:string last_name:string reply_markup:flags.2?ReplyMarkup = BotInlineMessage;
class TL_botInlineMessageMediaContact : public BotInlineMessage {
public:
  enum {
    CLASS_ID = 0x35edb4d4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botInlineMessageMediaContact#0x35edb4d4";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

private:
  int32_t flags_;
  std::string phone_number_;
  std::string first_name_;
  std::string last_name_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// botInlineResult#9bebaeb9 flags:# id:string type:string title:flags.1?string description:flags.2?string url:flags.3?string thumb_url:flags.4?string content_url:flags.5?string content_type:flags.5?string w:flags.6?int h:flags.6?int duration:flags.7?int send_message:BotInlineMessage = BotInlineResult;
class TL_botInlineResult : public BotInlineResult {
public:
  enum {
    CLASS_ID = 0x9bebaeb9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botInlineResult#0x9bebaeb9";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_thumb_url() { return &thumb_url_; } 
  const std::string& thumb_url() const { return thumb_url_; } 
  void set_thumb_url(const std::string& v) { thumb_url_ = v; } 
  void set_thumb_url(const char* v, size_t n) { thumb_url_.assign(v, n); } 
  void set_thumb_url(const char* v) { thumb_url_ = v; } 

  std::string* mutable_content_url() { return &content_url_; } 
  const std::string& content_url() const { return content_url_; } 
  void set_content_url(const std::string& v) { content_url_ = v; } 
  void set_content_url(const char* v, size_t n) { content_url_.assign(v, n); } 
  void set_content_url(const char* v) { content_url_ = v; } 

  std::string* mutable_content_type() { return &content_type_; } 
  const std::string& content_type() const { return content_type_; } 
  void set_content_type(const std::string& v) { content_type_ = v; } 
  void set_content_type(const char* v, size_t n) { content_type_.assign(v, n); } 
  void set_content_type(const char* v) { content_type_ = v; } 

  int32_t w() const { return w_; } 
  void set_w(int32_t v) { w_ = v; } 

  int32_t h() const { return h_; } 
  void set_h(int32_t v) { h_ = v; } 

  int32_t duration() const { return duration_; } 
  void set_duration(int32_t v) { duration_ = v; } 

private:
  int32_t flags_;
  std::string id_;
  std::string type_;
  std::string title_;
  std::string description_;
  std::string url_;
  std::string thumb_url_;
  std::string content_url_;
  std::string content_type_;
  int32_t w_;
  int32_t h_;
  int32_t duration_;
  std::unique_ptr<BotInlineMessage> send_message_;
};

// botInlineMediaResult#17db940b flags:# id:string type:string photo:flags.0?Photo document:flags.1?Document title:flags.2?string description:flags.3?string send_message:BotInlineMessage = BotInlineResult;
class TL_botInlineMediaResult : public BotInlineResult {
public:
  enum {
    CLASS_ID = 0x17db940b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "botInlineMediaResult#0x17db940b";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_type() { return &type_; } 
  const std::string& type() const { return type_; } 
  void set_type(const std::string& v) { type_ = v; } 
  void set_type(const char* v, size_t n) { type_.assign(v, n); } 
  void set_type(const char* v) { type_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

private:
  int32_t flags_;
  std::string id_;
  std::string type_;
  std::unique_ptr<Photo> photo_;
  std::unique_ptr<Document> document_;
  std::string title_;
  std::string description_;
  std::unique_ptr<BotInlineMessage> send_message_;
};

// messages.botResults#ccd3563d flags:# gallery:flags.0?true query_id:long next_offset:flags.1?string switch_pm:flags.2?InlineBotSwitchPM results:Vector<BotInlineResult> cache_time:int = messages.BotResults;
class TL_messages_botResults : public messages_BotResults {
public:
  enum {
    CLASS_ID = 0xccd3563d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_botResults#0xccd3563d";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  std::string* mutable_next_offset() { return &next_offset_; } 
  const std::string& next_offset() const { return next_offset_; } 
  void set_next_offset(const std::string& v) { next_offset_ = v; } 
  void set_next_offset(const char* v, size_t n) { next_offset_.assign(v, n); } 
  void set_next_offset(const char* v) { next_offset_ = v; } 

  int32_t cache_time() const { return cache_time_; } 
  void set_cache_time(int32_t v) { cache_time_ = v; } 

private:
  int32_t flags_;
  bool gallery_ {false};
  int64_t query_id_;
  std::string next_offset_;
  std::unique_ptr<InlineBotSwitchPM> switch_pm_;
  TLObjectVector<BotInlineResult> results_;
  int32_t cache_time_;
};

// exportedMessageLink#1f486803 link:string = ExportedMessageLink;
class TL_exportedMessageLink : public ExportedMessageLink {
public:
  enum {
    CLASS_ID = 0x1f486803
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "exportedMessageLink#0x1f486803";
  }

  std::string* mutable_link() { return &link_; } 
  const std::string& link() const { return link_; } 
  void set_link(const std::string& v) { link_ = v; } 
  void set_link(const char* v, size_t n) { link_.assign(v, n); } 
  void set_link(const char* v) { link_ = v; } 

private:
  std::string link_;
};

// messageFwdHeader#c786ddcb flags:# from_id:flags.0?int date:int channel_id:flags.1?int channel_post:flags.2?int = MessageFwdHeader;
class TL_messageFwdHeader : public MessageFwdHeader {
public:
  enum {
    CLASS_ID = 0xc786ddcb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messageFwdHeader#0xc786ddcb";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t from_id() const { return from_id_; } 
  void set_from_id(int32_t v) { from_id_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t channel_id() const { return channel_id_; } 
  void set_channel_id(int32_t v) { channel_id_ = v; } 

  int32_t channel_post() const { return channel_post_; } 
  void set_channel_post(int32_t v) { channel_post_ = v; } 

private:
  int32_t flags_;
  int32_t from_id_;
  int32_t date_;
  int32_t channel_id_;
  int32_t channel_post_;
};

// auth.codeTypeSms#72a3158c = auth.CodeType;
class TL_auth_codeTypeSms : public auth_CodeType {
public:
  enum {
    CLASS_ID = 0x72a3158c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_codeTypeSms#0x72a3158c";
  }

private:
};

// auth.codeTypeCall#741cd3e3 = auth.CodeType;
class TL_auth_codeTypeCall : public auth_CodeType {
public:
  enum {
    CLASS_ID = 0x741cd3e3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_codeTypeCall#0x741cd3e3";
  }

private:
};

// auth.codeTypeFlashCall#226ccefb = auth.CodeType;
class TL_auth_codeTypeFlashCall : public auth_CodeType {
public:
  enum {
    CLASS_ID = 0x226ccefb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_codeTypeFlashCall#0x226ccefb";
  }

private:
};

// auth.sentCodeTypeApp#3dbb5986 length:int = auth.SentCodeType;
class TL_auth_sentCodeTypeApp : public auth_SentCodeType {
public:
  enum {
    CLASS_ID = 0x3dbb5986
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_sentCodeTypeApp#0x3dbb5986";
  }

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t length_;
};

// auth.sentCodeTypeSms#c000bba2 length:int = auth.SentCodeType;
class TL_auth_sentCodeTypeSms : public auth_SentCodeType {
public:
  enum {
    CLASS_ID = 0xc000bba2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_sentCodeTypeSms#0xc000bba2";
  }

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t length_;
};

// auth.sentCodeTypeCall#5353e5a7 length:int = auth.SentCodeType;
class TL_auth_sentCodeTypeCall : public auth_SentCodeType {
public:
  enum {
    CLASS_ID = 0x5353e5a7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_sentCodeTypeCall#0x5353e5a7";
  }

  int32_t length() const { return length_; } 
  void set_length(int32_t v) { length_ = v; } 

private:
  int32_t length_;
};

// auth.sentCodeTypeFlashCall#ab03c6d9 pattern:string = auth.SentCodeType;
class TL_auth_sentCodeTypeFlashCall : public auth_SentCodeType {
public:
  enum {
    CLASS_ID = 0xab03c6d9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_sentCodeTypeFlashCall#0xab03c6d9";
  }

  std::string* mutable_pattern() { return &pattern_; } 
  const std::string& pattern() const { return pattern_; } 
  void set_pattern(const std::string& v) { pattern_ = v; } 
  void set_pattern(const char* v, size_t n) { pattern_.assign(v, n); } 
  void set_pattern(const char* v) { pattern_ = v; } 

private:
  std::string pattern_;
};

// messages.botCallbackAnswer#36585ea4 flags:# alert:flags.1?true has_url:flags.3?true message:flags.0?string url:flags.2?string cache_time:int = messages.BotCallbackAnswer;
class TL_messages_botCallbackAnswer : public messages_BotCallbackAnswer {
public:
  enum {
    CLASS_ID = 0x36585ea4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_botCallbackAnswer#0x36585ea4";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  int32_t cache_time() const { return cache_time_; } 
  void set_cache_time(int32_t v) { cache_time_ = v; } 

private:
  int32_t flags_;
  bool alert_ {false};
  bool has_url_ {false};
  std::string message_;
  std::string url_;
  int32_t cache_time_;
};

// messages.messageEditData#26b5dde6 flags:# caption:flags.0?true = messages.MessageEditData;
class TL_messages_messageEditData : public messages_MessageEditData {
public:
  enum {
    CLASS_ID = 0x26b5dde6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_messageEditData#0x26b5dde6";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool caption_ {false};
};

// inputBotInlineMessageID#890c3d89 dc_id:int id:long access_hash:long = InputBotInlineMessageID;
class TL_inputBotInlineMessageID : public InputBotInlineMessageID {
public:
  enum {
    CLASS_ID = 0x890c3d89
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputBotInlineMessageID#0x890c3d89";
  }

  int32_t dc_id() const { return dc_id_; } 
  void set_dc_id(int32_t v) { dc_id_ = v; } 

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int32_t dc_id_;
  int64_t id_;
  int64_t access_hash_;
};

// inlineBotSwitchPM#3c20629f text:string start_param:string = InlineBotSwitchPM;
class TL_inlineBotSwitchPM : public InlineBotSwitchPM {
public:
  enum {
    CLASS_ID = 0x3c20629f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inlineBotSwitchPM#0x3c20629f";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

  std::string* mutable_start_param() { return &start_param_; } 
  const std::string& start_param() const { return start_param_; } 
  void set_start_param(const std::string& v) { start_param_ = v; } 
  void set_start_param(const char* v, size_t n) { start_param_.assign(v, n); } 
  void set_start_param(const char* v) { start_param_ = v; } 

private:
  std::string text_;
  std::string start_param_;
};

// messages.peerDialogs#3371c354 dialogs:Vector<Dialog> messages:Vector<Message> chats:Vector<Chat> users:Vector<User> state:updates.State = messages.PeerDialogs;
class TL_messages_peerDialogs : public messages_PeerDialogs {
public:
  enum {
    CLASS_ID = 0x3371c354
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_peerDialogs#0x3371c354";
  }

private:
  TLObjectVector<Dialog> dialogs_;
  TLObjectVector<Message> messages_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
  std::unique_ptr<updates_State> state_;
};

// topPeer#edcdc05b peer:Peer rating:double = TopPeer;
class TL_topPeer : public TopPeer {
public:
  enum {
    CLASS_ID = 0xedcdc05b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "topPeer#0xedcdc05b";
  }

private:
  std::unique_ptr<Peer> peer_;
  double rating_;
};

// topPeerCategoryBotsPM#ab661b5b = TopPeerCategory;
class TL_topPeerCategoryBotsPM : public TopPeerCategory {
public:
  enum {
    CLASS_ID = 0xab661b5b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "topPeerCategoryBotsPM#0xab661b5b";
  }

private:
};

// topPeerCategoryBotsInline#148677e2 = TopPeerCategory;
class TL_topPeerCategoryBotsInline : public TopPeerCategory {
public:
  enum {
    CLASS_ID = 0x148677e2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "topPeerCategoryBotsInline#0x148677e2";
  }

private:
};

// topPeerCategoryCorrespondents#637b7ed = TopPeerCategory;
class TL_topPeerCategoryCorrespondents : public TopPeerCategory {
public:
  enum {
    CLASS_ID = 0x637b7ed
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "topPeerCategoryCorrespondents#0x637b7ed";
  }

private:
};

// topPeerCategoryGroups#bd17a14a = TopPeerCategory;
class TL_topPeerCategoryGroups : public TopPeerCategory {
public:
  enum {
    CLASS_ID = 0xbd17a14a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "topPeerCategoryGroups#0xbd17a14a";
  }

private:
};

// topPeerCategoryChannels#161d9628 = TopPeerCategory;
class TL_topPeerCategoryChannels : public TopPeerCategory {
public:
  enum {
    CLASS_ID = 0x161d9628
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "topPeerCategoryChannels#0x161d9628";
  }

private:
};

// topPeerCategoryPeers#fb834291 category:TopPeerCategory count:int peers:Vector<TopPeer> = TopPeerCategoryPeers;
class TL_topPeerCategoryPeers : public TopPeerCategoryPeers {
public:
  enum {
    CLASS_ID = 0xfb834291
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "topPeerCategoryPeers#0xfb834291";
  }

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  std::unique_ptr<TopPeerCategory> category_;
  int32_t count_;
  TLObjectVector<TopPeer> peers_;
};

// contacts.topPeersNotModified#de266ef5 = contacts.TopPeers;
class TL_contacts_topPeersNotModified : public contacts_TopPeers {
public:
  enum {
    CLASS_ID = 0xde266ef5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_topPeersNotModified#0xde266ef5";
  }

private:
};

// contacts.topPeers#70b772a8 categories:Vector<TopPeerCategoryPeers> chats:Vector<Chat> users:Vector<User> = contacts.TopPeers;
class TL_contacts_topPeers : public contacts_TopPeers {
public:
  enum {
    CLASS_ID = 0x70b772a8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_topPeers#0x70b772a8";
  }

private:
  TLObjectVector<TopPeerCategoryPeers> categories_;
  TLObjectVector<Chat> chats_;
  TLObjectVector<User> users_;
};

// draftMessageEmpty#ba4baec5 = DraftMessage;
class TL_draftMessageEmpty : public DraftMessage {
public:
  enum {
    CLASS_ID = 0xba4baec5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "draftMessageEmpty#0xba4baec5";
  }

private:
};

// draftMessage#fd8e711f flags:# no_webpage:flags.1?true reply_to_msg_id:flags.0?int message:string entities:flags.3?Vector<MessageEntity> date:int = DraftMessage;
class TL_draftMessage : public DraftMessage {
public:
  enum {
    CLASS_ID = 0xfd8e711f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "draftMessage#0xfd8e711f";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  int32_t flags_;
  bool no_webpage_ {false};
  int32_t reply_to_msg_id_;
  std::string message_;
  TLObjectVector<MessageEntity> entities_;
  int32_t date_;
};

// messages.featuredStickersNotModified#4ede3cf = messages.FeaturedStickers;
class TL_messages_featuredStickersNotModified : public messages_FeaturedStickers {
public:
  enum {
    CLASS_ID = 0x4ede3cf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_featuredStickersNotModified#0x4ede3cf";
  }

private:
};

// messages.featuredStickers#f89d88e5 hash:int sets:Vector<StickerSetCovered> unread:Vector<long> = messages.FeaturedStickers;
class TL_messages_featuredStickers : public messages_FeaturedStickers {
public:
  enum {
    CLASS_ID = 0xf89d88e5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_featuredStickers#0xf89d88e5";
  }

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

  size_t unread_size() const { return unread_.size(); } 
  const TLInt64Vector& unread() const { return unread_; } 
  int64_t unread(int idx) const { return unread_.vector()[idx]; } 
  void add_unread(int64_t v) {unread_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_unread() { return &unread_; } 

private:
  int32_t hash_;
  TLObjectVector<StickerSetCovered> sets_;
  TLInt64Vector unread_;
};

// messages.recentStickersNotModified#b17f890 = messages.RecentStickers;
class TL_messages_recentStickersNotModified : public messages_RecentStickers {
public:
  enum {
    CLASS_ID = 0xb17f890
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_recentStickersNotModified#0xb17f890";
  }

private:
};

// messages.recentStickers#5ce20970 hash:int stickers:Vector<Document> = messages.RecentStickers;
class TL_messages_recentStickers : public messages_RecentStickers {
public:
  enum {
    CLASS_ID = 0x5ce20970
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_recentStickers#0x5ce20970";
  }

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t hash_;
  TLObjectVector<Document> stickers_;
};

// messages.archivedStickers#4fcba9c8 count:int sets:Vector<StickerSetCovered> = messages.ArchivedStickers;
class TL_messages_archivedStickers : public messages_ArchivedStickers {
public:
  enum {
    CLASS_ID = 0x4fcba9c8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_archivedStickers#0x4fcba9c8";
  }

  int32_t count() const { return count_; } 
  void set_count(int32_t v) { count_ = v; } 

private:
  int32_t count_;
  TLObjectVector<StickerSetCovered> sets_;
};

// messages.stickerSetInstallResultSuccess#38641628 = messages.StickerSetInstallResult;
class TL_messages_stickerSetInstallResultSuccess : public messages_StickerSetInstallResult {
public:
  enum {
    CLASS_ID = 0x38641628
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_stickerSetInstallResultSuccess#0x38641628";
  }

private:
};

// messages.stickerSetInstallResultArchive#35e410a8 sets:Vector<StickerSetCovered> = messages.StickerSetInstallResult;
class TL_messages_stickerSetInstallResultArchive : public messages_StickerSetInstallResult {
public:
  enum {
    CLASS_ID = 0x35e410a8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_stickerSetInstallResultArchive#0x35e410a8";
  }

private:
  TLObjectVector<StickerSetCovered> sets_;
};

// stickerSetCovered#6410a5d2 set:StickerSet cover:Document = StickerSetCovered;
class TL_stickerSetCovered : public StickerSetCovered {
public:
  enum {
    CLASS_ID = 0x6410a5d2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "stickerSetCovered#0x6410a5d2";
  }

private:
  std::unique_ptr<StickerSet> set_;
  std::unique_ptr<Document> cover_;
};

// stickerSetMultiCovered#3407e51b set:StickerSet covers:Vector<Document> = StickerSetCovered;
class TL_stickerSetMultiCovered : public StickerSetCovered {
public:
  enum {
    CLASS_ID = 0x3407e51b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "stickerSetMultiCovered#0x3407e51b";
  }

private:
  std::unique_ptr<StickerSet> set_;
  TLObjectVector<Document> covers_;
};

// maskCoords#aed6dbb2 n:int x:double y:double zoom:double = MaskCoords;
class TL_maskCoords : public MaskCoords {
public:
  enum {
    CLASS_ID = 0xaed6dbb2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "maskCoords#0xaed6dbb2";
  }

  int32_t n() const { return n_; } 
  void set_n(int32_t v) { n_ = v; } 

private:
  int32_t n_;
  double x_;
  double y_;
  double zoom_;
};

// inputStickeredMediaPhoto#4a992157 id:InputPhoto = InputStickeredMedia;
class TL_inputStickeredMediaPhoto : public InputStickeredMedia {
public:
  enum {
    CLASS_ID = 0x4a992157
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputStickeredMediaPhoto#0x4a992157";
  }

private:
  std::unique_ptr<InputPhoto> id_;
};

// inputStickeredMediaDocument#438865b id:InputDocument = InputStickeredMedia;
class TL_inputStickeredMediaDocument : public InputStickeredMedia {
public:
  enum {
    CLASS_ID = 0x438865b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputStickeredMediaDocument#0x438865b";
  }

private:
  std::unique_ptr<InputDocument> id_;
};

// game#bdf9653b flags:# id:long access_hash:long short_name:string title:string description:string photo:Photo document:flags.0?Document = Game;
class TL_game : public Game {
public:
  enum {
    CLASS_ID = 0xbdf9653b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "game#0xbdf9653b";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  std::string* mutable_short_name() { return &short_name_; } 
  const std::string& short_name() const { return short_name_; } 
  void set_short_name(const std::string& v) { short_name_ = v; } 
  void set_short_name(const char* v, size_t n) { short_name_.assign(v, n); } 
  void set_short_name(const char* v) { short_name_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_description() { return &description_; } 
  const std::string& description() const { return description_; } 
  void set_description(const std::string& v) { description_ = v; } 
  void set_description(const char* v, size_t n) { description_.assign(v, n); } 
  void set_description(const char* v) { description_ = v; } 

private:
  int32_t flags_;
  int64_t id_;
  int64_t access_hash_;
  std::string short_name_;
  std::string title_;
  std::string description_;
  std::unique_ptr<Photo> photo_;
  std::unique_ptr<Document> document_;
};

// inputGameID#32c3e77 id:long access_hash:long = InputGame;
class TL_inputGameID : public InputGame {
public:
  enum {
    CLASS_ID = 0x32c3e77
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputGameID#0x32c3e77";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
};

// inputGameShortName#c331e80a bot_id:InputUser short_name:string = InputGame;
class TL_inputGameShortName : public InputGame {
public:
  enum {
    CLASS_ID = 0xc331e80a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputGameShortName#0xc331e80a";
  }

  std::string* mutable_short_name() { return &short_name_; } 
  const std::string& short_name() const { return short_name_; } 
  void set_short_name(const std::string& v) { short_name_ = v; } 
  void set_short_name(const char* v, size_t n) { short_name_.assign(v, n); } 
  void set_short_name(const char* v) { short_name_ = v; } 

private:
  std::unique_ptr<InputUser> bot_id_;
  std::string short_name_;
};

// highScore#58fffcd0 pos:int user_id:int score:int = HighScore;
class TL_highScore : public HighScore {
public:
  enum {
    CLASS_ID = 0x58fffcd0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "highScore#0x58fffcd0";
  }

  int32_t pos() const { return pos_; } 
  void set_pos(int32_t v) { pos_ = v; } 

  int32_t user_id() const { return user_id_; } 
  void set_user_id(int32_t v) { user_id_ = v; } 

  int32_t score() const { return score_; } 
  void set_score(int32_t v) { score_ = v; } 

private:
  int32_t pos_;
  int32_t user_id_;
  int32_t score_;
};

// messages.highScores#9a3bfd99 scores:Vector<HighScore> users:Vector<User> = messages.HighScores;
class TL_messages_highScores : public messages_HighScores {
public:
  enum {
    CLASS_ID = 0x9a3bfd99
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_highScores#0x9a3bfd99";
  }

private:
  TLObjectVector<HighScore> scores_;
  TLObjectVector<User> users_;
};

// textEmpty#dc3d824f = RichText;
class TL_textEmpty : public RichText {
public:
  enum {
    CLASS_ID = 0xdc3d824f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textEmpty#0xdc3d824f";
  }

private:
};

// textPlain#744694e0 text:string = RichText;
class TL_textPlain : public RichText {
public:
  enum {
    CLASS_ID = 0x744694e0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textPlain#0x744694e0";
  }

  std::string* mutable_text() { return &text_; } 
  const std::string& text() const { return text_; } 
  void set_text(const std::string& v) { text_ = v; } 
  void set_text(const char* v, size_t n) { text_.assign(v, n); } 
  void set_text(const char* v) { text_ = v; } 

private:
  std::string text_;
};

// textBold#6724abc4 text:RichText = RichText;
class TL_textBold : public RichText {
public:
  enum {
    CLASS_ID = 0x6724abc4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textBold#0x6724abc4";
  }

private:
  std::unique_ptr<RichText> text_;
};

// textItalic#d912a59c text:RichText = RichText;
class TL_textItalic : public RichText {
public:
  enum {
    CLASS_ID = 0xd912a59c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textItalic#0xd912a59c";
  }

private:
  std::unique_ptr<RichText> text_;
};

// textUnderline#c12622c4 text:RichText = RichText;
class TL_textUnderline : public RichText {
public:
  enum {
    CLASS_ID = 0xc12622c4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textUnderline#0xc12622c4";
  }

private:
  std::unique_ptr<RichText> text_;
};

// textStrike#9bf8bb95 text:RichText = RichText;
class TL_textStrike : public RichText {
public:
  enum {
    CLASS_ID = 0x9bf8bb95
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textStrike#0x9bf8bb95";
  }

private:
  std::unique_ptr<RichText> text_;
};

// textFixed#6c3f19b9 text:RichText = RichText;
class TL_textFixed : public RichText {
public:
  enum {
    CLASS_ID = 0x6c3f19b9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textFixed#0x6c3f19b9";
  }

private:
  std::unique_ptr<RichText> text_;
};

// textUrl#3c2884c1 text:RichText url:string webpage_id:long = RichText;
class TL_textUrl : public RichText {
public:
  enum {
    CLASS_ID = 0x3c2884c1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textUrl#0x3c2884c1";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  int64_t webpage_id() const { return webpage_id_; } 
  void set_webpage_id(int64_t v) { webpage_id_ = v; } 

private:
  std::unique_ptr<RichText> text_;
  std::string url_;
  int64_t webpage_id_;
};

// textEmail#de5a0dd6 text:RichText email:string = RichText;
class TL_textEmail : public RichText {
public:
  enum {
    CLASS_ID = 0xde5a0dd6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textEmail#0xde5a0dd6";
  }

  std::string* mutable_email() { return &email_; } 
  const std::string& email() const { return email_; } 
  void set_email(const std::string& v) { email_ = v; } 
  void set_email(const char* v, size_t n) { email_.assign(v, n); } 
  void set_email(const char* v) { email_ = v; } 

private:
  std::unique_ptr<RichText> text_;
  std::string email_;
};

// textConcat#7e6260d7 texts:Vector<RichText> = RichText;
class TL_textConcat : public RichText {
public:
  enum {
    CLASS_ID = 0x7e6260d7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "textConcat#0x7e6260d7";
  }

private:
  TLObjectVector<RichText> texts_;
};

// pageBlockUnsupported#13567e8a = PageBlock;
class TL_pageBlockUnsupported : public PageBlock {
public:
  enum {
    CLASS_ID = 0x13567e8a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockUnsupported#0x13567e8a";
  }

private:
};

// pageBlockTitle#70abc3fd text:RichText = PageBlock;
class TL_pageBlockTitle : public PageBlock {
public:
  enum {
    CLASS_ID = 0x70abc3fd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockTitle#0x70abc3fd";
  }

private:
  std::unique_ptr<RichText> text_;
};

// pageBlockSubtitle#8ffa9a1f text:RichText = PageBlock;
class TL_pageBlockSubtitle : public PageBlock {
public:
  enum {
    CLASS_ID = 0x8ffa9a1f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockSubtitle#0x8ffa9a1f";
  }

private:
  std::unique_ptr<RichText> text_;
};

// pageBlockAuthorDate#baafe5e0 author:RichText published_date:int = PageBlock;
class TL_pageBlockAuthorDate : public PageBlock {
public:
  enum {
    CLASS_ID = 0xbaafe5e0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockAuthorDate#0xbaafe5e0";
  }

  int32_t published_date() const { return published_date_; } 
  void set_published_date(int32_t v) { published_date_ = v; } 

private:
  std::unique_ptr<RichText> author_;
  int32_t published_date_;
};

// pageBlockHeader#bfd064ec text:RichText = PageBlock;
class TL_pageBlockHeader : public PageBlock {
public:
  enum {
    CLASS_ID = 0xbfd064ec
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockHeader#0xbfd064ec";
  }

private:
  std::unique_ptr<RichText> text_;
};

// pageBlockSubheader#f12bb6e1 text:RichText = PageBlock;
class TL_pageBlockSubheader : public PageBlock {
public:
  enum {
    CLASS_ID = 0xf12bb6e1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockSubheader#0xf12bb6e1";
  }

private:
  std::unique_ptr<RichText> text_;
};

// pageBlockParagraph#467a0766 text:RichText = PageBlock;
class TL_pageBlockParagraph : public PageBlock {
public:
  enum {
    CLASS_ID = 0x467a0766
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockParagraph#0x467a0766";
  }

private:
  std::unique_ptr<RichText> text_;
};

// pageBlockPreformatted#c070d93e text:RichText language:string = PageBlock;
class TL_pageBlockPreformatted : public PageBlock {
public:
  enum {
    CLASS_ID = 0xc070d93e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockPreformatted#0xc070d93e";
  }

  std::string* mutable_language() { return &language_; } 
  const std::string& language() const { return language_; } 
  void set_language(const std::string& v) { language_ = v; } 
  void set_language(const char* v, size_t n) { language_.assign(v, n); } 
  void set_language(const char* v) { language_ = v; } 

private:
  std::unique_ptr<RichText> text_;
  std::string language_;
};

// pageBlockFooter#48870999 text:RichText = PageBlock;
class TL_pageBlockFooter : public PageBlock {
public:
  enum {
    CLASS_ID = 0x48870999
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockFooter#0x48870999";
  }

private:
  std::unique_ptr<RichText> text_;
};

// pageBlockDivider#db20b188 = PageBlock;
class TL_pageBlockDivider : public PageBlock {
public:
  enum {
    CLASS_ID = 0xdb20b188
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockDivider#0xdb20b188";
  }

private:
};

// pageBlockAnchor#ce0d37b0 name:string = PageBlock;
class TL_pageBlockAnchor : public PageBlock {
public:
  enum {
    CLASS_ID = 0xce0d37b0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockAnchor#0xce0d37b0";
  }

  std::string* mutable_name() { return &name_; } 
  const std::string& name() const { return name_; } 
  void set_name(const std::string& v) { name_ = v; } 
  void set_name(const char* v, size_t n) { name_.assign(v, n); } 
  void set_name(const char* v) { name_ = v; } 

private:
  std::string name_;
};

// pageBlockList#3a58c7f4 ordered:Bool items:Vector<RichText> = PageBlock;
class TL_pageBlockList : public PageBlock {
public:
  enum {
    CLASS_ID = 0x3a58c7f4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockList#0x3a58c7f4";
  }

private:
  std::unique_ptr<Bool> ordered_;
  TLObjectVector<RichText> items_;
};

// pageBlockBlockquote#263d7c26 text:RichText caption:RichText = PageBlock;
class TL_pageBlockBlockquote : public PageBlock {
public:
  enum {
    CLASS_ID = 0x263d7c26
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockBlockquote#0x263d7c26";
  }

private:
  std::unique_ptr<RichText> text_;
  std::unique_ptr<RichText> caption_;
};

// pageBlockPullquote#4f4456d3 text:RichText caption:RichText = PageBlock;
class TL_pageBlockPullquote : public PageBlock {
public:
  enum {
    CLASS_ID = 0x4f4456d3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockPullquote#0x4f4456d3";
  }

private:
  std::unique_ptr<RichText> text_;
  std::unique_ptr<RichText> caption_;
};

// pageBlockPhoto#e9c69982 photo_id:long caption:RichText = PageBlock;
class TL_pageBlockPhoto : public PageBlock {
public:
  enum {
    CLASS_ID = 0xe9c69982
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockPhoto#0xe9c69982";
  }

  int64_t photo_id() const { return photo_id_; } 
  void set_photo_id(int64_t v) { photo_id_ = v; } 

private:
  int64_t photo_id_;
  std::unique_ptr<RichText> caption_;
};

// pageBlockVideo#d9d71866 flags:# autoplay:flags.0?true loop:flags.1?true video_id:long caption:RichText = PageBlock;
class TL_pageBlockVideo : public PageBlock {
public:
  enum {
    CLASS_ID = 0xd9d71866
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockVideo#0xd9d71866";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t video_id() const { return video_id_; } 
  void set_video_id(int64_t v) { video_id_ = v; } 

private:
  int32_t flags_;
  bool autoplay_ {false};
  bool loop_ {false};
  int64_t video_id_;
  std::unique_ptr<RichText> caption_;
};

// pageBlockCover#39f23300 cover:PageBlock = PageBlock;
class TL_pageBlockCover : public PageBlock {
public:
  enum {
    CLASS_ID = 0x39f23300
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockCover#0x39f23300";
  }

private:
  std::unique_ptr<PageBlock> cover_;
};

// pageBlockEmbed#cde200d1 flags:# full_width:flags.0?true allow_scrolling:flags.3?true url:flags.1?string html:flags.2?string poster_photo_id:flags.4?long w:int h:int caption:RichText = PageBlock;
class TL_pageBlockEmbed : public PageBlock {
public:
  enum {
    CLASS_ID = 0xcde200d1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockEmbed#0xcde200d1";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_html() { return &html_; } 
  const std::string& html() const { return html_; } 
  void set_html(const std::string& v) { html_ = v; } 
  void set_html(const char* v, size_t n) { html_.assign(v, n); } 
  void set_html(const char* v) { html_ = v; } 

  int64_t poster_photo_id() const { return poster_photo_id_; } 
  void set_poster_photo_id(int64_t v) { poster_photo_id_ = v; } 

  int32_t w() const { return w_; } 
  void set_w(int32_t v) { w_ = v; } 

  int32_t h() const { return h_; } 
  void set_h(int32_t v) { h_ = v; } 

private:
  int32_t flags_;
  bool full_width_ {false};
  bool allow_scrolling_ {false};
  std::string url_;
  std::string html_;
  int64_t poster_photo_id_;
  int32_t w_;
  int32_t h_;
  std::unique_ptr<RichText> caption_;
};

// pageBlockEmbedPost#292c7be9 url:string webpage_id:long author_photo_id:long author:string date:int blocks:Vector<PageBlock> caption:RichText = PageBlock;
class TL_pageBlockEmbedPost : public PageBlock {
public:
  enum {
    CLASS_ID = 0x292c7be9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockEmbedPost#0x292c7be9";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  int64_t webpage_id() const { return webpage_id_; } 
  void set_webpage_id(int64_t v) { webpage_id_ = v; } 

  int64_t author_photo_id() const { return author_photo_id_; } 
  void set_author_photo_id(int64_t v) { author_photo_id_ = v; } 

  std::string* mutable_author() { return &author_; } 
  const std::string& author() const { return author_; } 
  void set_author(const std::string& v) { author_ = v; } 
  void set_author(const char* v, size_t n) { author_.assign(v, n); } 
  void set_author(const char* v) { author_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

private:
  std::string url_;
  int64_t webpage_id_;
  int64_t author_photo_id_;
  std::string author_;
  int32_t date_;
  TLObjectVector<PageBlock> blocks_;
  std::unique_ptr<RichText> caption_;
};

// pageBlockCollage#8b31c4f items:Vector<PageBlock> caption:RichText = PageBlock;
class TL_pageBlockCollage : public PageBlock {
public:
  enum {
    CLASS_ID = 0x8b31c4f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockCollage#0x8b31c4f";
  }

private:
  TLObjectVector<PageBlock> items_;
  std::unique_ptr<RichText> caption_;
};

// pageBlockSlideshow#130c8963 items:Vector<PageBlock> caption:RichText = PageBlock;
class TL_pageBlockSlideshow : public PageBlock {
public:
  enum {
    CLASS_ID = 0x130c8963
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockSlideshow#0x130c8963";
  }

private:
  TLObjectVector<PageBlock> items_;
  std::unique_ptr<RichText> caption_;
};

// pageBlockChannel#ef1751b5 channel:Chat = PageBlock;
class TL_pageBlockChannel : public PageBlock {
public:
  enum {
    CLASS_ID = 0xef1751b5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageBlockChannel#0xef1751b5";
  }

private:
  std::unique_ptr<Chat> channel_;
};

// pagePart#8dee6c44 blocks:Vector<PageBlock> photos:Vector<Photo> videos:Vector<Document> = Page;
class TL_pagePart : public Page {
public:
  enum {
    CLASS_ID = 0x8dee6c44
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pagePart#0x8dee6c44";
  }

private:
  TLObjectVector<PageBlock> blocks_;
  TLObjectVector<Photo> photos_;
  TLObjectVector<Document> videos_;
};

// pageFull#d7a19d69 blocks:Vector<PageBlock> photos:Vector<Photo> videos:Vector<Document> = Page;
class TL_pageFull : public Page {
public:
  enum {
    CLASS_ID = 0xd7a19d69
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "pageFull#0xd7a19d69";
  }

private:
  TLObjectVector<PageBlock> blocks_;
  TLObjectVector<Photo> photos_;
  TLObjectVector<Document> videos_;
};

// phoneCallDiscardReasonMissed#85e42301 = PhoneCallDiscardReason;
class TL_phoneCallDiscardReasonMissed : public PhoneCallDiscardReason {
public:
  enum {
    CLASS_ID = 0x85e42301
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallDiscardReasonMissed#0x85e42301";
  }

private:
};

// phoneCallDiscardReasonDisconnect#e095c1a0 = PhoneCallDiscardReason;
class TL_phoneCallDiscardReasonDisconnect : public PhoneCallDiscardReason {
public:
  enum {
    CLASS_ID = 0xe095c1a0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallDiscardReasonDisconnect#0xe095c1a0";
  }

private:
};

// phoneCallDiscardReasonHangup#57adc690 = PhoneCallDiscardReason;
class TL_phoneCallDiscardReasonHangup : public PhoneCallDiscardReason {
public:
  enum {
    CLASS_ID = 0x57adc690
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallDiscardReasonHangup#0x57adc690";
  }

private:
};

// phoneCallDiscardReasonBusy#faf7e8c9 = PhoneCallDiscardReason;
class TL_phoneCallDiscardReasonBusy : public PhoneCallDiscardReason {
public:
  enum {
    CLASS_ID = 0xfaf7e8c9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallDiscardReasonBusy#0xfaf7e8c9";
  }

private:
};

// dataJSON#7d748d04 data:string = DataJSON;
class TL_dataJSON : public DataJSON {
public:
  enum {
    CLASS_ID = 0x7d748d04
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "dataJSON#0x7d748d04";
  }

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

private:
  std::string data_;
};

// labeledPrice#cb296bf8 label:string amount:long = LabeledPrice;
class TL_labeledPrice : public LabeledPrice {
public:
  enum {
    CLASS_ID = 0xcb296bf8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "labeledPrice#0xcb296bf8";
  }

  std::string* mutable_label() { return &label_; } 
  const std::string& label() const { return label_; } 
  void set_label(const std::string& v) { label_ = v; } 
  void set_label(const char* v, size_t n) { label_.assign(v, n); } 
  void set_label(const char* v) { label_ = v; } 

  int64_t amount() const { return amount_; } 
  void set_amount(int64_t v) { amount_ = v; } 

private:
  std::string label_;
  int64_t amount_;
};

// invoice#c30aa358 flags:# test:flags.0?true name_requested:flags.1?true phone_requested:flags.2?true email_requested:flags.3?true shipping_address_requested:flags.4?true flexible:flags.5?true currency:string prices:Vector<LabeledPrice> = Invoice;
class TL_invoice : public Invoice {
public:
  enum {
    CLASS_ID = 0xc30aa358
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "invoice#0xc30aa358";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_currency() { return &currency_; } 
  const std::string& currency() const { return currency_; } 
  void set_currency(const std::string& v) { currency_ = v; } 
  void set_currency(const char* v, size_t n) { currency_.assign(v, n); } 
  void set_currency(const char* v) { currency_ = v; } 

private:
  int32_t flags_;
  bool test_ {false};
  bool name_requested_ {false};
  bool phone_requested_ {false};
  bool email_requested_ {false};
  bool shipping_address_requested_ {false};
  bool flexible_ {false};
  std::string currency_;
  TLObjectVector<LabeledPrice> prices_;
};

// paymentCharge#ea02c27e id:string provider_charge_id:string = PaymentCharge;
class TL_paymentCharge : public PaymentCharge {
public:
  enum {
    CLASS_ID = 0xea02c27e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "paymentCharge#0xea02c27e";
  }

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_provider_charge_id() { return &provider_charge_id_; } 
  const std::string& provider_charge_id() const { return provider_charge_id_; } 
  void set_provider_charge_id(const std::string& v) { provider_charge_id_ = v; } 
  void set_provider_charge_id(const char* v, size_t n) { provider_charge_id_.assign(v, n); } 
  void set_provider_charge_id(const char* v) { provider_charge_id_ = v; } 

private:
  std::string id_;
  std::string provider_charge_id_;
};

// postAddress#1e8caaeb street_line1:string street_line2:string city:string state:string country_iso2:string post_code:string = PostAddress;
class TL_postAddress : public PostAddress {
public:
  enum {
    CLASS_ID = 0x1e8caaeb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "postAddress#0x1e8caaeb";
  }

  std::string* mutable_street_line1() { return &street_line1_; } 
  const std::string& street_line1() const { return street_line1_; } 
  void set_street_line1(const std::string& v) { street_line1_ = v; } 
  void set_street_line1(const char* v, size_t n) { street_line1_.assign(v, n); } 
  void set_street_line1(const char* v) { street_line1_ = v; } 

  std::string* mutable_street_line2() { return &street_line2_; } 
  const std::string& street_line2() const { return street_line2_; } 
  void set_street_line2(const std::string& v) { street_line2_ = v; } 
  void set_street_line2(const char* v, size_t n) { street_line2_.assign(v, n); } 
  void set_street_line2(const char* v) { street_line2_ = v; } 

  std::string* mutable_city() { return &city_; } 
  const std::string& city() const { return city_; } 
  void set_city(const std::string& v) { city_ = v; } 
  void set_city(const char* v, size_t n) { city_.assign(v, n); } 
  void set_city(const char* v) { city_ = v; } 

  std::string* mutable_state() { return &state_; } 
  const std::string& state() const { return state_; } 
  void set_state(const std::string& v) { state_ = v; } 
  void set_state(const char* v, size_t n) { state_.assign(v, n); } 
  void set_state(const char* v) { state_ = v; } 

  std::string* mutable_country_iso2() { return &country_iso2_; } 
  const std::string& country_iso2() const { return country_iso2_; } 
  void set_country_iso2(const std::string& v) { country_iso2_ = v; } 
  void set_country_iso2(const char* v, size_t n) { country_iso2_.assign(v, n); } 
  void set_country_iso2(const char* v) { country_iso2_ = v; } 

  std::string* mutable_post_code() { return &post_code_; } 
  const std::string& post_code() const { return post_code_; } 
  void set_post_code(const std::string& v) { post_code_ = v; } 
  void set_post_code(const char* v, size_t n) { post_code_.assign(v, n); } 
  void set_post_code(const char* v) { post_code_ = v; } 

private:
  std::string street_line1_;
  std::string street_line2_;
  std::string city_;
  std::string state_;
  std::string country_iso2_;
  std::string post_code_;
};

// paymentRequestedInfo#909c3f94 flags:# name:flags.0?string phone:flags.1?string email:flags.2?string shipping_address:flags.3?PostAddress = PaymentRequestedInfo;
class TL_paymentRequestedInfo : public PaymentRequestedInfo {
public:
  enum {
    CLASS_ID = 0x909c3f94
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "paymentRequestedInfo#0x909c3f94";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_name() { return &name_; } 
  const std::string& name() const { return name_; } 
  void set_name(const std::string& v) { name_ = v; } 
  void set_name(const char* v, size_t n) { name_.assign(v, n); } 
  void set_name(const char* v) { name_ = v; } 

  std::string* mutable_phone() { return &phone_; } 
  const std::string& phone() const { return phone_; } 
  void set_phone(const std::string& v) { phone_ = v; } 
  void set_phone(const char* v, size_t n) { phone_.assign(v, n); } 
  void set_phone(const char* v) { phone_ = v; } 

  std::string* mutable_email() { return &email_; } 
  const std::string& email() const { return email_; } 
  void set_email(const std::string& v) { email_ = v; } 
  void set_email(const char* v, size_t n) { email_.assign(v, n); } 
  void set_email(const char* v) { email_ = v; } 

private:
  int32_t flags_;
  std::string name_;
  std::string phone_;
  std::string email_;
  std::unique_ptr<PostAddress> shipping_address_;
};

// paymentSavedCredentialsCard#cdc27a1f id:string title:string = PaymentSavedCredentials;
class TL_paymentSavedCredentialsCard : public PaymentSavedCredentials {
public:
  enum {
    CLASS_ID = 0xcdc27a1f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "paymentSavedCredentialsCard#0xcdc27a1f";
  }

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  std::string id_;
  std::string title_;
};

// webDocument#c61acbd8 url:string access_hash:long size:int mime_type:string attributes:Vector<DocumentAttribute> dc_id:int = WebDocument;
class TL_webDocument : public WebDocument {
public:
  enum {
    CLASS_ID = 0xc61acbd8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "webDocument#0xc61acbd8";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t size() const { return size_; } 
  void set_size(int32_t v) { size_ = v; } 

  std::string* mutable_mime_type() { return &mime_type_; } 
  const std::string& mime_type() const { return mime_type_; } 
  void set_mime_type(const std::string& v) { mime_type_ = v; } 
  void set_mime_type(const char* v, size_t n) { mime_type_.assign(v, n); } 
  void set_mime_type(const char* v) { mime_type_ = v; } 

  int32_t dc_id() const { return dc_id_; } 
  void set_dc_id(int32_t v) { dc_id_ = v; } 

private:
  std::string url_;
  int64_t access_hash_;
  int32_t size_;
  std::string mime_type_;
  TLObjectVector<DocumentAttribute> attributes_;
  int32_t dc_id_;
};

// inputWebDocument#9bed434d url:string size:int mime_type:string attributes:Vector<DocumentAttribute> = InputWebDocument;
class TL_inputWebDocument : public InputWebDocument {
public:
  enum {
    CLASS_ID = 0x9bed434d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputWebDocument#0x9bed434d";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  int32_t size() const { return size_; } 
  void set_size(int32_t v) { size_ = v; } 

  std::string* mutable_mime_type() { return &mime_type_; } 
  const std::string& mime_type() const { return mime_type_; } 
  void set_mime_type(const std::string& v) { mime_type_ = v; } 
  void set_mime_type(const char* v, size_t n) { mime_type_.assign(v, n); } 
  void set_mime_type(const char* v) { mime_type_ = v; } 

private:
  std::string url_;
  int32_t size_;
  std::string mime_type_;
  TLObjectVector<DocumentAttribute> attributes_;
};

// inputWebFileLocation#c239d686 url:string access_hash:long = InputWebFileLocation;
class TL_inputWebFileLocation : public InputWebFileLocation {
public:
  enum {
    CLASS_ID = 0xc239d686
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputWebFileLocation#0xc239d686";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  std::string url_;
  int64_t access_hash_;
};

// upload.webFile#21e753bc size:int mime_type:string file_type:storage.FileType mtime:int bytes:bytes = upload.WebFile;
class TL_upload_webFile : public upload_WebFile {
public:
  enum {
    CLASS_ID = 0x21e753bc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_webFile#0x21e753bc";
  }

  int32_t size() const { return size_; } 
  void set_size(int32_t v) { size_ = v; } 

  std::string* mutable_mime_type() { return &mime_type_; } 
  const std::string& mime_type() const { return mime_type_; } 
  void set_mime_type(const std::string& v) { mime_type_ = v; } 
  void set_mime_type(const char* v, size_t n) { mime_type_.assign(v, n); } 
  void set_mime_type(const char* v) { mime_type_ = v; } 

  int32_t mtime() const { return mtime_; } 
  void set_mtime(int32_t v) { mtime_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  int32_t size_;
  std::string mime_type_;
  std::unique_ptr<storage_FileType> file_type_;
  int32_t mtime_;
  std::string bytes_;
};

// payments.paymentForm#3f56aea3 flags:# can_save_credentials:flags.2?true password_missing:flags.3?true bot_id:int invoice:Invoice provider_id:int url:string native_provider:flags.4?string native_params:flags.4?DataJSON saved_info:flags.0?PaymentRequestedInfo saved_credentials:flags.1?PaymentSavedCredentials users:Vector<User> = payments.PaymentForm;
class TL_payments_paymentForm : public payments_PaymentForm {
public:
  enum {
    CLASS_ID = 0x3f56aea3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_paymentForm#0x3f56aea3";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t bot_id() const { return bot_id_; } 
  void set_bot_id(int32_t v) { bot_id_ = v; } 

  int32_t provider_id() const { return provider_id_; } 
  void set_provider_id(int32_t v) { provider_id_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  std::string* mutable_native_provider() { return &native_provider_; } 
  const std::string& native_provider() const { return native_provider_; } 
  void set_native_provider(const std::string& v) { native_provider_ = v; } 
  void set_native_provider(const char* v, size_t n) { native_provider_.assign(v, n); } 
  void set_native_provider(const char* v) { native_provider_ = v; } 

private:
  int32_t flags_;
  bool can_save_credentials_ {false};
  bool password_missing_ {false};
  int32_t bot_id_;
  std::unique_ptr<Invoice> invoice_;
  int32_t provider_id_;
  std::string url_;
  std::string native_provider_;
  std::unique_ptr<DataJSON> native_params_;
  std::unique_ptr<PaymentRequestedInfo> saved_info_;
  std::unique_ptr<PaymentSavedCredentials> saved_credentials_;
  TLObjectVector<User> users_;
};

// payments.validatedRequestedInfo#d1451883 flags:# id:flags.0?string shipping_options:flags.1?Vector<ShippingOption> = payments.ValidatedRequestedInfo;
class TL_payments_validatedRequestedInfo : public payments_ValidatedRequestedInfo {
public:
  enum {
    CLASS_ID = 0xd1451883
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_validatedRequestedInfo#0xd1451883";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

private:
  int32_t flags_;
  std::string id_;
  TLObjectVector<ShippingOption> shipping_options_;
};

// payments.paymentResult#4e5f810d updates:Updates = payments.PaymentResult;
class TL_payments_paymentResult : public payments_PaymentResult {
public:
  enum {
    CLASS_ID = 0x4e5f810d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_paymentResult#0x4e5f810d";
  }

private:
  std::unique_ptr<Updates> updates_;
};

// payments.paymentVerficationNeeded#6b56b921 url:string = payments.PaymentResult;
class TL_payments_paymentVerficationNeeded : public payments_PaymentResult {
public:
  enum {
    CLASS_ID = 0x6b56b921
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_paymentVerficationNeeded#0x6b56b921";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

private:
  std::string url_;
};

// payments.paymentReceipt#500911e1 flags:# date:int bot_id:int invoice:Invoice provider_id:int info:flags.0?PaymentRequestedInfo shipping:flags.1?ShippingOption currency:string total_amount:long credentials_title:string users:Vector<User> = payments.PaymentReceipt;
class TL_payments_paymentReceipt : public payments_PaymentReceipt {
public:
  enum {
    CLASS_ID = 0x500911e1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_paymentReceipt#0x500911e1";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t bot_id() const { return bot_id_; } 
  void set_bot_id(int32_t v) { bot_id_ = v; } 

  int32_t provider_id() const { return provider_id_; } 
  void set_provider_id(int32_t v) { provider_id_ = v; } 

  std::string* mutable_currency() { return &currency_; } 
  const std::string& currency() const { return currency_; } 
  void set_currency(const std::string& v) { currency_ = v; } 
  void set_currency(const char* v, size_t n) { currency_.assign(v, n); } 
  void set_currency(const char* v) { currency_ = v; } 

  int64_t total_amount() const { return total_amount_; } 
  void set_total_amount(int64_t v) { total_amount_ = v; } 

  std::string* mutable_credentials_title() { return &credentials_title_; } 
  const std::string& credentials_title() const { return credentials_title_; } 
  void set_credentials_title(const std::string& v) { credentials_title_ = v; } 
  void set_credentials_title(const char* v, size_t n) { credentials_title_.assign(v, n); } 
  void set_credentials_title(const char* v) { credentials_title_ = v; } 

private:
  int32_t flags_;
  int32_t date_;
  int32_t bot_id_;
  std::unique_ptr<Invoice> invoice_;
  int32_t provider_id_;
  std::unique_ptr<PaymentRequestedInfo> info_;
  std::unique_ptr<ShippingOption> shipping_;
  std::string currency_;
  int64_t total_amount_;
  std::string credentials_title_;
  TLObjectVector<User> users_;
};

// payments.savedInfo#fb8fe43c flags:# has_saved_credentials:flags.1?true saved_info:flags.0?PaymentRequestedInfo = payments.SavedInfo;
class TL_payments_savedInfo : public payments_SavedInfo {
public:
  enum {
    CLASS_ID = 0xfb8fe43c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_savedInfo#0xfb8fe43c";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool has_saved_credentials_ {false};
  std::unique_ptr<PaymentRequestedInfo> saved_info_;
};

// inputPaymentCredentialsSaved#c10eb2cf id:string tmp_password:bytes = InputPaymentCredentials;
class TL_inputPaymentCredentialsSaved : public InputPaymentCredentials {
public:
  enum {
    CLASS_ID = 0xc10eb2cf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPaymentCredentialsSaved#0xc10eb2cf";
  }

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_tmp_password() { return &tmp_password_; } 
  const std::string& tmp_password() const { return tmp_password_; } 
  void set_tmp_password(const std::string& v) { tmp_password_ = v; } 
  void set_tmp_password(const char* v, size_t n) { tmp_password_.assign(v, n); } 
  void set_tmp_password(const char* v) { tmp_password_ = v; } 

private:
  std::string id_;
  std::string tmp_password_;
};

// inputPaymentCredentials#3417d728 flags:# save:flags.0?true data:DataJSON = InputPaymentCredentials;
class TL_inputPaymentCredentials : public InputPaymentCredentials {
public:
  enum {
    CLASS_ID = 0x3417d728
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPaymentCredentials#0x3417d728";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool save_ {false};
  std::unique_ptr<DataJSON> data_;
};

// account.tmpPassword#db64fd34 tmp_password:bytes valid_until:int = account.TmpPassword;
class TL_account_tmpPassword : public account_TmpPassword {
public:
  enum {
    CLASS_ID = 0xdb64fd34
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_tmpPassword#0xdb64fd34";
  }

  std::string* mutable_tmp_password() { return &tmp_password_; } 
  const std::string& tmp_password() const { return tmp_password_; } 
  void set_tmp_password(const std::string& v) { tmp_password_ = v; } 
  void set_tmp_password(const char* v, size_t n) { tmp_password_.assign(v, n); } 
  void set_tmp_password(const char* v) { tmp_password_ = v; } 

  int32_t valid_until() const { return valid_until_; } 
  void set_valid_until(int32_t v) { valid_until_ = v; } 

private:
  std::string tmp_password_;
  int32_t valid_until_;
};

// shippingOption#b6213cdf id:string title:string prices:Vector<LabeledPrice> = ShippingOption;
class TL_shippingOption : public ShippingOption {
public:
  enum {
    CLASS_ID = 0xb6213cdf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "shippingOption#0xb6213cdf";
  }

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  std::string id_;
  std::string title_;
  TLObjectVector<LabeledPrice> prices_;
};

// inputPhoneCall#1e36fded id:long access_hash:long = InputPhoneCall;
class TL_inputPhoneCall : public InputPhoneCall {
public:
  enum {
    CLASS_ID = 0x1e36fded
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "inputPhoneCall#0x1e36fded";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
};

// phoneCallEmpty#5366c915 id:long = PhoneCall;
class TL_phoneCallEmpty : public PhoneCall {
public:
  enum {
    CLASS_ID = 0x5366c915
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallEmpty#0x5366c915";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

private:
  int64_t id_;
};

// phoneCallWaiting#1b8f4ad1 flags:# id:long access_hash:long date:int admin_id:int participant_id:int protocol:PhoneCallProtocol receive_date:flags.0?int = PhoneCall;
class TL_phoneCallWaiting : public PhoneCall {
public:
  enum {
    CLASS_ID = 0x1b8f4ad1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallWaiting#0x1b8f4ad1";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t admin_id() const { return admin_id_; } 
  void set_admin_id(int32_t v) { admin_id_ = v; } 

  int32_t participant_id() const { return participant_id_; } 
  void set_participant_id(int32_t v) { participant_id_ = v; } 

  int32_t receive_date() const { return receive_date_; } 
  void set_receive_date(int32_t v) { receive_date_ = v; } 

private:
  int32_t flags_;
  int64_t id_;
  int64_t access_hash_;
  int32_t date_;
  int32_t admin_id_;
  int32_t participant_id_;
  std::unique_ptr<PhoneCallProtocol> protocol_;
  int32_t receive_date_;
};

// phoneCallRequested#83761ce4 id:long access_hash:long date:int admin_id:int participant_id:int g_a_hash:bytes protocol:PhoneCallProtocol = PhoneCall;
class TL_phoneCallRequested : public PhoneCall {
public:
  enum {
    CLASS_ID = 0x83761ce4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallRequested#0x83761ce4";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t admin_id() const { return admin_id_; } 
  void set_admin_id(int32_t v) { admin_id_ = v; } 

  int32_t participant_id() const { return participant_id_; } 
  void set_participant_id(int32_t v) { participant_id_ = v; } 

  std::string* mutable_g_a_hash() { return &g_a_hash_; } 
  const std::string& g_a_hash() const { return g_a_hash_; } 
  void set_g_a_hash(const std::string& v) { g_a_hash_ = v; } 
  void set_g_a_hash(const char* v, size_t n) { g_a_hash_.assign(v, n); } 
  void set_g_a_hash(const char* v) { g_a_hash_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
  int32_t date_;
  int32_t admin_id_;
  int32_t participant_id_;
  std::string g_a_hash_;
  std::unique_ptr<PhoneCallProtocol> protocol_;
};

// phoneCallAccepted#6d003d3f id:long access_hash:long date:int admin_id:int participant_id:int g_b:bytes protocol:PhoneCallProtocol = PhoneCall;
class TL_phoneCallAccepted : public PhoneCall {
public:
  enum {
    CLASS_ID = 0x6d003d3f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallAccepted#0x6d003d3f";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t admin_id() const { return admin_id_; } 
  void set_admin_id(int32_t v) { admin_id_ = v; } 

  int32_t participant_id() const { return participant_id_; } 
  void set_participant_id(int32_t v) { participant_id_ = v; } 

  std::string* mutable_g_b() { return &g_b_; } 
  const std::string& g_b() const { return g_b_; } 
  void set_g_b(const std::string& v) { g_b_ = v; } 
  void set_g_b(const char* v, size_t n) { g_b_.assign(v, n); } 
  void set_g_b(const char* v) { g_b_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
  int32_t date_;
  int32_t admin_id_;
  int32_t participant_id_;
  std::string g_b_;
  std::unique_ptr<PhoneCallProtocol> protocol_;
};

// phoneCall#ffe6ab67 id:long access_hash:long date:int admin_id:int participant_id:int g_a_or_b:bytes key_fingerprint:long protocol:PhoneCallProtocol connection:PhoneConnection alternative_connections:Vector<PhoneConnection> start_date:int = PhoneCall;
class TL_phoneCall : public PhoneCall {
public:
  enum {
    CLASS_ID = 0xffe6ab67
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCall#0xffe6ab67";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int64_t access_hash() const { return access_hash_; } 
  void set_access_hash(int64_t v) { access_hash_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t admin_id() const { return admin_id_; } 
  void set_admin_id(int32_t v) { admin_id_ = v; } 

  int32_t participant_id() const { return participant_id_; } 
  void set_participant_id(int32_t v) { participant_id_ = v; } 

  std::string* mutable_g_a_or_b() { return &g_a_or_b_; } 
  const std::string& g_a_or_b() const { return g_a_or_b_; } 
  void set_g_a_or_b(const std::string& v) { g_a_or_b_ = v; } 
  void set_g_a_or_b(const char* v, size_t n) { g_a_or_b_.assign(v, n); } 
  void set_g_a_or_b(const char* v) { g_a_or_b_ = v; } 

  int64_t key_fingerprint() const { return key_fingerprint_; } 
  void set_key_fingerprint(int64_t v) { key_fingerprint_ = v; } 

  int32_t start_date() const { return start_date_; } 
  void set_start_date(int32_t v) { start_date_ = v; } 

private:
  int64_t id_;
  int64_t access_hash_;
  int32_t date_;
  int32_t admin_id_;
  int32_t participant_id_;
  std::string g_a_or_b_;
  int64_t key_fingerprint_;
  std::unique_ptr<PhoneCallProtocol> protocol_;
  std::unique_ptr<PhoneConnection> connection_;
  TLObjectVector<PhoneConnection> alternative_connections_;
  int32_t start_date_;
};

// phoneCallDiscarded#50ca4de1 flags:# need_rating:flags.2?true need_debug:flags.3?true id:long reason:flags.0?PhoneCallDiscardReason duration:flags.1?int = PhoneCall;
class TL_phoneCallDiscarded : public PhoneCall {
public:
  enum {
    CLASS_ID = 0x50ca4de1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallDiscarded#0x50ca4de1";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  int32_t duration() const { return duration_; } 
  void set_duration(int32_t v) { duration_ = v; } 

private:
  int32_t flags_;
  bool need_rating_ {false};
  bool need_debug_ {false};
  int64_t id_;
  std::unique_ptr<PhoneCallDiscardReason> reason_;
  int32_t duration_;
};

// phoneConnection#9d4c17c0 id:long ip:string ipv6:string port:int peer_tag:bytes = PhoneConnection;
class TL_phoneConnection : public PhoneConnection {
public:
  enum {
    CLASS_ID = 0x9d4c17c0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneConnection#0x9d4c17c0";
  }

  int64_t id() const { return id_; } 
  void set_id(int64_t v) { id_ = v; } 

  std::string* mutable_ip() { return &ip_; } 
  const std::string& ip() const { return ip_; } 
  void set_ip(const std::string& v) { ip_ = v; } 
  void set_ip(const char* v, size_t n) { ip_.assign(v, n); } 
  void set_ip(const char* v) { ip_ = v; } 

  std::string* mutable_ipv6() { return &ipv6_; } 
  const std::string& ipv6() const { return ipv6_; } 
  void set_ipv6(const std::string& v) { ipv6_ = v; } 
  void set_ipv6(const char* v, size_t n) { ipv6_.assign(v, n); } 
  void set_ipv6(const char* v) { ipv6_ = v; } 

  int32_t port() const { return port_; } 
  void set_port(int32_t v) { port_ = v; } 

  std::string* mutable_peer_tag() { return &peer_tag_; } 
  const std::string& peer_tag() const { return peer_tag_; } 
  void set_peer_tag(const std::string& v) { peer_tag_ = v; } 
  void set_peer_tag(const char* v, size_t n) { peer_tag_.assign(v, n); } 
  void set_peer_tag(const char* v) { peer_tag_ = v; } 

private:
  int64_t id_;
  std::string ip_;
  std::string ipv6_;
  int32_t port_;
  std::string peer_tag_;
};

// phoneCallProtocol#a2bb35cb flags:# udp_p2p:flags.0?true udp_reflector:flags.1?true min_layer:int max_layer:int = PhoneCallProtocol;
class TL_phoneCallProtocol : public PhoneCallProtocol {
public:
  enum {
    CLASS_ID = 0xa2bb35cb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phoneCallProtocol#0xa2bb35cb";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t min_layer() const { return min_layer_; } 
  void set_min_layer(int32_t v) { min_layer_ = v; } 

  int32_t max_layer() const { return max_layer_; } 
  void set_max_layer(int32_t v) { max_layer_ = v; } 

private:
  int32_t flags_;
  bool udp_p2p_ {false};
  bool udp_reflector_ {false};
  int32_t min_layer_;
  int32_t max_layer_;
};

// phone.phoneCall#ec82e140 phone_call:PhoneCall users:Vector<User> = phone.PhoneCall;
class TL_phone_phoneCall : public phone_PhoneCall {
public:
  enum {
    CLASS_ID = 0xec82e140
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_phoneCall#0xec82e140";
  }

private:
  std::unique_ptr<PhoneCall> phone_call_;
  TLObjectVector<User> users_;
};

// upload.cdnFileReuploadNeeded#eea8e46e request_token:bytes = upload.CdnFile;
class TL_upload_cdnFileReuploadNeeded : public upload_CdnFile {
public:
  enum {
    CLASS_ID = 0xeea8e46e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_cdnFileReuploadNeeded#0xeea8e46e";
  }

  std::string* mutable_request_token() { return &request_token_; } 
  const std::string& request_token() const { return request_token_; } 
  void set_request_token(const std::string& v) { request_token_ = v; } 
  void set_request_token(const char* v, size_t n) { request_token_.assign(v, n); } 
  void set_request_token(const char* v) { request_token_ = v; } 

private:
  std::string request_token_;
};

// upload.cdnFile#a99fca4f bytes:bytes = upload.CdnFile;
class TL_upload_cdnFile : public upload_CdnFile {
public:
  enum {
    CLASS_ID = 0xa99fca4f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_cdnFile#0xa99fca4f";
  }

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  std::string bytes_;
};

// cdnPublicKey#c982eaba dc_id:int public_key:string = CdnPublicKey;
class TL_cdnPublicKey : public CdnPublicKey {
public:
  enum {
    CLASS_ID = 0xc982eaba
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "cdnPublicKey#0xc982eaba";
  }

  int32_t dc_id() const { return dc_id_; } 
  void set_dc_id(int32_t v) { dc_id_ = v; } 

  std::string* mutable_public_key() { return &public_key_; } 
  const std::string& public_key() const { return public_key_; } 
  void set_public_key(const std::string& v) { public_key_ = v; } 
  void set_public_key(const char* v, size_t n) { public_key_.assign(v, n); } 
  void set_public_key(const char* v) { public_key_ = v; } 

private:
  int32_t dc_id_;
  std::string public_key_;
};

// cdnConfig#5725e40a public_keys:Vector<CdnPublicKey> = CdnConfig;
class TL_cdnConfig : public CdnConfig {
public:
  enum {
    CLASS_ID = 0x5725e40a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "cdnConfig#0x5725e40a";
  }

private:
  TLObjectVector<CdnPublicKey> public_keys_;
};


// RPC
// req_pq#60469778 nonce:int128 = ResPQ;
class TL_req_pq : public TLObject {
public:
  enum {
    CLASS_ID = 0x60469778
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "req_pq#0x60469778";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

private:
  TLInt128 nonce_;
};

// req_DH_params#d712e4be nonce:int128 server_nonce:int128 p:string q:string public_key_fingerprint:long encrypted_data:string = Server_DH_Params;
class TL_req_DH_params : public TLObject {
public:
  enum {
    CLASS_ID = 0xd712e4be
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "req_DH_params#0xd712e4be";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  std::string* mutable_p() { return &p_; } 
  const std::string& p() const { return p_; } 
  void set_p(const std::string& v) { p_ = v; } 
  void set_p(const char* v, size_t n) { p_.assign(v, n); } 
  void set_p(const char* v) { p_ = v; } 

  std::string* mutable_q() { return &q_; } 
  const std::string& q() const { return q_; } 
  void set_q(const std::string& v) { q_ = v; } 
  void set_q(const char* v, size_t n) { q_.assign(v, n); } 
  void set_q(const char* v) { q_ = v; } 

  int64_t public_key_fingerprint() const { return public_key_fingerprint_; } 
  void set_public_key_fingerprint(int64_t v) { public_key_fingerprint_ = v; } 

  std::string* mutable_encrypted_data() { return &encrypted_data_; } 
  const std::string& encrypted_data() const { return encrypted_data_; } 
  void set_encrypted_data(const std::string& v) { encrypted_data_ = v; } 
  void set_encrypted_data(const char* v, size_t n) { encrypted_data_.assign(v, n); } 
  void set_encrypted_data(const char* v) { encrypted_data_ = v; } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  std::string p_;
  std::string q_;
  int64_t public_key_fingerprint_;
  std::string encrypted_data_;
};

// set_client_DH_params#f5045f1f nonce:int128 server_nonce:int128 encrypted_data:string = Set_client_DH_params_answer;
class TL_set_client_DH_params : public TLObject {
public:
  enum {
    CLASS_ID = 0xf5045f1f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "set_client_DH_params#0xf5045f1f";
  }

  TLInt128* mutable_nonce() { return &nonce_; } 
  const TLInt128& nonce() const { return nonce_; } 
  void set_nonce(const TLInt128& v) { nonce_.Copy(v); } 

  TLInt128* mutable_server_nonce() { return &server_nonce_; } 
  const TLInt128& server_nonce() const { return server_nonce_; } 
  void set_server_nonce(const TLInt128& v) { server_nonce_.Copy(v); } 

  std::string* mutable_encrypted_data() { return &encrypted_data_; } 
  const std::string& encrypted_data() const { return encrypted_data_; } 
  void set_encrypted_data(const std::string& v) { encrypted_data_ = v; } 
  void set_encrypted_data(const char* v, size_t n) { encrypted_data_.assign(v, n); } 
  void set_encrypted_data(const char* v) { encrypted_data_ = v; } 

private:
  TLInt128 nonce_;
  TLInt128 server_nonce_;
  std::string encrypted_data_;
};

// destroy_auth_key#d1435160 = DestroyAuthKeyRes;
class TL_destroy_auth_key : public TLObject {
public:
  enum {
    CLASS_ID = 0xd1435160
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "destroy_auth_key#0xd1435160";
  }

private:
};

// rpc_drop_answer#58e4a740 req_msg_id:long = RpcDropAnswer;
class TL_rpc_drop_answer : public TLObject {
public:
  enum {
    CLASS_ID = 0x58e4a740
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "rpc_drop_answer#0x58e4a740";
  }

  int64_t req_msg_id() const { return req_msg_id_; } 
  void set_req_msg_id(int64_t v) { req_msg_id_ = v; } 

private:
  int64_t req_msg_id_;
};

// get_future_salts#b921bd04 num:int = FutureSalts;
class TL_get_future_salts : public TLObject {
public:
  enum {
    CLASS_ID = 0xb921bd04
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "get_future_salts#0xb921bd04";
  }

  int32_t num() const { return num_; } 
  void set_num(int32_t v) { num_ = v; } 

private:
  int32_t num_;
};

// ping#7abe77ec ping_id:long = Pong;
class TL_ping : public TLObject {
public:
  enum {
    CLASS_ID = 0x7abe77ec
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "ping#0x7abe77ec";
  }

  int64_t ping_id() const { return ping_id_; } 
  void set_ping_id(int64_t v) { ping_id_ = v; } 

private:
  int64_t ping_id_;
};

// ping_delay_disconnect#f3427b8c ping_id:long disconnect_delay:int = Pong;
class TL_ping_delay_disconnect : public TLObject {
public:
  enum {
    CLASS_ID = 0xf3427b8c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "ping_delay_disconnect#0xf3427b8c";
  }

  int64_t ping_id() const { return ping_id_; } 
  void set_ping_id(int64_t v) { ping_id_ = v; } 

  int32_t disconnect_delay() const { return disconnect_delay_; } 
  void set_disconnect_delay(int32_t v) { disconnect_delay_ = v; } 

private:
  int64_t ping_id_;
  int32_t disconnect_delay_;
};

// destroy_session#e7512126 session_id:long = DestroySessionRes;
class TL_destroy_session : public TLObject {
public:
  enum {
    CLASS_ID = 0xe7512126
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "destroy_session#0xe7512126";
  }

  int64_t session_id() const { return session_id_; } 
  void set_session_id(int64_t v) { session_id_ = v; } 

private:
  int64_t session_id_;
};

// contest.saveDeveloperInfo#9a5f6e95 vk_id:int name:string phone_number:string age:int city:string = Bool;
class TL_contest_saveDeveloperInfo : public TLObject {
public:
  enum {
    CLASS_ID = 0x9a5f6e95
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contest_saveDeveloperInfo#0x9a5f6e95";
  }

  int32_t vk_id() const { return vk_id_; } 
  void set_vk_id(int32_t v) { vk_id_ = v; } 

  std::string* mutable_name() { return &name_; } 
  const std::string& name() const { return name_; } 
  void set_name(const std::string& v) { name_ = v; } 
  void set_name(const char* v, size_t n) { name_.assign(v, n); } 
  void set_name(const char* v) { name_ = v; } 

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  int32_t age() const { return age_; } 
  void set_age(int32_t v) { age_ = v; } 

  std::string* mutable_city() { return &city_; } 
  const std::string& city() const { return city_; } 
  void set_city(const std::string& v) { city_ = v; } 
  void set_city(const char* v, size_t n) { city_.assign(v, n); } 
  void set_city(const char* v) { city_ = v; } 

private:
  int32_t vk_id_;
  std::string name_;
  std::string phone_number_;
  int32_t age_;
  std::string city_;
};

// auth.logOut#5717da40 = Bool;
class TL_auth_logOut : public TLObject {
public:
  enum {
    CLASS_ID = 0x5717da40
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_logOut#0x5717da40";
  }

private:
};

// auth.resetAuthorizations#9fab0d1a = Bool;
class TL_auth_resetAuthorizations : public TLObject {
public:
  enum {
    CLASS_ID = 0x9fab0d1a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_resetAuthorizations#0x9fab0d1a";
  }

private:
};

// auth.sendInvites#771c1d97 phone_numbers:Vector<string> message:string = Bool;
class TL_auth_sendInvites : public TLObject {
public:
  enum {
    CLASS_ID = 0x771c1d97
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_sendInvites#0x771c1d97";
  }

  size_t phone_numbers_size() const { return phone_numbers_.size(); } 
  const TLStringVector& phone_numbers() const { return phone_numbers_; } 
  const std::string& phone_numbers(int idx) const { return phone_numbers_.vector()[idx]; } 
  void add_phone_numbers(const std::string& v) {phone_numbers_.mutable_vector()->push_back(v); } 
  TLStringVector* mutable_phone_numbers() { return &phone_numbers_; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  TLStringVector phone_numbers_;
  std::string message_;
};

// auth.bindTempAuthKey#cdd42a05 perm_auth_key_id:long nonce:long expires_at:int encrypted_message:bytes = Bool;
class TL_auth_bindTempAuthKey : public TLObject {
public:
  enum {
    CLASS_ID = 0xcdd42a05
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_bindTempAuthKey#0xcdd42a05";
  }

  int64_t perm_auth_key_id() const { return perm_auth_key_id_; } 
  void set_perm_auth_key_id(int64_t v) { perm_auth_key_id_ = v; } 

  int64_t nonce() const { return nonce_; } 
  void set_nonce(int64_t v) { nonce_ = v; } 

  int32_t expires_at() const { return expires_at_; } 
  void set_expires_at(int32_t v) { expires_at_ = v; } 

  std::string* mutable_encrypted_message() { return &encrypted_message_; } 
  const std::string& encrypted_message() const { return encrypted_message_; } 
  void set_encrypted_message(const std::string& v) { encrypted_message_ = v; } 
  void set_encrypted_message(const char* v, size_t n) { encrypted_message_.assign(v, n); } 
  void set_encrypted_message(const char* v) { encrypted_message_ = v; } 

private:
  int64_t perm_auth_key_id_;
  int64_t nonce_;
  int32_t expires_at_;
  std::string encrypted_message_;
};

// auth.cancelCode#1f040578 phone_number:string phone_code_hash:string = Bool;
class TL_auth_cancelCode : public TLObject {
public:
  enum {
    CLASS_ID = 0x1f040578
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_cancelCode#0x1f040578";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_phone_code_hash() { return &phone_code_hash_; } 
  const std::string& phone_code_hash() const { return phone_code_hash_; } 
  void set_phone_code_hash(const std::string& v) { phone_code_hash_ = v; } 
  void set_phone_code_hash(const char* v, size_t n) { phone_code_hash_.assign(v, n); } 
  void set_phone_code_hash(const char* v) { phone_code_hash_ = v; } 

private:
  std::string phone_number_;
  std::string phone_code_hash_;
};

// auth.dropTempAuthKeys#8e48a188 except_auth_keys:Vector<long> = Bool;
class TL_auth_dropTempAuthKeys : public TLObject {
public:
  enum {
    CLASS_ID = 0x8e48a188
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_dropTempAuthKeys#0x8e48a188";
  }

  size_t except_auth_keys_size() const { return except_auth_keys_.size(); } 
  const TLInt64Vector& except_auth_keys() const { return except_auth_keys_; } 
  int64_t except_auth_keys(int idx) const { return except_auth_keys_.vector()[idx]; } 
  void add_except_auth_keys(int64_t v) {except_auth_keys_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_except_auth_keys() { return &except_auth_keys_; } 

private:
  TLInt64Vector except_auth_keys_;
};

// account.registerDevice#637ea878 token_type:int token:string = Bool;
class TL_account_registerDevice : public TLObject {
public:
  enum {
    CLASS_ID = 0x637ea878
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_registerDevice#0x637ea878";
  }

  int32_t token_type() const { return token_type_; } 
  void set_token_type(int32_t v) { token_type_ = v; } 

  std::string* mutable_token() { return &token_; } 
  const std::string& token() const { return token_; } 
  void set_token(const std::string& v) { token_ = v; } 
  void set_token(const char* v, size_t n) { token_.assign(v, n); } 
  void set_token(const char* v) { token_ = v; } 

private:
  int32_t token_type_;
  std::string token_;
};

// account.unregisterDevice#65c55b40 token_type:int token:string = Bool;
class TL_account_unregisterDevice : public TLObject {
public:
  enum {
    CLASS_ID = 0x65c55b40
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_unregisterDevice#0x65c55b40";
  }

  int32_t token_type() const { return token_type_; } 
  void set_token_type(int32_t v) { token_type_ = v; } 

  std::string* mutable_token() { return &token_; } 
  const std::string& token() const { return token_; } 
  void set_token(const std::string& v) { token_ = v; } 
  void set_token(const char* v, size_t n) { token_.assign(v, n); } 
  void set_token(const char* v) { token_ = v; } 

private:
  int32_t token_type_;
  std::string token_;
};

// account.updateNotifySettings#84be5b93 peer:InputNotifyPeer settings:InputPeerNotifySettings = Bool;
class TL_account_updateNotifySettings : public TLObject {
public:
  enum {
    CLASS_ID = 0x84be5b93
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_updateNotifySettings#0x84be5b93";
  }

private:
  std::unique_ptr<InputNotifyPeer> peer_;
  std::unique_ptr<InputPeerNotifySettings> settings_;
};

// account.resetNotifySettings#db7e1747 = Bool;
class TL_account_resetNotifySettings : public TLObject {
public:
  enum {
    CLASS_ID = 0xdb7e1747
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_resetNotifySettings#0xdb7e1747";
  }

private:
};

// account.updateStatus#6628562c offline:Bool = Bool;
class TL_account_updateStatus : public TLObject {
public:
  enum {
    CLASS_ID = 0x6628562c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_updateStatus#0x6628562c";
  }

private:
  std::unique_ptr<Bool> offline_;
};

// account.reportPeer#ae189d5f peer:InputPeer reason:ReportReason = Bool;
class TL_account_reportPeer : public TLObject {
public:
  enum {
    CLASS_ID = 0xae189d5f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_reportPeer#0xae189d5f";
  }

private:
  std::unique_ptr<InputPeer> peer_;
  std::unique_ptr<ReportReason> reason_;
};

// account.checkUsername#2714d86c username:string = Bool;
class TL_account_checkUsername : public TLObject {
public:
  enum {
    CLASS_ID = 0x2714d86c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_checkUsername#0x2714d86c";
  }

  std::string* mutable_username() { return &username_; } 
  const std::string& username() const { return username_; } 
  void set_username(const std::string& v) { username_ = v; } 
  void set_username(const char* v, size_t n) { username_.assign(v, n); } 
  void set_username(const char* v) { username_ = v; } 

private:
  std::string username_;
};

// account.deleteAccount#418d4e0b reason:string = Bool;
class TL_account_deleteAccount : public TLObject {
public:
  enum {
    CLASS_ID = 0x418d4e0b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_deleteAccount#0x418d4e0b";
  }

  std::string* mutable_reason() { return &reason_; } 
  const std::string& reason() const { return reason_; } 
  void set_reason(const std::string& v) { reason_ = v; } 
  void set_reason(const char* v, size_t n) { reason_.assign(v, n); } 
  void set_reason(const char* v) { reason_ = v; } 

private:
  std::string reason_;
};

// account.setAccountTTL#2442485e ttl:AccountDaysTTL = Bool;
class TL_account_setAccountTTL : public TLObject {
public:
  enum {
    CLASS_ID = 0x2442485e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_setAccountTTL#0x2442485e";
  }

private:
  std::unique_ptr<AccountDaysTTL> ttl_;
};

// account.updateDeviceLocked#38df3532 period:int = Bool;
class TL_account_updateDeviceLocked : public TLObject {
public:
  enum {
    CLASS_ID = 0x38df3532
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_updateDeviceLocked#0x38df3532";
  }

  int32_t period() const { return period_; } 
  void set_period(int32_t v) { period_ = v; } 

private:
  int32_t period_;
};

// account.resetAuthorization#df77f3bc hash:long = Bool;
class TL_account_resetAuthorization : public TLObject {
public:
  enum {
    CLASS_ID = 0xdf77f3bc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_resetAuthorization#0xdf77f3bc";
  }

  int64_t hash() const { return hash_; } 
  void set_hash(int64_t v) { hash_ = v; } 

private:
  int64_t hash_;
};

// account.updatePasswordSettings#fa7c4b86 current_password_hash:bytes new_settings:account.PasswordInputSettings = Bool;
class TL_account_updatePasswordSettings : public TLObject {
public:
  enum {
    CLASS_ID = 0xfa7c4b86
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_updatePasswordSettings#0xfa7c4b86";
  }

  std::string* mutable_current_password_hash() { return &current_password_hash_; } 
  const std::string& current_password_hash() const { return current_password_hash_; } 
  void set_current_password_hash(const std::string& v) { current_password_hash_ = v; } 
  void set_current_password_hash(const char* v, size_t n) { current_password_hash_.assign(v, n); } 
  void set_current_password_hash(const char* v) { current_password_hash_ = v; } 

private:
  std::string current_password_hash_;
  std::unique_ptr<account_PasswordInputSettings> new_settings_;
};

// account.confirmPhone#5f2178c3 phone_code_hash:string phone_code:string = Bool;
class TL_account_confirmPhone : public TLObject {
public:
  enum {
    CLASS_ID = 0x5f2178c3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_confirmPhone#0x5f2178c3";
  }

  std::string* mutable_phone_code_hash() { return &phone_code_hash_; } 
  const std::string& phone_code_hash() const { return phone_code_hash_; } 
  void set_phone_code_hash(const std::string& v) { phone_code_hash_ = v; } 
  void set_phone_code_hash(const char* v, size_t n) { phone_code_hash_.assign(v, n); } 
  void set_phone_code_hash(const char* v) { phone_code_hash_ = v; } 

  std::string* mutable_phone_code() { return &phone_code_; } 
  const std::string& phone_code() const { return phone_code_; } 
  void set_phone_code(const std::string& v) { phone_code_ = v; } 
  void set_phone_code(const char* v, size_t n) { phone_code_.assign(v, n); } 
  void set_phone_code(const char* v) { phone_code_ = v; } 

private:
  std::string phone_code_hash_;
  std::string phone_code_;
};

// contacts.deleteContacts#59ab389e id:Vector<InputUser> = Bool;
class TL_contacts_deleteContacts : public TLObject {
public:
  enum {
    CLASS_ID = 0x59ab389e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_deleteContacts#0x59ab389e";
  }

private:
  TLObjectVector<InputUser> id_;
};

// contacts.block#332b49fc id:InputUser = Bool;
class TL_contacts_block : public TLObject {
public:
  enum {
    CLASS_ID = 0x332b49fc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_block#0x332b49fc";
  }

private:
  std::unique_ptr<InputUser> id_;
};

// contacts.unblock#e54100bd id:InputUser = Bool;
class TL_contacts_unblock : public TLObject {
public:
  enum {
    CLASS_ID = 0xe54100bd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_unblock#0xe54100bd";
  }

private:
  std::unique_ptr<InputUser> id_;
};

// contacts.resetTopPeerRating#1ae373ac category:TopPeerCategory peer:InputPeer = Bool;
class TL_contacts_resetTopPeerRating : public TLObject {
public:
  enum {
    CLASS_ID = 0x1ae373ac
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_resetTopPeerRating#0x1ae373ac";
  }

private:
  std::unique_ptr<TopPeerCategory> category_;
  std::unique_ptr<InputPeer> peer_;
};

// messages.setTyping#a3825e50 peer:InputPeer action:SendMessageAction = Bool;
class TL_messages_setTyping : public TLObject {
public:
  enum {
    CLASS_ID = 0xa3825e50
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_setTyping#0xa3825e50";
  }

private:
  std::unique_ptr<InputPeer> peer_;
  std::unique_ptr<SendMessageAction> action_;
};

// messages.reportSpam#cf1592db peer:InputPeer = Bool;
class TL_messages_reportSpam : public TLObject {
public:
  enum {
    CLASS_ID = 0xcf1592db
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_reportSpam#0xcf1592db";
  }

private:
  std::unique_ptr<InputPeer> peer_;
};

// messages.hideReportSpam#a8f1709b peer:InputPeer = Bool;
class TL_messages_hideReportSpam : public TLObject {
public:
  enum {
    CLASS_ID = 0xa8f1709b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_hideReportSpam#0xa8f1709b";
  }

private:
  std::unique_ptr<InputPeer> peer_;
};

// messages.discardEncryption#edd923c5 chat_id:int = Bool;
class TL_messages_discardEncryption : public TLObject {
public:
  enum {
    CLASS_ID = 0xedd923c5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_discardEncryption#0xedd923c5";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
};

// messages.setEncryptedTyping#791451ed peer:InputEncryptedChat typing:Bool = Bool;
class TL_messages_setEncryptedTyping : public TLObject {
public:
  enum {
    CLASS_ID = 0x791451ed
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_setEncryptedTyping#0x791451ed";
  }

private:
  std::unique_ptr<InputEncryptedChat> peer_;
  std::unique_ptr<Bool> typing_;
};

// messages.readEncryptedHistory#7f4b690a peer:InputEncryptedChat max_date:int = Bool;
class TL_messages_readEncryptedHistory : public TLObject {
public:
  enum {
    CLASS_ID = 0x7f4b690a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_readEncryptedHistory#0x7f4b690a";
  }

  int32_t max_date() const { return max_date_; } 
  void set_max_date(int32_t v) { max_date_ = v; } 

private:
  std::unique_ptr<InputEncryptedChat> peer_;
  int32_t max_date_;
};

// messages.reportEncryptedSpam#4b0c8c0f peer:InputEncryptedChat = Bool;
class TL_messages_reportEncryptedSpam : public TLObject {
public:
  enum {
    CLASS_ID = 0x4b0c8c0f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_reportEncryptedSpam#0x4b0c8c0f";
  }

private:
  std::unique_ptr<InputEncryptedChat> peer_;
};

// messages.uninstallStickerSet#f96e55de stickerset:InputStickerSet = Bool;
class TL_messages_uninstallStickerSet : public TLObject {
public:
  enum {
    CLASS_ID = 0xf96e55de
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_uninstallStickerSet#0xf96e55de";
  }

private:
  std::unique_ptr<InputStickerSet> stickerset_;
};

// messages.editChatAdmin#a9e69f2e chat_id:int user_id:InputUser is_admin:Bool = Bool;
class TL_messages_editChatAdmin : public TLObject {
public:
  enum {
    CLASS_ID = 0xa9e69f2e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_editChatAdmin#0xa9e69f2e";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
  std::unique_ptr<InputUser> user_id_;
  std::unique_ptr<Bool> is_admin_;
};

// messages.reorderStickerSets#78337739 flags:# masks:flags.0?true order:Vector<long> = Bool;
class TL_messages_reorderStickerSets : public TLObject {
public:
  enum {
    CLASS_ID = 0x78337739
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_reorderStickerSets#0x78337739";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  size_t order_size() const { return order_.size(); } 
  const TLInt64Vector& order() const { return order_; } 
  int64_t order(int idx) const { return order_.vector()[idx]; } 
  void add_order(int64_t v) {order_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_order() { return &order_; } 

private:
  int32_t flags_;
  bool masks_;
  TLInt64Vector order_;
};

// messages.saveGif#327a30cb id:InputDocument unsave:Bool = Bool;
class TL_messages_saveGif : public TLObject {
public:
  enum {
    CLASS_ID = 0x327a30cb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_saveGif#0x327a30cb";
  }

private:
  std::unique_ptr<InputDocument> id_;
  std::unique_ptr<Bool> unsave_;
};

// messages.setInlineBotResults#eb5ea206 flags:# gallery:flags.0?true private:flags.1?true query_id:long results:Vector<InputBotInlineResult> cache_time:int next_offset:flags.2?string switch_pm:flags.3?InlineBotSwitchPM = Bool;
class TL_messages_setInlineBotResults : public TLObject {
public:
  enum {
    CLASS_ID = 0xeb5ea206
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_setInlineBotResults#0xeb5ea206";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  int32_t cache_time() const { return cache_time_; } 
  void set_cache_time(int32_t v) { cache_time_ = v; } 

  std::string* mutable_next_offset() { return &next_offset_; } 
  const std::string& next_offset() const { return next_offset_; } 
  void set_next_offset(const std::string& v) { next_offset_ = v; } 
  void set_next_offset(const char* v, size_t n) { next_offset_.assign(v, n); } 
  void set_next_offset(const char* v) { next_offset_ = v; } 

private:
  int32_t flags_;
  bool gallery_;
  bool private_;
  int64_t query_id_;
  TLObjectVector<InputBotInlineResult> results_;
  int32_t cache_time_;
  std::string next_offset_;
  std::unique_ptr<InlineBotSwitchPM> switch_pm_;
};

// messages.editInlineBotMessage#130c2c85 flags:# no_webpage:flags.1?true id:InputBotInlineMessageID message:flags.11?string reply_markup:flags.2?ReplyMarkup entities:flags.3?Vector<MessageEntity> = Bool;
class TL_messages_editInlineBotMessage : public TLObject {
public:
  enum {
    CLASS_ID = 0x130c2c85
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_editInlineBotMessage#0x130c2c85";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  int32_t flags_;
  bool no_webpage_;
  std::unique_ptr<InputBotInlineMessageID> id_;
  std::string message_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
  TLObjectVector<MessageEntity> entities_;
};

// messages.setBotCallbackAnswer#d58f130a flags:# alert:flags.1?true query_id:long message:flags.0?string url:flags.2?string cache_time:int = Bool;
class TL_messages_setBotCallbackAnswer : public TLObject {
public:
  enum {
    CLASS_ID = 0xd58f130a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_setBotCallbackAnswer#0xd58f130a";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  int32_t cache_time() const { return cache_time_; } 
  void set_cache_time(int32_t v) { cache_time_ = v; } 

private:
  int32_t flags_;
  bool alert_;
  int64_t query_id_;
  std::string message_;
  std::string url_;
  int32_t cache_time_;
};

// messages.saveDraft#bc39e14b flags:# no_webpage:flags.1?true reply_to_msg_id:flags.0?int peer:InputPeer message:string entities:flags.3?Vector<MessageEntity> = Bool;
class TL_messages_saveDraft : public TLObject {
public:
  enum {
    CLASS_ID = 0xbc39e14b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_saveDraft#0xbc39e14b";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  int32_t flags_;
  bool no_webpage_;
  int32_t reply_to_msg_id_;
  std::unique_ptr<InputPeer> peer_;
  std::string message_;
  TLObjectVector<MessageEntity> entities_;
};

// messages.readFeaturedStickers#5b118126 id:Vector<long> = Bool;
class TL_messages_readFeaturedStickers : public TLObject {
public:
  enum {
    CLASS_ID = 0x5b118126
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_readFeaturedStickers#0x5b118126";
  }

  size_t id_size() const { return id_.size(); } 
  const TLInt64Vector& id() const { return id_; } 
  int64_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int64_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_id() { return &id_; } 

private:
  TLInt64Vector id_;
};

// messages.saveRecentSticker#392718f8 flags:# attached:flags.0?true id:InputDocument unsave:Bool = Bool;
class TL_messages_saveRecentSticker : public TLObject {
public:
  enum {
    CLASS_ID = 0x392718f8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_saveRecentSticker#0x392718f8";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool attached_;
  std::unique_ptr<InputDocument> id_;
  std::unique_ptr<Bool> unsave_;
};

// messages.clearRecentStickers#8999602d flags:# attached:flags.0?true = Bool;
class TL_messages_clearRecentStickers : public TLObject {
public:
  enum {
    CLASS_ID = 0x8999602d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_clearRecentStickers#0x8999602d";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool attached_;
};

// messages.setInlineGameScore#15ad9f64 flags:# edit_message:flags.0?true force:flags.1?true id:InputBotInlineMessageID user_id:InputUser score:int = Bool;
class TL_messages_setInlineGameScore : public TLObject {
public:
  enum {
    CLASS_ID = 0x15ad9f64
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_setInlineGameScore#0x15ad9f64";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t score() const { return score_; } 
  void set_score(int32_t v) { score_ = v; } 

private:
  int32_t flags_;
  bool edit_message_;
  bool force_;
  std::unique_ptr<InputBotInlineMessageID> id_;
  std::unique_ptr<InputUser> user_id_;
  int32_t score_;
};

// messages.toggleDialogPin#3289be6a flags:# pinned:flags.0?true peer:InputPeer = Bool;
class TL_messages_toggleDialogPin : public TLObject {
public:
  enum {
    CLASS_ID = 0x3289be6a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_toggleDialogPin#0x3289be6a";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool pinned_;
  std::unique_ptr<InputPeer> peer_;
};

// messages.reorderPinnedDialogs#959ff644 flags:# force:flags.0?true order:Vector<InputPeer> = Bool;
class TL_messages_reorderPinnedDialogs : public TLObject {
public:
  enum {
    CLASS_ID = 0x959ff644
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_reorderPinnedDialogs#0x959ff644";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool force_;
  TLObjectVector<InputPeer> order_;
};

// messages.setBotShippingResults#e5f672fa flags:# query_id:long error:flags.0?string shipping_options:flags.1?Vector<ShippingOption> = Bool;
class TL_messages_setBotShippingResults : public TLObject {
public:
  enum {
    CLASS_ID = 0xe5f672fa
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_setBotShippingResults#0xe5f672fa";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  std::string* mutable_error() { return &error_; } 
  const std::string& error() const { return error_; } 
  void set_error(const std::string& v) { error_ = v; } 
  void set_error(const char* v, size_t n) { error_.assign(v, n); } 
  void set_error(const char* v) { error_ = v; } 

private:
  int32_t flags_;
  int64_t query_id_;
  std::string error_;
  TLObjectVector<ShippingOption> shipping_options_;
};

// messages.setBotPrecheckoutResults#9c2dd95 flags:# success:flags.1?true query_id:long error:flags.0?string = Bool;
class TL_messages_setBotPrecheckoutResults : public TLObject {
public:
  enum {
    CLASS_ID = 0x9c2dd95
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_setBotPrecheckoutResults#0x9c2dd95";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  std::string* mutable_error() { return &error_; } 
  const std::string& error() const { return error_; } 
  void set_error(const std::string& v) { error_ = v; } 
  void set_error(const char* v, size_t n) { error_.assign(v, n); } 
  void set_error(const char* v) { error_ = v; } 

private:
  int32_t flags_;
  bool success_;
  int64_t query_id_;
  std::string error_;
};

// upload.saveFilePart#b304a621 file_id:long file_part:int bytes:bytes = Bool;
class TL_upload_saveFilePart : public TLObject {
public:
  enum {
    CLASS_ID = 0xb304a621
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_saveFilePart#0xb304a621";
  }

  int64_t file_id() const { return file_id_; } 
  void set_file_id(int64_t v) { file_id_ = v; } 

  int32_t file_part() const { return file_part_; } 
  void set_file_part(int32_t v) { file_part_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  int64_t file_id_;
  int32_t file_part_;
  std::string bytes_;
};

// upload.saveBigFilePart#de7b673d file_id:long file_part:int file_total_parts:int bytes:bytes = Bool;
class TL_upload_saveBigFilePart : public TLObject {
public:
  enum {
    CLASS_ID = 0xde7b673d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_saveBigFilePart#0xde7b673d";
  }

  int64_t file_id() const { return file_id_; } 
  void set_file_id(int64_t v) { file_id_ = v; } 

  int32_t file_part() const { return file_part_; } 
  void set_file_part(int32_t v) { file_part_ = v; } 

  int32_t file_total_parts() const { return file_total_parts_; } 
  void set_file_total_parts(int32_t v) { file_total_parts_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  int64_t file_id_;
  int32_t file_part_;
  int32_t file_total_parts_;
  std::string bytes_;
};

// upload.reuploadCdnFile#2e7a2020 file_token:bytes request_token:bytes = Bool;
class TL_upload_reuploadCdnFile : public TLObject {
public:
  enum {
    CLASS_ID = 0x2e7a2020
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_reuploadCdnFile#0x2e7a2020";
  }

  std::string* mutable_file_token() { return &file_token_; } 
  const std::string& file_token() const { return file_token_; } 
  void set_file_token(const std::string& v) { file_token_ = v; } 
  void set_file_token(const char* v, size_t n) { file_token_.assign(v, n); } 
  void set_file_token(const char* v) { file_token_ = v; } 

  std::string* mutable_request_token() { return &request_token_; } 
  const std::string& request_token() const { return request_token_; } 
  void set_request_token(const std::string& v) { request_token_ = v; } 
  void set_request_token(const char* v, size_t n) { request_token_.assign(v, n); } 
  void set_request_token(const char* v) { request_token_ = v; } 

private:
  std::string file_token_;
  std::string request_token_;
};

// help.saveAppLog#6f02f748 events:Vector<InputAppEvent> = Bool;
class TL_help_saveAppLog : public TLObject {
public:
  enum {
    CLASS_ID = 0x6f02f748
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_saveAppLog#0x6f02f748";
  }

private:
  TLObjectVector<InputAppEvent> events_;
};

// help.setBotUpdatesStatus#ec22cfcd pending_updates_count:int message:string = Bool;
class TL_help_setBotUpdatesStatus : public TLObject {
public:
  enum {
    CLASS_ID = 0xec22cfcd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_setBotUpdatesStatus#0xec22cfcd";
  }

  int32_t pending_updates_count() const { return pending_updates_count_; } 
  void set_pending_updates_count(int32_t v) { pending_updates_count_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  int32_t pending_updates_count_;
  std::string message_;
};

// channels.readHistory#cc104937 channel:InputChannel max_id:int = Bool;
class TL_channels_readHistory : public TLObject {
public:
  enum {
    CLASS_ID = 0xcc104937
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_readHistory#0xcc104937";
  }

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

private:
  std::unique_ptr<InputChannel> channel_;
  int32_t max_id_;
};

// channels.reportSpam#fe087810 channel:InputChannel user_id:InputUser id:Vector<int> = Bool;
class TL_channels_reportSpam : public TLObject {
public:
  enum {
    CLASS_ID = 0xfe087810
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_reportSpam#0xfe087810";
  }

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<InputUser> user_id_;
  TLInt32Vector id_;
};

// channels.editAbout#13e27f1e channel:InputChannel about:string = Bool;
class TL_channels_editAbout : public TLObject {
public:
  enum {
    CLASS_ID = 0x13e27f1e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_editAbout#0x13e27f1e";
  }

  std::string* mutable_about() { return &about_; } 
  const std::string& about() const { return about_; } 
  void set_about(const std::string& v) { about_ = v; } 
  void set_about(const char* v, size_t n) { about_.assign(v, n); } 
  void set_about(const char* v) { about_ = v; } 

private:
  std::unique_ptr<InputChannel> channel_;
  std::string about_;
};

// channels.checkUsername#10e6bd2c channel:InputChannel username:string = Bool;
class TL_channels_checkUsername : public TLObject {
public:
  enum {
    CLASS_ID = 0x10e6bd2c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_checkUsername#0x10e6bd2c";
  }

  std::string* mutable_username() { return &username_; } 
  const std::string& username() const { return username_; } 
  void set_username(const std::string& v) { username_ = v; } 
  void set_username(const char* v, size_t n) { username_.assign(v, n); } 
  void set_username(const char* v) { username_ = v; } 

private:
  std::unique_ptr<InputChannel> channel_;
  std::string username_;
};

// channels.updateUsername#3514b3de channel:InputChannel username:string = Bool;
class TL_channels_updateUsername : public TLObject {
public:
  enum {
    CLASS_ID = 0x3514b3de
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_updateUsername#0x3514b3de";
  }

  std::string* mutable_username() { return &username_; } 
  const std::string& username() const { return username_; } 
  void set_username(const std::string& v) { username_ = v; } 
  void set_username(const char* v, size_t n) { username_.assign(v, n); } 
  void set_username(const char* v) { username_ = v; } 

private:
  std::unique_ptr<InputChannel> channel_;
  std::string username_;
};

// bots.answerWebhookJSONQuery#e6213f4d query_id:long data:DataJSON = Bool;
class TL_bots_answerWebhookJSONQuery : public TLObject {
public:
  enum {
    CLASS_ID = 0xe6213f4d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "bots_answerWebhookJSONQuery#0xe6213f4d";
  }

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

private:
  int64_t query_id_;
  std::unique_ptr<DataJSON> data_;
};

// payments.clearSavedInfo#d83d70c1 flags:# credentials:flags.0?true info:flags.1?true = Bool;
class TL_payments_clearSavedInfo : public TLObject {
public:
  enum {
    CLASS_ID = 0xd83d70c1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_clearSavedInfo#0xd83d70c1";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

private:
  int32_t flags_;
  bool credentials_;
  bool info_;
};

// phone.receivedCall#17d54f61 peer:InputPhoneCall = Bool;
class TL_phone_receivedCall : public TLObject {
public:
  enum {
    CLASS_ID = 0x17d54f61
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_receivedCall#0x17d54f61";
  }

private:
  std::unique_ptr<InputPhoneCall> peer_;
};

// phone.saveCallDebug#277add7e peer:InputPhoneCall debug:DataJSON = Bool;
class TL_phone_saveCallDebug : public TLObject {
public:
  enum {
    CLASS_ID = 0x277add7e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_saveCallDebug#0x277add7e";
  }

private:
  std::unique_ptr<InputPhoneCall> peer_;
  std::unique_ptr<DataJSON> debug_;
};

// invokeAfterMsg#cb9f372d {X:Type} msg_id:long query:!X = X;
class TL_invokeAfterMsg : public TLObject {
public:
  enum {
    CLASS_ID = 0xcb9f372d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "invokeAfterMsg#0xcb9f372d";
  }

  int64_t msg_id() const { return msg_id_; } 
  void set_msg_id(int64_t v) { msg_id_ = v; } 

private:
  int64_t msg_id_;
//  TQueryType query_;
};

// invokeAfterMsgs#3dc4b4f0 {X:Type} msg_ids:Vector<long> query:!X = X;
class TL_invokeAfterMsgs : public TLObject {
public:
  enum {
    CLASS_ID = 0x3dc4b4f0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "invokeAfterMsgs#0x3dc4b4f0";
  }

  size_t msg_ids_size() const { return msg_ids_.size(); } 
  const TLInt64Vector& msg_ids() const { return msg_ids_; } 
  int64_t msg_ids(int idx) const { return msg_ids_.vector()[idx]; } 
  void add_msg_ids(int64_t v) {msg_ids_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_msg_ids() { return &msg_ids_; } 

private:
  TLInt64Vector msg_ids_;
//  TQueryType query_;
};

// initConnection#69796de9 {X:Type} api_id:int device_model:string system_version:string app_version:string lang_code:string query:!X = X;
class TL_initConnection : public TLObject {
public:
  enum {
    CLASS_ID = 0x69796de9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "initConnection#0x69796de9";
  }

  int32_t api_id() const { return api_id_; } 
  void set_api_id(int32_t v) { api_id_ = v; } 

  std::string* mutable_device_model() { return &device_model_; } 
  const std::string& device_model() const { return device_model_; } 
  void set_device_model(const std::string& v) { device_model_ = v; } 
  void set_device_model(const char* v, size_t n) { device_model_.assign(v, n); } 
  void set_device_model(const char* v) { device_model_ = v; } 

  std::string* mutable_system_version() { return &system_version_; } 
  const std::string& system_version() const { return system_version_; } 
  void set_system_version(const std::string& v) { system_version_ = v; } 
  void set_system_version(const char* v, size_t n) { system_version_.assign(v, n); } 
  void set_system_version(const char* v) { system_version_ = v; } 

  std::string* mutable_app_version() { return &app_version_; } 
  const std::string& app_version() const { return app_version_; } 
  void set_app_version(const std::string& v) { app_version_ = v; } 
  void set_app_version(const char* v, size_t n) { app_version_.assign(v, n); } 
  void set_app_version(const char* v) { app_version_ = v; } 

  std::string* mutable_lang_code() { return &lang_code_; } 
  const std::string& lang_code() const { return lang_code_; } 
  void set_lang_code(const std::string& v) { lang_code_ = v; } 
  void set_lang_code(const char* v, size_t n) { lang_code_.assign(v, n); } 
  void set_lang_code(const char* v) { lang_code_ = v; } 

private:
  int32_t api_id_;
  std::string device_model_;
  std::string system_version_;
  std::string app_version_;
  std::string lang_code_;
//  TQueryType query_;
};

// invokeWithLayer#da9b0d0d {X:Type} layer:int query:!X = X;
class TL_invokeWithLayer : public TLObject {
public:
  enum {
    CLASS_ID = 0xda9b0d0d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "invokeWithLayer#0xda9b0d0d";
  }

  int32_t layer() const { return layer_; } 
  void set_layer(int32_t v) { layer_ = v; } 

private:
  int32_t layer_;
//  TQueryType query_;
};

// invokeWithoutUpdates#bf9459b7 {X:Type} query:!X = X;
class TL_invokeWithoutUpdates : public TLObject {
public:
  enum {
    CLASS_ID = 0xbf9459b7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "invokeWithoutUpdates#0xbf9459b7";
  }

private:
//  TQueryType query_;
};

// auth.checkPhone#6fe51dfb phone_number:string = auth.CheckedPhone;
class TL_auth_checkPhone : public TLObject {
public:
  enum {
    CLASS_ID = 0x6fe51dfb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_checkPhone#0x6fe51dfb";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

private:
  std::string phone_number_;
};

// auth.sendCode#86aef0ec flags:# allow_flashcall:flags.0?true phone_number:string current_number:flags.0?Bool api_id:int api_hash:string = auth.SentCode;
class TL_auth_sendCode : public TLObject {
public:
  enum {
    CLASS_ID = 0x86aef0ec
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_sendCode#0x86aef0ec";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  int32_t api_id() const { return api_id_; } 
  void set_api_id(int32_t v) { api_id_ = v; } 

  std::string* mutable_api_hash() { return &api_hash_; } 
  const std::string& api_hash() const { return api_hash_; } 
  void set_api_hash(const std::string& v) { api_hash_ = v; } 
  void set_api_hash(const char* v, size_t n) { api_hash_.assign(v, n); } 
  void set_api_hash(const char* v) { api_hash_ = v; } 

private:
  int32_t flags_;
  bool allow_flashcall_;
  std::string phone_number_;
  std::unique_ptr<Bool> current_number_;
  int32_t api_id_;
  std::string api_hash_;
};

// auth.resendCode#3ef1a9bf phone_number:string phone_code_hash:string = auth.SentCode;
class TL_auth_resendCode : public TLObject {
public:
  enum {
    CLASS_ID = 0x3ef1a9bf
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_resendCode#0x3ef1a9bf";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_phone_code_hash() { return &phone_code_hash_; } 
  const std::string& phone_code_hash() const { return phone_code_hash_; } 
  void set_phone_code_hash(const std::string& v) { phone_code_hash_ = v; } 
  void set_phone_code_hash(const char* v, size_t n) { phone_code_hash_.assign(v, n); } 
  void set_phone_code_hash(const char* v) { phone_code_hash_ = v; } 

private:
  std::string phone_number_;
  std::string phone_code_hash_;
};

// account.sendChangePhoneCode#8e57deb flags:# allow_flashcall:flags.0?true phone_number:string current_number:flags.0?Bool = auth.SentCode;
class TL_account_sendChangePhoneCode : public TLObject {
public:
  enum {
    CLASS_ID = 0x8e57deb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_sendChangePhoneCode#0x8e57deb";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

private:
  int32_t flags_;
  bool allow_flashcall_;
  std::string phone_number_;
  std::unique_ptr<Bool> current_number_;
};

// account.sendConfirmPhoneCode#1516d7bd flags:# allow_flashcall:flags.0?true hash:string current_number:flags.0?Bool = auth.SentCode;
class TL_account_sendConfirmPhoneCode : public TLObject {
public:
  enum {
    CLASS_ID = 0x1516d7bd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_sendConfirmPhoneCode#0x1516d7bd";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_hash() { return &hash_; } 
  const std::string& hash() const { return hash_; } 
  void set_hash(const std::string& v) { hash_ = v; } 
  void set_hash(const char* v, size_t n) { hash_.assign(v, n); } 
  void set_hash(const char* v) { hash_ = v; } 

private:
  int32_t flags_;
  bool allow_flashcall_;
  std::string hash_;
  std::unique_ptr<Bool> current_number_;
};

// auth.signUp#1b067634 phone_number:string phone_code_hash:string phone_code:string first_name:string last_name:string = auth.Authorization;
class TL_auth_signUp : public TLObject {
public:
  enum {
    CLASS_ID = 0x1b067634
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_signUp#0x1b067634";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_phone_code_hash() { return &phone_code_hash_; } 
  const std::string& phone_code_hash() const { return phone_code_hash_; } 
  void set_phone_code_hash(const std::string& v) { phone_code_hash_ = v; } 
  void set_phone_code_hash(const char* v, size_t n) { phone_code_hash_.assign(v, n); } 
  void set_phone_code_hash(const char* v) { phone_code_hash_ = v; } 

  std::string* mutable_phone_code() { return &phone_code_; } 
  const std::string& phone_code() const { return phone_code_; } 
  void set_phone_code(const std::string& v) { phone_code_ = v; } 
  void set_phone_code(const char* v, size_t n) { phone_code_.assign(v, n); } 
  void set_phone_code(const char* v) { phone_code_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

private:
  std::string phone_number_;
  std::string phone_code_hash_;
  std::string phone_code_;
  std::string first_name_;
  std::string last_name_;
};

// auth.signIn#bcd51581 phone_number:string phone_code_hash:string phone_code:string = auth.Authorization;
class TL_auth_signIn : public TLObject {
public:
  enum {
    CLASS_ID = 0xbcd51581
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_signIn#0xbcd51581";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_phone_code_hash() { return &phone_code_hash_; } 
  const std::string& phone_code_hash() const { return phone_code_hash_; } 
  void set_phone_code_hash(const std::string& v) { phone_code_hash_ = v; } 
  void set_phone_code_hash(const char* v, size_t n) { phone_code_hash_.assign(v, n); } 
  void set_phone_code_hash(const char* v) { phone_code_hash_ = v; } 

  std::string* mutable_phone_code() { return &phone_code_; } 
  const std::string& phone_code() const { return phone_code_; } 
  void set_phone_code(const std::string& v) { phone_code_ = v; } 
  void set_phone_code(const char* v, size_t n) { phone_code_.assign(v, n); } 
  void set_phone_code(const char* v) { phone_code_ = v; } 

private:
  std::string phone_number_;
  std::string phone_code_hash_;
  std::string phone_code_;
};

// auth.importAuthorization#e3ef9613 id:int bytes:bytes = auth.Authorization;
class TL_auth_importAuthorization : public TLObject {
public:
  enum {
    CLASS_ID = 0xe3ef9613
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_importAuthorization#0xe3ef9613";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_bytes() { return &bytes_; } 
  const std::string& bytes() const { return bytes_; } 
  void set_bytes(const std::string& v) { bytes_ = v; } 
  void set_bytes(const char* v, size_t n) { bytes_.assign(v, n); } 
  void set_bytes(const char* v) { bytes_ = v; } 

private:
  int32_t id_;
  std::string bytes_;
};

// auth.importBotAuthorization#67a3ff2c flags:int api_id:int api_hash:string bot_auth_token:string = auth.Authorization;
class TL_auth_importBotAuthorization : public TLObject {
public:
  enum {
    CLASS_ID = 0x67a3ff2c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_importBotAuthorization#0x67a3ff2c";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t api_id() const { return api_id_; } 
  void set_api_id(int32_t v) { api_id_ = v; } 

  std::string* mutable_api_hash() { return &api_hash_; } 
  const std::string& api_hash() const { return api_hash_; } 
  void set_api_hash(const std::string& v) { api_hash_ = v; } 
  void set_api_hash(const char* v, size_t n) { api_hash_.assign(v, n); } 
  void set_api_hash(const char* v) { api_hash_ = v; } 

  std::string* mutable_bot_auth_token() { return &bot_auth_token_; } 
  const std::string& bot_auth_token() const { return bot_auth_token_; } 
  void set_bot_auth_token(const std::string& v) { bot_auth_token_ = v; } 
  void set_bot_auth_token(const char* v, size_t n) { bot_auth_token_.assign(v, n); } 
  void set_bot_auth_token(const char* v) { bot_auth_token_ = v; } 

private:
  int32_t flags_;
  int32_t api_id_;
  std::string api_hash_;
  std::string bot_auth_token_;
};

// auth.checkPassword#a63011e password_hash:bytes = auth.Authorization;
class TL_auth_checkPassword : public TLObject {
public:
  enum {
    CLASS_ID = 0xa63011e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_checkPassword#0xa63011e";
  }

  std::string* mutable_password_hash() { return &password_hash_; } 
  const std::string& password_hash() const { return password_hash_; } 
  void set_password_hash(const std::string& v) { password_hash_ = v; } 
  void set_password_hash(const char* v, size_t n) { password_hash_.assign(v, n); } 
  void set_password_hash(const char* v) { password_hash_ = v; } 

private:
  std::string password_hash_;
};

// auth.recoverPassword#4ea56e92 code:string = auth.Authorization;
class TL_auth_recoverPassword : public TLObject {
public:
  enum {
    CLASS_ID = 0x4ea56e92
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_recoverPassword#0x4ea56e92";
  }

  std::string* mutable_code() { return &code_; } 
  const std::string& code() const { return code_; } 
  void set_code(const std::string& v) { code_ = v; } 
  void set_code(const char* v, size_t n) { code_.assign(v, n); } 
  void set_code(const char* v) { code_ = v; } 

private:
  std::string code_;
};

// auth.exportAuthorization#e5bfffcd dc_id:int = auth.ExportedAuthorization;
class TL_auth_exportAuthorization : public TLObject {
public:
  enum {
    CLASS_ID = 0xe5bfffcd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_exportAuthorization#0xe5bfffcd";
  }

  int32_t dc_id() const { return dc_id_; } 
  void set_dc_id(int32_t v) { dc_id_ = v; } 

private:
  int32_t dc_id_;
};

// auth.requestPasswordRecovery#d897bc66 = auth.PasswordRecovery;
class TL_auth_requestPasswordRecovery : public TLObject {
public:
  enum {
    CLASS_ID = 0xd897bc66
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "auth_requestPasswordRecovery#0xd897bc66";
  }

private:
};

// account.getNotifySettings#12b3ad31 peer:InputNotifyPeer = PeerNotifySettings;
class TL_account_getNotifySettings : public TLObject {
public:
  enum {
    CLASS_ID = 0x12b3ad31
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_getNotifySettings#0x12b3ad31";
  }

private:
  std::unique_ptr<InputNotifyPeer> peer_;
};

// account.updateProfile#78515775 flags:# first_name:flags.0?string last_name:flags.1?string about:flags.2?string = User;
class TL_account_updateProfile : public TLObject {
public:
  enum {
    CLASS_ID = 0x78515775
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_updateProfile#0x78515775";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_first_name() { return &first_name_; } 
  const std::string& first_name() const { return first_name_; } 
  void set_first_name(const std::string& v) { first_name_ = v; } 
  void set_first_name(const char* v, size_t n) { first_name_.assign(v, n); } 
  void set_first_name(const char* v) { first_name_ = v; } 

  std::string* mutable_last_name() { return &last_name_; } 
  const std::string& last_name() const { return last_name_; } 
  void set_last_name(const std::string& v) { last_name_ = v; } 
  void set_last_name(const char* v, size_t n) { last_name_.assign(v, n); } 
  void set_last_name(const char* v) { last_name_ = v; } 

  std::string* mutable_about() { return &about_; } 
  const std::string& about() const { return about_; } 
  void set_about(const std::string& v) { about_ = v; } 
  void set_about(const char* v, size_t n) { about_.assign(v, n); } 
  void set_about(const char* v) { about_ = v; } 

private:
  int32_t flags_;
  std::string first_name_;
  std::string last_name_;
  std::string about_;
};

// account.updateUsername#3e0bdd7c username:string = User;
class TL_account_updateUsername : public TLObject {
public:
  enum {
    CLASS_ID = 0x3e0bdd7c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_updateUsername#0x3e0bdd7c";
  }

  std::string* mutable_username() { return &username_; } 
  const std::string& username() const { return username_; } 
  void set_username(const std::string& v) { username_ = v; } 
  void set_username(const char* v, size_t n) { username_.assign(v, n); } 
  void set_username(const char* v) { username_ = v; } 

private:
  std::string username_;
};

// account.changePhone#70c32edb phone_number:string phone_code_hash:string phone_code:string = User;
class TL_account_changePhone : public TLObject {
public:
  enum {
    CLASS_ID = 0x70c32edb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_changePhone#0x70c32edb";
  }

  std::string* mutable_phone_number() { return &phone_number_; } 
  const std::string& phone_number() const { return phone_number_; } 
  void set_phone_number(const std::string& v) { phone_number_ = v; } 
  void set_phone_number(const char* v, size_t n) { phone_number_.assign(v, n); } 
  void set_phone_number(const char* v) { phone_number_ = v; } 

  std::string* mutable_phone_code_hash() { return &phone_code_hash_; } 
  const std::string& phone_code_hash() const { return phone_code_hash_; } 
  void set_phone_code_hash(const std::string& v) { phone_code_hash_ = v; } 
  void set_phone_code_hash(const char* v, size_t n) { phone_code_hash_.assign(v, n); } 
  void set_phone_code_hash(const char* v) { phone_code_hash_ = v; } 

  std::string* mutable_phone_code() { return &phone_code_; } 
  const std::string& phone_code() const { return phone_code_; } 
  void set_phone_code(const std::string& v) { phone_code_ = v; } 
  void set_phone_code(const char* v, size_t n) { phone_code_.assign(v, n); } 
  void set_phone_code(const char* v) { phone_code_ = v; } 

private:
  std::string phone_number_;
  std::string phone_code_hash_;
  std::string phone_code_;
};

// contacts.importCard#4fe196fe export_card:Vector<int> = User;
class TL_contacts_importCard : public TLObject {
public:
  enum {
    CLASS_ID = 0x4fe196fe
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_importCard#0x4fe196fe";
  }

  size_t export_card_size() const { return export_card_.size(); } 
  const TLInt32Vector& export_card() const { return export_card_; } 
  int32_t export_card(int idx) const { return export_card_.vector()[idx]; } 
  void add_export_card(int32_t v) {export_card_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_export_card() { return &export_card_; } 

private:
  TLInt32Vector export_card_;
};

// account.getWallPapers#c04cfac2 = Vector<WallPaper>;
class TL_account_getWallPapers : public TLObject {
public:
  enum {
    CLASS_ID = 0xc04cfac2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_getWallPapers#0xc04cfac2";
  }

private:
};

// account.getPrivacy#dadbc950 key:InputPrivacyKey = account.PrivacyRules;
class TL_account_getPrivacy : public TLObject {
public:
  enum {
    CLASS_ID = 0xdadbc950
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_getPrivacy#0xdadbc950";
  }

private:
  std::unique_ptr<InputPrivacyKey> key_;
};

// account.setPrivacy#c9f81ce8 key:InputPrivacyKey rules:Vector<InputPrivacyRule> = account.PrivacyRules;
class TL_account_setPrivacy : public TLObject {
public:
  enum {
    CLASS_ID = 0xc9f81ce8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_setPrivacy#0xc9f81ce8";
  }

private:
  std::unique_ptr<InputPrivacyKey> key_;
  TLObjectVector<InputPrivacyRule> rules_;
};

// account.getAccountTTL#8fc711d = AccountDaysTTL;
class TL_account_getAccountTTL : public TLObject {
public:
  enum {
    CLASS_ID = 0x8fc711d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_getAccountTTL#0x8fc711d";
  }

private:
};

// account.getAuthorizations#e320c158 = account.Authorizations;
class TL_account_getAuthorizations : public TLObject {
public:
  enum {
    CLASS_ID = 0xe320c158
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_getAuthorizations#0xe320c158";
  }

private:
};

// account.getPassword#548a30f5 = account.Password;
class TL_account_getPassword : public TLObject {
public:
  enum {
    CLASS_ID = 0x548a30f5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_getPassword#0x548a30f5";
  }

private:
};

// account.getPasswordSettings#bc8d11bb current_password_hash:bytes = account.PasswordSettings;
class TL_account_getPasswordSettings : public TLObject {
public:
  enum {
    CLASS_ID = 0xbc8d11bb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_getPasswordSettings#0xbc8d11bb";
  }

  std::string* mutable_current_password_hash() { return &current_password_hash_; } 
  const std::string& current_password_hash() const { return current_password_hash_; } 
  void set_current_password_hash(const std::string& v) { current_password_hash_ = v; } 
  void set_current_password_hash(const char* v, size_t n) { current_password_hash_.assign(v, n); } 
  void set_current_password_hash(const char* v) { current_password_hash_ = v; } 

private:
  std::string current_password_hash_;
};

// account.getTmpPassword#4a82327e password_hash:bytes period:int = account.TmpPassword;
class TL_account_getTmpPassword : public TLObject {
public:
  enum {
    CLASS_ID = 0x4a82327e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "account_getTmpPassword#0x4a82327e";
  }

  std::string* mutable_password_hash() { return &password_hash_; } 
  const std::string& password_hash() const { return password_hash_; } 
  void set_password_hash(const std::string& v) { password_hash_ = v; } 
  void set_password_hash(const char* v, size_t n) { password_hash_.assign(v, n); } 
  void set_password_hash(const char* v) { password_hash_ = v; } 

  int32_t period() const { return period_; } 
  void set_period(int32_t v) { period_ = v; } 

private:
  std::string password_hash_;
  int32_t period_;
};

// users.getUsers#d91a548 id:Vector<InputUser> = Vector<User>;
class TL_users_getUsers : public TLObject {
public:
  enum {
    CLASS_ID = 0xd91a548
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "users_getUsers#0xd91a548";
  }

private:
  TLObjectVector<InputUser> id_;
};

// users.getFullUser#ca30a5b1 id:InputUser = UserFull;
class TL_users_getFullUser : public TLObject {
public:
  enum {
    CLASS_ID = 0xca30a5b1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "users_getFullUser#0xca30a5b1";
  }

private:
  std::unique_ptr<InputUser> id_;
};

// contacts.getStatuses#c4a353ee = Vector<ContactStatus>;
class TL_contacts_getStatuses : public TLObject {
public:
  enum {
    CLASS_ID = 0xc4a353ee
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_getStatuses#0xc4a353ee";
  }

private:
};

// contacts.getContacts#22c6aa08 hash:string = contacts.Contacts;
class TL_contacts_getContacts : public TLObject {
public:
  enum {
    CLASS_ID = 0x22c6aa08
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_getContacts#0x22c6aa08";
  }

  std::string* mutable_hash() { return &hash_; } 
  const std::string& hash() const { return hash_; } 
  void set_hash(const std::string& v) { hash_ = v; } 
  void set_hash(const char* v, size_t n) { hash_.assign(v, n); } 
  void set_hash(const char* v) { hash_ = v; } 

private:
  std::string hash_;
};

// contacts.importContacts#da30b32d contacts:Vector<InputContact> replace:Bool = contacts.ImportedContacts;
class TL_contacts_importContacts : public TLObject {
public:
  enum {
    CLASS_ID = 0xda30b32d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_importContacts#0xda30b32d";
  }

private:
  TLObjectVector<InputContact> contacts_;
  std::unique_ptr<Bool> replace_;
};

// contacts.deleteContact#8e953744 id:InputUser = contacts.Link;
class TL_contacts_deleteContact : public TLObject {
public:
  enum {
    CLASS_ID = 0x8e953744
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_deleteContact#0x8e953744";
  }

private:
  std::unique_ptr<InputUser> id_;
};

// contacts.getBlocked#f57c350f offset:int limit:int = contacts.Blocked;
class TL_contacts_getBlocked : public TLObject {
public:
  enum {
    CLASS_ID = 0xf57c350f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_getBlocked#0xf57c350f";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  int32_t offset_;
  int32_t limit_;
};

// contacts.exportCard#84e53737 = Vector<int>;
class TL_contacts_exportCard : public TLObject {
public:
  enum {
    CLASS_ID = 0x84e53737
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_exportCard#0x84e53737";
  }

private:
};

// messages.getMessagesViews#c4c8a55d peer:InputPeer id:Vector<int> increment:Bool = Vector<int>;
class TL_messages_getMessagesViews : public TLObject {
public:
  enum {
    CLASS_ID = 0xc4c8a55d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getMessagesViews#0xc4c8a55d";
  }

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

private:
  std::unique_ptr<InputPeer> peer_;
  TLInt32Vector id_;
  std::unique_ptr<Bool> increment_;
};

// contacts.search#11f812d8 q:string limit:int = contacts.Found;
class TL_contacts_search : public TLObject {
public:
  enum {
    CLASS_ID = 0x11f812d8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_search#0x11f812d8";
  }

  std::string* mutable_q() { return &q_; } 
  const std::string& q() const { return q_; } 
  void set_q(const std::string& v) { q_ = v; } 
  void set_q(const char* v, size_t n) { q_.assign(v, n); } 
  void set_q(const char* v) { q_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  std::string q_;
  int32_t limit_;
};

// contacts.resolveUsername#f93ccba3 username:string = contacts.ResolvedPeer;
class TL_contacts_resolveUsername : public TLObject {
public:
  enum {
    CLASS_ID = 0xf93ccba3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_resolveUsername#0xf93ccba3";
  }

  std::string* mutable_username() { return &username_; } 
  const std::string& username() const { return username_; } 
  void set_username(const std::string& v) { username_ = v; } 
  void set_username(const char* v, size_t n) { username_.assign(v, n); } 
  void set_username(const char* v) { username_ = v; } 

private:
  std::string username_;
};

// contacts.getTopPeers#d4982db5 flags:# correspondents:flags.0?true bots_pm:flags.1?true bots_inline:flags.2?true groups:flags.10?true channels:flags.15?true offset:int limit:int hash:int = contacts.TopPeers;
class TL_contacts_getTopPeers : public TLObject {
public:
  enum {
    CLASS_ID = 0xd4982db5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "contacts_getTopPeers#0xd4982db5";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t flags_;
  bool correspondents_;
  bool bots_pm_;
  bool bots_inline_;
  bool groups_;
  bool channels_;
  int32_t offset_;
  int32_t limit_;
  int32_t hash_;
};

// messages.getMessages#4222fa74 id:Vector<int> = messages.Messages;
class TL_messages_getMessages : public TLObject {
public:
  enum {
    CLASS_ID = 0x4222fa74
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getMessages#0x4222fa74";
  }

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

private:
  TLInt32Vector id_;
};

// messages.getHistory#afa92846 peer:InputPeer offset_id:int offset_date:int add_offset:int limit:int max_id:int min_id:int = messages.Messages;
class TL_messages_getHistory : public TLObject {
public:
  enum {
    CLASS_ID = 0xafa92846
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getHistory#0xafa92846";
  }

  int32_t offset_id() const { return offset_id_; } 
  void set_offset_id(int32_t v) { offset_id_ = v; } 

  int32_t offset_date() const { return offset_date_; } 
  void set_offset_date(int32_t v) { offset_date_ = v; } 

  int32_t add_offset() const { return add_offset_; } 
  void set_add_offset(int32_t v) { add_offset_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

  int32_t min_id() const { return min_id_; } 
  void set_min_id(int32_t v) { min_id_ = v; } 

private:
  std::unique_ptr<InputPeer> peer_;
  int32_t offset_id_;
  int32_t offset_date_;
  int32_t add_offset_;
  int32_t limit_;
  int32_t max_id_;
  int32_t min_id_;
};

// messages.search#d4569248 flags:# peer:InputPeer q:string filter:MessagesFilter min_date:int max_date:int offset:int max_id:int limit:int = messages.Messages;
class TL_messages_search : public TLObject {
public:
  enum {
    CLASS_ID = 0xd4569248
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_search#0xd4569248";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_q() { return &q_; } 
  const std::string& q() const { return q_; } 
  void set_q(const std::string& v) { q_ = v; } 
  void set_q(const char* v, size_t n) { q_.assign(v, n); } 
  void set_q(const char* v) { q_ = v; } 

  int32_t min_date() const { return min_date_; } 
  void set_min_date(int32_t v) { min_date_ = v; } 

  int32_t max_date() const { return max_date_; } 
  void set_max_date(int32_t v) { max_date_ = v; } 

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<InputPeer> peer_;
  std::string q_;
  std::unique_ptr<MessagesFilter> filter_;
  int32_t min_date_;
  int32_t max_date_;
  int32_t offset_;
  int32_t max_id_;
  int32_t limit_;
};

// messages.searchGlobal#9e3cacb0 q:string offset_date:int offset_peer:InputPeer offset_id:int limit:int = messages.Messages;
class TL_messages_searchGlobal : public TLObject {
public:
  enum {
    CLASS_ID = 0x9e3cacb0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_searchGlobal#0x9e3cacb0";
  }

  std::string* mutable_q() { return &q_; } 
  const std::string& q() const { return q_; } 
  void set_q(const std::string& v) { q_ = v; } 
  void set_q(const char* v, size_t n) { q_.assign(v, n); } 
  void set_q(const char* v) { q_ = v; } 

  int32_t offset_date() const { return offset_date_; } 
  void set_offset_date(int32_t v) { offset_date_ = v; } 

  int32_t offset_id() const { return offset_id_; } 
  void set_offset_id(int32_t v) { offset_id_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  std::string q_;
  int32_t offset_date_;
  std::unique_ptr<InputPeer> offset_peer_;
  int32_t offset_id_;
  int32_t limit_;
};

// channels.getMessages#93d7b347 channel:InputChannel id:Vector<int> = messages.Messages;
class TL_channels_getMessages : public TLObject {
public:
  enum {
    CLASS_ID = 0x93d7b347
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_getMessages#0x93d7b347";
  }

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

private:
  std::unique_ptr<InputChannel> channel_;
  TLInt32Vector id_;
};

// messages.getDialogs#191ba9c5 flags:# exclude_pinned:flags.0?true offset_date:int offset_id:int offset_peer:InputPeer limit:int = messages.Dialogs;
class TL_messages_getDialogs : public TLObject {
public:
  enum {
    CLASS_ID = 0x191ba9c5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getDialogs#0x191ba9c5";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t offset_date() const { return offset_date_; } 
  void set_offset_date(int32_t v) { offset_date_ = v; } 

  int32_t offset_id() const { return offset_id_; } 
  void set_offset_id(int32_t v) { offset_id_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  int32_t flags_;
  bool exclude_pinned_;
  int32_t offset_date_;
  int32_t offset_id_;
  std::unique_ptr<InputPeer> offset_peer_;
  int32_t limit_;
};

// messages.readHistory#e306d3a peer:InputPeer max_id:int = messages.AffectedMessages;
class TL_messages_readHistory : public TLObject {
public:
  enum {
    CLASS_ID = 0xe306d3a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_readHistory#0xe306d3a";
  }

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

private:
  std::unique_ptr<InputPeer> peer_;
  int32_t max_id_;
};

// messages.deleteMessages#e58e95d2 flags:# revoke:flags.0?true id:Vector<int> = messages.AffectedMessages;
class TL_messages_deleteMessages : public TLObject {
public:
  enum {
    CLASS_ID = 0xe58e95d2
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_deleteMessages#0xe58e95d2";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

private:
  int32_t flags_;
  bool revoke_;
  TLInt32Vector id_;
};

// messages.readMessageContents#36a73f77 id:Vector<int> = messages.AffectedMessages;
class TL_messages_readMessageContents : public TLObject {
public:
  enum {
    CLASS_ID = 0x36a73f77
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_readMessageContents#0x36a73f77";
  }

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

private:
  TLInt32Vector id_;
};

// channels.deleteMessages#84c1fd4e channel:InputChannel id:Vector<int> = messages.AffectedMessages;
class TL_channels_deleteMessages : public TLObject {
public:
  enum {
    CLASS_ID = 0x84c1fd4e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_deleteMessages#0x84c1fd4e";
  }

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

private:
  std::unique_ptr<InputChannel> channel_;
  TLInt32Vector id_;
};

// messages.deleteHistory#1c015b09 flags:# just_clear:flags.0?true peer:InputPeer max_id:int = messages.AffectedHistory;
class TL_messages_deleteHistory : public TLObject {
public:
  enum {
    CLASS_ID = 0x1c015b09
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_deleteHistory#0x1c015b09";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

private:
  int32_t flags_;
  bool just_clear_;
  std::unique_ptr<InputPeer> peer_;
  int32_t max_id_;
};

// channels.deleteUserHistory#d10dd71b channel:InputChannel user_id:InputUser = messages.AffectedHistory;
class TL_channels_deleteUserHistory : public TLObject {
public:
  enum {
    CLASS_ID = 0xd10dd71b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_deleteUserHistory#0xd10dd71b";
  }

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<InputUser> user_id_;
};

// messages.receivedMessages#5a954c0 max_id:int = Vector<ReceivedNotifyMessage>;
class TL_messages_receivedMessages : public TLObject {
public:
  enum {
    CLASS_ID = 0x5a954c0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_receivedMessages#0x5a954c0";
  }

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

private:
  int32_t max_id_;
};

// messages.sendMessage#fa88427a flags:# no_webpage:flags.1?true silent:flags.5?true background:flags.6?true clear_draft:flags.7?true peer:InputPeer reply_to_msg_id:flags.0?int message:string random_id:long reply_markup:flags.2?ReplyMarkup entities:flags.3?Vector<MessageEntity> = Updates;
class TL_messages_sendMessage : public TLObject {
public:
  enum {
    CLASS_ID = 0xfa88427a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_sendMessage#0xfa88427a";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

private:
  int32_t flags_;
  bool no_webpage_;
  bool silent_;
  bool background_;
  bool clear_draft_;
  std::unique_ptr<InputPeer> peer_;
  int32_t reply_to_msg_id_;
  std::string message_;
  int64_t random_id_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
  TLObjectVector<MessageEntity> entities_;
};

// messages.sendMedia#c8f16791 flags:# silent:flags.5?true background:flags.6?true clear_draft:flags.7?true peer:InputPeer reply_to_msg_id:flags.0?int media:InputMedia random_id:long reply_markup:flags.2?ReplyMarkup = Updates;
class TL_messages_sendMedia : public TLObject {
public:
  enum {
    CLASS_ID = 0xc8f16791
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_sendMedia#0xc8f16791";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

private:
  int32_t flags_;
  bool silent_;
  bool background_;
  bool clear_draft_;
  std::unique_ptr<InputPeer> peer_;
  int32_t reply_to_msg_id_;
  std::unique_ptr<InputMedia> media_;
  int64_t random_id_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
};

// messages.forwardMessages#708e0195 flags:# silent:flags.5?true background:flags.6?true with_my_score:flags.8?true from_peer:InputPeer id:Vector<int> random_id:Vector<long> to_peer:InputPeer = Updates;
class TL_messages_forwardMessages : public TLObject {
public:
  enum {
    CLASS_ID = 0x708e0195
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_forwardMessages#0x708e0195";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

  size_t random_id_size() const { return random_id_.size(); } 
  const TLInt64Vector& random_id() const { return random_id_; } 
  int64_t random_id(int idx) const { return random_id_.vector()[idx]; } 
  void add_random_id(int64_t v) {random_id_.mutable_vector()->push_back(v); } 
  TLInt64Vector* mutable_random_id() { return &random_id_; } 

private:
  int32_t flags_;
  bool silent_;
  bool background_;
  bool with_my_score_;
  std::unique_ptr<InputPeer> from_peer_;
  TLInt32Vector id_;
  TLInt64Vector random_id_;
  std::unique_ptr<InputPeer> to_peer_;
};

// messages.editChatTitle#dc452855 chat_id:int title:string = Updates;
class TL_messages_editChatTitle : public TLObject {
public:
  enum {
    CLASS_ID = 0xdc452855
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_editChatTitle#0xdc452855";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  int32_t chat_id_;
  std::string title_;
};

// messages.editChatPhoto#ca4c79d8 chat_id:int photo:InputChatPhoto = Updates;
class TL_messages_editChatPhoto : public TLObject {
public:
  enum {
    CLASS_ID = 0xca4c79d8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_editChatPhoto#0xca4c79d8";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
  std::unique_ptr<InputChatPhoto> photo_;
};

// messages.addChatUser#f9a0aa09 chat_id:int user_id:InputUser fwd_limit:int = Updates;
class TL_messages_addChatUser : public TLObject {
public:
  enum {
    CLASS_ID = 0xf9a0aa09
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_addChatUser#0xf9a0aa09";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

  int32_t fwd_limit() const { return fwd_limit_; } 
  void set_fwd_limit(int32_t v) { fwd_limit_ = v; } 

private:
  int32_t chat_id_;
  std::unique_ptr<InputUser> user_id_;
  int32_t fwd_limit_;
};

// messages.deleteChatUser#e0611f16 chat_id:int user_id:InputUser = Updates;
class TL_messages_deleteChatUser : public TLObject {
public:
  enum {
    CLASS_ID = 0xe0611f16
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_deleteChatUser#0xe0611f16";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
  std::unique_ptr<InputUser> user_id_;
};

// messages.createChat#9cb126e users:Vector<InputUser> title:string = Updates;
class TL_messages_createChat : public TLObject {
public:
  enum {
    CLASS_ID = 0x9cb126e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_createChat#0x9cb126e";
  }

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  TLObjectVector<InputUser> users_;
  std::string title_;
};

// messages.forwardMessage#33963bf9 peer:InputPeer id:int random_id:long = Updates;
class TL_messages_forwardMessage : public TLObject {
public:
  enum {
    CLASS_ID = 0x33963bf9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_forwardMessage#0x33963bf9";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

private:
  std::unique_ptr<InputPeer> peer_;
  int32_t id_;
  int64_t random_id_;
};

// messages.importChatInvite#6c50051c hash:string = Updates;
class TL_messages_importChatInvite : public TLObject {
public:
  enum {
    CLASS_ID = 0x6c50051c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_importChatInvite#0x6c50051c";
  }

  std::string* mutable_hash() { return &hash_; } 
  const std::string& hash() const { return hash_; } 
  void set_hash(const std::string& v) { hash_ = v; } 
  void set_hash(const char* v, size_t n) { hash_.assign(v, n); } 
  void set_hash(const char* v) { hash_ = v; } 

private:
  std::string hash_;
};

// messages.startBot#e6df7378 bot:InputUser peer:InputPeer random_id:long start_param:string = Updates;
class TL_messages_startBot : public TLObject {
public:
  enum {
    CLASS_ID = 0xe6df7378
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_startBot#0xe6df7378";
  }

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

  std::string* mutable_start_param() { return &start_param_; } 
  const std::string& start_param() const { return start_param_; } 
  void set_start_param(const std::string& v) { start_param_ = v; } 
  void set_start_param(const char* v, size_t n) { start_param_.assign(v, n); } 
  void set_start_param(const char* v) { start_param_ = v; } 

private:
  std::unique_ptr<InputUser> bot_;
  std::unique_ptr<InputPeer> peer_;
  int64_t random_id_;
  std::string start_param_;
};

// messages.toggleChatAdmins#ec8bd9e1 chat_id:int enabled:Bool = Updates;
class TL_messages_toggleChatAdmins : public TLObject {
public:
  enum {
    CLASS_ID = 0xec8bd9e1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_toggleChatAdmins#0xec8bd9e1";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
  std::unique_ptr<Bool> enabled_;
};

// messages.migrateChat#15a3b8e3 chat_id:int = Updates;
class TL_messages_migrateChat : public TLObject {
public:
  enum {
    CLASS_ID = 0x15a3b8e3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_migrateChat#0x15a3b8e3";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
};

// messages.sendInlineBotResult#b16e06fe flags:# silent:flags.5?true background:flags.6?true clear_draft:flags.7?true peer:InputPeer reply_to_msg_id:flags.0?int random_id:long query_id:long id:string = Updates;
class TL_messages_sendInlineBotResult : public TLObject {
public:
  enum {
    CLASS_ID = 0xb16e06fe
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_sendInlineBotResult#0xb16e06fe";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t reply_to_msg_id() const { return reply_to_msg_id_; } 
  void set_reply_to_msg_id(int32_t v) { reply_to_msg_id_ = v; } 

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

  int64_t query_id() const { return query_id_; } 
  void set_query_id(int64_t v) { query_id_ = v; } 

  std::string* mutable_id() { return &id_; } 
  const std::string& id() const { return id_; } 
  void set_id(const std::string& v) { id_ = v; } 
  void set_id(const char* v, size_t n) { id_.assign(v, n); } 
  void set_id(const char* v) { id_ = v; } 

private:
  int32_t flags_;
  bool silent_;
  bool background_;
  bool clear_draft_;
  std::unique_ptr<InputPeer> peer_;
  int32_t reply_to_msg_id_;
  int64_t random_id_;
  int64_t query_id_;
  std::string id_;
};

// messages.editMessage#ce91e4ca flags:# no_webpage:flags.1?true peer:InputPeer id:int message:flags.11?string reply_markup:flags.2?ReplyMarkup entities:flags.3?Vector<MessageEntity> = Updates;
class TL_messages_editMessage : public TLObject {
public:
  enum {
    CLASS_ID = 0xce91e4ca
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_editMessage#0xce91e4ca";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  int32_t flags_;
  bool no_webpage_;
  std::unique_ptr<InputPeer> peer_;
  int32_t id_;
  std::string message_;
  std::unique_ptr<ReplyMarkup> reply_markup_;
  TLObjectVector<MessageEntity> entities_;
};

// messages.getAllDrafts#6a3f8d65 = Updates;
class TL_messages_getAllDrafts : public TLObject {
public:
  enum {
    CLASS_ID = 0x6a3f8d65
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getAllDrafts#0x6a3f8d65";
  }

private:
};

// messages.setGameScore#8ef8ecc0 flags:# edit_message:flags.0?true force:flags.1?true peer:InputPeer id:int user_id:InputUser score:int = Updates;
class TL_messages_setGameScore : public TLObject {
public:
  enum {
    CLASS_ID = 0x8ef8ecc0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_setGameScore#0x8ef8ecc0";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

  int32_t score() const { return score_; } 
  void set_score(int32_t v) { score_ = v; } 

private:
  int32_t flags_;
  bool edit_message_;
  bool force_;
  std::unique_ptr<InputPeer> peer_;
  int32_t id_;
  std::unique_ptr<InputUser> user_id_;
  int32_t score_;
};

// help.getAppChangelog#9010ef6f prev_app_version:string = Updates;
class TL_help_getAppChangelog : public TLObject {
public:
  enum {
    CLASS_ID = 0x9010ef6f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_getAppChangelog#0x9010ef6f";
  }

  std::string* mutable_prev_app_version() { return &prev_app_version_; } 
  const std::string& prev_app_version() const { return prev_app_version_; } 
  void set_prev_app_version(const std::string& v) { prev_app_version_ = v; } 
  void set_prev_app_version(const char* v, size_t n) { prev_app_version_.assign(v, n); } 
  void set_prev_app_version(const char* v) { prev_app_version_ = v; } 

private:
  std::string prev_app_version_;
};

// channels.createChannel#f4893d7f flags:# broadcast:flags.0?true megagroup:flags.1?true title:string about:string = Updates;
class TL_channels_createChannel : public TLObject {
public:
  enum {
    CLASS_ID = 0xf4893d7f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_createChannel#0xf4893d7f";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

  std::string* mutable_about() { return &about_; } 
  const std::string& about() const { return about_; } 
  void set_about(const std::string& v) { about_ = v; } 
  void set_about(const char* v, size_t n) { about_.assign(v, n); } 
  void set_about(const char* v) { about_ = v; } 

private:
  int32_t flags_;
  bool broadcast_;
  bool megagroup_;
  std::string title_;
  std::string about_;
};

// channels.editAdmin#eb7611d0 channel:InputChannel user_id:InputUser role:ChannelParticipantRole = Updates;
class TL_channels_editAdmin : public TLObject {
public:
  enum {
    CLASS_ID = 0xeb7611d0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_editAdmin#0xeb7611d0";
  }

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<InputUser> user_id_;
  std::unique_ptr<ChannelParticipantRole> role_;
};

// channels.editTitle#566decd0 channel:InputChannel title:string = Updates;
class TL_channels_editTitle : public TLObject {
public:
  enum {
    CLASS_ID = 0x566decd0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_editTitle#0x566decd0";
  }

  std::string* mutable_title() { return &title_; } 
  const std::string& title() const { return title_; } 
  void set_title(const std::string& v) { title_ = v; } 
  void set_title(const char* v, size_t n) { title_.assign(v, n); } 
  void set_title(const char* v) { title_ = v; } 

private:
  std::unique_ptr<InputChannel> channel_;
  std::string title_;
};

// channels.editPhoto#f12e57c9 channel:InputChannel photo:InputChatPhoto = Updates;
class TL_channels_editPhoto : public TLObject {
public:
  enum {
    CLASS_ID = 0xf12e57c9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_editPhoto#0xf12e57c9";
  }

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<InputChatPhoto> photo_;
};

// channels.joinChannel#24b524c5 channel:InputChannel = Updates;
class TL_channels_joinChannel : public TLObject {
public:
  enum {
    CLASS_ID = 0x24b524c5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_joinChannel#0x24b524c5";
  }

private:
  std::unique_ptr<InputChannel> channel_;
};

// channels.leaveChannel#f836aa95 channel:InputChannel = Updates;
class TL_channels_leaveChannel : public TLObject {
public:
  enum {
    CLASS_ID = 0xf836aa95
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_leaveChannel#0xf836aa95";
  }

private:
  std::unique_ptr<InputChannel> channel_;
};

// channels.inviteToChannel#199f3a6c channel:InputChannel users:Vector<InputUser> = Updates;
class TL_channels_inviteToChannel : public TLObject {
public:
  enum {
    CLASS_ID = 0x199f3a6c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_inviteToChannel#0x199f3a6c";
  }

private:
  std::unique_ptr<InputChannel> channel_;
  TLObjectVector<InputUser> users_;
};

// channels.kickFromChannel#a672de14 channel:InputChannel user_id:InputUser kicked:Bool = Updates;
class TL_channels_kickFromChannel : public TLObject {
public:
  enum {
    CLASS_ID = 0xa672de14
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_kickFromChannel#0xa672de14";
  }

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<InputUser> user_id_;
  std::unique_ptr<Bool> kicked_;
};

// channels.deleteChannel#c0111fe3 channel:InputChannel = Updates;
class TL_channels_deleteChannel : public TLObject {
public:
  enum {
    CLASS_ID = 0xc0111fe3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_deleteChannel#0xc0111fe3";
  }

private:
  std::unique_ptr<InputChannel> channel_;
};

// channels.toggleInvites#49609307 channel:InputChannel enabled:Bool = Updates;
class TL_channels_toggleInvites : public TLObject {
public:
  enum {
    CLASS_ID = 0x49609307
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_toggleInvites#0x49609307";
  }

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<Bool> enabled_;
};

// channels.toggleSignatures#1f69b606 channel:InputChannel enabled:Bool = Updates;
class TL_channels_toggleSignatures : public TLObject {
public:
  enum {
    CLASS_ID = 0x1f69b606
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_toggleSignatures#0x1f69b606";
  }

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<Bool> enabled_;
};

// channels.updatePinnedMessage#a72ded52 flags:# silent:flags.0?true channel:InputChannel id:int = Updates;
class TL_channels_updatePinnedMessage : public TLObject {
public:
  enum {
    CLASS_ID = 0xa72ded52
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_updatePinnedMessage#0xa72ded52";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  int32_t flags_;
  bool silent_;
  std::unique_ptr<InputChannel> channel_;
  int32_t id_;
};

// phone.discardCall#78d413a6 peer:InputPhoneCall duration:int reason:PhoneCallDiscardReason connection_id:long = Updates;
class TL_phone_discardCall : public TLObject {
public:
  enum {
    CLASS_ID = 0x78d413a6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_discardCall#0x78d413a6";
  }

  int32_t duration() const { return duration_; } 
  void set_duration(int32_t v) { duration_ = v; } 

  int64_t connection_id() const { return connection_id_; } 
  void set_connection_id(int64_t v) { connection_id_ = v; } 

private:
  std::unique_ptr<InputPhoneCall> peer_;
  int32_t duration_;
  std::unique_ptr<PhoneCallDiscardReason> reason_;
  int64_t connection_id_;
};

// phone.setCallRating#1c536a34 peer:InputPhoneCall rating:int comment:string = Updates;
class TL_phone_setCallRating : public TLObject {
public:
  enum {
    CLASS_ID = 0x1c536a34
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_setCallRating#0x1c536a34";
  }

  int32_t rating() const { return rating_; } 
  void set_rating(int32_t v) { rating_ = v; } 

  std::string* mutable_comment() { return &comment_; } 
  const std::string& comment() const { return comment_; } 
  void set_comment(const std::string& v) { comment_ = v; } 
  void set_comment(const char* v, size_t n) { comment_.assign(v, n); } 
  void set_comment(const char* v) { comment_ = v; } 

private:
  std::unique_ptr<InputPhoneCall> peer_;
  int32_t rating_;
  std::string comment_;
};

// messages.getPeerSettings#3672e09c peer:InputPeer = PeerSettings;
class TL_messages_getPeerSettings : public TLObject {
public:
  enum {
    CLASS_ID = 0x3672e09c
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getPeerSettings#0x3672e09c";
  }

private:
  std::unique_ptr<InputPeer> peer_;
};

// messages.getChats#3c6aa187 id:Vector<int> = messages.Chats;
class TL_messages_getChats : public TLObject {
public:
  enum {
    CLASS_ID = 0x3c6aa187
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getChats#0x3c6aa187";
  }

  size_t id_size() const { return id_.size(); } 
  const TLInt32Vector& id() const { return id_; } 
  int32_t id(int idx) const { return id_.vector()[idx]; } 
  void add_id(int32_t v) {id_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_id() { return &id_; } 

private:
  TLInt32Vector id_;
};

// messages.getCommonChats#d0a48c4 user_id:InputUser max_id:int limit:int = messages.Chats;
class TL_messages_getCommonChats : public TLObject {
public:
  enum {
    CLASS_ID = 0xd0a48c4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getCommonChats#0xd0a48c4";
  }

  int32_t max_id() const { return max_id_; } 
  void set_max_id(int32_t v) { max_id_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  std::unique_ptr<InputUser> user_id_;
  int32_t max_id_;
  int32_t limit_;
};

// messages.getAllChats#eba80ff0 except_ids:Vector<int> = messages.Chats;
class TL_messages_getAllChats : public TLObject {
public:
  enum {
    CLASS_ID = 0xeba80ff0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getAllChats#0xeba80ff0";
  }

  size_t except_ids_size() const { return except_ids_.size(); } 
  const TLInt32Vector& except_ids() const { return except_ids_; } 
  int32_t except_ids(int idx) const { return except_ids_.vector()[idx]; } 
  void add_except_ids(int32_t v) {except_ids_.mutable_vector()->push_back(v); } 
  TLInt32Vector* mutable_except_ids() { return &except_ids_; } 

private:
  TLInt32Vector except_ids_;
};

// channels.getChannels#a7f6bbb id:Vector<InputChannel> = messages.Chats;
class TL_channels_getChannels : public TLObject {
public:
  enum {
    CLASS_ID = 0xa7f6bbb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_getChannels#0xa7f6bbb";
  }

private:
  TLObjectVector<InputChannel> id_;
};

// channels.getAdminedPublicChannels#8d8d82d7 = messages.Chats;
class TL_channels_getAdminedPublicChannels : public TLObject {
public:
  enum {
    CLASS_ID = 0x8d8d82d7
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_getAdminedPublicChannels#0x8d8d82d7";
  }

private:
};

// messages.getFullChat#3b831c66 chat_id:int = messages.ChatFull;
class TL_messages_getFullChat : public TLObject {
public:
  enum {
    CLASS_ID = 0x3b831c66
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getFullChat#0x3b831c66";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
};

// channels.getFullChannel#8736a09 channel:InputChannel = messages.ChatFull;
class TL_channels_getFullChannel : public TLObject {
public:
  enum {
    CLASS_ID = 0x8736a09
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_getFullChannel#0x8736a09";
  }

private:
  std::unique_ptr<InputChannel> channel_;
};

// messages.getDhConfig#26cf8950 version:int random_length:int = messages.DhConfig;
class TL_messages_getDhConfig : public TLObject {
public:
  enum {
    CLASS_ID = 0x26cf8950
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getDhConfig#0x26cf8950";
  }

  int32_t version() const { return version_; } 
  void set_version(int32_t v) { version_ = v; } 

  int32_t random_length() const { return random_length_; } 
  void set_random_length(int32_t v) { random_length_ = v; } 

private:
  int32_t version_;
  int32_t random_length_;
};

// messages.requestEncryption#f64daf43 user_id:InputUser random_id:int g_a:bytes = EncryptedChat;
class TL_messages_requestEncryption : public TLObject {
public:
  enum {
    CLASS_ID = 0xf64daf43
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_requestEncryption#0xf64daf43";
  }

  int32_t random_id() const { return random_id_; } 
  void set_random_id(int32_t v) { random_id_ = v; } 

  std::string* mutable_g_a() { return &g_a_; } 
  const std::string& g_a() const { return g_a_; } 
  void set_g_a(const std::string& v) { g_a_ = v; } 
  void set_g_a(const char* v, size_t n) { g_a_.assign(v, n); } 
  void set_g_a(const char* v) { g_a_ = v; } 

private:
  std::unique_ptr<InputUser> user_id_;
  int32_t random_id_;
  std::string g_a_;
};

// messages.acceptEncryption#3dbc0415 peer:InputEncryptedChat g_b:bytes key_fingerprint:long = EncryptedChat;
class TL_messages_acceptEncryption : public TLObject {
public:
  enum {
    CLASS_ID = 0x3dbc0415
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_acceptEncryption#0x3dbc0415";
  }

  std::string* mutable_g_b() { return &g_b_; } 
  const std::string& g_b() const { return g_b_; } 
  void set_g_b(const std::string& v) { g_b_ = v; } 
  void set_g_b(const char* v, size_t n) { g_b_.assign(v, n); } 
  void set_g_b(const char* v) { g_b_ = v; } 

  int64_t key_fingerprint() const { return key_fingerprint_; } 
  void set_key_fingerprint(int64_t v) { key_fingerprint_ = v; } 

private:
  std::unique_ptr<InputEncryptedChat> peer_;
  std::string g_b_;
  int64_t key_fingerprint_;
};

// messages.sendEncrypted#a9776773 peer:InputEncryptedChat random_id:long data:bytes = messages.SentEncryptedMessage;
class TL_messages_sendEncrypted : public TLObject {
public:
  enum {
    CLASS_ID = 0xa9776773
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_sendEncrypted#0xa9776773";
  }

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

private:
  std::unique_ptr<InputEncryptedChat> peer_;
  int64_t random_id_;
  std::string data_;
};

// messages.sendEncryptedFile#9a901b66 peer:InputEncryptedChat random_id:long data:bytes file:InputEncryptedFile = messages.SentEncryptedMessage;
class TL_messages_sendEncryptedFile : public TLObject {
public:
  enum {
    CLASS_ID = 0x9a901b66
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_sendEncryptedFile#0x9a901b66";
  }

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

private:
  std::unique_ptr<InputEncryptedChat> peer_;
  int64_t random_id_;
  std::string data_;
  std::unique_ptr<InputEncryptedFile> file_;
};

// messages.sendEncryptedService#32d439a4 peer:InputEncryptedChat random_id:long data:bytes = messages.SentEncryptedMessage;
class TL_messages_sendEncryptedService : public TLObject {
public:
  enum {
    CLASS_ID = 0x32d439a4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_sendEncryptedService#0x32d439a4";
  }

  int64_t random_id() const { return random_id_; } 
  void set_random_id(int64_t v) { random_id_ = v; } 

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

private:
  std::unique_ptr<InputEncryptedChat> peer_;
  int64_t random_id_;
  std::string data_;
};

// messages.receivedQueue#55a5bb66 max_qts:int = Vector<long>;
class TL_messages_receivedQueue : public TLObject {
public:
  enum {
    CLASS_ID = 0x55a5bb66
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_receivedQueue#0x55a5bb66";
  }

  int32_t max_qts() const { return max_qts_; } 
  void set_max_qts(int32_t v) { max_qts_ = v; } 

private:
  int32_t max_qts_;
};

// photos.deletePhotos#87cf7f2f id:Vector<InputPhoto> = Vector<long>;
class TL_photos_deletePhotos : public TLObject {
public:
  enum {
    CLASS_ID = 0x87cf7f2f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photos_deletePhotos#0x87cf7f2f";
  }

private:
  TLObjectVector<InputPhoto> id_;
};

// messages.getAllStickers#1c9618b1 hash:int = messages.AllStickers;
class TL_messages_getAllStickers : public TLObject {
public:
  enum {
    CLASS_ID = 0x1c9618b1
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getAllStickers#0x1c9618b1";
  }

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t hash_;
};

// messages.getMaskStickers#65b8c79f hash:int = messages.AllStickers;
class TL_messages_getMaskStickers : public TLObject {
public:
  enum {
    CLASS_ID = 0x65b8c79f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getMaskStickers#0x65b8c79f";
  }

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t hash_;
};

// messages.getWebPagePreview#25223e24 message:string = MessageMedia;
class TL_messages_getWebPagePreview : public TLObject {
public:
  enum {
    CLASS_ID = 0x25223e24
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getWebPagePreview#0x25223e24";
  }

  std::string* mutable_message() { return &message_; } 
  const std::string& message() const { return message_; } 
  void set_message(const std::string& v) { message_ = v; } 
  void set_message(const char* v, size_t n) { message_.assign(v, n); } 
  void set_message(const char* v) { message_ = v; } 

private:
  std::string message_;
};

// messages.exportChatInvite#7d885289 chat_id:int = ExportedChatInvite;
class TL_messages_exportChatInvite : public TLObject {
public:
  enum {
    CLASS_ID = 0x7d885289
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_exportChatInvite#0x7d885289";
  }

  int32_t chat_id() const { return chat_id_; } 
  void set_chat_id(int32_t v) { chat_id_ = v; } 

private:
  int32_t chat_id_;
};

// channels.exportInvite#c7560885 channel:InputChannel = ExportedChatInvite;
class TL_channels_exportInvite : public TLObject {
public:
  enum {
    CLASS_ID = 0xc7560885
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_exportInvite#0xc7560885";
  }

private:
  std::unique_ptr<InputChannel> channel_;
};

// messages.checkChatInvite#3eadb1bb hash:string = ChatInvite;
class TL_messages_checkChatInvite : public TLObject {
public:
  enum {
    CLASS_ID = 0x3eadb1bb
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_checkChatInvite#0x3eadb1bb";
  }

  std::string* mutable_hash() { return &hash_; } 
  const std::string& hash() const { return hash_; } 
  void set_hash(const std::string& v) { hash_ = v; } 
  void set_hash(const char* v, size_t n) { hash_.assign(v, n); } 
  void set_hash(const char* v) { hash_ = v; } 

private:
  std::string hash_;
};

// messages.getStickerSet#2619a90e stickerset:InputStickerSet = messages.StickerSet;
class TL_messages_getStickerSet : public TLObject {
public:
  enum {
    CLASS_ID = 0x2619a90e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getStickerSet#0x2619a90e";
  }

private:
  std::unique_ptr<InputStickerSet> stickerset_;
};

// messages.installStickerSet#c78fe460 stickerset:InputStickerSet archived:Bool = messages.StickerSetInstallResult;
class TL_messages_installStickerSet : public TLObject {
public:
  enum {
    CLASS_ID = 0xc78fe460
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_installStickerSet#0xc78fe460";
  }

private:
  std::unique_ptr<InputStickerSet> stickerset_;
  std::unique_ptr<Bool> archived_;
};

// messages.getDocumentByHash#338e2464 sha256:bytes size:int mime_type:string = Document;
class TL_messages_getDocumentByHash : public TLObject {
public:
  enum {
    CLASS_ID = 0x338e2464
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getDocumentByHash#0x338e2464";
  }

  std::string* mutable_sha256() { return &sha256_; } 
  const std::string& sha256() const { return sha256_; } 
  void set_sha256(const std::string& v) { sha256_ = v; } 
  void set_sha256(const char* v, size_t n) { sha256_.assign(v, n); } 
  void set_sha256(const char* v) { sha256_ = v; } 

  int32_t size() const { return size_; } 
  void set_size(int32_t v) { size_ = v; } 

  std::string* mutable_mime_type() { return &mime_type_; } 
  const std::string& mime_type() const { return mime_type_; } 
  void set_mime_type(const std::string& v) { mime_type_ = v; } 
  void set_mime_type(const char* v, size_t n) { mime_type_.assign(v, n); } 
  void set_mime_type(const char* v) { mime_type_ = v; } 

private:
  std::string sha256_;
  int32_t size_;
  std::string mime_type_;
};

// messages.searchGifs#bf9a776b q:string offset:int = messages.FoundGifs;
class TL_messages_searchGifs : public TLObject {
public:
  enum {
    CLASS_ID = 0xbf9a776b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_searchGifs#0xbf9a776b";
  }

  std::string* mutable_q() { return &q_; } 
  const std::string& q() const { return q_; } 
  void set_q(const std::string& v) { q_ = v; } 
  void set_q(const char* v, size_t n) { q_.assign(v, n); } 
  void set_q(const char* v) { q_ = v; } 

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

private:
  std::string q_;
  int32_t offset_;
};

// messages.getSavedGifs#83bf3d52 hash:int = messages.SavedGifs;
class TL_messages_getSavedGifs : public TLObject {
public:
  enum {
    CLASS_ID = 0x83bf3d52
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getSavedGifs#0x83bf3d52";
  }

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t hash_;
};

// messages.getInlineBotResults#514e999d flags:# bot:InputUser peer:InputPeer geo_point:flags.0?InputGeoPoint query:string offset:string = messages.BotResults;
class TL_messages_getInlineBotResults : public TLObject {
public:
  enum {
    CLASS_ID = 0x514e999d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getInlineBotResults#0x514e999d";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  std::string* mutable_query() { return &query_; } 
  const std::string& query() const { return query_; } 
  void set_query(const std::string& v) { query_ = v; } 
  void set_query(const char* v, size_t n) { query_.assign(v, n); } 
  void set_query(const char* v) { query_ = v; } 

  std::string* mutable_offset() { return &offset_; } 
  const std::string& offset() const { return offset_; } 
  void set_offset(const std::string& v) { offset_ = v; } 
  void set_offset(const char* v, size_t n) { offset_.assign(v, n); } 
  void set_offset(const char* v) { offset_ = v; } 

private:
  int32_t flags_;
  std::unique_ptr<InputUser> bot_;
  std::unique_ptr<InputPeer> peer_;
  std::unique_ptr<InputGeoPoint> geo_point_;
  std::string query_;
  std::string offset_;
};

// messages.getMessageEditData#fda68d36 peer:InputPeer id:int = messages.MessageEditData;
class TL_messages_getMessageEditData : public TLObject {
public:
  enum {
    CLASS_ID = 0xfda68d36
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getMessageEditData#0xfda68d36";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  std::unique_ptr<InputPeer> peer_;
  int32_t id_;
};

// messages.getBotCallbackAnswer#810a9fec flags:# game:flags.1?true peer:InputPeer msg_id:int data:flags.0?bytes = messages.BotCallbackAnswer;
class TL_messages_getBotCallbackAnswer : public TLObject {
public:
  enum {
    CLASS_ID = 0x810a9fec
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getBotCallbackAnswer#0x810a9fec";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t msg_id() const { return msg_id_; } 
  void set_msg_id(int32_t v) { msg_id_ = v; } 

  std::string* mutable_data() { return &data_; } 
  const std::string& data() const { return data_; } 
  void set_data(const std::string& v) { data_ = v; } 
  void set_data(const char* v, size_t n) { data_.assign(v, n); } 
  void set_data(const char* v) { data_ = v; } 

private:
  int32_t flags_;
  bool game_;
  std::unique_ptr<InputPeer> peer_;
  int32_t msg_id_;
  std::string data_;
};

// messages.getPeerDialogs#2d9776b9 peers:Vector<InputPeer> = messages.PeerDialogs;
class TL_messages_getPeerDialogs : public TLObject {
public:
  enum {
    CLASS_ID = 0x2d9776b9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getPeerDialogs#0x2d9776b9";
  }

private:
  TLObjectVector<InputPeer> peers_;
};

// messages.getPinnedDialogs#e254d64e = messages.PeerDialogs;
class TL_messages_getPinnedDialogs : public TLObject {
public:
  enum {
    CLASS_ID = 0xe254d64e
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getPinnedDialogs#0xe254d64e";
  }

private:
};

// messages.getFeaturedStickers#2dacca4f hash:int = messages.FeaturedStickers;
class TL_messages_getFeaturedStickers : public TLObject {
public:
  enum {
    CLASS_ID = 0x2dacca4f
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getFeaturedStickers#0x2dacca4f";
  }

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t hash_;
};

// messages.getRecentStickers#5ea192c9 flags:# attached:flags.0?true hash:int = messages.RecentStickers;
class TL_messages_getRecentStickers : public TLObject {
public:
  enum {
    CLASS_ID = 0x5ea192c9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getRecentStickers#0x5ea192c9";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  int32_t flags_;
  bool attached_;
  int32_t hash_;
};

// messages.getArchivedStickers#57f17692 flags:# masks:flags.0?true offset_id:long limit:int = messages.ArchivedStickers;
class TL_messages_getArchivedStickers : public TLObject {
public:
  enum {
    CLASS_ID = 0x57f17692
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getArchivedStickers#0x57f17692";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int64_t offset_id() const { return offset_id_; } 
  void set_offset_id(int64_t v) { offset_id_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  int32_t flags_;
  bool masks_;
  int64_t offset_id_;
  int32_t limit_;
};

// messages.getAttachedStickers#cc5b67cc media:InputStickeredMedia = Vector<StickerSetCovered>;
class TL_messages_getAttachedStickers : public TLObject {
public:
  enum {
    CLASS_ID = 0xcc5b67cc
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getAttachedStickers#0xcc5b67cc";
  }

private:
  std::unique_ptr<InputStickeredMedia> media_;
};

// messages.getGameHighScores#e822649d peer:InputPeer id:int user_id:InputUser = messages.HighScores;
class TL_messages_getGameHighScores : public TLObject {
public:
  enum {
    CLASS_ID = 0xe822649d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getGameHighScores#0xe822649d";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  std::unique_ptr<InputPeer> peer_;
  int32_t id_;
  std::unique_ptr<InputUser> user_id_;
};

// messages.getInlineGameHighScores#f635e1b id:InputBotInlineMessageID user_id:InputUser = messages.HighScores;
class TL_messages_getInlineGameHighScores : public TLObject {
public:
  enum {
    CLASS_ID = 0xf635e1b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getInlineGameHighScores#0xf635e1b";
  }

private:
  std::unique_ptr<InputBotInlineMessageID> id_;
  std::unique_ptr<InputUser> user_id_;
};

// messages.getWebPage#32ca8f91 url:string hash:int = WebPage;
class TL_messages_getWebPage : public TLObject {
public:
  enum {
    CLASS_ID = 0x32ca8f91
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "messages_getWebPage#0x32ca8f91";
  }

  std::string* mutable_url() { return &url_; } 
  const std::string& url() const { return url_; } 
  void set_url(const std::string& v) { url_ = v; } 
  void set_url(const char* v, size_t n) { url_.assign(v, n); } 
  void set_url(const char* v) { url_ = v; } 

  int32_t hash() const { return hash_; } 
  void set_hash(int32_t v) { hash_ = v; } 

private:
  std::string url_;
  int32_t hash_;
};

// updates.getState#edd4882a = updates.State;
class TL_updates_getState : public TLObject {
public:
  enum {
    CLASS_ID = 0xedd4882a
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_getState#0xedd4882a";
  }

private:
};

// updates.getDifference#25939651 flags:# pts:int pts_total_limit:flags.0?int date:int qts:int = updates.Difference;
class TL_updates_getDifference : public TLObject {
public:
  enum {
    CLASS_ID = 0x25939651
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_getDifference#0x25939651";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t pts_total_limit() const { return pts_total_limit_; } 
  void set_pts_total_limit(int32_t v) { pts_total_limit_ = v; } 

  int32_t date() const { return date_; } 
  void set_date(int32_t v) { date_ = v; } 

  int32_t qts() const { return qts_; } 
  void set_qts(int32_t v) { qts_ = v; } 

private:
  int32_t flags_;
  int32_t pts_;
  int32_t pts_total_limit_;
  int32_t date_;
  int32_t qts_;
};

// updates.getChannelDifference#3173d78 flags:# force:flags.0?true channel:InputChannel filter:ChannelMessagesFilter pts:int limit:int = updates.ChannelDifference;
class TL_updates_getChannelDifference : public TLObject {
public:
  enum {
    CLASS_ID = 0x3173d78
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "updates_getChannelDifference#0x3173d78";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t pts() const { return pts_; } 
  void set_pts(int32_t v) { pts_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  int32_t flags_;
  bool force_;
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<ChannelMessagesFilter> filter_;
  int32_t pts_;
  int32_t limit_;
};

// photos.updateProfilePhoto#f0bb5152 id:InputPhoto = UserProfilePhoto;
class TL_photos_updateProfilePhoto : public TLObject {
public:
  enum {
    CLASS_ID = 0xf0bb5152
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photos_updateProfilePhoto#0xf0bb5152";
  }

private:
  std::unique_ptr<InputPhoto> id_;
};

// photos.uploadProfilePhoto#4f32c098 file:InputFile = photos.Photo;
class TL_photos_uploadProfilePhoto : public TLObject {
public:
  enum {
    CLASS_ID = 0x4f32c098
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photos_uploadProfilePhoto#0x4f32c098";
  }

private:
  std::unique_ptr<InputFile> file_;
};

// photos.getUserPhotos#91cd32a8 user_id:InputUser offset:int max_id:long limit:int = photos.Photos;
class TL_photos_getUserPhotos : public TLObject {
public:
  enum {
    CLASS_ID = 0x91cd32a8
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "photos_getUserPhotos#0x91cd32a8";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int64_t max_id() const { return max_id_; } 
  void set_max_id(int64_t v) { max_id_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  std::unique_ptr<InputUser> user_id_;
  int32_t offset_;
  int64_t max_id_;
  int32_t limit_;
};

// upload.getFile#e3a6cfb5 location:InputFileLocation offset:int limit:int = upload.File;
class TL_upload_getFile : public TLObject {
public:
  enum {
    CLASS_ID = 0xe3a6cfb5
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_getFile#0xe3a6cfb5";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  std::unique_ptr<InputFileLocation> location_;
  int32_t offset_;
  int32_t limit_;
};

// upload.getWebFile#24e6818d location:InputWebFileLocation offset:int limit:int = upload.WebFile;
class TL_upload_getWebFile : public TLObject {
public:
  enum {
    CLASS_ID = 0x24e6818d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_getWebFile#0x24e6818d";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  std::unique_ptr<InputWebFileLocation> location_;
  int32_t offset_;
  int32_t limit_;
};

// upload.getCdnFile#2000bcc3 file_token:bytes offset:int limit:int = upload.CdnFile;
class TL_upload_getCdnFile : public TLObject {
public:
  enum {
    CLASS_ID = 0x2000bcc3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "upload_getCdnFile#0x2000bcc3";
  }

  std::string* mutable_file_token() { return &file_token_; } 
  const std::string& file_token() const { return file_token_; } 
  void set_file_token(const std::string& v) { file_token_ = v; } 
  void set_file_token(const char* v, size_t n) { file_token_.assign(v, n); } 
  void set_file_token(const char* v) { file_token_ = v; } 

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  std::string file_token_;
  int32_t offset_;
  int32_t limit_;
};

// help.getConfig#c4f9186b = Config;
class TL_help_getConfig : public TLObject {
public:
  enum {
    CLASS_ID = 0xc4f9186b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_getConfig#0xc4f9186b";
  }

private:
};

// help.getNearestDc#1fb33026 = NearestDc;
class TL_help_getNearestDc : public TLObject {
public:
  enum {
    CLASS_ID = 0x1fb33026
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_getNearestDc#0x1fb33026";
  }

private:
};

// help.getAppUpdate#ae2de196 = help.AppUpdate;
class TL_help_getAppUpdate : public TLObject {
public:
  enum {
    CLASS_ID = 0xae2de196
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_getAppUpdate#0xae2de196";
  }

private:
};

// help.getInviteText#4d392343 = help.InviteText;
class TL_help_getInviteText : public TLObject {
public:
  enum {
    CLASS_ID = 0x4d392343
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_getInviteText#0x4d392343";
  }

private:
};

// help.getSupport#9cdf08cd = help.Support;
class TL_help_getSupport : public TLObject {
public:
  enum {
    CLASS_ID = 0x9cdf08cd
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_getSupport#0x9cdf08cd";
  }

private:
};

// help.getTermsOfService#350170f3 = help.TermsOfService;
class TL_help_getTermsOfService : public TLObject {
public:
  enum {
    CLASS_ID = 0x350170f3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_getTermsOfService#0x350170f3";
  }

private:
};

// help.getCdnConfig#52029342 = CdnConfig;
class TL_help_getCdnConfig : public TLObject {
public:
  enum {
    CLASS_ID = 0x52029342
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "help_getCdnConfig#0x52029342";
  }

private:
};

// channels.getParticipants#24d98f92 channel:InputChannel filter:ChannelParticipantsFilter offset:int limit:int = channels.ChannelParticipants;
class TL_channels_getParticipants : public TLObject {
public:
  enum {
    CLASS_ID = 0x24d98f92
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_getParticipants#0x24d98f92";
  }

  int32_t offset() const { return offset_; } 
  void set_offset(int32_t v) { offset_ = v; } 

  int32_t limit() const { return limit_; } 
  void set_limit(int32_t v) { limit_ = v; } 

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<ChannelParticipantsFilter> filter_;
  int32_t offset_;
  int32_t limit_;
};

// channels.getParticipant#546dd7a6 channel:InputChannel user_id:InputUser = channels.ChannelParticipant;
class TL_channels_getParticipant : public TLObject {
public:
  enum {
    CLASS_ID = 0x546dd7a6
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_getParticipant#0x546dd7a6";
  }

private:
  std::unique_ptr<InputChannel> channel_;
  std::unique_ptr<InputUser> user_id_;
};

// channels.exportMessageLink#c846d22d channel:InputChannel id:int = ExportedMessageLink;
class TL_channels_exportMessageLink : public TLObject {
public:
  enum {
    CLASS_ID = 0xc846d22d
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "channels_exportMessageLink#0xc846d22d";
  }

  int32_t id() const { return id_; } 
  void set_id(int32_t v) { id_ = v; } 

private:
  std::unique_ptr<InputChannel> channel_;
  int32_t id_;
};

// bots.sendCustomRequest#aa2769ed custom_method:string params:DataJSON = DataJSON;
class TL_bots_sendCustomRequest : public TLObject {
public:
  enum {
    CLASS_ID = 0xaa2769ed
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "bots_sendCustomRequest#0xaa2769ed";
  }

  std::string* mutable_custom_method() { return &custom_method_; } 
  const std::string& custom_method() const { return custom_method_; } 
  void set_custom_method(const std::string& v) { custom_method_ = v; } 
  void set_custom_method(const char* v, size_t n) { custom_method_.assign(v, n); } 
  void set_custom_method(const char* v) { custom_method_ = v; } 

private:
  std::string custom_method_;
  std::unique_ptr<DataJSON> params_;
};

// phone.getCallConfig#55451fa9 = DataJSON;
class TL_phone_getCallConfig : public TLObject {
public:
  enum {
    CLASS_ID = 0x55451fa9
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_getCallConfig#0x55451fa9";
  }

private:
};

// payments.getPaymentForm#99f09745 msg_id:int = payments.PaymentForm;
class TL_payments_getPaymentForm : public TLObject {
public:
  enum {
    CLASS_ID = 0x99f09745
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_getPaymentForm#0x99f09745";
  }

  int32_t msg_id() const { return msg_id_; } 
  void set_msg_id(int32_t v) { msg_id_ = v; } 

private:
  int32_t msg_id_;
};

// payments.getPaymentReceipt#a092a980 msg_id:int = payments.PaymentReceipt;
class TL_payments_getPaymentReceipt : public TLObject {
public:
  enum {
    CLASS_ID = 0xa092a980
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_getPaymentReceipt#0xa092a980";
  }

  int32_t msg_id() const { return msg_id_; } 
  void set_msg_id(int32_t v) { msg_id_ = v; } 

private:
  int32_t msg_id_;
};

// payments.validateRequestedInfo#770a8e74 flags:# save:flags.0?true msg_id:int info:PaymentRequestedInfo = payments.ValidatedRequestedInfo;
class TL_payments_validateRequestedInfo : public TLObject {
public:
  enum {
    CLASS_ID = 0x770a8e74
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_validateRequestedInfo#0x770a8e74";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t msg_id() const { return msg_id_; } 
  void set_msg_id(int32_t v) { msg_id_ = v; } 

private:
  int32_t flags_;
  bool save_;
  int32_t msg_id_;
  std::unique_ptr<PaymentRequestedInfo> info_;
};

// payments.sendPaymentForm#2b8879b3 flags:# msg_id:int requested_info_id:flags.0?string shipping_option_id:flags.1?string credentials:InputPaymentCredentials = payments.PaymentResult;
class TL_payments_sendPaymentForm : public TLObject {
public:
  enum {
    CLASS_ID = 0x2b8879b3
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_sendPaymentForm#0x2b8879b3";
  }

  int32_t flags() const { return flags_; } 
  void set_flags(int32_t v) { flags_ = v; } 

  int32_t msg_id() const { return msg_id_; } 
  void set_msg_id(int32_t v) { msg_id_ = v; } 

  std::string* mutable_requested_info_id() { return &requested_info_id_; } 
  const std::string& requested_info_id() const { return requested_info_id_; } 
  void set_requested_info_id(const std::string& v) { requested_info_id_ = v; } 
  void set_requested_info_id(const char* v, size_t n) { requested_info_id_.assign(v, n); } 
  void set_requested_info_id(const char* v) { requested_info_id_ = v; } 

  std::string* mutable_shipping_option_id() { return &shipping_option_id_; } 
  const std::string& shipping_option_id() const { return shipping_option_id_; } 
  void set_shipping_option_id(const std::string& v) { shipping_option_id_ = v; } 
  void set_shipping_option_id(const char* v, size_t n) { shipping_option_id_.assign(v, n); } 
  void set_shipping_option_id(const char* v) { shipping_option_id_ = v; } 

private:
  int32_t flags_;
  int32_t msg_id_;
  std::string requested_info_id_;
  std::string shipping_option_id_;
  std::unique_ptr<InputPaymentCredentials> credentials_;
};

// payments.getSavedInfo#227d824b = payments.SavedInfo;
class TL_payments_getSavedInfo : public TLObject {
public:
  enum {
    CLASS_ID = 0x227d824b
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "payments_getSavedInfo#0x227d824b";
  }

private:
};

// phone.requestCall#5b95b3d4 user_id:InputUser random_id:int g_a_hash:bytes protocol:PhoneCallProtocol = phone.PhoneCall;
class TL_phone_requestCall : public TLObject {
public:
  enum {
    CLASS_ID = 0x5b95b3d4
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_requestCall#0x5b95b3d4";
  }

  int32_t random_id() const { return random_id_; } 
  void set_random_id(int32_t v) { random_id_ = v; } 

  std::string* mutable_g_a_hash() { return &g_a_hash_; } 
  const std::string& g_a_hash() const { return g_a_hash_; } 
  void set_g_a_hash(const std::string& v) { g_a_hash_ = v; } 
  void set_g_a_hash(const char* v, size_t n) { g_a_hash_.assign(v, n); } 
  void set_g_a_hash(const char* v) { g_a_hash_ = v; } 

private:
  std::unique_ptr<InputUser> user_id_;
  int32_t random_id_;
  std::string g_a_hash_;
  std::unique_ptr<PhoneCallProtocol> protocol_;
};

// phone.acceptCall#3bd2b4a0 peer:InputPhoneCall g_b:bytes protocol:PhoneCallProtocol = phone.PhoneCall;
class TL_phone_acceptCall : public TLObject {
public:
  enum {
    CLASS_ID = 0x3bd2b4a0
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_acceptCall#0x3bd2b4a0";
  }

  std::string* mutable_g_b() { return &g_b_; } 
  const std::string& g_b() const { return g_b_; } 
  void set_g_b(const std::string& v) { g_b_ = v; } 
  void set_g_b(const char* v, size_t n) { g_b_.assign(v, n); } 
  void set_g_b(const char* v) { g_b_ = v; } 

private:
  std::unique_ptr<InputPhoneCall> peer_;
  std::string g_b_;
  std::unique_ptr<PhoneCallProtocol> protocol_;
};

// phone.confirmCall#2efe1722 peer:InputPhoneCall g_a:bytes key_fingerprint:long protocol:PhoneCallProtocol = phone.PhoneCall;
class TL_phone_confirmCall : public TLObject {
public:
  enum {
    CLASS_ID = 0x2efe1722
  };

  uint32_t GetClassID() const override {
    return CLASS_ID;
  }

  bool Decode(IOBufReader& iobr) override;
  bool Encode(IOBufWriter& iobw) const override;

  std::string ToString() const override {
    return "phone_confirmCall#0x2efe1722";
  }

  std::string* mutable_g_a() { return &g_a_; } 
  const std::string& g_a() const { return g_a_; } 
  void set_g_a(const std::string& v) { g_a_ = v; } 
  void set_g_a(const char* v, size_t n) { g_a_.assign(v, n); } 
  void set_g_a(const char* v) { g_a_ = v; } 

  int64_t key_fingerprint() const { return key_fingerprint_; } 
  void set_key_fingerprint(int64_t v) { key_fingerprint_ = v; } 

private:
  std::unique_ptr<InputPhoneCall> peer_;
  std::string g_a_;
  int64_t key_fingerprint_;
  std::unique_ptr<PhoneCallProtocol> protocol_;
};



#endif
