#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> s;
    
    while(!a.empty()) {
        auto v = a.top();
        a.pop();

        std::vector<std::queue<int>> vv;
        for(auto q : v) {
            std::queue<int> qq;
            while(!q.empty()) {
                auto x = q.front();
                q.pop();
                if(x == from) qq.push(to);
                else qq.push(x);
            }
            vv.push_back(qq);
        }

        s.push(vv);
    }

    while(!s.empty()) {
        a.push(s.top());
        s.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    for(auto [key, val] : a) {
        auto [pq, i] = val;

        std::priority_queue<int> tmp;
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();

            if(x == from) tmp.push(to);
            else tmp.push(x);
        }   
        if(i == from) i = to;

        a[key] = make_pair(tmp, i);
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> s;
    for(auto [l, mp] : a) {
        std::map<int, std::pair<int, string>> tmp;
        for(auto [key, val] : mp) {
            auto [i, s] = val;
            int k = (key == from) ? to : key;
            if(i == from) i = to;
            tmp[k] = {i, s};
        }

        std::list<int> ls;
        for(auto i : l) {
            if(i == from) ls.push_back(to);
            else ls.push_back(i);
        }
        s.insert(make_pair(ls, tmp));
    }    
    a = s;
}

#endif
