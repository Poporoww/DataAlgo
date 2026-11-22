#include "priority_queue.h"
#include <utility>
#include <cmath>

template <typename T,typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k) {
  int h = log2(mSize), hk = log2(k + 1);
  int prev_start = k;

  for(int i = 1; i <= h - hk; ++i) {
    int start = 2*prev_start + 1, r = pow(2, i - 1);
    prev_start = start;

    for(int j = 0; j < r; ++j) {
      std::swap(mData[start + j], mData[start + j + r]);
    }
  }
}