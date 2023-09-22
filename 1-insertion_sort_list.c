#include "sort.h"

listint_t *rejoin(listint_t *list, listint_t *sorted);
listint_t *sorted_insert(listint_t *temp, listint_t **head);
void insertion_sort(listint_t **list);

/**
 * rejoin - joins a sorted half of a list to the other
 * half
 * @list: unsorted half
 * @sorted: sorted half
 * Return: a pointer to start of the new list
 */
listint_t *rejoin(listint_t *list, listint_t *sorted)
{
	listint_t *temp = sorted;

	if (!sorted)
		return (list);
	if (!list)
		return (sorted);

	while (sorted->next)
	{
		print_list(sorted);
		sorted = sorted->next;
	}
	sorted->next = list;
	list->prev = sorted;
	return (temp);
}

/**
 * sorted_insert - inserts a node in a sorted list in the right other
 * @temp: new node to insert
 * @head: pointer to head of sorted list
 * Return: New head of the sorted list
 */
listint_t *sorted_insert(listint_t *temp, listint_t **head)
{
	listint_t *tail, *current;

	if (!head || !temp)
		return (NULL);
	temp->prev = NULL;
	temp->next = NULL;

	tail = *head;
	while (tail->next)
		tail = tail->next;
	while (tail)
	{
		if (temp->n >= tail->n)
		{
			temp->prev = tail;
			temp->next = tail->next;
			if (tail->next)
				tail->next->prev = temp;
			else
				temp->next = NULL;
			tail->next = temp;
			break;
		}
		current = tail;
		tail = tail->prev;
	}

	/*If tail is NULL meaning temp holds the smallest value*/
	/*And should be inserted at start*/
	if (tail == NULL)
	{
		temp->next = current;
		current->prev = temp;
		/*If there's a new start of list return start*/
		/*Otherwise NULL*/
		return (temp);
	} return (NULL);
}

/**
 * insertion_sort_list - implements insertion sort
 * and print the state of the list after each swap
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *temp, *head, *store;

	if (!list || !(*list) || !(*list)->next)
		return;
	/*Assign first element to a the sorted half*/
	sorted = (*list);
	head = (*list)->next;
	sorted->next = NULL;
	sorted->prev = NULL;

	while (head)
	{
		temp = head;
		head = head->next;
		store = sorted_insert(temp, &sorted);
		sorted = (store) ? store : sorted;
		print_list(rejoin(head, sorted));
	}
}
