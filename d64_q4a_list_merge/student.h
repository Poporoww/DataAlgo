#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  node *prev_node = mHeader->prev;
  int total_size = mSize;
  for(auto &s : ls) {
    if(s.mSize == 0) continue;
    total_size += s.mSize;

    node *first = s.mHeader->next, *tail = s.mHeader->prev;

    prev_node->next = first;
    first->prev = prev_node;

    prev_node = tail;

    s.mHeader->next = s.mHeader;
    s.mHeader->prev = s.mHeader;
    s.mSize = 0;
  }

  prev_node->next = mHeader;
  mHeader->prev = prev_node;

  mSize = total_size;
}

#endif
