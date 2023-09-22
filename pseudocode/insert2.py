insertion_sort(list):
    if list is NULL:
        return
    let sorted = list
    let head = list->next

    while (head):
        let temp = head
        head = head->next
        let store = sorted_insert(temp, head)
        (store) ? sorted = store : sorted = sorted;
        print_list(rejoin(list, sorted))

sorted_insert(temp, head):
    temp->prev = NULL
    temp->next = NULL
    while (head):
        if temp->n >= head->n:
            temp->prev = head
            temp->next = head->next
            if (head->next):
                head->next->prev = temp
            head->next = temp
            break
        prev_node = head
        head = head->prev

    if head is NULL:
        temp->next = prev_node
        prev_node->prev = temp
        return temp
return NULL

rejoin(list, sorted):
    let temp = sorted
    while sorted->next:
        sorted = sorted->next;
    sorted->next = list
    if list is not NULL:
        list->prev = sorted
    return temp
