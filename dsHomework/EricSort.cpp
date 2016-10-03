#include "EricSort.h"
#include <cmath>

void eric::qsort(int* target, int indexStart, int indexEnd) {
	int indexOriginStart = indexStart;
	int indexOriginEnd = indexEnd;

	int key = target[indexStart];
	// flag == 0 --> end=>start | flag == 1 --> start=>end
	bool flag = 0;
	while (indexStart < indexEnd) {
		if (0 == flag) {
			if (target[indexEnd] < key) {
				int temp = target[indexEnd];
				target[indexEnd] = target[indexStart];
				target[indexStart] = temp;
				flag = 1;
			}
			else {
				indexEnd--;
			}
		}
		else {
			if (target[indexStart] > key) {
				int temp = target[indexEnd];
				target[indexEnd] = target[indexStart];
				target[indexStart] = temp;
				flag = 0;
			}
			else {
				indexStart++;
			}
		}
	}

	if (abs(indexOriginStart - indexStart) > 0) {
		eric::qsort(target, indexOriginStart, indexStart - 1);
	}
	if (abs(indexOriginEnd - indexEnd) > 0) {
		eric::qsort(target, indexEnd + 1, indexOriginEnd);
	}
	return;
}