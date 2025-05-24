#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.length(), n = t.length();
    int i = m-1, j = n-1;
    
    while (i >= 0 && j >= 0) {
        if (s[i] == '0' && t[j] == '0') {
            s.pop_back();
            t.pop_back();
            i--; j--;
            m--; n--;
        } else break;
    }
    
    int gap;
    if (m >= n) {
        gap = m - n + 1;
        if (gap < m) s.insert(gap, ".");
        cout << s;
    } else {
        gap = n - m - 1;
        string res = "0.";
        while (gap--) res += '0';
        cout << res + s;
    }
    
    return 0;
}