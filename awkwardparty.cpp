#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x, ans = INT_MAX;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (mp.find(x) != mp.end()) ans = min(ans, i - mp[x].back());
        mp[x].push_back(i);
    }
    
    cout << ((ans == INT_MAX) ? n : ans);
    return 0;
}