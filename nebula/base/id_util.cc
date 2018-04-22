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

#include "nebula/base/snowflake4cxx/id.h"


namespace {
  
uint16_t g_worker_id = 1;
uint16_t g_data_center_id = 1;
  
}

void    InitSnowflakeWorkerID(uint16_t worker_id, uint16_t data_center_id) {
  g_worker_id = worker_id;
  g_data_center_id = data_center_id;
}


uint64_t GetNextIDBySnowflake() {
  static snowflake4cxx::IdWorkerThreadSafe g_id_worker(g_worker_id, g_data_center_id);
  return g_id_worker.GetNextID();
}

