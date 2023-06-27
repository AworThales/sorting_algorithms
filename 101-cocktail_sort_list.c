#include "sort.h"

/**
 * dll_adj_swap - swaps the two adjacent nodes of a doubly linked list
 * @list: doubly linked list of the integers to be sorted
 * @left: node closer to the head, right->prev
 * @right: node closer to the tail, left->next
 */
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *swaper;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;
	right->prev = left->prev;
	left->prev = right;
	swaper = right;
	left->next = right->next;
	swaper->next = left;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts the doubly linked list of the integers in ascending
 * order using an cocktail shaker sort algorithm
 * @list: doubly linked list of the integers to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapper_f, swapper_c;
	int shake_ranged = 1000000, checker;
	listint_t *tempral;

	if (!list || !(*list) || !(*list)->next)
		return;

	tempral = *list;
	do {
		swapper_f = swapper_c = false;
		for (checker = 0; tempral->next && checker < shake_ranged; checker++)
		{
			if (tempral->next->n < tempral->n)
			{
				dll_adj_swap(list, tempral, tempral->next);
				swapper_f = true;
			}
			else
				tempral = tempral->next;
		}
		if (!tempral->next)  /* first loop, to measuring list */
			shake_ranged = checker;
		if (swapper_f)
			tempral = tempral->prev;
		shake_ranged--;
		for (checker = 0; tempral->prev && checker < shake_ranged; checker++)
		{
			if (tempral->n < tempral->prev->n)
			{
				dll_adj_swap(list, tempral->prev, tempral);
				swapper_c = true;
			}
			else
				tempral = tempral->prev;
		}
		if (swapper_c)
			tempral = tempral->next;
	} while (swapper_f || swapper_c);
}
