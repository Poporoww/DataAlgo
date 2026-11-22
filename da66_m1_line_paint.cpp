#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    int prev = v[0].second;
    cout << v[0].first << ' ';

    for(int i = 1; i < v.size(); ++i) {
        if(v[i].first > prev + 1) {
            cout << prev << ' ' << v[i].first << ' ';
            prev = v[i].second;
        } else if(v[i].first <= prev + 1 and v[i].second >= prev) {
            prev = v[i].second;
        }
    }
    cout << prev;

    return 0;
}