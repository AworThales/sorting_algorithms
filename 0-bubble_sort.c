#include "sort.h"

/**
 * bubble_sort - sorts array of integers in the ascending order using a bubble
 * sort algorithm
 * @array: array of the integers to be sorted
 * @size: amount of the elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t t, s;
	int tempral;
	bool swapped = true;

	if (!array || size < 2)
		return;

	s = size;
	while (swapped)
	{
		swapped = false;
		for (t = 1; t < s; t++)
		{
			if (array[t - 1] > array[t])
			{
				tempral = array[t - 1];
				array[t - 1] = array[t];
				array[t] = tempral;
				swapped = true;
				print_array(array, size);
			}
		}
		/* optimize by the logically elinating final swap from last loop */
		s--;
	}
}
