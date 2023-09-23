#include "sort.h"

void quick_sort(int *array, size_t size);
int partition(int *array, int start, int end, size_t size);
void sorter(int *array, int start, int end, size_t size);

/**
 * partition - partitions the array such that the pivot
 * is in its right position using lomuto scheme
 * @array: array to partition
 * @start: starting point of array or sub array
 * @end: end of array
 * @size: size of array `for printing'
 * Return: the new pivot
 */
int partition(int *array, int start, int end, size_t size)
{
	int i = start - 1;
	int j, temp;

	(void)size;
	for (j = start; j < end; j++)
	{
		/*array end last element is always the pivot*/
		if (array[j] < array[end])
		{
			if (array[i] != array[j])
			{
				temp = array[++i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[++i] != array[end])
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * sorter - helper function to recursively call the
 * quick sort implementation
 * @array: array to sort
 * @start: start of array or subarray to sort
 * @end: end of array or subarray to sort
 * @size: size of array
 */
void sorter(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;
	pivot = partition(array, start, end, size);
	/*Sort left half*/
	sorter(array, start, pivot - 1, size);
	/*Sort right half*/
	sorter(array, pivot + 1, end, size);
}

/**
 * quick_sort - sorts the array using quick sort
 * algorithm and prints the output to screen after
 * each swaps
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int start, end;

	if (!array || size < 2)
		return;

	start = 0;
	end = size - 1;
	sorter(array, start, end, size);
}
