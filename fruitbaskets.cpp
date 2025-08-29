#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
void solve(int idx, vector<long long>& fruits, long long weight) {
    if (weight >= 200) return;
    if (idx == fruits.size()) {
        if (weight < 200) ans += weight;
        return;
    }
    solve(idx+1, fruits, weight+fruits[idx]);
    solve(idx+1, fruits, weight);
}

int main() {
    int n; cin >> n;
    vector<long long> fruits(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) cin >> fruits[i];
    for (int i = 0; i < n; i++) sum += fruits[i];
    solve(0, fruits, 0);
    cout << (sum *(1LL << (n-1)) - ans);
}