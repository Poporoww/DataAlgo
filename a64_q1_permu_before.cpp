#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, vector<int>> mp;

void perm(vector<int> v, vector<bool> used) {
    for(auto [k, val] : mp) {
        auto it1 = find(v.begin(), v.end(), k);
        for(auto i : val) {
            auto it2 = find(v.begin(), v.end(), i);
            //cout << it1 - v.begin() << ' ' << it2 - v.begin() << '\n';
            if(it2 < it1) return;
        }
    }

    if(v.size() == n) {
        for(auto i : v) cout << i << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(!used[i]) {
            used[i] = true;
            v.push_back(i);
            perm(v, used);
            used[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }

    vector<bool> used(n, false);
    perm({}, used);

    return 0;
}