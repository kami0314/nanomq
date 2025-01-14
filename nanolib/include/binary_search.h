# ifndef BINARY_SEARCH_H
# define BINARY_SEARCH_H

#include "cvector.h"
/**
 * @brief binary_search - A iterative binary search function.
 * @param vec - normally vec is an dynamic array
 * @param l - it is the left boundry of the vec
 * @param index - index is the result we search
 * @param e - e contain message we want to search
 * @param cmp - cmp is a compare method
 * @return true or false, if we find or not
 */
static bool
binary_search(
    void **vec, int l, int *index, void *e, int (*cmp)(void *x, void *y))
{

	int r = cvector_size(vec) - 1;
	int m = 0;

	// if we do not find the element
	// vec = [0, 1, 3, 4], e = 2 ,
	// m will be 2, index = 2 ok
	// vec = [0, 1, 2, 4], e = 3 ,
	// m will be 2, index = 2 error,
	// index = 2 + add(1) ok
	int add = 0;

	// log_info("l: %d", l);
	// log_info("r: %d", r);

	while (l <= r) {
		m = l + (r - l) / 2;

		// Check if x is present at mid
		if (cmp(vec[m], e) == 0) {
			*index = m;
			return true;
		}
		// log_info("m: %d", m);

		// If x greater, ignore left half
		if (cmp(vec[m], e) < 0) {
			l   = m + 1;
			add = 1;

			// If x is smaller, ignore right half
		} else {
			r   = m - 1;
			add = 0;
		}
	}
	// log_info("m: %d", m);

	// if we reach here, then element was
	// not present
	*index = m + add;
	return false;
}

#endif
