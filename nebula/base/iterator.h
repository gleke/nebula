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

#ifndef NEBULA_BASE_ITERATOR_H_
#define NEBULA_BASE_ITERATOR_H_

namespace nebula {

template<class ElemT>
class Iterator {
public:
  typedef ElemT element_type;

  Iterator() = default;
  virtual ~Iterator(void) = default;

	virtual void		Reset() = 0;
	virtual bool		HasNext() const = 0;
	virtual ElemT		Next() = 0;
	virtual size_t	Size() const= 0;
};

} 

#endif

