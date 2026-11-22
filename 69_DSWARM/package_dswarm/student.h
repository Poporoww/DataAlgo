#ifndef __STUDENT_H_
#define __STUDENT_H_

// You may include library here
#include "filter_vector.h"

template <typename T>
void CP::filter_vector<T>::insert(int index, const T &element) {
  // Write your code here
  ensureCapacity(mSize + 1);
  if(mSize == 0) {
    mMin = -2e9;
    mMax = 2e9;
  }
  //std::cout << mMin << ' ' << mMax << '\n';
  int idx = -1, tmp = -1;
  for(int i = 0; i < mSize; ++i) {
    if(mData[i] >= mMin and mData[i] <= mMax) ++tmp;
    if(tmp == index) {
      idx = i;
      break;
    }
  }
  if(idx == -1) idx = mSize;

  for(int i = mSize; i > idx; --i) {
    mData[i] = mData[i - 1];
  }
  mData[idx] = element;
  
  mSize++;
  if(element >= mMin and element <= mMax) mFilteredSize++;

  // std::cout << idx << ' ' << element << '\n';
  // for(int i = 0; i < mSize; ++i) std::cout << mData[i] << ' ';
  // std::cout << '\n';
}

template <typename T>
T &CP::filter_vector<T>::operator[](int index) const {
  // Write your code here
  int tmp = -1;
  for(int i = 0; i < mSize; ++i) {
    if(mData[i] >= mMin and mData[i] <= mMax) ++tmp;
    if(tmp == index) return mData[i];
  }
  return mData[mSize - 1];
}

template <typename T>
void CP::filter_vector<T>::set_bounds(const T& min, const T& max) {
  // Write your code here
  if(min == 0) {
    mMin = -2e9;
  } else {
    mMin = min;
  }
  if(max == 0) {
    mMax = 2e9;
  } else {
    mMax = max;
  }
  
  int cnt = 0;
  for(int i = 0; i < mSize; ++i) {

    if(mData[i] >= mMin and mData[i] <= mMax) ++cnt;
  }
  //std::cout << cnt << '\n';
  mFilteredSize = cnt;
}

#endif
