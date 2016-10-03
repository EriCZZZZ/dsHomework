#include "EricSort.h"
#include "EricUtil.h"
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

void eric::msort(int* target, int indexStart, int indexEnd) {
	int length = indexEnd - indexStart + 1;
	if (length > 2) {
		eric::msort(target, indexStart, indexStart + (length - 2) / 2);
		eric::msort(target, indexStart + length / 2, indexEnd);
	}                       

	if (length < 2) {
		return;
	}
	// merge
	int* right = eric::copyArray(target, indexStart, indexStart + (length - 2) / 2);
	int* left = eric::copyArray(target, indexStart + length / 2, indexEnd);

	int lengthRight = (length - 2) / 2 + 1;
	int lengthLeft = indexEnd - (indexStart + length / 2) + 1;
	int countRight;
	int countLeft;
	int index;
	for (index = indexStart, countRight = 0, countLeft = 0; countRight < lengthRight && countLeft < lengthLeft; index++) {
		if (right[countRight] < left[countLeft]) {
			target[index] = right[countRight++];
		}
		else {
			target[index] = left[countLeft++];
		}
	}
	if (countRight < lengthRight) {
		while (countRight < lengthRight) {
			target[index++] = right[countRight++];
		}
	}
	else if (countLeft < lengthLeft) {
		while (countLeft < lengthLeft) {
			target[index++] = left[countLeft++];
		}
	}
}