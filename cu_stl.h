#ifndef _CLASS_UTILITY_STL_H_
#define _CLASS_UTILITY_STL_H_

#define USE_MM_ALLOCATOR

#ifdef USE_MM_ALLOCATOR
#include <memmgr/Allocator.h>
#else
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#endif // USE_MM_ALLOCATOR

#ifdef USE_MM_ALLOCATOR
	#define CU_STR  mm::AllocString
	#define CU_VEC  mm::AllocVector
	#define CU_LIST mm::AllocList
	#define CU_SET  mm::AllocSet
	#define CU_MAP  mm::AllocMap
	#define CU_UNORDERED_MAP mm::AllocUnorderedMap
#else
	#define CU_STR  std::string
	#define CU_VEC  std::vector
	#define CU_LIST std::list
	#define CU_SET  std::set
	#define CU_MAP  std::map
	#define CU_UNORDERED_MAP std::unordered_map
#endif // USE_MM_ALLOCATOR

#endif // _CLASS_UTILITY_STL_H_