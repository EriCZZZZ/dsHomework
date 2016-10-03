#include <iostream>
#include <cstdlib>
#include <ctime>
#include "EricSort.h"

#include "EricUtil.h"

#define count 10000

int main(void) {
	srand(clock());
	int target[count];

	for (int i = 0; i < count; i++) {
		target[i] = rand();
	}

	std::cout << "start: " << clock() << std::endl;

	int time = clock();

	eric::qsort(target, 0, count - 1);
	
	std::cout << "qsort: " << clock() - time << std::endl;

	time = clock();

	eric::msort(target, 0, count - 1);

	std::cout << "msort: " << clock() - time << std::endl;

	for (int i = 0; i < count; i++) {
		std::cout << target[i] << std::endl;
	}
	/*for (int i = 0; i < count; i++) {
		for (int j = count - 1; j > i; j--) {
			if (target[j] < target[j - 1]) {
				int temp = target[j];
				target[j] = target[j - 1];
				target[j - 1] = temp;
			}
		}
	}*/
	system("pause");
	return 0;
}