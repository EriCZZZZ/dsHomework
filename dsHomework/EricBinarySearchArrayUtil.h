#ifndef ERIC_BINARY_SEARCH_ARRAY_UTIL
#define ERIC_BINARY_SEARCH_ARRAY_UTIL

#define UN_EXIST -1
// binary search homework
// author : Eric
// date : 2016-10-17 11:32:13

namespace eric {
	// return index of target or -1 for unexist
	int find(int* source, int indexStart, int indexEnd, int target);
}
#endif