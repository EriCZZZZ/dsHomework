#ifndef ERIC_SORT
#define ERIC_SORT

namespace eric {
	// quick sort
	void qsort(int* target, int indexStart, int indexEnd);
	// merge sort
	void msort(int* target, int indexStart, int indexEnd);
}

#endif