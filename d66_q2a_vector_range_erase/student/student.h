#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  vector<int> check(mSize);

  for(auto [a, b] : ranges) {
    check[a - begin()] += 1;
    check[b - begin()] -= 1;
  }

  int write_idx = 0, write = 0;

  for(int i = 0; i < mSize; ++i) {
    write += check[i];
    if(write == 0) {
      mData[write_idx++] = mData[i];
    }
  }

  mSize = write_idx;
}

#endif
