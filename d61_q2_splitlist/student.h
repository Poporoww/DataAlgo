void splitList(list<T>& list1, list<T>& list2) {
    int split1 = (this->mSize + 1) / 2;
    int split2 = this->mSize - split1;

    auto x_tail = this->mHeader->prev;
    auto x_head = this->mHeader->next;
    auto cur = mHeader;

    for(int i = 0; i < split1; ++i) cur = cur->next;
    auto cur2 = cur->next;

    if(split1 > 0) {
        auto l1_tail = list1.mHeader->prev;
        l1_tail->next = this->mHeader->next;
        x_head->prev = l1_tail;
        cur->next = list1.mHeader;
        list1.mHeader->prev = cur;
        list1.mSize += split1;
    }

    if(split2 > 0) {
        auto l2_tail = list2.mHeader->prev;
        l2_tail->next = cur2;
        cur2->prev = l2_tail;
        x_tail->next = list2.mHeader;
        list2.mHeader->prev = x_tail;
        list2.mSize += split2;
    }

    this->mHeader->next = this->mHeader;
    this->mHeader->prev = this->mHeader;
    this->mSize = 0;
}
