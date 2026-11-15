#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  if(k == 1) return mData[0];

  if(k == 2) {
    if(mSize == 2) return mData[1];
    return mLess(mData[1], mData[2]) ? mData[2] : mData[1];
  }

  size_t idx = mLess(mData[1], mData[2]) ? 2 : 1;
  size_t other = (idx == 1) ? 2 : 1;

  T ans = mData[other];

  size_t idx_left = (idx * 2) + 1, idx_right = (idx * 2) + 2;

  if(mLess(ans, mData[idx_left])) ans = mData[idx_left];
  if(mLess(ans, mData[idx_right])) ans = mData[idx_right];

  return ans;
}

#endif
