#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    while(m--) {
        int a, b;
        cin >> a >> b;

        auto it = upper_bound(v.begin(), v.end(), make_pair(a, b));

        if(it == v.begin()) {
            cout << "-1 -1 ";
        } else {
            --it;
            if(it->first == a and it->second == b) cout << "0 0 ";
            else cout << it->first << ' ' << it->second << ' ';
        }
    }

    return 0;
}