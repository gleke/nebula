/*
 *  Copyright (c) 2016, https://github.com/nebula-im
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

#ifndef	PROTO_ERROR_CODES_H_
#define	PROTO_ERROR_CODES_H_

const int kErrOK         = 0;

const int kErrDBError    = 1000; // DB无法连接
const int kErrDBConn     = 1001; // DB无法连接
const int kErrDBSql      = 1002; // SQL非法
const int kErrDBData     = 1003; // QueryAnswer解析有问题
const int kErrDBDup      = 1004; // QueryAnswer解析有问题

const int kErrNotImpl    = 1100; // QueryAnswer解析有问题

/*
  303
  500
  420
  400
  401
 */

#endif
