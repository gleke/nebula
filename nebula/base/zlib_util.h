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

#ifndef NEBULA_BASE_ZLIB_UTIL_H_
#define NEBULA_BASE_ZLIB_UTIL_H_

inline NativeByteBuffer *decompressGZip(NativeByteBuffer *data) {
  int retCode;
  z_stream stream;
  
  memset(&stream, 0, sizeof(z_stream));
  stream.avail_in = data->limit();
  stream.next_in = data->bytes();
  
  retCode = inflateInit2(&stream, 15 + 32);
  if (retCode != Z_OK) {
    DEBUG_E("can't decompress data");
    exit(1);
  }
  NativeByteBuffer *result = BuffersStorage::getInstance().getFreeBuffer(data->limit() * 4);
  stream.avail_out = result->capacity();
  stream.next_out = result->bytes();
  while (1) {
    retCode = inflate(&stream, Z_NO_FLUSH);
    if (retCode == Z_STREAM_END) {
      break;
    }
    if (retCode == Z_OK) {
      NativeByteBuffer *newResult = BuffersStorage::getInstance().getFreeBuffer(result->capacity() * 2);
      memcpy(newResult->bytes(), result->bytes(), result->capacity());
      stream.avail_out = newResult->capacity() - result->capacity();
      stream.next_out = newResult->bytes() + result->capacity();
      result->reuse();
      result = newResult;
    } else {
      DEBUG_E("can't decompress data");
      exit(1);
    }
  }
  result->limit((uint32_t) stream.total_out);
  inflateEnd(&stream);
  return result;
}

inline NativeByteBuffer *compressGZip(NativeByteBuffer *buffer) {
  if (buffer == nullptr || buffer->limit() == 0) {
    return nullptr;
  }
  z_stream stream;
  int retCode;
  
  memset(&stream, 0, sizeof(z_stream));
  stream.avail_in = buffer->limit();
  stream.next_in = buffer->bytes();
  
  retCode = deflateInit2(&stream, Z_BEST_COMPRESSION, Z_DEFLATED, 15 + 16, 8, Z_DEFAULT_STRATEGY);
  if (retCode != Z_OK) {
    DEBUG_E("%s: deflateInit2() failed with error %i", __PRETTY_FUNCTION__, retCode);
    return nullptr;
  }
  
  NativeByteBuffer *result = BuffersStorage::getInstance().getFreeBuffer(buffer->limit());
  stream.avail_out = result->limit();
  stream.next_out = result->bytes();
  retCode = deflate(&stream, Z_FINISH);
  if ((retCode != Z_OK) && (retCode != Z_STREAM_END)) {
    DEBUG_E("%s: deflate() failed with error %i", __PRETTY_FUNCTION__, retCode);
    deflateEnd(&stream);
    result->reuse();
    return nullptr;
  }
  if (retCode != Z_STREAM_END || stream.total_out >= buffer->limit() - 4) {
    deflateEnd(&stream);
    result->reuse();
    return nullptr;
  }
  result->limit((uint32_t) stream.total_out);
  deflateEnd(&stream);
  return result;
}

#endif
