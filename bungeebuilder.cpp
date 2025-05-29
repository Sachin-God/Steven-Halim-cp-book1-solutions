#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, h; cin >> n;
    vector<int> heights;
    for (int i = 0; i < n; i++) {
        cin >> h;
        heights.push_back(h);
    }
    
    int ans = 0, curr_max_idx = 0, curr_min_idx = 0, curr_h;
    for (int i = 1; i < n; i++) {
        curr_h = heights[i];
        int h = min(curr_h, heights[curr_max_idx]);
        ans = max(ans, h - heights[curr_min_idx]);
        
        if (heights[i] > heights[curr_max_idx]) {
            curr_max_idx = i;
        }
        if (heights[i] < heights[curr_min_idx] || curr_max_idx > curr_min_idx) {
            curr_min_idx = i;
        }
    }
    
    cout << ans;
    
    return 0;
}