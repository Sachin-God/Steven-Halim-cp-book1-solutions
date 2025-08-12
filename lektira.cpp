#include <bits/stdc++.h>
using namespace std;

int main() {
    string word; cin >> word;
    string ans = word;
    int n = word.size();
    for (int i = 1; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            string s = word;
            int x = 0, y = i-1;
            while (x <= y) swap(s[x++], s[y--]);
            
            x = i, y = j-1;
            while (x <= y) swap(s[x++], s[y--]);
            
            x = j, y = n-1;
            while (x <= y) swap(s[x++], s[y--]);
            
            ans = min(s, ans);
        }
    }
    cout << ans;
}