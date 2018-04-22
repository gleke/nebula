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

#ifndef NEBULA_BASE_DYN_LIB_MANAGER_H_
#define NEBULA_BASE_DYN_LIB_MANAGER_H_

#include <string>
#include <map>
#include <folly/Singleton.h>

namespace nebula {

/** Manager for Dynamic-loading Libraries.
 @remarks
 This manager keeps a track of all the open dynamic-loading
 libraries, opens them and returns references to already-open
 libraries.
 */
class DynLib;
class DynLibManager {
public:
  static std::shared_ptr<DynLibManager> GetInstance();

  /** Loads the passed library.
   @param
   filename The name of the library. The extension can be omitted
   */
  DynLib* load(const std::string& filename);

  /** Unloads the passed library.
   @param
   filename The name of the library. The extension can be omitted
   */
  void unload(DynLib* lib);

protected:
  friend class folly::Singleton<DynLibManager>;

  /** Default constructor.
   @note
   <br>Should never be called as the singleton is automatically
   created during the creation of the Root object.
   @see
   Root::Root
   */
  DynLibManager();

  /** Default destructor.
   @see
   Root::~Root
   */
  virtual ~DynLibManager();

  typedef std::map<std::string, DynLib*> DynLibList;
  DynLibList mLibList;
};

}

#endif

