#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **_nodea, listint_t **_nodeb,
		listint_t **list);


/**
 * swap_node - swaps the positon of two node in a doubly
 * linked list
 * @_nodea: node to push to back
 * @_nodeb: node to push to front
 * @list: list to sort
 */
void swap_node(listint_t **_nodea, listint_t **_nodeb,
		listint_t **list)
{
	listint_t *node_a, *node_b, *temp1, *temp2;

	if (!_nodea || !_nodeb)
		return;
	node_a = *_nodea;
	node_b = *_nodeb;
	if (!node_a || !node_b)
		return;
	temp1 = node_a->prev;
	temp2 = node_b->next;

	node_a->next = temp2;
	node_a->prev = node_b;
	node_b->next = node_a;
	node_b->prev = temp1;

	if (temp1)
		temp1->next = node_b;
	else
		*list = node_b;
	if (temp2)
		temp2->prev = node_a;
}


/**
 * cocktail_sort_list - sorts a list using the cocktail
 * algorithm and prints out the list after each swap
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *list1, *list2, *temp, *store, *store2;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;
	list1 = *list;
	list2 = *list;
	store = NULL;
	temp = *list;
	for (; list1; list1 = list1->next)
	{
		list2 = temp;
		swapped = 0;
		while (list2 != store)
		{
			temp = list2;
			list2 = list2->next;
			if (!list2)
				break;
			if (temp->n > list2->n)
			{
				swap_node(&temp, &list2, list);
				print_list(*list);
				swapped = 1;
			} } store = list2 = temp;
		while (list2 != store2)
		{
			temp = list2;
			list2 = list2->prev;
			if (!list2)
				break;
			if (temp->n < list2->n)
			{
				swap_node(&list2, &temp, list);
				print_list(*list);
				swapped = 1;
			} } store2 = temp;
		if (!swapped)
			break;
	} }
