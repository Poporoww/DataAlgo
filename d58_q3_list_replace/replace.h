void replace(const T& x, list<T>& y) {  
  auto cur = begin();

  while(cur != end()) {
    auto tmp = cur;
    ++tmp;

    if(*cur == x) {
      for(auto it = y.begin(); it != y.end(); ++it) {
        insert(cur, *it);
      }
      erase(cur);
    }

    cur = tmp;
  }

}
