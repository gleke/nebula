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

#include "nebula/base/io_buf_util.h"

#include <folly/Range.h>

namespace nebula {
namespace io_buf_util {
  
void TrimStart(folly::IOBuf* io_buf, size_t amount) {
  // TODO(@wubenqi): Check(io_buf);
  
  if (io_buf->computeChainDataLength() < amount) {
    LOG(ERROR) << "TrimStart - Attempt to trim more bytes than are present in IOBuf";
    throw std::underflow_error(
                               "Attempt to trim more bytes than are present in IOBuf");
  }
  
  // folly::IOBuf* head = io_buf;
  while (amount > 0) {
    if (io_buf->length() > amount) {
      io_buf->trimStart(amount);
      break;
    }
    amount -= io_buf->length();
    io_buf->trimStart(io_buf->length());
    io_buf->pop();
  }
}
  
void TrimEnd(folly::IOBuf* io_buf, size_t amount) {
  // TODO(@wubenqi): Check(io_buf);
  if (io_buf->computeChainDataLength() < amount) {
    LOG(ERROR) << "TrimEnd - Attempt to trim more bytes than are present in IOBuf";
    throw std::underflow_error(
      "Attempt to trim more bytes than are present in IOBuf");
  }

  while (amount > 0) {
    if (io_buf->prev()->length() > amount) {
      io_buf->prev()->trimEnd(amount);
      break;
    }
    amount -= io_buf->prev()->length();
    
    if (io_buf->isChained()) {
      io_buf->prev()->unlink();
    }
  }
}

} // IOBufUtil
} // nebula


folly::StringPiece getRange(const std::unique_ptr<folly::IOBuf>& buf) {
  if (!buf) {
    return {};
  }
  return getRange(*buf);
}

folly::StringPiece getRange(const folly::IOBuf& buf) {
  assert(!buf.isChained());
  return {reinterpret_cast<const char*>(buf.data()), buf.length()};
}

folly::StringPiece coalesceAndGetRange(std::unique_ptr<folly::IOBuf>& buf) {
  if (!buf) {
    return {};
  }
  
  return coalesceAndGetRange(*buf);
}

folly::StringPiece coalesceAndGetRange(folly::IOBuf& buf) {
  buf.coalesce();
  return getRange(buf);
}

folly::StringPiece coalesceAndGetRange(folly::Optional<folly::IOBuf>& buf) {
  return buf.hasValue() ? coalesceAndGetRange(*buf) : folly::StringPiece();
}

bool hasSameMemoryRegion(const folly::IOBuf& buf, folly::StringPiece range) {
  return !buf.isChained() &&
  (buf.length() == 0 ||
   (range.begin() == reinterpret_cast<const char*>(buf.data()) &&
    range.size() == buf.length()));
}

bool hasSameMemoryRegion(const folly::IOBuf& a, const folly::IOBuf& b) {
  return !a.isChained() && !b.isChained() &&
  ((a.length() == 0 && b.length() == 0) ||
   (a.data() == b.data() && a.length() == b.length()));
}

void copyInto(char* raw, const folly::IOBuf& buf) {
  auto cur = &buf;
  auto next = cur->next();
  do {
    ::memcpy(raw, cur->data(), cur->length());
    raw += cur->length();
    cur = next;
    next = next->next();
  } while (cur != &buf);
}

namespace {
/**
 * Creating IOBuf from an iovec array.
 */
folly::IOBuf
coalesceSlow(const struct iovec* iov, size_t iovcnt, size_t destCapacity) {
  folly::IOBuf buffer(folly::IOBuf::CREATE, destCapacity);
  for (size_t i = 0; i < iovcnt; ++i) {
    std::memcpy(buffer.writableTail(), iov[i].iov_base, iov[i].iov_len);
    buffer.append(iov[i].iov_len);
  }
  assert(buffer.length() <= destCapacity);
  return buffer;
}
} // anonymous namespace

folly::IOBuf
coalesceIovecs(const struct iovec* iov, size_t iovcnt, size_t destCapacity) {
  if (iovcnt == 1) {
    return folly::IOBuf(
                        folly::IOBuf::WRAP_BUFFER, iov[0].iov_base, iov[0].iov_len);
  }
  return coalesceSlow(iov, iovcnt, destCapacity);
}

