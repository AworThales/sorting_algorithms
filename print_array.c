#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints array of integers
 *
 * @array: The array to printed
 * @size: Number of the elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t t;

	t = 0;
	while (array && t < size)
	{
		if (t > 0)
			printf(", ");
		printf("%d", array[t]);
		++t;
	}
	printf("\n");
}
