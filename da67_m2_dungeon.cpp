#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, d, t, z;
    cin >> n >> d >> t >> z;
    
    vector<vector<int>> item(z);
    for(int i = 0; i < d; ++i) {
        int tt, zz;
        cin >> tt >> zz;
        item[zz].push_back(tt);
    }

    for(int i = 0; i < z; ++i) sort(item[i].begin(), item[i].end());
    vector<int> cur(z, 0);

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        int q;
        cin >> q;

        map<int, int> mp;
        for(int j = 0; j < q; ++j) {
            int x;
            cin >> x;
            mp[x]++;
        }

        bool pass = true;
        for(auto [key, val] : mp) {
            if(item[key].empty() or cur[key] >= item[key].size()) {
                pass = false;
                break;
            }

            while(val--) {
                if(item[key][cur[key]] > t) {
                    pass = false;
                    break;
                }
                t -= item[key][cur[key]];
                cur[key]++;
            }

            if(!pass) break;
        }

        if(pass) ++cnt;
        else break;
    }

    cout << cnt;

    return 0;
}