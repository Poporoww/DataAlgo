#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  int pos_idx = position - begin(), range = last - first;
  int cur = mSize;

  for(int i = 0; i < range; ++i) this->push_back(T());

  for(int i = cur - 1; i >= pos_idx; --i) {
    mData[i + range] = mData[i];
  }

  for(int i = 0; i < range; ++i) {
    mData[pos_idx + i] = *first;
    ++first;
  }

}

#endif
