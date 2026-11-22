#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include <algorithm>

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  std::vector<size_t> r;
  //write your code here

  std::vector<int> v;
  for(auto &[key, val] : data) v.push_back(val);
  sort(v.begin(), v.end());;

  for(auto &[a, b]: queries) {
    auto it1 = lower_bound(v.begin(), v.end(), a);
    auto it2 = upper_bound(v.begin(), v.end(), b);
    r.push_back(it2 - it1);
  }
  return r;
}

#endif
