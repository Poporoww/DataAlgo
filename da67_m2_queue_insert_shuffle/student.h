#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	queue<T> tmp;

	for(int i = 0; i < pos; ++i) {
		tmp.push(this->front());
		this->pop();
	}

	int i = 0;
	while(i < items.size() and !this->empty()) {
		tmp.push(items[i]);
		tmp.push(this->front());
		++i;
		this->pop();
	}

	while(!this->empty()) {
		tmp.push(this->front());
		this->pop();
	}
	
	while(i < items.size()) {
		tmp.push(items[i++]);
	}

	while(!tmp.empty()) {
		this->push(tmp.front());
		tmp.pop();
	}
}

#endif
