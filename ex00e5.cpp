#include <bits/stdc++.h>
using namespace std;

int k, n;

void f(string s) {
    if(s.size() == n) {
        int pos1 = s.find('1', 0);
        int mx = 0;

        while(pos1 != string::npos) {
            int pos2 = s.find('0', pos1);
            if(pos2 == string::npos) pos2 = n;
            mx = max(pos2 - pos1, mx);
            pos1 = s.find('1', pos2);
        }

        if(mx >= k) cout << s << '\n';
        return;
    }

    s += "0";
    f(s);
    s.pop_back();
    s += "1";
    f(s);
    s.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;

    f("");

    return 0;
}