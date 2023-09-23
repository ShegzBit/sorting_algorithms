#include "sort.h"

/**
 * swap - swaps a node with the next node
 * @store: node to swap with
 * @ptr: node to swap
 * @list: pointer to list
 */
void swap(listint_t **store, listint_t **ptr, listint_t **list)
{
	listint_t *_store = *store, *_ptr = *ptr;

	if (_store->prev)
		_store->prev->next = _ptr;
	if (_ptr->next)
		_ptr->next->prev = _store;
	_store->next = _ptr->next;
	_ptr->prev = _store->prev;
	_store->prev = _ptr;
	_ptr->next = _store;
	if (_ptr->prev == NULL)
		*list = _ptr;
}

/**
 * swap_prev - swaps a node with the previous
 * @store: node to swap with
 * @temp: node to swap
 * @list: pointer to list
 */
void swap_prev(listint_t **store, listint_t **temp, listint_t **list)
{
	listint_t *_temp = *temp, *_store = *store;

	if (_temp->prev)
		_temp->prev->next = _store;
	if (_store->next)
		_store->next->prev = _temp;
	_temp->next = _store->next;
	_store->next = _temp;
	_store->prev = _temp->prev;
	_temp->prev = _store;
	if (_store->prev == NULL)
		*list = _store;
}

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
			swap(&store, &ptr, list);
			temp = ptr;
			print_list(*list);
			while (temp)
			{
				if (temp->prev && temp->n < temp->prev->n)
				{
					store = temp;
					temp = temp->prev;
					swap_prev(&store, &temp, list);
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
