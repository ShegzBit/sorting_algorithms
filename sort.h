#ifndef _SORT_H_
#define _SORT_H_

/*Standard Header files*/
#include <stdlib.h>
#include <stdio.h>


void print_array(const int *array, size_t size);
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Default functions*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*Task functions*/
void bubble_sort(int *array, size_t size);
<<<<<<< HEAD
void insertion_sort_list(listint_t **list);
listint_t *rejoin(listint_t *list, listint_t *sorted);
listint_t *sorted_insert(listint_t *temp, listint_t **head);
void insertion_sort_list(listint_t **list);
=======
void selection_sort(int *array, size_t size);

>>>>>>> d50d8b0724ab00d169d9c24f03e8f67645d41e92

#endif /*_SORT_H_*/
