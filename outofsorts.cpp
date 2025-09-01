#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> seq;
int bs(ll target) {
    int lo = 0, hi = seq.size()-1;
    while (lo <= hi) {
        int mid = (lo+hi) / 2;
        if (seq[mid] == target) return 1;
        else if (seq[mid] > target) hi = mid-1;
        else lo = mid+1;
    }
    return 0;
}

int main() {
    ll n, m, a, c, x; cin >> n >> m >> a >> c >> x;
    for (int i = 0; i < n; i++) {
        ll num = (a*x + c) % m;
        seq.push_back(num);
        x = num;
    }
    int ans = 0;
    for (auto& i : seq) ans += bs(i);
    cout << ans;
}