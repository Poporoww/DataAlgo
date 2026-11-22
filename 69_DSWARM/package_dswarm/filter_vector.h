#ifndef _CP_FILTER_VECTOR_INCLUDED_
#define _CP_FILTER_VECTOR_INCLUDED_
#include <iostream>

namespace CP {

template <typename T>
class filter_vector {
private:
  T *mData;
  size_t mCap;
  size_t mSize;
  size_t mFilteredSize;

  T mMin;
  T mMax;

protected:
  void ensureCapacity(size_t capacity) {
    if (capacity > mCap) {
      size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
      expand(s);
    }
  }

  void expand(size_t capacity) {
    T* arr = new T[capacity]();
    for (size_t i = 0; i < mSize; i++) {
      arr[i] = mData[i];
    }
    delete[] mData;
    mData = arr;
    mCap = capacity;
  }

public:
  filter_vector(size_t capacity) {
    mCap = capacity;
    mSize = 0;
    mFilteredSize = 0;
    mMin = 0;
    mMax = 0;
    mData = new T[mCap]();
  }
  ~filter_vector() {
    delete[] mData;
  }
  size_t size() { return mSize; }
  size_t filtered_size() { return mFilteredSize; }
  size_t capacity() { return mCap; }

  bool in_bounds(T value) const {
    if (mMin != 0 && value < mMin) return false;
    if (mMax != 0 && value > mMax) return false;
    return true;
  }

  void pop_back() {
    int i = mSize - 1;
    for (; i >= 0; i--) {
      if (in_bounds(mData[i])) break;
    }
    for (; i < mSize - 1; i++) {
      mData[i] = mData[i + 1];
    }
    mFilteredSize--;
    mSize--;
  }
  void push_back(const T &element) { insert(mFilteredSize, element); }
  void print_vector() {
    std::cout << mFilteredSize << " | ";
    for (int i = 0; i < mFilteredSize; i++) {
      std::cout << (*this)[i] << ' ';
    }
    std::cout << '\n';
  }

  /* --------------- FOR student.h --------------- */
public:
  void insert(int index, const T &element);
  T &operator[](int index) const;
  void set_bounds(const T& min, const T& max);
  /* --------------------------------------------- */
};

} // namespace CP
#endif
