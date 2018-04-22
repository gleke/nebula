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

#include "nebula/net/handler/module_install.h"

void InstallModule() {
  // echo
  extern void ModuleEchoInitialize();
  ModuleEchoInitialize();
  
  // zproto
  extern void ModuleZProtoInitialize();
  ModuleZProtoInitialize();
  
  // http
  extern void ModuleHttpInitialize();
  ModuleHttpInitialize();
  
  // rpc
  extern void ModuleZRpcInitialize();
  ModuleZRpcInitialize();
  
  // teamtalk
  // extern void ModuleTeamtalkInitialize();
  // ModuleTeamtalkInitialize();
  
  // telegram
  // extern void ModuleTelegramInitialize();
  // ModuleTelegramInitialize();
  
  // mtproto
  extern void ModuleMTProtoInitialize();
  ModuleMTProtoInitialize();
}

