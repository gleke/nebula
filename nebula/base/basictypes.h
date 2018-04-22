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

#ifndef NEBULA_BASE_BASICTYPES_H_
#define NEBULA_BASE_BASICTYPES_H_

#include <string>
#include <vector>
#include <map>
#include <set>

#include <stddef.h>  // For size_t.

// Put this in the declarations for a class to be uncopyable.
#define DISALLOW_COPY(TypeName) \
TypeName(const TypeName&) = delete

// Put this in the declarations for a class to be unassignable.
#define DISALLOW_ASSIGN(TypeName) \
void operator=(const TypeName&) = delete

// A macro to disallow the copy constructor and operator= functions.
// This should be used in the private: declarations for a class.
#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&) = delete;      \
void operator=(const TypeName&) = delete
#endif

// A macro to disallow all the implicit constructors, namely the
// default constructor, copy constructor and operator= functions.
//
// This should be used in the private: declarations for a class
// that wants to prevent anyone from instantiating it. This is
// especially useful for classes containing only static methods.
#ifndef DISALLOW_IMPLICIT_CONSTRUCTORS
#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
TypeName() = delete;                           \
DISALLOW_COPY_AND_ASSIGN(TypeName)
#endif

// The arraysize(arr) macro returns the # of elements in an array arr.  The
// expression is a compile-time constant, and therefore can be used in defining
// new arrays, for example.  If you use arraysize on a pointer by mistake, you
// will get a compile-time error.  For the technical details, refer to
// http://blogs.msdn.com/b/the1/archive/2004/05/07/128242.aspx.

// This template function declaration is used in defining arraysize.
// Note that the function doesn't need an implementation, as we only
// use its type.
template <typename T, size_t N> char (&ArraySizeHelper(T (&array)[N]))[N];
#define arraysize(array) (sizeof(ArraySizeHelper(array)))

namespace nebula {

inline uint64_t MakeInt64(uint32_t low, uint32_t high) {
  return ((uint64_t)(((uint32_t)(low)) | ((uint64_t)((uint32_t)(high))) << 32));
}

inline uint32_t GetLowInt32ByInt64(uint64_t v) {
  return v & 0xFFFFFFFF;
}

inline uint32_t GetHighInt32ByInt64(uint64_t v) {
  return (v >> 32) & 0xFFFFFFFF;
}

inline uint32_t MakeInt32(uint16_t low, uint16_t high) {
  return ((uint32_t)(((uint16_t)(low) << 16) | ((uint32_t)((uint16_t)(high)))));
}

inline uint16_t GetLowInt16ByInt32(uint32_t v) {
  return (v >> 16) & 0xFFFF;
}

inline uint16_t GetHighInt16ByInt32(uint32_t v) {
  return v & 0xFFFF;
}

} // end namespace nebula

#endif  // NEBULA_BASE_BASICTYPES_H_

