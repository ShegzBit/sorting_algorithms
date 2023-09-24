#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **_nodea, listint_t **_nodeb);


/**
 * swap_node - swaps the positon of two node in a doubly
 * linked list
 * @_nodea: node to push to back
 * @_nodeb: node to push to front
 */
void swap_node(listint_t **_nodea, listint_t **_nodeb)
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
	if (temp2)
		temp2->prev = node_a;
}


/**
 * cocktail_sort - sorts a list using the cocktail
 * algorithm and prints out the list after each swap
 */
void cocktail_sort_list(listint_t **list)
{
}
