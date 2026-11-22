#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
size_t CP::list<T>::fix_wrong() {
  auto cur_node = mHeader->next;
  auto prev_node = mHeader;

  int wrong = 0;
  for(int i = 0; i < mSize; ++i) {
    if(cur_node->prev != prev_node) {
      wrong++;
      cur_node->prev = prev_node;
    }
    prev_node = cur_node;
    cur_node = cur_node->next;
  }
  if(cur_node->prev != prev_node) {
    ++wrong;
    cur_node->prev = prev_node;
  }

  return wrong;
}

#endif