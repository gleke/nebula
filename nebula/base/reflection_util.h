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

// 原始出处：https://github.com/qicosmos/Kapok/blob/master/kapok/Common.hpp
// Edit by @benqi
// 我靠，又是黑科技
//

#ifndef NEBULA_BASE_REFLECTION_UTIL_H_
#define NEBULA_BASE_REFLECTION_UTIL_H_

#include <memory>
#include <string>
#include <array>
#include <tuple>

namespace nebula {
  
template<unsigned N>
std::array<std::string, N> split(const std::string& s, const char delimiter) {
	size_t start = 0;
	size_t end = s.find_first_of(delimiter);

	std::array<std::string, N> output;

	size_t i = 0;
	while (end <= std::string::npos) {
		output[i++] = std::move(s.substr(start, end - start));
		if (end == std::string::npos)
			break;

		start = end + 2;
		end = s.find_first_of(delimiter, start);
	}

	return output;
}

template <size_t N, typename T, typename T1>
static inline auto make(const std::array<std::string, N>&ar, unsigned index, T const & t, T1& args) {
	return std::tuple_cat(t, std::make_tuple(std::pair<std::string, T1&>(ar[index], args)));
}

template <size_t N, typename T, typename T1, typename... Args>
static inline auto make(const std::array<std::string, N>&ar, unsigned index, T const & t, T1& first, Args&... args) {
	return make(ar, index + 1, std::tuple_cat(t, std::make_tuple(std::pair<std::string, T1&>(ar[index], first))), args...);
}

#define VA_ARGS_NUM(...) std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value

//#define META(...) auto Meta(){\
//	auto ar = split<VA_ARGS_NUM(__VA_ARGS__)>(#__VA_ARGS__, ',');\
//	return make(ar, 0, std::tuple<>(), __VA_ARGS__);\
//}

/******************************************/
#define MARCO_EXPAND(...)                 __VA_ARGS__
#define APPLY_VARIADIC_MACRO(macro, ...)  MARCO_EXPAND(macro(__VA_ARGS__))

#define ADD_REFERENCE(t)        std::reference_wrapper<decltype(t)>(t)
#define ADD_REFERENCE_CONST(t)  std::reference_wrapper<std::add_const_t<decltype(t)>>(t)
#define PAIR_OBJECT(t)          std::make_pair(#t, ADD_REFERENCE(t))
#define PAIR_OBJECT_CONST(t)    std::make_pair(#t, ADD_REFERENCE_CONST(t))
#define MAKE_TUPLE(...)         auto Meta() { return std::make_tuple(__VA_ARGS__); }
//#define MAKE_TUPLE_CONST(...)   auto tuple() const { return std::make_tuple(__VA_ARGS__); }

/* arg list expand macro, now support 40 args */
#define MAKE_ARG_LIST_1(op, arg, ...)   op(arg)
#define MAKE_ARG_LIST_2(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_1(op, __VA_ARGS__))
#define MAKE_ARG_LIST_3(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_2(op, __VA_ARGS__))
#define MAKE_ARG_LIST_4(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_3(op, __VA_ARGS__))
#define MAKE_ARG_LIST_5(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_4(op, __VA_ARGS__))
#define MAKE_ARG_LIST_6(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_5(op, __VA_ARGS__))
#define MAKE_ARG_LIST_7(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_6(op, __VA_ARGS__))
#define MAKE_ARG_LIST_8(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_7(op, __VA_ARGS__))
#define MAKE_ARG_LIST_9(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_8(op, __VA_ARGS__))
#define MAKE_ARG_LIST_10(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_9(op, __VA_ARGS__))
#define MAKE_ARG_LIST_11(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_10(op, __VA_ARGS__))
#define MAKE_ARG_LIST_12(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_11(op, __VA_ARGS__))
#define MAKE_ARG_LIST_13(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_12(op, __VA_ARGS__))
#define MAKE_ARG_LIST_14(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_13(op, __VA_ARGS__))
#define MAKE_ARG_LIST_15(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_14(op, __VA_ARGS__))
#define MAKE_ARG_LIST_16(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_15(op, __VA_ARGS__))
#define MAKE_ARG_LIST_17(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_16(op, __VA_ARGS__))
#define MAKE_ARG_LIST_18(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_17(op, __VA_ARGS__))
#define MAKE_ARG_LIST_19(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_18(op, __VA_ARGS__))
#define MAKE_ARG_LIST_20(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_19(op, __VA_ARGS__))
#define MAKE_ARG_LIST_21(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_20(op, __VA_ARGS__))
#define MAKE_ARG_LIST_22(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_21(op, __VA_ARGS__))
#define MAKE_ARG_LIST_23(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_22(op, __VA_ARGS__))
#define MAKE_ARG_LIST_24(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_23(op, __VA_ARGS__))
#define MAKE_ARG_LIST_25(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_24(op, __VA_ARGS__))
#define MAKE_ARG_LIST_26(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_25(op, __VA_ARGS__))
#define MAKE_ARG_LIST_27(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_26(op, __VA_ARGS__))
#define MAKE_ARG_LIST_28(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_27(op, __VA_ARGS__))
#define MAKE_ARG_LIST_29(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_28(op, __VA_ARGS__))
#define MAKE_ARG_LIST_30(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_29(op, __VA_ARGS__))
#define MAKE_ARG_LIST_31(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_30(op, __VA_ARGS__))
#define MAKE_ARG_LIST_32(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_31(op, __VA_ARGS__))
#define MAKE_ARG_LIST_33(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_32(op, __VA_ARGS__))
#define MAKE_ARG_LIST_34(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_33(op, __VA_ARGS__))
#define MAKE_ARG_LIST_35(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_34(op, __VA_ARGS__))
#define MAKE_ARG_LIST_36(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_35(op, __VA_ARGS__))
#define MAKE_ARG_LIST_37(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_36(op, __VA_ARGS__))
#define MAKE_ARG_LIST_38(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_37(op, __VA_ARGS__))
#define MAKE_ARG_LIST_39(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_38(op, __VA_ARGS__))
#define MAKE_ARG_LIST_40(op, arg, ...)  op(arg), MARCO_EXPAND(MAKE_ARG_LIST_39(op, __VA_ARGS__))

/* emmbed marco, using EMMBED_TUPLE(5 , a, b, c, d, e) */
//note use MACRO_CONCAT like A##_##B direct may cause marco expand error
#define MACRO_CONCAT(A, B) MACRO_CONCAT1(A, B)
#define MACRO_CONCAT1(A, B) A##_##B

#define MAKE_ARG_LIST(N, op, arg, ...) \
        MACRO_CONCAT(MAKE_ARG_LIST, N)(op, arg, __VA_ARGS__)

#define EMMBED_TUPLE(N, ...) \
MAKE_TUPLE(MAKE_ARG_LIST(N, PAIR_OBJECT, __VA_ARGS__)) 
//MAKE_TUPLE_CONST(MAKE_ARG_LIST(N, PAIR_OBJECT_CONST, __VA_ARGS__))

#define RSEQ_N() \
		 119,118,117,116,115,114,113,112,111,110,\
		 109,108,107,106,105,104,103,102,101,100,\
		 99,98,97,96,95,94,93,92,91,90, \
		 89,88,87,86,85,84,83,82,81,80, \
		 79,78,77,76,75,74,73,72,71,70, \
		 69,68,67,66,65,64,63,62,61,60, \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

#define ARG_N( \
         _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
		 _61,_62,_63,_64,_65,_66,_67,_68,_69,_70, \
		 _71,_72,_73,_74,_75,_76,_77,_78,_79,_80, \
		 _81,_82,_83,_84,_85,_86,_87,_88,_89,_90, \
		 _91,_92,_93,_94,_95,_96,_97,_98,_99,_100, \
		 _101,_102,_103,_104,_105,_106,_107,_108,_109,_110, \
         _111,_112,_113,_114,_115,_116,_117,_118,_119,N, ...) N

