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

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>


#include "nebula/base/config_manager.h"
#include "nebula/net/thread_group_list_manager.h"

DEFINE_string(json, "", "thread_util_test.json");

using namespace nebula;

int main(int argc, char* argv[]) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    // google::InitGoogleLogging(argv[0]);
    // google::InstallFailureSignalHandler();

    folly::EventBase main_evb;
    
    ConfigManager* config_manager = ConfigManager::GetInstance();
    
    ThreadGroupListOption thread_options;
    config_manager->Register("thread_pool", &thread_options);
    
    std::string config_path = FLAGS_json;
    if (FLAGS_json.empty()){
        config_path = "thread_util_test"; //google::ProgramInvocationShortName();
        config_path += ".json";
    }

    config_manager->Initialize(config_path);
    ThreadGroupListManager thread_manager(thread_options);
    // thread_manager->Initialize();

    main_evb.loopForever();
    
    return 0;
}

