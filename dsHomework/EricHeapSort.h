#ifndef ERIC_HEAP_SORT_H
#define ERIC_HEAP_SORT_H

#define HEAP_CHANGED_LEFT 2
#define HEAP_CHANGED_RIGHT 1
#define HEAP_UN_CHANGED 0

#include <vector>

namespace eric {
	typedef struct heapInfo {
		std::vector<int> src;
	} HeapInfo;
	void initHeap(HeapInfo* heap, int* src, int size);
	void heapInsert(HeapInfo* heap, int value);
	int heapPop(HeapInfo* heap);
	int adjustNode(HeapInfo* heap, int indexOfFather);
}
#endif
