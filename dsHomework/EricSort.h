#ifndef ERIC_SORT_H
#define ERIC_SORT_H

namespace eric {
	// quick sort
	void qsort(int* target, int indexStart, int indexEnd);
	// merge sort
	void msort(int* target, int indexStart, int indexEnd);
}

#endif