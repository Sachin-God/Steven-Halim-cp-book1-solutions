#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> arr, right_small(n, -1),  left_large(n, -1);
    cin >> x;
    int curr_big = x;
    arr.push_back(x);
    
    for (int i = 1; i < n; i++) {
        cin >> x;
        arr.push_back(x);
        if (x < curr_big) right_small[i] = 0;
        else curr_big = x;
    }
    
    int curr_small = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        x = arr[i];
        if (x >= curr_small) left_large[i] = 0;
        else curr_small = x;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (left_large[i] == -1 && right_small[i] == -1) {
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}