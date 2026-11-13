#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    set<int> s;
    for(int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        if(d > 0 and d <= n) s.insert(d);
    }

    if(s.size() == n) cout << "YES";
    else cout << "NO";

    return 0;
}