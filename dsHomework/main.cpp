#include <iostream>
#include "EricHeapSort.h"
#include <random>
#include <ctime>

#define SOURCE_LENGTH 100000

int main() {
	srand(clock());
	//int source[SOURCE_LENGTH] = { 1, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3 };
	int* source = (int*)malloc(sizeof(int) * SOURCE_LENGTH);
	for (int i = 0; i < SOURCE_LENGTH; i++) {
		source[i] = rand();
	}
	eric::HeapInfo heap;
	eric::initHeap(&heap, source, SOURCE_LENGTH);
	std::cout << clock() << std::endl;
	for (int i = 0; i < SOURCE_LENGTH; i++) {
		//std::cout << eric::heapPop(&heap) << std::endl;
		eric::heapPop(&heap);
	}
	std::cout << clock() << std::endl;

	system("pause");

	return 0;
}