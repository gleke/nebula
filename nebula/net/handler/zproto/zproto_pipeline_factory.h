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

#ifndef NEBULA_NET_HANDLER_ZPROTO_ZPROTO_PIPELINE_FACTORY_H_
#define NEBULA_NET_HANDLER_ZPROTO_ZPROTO_PIPELINE_FACTORY_H_

#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/handler/zproto/zproto_handler.h"

class ZProtoPipelineFactory : public wangle::PipelineFactory<nebula::ZProtoPipeline> {
public:
  ZProtoPipelineFactory(nebula::ServiceBase* service)
    : service_(service) {}
  
  nebula::ZProtoPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
  
private:
  nebula::ServiceBase* service_{nullptr};
};

class ZProtoClientPipelineFactory : public wangle::PipelineFactory<nebula::ZProtoPipeline> {
public:
  ZProtoClientPipelineFactory(nebula::ServiceBase* service)
    : service_(service) {}
  
  nebula::ZProtoPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
  
private:
  nebula::ServiceBase* service_{nullptr};
};

class ZProtoServerPipelineFactory : public wangle::PipelineFactory<nebula::ZProtoPipeline> {
public:
  ZProtoServerPipelineFactory(nebula::ServiceBase* service)
    : service_(service) {}
  
  nebula::ZProtoPipeline::Ptr newPipeline(std::shared_ptr<folly::AsyncTransportWrapper> sock);
  
private:
  nebula::ServiceBase* service_{nullptr};
};

#endif

