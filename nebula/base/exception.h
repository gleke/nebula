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

#ifndef NEBULA_BASE_EXCEPTION_H_
#define NEBULA_BASE_EXCEPTION_H_

#include <exception>
#include <string>

#include <glog/logging.h>
#include <folly/String.h>

namespace nebula {

/** The class Exception and its subclasses indicate conditions that a
 reasonable application might want to catch.
 */
class Exception : public std::exception {
public:
  Exception()
    : what_("Exception") {
  }
  
  Exception(const std::string& msg)
    : what_(msg) {
  }
  
  virtual ~Exception() throw() {}
  
  virtual const char* what() const throw() {
    return what_.c_str();
  }
  
protected:
  folly::fbstring what_;
}; // class Exception


#define DECLARE_EXCEPTION(exp_class) \
class exp_class : public Exception { \
public: \
  exp_class() : Exception(#exp_class){} \
  exp_class(const std::string& msg) : Exception(msg) {} \
  exp_class(const std::string& prefix, const std::string& msg) : Exception(prefix + msg) {} \
  virtual ~exp_class() throw() {} \
};
  
#define DECLARE_EXCEPTION2(exp_class, base_exp_class) \
class exp_class : public base_exp_class { \
public: \
  exp_class() : base_exp_class(#exp_class){} \
  exp_class(const std::string& msg) : base_exp_class(msg) {} \
  exp_class(const std::string& prefix, const std::string& msg) : base_exp_class(prefix + msg) {} \
  virtual ~exp_class() throw() {} \
};
  
  
// #define  Throwable Exception

/** RuntimeException is the parent class of those exceptions that can be
 thrown during the normal operation of the process.
 */
DECLARE_EXCEPTION(RuntimeException);

/** Thrown when an application attempts to use NULL in a case where an
 object is required.
 */
DECLARE_EXCEPTION(NullPointerException);

/** Thrown to indicate that a method has been passed
 an illegal or inappropriate argument.*/
DECLARE_EXCEPTION(IllegalArgumentException);

/** Signals that an I/O exception of some sort has occurred. This class
 is the general class of exceptions produced by failed or interrupted
 I/O operations.
 */
DECLARE_EXCEPTION(IOException);

DECLARE_EXCEPTION(MissingResourceException);

DECLARE_EXCEPTION(MutexException);

DECLARE_EXCEPTION(InterruptedException);

DECLARE_EXCEPTION(ThreadException);

DECLARE_EXCEPTION(FileNotFoundException);

DECLARE_EXCEPTION(TranscoderException);

DECLARE_EXCEPTION(IllegalMonitorStateException);

/**
 Thrown when an application tries to create an instance of a class using
 the newInstance method in class Class, but the specified class object
 cannot be instantiated because it is an interface or is an abstract class.
 */
DECLARE_EXCEPTION(InstantiationException);

/**
 Thrown when an application tries to load in a class through its
 string name but no definition for the class with the specified name
 could be found.
 */
DECLARE_EXCEPTION(ClassNotFoundException);

DECLARE_EXCEPTION(NoSuchElementException);

DECLARE_EXCEPTION(IllegalStateException);

DECLARE_EXCEPTION(ArrayIndexOutOfBoundsException);

DECLARE_EXCEPTION(UnsupportedOperationException);

DECLARE_EXCEPTION(EOFException);

DECLARE_EXCEPTION(AssertionError);

DECLARE_EXCEPTION(InternalErrorException);

} // namespace base

//////////////////////////////////////////////////////////////////////////////////////////
#define THROW_EXCEPTION(exception, msg, ...) \
do { \
  std::string buf = folly::stringPrintf(msg, ##__VA_ARGS__); \
  LOG(ERROR) << "[EXCEPTION]: " << buf; \
  throw exception(buf); \
} while (0)

#define THROW_RET_EXCEPTION(e) throw e;

#define FINALLY(x) catch(...){ x; throw; } x //note: code x is not run if return is called

#endif // BASE_EXCEPTION_H_


