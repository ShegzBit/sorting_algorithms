#include "sort.h"

/**
 * counting_array - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void counting_array(int *array, size_t size)
{
	size_t i, max = array[0], j = 0;
	int *arr;

	if (array == NULL || size < 2)
		return;
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


/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, range, j;
	int max, min, *count;

	counting_array(array, size);
	if (array == NULL || size < 2)
		return;

	max = array[0];
	min = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
		if (array[i] < min)
		min = array[i];
	}
	range = max - min + 1;
	count = malloc(sizeof(int) * range);
	if (count == NULL)
		return;

	for (i = 0; i < range; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i] - min]++;

	j = 0;
	for (i = min; i <= (size_t)max; i++)
	{
		while (count[i - min] > 0)
		{
			array[j] = i;
			count[i - min]--;
			j++;
		}
	}
	free(count);
}
