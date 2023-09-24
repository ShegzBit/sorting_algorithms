#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j = 0, max = array[0];
	int *arr = NULL;

	for (i = 1; i < size; i++)
	{
		if (array[j] < array[i])
		{
			max = array[i];
			j = i;
		}
	}
	arr = malloc(sizeof(int) * max + 1);
	if (arr == NULL)
		return;

	for (i = 0; i < max + 1; i++)
		arr[i] = 0;
	for (i = 0; i < size; i++)
		++arr[array[i]];
	for (i = 1; i < max + 1; i++)
		arr[i] += arr[i - 1];
	print_array(arr, max + 1);
	free(arr);
}
