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

#ifndef NET_TELEGRAM_TL_OBJECT_HANDLER_H_
#define NET_TELEGRAM_TL_OBJECT_HANDLER_H_

struct AuthKey {
  AES_KEY encryptKey;
  uint8_t encryptIv[16];
  uint32_t encryptNum;
  uint8_t encryptCount[16];
  
  AES_KEY decryptKey;
  uint8_t decryptIv[16];
  uint32_t decryptNum;
  uint8_t decryptCount[16];
};

#if 0

void Connection::sendData(NativeByteBuffer *buff, bool reportAck) {
  if (buff == nullptr) {
    return;
  }
  buff->rewind();
  if (connectionState == TcpConnectionStageIdle || connectionState == TcpConnectionStageReconnecting || connectionState == TcpConnectionStageSuspended) {
    connect();
  }
  
  if (isDisconnected()) {
    buff->reuse();
    DEBUG_D("connection(%p, dc%u, type %d) disconnected, don't send data", this, currentDatacenter->getDatacenterId(), connectionType);
    return;
  }
  
  uint32_t bufferLen = 0;
  uint32_t packetLength = buff->limit() / 4;
  
  if (packetLength < 0x7f) {
    bufferLen++;
  } else {
    bufferLen += 4;
  }
  if (!firstPacketSent) {
    bufferLen += 64;
  }
  
  NativeByteBuffer *buffer = BuffersStorage::getInstance().getFreeBuffer(bufferLen);
  uint8_t *bytes = buffer->bytes();
  
  if (!firstPacketSent) {
    buffer->position(64);
    static uint8_t temp[64];
    while (true) {
      RAND_bytes(bytes, 64);
      uint32_t val = (bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | (bytes[0]);
      uint32_t val2 = (bytes[7] << 24) | (bytes[6] << 16) | (bytes[5] << 8) | (bytes[4]);
      if (bytes[0] != 0xef && val != 0x44414548 && val != 0x54534f50 && val != 0x20544547 && val != 0x4954504f && val != 0xeeeeeeee && val2 != 0x00000000) {
        bytes[56] = bytes[57] = bytes[58] = bytes[59] = 0xef;
        break;
      }
    }
    for (int a = 0; a < 48; a++) {
      temp[a] = bytes[55 - a];
    }
    
    encryptNum = decryptNum = 0;
    memset(encryptCount, 0, 16);
    memset(decryptCount, 0, 16);
    
    if (AES_set_encrypt_key(bytes + 8, 256, &encryptKey) < 0) {
      DEBUG_E("unable to set encryptKey");
      exit(1);
    }
    memcpy(encryptIv, bytes + 40, 16);
    
    if (AES_set_encrypt_key(temp, 256, &decryptKey) < 0) {
      DEBUG_E("unable to set decryptKey");
      exit(1);
    }
    memcpy(decryptIv, temp + 32, 16);
    
    AES_ctr128_encrypt(bytes, temp, 64, &encryptKey, encryptIv, encryptCount, &encryptNum);
    memcpy(bytes + 56, temp + 56, 8);
    
    firstPacketSent = true;
  }
  if (packetLength < 0x7f) {
    if (reportAck) {
      packetLength |= (1 << 7);
    }
    buffer->writeByte((uint8_t) packetLength);
    bytes += (buffer->limit() - 1);
    AES_ctr128_encrypt(bytes, bytes, 1, &encryptKey, encryptIv, encryptCount, &encryptNum);
  } else {
    packetLength = (packetLength << 8) + 0x7f;
    if (reportAck) {
      packetLength |= (1 << 7);
    }
    buffer->writeInt32(packetLength);
    bytes += (buffer->limit() - 4);
    AES_ctr128_encrypt(bytes, bytes, 4, &encryptKey, encryptIv, encryptCount, &encryptNum);
  }
  
  buffer->rewind();
  writeBuffer(buffer);
  buff->rewind();
  AES_ctr128_encrypt(buff->bytes(), buff->bytes(), buff->limit(), &encryptKey, encryptIv, encryptCount, &encryptNum);
  writeBuffer(buff);
}

#endif

