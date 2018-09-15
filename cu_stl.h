#ifndef _CLASS_UTILITY_STL_H_
#define _CLASS_UTILITY_STL_H_

//#define USE_MM_ALLOCATOR

#ifdef USE_MM_ALLOCATOR
#include <memmgr/Allocator.h>
#else
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#endif // USE_MM_ALLOCATOR

#ifdef USE_MM_ALLOCATOR
	#define CU_STR           mm::AllocString
	#define CU_VEC           mm::AllocVector
	#define CU_DEQUE         mm::AllocDeque
	#define CU_LIST          mm::AllocList
	#define CU_SET           mm::AllocSet
	#define CU_MAP           mm::AllocMap
	#define CU_UNORDERED_MAP mm::AllocUnorderedMap

	#define CU_MAKE_SHARED   mm::allocate_shared
	#define CU_MAKE_UNIQUE   mm::allocate_unique
#else
	#define CU_STR           std::string
	#define CU_VEC           std::vector
	#define CU_DEQUE         std::deque
	#define CU_LIST          std::list
	#define CU_SET           std::set
	#define CU_MAP           std::map
	#define CU_UNORDERED_MAP std::unordered_map

	#define CU_MAKE_SHARED   std::make_shared
	#define CU_MAKE_UNIQUE   std::make_unique
#endif // USE_MM_ALLOCATOR

#endif // _CLASS_UTILITY_STL_H_