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

#include "proto/mtproto/core/tl_codec_util.h"

#include "nebula/base/stl_util.h"

#include <glog/logging.h>

namespace mtproto {
  
bool ReadString(IOBufReader& iobr, TLString* data) {
  bool rv = false;
  uint32_t sl = 1;
  // uint8_t
  auto buf_length = iobr.totalLength();
  
  do {
    // 读长度
    size_t position = 0;
    if (position+1 > buf_length) {
      LOG(WARNING) << "ReadString - error";
      break;
    }
    
    uint32_t l = iobr.read<uint8_t>();
    position += 1;
    
    if (l >= 254) {
      if (position + 3 > buf_length) {
        LOG(WARNING) << "ReadString - error";
        break;
      }
      
      l = iobr.read<uint8_t>() | (iobr.read<uint8_t>() << 8) | (iobr.read<uint8_t>() << 16);
      position += 3;
      sl = 4;
    }
    
    uint32_t addition = (l + sl) % 4;
    if (addition != 0) {
      addition = 4 - addition;
    }
    
    if (position + l + addition > buf_length) {
      LOG(WARNING) << "ReadString - error";
      break;
    }
    
    data->resize(l);
    iobr.pull(&*data->begin(), l);
    iobr.skip(addition);
    
    rv = true;

  } while (0);
  
  return rv;
}

bool WriteString(IOBufWriter& iobw, const TLString& data) {
  size_t data_length = data.size();
  
  if (data.size() <= 253) {
    iobw.write<uint8_t>((uint8_t)data_length);
  } else {
    iobw.write<uint8_t>((uint8_t)254);
    iobw.write<uint8_t>((uint8_t)data_length);
    iobw.write<uint8_t>((uint8_t)(data_length >> 8));
    iobw.write<uint8_t>((uint8_t)(data_length >> 16));
  }

  iobw.push(reinterpret_cast<const uint8_t*>(data.data()), data_length);

  uint32_t addition = (data_length + (data_length <= 253 ? 1 : 4)) % 4;
  if (addition != 0) {
    addition = 4 - addition;
  }
  
  for (uint32_t a = 0; a < addition; a++) {
    iobw.write<uint8_t>((uint8_t)((uint8_t)0));
  }
  
  return true;
}

template<> size_t CalcObjSize(const TLString& t) {
  size_t obj_size = 0;
  size_t data_length = t.size();
  if (data_length <= 253) {
    obj_size = 1;
  } else {
    obj_size = 4;
  }
  
  size_t addition = (data_length + (data_length <= 253 ? 1 : 4)) % 4;
  if (addition != 0) {
    addition = 4 - addition;
  }
  obj_size += data_length + addition;

  return obj_size;
}
  
}


