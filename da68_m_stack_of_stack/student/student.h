#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <vector>

// can include other libs or write util funtion here

template <typename T>
void CP::stack<T>::push(const T& value) {
    //write your code here
    if(size() == 0) {
        mData.push_back({value});
        ++mSize;
        return;
    } 
    int n1 = mData.size() - 1;
    if(mData[n1].size() >= n1 + 1) {
        mData.push_back({value});
        ++mSize;
    } else {
        mData[n1].push_back(value);
        ++mSize;
    }
}

template <typename T>
void CP::stack<T>::pop() {
    if (size() == 0) throw std::out_of_range("index of out range") ;
	//write your code here
    int n1 = mData.size() - 1;
    mData[n1].pop_back();
    if(mData[n1].empty()) mData.pop_back();
    mSize--;
}

template <typename T>
size_t CP::stack<T>::size() const {
    //write your code here
    return mSize;
}

template <typename T>
const T&  CP::stack<T>::top() const {
    //write your code here
    if (size() == 0) throw std::out_of_range("index of out range") ;
    int n1 = mData.size() - 1;
    int n2 = mData[n1].size() - 1;
    return mData[n1][n2];   
}

/*
Push and pop with steady hand,
or tears may fall from teacher’s stand.
*/

#endif