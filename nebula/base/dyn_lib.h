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

#ifndef NEBULA_BASE_DYN_LIB_H_
#define NEBULA_BASE_DYN_LIB_H_

#include <string>

#ifdef WIN32
#    define DYNLIB_HANDLE hInstance
#    define DYNLIB_LOAD( a ) LoadLibraryExA( a, NULL, LOAD_WITH_ALTERED_SEARCH_PATH )
#    define DYNLIB_GETSYM( a, b ) GetProcAddress( a, b )
#    define DYNLIB_UNLOAD( a ) !FreeLibrary( a )

struct HINSTANCE__;
typedef struct HINSTANCE__* hInstance;

#else
#    define DYNLIB_HANDLE void*
#    define DYNLIB_LOAD( a ) dlopen( a, RTLD_LAZY | RTLD_GLOBAL)
#    define DYNLIB_GETSYM( a, b ) dlsym( a, b )
#    define DYNLIB_UNLOAD( a ) dlclose( a )

#endif

namespace nebula {

/** Resource holding data about a dynamic library.
    @remarks
        This class holds the data required to get symbols from
        libraries loaded at run-time (i.e. from DLL's for so's)
    @author
        Adrian Cearn鉼 (cearny@cearny.ro)
    @since
        27 January 2002
    @see
        Resource
*/
class DynLib {
public:
  /** Default constructor - used by DynLibManager.
      @warning
         Do not call directly
  */
  DynLib( const std::string& name );

  /** Default destructor.
  */
  ~DynLib();

  /** Load the library
  */
  void load();
  /** Unload the library
  */
  void unload();
  /// Get the name of the library
  const std::string& getName(void) const { 
    return name_; 
  }

  /**
      Returns the address of the given symbol from the loaded library.
      @param
          strName The name of the symbol to search for
      @returns
          If the function succeeds, the returned value is a handle to
          the symbol.
      @par
          If the function fails, the returned value is <b>NULL</b>.

   */
  void* getSymbol( const std::string& strName ) const throw();

protected:
  std::string name_;
  /// Gets the last loading error
  std::string dynlibError(void);

  /// Handle to the loaded library.
  DYNLIB_HANDLE m_hInst;
};

}

#endif

