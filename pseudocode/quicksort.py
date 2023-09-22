quicksort(array, size):
    let start = 0, end = size;
    sorter(array, start, end)
sorter(array, start, end):
    let pivot = partition(array, start, end)

    if (start == end):
        return;
    # sort left half
    sorter(start, pivot - 1)
    # sort right half
    sorter(pivot - 1, end)

partition(array, start, end):
    let i = start - 1

    for let j = start; j to end:
        if array[j] < array[end]:
            i++
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
    i++
    temp = array[end];
    array[end] = array[i];
    array[i] = array[end]
    return i
