#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> keypad;
vector<int> num;
void gen(int idx, int r, int c, string n) {
    if (idx == 3 || r == 4 || c == 3) {
        if (n.length() > 0) num.push_back(stoi(n));
        return;
    }
    if (r < 4 && c < 3) {
        if (keypad[r][c] != ' ') gen(idx+1, r, c, n + keypad[r][c]);
        gen(idx, r+1, c, n);
        gen(idx, r, c+1, n);
    }
}

int main() {
    keypad.resize(4, vector<char> (3, ' '));
    string keys = "123456789 0 "; int c = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            keypad[i][j] = keys[c++];
        }
    }
    
    gen(0, 0, 0, "");
    sort(num.begin(), num.end());
    
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        int idx = lower_bound(num.begin(), num.end(), k) - num.begin();
        int df = abs(num[idx] - k);
        int n = num[idx];
        if (idx + 1 < num.size()) {
            if (df > abs(num[idx+1] - k)) {
                df = abs(num[idx+1] - k);
                n = num[idx+1];
            }
        }
        
        if (idx - 1 >= 0) {
            if (df > abs(num[idx-1] - k)) {
                df = abs(num[idx-1] - k);
                n = num[idx-1];
            }
        }
        
        cout << n << "\n";
    }
}