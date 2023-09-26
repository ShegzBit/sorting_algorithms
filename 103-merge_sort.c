#include "sort.h"

#define _arr sup_arr
#define sup_bg(idx) sup_arr.bg[idx]


/**
 * merge - merges to array twogether
 * @sup_arr: main array of the operation
 * @left: left sub array to merge
 * @right: right sub array to merge
 * @space: extra space for merging
 */
void merge(array_t sup_arr, array_t left, array_t right,
		int *space)
{
	(void)sup_arr;
	(void)left;
	(void)right;
	(void)space;
}

/**
 * sort_helper - helps merge_sort in recursive calls
 * @array: new array space for merging
 * @sup_arr: array to merge
 */
void sort_helper(array_t sup_arr, int *space)
{
	/*note macro of sup_arr = _arr definition at top*/
	int size = sup_arr.end - sup_arr.start + 1;
	int l_stop = sup_arr.mid, l_start = sup_arr.start;
	int l_mid = (l_start + l_stop) / 2;
	int l_size = l_stop - l_start + 1;
	int r_stop = sup_arr.stop, r_start = sup_arr.mid + 1;
	int r_mid = (r_start + r_stop) / 2;
	int r_size = l_stop + l_start + 1;
	array_t sub_left, sub_right, left, right;

	if (size == 1)
		return (sup_arr);
	sub_left = {
		sup_arr.bg + l_start, sup_arr.bg + l_end,
		l_start, l_mid, l_stop, l_size
	};

	sub_right = {
		sup_arr.bg + r_start, sup_arr.end, r_start, r_mid,
		r_stop, r_size;
	}

	left = sort_helper(space, sub_left);
	right = sort_helper(space, right);

	merge(sup_arr, left, right, space);

}

/**
 * merge_sort - sort an array using the merge sort
 * algorithm
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *space, end;

	if (!array || size < 2)
		return;
	space = malloc(sizeof(int));

	end = size - 1;
	array_t sup_arr = {
		array, array + end, 0, end / 2, end, size
	};

	sort_helper(space, array);
}
