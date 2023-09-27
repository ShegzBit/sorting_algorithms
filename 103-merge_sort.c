#include "sort.h"

#define _arr sup_arr
#define RIGHT(x) right.bg[x]
#define LEFT(x) left.bg[x]


/**
 * merge - merges to array twogether
 * @sup_arr: main array of the operation
 * @left: left sub array to merge
 * @right: right sub array to merge
 * @space: extra space for merging
 */
array_t merge(array_t sup_arr, array_t left, array_t right,
		int *space)
{
	/*Macro RIGHT(x) evaluates to right.bg[x] for ease of type*/
	/*Macro LEFT(x) evaluates to left.bg[x] for ease of type*/
	int l_idx = 0, r_idx = 0, i = sup_arr.start;
	array_t spaces;

	print_merge(left, right);
	while (r_idx <= right.stop && l_idx <= left.stop)
	{
		if (RIGHT(r_idx) < LEFT(l_idx))
		{
			space[i++] = RIGHT(r_idx++);
		}
		else
		{
			space[i++] = LEFT(l_idx++);
		}
	}
	while (l_idx <= left.stop)
	{
		space[i++] = LEFT(l_idx++);
	}
	while (r_idx <= right.stop)
	{
		space[i++] = RIGHT(r_idx++);
	}
	spaces = create_array(space, i, sup_arr.start);
	print_merge(spaces, create_array(NULL, 0, 0));

	return (spaces);
}

/**
 * sort_helper - helps merge_sort in recursive calls
 * @array: new array space for merging
 * @sup_arr: array to merge
 */
array_t sort_helper(array_t sup_arr, int *space)
{
	/*note macro of sup_arr = _arr definition at top*/
	int size = sup_arr.stop - sup_arr.start + 1;
	int l_stop = sup_arr.mid, l_start = sup_arr.start;
	int l_size = l_stop - l_start + 1;
	int r_start = sup_arr.mid + 1, r_stop = sup_arr.stop;
	int r_size = r_stop - r_start + 1;
	array_t sub_left, sub_right, left, right;

	if (size == 1)
		return (sup_arr);
	sub_left = create_array(sup_arr.bg, l_size, l_start);
	sub_right = create_array(sup_arr.bg, r_size, r_start);

	left = sort_helper(sub_left, space);
	right = sort_helper(sub_right, space);

	return (merge(sup_arr, left, right, space));

}

/**
 * merge_sort - sort an array using the merge sort
 * algorithm
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *space;
	array_t sup_arr;

	if (!array || size < 2)
		return;
	space = malloc(sizeof(int) * size);

	sup_arr = create_array(array, size, 0);

	sort_helper(sup_arr, space);
}

array_t create_array(int *array, int size, int start)
{
	array_t new_array = {NULL, NULL, 0, 0, 0, 0};
	int stop, mid;

	if (!array)
		return new_array;
	stop = start + size - 1;
	mid = (start + stop) / 2;

	new_array.bg = array + start;
	new_array.end = array + stop;
	new_array.start = start;
	new_array.mid = mid;
	new_array.stop = stop;
	new_array.size = size;

	return new_array;
}


/**
 * print_merge - prints arrays beivng merge to screen
 * @left: array to the left or main array to print
 * when done if right is NULL
 * @right: array to the right
 */
void print_merge(array_t left, array_t right)
{
	if(!right.bg)
	{
		printf("[Done]: ");
		print_array(left.bg, left.size);
		return;
	}
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left.bg, left.size);
	printf("[right]: ");
	print_array(right.bg, right.size);
}
