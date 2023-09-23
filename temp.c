void swap(listint_t **store, listint_t **ptr, listint_t **list)
{
	listint_t *_store = *store, *_ptr = *ptr;

	_store = _ptr;
	_ptr = _ptr->next;
	if (_store->prev)
		_store->prev->next = _ptr;
	if (_ptr->next)
		_ptr->next->prev = store;
	_store->next = _ptr->next;
	_ptr->prev = _store->prev;
	_store->prev = _ptr;
	_ptr->next = _store;
	if (_ptr->prev == NULL)
		*list = _ptr;
}

void swap_prev(listint_t **store, listint_t **temp, listint_t **list)
{
	listint_t *_temp = *temp, listint_t *_store = *store;

	if (_temp->prev)
		_temp->prev->next = _store;
	if (_store->next)
		_store->next->prev = _temp;
	_temp->next = _store->next;
	_store->next = _temp;
	_store->prev = _temp->prev;
	_temp->prev = _store;
	if (_store->prev == NULL)
		*list = _store;
}
