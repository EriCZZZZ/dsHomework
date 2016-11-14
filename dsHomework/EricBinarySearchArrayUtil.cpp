#include "EricBinarySearchArrayUtil.h"

int eric::find(int* source, int indexStart, int indexEnd, int target) {
	if (indexStart > indexEnd) {
		return UN_EXIST;
	}
	else if (indexStart == indexEnd) {
		if (target == source[indexStart]) {
			return indexStart;
		}
		else {
			return UN_EXIST;
		}
	}
	else {
		int indexMiddle = (indexStart + indexEnd) / 2;
		if (target == source[indexMiddle]) {
			return indexMiddle;
		}
		else if (target < source[indexMiddle]) {
			return find(source, indexStart, indexMiddle, target);
		}
		else {
			return find(source, indexMiddle + 1, indexEnd, target);
		}
	}
}