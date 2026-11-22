#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> s;

void recur(int i) {
    if(i == m) return;
    if(i > n - 1) return;
    s.insert(i);
    recur(2*i + 1);
    recur(2*i + 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    recur(0);

    cout << s.size() << '\n';
    for(int i : s) cout << i << ' ';

    return 0;
}