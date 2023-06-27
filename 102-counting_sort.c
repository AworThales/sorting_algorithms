#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts array of integers in ascending order using a
 * counting sort algorithm
 * @array: array of the integers to be sorted
 * @size: amount of the elements in array
 */
void counting_sort(int *array, size_t size)
{
	int t, summ, maxi;
	int *begin, *output;

	if (!array || size < 2)
		return;

	maxi = array[0];
	for (t = 0; t < (int)size; t++)
	{
		if (array[t] > maxi)
			maxi = array[t];
	}

	begin = calloc((maxi + 1), sizeof(int));
	if (!begin)
		return;
	for (t = 0; t < (int)size; t++)
		begin[array[t]]++;

	for (t = 0, summ = 0; t < maxi + 1; t++)
	{
		summ = begin[t] + summ;
		begin[t] = summ;
	}
	print_array(begin, maxi + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (t = 0; t < (int)size; t++)
	{
		output[begin[array[t]] - 1] = array[t];
		begin[array[t]]--; /* needed to  the handle identical values */
	}

	for (t = 0; t < (int)size; t++)
		array[t] = output[t];
	free(begin);
	free(output);
}
