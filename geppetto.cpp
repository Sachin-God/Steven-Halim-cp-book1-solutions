#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> na;
int ans = 0;

void subset(int idx, const int& n, vector<bool> sub) {
    if (idx == n) {
        for (auto& [f,s] : na) {
            if (sub[f] && sub[s]) return;
        }
        ans++;
        return;
    }
    sub[idx] = true;
    subset(idx+1, n, sub);
    sub[idx] = false;
    subset(idx+1, n, sub);
}

int main () {
    int n, m; cin >> n >> m;
    na.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> na[i].first >> na[i].second;
    }
    
    subset(1, n+1, vector<bool> (n+1, false));
    cout << ans;
    
}