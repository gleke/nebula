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

#ifndef NEBULA_BASE_JSON_DYNAMIC_CONVERTER_H_
#define NEBULA_BASE_JSON_DYNAMIC_CONVERTER_H_

#include <folly/DynamicConverter.h>
#include <folly/Conv.h>

#include "nebula/base/traits.h"


/**
 folly的DynamicConverter(https://github.com/facebook/folly/blob/master/folly/docs/DynamicConverter.md)
 用法：
  // DynamicConstructor
  struct Token {
    int kind_;
    fbstring lexeme_;
    
    explicit Token(int kind, const fbstring& lexeme)
    : kind_(kind), lexeme_(lexeme) {}
  };
  namespace folly {
    template <> struct DynamicConverter<Token> {
      static Token convert(const dynamic& d) {
        int k = convertTo<int>(d["KIND"]);
        fbstring lex = convertTo<fbstring>(d["LEXEME"]);
        return Token(k, lex);
      }
    };
  }
 
 DynamicConverter提供了folly::dynamic和其它类型的强大的互相转换能力。
 但DynamicConverter对json格式的支持不够友好：
  比如对std::pair，是通过dynamic::array存储pair的两个值。
  map，如果k不是string，则也会存在问题
 通常情况下，一个pair对定义成json的一个"k":"v"
 在这里，基于DynamicConverter，实现了兼容json类型的格式转换
 */

// 需要注意的地方：
// 我们认为pair的first做为一个key，map的k也做为一个key
// 那么对key就有个限制，key只能是简单的类型
// 我们的实现里做了一个简单的限制，k可以通过folly::to<std::string>()进行转换


///////////////////////////////////////////////////////////////////////////////
// DynamicConverter specializations


template <typename T> T JsonDynamciConvertTo(const folly::dynamic&);
template <typename T> folly::dynamic ToJsonDynamic(const T&);

/**
 * Each specialization of DynamicConverter has the function
 *     'static T convert(const dynamic&);'
 */
// default - intentionally unimplemented
template <typename T, typename Enable = void> struct JsonDynamicConverter;

// boolean
template <>
struct JsonDynamicConverter<bool> {
  static bool convert(const folly::dynamic& d) {
    return d.asBool();
  }
};

// integrals
template <typename T>
struct JsonDynamicConverter<T,
typename std::enable_if<
  std::is_integral<T>::value &&
  !std::is_same<T, bool>::value>::type> {
  
  static T convert(const folly::dynamic& d) {
    return folly::to<T>(d.asInt());
  }
};

// enums
template <typename T>
struct JsonDynamicConverter<T,
  typename std::enable_if<std::is_enum<T>::value>::type> {
  static T convert(const folly::dynamic& d) {
    using type = typename std::underlying_type<T>::type;
    return static_cast<T>(JsonDynamicConverter<type>::convert(d));
  }
};

// floating point
template <typename T>
struct JsonDynamicConverter<T,
  typename std::enable_if<std::is_floating_point<T>::value>::type> {
  static T convert(const folly::dynamic& d) {
    return folly::to<T>(d.asDouble());
  }
};

// fbstring
template <>
struct JsonDynamicConverter<folly::fbstring> {
  static folly::fbstring convert(const folly::dynamic& d) {
    return d.asString();
  }
};

// std::string
template <>
struct JsonDynamicConverter<std::string> {
  static std::string convert(const folly::dynamic& d) {
    return d.asString();
  }
};

// std::pair
template <typename F, typename S>
struct JsonDynamicConverter<std::pair<F,S>> {
  static std::pair<F, S> convert(const folly::dynamic& d) {
    if (d.isArray() && d.size() == 2) {
      return std::make_pair(JsonDynamciConvertTo<F>(d[0]), JsonDynamciConvertTo<S>(d[1]));
    } else if (d.isObject() && d.size() == 1) {
      auto it = d.items().begin();
      return std::make_pair(JsonDynamciConvertTo<F>(it->first), JsonDynamciConvertTo<S>(it->second));
    } else {
      throw folly::TypeError("array (size 2) or object (size 1)", d.type());
    }
  }
};

