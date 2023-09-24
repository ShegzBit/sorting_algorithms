#include "sort.h"
void shell_sort(int *array, size_t size);
size_t knuth_seq(size_t size);
void swap_int(int *a, int *b);

/**
 * knuth_seq - calculates the first sequence
 * to use on an array of size <size>
 * @size: size of array
 * Return: knuth gap for array of size <size>
 */
size_t knuth_seq(size_t size)
{
	size_t seq;

	for (seq = 1; seq < size; seq = seq * 3 + 1)
		;
	return (seq / 3);
}

/**
 * swap_int - swaps the value of two integers
 * @a: pointer to first value
 * @b: pointer to second value
 */
void swap_int(int *a, int *b)
{
	int temp = *a;

	(*a) = *b;
	*b = temp;
}


/**
 * shell_sort - sorts the array using shell sorts
 * and print the array after every decrease in gap used
 * @array: array to sort
 * @size: size of array to work with
 */
void shell_sort(int *array, size_t size)
{
	int seq, i, j, int_size = size;

	for (seq = knuth_seq(size); seq >= 1; seq /= 3)
	{
		for (j = seq; j < int_size; j++)
		{
			for (i = j - seq; i >= 0; i -= seq)
			{
				if (array[i + seq] < array[i])
					swap_int(array + i + seq, array + i);
				else
					break;
			}
		}
		print_array(array, size);
	}
}
