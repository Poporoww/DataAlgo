void shift(int k) {
	// TODO: Add your code here
	int n = mSize;
	k = ((k % n) + n) % n;
	
	if(k == 0) return;

	node *first = mHeader->next, *tail = mHeader->prev;
	node *pos = mHeader->next;
	
	for(int i = 0; i < k - 1; ++i) pos = pos->next;
	node *next_pos = pos->next;

	pos->next = mHeader;
	mHeader->prev = pos;
	mHeader->next = next_pos;
	next_pos->prev = mHeader;

	first->prev = tail;
	tail->next = first;
}
