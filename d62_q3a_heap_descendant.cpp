#include <bits/stdc++.h>
using namespace std;

set<int> s;
int n, a;

void f(int i) {
    if(i >= n) return;

    s.insert(i);

    f(i * 2 + 1);
    f(i * 2 + 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> a;

    f(a);

    cout << s.size() << '\n';
    for(auto i : s) cout << i << ' ';

    return 0;
}