insertion_sort(list):
    create head to sorted list <sorted>
    for list is not NULL:
        let temp = list
        list = list->next
        if list is not NULL:
            list->prev = NULL
        sorted_insert(temp, sorted)

sorted_insert(temp, sorted):
    temp->next = NULL
    temp->prev = NULL
    if sorted is NULL:
        sorted = temp
        return sorted
    let container = sorted
    for container is not NULL:
        if container.n > temp:
            swap(container, temp)
        else:
            container->next = temp
            temp->prev = container
    return sorted

swap(container, temp):
    if container->prev is not NULL:
        container->prev->next = temp
    temp->prev = container->prev;
    container->prev = temp
    temp->next = container
    container->next = NULL
