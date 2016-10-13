#include <iostream>
#include "EricNumHash.h"

// hash homework
// author : EriCZZZZ
// time : 2016-10-12 02:17:21

int main(void) {
	PHead* hashArray = initHashArray();
	int source[] = { 13, 27, 61, 25, 33, 39, 41, 83, 45, 77, 35, 19, 66, 49, 56, 22, 50, 71, 88, 28 };

	int i = 0;
	while (i < sizeof(source) / sizeof(int)) {
		insert2HashArray(hashArray, source[i++]);
	}

	i = 0;
	while (i < sizeof(source) / sizeof(int)) {
		std::cout << source[i] << " : " << isNumExist(hashArray, source[i]) << std::endl;
		i++;
	}
	// to check is find work.
	i = 0;
	while (i < 100) {
		std::cout << i << " : " << isNumExist(hashArray, i) << std::endl;
		i++;
	}

	freeHashArray(hashArray);

	system("pause");
	return 0;
}