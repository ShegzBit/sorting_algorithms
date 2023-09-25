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
void insertion_sort_list(listint_t **list);
listint_t *rejoin(listint_t *list, listint_t *sorted);
listint_t *sorted_insert(listint_t *temp, listint_t **head);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int start, int end, size_t size);
void sorter(int *array, int start, int end, size_t size);
void swap(listint_t **store, listint_t **ptr, listint_t **list);
void swap_prev(listint_t **store, listint_t **temp, listint_t **list);
void shell_sort(int *array, size_t size);
size_t knuth_seq(size_t size);
void swap_int(int *a, int *b);
void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **_nodea, listint_t **_nodeb,
		listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


#endif /*_SORT_H_*/
