knuth(size):
    for h = 1 up to size - 1:
        h = h * 3 + 1
    return h

swap(a, b):
    temp = a
    a = b
    b = a

shell(array, size):
    declare gap

    for gap = knuth(size) up to size - 1; gap /= 3:
        for j = gap up to size; j += 1:
            for i = j - gap down to 0; i -= gap:
                if array[gap + i] < array[i]:
                    swap(array + gap + i, array + i);
                else:
                    break
        print_array(array)
