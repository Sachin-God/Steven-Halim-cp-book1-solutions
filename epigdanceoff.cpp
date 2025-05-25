#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> bit(n, 0);
    
    string row;
    for (int i = 0; i < m; i++) {
        cin >> row;
        for (int j = 0; j < n; j++) {
            if (row[j] == '$') bit[j] = 1;
        }
    }
    
    int ans = 1;
    for (auto& x : bit) {
        if (x == 0) ans++;
    }
    
    cout<<ans;
    
    return 0;
}