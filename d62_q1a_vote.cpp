#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    priority_queue<int> pq;
    unordered_map<string, int> mp;

    for(int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        ++mp[x];
    }

    for(auto it = mp.begin(); it != mp.end(); ++it) {
        pq.push(it->second);
    }

    int score = 0;
    while(k-- and !pq.empty()) {
        score = pq.top();
        pq.pop();
    }

    cout << score;

    return 0;
}