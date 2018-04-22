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

#include "nebula/base/testing/testing_util.h"

#include <iostream>
#include "nebula/base/json/json.h"

using namespace nebula;

struct Person {
  Person() {}
  Person(std::string n, int a) : name(n), age(a) {}
  std::string name;
  int age;
  
  META(name, age);
};

struct Token {
  Token() {}
  
  int id;
  std::string name;
};

namespace folly {
  template <> struct DynamicConverter<Person> {
    static Person convert(const dynamic& d) {
      std::string name = convertTo<std::string>(d["name"]);
      int age = convertTo<int>(d["age"]);
      return Person(name, age);  }
  };
  
  template <> struct DynamicConstructor<Person> {
    static dynamic construct(const Person& x) {
      return dynamic::object("name", x.name)("age", x.age);
    }
  };
  
  //template <> struct DynamicConstructor<Token> {
  //  static dynamic construct(const Token& x) {
  //    return dynamic::object(x.id, x.name)("age", x.age);
  //  }
  //};
  
}

// int main(int argc, char* argv[]) {
void JsonTest() {
  Person person = {"benqi", 42};
  //auto t = person.Meta();
  
  auto d1 = Marshal(person);
  std::cout << folly::toJson(d1) << std::endl;
  
  
  //  std::vector<std::pair<int, int>> v;
  //  v.push_back(std::make_pair(1, 1));
  //  v.push_back(std::make_pair(2, 2));
  //  v.push_back(std::make_pair(3, 3));
  //  v.push_back(std::make_pair(4, 4));
  //
  //  auto d1 = ToJsonDynamic(v);
  //  std::cout << folly::toJson(d1) << std::endl;
  //
  ///*
  //  std::map<std::string, std::string> m;
  //  m["a"] = "aa";
  //  m["b"] = "bb";
  //  m["c"] = "cc";
  // */
  
  folly::dynamic d = folly::dynamic::object(1,1)(2,2)(3,3);
  
  typedef std::map<int, int> IntIntMap;
  
  auto a222 = Unmarshal<IntIntMap>(d);
  
  for (auto v : a222) {
    std::cout << v.first << " ==> " << v.second << std::endl;
  }
  //  m[1] = 1; // {"a", 1};
  //  m[2] = 2; // {"b", 2};
  //  m[3] = 3; // {"c", 3};
  
  //
  //  auto d2 = ToJsonDynamic(m);
  //  
  //  std::cout << folly::toJson(d2) << std::endl;
}

// static TestingFuncManager g_testing_json(JsonTest);

