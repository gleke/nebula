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

#include "nebula/base/dyn_lib_manager.h"
#include "nebula/base/dyn_lib.h"

static folly::Singleton<nebula::DynLibManager> g_dyn_lib_manager;

namespace nebula {

//-----------------------------------------------------------------------
DynLibManager::DynLibManager() {
}

std::shared_ptr<DynLibManager> DynLibManager::GetInstance() {
  return folly::Singleton<DynLibManager>::try_get();
}

//-----------------------------------------------------------------------
DynLib* DynLibManager::load( const std::string& filename) {
	DynLibList::iterator i = mLibList.find(filename);
	if (i != mLibList.end()) {
		return i->second;
	} else {
        DynLib* pLib = new DynLib(filename);
		pLib->load();        
    	mLibList[filename] = pLib;
        return pLib;
	}
}

//-----------------------------------------------------------------------
void DynLibManager::unload(DynLib* lib) {
	DynLibList::iterator i = mLibList.find(lib->getName());
	if (i != mLibList.end()) {
		mLibList.erase(i);
	}
	lib->unload();
	delete lib;
}

//-----------------------------------------------------------------------
DynLibManager::~DynLibManager() {
    // Unload & delete resources in turn
    for( DynLibList::iterator it = mLibList.begin(); it != mLibList.end(); ++it ) {
        it->second->unload();
        delete it->second;
    }

    // Empty the list
    mLibList.clear();
}

}


