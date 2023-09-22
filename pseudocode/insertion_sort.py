insertion_sort(list):
    create head to sorted list <sorted>
    for list is not NULL:
        let temp = list
        list = list->next
        if list is not NULL:
            list->prev = NULL
        sorted_insert(temp, sorted)
        rejoin(sorted, list)

sorted_insert(temp, sorted):
    temp->next = NULL
    temp->prev = NULL
    if sorted is NULL:
        sorted = temp
        return sorted
    let tail = sorted
    for tail is not NULL:
        if tail->n > temp:
            swap(tail, temp)
        else:
            tail->next = temp
            temp->prev = tail
        tail = tail->prev
    return sorted

swap(tail, temp):
    if tail->prev is not NULL:
        tail->prev->next = temp
    temp->prev = tail->prev;
    tail->prev = temp
    temp->next = tail

rejoin(sorted, list):
    declare temp
    if sorted is NULL:
        return list
    if list is NULL:
        return sorted
    while sorted is not NULL:
        temp = sorted
        sorted = sorted->next
    temp->next = list
    list->prev =temp
