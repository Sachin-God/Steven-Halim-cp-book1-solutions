#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>& shop, int target) {
    int lo = 0, hi = shop.size()-1;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (shop[mid] >= target) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    if (ans == -1) return 0;
    return shop[ans] - target;
}

int main () {
    int n, m; cin >> n >> m;
    vector<int> shop(n), paint(m);
    for (int i = 0; i < n; i++) cin >> shop[i];
    for (int i = 0; i < m; i++) cin >> paint[i];
    
    sort(begin(shop), end(shop));
    long long ans = 0;
    for (auto& x : paint) {
        ans += bs(shop, x);
    }
    cout << ans;
    return 0;
}