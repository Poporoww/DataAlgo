#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    if(mSize == mCap) return;

    if(mSize == 0) {
        delete[] mData;
        mData = NULL;
        mCap = 0;
        return;
    }

    T *new_mData = new T[mSize];
    for(int i = 0; i < mSize; ++i) {
        new_mData[i] = mData[i];
    }
    delete[] mData;

    mData = new_mData;
    mCap = mSize;
}

#endif
