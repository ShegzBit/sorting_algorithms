merge_sort(array, n):
    alloc space[size]
    sort_helper(array, space, 0, size - 1)

sort_helper(array, space, start, end):
    size = end - start + 1

    if size == 1: return array[start]
    let mid = (start + end) / 2
    sort_helper(array, space, start, mid)
    sort_helper(array, space, mid + 1, end)

    return merge(array, space, start, mid, end)

merger(array, space, start, mid, end):
    left = mid - start
    right = end - start
    min = left: if left < right else: right
    max = left: if left > right else: right

    temp = array[mid + 1]
    left = 1
    begin = start
    for i = 0 j = 0 up to min:
        if left == 1:
            pass
        else:
            let temp = start
            start = mid + 1
            mid = temp - 1
            temp = i
            i = j
            j = i
        if array[start + i] < temp:
            space[begin + i + j] = array[start + i]
            temp = array[mid + j + 1]
            i++
            left = 1
        else:
            space[begin + i + j] = temp
            temp = array[start + i]
            j++
            left = 0
    if (i < max):

