#include "sort.h"

/**
 * insertion_sort_list - sorts the doubly linked list of integers in ascending
 * order using an insertion sort algorithm
 * @list: doubly linked list of the integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *leads, *followers, *fresh, *tempral;

	if (!list || !(*list) || !((*list)->next))
		return;

	/* dance to begins with 1st from house left following */
	followers = (*list);
	/* and the next dancer to house right leading */
	leads = (*list)->next;
	while (leads)
	{
		fresh = leads->next;
		while (followers && leads->n < followers->n)
		{
			/* leads and the followers swap positions */
			if (followers->prev)
				followers->prev->next = leads;
			else
				/* if the leads makes it to house left, now head */
				*list = leads;
			if (leads->next)
				leads->next->prev = followers;
			tempral = leads->next;
			leads->next = followers;
			leads->prev = followers->prev;
			followers->next = tempral;
			followers->prev = leads;
			print_list(*list);
			/* compare next pair, flowing to house left */
			followers = leads->prev;
		}
		/* leads to sorted to left, fresh cycle starts @ right leading edge */
		leads = fresh;
		if (leads)
			followers = leads->prev;
	}
}
