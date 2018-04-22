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

// Author: wubenqi@gmail.com (wubenqi)
//

#ifndef NEBULA_MYSQL_CLIENT_MYSQL_QUERY_UTIL_H_
#define NEBULA_MYSQL_CLIENT_MYSQL_QUERY_UTIL_H_
#pragma once

#include <string.h>

#include <string>
#include <vector>
// #include "base/basictypes.h"

// TODO(@benqi): 使用模板简化

enum ColumnType { 
	kColumnTypeStrEsc = 0,
	kColumnTypeStr,
	kColumnTypeInt32,
	kColumnTypeUInt32,
  kColumnTypeUInt64,
	kColumnTypeBlob,
	kColumnTypeStr2,
	kColumnTypeFloat,
	kColumnTypeDouble
};

struct QueryParamItem {
	int type;
	int len;
	const char* param;
};

class QueryParam : 
	public std::vector<QueryParamItem> {
public:

	void AddParamEsc(const char *param) {
		_addparam(param, static_cast<int>(strlen(param)), kColumnTypeStrEsc);
	}

	void AddParam(const char *param) {
		_addparam(param, static_cast<int>(strlen(param)), kColumnTypeStr);
	}

	void AddParam(const int *param) {
		_addparam((const char*)param, sizeof(int), kColumnTypeInt32 );
	}

	void AddParam(const float *param) {
		_addparam((const char*)param, sizeof(float), kColumnTypeFloat );
	}

	void AddParam(const uint32_t *param) {
		_addparam((const char*)param, sizeof(uint32_t), kColumnTypeUInt32);
	}

  void AddParam(const uint64_t *param) {
    _addparam((const char*)param, sizeof(uint64_t), kColumnTypeUInt64);
  }

	void AddParam(const char *param, int len) {
		_addparam((const char*)param, len, kColumnTypeStr);
	}

	void AddParamEsc(const char *param, int len) {
		_addparam(param, len, kColumnTypeBlob);
	}

	void AddParam(const double *param) {
		_addparam((const char*)param, sizeof(double), kColumnTypeDouble);
	}

	void Clear() {
		clear();
	}

private:
	void _addparam(const char *param, int len, int type) {
		QueryParamItem p;
		p.len = len;
		p.type = type;
		p.param = param;
		push_back(p);
	}
};

bool MakeQueryString(const char *query, int lmt, std::string *query_string);
bool MakeQueryString(const char *query, QueryParam *param, std::string *query_string);
bool MakeQueryString(const char *query, QueryParam *param, int lmt, std::string *query_string);


#endif
