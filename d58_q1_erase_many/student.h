#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  int pos_idx = 0, write_idx = 0;

  for(int i = 0; i < mSize; ++i) {
    if(i == pos[pos_idx] and pos_idx < pos.size()) ++pos_idx;
    else {
      mData[write_idx] = mData[i];
      ++write_idx;
    }
  }

  mSize = write_idx;
}

#endif
