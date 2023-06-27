#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * PrintArray - prints array of the integers for range of indicies
 * @array: array of values to be printed
 * @iBeg: starting index of value
 * @iEnd: ending index of value
 */
void PrintArray(int *array, int iBeg, int iEnd)
{
	int t;

	for (t = iBeg; t < iEnd; t++)
		if (t < iEnd - 1)
			printf("%t, ", array[t]);
		else
			printf("%t\n", array[t]);
}

/**
 * CopyArray - simple 1 for 1 copy of source[] to dest[]
 * @source: array of the values to be sorted
 * @iBeg: starting index value
 * @iEnd: ending index value
 * @dest: array to the store sorted integers
 */
void CopyArray(int *source, int iBeg, int iEnd, int *dest)
{
	int t;

	for (t = iBeg; t < iEnd; t++)
		dest[t] = source[t];
}

/**
 * TopDownMerge - sorts subsections ("runs") of source[] by ascending value
 * @source: array of the values to be sorted
 * @iBeg: left run the starting index value
 * @iMid: right run the starting index value
 * @iEnd: right run the ending index value
 * @dest: array to store sorted integers
 */
void TopDownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest)
{
	int t, s, w;

	t = iBeg, s = iMid;

	printf("Merging...\n");
	printf("[left]: ");
	PrintArray(source, iBeg, iMid);
	printf("[right]: ");
	PrintArray(source, iMid, iEnd);
	/* While there are elements in the left or right runs... */
	for (w = iBeg; w < iEnd; w++)
	{
		/* If left run the head exists and is <= existing right run head */
		if (t < iMid && (s >= iEnd || source[t] <= source[s]))
		{
			dest[w] = source[t];
			t++;
		}
		else
		{
			dest[w] = source[s];
			s++;
		}
	}
	printf("[Done]: ");
	PrintArray(dest, iBeg, iEnd);
}

/**
 * TopDownSplitMerge - recursive engine of the merge_sort, splits working copy of
 * array into left and right runs, then merges with TopDownMerge
 * @source: array of the integers to sorted
 * @iBeg: starting index value
 * @iEnd: ending index value
 * @dest: array to store sorted integers
 */
void TopDownSplitMerge(int *source, int iBeg, int iEnd, int *dest)
{
	int iMid;

	if (iEnd - iBeg < 2) /* if run size == 1 */
		return;     /* consider it sorted */
	/* split run longer than 1 item into halves */
	iMid = (iEnd + iBeg) / 2;

	TopDownSplitMerge(dest, iBeg, iMid, source);  /* sort left run */
	TopDownSplitMerge(dest, iMid, iEnd, source);  /* sort right run */
	/* merge of resulting runs from array[] into work_copying[] */
	TopDownMerge(source, iBeg, iMid, iEnd, dest);
}

/**
 * merge_sort - sorts array of integers in ascending order using a
 * top-down merge sort algorithm
 * @array: array of the integers to be sorted
 * @size: amount of the elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *work_copying;

	if (!array || size < 2)
		return;

	work_copying = malloc(sizeof(int) * size);
	if (!work_copying)
		return;

	CopyArray(array, 0, size, work_copying);
	TopDownSplitMerge(work_copying, 0, size, array);

	free(work_copying);
}
