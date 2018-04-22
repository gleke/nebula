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

#ifndef NEBULA_BASE_LINKED_MAP_H_
#define NEBULA_BASE_LINKED_MAP_H_

#include <list>
#include <set>
#include <utility>

namespace nebula {

template < typename KeyType, typename MappedType,
typename Comp = std::less< KeyType > >
struct linked_map {

	typedef KeyType key_type;
	typedef MappedType mapped_type;
	typedef std::pair< const key_type, mapped_type > value_type;

private:

	typedef std::list< value_type > list_type;
	typedef typename list_type::iterator list_iterator;

	struct compare_keys {

		Comp the_order;

		compare_keys ( Comp o )
			: the_order ( o )
		{}

		bool operator() ( list_iterator lhs, list_iterator rhs ) const {
			return ( the_order( lhs->first, rhs->first ) );
		}

	};

	typedef std::set< list_iterator, compare_keys > set_type;
	typedef typename set_type::iterator set_iterator;

	list_type the_list;
	set_type the_set;

public:

	typedef list_iterator iterator;
	typedef typename set_type::size_type size_type;

	linked_map ( Comp o = Comp() )
		: the_list()
		, the_set ( compare_keys( o ) )
	{}

	iterator find ( key_type const & key ) {
		value_type dummy_value ( key, mapped_type() );
		list_type dummy_list;
		dummy_list.push_back( dummy_value );
		set_iterator where = the_set.find( dummy_list.begin() );
		if ( where == the_set.end() ) {
			return ( the_list.end() );
		}
		return ( *where );
	}

	iterator insert ( value_type const & value ) {
		list_type dummy;
		dummy.push_back( value );
		set_iterator where = the_set.find( dummy.begin() );
		if ( where == the_set.end() ) {
			the_list.push_back( value );
			list_iterator pos = the_list.end();
			-- pos;
			the_set.insert( pos );
			return ( pos );
		} else {
			(*where)->second = value.second;
			return ( *where );
		}
	}

	iterator erase ( iterator where ) {
		the_set.erase( where );
		return ( the_list.erase( where ) );
	}

	iterator begin ( void ) {
		return ( the_list.begin() );
	}

	iterator end ( void ) {
		return ( the_list.end() );
	}

	size_type size ( void ) const {
		return ( the_set.size() );
	}

	mapped_type & operator[] ( key_type const & key ) {
		iterator pos = insert( std::make_pair( key, mapped_type() ) );
		return ( pos->second );
	}

	bool empty ( void ) const {
		return ( the_set.size()==0 );
	}

};

}

#if 0
#include <iostream>

int main ( void ) {
	linked_map< int, int > lm;
	lm[4] = 3;
	lm[2] = 1;
	lm[5] = 2;
	lm[2] = 0;
	for ( linked_map<int,int>::iterator iter = lm.begin();
		iter != lm.end(); ++iter ) {
			std::cout << iter->first << " --> " << iter->second << '\n';
	}
}
#endif


#endif // end of file

