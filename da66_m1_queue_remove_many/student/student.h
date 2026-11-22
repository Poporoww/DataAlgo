#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  sort(pos.begin(), pos.end());
  int write_idx = mFront, pos_idx = 0;

  for(int i = 0; i < mSize; ++i) {
    if(i == pos[pos_idx] and pos_idx < pos.size()) {
      ++pos_idx;
    } else {
      mData[write_idx] = mData[(mFront + i) % mCap];
      write_idx = (write_idx + 1) % mCap;
    }
  }

  mSize -= pos.size();
}

#endif
