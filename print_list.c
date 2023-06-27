#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints the list of integers
 *
 * @list: The list to printed
 */
void print_list(const listint_t *list)
{
	int t;

	t = 0;
	while (list)
	{
		if (t > 0)
			printf(", ");
		printf("%d", list->n);
		++t;
		list = list->next;
	}
	printf("\n");
}
