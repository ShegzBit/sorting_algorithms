#include "sort.h"


/**
 * bubble_sort - prints sorted array by
 * implementing bubble sort
 * @array: Array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	long unsigned int i, j, swapped, temp;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
