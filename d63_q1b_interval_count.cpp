#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    while(m--) {
        int p;
        cin >> p;

        auto low = lower_bound(v.begin(), v.end(), p - k);
        auto up = upper_bound(v.begin(), v.end(), p + k);

        cout << up - low << ' ';
    }

    return 0;
}