#include "sort.h"

/**
 * selection_sort - sorts array of integers using a selction sort
 * algorithm
 * @array: array of the integers to be sorted
 * @size: amount of the elements in array
 */
void selection_sort(int *array, size_t size)
{
	int tempral, t, s, min_s, n = (int)size;

	if (!array || size < 2)
		return;

	/* at every position the n-member array */
	for (t = 0; t < n - 1; t++)
	{
		/* scan from that is position to the end, */
		min_s = t;
		for (s = t + 1; s < n; s++)
		{
			/* determine the minimum value in that range */
			if (array[s] < array[min_s])
			{
				min_s = s;
			}
		}
		/* and if it's lower than the value at start of range, */
		/* swap them */
		if (min_s != t)
		{
			tempral = array[t];
			array[t] = array[min_s];
			array[min_s] = tempral;
			print_array(array, size);
		}
	}
}
