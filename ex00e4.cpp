#include <bits/stdc++.h>
using namespace std;

int a, b;

void barcode(string s, int ones) {
    if(ones > a) return;
    if(s.size() == b) {
        if(ones == a) {
            cout << s << '\n';            
        }
        return;
    }

    s += "0";
    barcode(s, ones);
    s.pop_back();
    s += "1";
    barcode(s, ones + 1);
    s.pop_back();

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> a >> b;

    barcode("", 0);

    return 0;
}