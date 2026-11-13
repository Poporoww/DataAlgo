#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<long long, long long> father;
    while(n--) {
        long long f, s;
        cin >> f >> s;
        father[s] = f;
    }

    while(m--) {
        long long a, b;
        cin >> a >> b;

        long long gpa = father[father[a]], gpb = father[father[b]];

        if(gpa == gpb and gpa != 0 and gpb != 0 and a != b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}