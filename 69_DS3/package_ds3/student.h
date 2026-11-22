#ifndef __STUDENT_H_
#define __STUDENT_H_

// You may include library here
#include "queue.h"

template <typename T>
void CP::queue<T>::fusion(CP::queue<T>& other) {
  if(other.empty()) return;
  bool same = (&mData == &other.mData) ? true : false;
  int sa = mSize, sb = other.mSize;
  queue<T> tmp;  
  
  if(sa == sb) {
    for(int i = 0; i < sa; ++i) {
      int idx_a = (mFront + i) % mCap, idx_b = (other.mFront + i) % other.mCap;
      int sum = mData[idx_a] + other.mData[idx_b];
      if(sum != 0) tmp.push(sum);
    }
    while(!this->empty()) this->pop();
    while(!other.empty() and !same) other.pop();
  } else if(sa > sb) {
    int pos = sa - sb;
    for(int i = 0; i < pos; ++i) {
      tmp.push(mData[(mFront + i) % mCap]);
    }
    for(int i = 0; i < sb; ++i) {
      int idx_a = (mFront + i + pos) % mCap, idx_b = (other.mFront + i) % other.mCap;
      int sum = mData[idx_a] + other.mData[idx_b];
      if(sum != 0) tmp.push(sum);
    }
    while(!other.empty()) other.pop();
    while(!this->empty()) this->pop();
  } else {
    int pos = sb - sa;
    for(int i = 0; i < pos; ++i) {
      tmp.push(other.mData[(other.mFront + i) % other.mCap]);
    }
    for(int i = 0; i < sa; ++i) {
      int idx_a = (mFront + i) % mCap, idx_b = (other.mFront + i + pos) % other.mCap;
      int sum = mData[idx_a] + other.mData[idx_b];
      if(sum != 0) tmp.push(sum);
    }
    while(!other.empty()) other.pop();
    while(!this->empty()) this->pop();
  }

  while(!tmp.empty()) {
    this->push(tmp.front());
    tmp.pop();
  }
}

#endif
