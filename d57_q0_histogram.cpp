#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    map<string, int> mp;
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++mp[s];
    }

    for(auto [key, val] : mp) {
        if(val > 1) cout << key << ' ' << val << '\n';
    }

    return 0;
}