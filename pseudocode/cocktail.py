cocktail(list):
    let list1 = list, list2 = list
    for list1 is not null; list1 = list1->next:
        for list2 is not null:
            let temp = list2
            list2 = list2->next;
            if list2 is null: break
            if temp->n > list2->n:
                swap_node(temp, list2)
        let list3 = temp
        for list3 is not null:
            temp = list3
            list3 = list3->prev
            if list3 is null: break
            if temp->n < list3->n:
                swap_node(temp, list3)

swap_node(node_a, node_b):
    if node_a or node_b is null:
        return

    if node_a->prev is not null:
        node_a->prev->next = node_b
    if node_b->next is not null:
        node_b->next->prev = node_a
    node_b->prev = node_a->prev
    node_a->next = node_b->next
    node_a->prev = node_b
    node_b->next = node_a
