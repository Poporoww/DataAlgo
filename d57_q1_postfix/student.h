#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT
  stack<int> s;
  for(auto [op, val] : v) { 
    if(op == 1) {
      s.push(val);
    } else {
      int b = s.top(); s.pop();
      int a = s.top(); s.pop();
      if(val == 0) s.push(a + b);
      else if(val == 1) s.push(a - b);
      else if(val == 2) s.push(a * b);
      else s.push(a / b);
    }
  }
  return s.top();
}

#endif
