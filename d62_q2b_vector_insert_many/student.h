#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  vector<T> tmp(mSize + data.size());
  vector<bool> write(mSize + data.size());

  std::sort(data.begin(), data.end());

  for(int i = 0; i < data.size(); ++i) {
    int pos = data[i].first;
    T val = data[i].second;
    tmp[pos + i] = val;
    write[pos + i] = 1;
  }

  int idx = 0;
  for(int i = 0; i < mSize + data.size(); ++i) {
    if(!write[i]) {
      tmp[i] = mData[idx];
      ++idx;
    }
  }

  *this = tmp;
}

#endif
