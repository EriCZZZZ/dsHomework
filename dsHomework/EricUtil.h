#ifndef ERIC_UTIL
#define ERIC_UTIL

namespace eric {
	// cp array 
	// @param target array pointer
	// @param _start index to start copy
	// @param _end index to end copy
	// @return a pointer to new array, return nullptr when error happen
	template <typename T>
	T* copyArray(T* target, int _start, int _end) {
		// check _start and _end
		int length = _end - _start + 1;
		if (length < 1) {
			return nullptr;
		}
		T* result = (T*)malloc(length * sizeof(T));
		for (int i = 0; i < length; i++) {
			result[i] = target[_start + i];
		}

		return result;
	}
}

#endif