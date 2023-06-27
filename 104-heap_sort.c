#include "sort.h"

/**
 * iParent - returns index of parent node for an array arranged as a binary
 * tree, for index i
 * @i: starting index to the determine parent node index
 * Return: index of the parent node
 */
int iParent(int i)
{
	return ((i - 1) / 2);
}

/**
 * iLeftChild- returns index of the left childs branch for an array arranged as
 * a binary tree, for index i
 * @i: starting index to the determine left childs branch index
 * Return: index of the left childs node
 */
int iLeftChild(int i)
{
	return ((2 * i) + 1);
}

/**
 * ConvertToHeap - arranges array of the integers into a heap/binary tree scheme
 * @array: array of integers
 * @size: number of elements in the array
 */
void ConvertToHeap(int *array, size_t size)
{
	int start;

	start = iParent(size - 1);

	while (start >= 0)
	{
		SiftDown(array, size, start, size - 1);
		start--;
	}
}

/**
 * SiftDown - shuffles heap/binary tree sorted array into array sorted by
 * ascending value
 * @array: array of values to be the sorted in place, from heap to ascending
 * @size: number of elements in the array
 * @start: starting index
 * @end: ending index
 */
void SiftDown(int *array, size_t size, int start, int end)
{
	int rooter, swapper, tempral, childs;

	rooter = start;

	while (iLeftChild(rooter) <= end)
	{
		childs = iLeftChild(rooter);
		swapper = rooter;

		if (array[swapper] < array[childs])
			swapper = childs;
		if (childs + 1 <= end && array[swapper] < array[childs + 1])
			swapper = childs + 1;
		if (swapper != rooter)
		{
			tempral = array[rooter];
			array[rooter] = array[swapper];
			array[swapper] = tempral;
			print_array(array, size);
			rooter = swapper;
		}
		else
			return;
	}
}

/**
 * heap_sort - sorts array of integers in the ascending order using a heap sort
 * sift-down alogrithm
 * @array: array of values to be the sorted
 * @size: number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int iEnd, tempral;

	if (!array || size < 2)
		return;

	ConvertToHeap(array, size);

	iEnd =  (int)size - 1;
	while (iEnd > 0)
	{
		tempral = array[iEnd];
		array[iEnd] = array[0];
		array[0] = tempral;
		print_array(array, size);
		iEnd--;
		SiftDown(array, size, 0, iEnd);
	}
}
