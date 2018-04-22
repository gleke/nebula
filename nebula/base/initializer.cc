/**
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

#include "nebula/base/initializer.h"

#include <glog/logging.h>
#include <gflags/gflags.h>
#include <folly/Singleton.h>

#ifndef __APPLE__
#include <folly/init/Init.h>
#endif

#include "nebula/base/logger/glog_util.h"

namespace nebula {
  
void Initializer(int* argc, char*** argv, bool remove_flags) {
#ifdef __APPLE__
  // Install the handler now, to trap errors received during startup.
  // The callbacks, if any, can be installed later
  // folly::symbolizer::installFatalSignalHandler();
  
  google::ParseCommandLineFlags(argc, argv, remove_flags);

  auto programName = argc && argv && *argc > 0 ? (*argv)[0] : "unknown";
  google::InitGoogleLogging(programName);
  
  // google::ParseCommandLineFlags(argc, argv, removeFlags);
  
  // Don't use glog's DumpStackTraceAndExit; rely on our signal handler.
  google::InstallFailureFunction(abort);
  // google::InstallFailureSignalHandler();
  
  // Move from the registration phase to the "you can actually instantiate
  // things now" phase.
  folly::SingletonVault::singleton()->registrationComplete();
  
  // Actually install the callbacks into the handler.
  // folly::symbolizer::installFatalSignalCallbacks();

#else
  folly::init(argc, argv);
#endif
  
  LogInitializer::Initialize((*argv)[0]);
}

}
