#include "EricHeapSort.h"
#include <cstdlib>

void eric::initHeap(HeapInfo* heap, int* src, int size) {
	// add a empty value
	heap->src.push_back(-1);
	// copy array
	for (int i = 0; i < size; i++) {
		heap->src.push_back(src[i]);
	}
	// init heap
	for (int i = size / 2; i > 0; i--) {
		int index = i;
		while (index < heap->src.size()) {
			int adjustResult = adjustNode(heap, index);
			if (HEAP_UN_CHANGED == adjustResult) {
				break;
			}
			switch (adjustResult)
			{
			case HEAP_CHANGED_LEFT:
				index = index * 2;
				break;
			case HEAP_CHANGED_RIGHT:
				index = index * 2 + 1;
				break;
			default:
				break;
			}
		}
	}
}

void eric::heapInsert(HeapInfo* heap, int value) {
	heap->src.push_back(value);
	int index = heap->src.size() - 1;
	while ((HEAP_UN_CHANGED != eric::adjustNode(heap, (index = index / 2))));
}

int eric::heapPop(HeapInfo* heap) {
	if (heap->src.size() == 1) {
		return -1;
	}
	int result = heap->src.at(1);
	heap->src[1] = heap->src[heap->src.size() - 1];
	heap->src.pop_back();
	int index = 1;
	while (index < heap->src.size()) {
		int adjustResult = adjustNode(heap, index);
		if (HEAP_UN_CHANGED == adjustResult) {
			break;
		}
		switch (adjustResult)
		{
		case HEAP_CHANGED_LEFT:
			index = index * 2;
			break;
		case HEAP_CHANGED_RIGHT:
			index = index * 2 + 1;
			break;
		default:
			break;
		}
	}
	return result;
}

int eric::adjustNode(HeapInfo* target, int indexOfFather) {
	if (indexOfFather < 1) {
		return HEAP_UN_CHANGED;
	}
	if (target->src.size() - 1 >= indexOfFather * 2 + 1) {
		if (target->src[2 * indexOfFather] < target->src[2 * indexOfFather + 1]) {
			if (target->src[indexOfFather] > target->src[2 * indexOfFather]) {
				int temp = target->src[indexOfFather];
				target->src[indexOfFather] = target->src[2 * indexOfFather];
				target->src[2 * indexOfFather] = temp;
				return HEAP_CHANGED_LEFT;
			}
		}
		else {
			if (target->src[indexOfFather] > target->src[2 * indexOfFather + 1]) {
				int temp = target->src[indexOfFather];
				target->src[indexOfFather] = target->src[2 * indexOfFather + 1];
				target->src[2 * indexOfFather + 1] = temp;
				return HEAP_CHANGED_RIGHT;
			}
		}
	}
	else if (target->src.size() - 1 == indexOfFather * 2) {
		if (target->src[indexOfFather] > target->src[2 * indexOfFather]) {
			int temp = target->src[indexOfFather];
			target->src[indexOfFather] = target->src[2 * indexOfFather];
			target->src[2 * indexOfFather] = temp;
			return HEAP_CHANGED_LEFT;
		}
	}
	return HEAP_UN_CHANGED;
}