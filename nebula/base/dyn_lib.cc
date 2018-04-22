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

#include "nebula/base/dyn_lib.h"

#ifdef WIN32
//#  define WIN32_LEAN_AND_MEAN
//#  define NOMINMAX // required to stop windows.h messing up std::min
#  include <windows.h>
#else
#include <dlfcn.h>
#endif

#include "nebula/base/exception.h"


namespace nebula {
  
//-----------------------------------------------------------------------
DynLib::DynLib( const std::string& name ) {
  name_ = name;
  m_hInst = NULL;
}

//-----------------------------------------------------------------------
DynLib::~DynLib() {
}

//-----------------------------------------------------------------------
void DynLib::load() {
  std::string name = name_;
#if defined(OS_MACOSX)
  // dlopen() does not add .so to the filename, like windows does for .dll
  if (name.substr(name.length() - 6, 6) != ".dylib")
    name += ".dylib";
#elif defined(OS_LINUX)
  // dlopen() does not add .so to the filename, like windows does for .dll
  if (name.substr(name.length() - 3, 3) != ".so")
    name += ".so";
#endif
  
  m_hInst = (DYNLIB_HANDLE)DYNLIB_LOAD( name.c_str() );
  
  if( !m_hInst ) {
    throw InternalErrorException(
                                 "Could not load dynamic library " + name_ +
                                 ".  System Error: " + dynlibError()
                                 );
  }
}

//-----------------------------------------------------------------------
void DynLib::unload() {
  if( DYNLIB_UNLOAD( m_hInst ) ) {
    throw InternalErrorException(
                                 "Could not unload dynamic library " + name_ +
                                 ".  System Error: " + dynlibError()
                                 );
  }
  
}

//-----------------------------------------------------------------------
void* DynLib::getSymbol( const std::string& strName ) const throw() {
  return (void*)DYNLIB_GETSYM( m_hInst, strName.c_str() );
}

//-----------------------------------------------------------------------
std::string DynLib::dynlibError( void ) {
#ifdef WIN32
  LPVOID lpMsgBuf;
  FormatMessage(
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
                GetLastError(), 
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
                (LPTSTR) &lpMsgBuf, 
                0, 
                NULL 
               ); 
  std::string ret = (char*)lpMsgBuf;
  // Free the buffer.
  LocalFree( lpMsgBuf );
  return ret;
#else
  return std::string(dlerror());
#endif
}
  
}
