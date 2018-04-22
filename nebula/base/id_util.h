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

#ifndef NEBULA_BASE_ID_UTIL_H_
#define NEBULA_BASE_ID_UTIL_H_

#include <stdint.h>

void InitSnowflakeWorkerID(uint16_t worker_id, uint16_t data_center_id=1);

uint64_t GetNextIDBySnowflake();

// 非线程安全
// uint64_t GetNextIDBySnowflakeUnSafe();

#endif