#define GET_ARG_COUNT_INNER(...)    MARCO_EXPAND(ARG_N(__VA_ARGS__))
  
// 获得参数个数
#define GET_ARG_COUNT(...)          GET_ARG_COUNT_INNER(__VA_ARGS__, RSEQ_N())

#define META(...) EMMBED_TUPLE(GET_ARG_COUNT(__VA_ARGS__), __VA_ARGS__)
/******************************************/

// Patch by @benqi
#if 0
class NonCopyable {
public:
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator = (const NonCopyable&) = delete; 
	NonCopyable() = default; 
};
#endif
  
/*********************************************************************
// 分析和解读
// 简单的例子
struct Person {
  std::string name;
  int age;
 
  META(name, age);
};

// 通过展开META(name, age)来理解
 
// 1. 展开META
//  EMMBED_TUPLE(GET_ARG_COUNT(name, age), name, age);
//
// 2. 展开GET_ARG_COUNT(name, age)
//  GET_ARG_COUNT_INNER(name, age, RSEQ_N())
// 
// 3. 精简ARG_N和RSEQ_N，为了好理解，精简成4个数字
//  #define RSEQ_N() 3,2,1,0
//  #define ARG_N(1,2,3,N, ...) N
//
// 4. GET_ARG_COUNT_INNER(name, age, RSEQ_N())展开为
//  GET_ARG_COUNT_INNER(name, age, 3, 2, 1, 0)
 
// 5. GET_ARG_COUNT_INNER替换成MARCO_EXPAND(ARG_N(__VA_ARGS__))
//  ARG_N(__VA_ARGS__) ==> ARG_N(name, age, 3, 2, 1, 0) ==> 则N为 2, 绝对的黑科技!!!!
//  故MARCO_EXPAND(ARG_N(__VA_ARGS__)) ==> MARCO_EXPAND(2)
//  又通过 #define MARCO_EXPAND(...)                 __VA_ARGS__
//  则可计算出GET_ARG_COUNT(...)参数值。
// 你妈的，咋想出来的!!!!
//
// 6. 再回到 EMMBED_TUPLE(GET_ARG_COUNT(name, age), name, age)，变为
//  EMMBED_TUPLE(2, name, age)
//  #define EMMBED_TUPLE(N, ...) \
//    MAKE_TUPLE(MAKE_ARG_LIST(N, PAIR_OBJECT, __VA_ARGS__))
//  由EMMBED_TUPLE宏展开： MAKE_TUPLE(MAKE_ARG_LIST(2,PAIR_OBJECT, name, age))
//
// 7. 先来看MAKE_ARG_LIST(2,PAIR_OBJECT, name, age)
//
//  #define MACRO_CONCAT(A, B) MACRO_CONCAT1(A, B)
//  #define MACRO_CONCAT1(A, B) A##_##B
//  #define MAKE_ARG_LIST(N, op, arg, ...) \
//  MACRO_CONCAT(MAKE_ARG_LIST, N)(op, arg, __VA_ARGS__)
//
//  由上面宏可以又可以推导出: MAKE_ARG_LIST_2(PAIR_OBJECT, name, age)
//   #define MAKE_ARG_LIST_1(op, arg, ...)   op(arg)
//   #define MAKE_ARG_LIST_2(op, arg, ...)   op(arg), MARCO_EXPAND(MAKE_ARG_LIST_1(op, __VA_ARGS__))
// 
//   PAIR_OBJECT(name), MAKE_ARG_LIST_1(PAIR_OBJECT, age), 展开MAKE_ARG_LIST_1，变成：
//   PAIR_OBJECT(name), PAIR_OBJECT(age)
//
// 8. 展开PAIR_OBJECT(name), PAIR_OBJECT(age)
//  #define ADD_REFERENCE(t)        std::reference_wrapper<decltype(t)>(t)
//  #define PAIR_OBJECT(t)          std::make_pair(#t, ADD_REFERENCE(t))
//  std::make_pair("name", std::reference_wrapper<decltype(name)>(name)), std::make_pair("age", std::reference_wrapper<decltype(age)>(age))
//
// 9. 再来看 MAKE_TUPLE(MAKE_ARG_LIST(N, PAIR_OBJECT, __VA_ARGS__))
//  MAKE_TUPLE(MAKE_ARG_LIST(N, PAIR_OBJECT, __VA_ARGS__))
//  变成:
//  MAKE_TUPLE(std::make_pair("name", std::reference_wrapper<decltype(name)>(name)),
//               std::make_pair("age", std::reference_wrapper<decltype(age)>(age))
// #define MAKE_TUPLE(...)         auto Meta() { return std::make_tuple(__VA_ARGS__); }
//
// auto Meta() {
//    return std::make_tuple(std::make_pair("name", std::reference_wrapper<decltype(name)>(name)),
//                           std::make_pair("age", std::reference_wrapper<decltype(age)>(age)));
// }
//
// 由上分析可见，完整的Person类：
//

struct Person {
  std::string name;
  int age;

  // META(name, age);
  auto Meta() {
     return std::make_tuple(std::make_pair("name", std::reference_wrapper<decltype(name)>(name)),
                            std::make_pair("age", std::reference_wrapper<decltype(age)>(age)));
  }
};

 
*********************************************************************/

} // namespace nebula

#endif // NEBULA_BASE_REFLECTION_UTIL_H_
