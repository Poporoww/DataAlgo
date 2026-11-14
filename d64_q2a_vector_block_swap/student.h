#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if(m <= 0) return false;
  if(a < begin() or a + m - 1 >= end()) return false;
  if(b < begin() or b + m - 1 >= end()) return false;

  if(a + m - 1 < b or b + m - 1 < a) {
    for(int i = 0; i < m; ++i) std::swap(*(a + i), *(b + i));
    return true;
  }

  return false;
}

#endif
