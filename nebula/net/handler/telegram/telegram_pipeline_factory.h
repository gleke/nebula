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

#ifndef NET_TELEGRAM_TELEGRAM_PIPELINE_FACTORY_H_
#define NET_TELEGRAM_TELEGRAM_PIPELINE_FACTORY_H_

#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/handler/telegram/mtproto_object_handler.h"

class TelegramPipelineFactory : public wangle::PipelineFactory<nebula::TelegramPipeline> {
public:
  TelegramPipelineFactory(nebula::ServiceBase* service)
    : service_(service) {}
  
  nebula::TelegramPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
  
private:
  nebula::ServiceBase* service_{nullptr};
};

class TelegramClientPipelineFactory : public wangle::PipelineFactory<nebula::TelegramPipeline> {
public:
  TelegramClientPipelineFactory(nebula::ServiceBase* service)
    : service_(service) {}
  
  nebula::TelegramPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
  
private:
  nebula::ServiceBase* service_{nullptr};
};

class TelegramServerPipelineFactory : public wangle::PipelineFactory<nebula::TelegramPipeline> {
public:
  TelegramServerPipelineFactory(nebula::ServiceBase* service)
    : service_(service) {}
  
  nebula::TelegramPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
  
private:
  nebula::ServiceBase* service_{nullptr};
};

#endif

