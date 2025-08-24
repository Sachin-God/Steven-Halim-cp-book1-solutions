#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unsigned long long ans = 0;
    bool impossible = false;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] == arr[i+1] && arr[i] == 0) {
            impossible = true;
            break;
        }
        if (arr[i] >= arr[i+1]) {
            long long newVal = arr[i+1] - 1;
            if (newVal < 0) { // cannot reduce below 0
                impossible = true;
                break;
            }
            ans += arr[i] - newVal;
            arr[i] = newVal;
        }
    }

    if (impossible) cout << 1;
    else cout << ans;
}
