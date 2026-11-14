#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<int> v(1e5 + 5);
    vector<pair<int, int>> change(n);

    for(int i = 0; i < n; ++i) {
        cin >> change[i].first >> change[i].second;
    }
    
    sort(change.begin(), change.end());
    int prev_idx = 0, prev_s = s;

    for(int i = 0; i < n; ++i) {
        auto [a, x] = change[i];
        fill(v.begin() + prev_idx, v.begin() + a, prev_s);
        prev_idx = a;
        prev_s = x;
    }
    fill(v.begin() + prev_idx, v.end(), prev_s);

    vector<long long> sum(1e5 + 5);
    sum[0] = v[0];
    for(int i = 1; i < v.size(); ++i) {
        sum[i] = sum[i - 1] + v[i];
    }

    while(m--) {
        int p, x;
        cin >> p >> x;

        auto it = lower_bound(sum.begin(), sum.end(), p);
        if(it - sum.begin() <= x) {
            cout << it - sum.begin() << ' ';
        } else {
            it -= (it - sum.begin()) - x;
            auto it2 = lower_bound(sum.begin(), sum.end(), *it + p);
            cout << it2 - sum.begin() << ' ';
        }
    }

    return 0;
}