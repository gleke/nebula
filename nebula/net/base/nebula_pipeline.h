/*
 *  Copyright (c) 2016, https://github.com/zhatalk
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

#ifndef NEBULA_NET_BASE_NEBULA_PIPELINE_H_
#define NEBULA_NET_BASE_NEBULA_PIPELINE_H_

#include "nebula/base/exception.h"

#include <wangle/channel/Pipeline.h>

namespace nebula {
  
using PipelineBasePtr = std::shared_ptr<wangle::PipelineBase>;
using EchoPipeline = wangle::Pipeline<folly::IOBufQueue&, std::string>;
using DefaultPipeline = wangle::Pipeline<folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>>;
using ZProtoPipeline = wangle::Pipeline<folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>>;
using TelegramPipeline = wangle::Pipeline<folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>>;
using MTProtoPipeline = wangle::Pipeline<folly::IOBufQueue&, std::unique_ptr<folly::IOBuf>>;

// hack...
template <class W>
inline folly::Future<folly::Unit> write(wangle::PipelineBase* pipeline, W msg) {
  // hack，黑科技慎用！！！！
  auto pl = dynamic_cast<wangle::Pipeline<folly::IOBufQueue&, W>*>(pipeline);
  if (!pl) {
    THROW_EXCEPTION(RuntimeException, "write(): no cast to wangle::Pipeline<folly::IOBufQueue&, W>");
  }
  
  return pl->write(std::forward<W>(msg));
}

// 客户端连接建立成功后未设置Addr，手动设置
void SetPipelineAddr(wangle::PipelineBase* pipeline, folly::AsyncTransportWrapper* sock);

}

#endif
