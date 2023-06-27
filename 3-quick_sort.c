#include "sort.h"

/**
 * partition - scans a partition of an array of integers for values less than
 * pivots value, and swaps them with first value in partition, then swaps pivots
 * value with first value in partition
 * @array: array of integers to be sorted
 * @low: index in array that begins partition
 * @high: index in array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int t, s, pivots, tempral;

	pivots = array[high];
	t = low;
	for (s = low; s < high; s++)
	{
		if (array[s] < pivots)
		{
			tempral = array[t];
			array[t] = array[s];
			array[s] = tempral;
			if (array[t] != array[s])
				print_array(array, size);
			t++;
		}
	}
	tempral = array[t];
	array[t] = array[high];
	array[high] = tempral;
	if (array[t] != array[high])
		print_array(array, size);
	return (t);
}

/**
 * quicksort - recursively sorts the array of integers by separating into two
 * partitions, using Lomuto quick sort
 * @array: array of the integers to be sorted
 * @low: index in the array that begins partition
 * @high: index in the array that ends partition
 * @size: amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int w;

	if (low < high)
	{
		w = partition(array, low, high, size);
		quicksort(array, low, w - 1, size);
		quicksort(array, w + 1, high, size);
	}
}

/**
 * quick_sort - sorts array of integers in ascending order using a quick
 * sort algorithm, with Lomuto partition scheme
 * @array: array of the integers to be sorted
 * @size: amount of the elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
