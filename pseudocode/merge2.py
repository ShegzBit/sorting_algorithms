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
    while r_idx <= sub_right.end and l_idx <= sub_left.end:
        if sub_right.bg[r_idx] < sub_left.bg[l_idx]:
            sup_arr.bg[i] = sub_right.bg[r_idx]
            r_idx++
            i++
        else:
            sup_arr.bg[i] = sub_left.bg[l_idx]
            l_idx++
            i++
    while l_idx <= sub_left.end:
        sup_arr.bg[i] = sub_left.bg[l_idx]
        i++
        l_idx++
    while r_idx <= sub_right.end:
        sup_arr.bg[i] = sub_right.bg[r_idx]
        i++
        r_idx++
