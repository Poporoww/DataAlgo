#include <iostream>
#include <string>
#include "filter_vector.h"
#include "student.h"

using namespace std;

int main() {
  int n, cap;
  cin >> n >> cap;
  CP::filter_vector<int> vec(cap);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  string cmd;
  while (true) {
    cin >> cmd;
    int idx, val;
    int min, max;
    if (cmd == "acc") {
      cin >> idx;
      cout << vec[idx] << endl;
    } else if (cmd == "ins") {
      cin >> idx >> val;
      vec.insert(idx, val);
    } else if (cmd == "pop") {
      vec.pop_back();
    } else if (cmd == "sz") {
      cout << vec.size() << "," << vec.filtered_size() << endl;
    } else if (cmd == "bnd") {
      cin >> min >> max;
      vec.set_bounds(min, max);
    } else if (cmd == "print") {
      vec.print_vector();
    } else if (cmd == "q") {
      break;
    }
  }

  return 0;
}
