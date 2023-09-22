#include "sort.h"

/**
 * rejoin - rejoins the sorted part of a list to the
 * unsorted part
 * @sorted: sorted half of the list
 * @list: other half
 */
void rejoin(listint_t *sorted, listint_t **list,
		listint_t **main_list)
{
	if (sorted == NULL)
	{
		*main_list = *list;
		return;
	}
	if (*list == NULL)
	{
		*main_list = sorted;
		return;
	}

	*main_list = sorted;
	while(sorted->next)
		sorted = sorted->next;
	sorted->next = *list;
	(*list)->prev = sorted;
}

/**
 * swap - swaps to node of a linked list
 * @temp
 */
void swap(listint_t **head, listint_t **temp)
{
	listint_t *_temp, *_head;

	if (temp == NULL || head == NULL)
		return;
	_temp = *temp;
	_head = *head;

	if (_head->prev)
		_head->prev->next = _temp;
	_temp->prev = _head->prev;
	_head->prev = *temp;
	_temp->next = _head;
}

/**
 * sorted_insert - inserts a node in its ordered position
 * in a sorted list
 * @temp: node to input
 * @sorted: sorted list to insert in
 * Return: sorted list containing new node
 */
listint_t *sorted_insert(listint_t *temp, listint_t **sorted)
{
	listint_t *tail;

	temp->next = NULL;
	temp->prev = NULL;
	if (sorted == NULL)
	{
		*sorted = temp;
		return *sorted;
	}

	tail = *sorted;
	while (tail->next)
		tail = tail->next;
	for (; tail; tail = tail->prev)
	{
		if (tail->n > temp->n)
			swap(&temp, &tail);
		else
		{
			tail->next = temp;
			temp->prev = tail;
			break;
		}
	}
	return *sorted;
}

/**
 * insertion_sort_list - prints a sorted version of list 
 * implementing insertion sort
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL, *_list, *temp;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;

	sorted = *list;
	sorted->prev = NULL;
	sorted->next = NULL;
	for (_list = (*list)->next; _list;)
	{
		temp = _list;
		_list = _list->next;
		if (_list)
			_list->prev = NULL;
		sorted = sorted_insert(temp, &sorted);
		rejoin(sorted, &_list, list);
		print_list((const listint_t *)(*list));
	}
}
