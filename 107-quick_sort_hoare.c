#include "sort.h"

/**
 * hoare_partition - Hoare partition scheme using rightmost index as pivoter;
 * other pivoter implementations exist, with some with greater efficiency: see
 * peudocode below function defs for middle or low pivoter schema
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int t, s, pivoter, tempral;

	pivoter = array[high];
	t = low - 1;
	s = high + 1;
	while (true)
	{
		do {
			t++;
		} while (array[t] < pivoter);
		do {
			s--;
		} while (array[s] > pivoter);
		if (t == s)
			return (s - 1);
		else if (t > s)
			return (s);
		tempral = array[t];
		array[t] = array[s];
		array[s] = tempral;
		print_array(array, size);
	}
}

/**
 * hoare_quicksort - recursively sorts array of integers by separating into two
 * partitions, using Hoare quick sort
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 */
void hoare_quicksort(int *array, size_t low, size_t high, size_t size)
{
	size_t bordered;

	if (low < high)
	{
		bordered = hoare_partition(array, low, high, size);
		hoare_quicksort(array, low, bordered, size);
		hoare_quicksort(array, bordered + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order using a quick
 * sort, Hoare partition scheme alogrithm
 * @array: array of values to be printed
 * @size: number of elements in array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort(array, 0, size - 1, size);
}

/*
 * Lomuto pseudo:
 *
 * algorithm quicksort(A, lo, hi) is
 *   if lo < hi then
 *       p := partition(A, lo, hi)
 *       quicksort(A, lo, p - 1)
 *       quicksort(A, p + 1, hi)
 *
 * algorithm partition(A, lo, hi) is
 *   pivoter := A[hi]
 *   t := lo
 *   for s := lo to hi do
 *       if A[s] < pivoter then
 *           swap A[t] with A[s]
 *           t := t + 1
 *   swap A[t] with A[hi]
 *   return t
 *
 * Hoare pseudo:
 *
 * algorithm quicksort(A, lo, hi) is
 *   if lo < hi then
 *       partition_border := partition(A, lo, hi)
 *       quicksort(A, lo, partition_border)
 *       quicksort(A, partition_border + 1, hi)
 *
 * (using middle pivoter):
 *
 * algorithm partition(A, lo, hi) is
 *    pivoter := A[(hi + lo) / 2] // depends on rounding towards 0, as in C
 *   t := lo
 *   s := hi
 *   loop forever
 *       while A[t] < pivoter
 *           t := t + 1
 *       while A[s] > pivoter
 *           s := s - 1
 *       if t  s then
 *           return s
 *       swap A[t] with A[s]
 *       t := t + 1
 *       s := s - 1
 *
 * (using first pivoter):
 *
 * algorithm partition(A, lo, hi) is
 *   pivoter := A[lo]
 *   t := lo - 1
 *   s := hi + 1
 *   loop forever
 *       do
 *           t := t + 1
 *       while A[t] < pivoter
 *	do
 *           s := s - 1
 *       while A[s] > pivoter
 *       if t >= s then
 *           return s
 *       swap A[t] with A[s]
 */

