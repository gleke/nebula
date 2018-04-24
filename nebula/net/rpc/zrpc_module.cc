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

#include "nebula/net/rpc/zrpc_client_handler.h"
#include "nebula/net/rpc/zrpc_server_handler.h"
#include "nebula/net/rpc/zrpc_pipeline_factory.h"

#include "nebula/net/engine/tcp_client_group.h"
#include "nebula/net/engine/rpc_client.h"
#include "nebula/net/engine/rpc_server.h"

using namespace nebula;

///////////////////////////////////////////////////////////////////////////////////////
// 不能直接使用静态类注册的原因:
// 不在一个.a文件里静态变量不可视
// 通过ModuleZProtoInitialize显式调用
void ModuleZRpcInitialize() {
  static ServiceSelfRegisterTemplate g_reg_zrpc_tcp_client_group(std::make_pair("tcp_client_group", "zrpc"),
           [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
             auto service= std::make_shared<TcpClientGroup<ZRpcClientPipeline>>(service_config, io_group);
             return service;
           });

  static ServiceSelfRegisterTemplate g_reg_zrpc_rpc_client(std::make_pair("rpc_client", "zrpc"),
           [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
             auto service = std::make_shared<RpcClient<ZRpcClientPipeline>>(service_config, io_group);
             auto factory = std::make_shared<ZRpcClientPipelineFactory>(service.get());
             service->SetChildPipeline(factory);
             return service;
           });

  static ServiceSelfRegisterTemplate g_reg_zproto_tcp_server(std::make_pair("rpc_server", "zrpc"),
           [](const ServiceConfig& service_config, const std::shared_ptr<folly::IOThreadPoolExecutor>& io_group) -> ServiceBasePtr {
             auto service = std::make_shared<RpcServer<ZRpcServerPipeline>>(service_config, io_group);
             auto factory = std::make_shared<ZRpcServerPipelineFactory>(service.get());
             service->SetChildPipeline(factory);
             return service;
           });
}