// containers
template <typename C>
struct JsonDynamicConverter<C,
typename std::enable_if<
  folly::dynamicconverter_detail::is_container<C>::value>::type> {
    
  static C convert(const folly::dynamic& d) {
    if (d.isArray()) {
      return C(folly::dynamicconverter_detail::conversionIterator<C>(d.begin()),
               folly::dynamicconverter_detail::conversionIterator<C>(d.end()));
    } else if (d.isObject()) {
      return C(folly::dynamicconverter_detail::conversionIterator<C>
               (d.items().begin()),
               folly::dynamicconverter_detail::conversionIterator<C>
               (d.items().end()));
    } else {
      throw folly::TypeError("object or array", d.type());
    }
  }
};

///////////////////////////////////////////////////////////////////////////////
// DynamicConstructor specializations

/**
 * Each specialization of DynamicConstructor has the function
 *     'static dynamic construct(const C&);'
 */

// default
template <typename C, typename Enable = void>
struct JsonDynamicConstructor {
  static folly::dynamic construct(const C& x) {
    return folly::dynamic(x);
  }
};

// maps
template<typename C>
struct JsonDynamicConstructor<C,
  typename std::enable_if<
    folly::dynamicconverter_detail::is_map<C>::value>::type> {
  static folly::dynamic construct(const C& x) {
    folly::dynamic d = folly::dynamic::object;
    for (auto& pair : x) {
      d.insert(folly::to<std::string>(pair.first), ToJsonDynamic(pair.second));
    }
    return d;
  }
};

// other ranges
template<typename C>
struct JsonDynamicConstructor<C,
  typename std::enable_if<
    !folly::dynamicconverter_detail::is_map<C>::value &&
    !std::is_constructible<folly::StringPiece, const C&>::value &&
    folly::dynamicconverter_detail::is_range<C>::value>::type> {
  static folly::dynamic construct(const C& x) {
    folly::dynamic d = folly::dynamic::array;
    for (auto& item : x) {
      d.push_back(ToJsonDynamic(item));
    }
    return d;
  }
};

// pair
template<typename A, typename B>
struct JsonDynamicConstructor<std::pair<A, B>, void> {
  static folly::dynamic construct(const std::pair<A, B>& x) {
    return folly::dynamic::object(folly::to<std::string>(x.first), ToJsonDynamic(x.second));
  }
};

template<std::size_t I = 0, typename Tuple>
typename std::enable_if<
    I == std::tuple_size<Tuple>::value
  >::type TupleToDynamic(const Tuple& t, folly::dynamic& d) {
}

template<std::size_t I = 0, typename Tuple>
typename std::enable_if<
    I < std::tuple_size<Tuple>::value
  >::type TupleToDynamic(const Tuple& t, folly::dynamic& d) {
  
  d.update(ToJsonDynamic(std::get<I>(t)));
  TupleToDynamic<I + 1>(t, d);
}


// user_class
template<typename C>
struct JsonDynamicConstructor<C,
typename std::enable_if<nebula::is_user_class<C>::value>::type> {
  static folly::dynamic construct(const C& c) {
    return ToJsonDynamic(((C&)c).Meta());
  }
};

// tuple
template<typename C>
struct JsonDynamicConstructor<C,
typename std::enable_if<nebula::is_tuple<C>::value>::type> {
  static folly::dynamic construct(const C& c) {
    folly::dynamic d = folly::dynamic::object();
    TupleToDynamic(c, d);
    return d;
  }
};

///////////////////////////////////////////////////////////////////////////////
// implementation

template <typename T>
T JsonConvertTo(const folly::dynamic& d) {
  return JsonDynamicConverter<typename std::remove_cv<T>::type>::convert(d);
}

template<typename T>
folly::dynamic ToJsonDynamic(const T& x) {
  return JsonDynamicConstructor<typename std::remove_cv<T>::type>::construct(x);
}

// }

#endif // NEBULA_BASE_DYNAMIC_CONVERTER_H_

