#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - helper to the bitonic_merge, sorts contents of current
 * subarray
 * @up: if true, sort in ascending order, false, descending
 * @x: subarray in the current frame of recursion
 * @size: number of the elements in `x`
 */
void bitonic_compare(bool up, int *x, size_t size)
{
	size_t distribute, t;
	int tempral;

	distribute = size / 2;
	for (t = 0; t < distribute; t++)
	{
		if ((x[t] > x[t + distribute]) == up)
		{
			tempral = x[t];
			x[t] = x[t + distribute];
			x[t + distribute] = tempral;
		}
	}
}

/**
 * bitonic_merge - final recursive function of bitonic_sort, sorts subarrays
 * via bitonic_compare, and merges the sorted results
 * @up: if true, sort in the ascending order, false, descending
 * @x: subarray in the previous frame of recursion
 * @size: number of the elements in `x`
 * @orig_size: number of elements in source array being sorted
 */
void bitonic_merge(bool up, int *x, size_t size, size_t orig_size)
{
	int *initial, *final;

	if (size > 1)
	{
		initial = x;
		final = x + (size / 2);
		bitonic_compare(up, x, size);
		bitonic_merge(up, initial, size / 2, orig_size);
		bitonic_merge(up, final, size / 2, orig_size);
	}
}

/**
 * bitonic_sort_r - initial recursive engine of bitonic_sort, divides array
 * into a binary tree of the subarrays, and assigns sorting order.
 * @up: if true, sort in the ascending order, false, descending
 * @x: subarray in previous frame of recursion
 * @size: number of the elements in `x`
 * @orig_size: number of the elements in source array being sorted
 */
void bitonic_sort_r(bool up, int *x, size_t size, size_t orig_size)
{
	int *initial, *final;

	if (size <= 1)
		return;
	initial = x;
	final = x + (size / 2);
	printf("Merging [%lu/%lu] (%s):\n", size, orig_size,
	       (up ? "UP" : "DOWN"));
	print_array(x, size);
	bitonic_sort_r(true, initial, size / 2, orig_size);
	bitonic_sort_r(false, final, size / 2, orig_size);
	bitonic_merge(up, initial, size, orig_size);
	printf("Result [%lu/%lu] (%s):\n", size, orig_size,
	       (up ? "UP" : "DOWN"));
	print_array(x, size);
}

/**
 * bitonic_sort - sorts array of the integers in ascending order using a bitonic
 * sort alogrithm
 * @array: array of the values to be printed
 * @size: number of the elements in array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	bitonic_sort_r(true, array, size, size);
}
