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

#include "nebula/mysql_client/mysql_query_util.h"

#include <folly/Format.h>

#include "nebula/base/logger/glog_util.h"
// #include "base/strings/stringprintf.h"

namespace {

void StringAppendQ(std::string* dest, const char* src, int count) {
	while (count-- > 0) {
		if (*src == '\'') {
			dest->push_back('\\');
		} else if (*src == '"') {
			dest->push_back('\\');
		} else if (*src == '\\') {
			dest->push_back('\\');
		}
		dest->push_back(*src++);
	}
}

}

bool MakeQueryString(const char *query, int lmt, std::string *query_string) {
	return MakeQueryString(query, NULL, lmt, query_string);
}

bool MakeQueryString(const char *query, QueryParam *param, std::string *query_string) {
	return MakeQueryString(query, param, 0, query_string);
}

bool MakeQueryString(const char *query, QueryParam *param, int lmt, std::string *query_string) {
	if (query==NULL || query_string==NULL) {
		LOG(ERROR) << "MakeQueryString param (query or query_string) is null";
		return false;
	}
	
	query_string->clear();

	const char *sp, *pprev;
	uint32_t i = 0;

	sp = pprev = query;

	if (!param) {
		*query_string = query;
	} else {
		while(*sp++) {
			if (*sp == '%' || *sp == ':') {
				const char *sp_t = sp++;
				// 为%s或者:数字
				while (*sp && ((*sp == 's') || (*sp >=0x30 && *sp<=0x39)))
					sp++;
				if (sp_t == sp)
					continue;
				if (i > (param->size() - 1)) {
					LOG(ERROR) << "Error in sql number of param = " << param->size() << ", query=" << query << " ";
					query_string->clear();
					return false;
				}
				query_string->append(pprev, sp_t-pprev);
				if ((*param)[i].param) {
					switch ((*param)[i].type) {
					case kColumnTypeStr2:
						query_string->push_back('\'');
						if ((*param)[i].len) {
							StringAppendQ(query_string, (*param)[i].param, (*param)[i].len << 1);
						}
						query_string->push_back('\'');
						break;
					case kColumnTypeStrEsc:
					case kColumnTypeBlob:
						query_string->push_back('\'');
						if ((*param)[i].len) {
							StringAppendQ(query_string, (*param)[i].param, (*param)[i].len);
						}
						query_string->push_back('\'');
						break;
					case kColumnTypeStr:
						if (*(sp_t + 1) != 's') query_string->push_back('\'');
						if ((*param)[i].len) {
							StringAppendQ(query_string, (*param)[i].param, (*param)[i].len);
						}
						if (*(sp_t + 1) != 's') query_string->push_back('\'');;
						break;
					case kColumnTypeInt32:
            // base::StringAppendF(&query_string, "%d", *((int*)(*param)[i].param));
						folly::format(query_string, "{}", *((int*)(*param)[i].param));
						break;
          case kColumnTypeUInt32:
            folly::format(query_string, "{}", *((uint32_t*)(*param)[i].param));
              break;
					case kColumnTypeUInt64:
						folly::format(query_string, "{}", *((uint64_t*)(*param)[i].param));
						break;
					case kColumnTypeFloat:
						folly::format(query_string, "{}", *((float*)(*param)[i].param));
						break;
					case kColumnTypeDouble:
						folly::format(query_string, "{}", *((double*)(*param)[i].param));
						break;
						}
				} else {
					query_string->append("NULL");
				}
				pprev = sp;
				i++;
			}
		}
		query_string->append(pprev);

		if (i != param->size()) {
			LOG(ERROR) << "Error in sql number of param =  " << param->size() << ", query=" << query;
			query_string->clear();
			return false;
		}
	}

	if (lmt) {
    folly::format(query_string, " LIMIT {}", lmt);
		
    // base::StringAppendF(query_string, " LIMIT %lu", lmt);
	}
  
  return true;
}


