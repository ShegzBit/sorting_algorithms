c struct
typedef struct{
        int *bg; //start of array
        int *end; //end of array
        int start; //start index
        int mid; //middle index
        int stop; //end index
        int size; //size of subarray
} sub_arr;


merge(sup_arr, sub_left, sub_right):
    let r_idx = sub_right.start
    let l_idx = sub_left.start
    let i = sup_arr.start
    while r_idx <= sub_right.stop and l_idx <= sub_left.stop:
        if sub_right.bg[r_idx] < sub_left.bg[l_idx]:
            sup_arr.bg[i] = sub_right.bg[r_idx]
            r_idx++
            i++
        else:
            sup_arr.bg[i] = sub_left.bg[l_idx]
            l_idx++
            i++
    while l_idx <= sub_left.stop:
        sup_arr.bg[i] = sub_left.bg[l_idx]
        i++
        l_idx++
    while r_idx <= sub_right.stop:
        sup_arr.bg[i] = sub_right.bg[r_idx]
        i++
        r_idx++

merge_sort(array, size):
    alloc space[size]
    sub_arr sup_arr = {
            space, space + size - 1, 0, (size - 1) / 2, size - 1, size
            }
    sort_helper(array, sup_arr)

sort_helper(array, sup_arr):
    if space.size == 1: return space.bg
    
    sub_left ={
            sup_arr.bg, sup_a
    }
