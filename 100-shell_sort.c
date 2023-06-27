#include "sort.h"

/**
 * shell_sort - sorts array of integers in ascending order using a shell
 * sort algorithm, with margin sizes determined by a decreasing Knuth seqeuence
 * @array: array of the integers to be sorted
 * @size: amount of the elements in array
 */
void shell_sort(int *array, size_t size)
{
	int t, s, margin, w, Knuth_maxs, tempral;

	if (!array || size < 2)
		return;

	w = (int)size;
	for (margin = 1; margin < w; margin = (margin * 3) + 1)
	{
		Knuth_maxs = margin;
	}
/* Start with alargest Knuth seq value less than w as margin, */
/* and work down sequence to a margin of 1 */
	for (margin = Knuth_maxs; margin > 0; margin = (margin - 1) / 3)
	{
		/* Do the gapped insertion sort for this margin size. */
		for (t = margin; t < w; t++)
		{
			/* add array[t] to the margin sorted elements; */
			/* save array[t] in the tempral in preparation to overwrite */
			tempral = array[t];
			/* shift earlier margin-sorted elements up until the */
			/* correct location for array[t] is found */
			for (s = t; s >= margin && array[s - margin] > tempral; s -= margin)
			{
				array[s] = array[s - margin];
			}
/* tempral original array[t]) to its correct location */
			array[s] = tempral;
		}
		print_array(array, size);
	}
}
