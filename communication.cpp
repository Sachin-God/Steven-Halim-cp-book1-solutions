#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    while (n--) {
        int c; cin >> c;
        for (char ch = 0; ch < 256; ch++) {
            char i = ch;
            if ((i ^ (i << 1)) != c) continue;
            if ((int)i < 0) cout << 256 + (int)i;
            else cout << (int)i;
            break;
        }
        cout << " ";
    }
}