#include <iostream>
#include <cstdlib>
#include <ctime>
#include "EricSort.h"

#define count 100

int main(void) {
	srand(clock());
	int target[count];

	for (int i = 0; i < count; i++) {
		target[i] = rand();
	}
	eric::qsort(target, 0, count - 1);
	for (int i = 0; i < count; i++) {
		printf("%d ", target[i]);
	}
	system("pause");
	return 0;
}