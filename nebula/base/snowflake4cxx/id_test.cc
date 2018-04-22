/*
 *  Copyright (c) 2016, https://github.com/wubenqi/snowflake4cxx
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
 *
 */

#include <sys/time.h>

#include <iostream>

#include "snowflake4cxx/id.h"

inline uint64_t GetNowInMsec() {
  timeval tv;
  gettimeofday(&tv, 0);
  return uint64_t(tv.tv_sec) * 1000 + tv.tv_usec/1000;
}

using namespace snowflake4cxx;

int main(int argc, char* argv[]) {
  IdWorkerUnThreadSafe id(0, 0);
  IdWorkerThreadSafe id2(0, 0);
  
  int c = 10000000;
  if (argc > 1) {
    int c2 = atoi(argv[1]);
    if (c2 > 0) {
      c = c2;
    }
  }
  uint64_t b = GetNowInMsec();
  // std::cout << "R"
  // std::cout << GetNowInMsec() <
  for (int i=0; i<c; ++i)
    id2.GetNextID();
  
  uint64_t d = GetNowInMsec() - b;
  std::cout << "IdWorkerUnThreadSafe> Executed: " << c << std::endl;
  std::cout << "IdWorkerUnThreadSafe> duration: " << (uint32_t)d << std::endl;
  std::cout << "IdWorkerUnThreadSafe> avg: " << (uint32_t) (((float)c/d)*1000) << std::endl;

  b = GetNowInMsec();
  // std::cout << "R"
  // std::cout << GetNowInMsec() <
  for (int i=0; i<c; ++i)
    id2.GetNextID();
  
  d = GetNowInMsec() - b;
  std::cout << "IdWorkerThreadSafe> Executed: " << c << std::endl;
  std::cout << "IdWorkerThreadSafe> duration: " << (uint32_t)d << std::endl;
  std::cout << "IdWorkerThreadSafe> avg: " << (uint32_t) (((float)c/d)*1000) << std::endl;

  return 0;
}

