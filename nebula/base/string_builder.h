//============================================================================
// Name        : StringBuilderDemo.cpp
// Author      : Pablo Aliskevicius
// Copyright   : Licensed under the Code Project Open License
// Description : std::basic_string<>::reserve can save _lots_ of time in reallocations.
//               Using std::accumulate on strings can have a _big_ performance cost.
// Version II modifications:
//      1.  Added std::basic_stringstream to the tests.
//          Thanks to http://www.codeproject.com/script/Membership/View.aspx?mid=797594
//      2.  Removed a function that is no longer relevant.
// 		3.	Performance test with side effects, so the compiler doesn't optimize it away.
// 			Inspired on the code at http://code.google.com/p/strtk/source/browse/trunk/strtk_tokenizer_cmp.cpp#699
//          There are two modifications:
//          a. Less tests (4001 instead of 40000 * number of items in vector)
//          b. Using ^= instead of if ... += else ... -=.
// 			Thanks to: http://www.codeproject.com/script/Membership/View.aspx?mid=1256594
//      4.  Added this lambda:
//          for_each(test.begin(), test.end(), [&](const std::wstring &s){ accumulator += s; });
//          Thanks to http://www.codeproject.com/script/Membership/View.aspx?mid=10171025
//
// C++ 11 Support in Eclipse:
//  		See http://stackoverflow.com/questions/9131763/eclipse-cdt-c11-c0x-support
//============================================================================

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


#ifndef	NEBULA_BASE_STRING_BUILDER_H_
#define NEBULA_BASE_STRING_BUILDER_H_

#include <string>   // for std::basic_string;
#include <deque>    // used in class StringBuilder, slightly faster than list.
#include <numeric>  // for accumulate

// Subset of http://msdn.microsoft.com/en-us/library/system.text.stringbuilder.aspx
template <typename chr>
class BasicStringBuilder {
	typedef std::basic_string<chr> string_t;
	// After testing several times with deque, vector and list, deque performed _slightly_ better.
 	typedef std::deque<string_t> container_t;
	container_t m_Data;
	typedef typename string_t::size_type size_type; // Reuse the size type in the string.
	size_type m_totalSize;
	void append(const string_t &src) {
		m_Data.push_back(src);
		m_totalSize += src.size();
	}
	// No copy constructor, no assignment.
	BasicStringBuilder(const BasicStringBuilder &);
	BasicStringBuilder & operator = (const BasicStringBuilder &);
  
public:
	BasicStringBuilder(const string_t &src) {
		if (src.empty()) {
			m_totalSize = 0;
		} else {
			m_Data.push_back(src);
			m_totalSize = src.size();
		}
	}
  
	BasicStringBuilder() {
		m_totalSize = 0;
	}

	BasicStringBuilder & Append(const string_t &src) {
		append(src);
		return *this; // allow chaining.
	}
  
	template<class iterator>
	BasicStringBuilder & Add(const iterator &first, const iterator &afterLast) {
		// std::for_each and a lambda look like overkill here.
		for (iterator f = first; f != afterLast; ++f) {
			append(*f);
		}
		return *this;
	}
  
	BasicStringBuilder & AppendLine(const string_t &src) {
		chr lineFeed[] { 10, 0 }; // C++ 11. Feel the love!
		m_Data.push_back(src + lineFeed);
		m_totalSize += 1 + src.size();
		return *this; // allow chaining.
	}
  
	BasicStringBuilder & AppendLine() {
		chr lineFeed[] { 10, 0 };
		m_Data.push_back(lineFeed);
		++m_totalSize;
		return *this; // allow chaining.
	}
  
	BasicStringBuilder &Clear() {
		m_totalSize = 0;
		m_Data.clear();
		return *this;
	}

	// ADVANCED TOPIC: AppendFormat()

    // Like C# StringBuilder.ToString()
	string_t ToString() const {
		string_t result;
		// The whole point of the exercise!
		// If the container has a lot of strings, reallocation (each time the result grows) may take a serious toll,
		// both in performance and chances of failure.
		// I measured (in code I don't own) fractions of a second using 'reserve', and almost two minutes using +=.
		result.reserve(1 + m_totalSize); // leave room for the ending zero.
	//	result = std::accumulate(m_Data.begin(), m_Data.end(), result); // This would lose the advantage of 'reserve'
		for (auto iter = m_Data.begin(); iter != m_Data.end(); ++iter) {
			result += *iter;
		}
		return result;
	}

	// Like Javascript array join.
	string_t Join(const string_t &delim) const {
		if (delim.empty()) {
			return ToString();
		}
		string_t result;
		if (m_Data.empty()) {
			return result;
		}
		// Compute the required size, hoping it won't overflow the size type.
		size_type st = (delim.size() * (m_Data.size() - 1)) + m_totalSize + 1;
		result.reserve(st);
		// Another nice feature in C++11: local structs can be used with STL algorithms.
		struct adder {
			string_t m_Joiner;
			adder(const string_t &s): m_Joiner(s) {
				// This constructor is NOT empty.
			}
			string_t operator()(string_t &preAllocated, const string_t &current) {
				preAllocated += m_Joiner;
				preAllocated += current;
				return preAllocated;
			}
		} adr(delim);
		auto iter = m_Data.begin();
		result += *iter;
		return std::accumulate(++iter, m_Data.end(), result, adr);
	}

}; // class BasicStringBuilder

typedef BasicStringBuilder<char> CStringBuilder;
typedef BasicStringBuilder<wchar_t> WStringBuilder;

#endif

