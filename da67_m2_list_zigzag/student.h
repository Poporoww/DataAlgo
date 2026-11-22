
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {
    if(ls.mSize == 0) return;
    auto cur1 = mHeader->next;
    auto cur2 = ls.mHeader->next;

    for(int i = 0; i + 1 < mSize and i < ls.mSize; ++i) {
        auto tmp1 = cur1->next, tmp2 = cur2->next;
        auto next_cur1 = cur1->next;

        cur1->next = cur2;
        cur2->prev = cur1;

        cur2->next = next_cur1;
        next_cur1->prev = cur2;

        cur1 = tmp1; cur2 = tmp2;
    }

    if(ls.mSize >= mSize) {
        auto tail2 = ls.mHeader->prev;

        cur1->next = cur2;
        cur2->prev = cur1;
        tail2->next = mHeader;
        mHeader->prev = tail2;
    }

    mSize += ls.mSize;
    ls.mHeader->next = ls.mHeader;
    ls.mHeader->prev = ls.mHeader;
    ls.mSize = 0;
}

#endif
