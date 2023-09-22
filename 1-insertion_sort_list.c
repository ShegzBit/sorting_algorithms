#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = *list, *temp, *store;

	if (*list == NULL)
		return;
	while (ptr)
	{
		if (ptr->next && ptr->next->n < ptr->n)
		{
			store = ptr;
			ptr = ptr->next;
			if (store->prev)
				store->prev->next = ptr;
			if (ptr->next)
				ptr->next->prev = store;
			store->next = ptr->next;
			ptr->prev = store->prev;
			store->prev = ptr;
			ptr->next = store;
			if (ptr->prev == NULL)
				*list = ptr;
			temp = ptr;
			print_list(*list);
			while (temp)
			{
				if (temp->prev && temp->n < temp->prev->n)
				{
					store = temp;
					temp = temp->prev;
					if (temp->prev)
						temp->prev->next = store;
					if (store->next)
						store->next->prev = temp;
					temp->next = store->next;
					store->next = temp;
					store->prev = temp->prev;
					temp->prev = store;
					if (store->prev == NULL)
						*list = store;
					print_list(*list);
				}
				else
					break;
				temp = temp->prev;
			}
		}
		ptr = ptr->next;
	}
}
