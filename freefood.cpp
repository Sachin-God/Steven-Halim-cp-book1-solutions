#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> interval;
    interval.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        auto& prev = interval.back();
        int u = intervals[i][0], v = intervals[i][1];
        if (u >= prev[0] && u <= prev[1]) {
            prev[1] = max(prev[1], v);
        } else {
            interval.push_back(intervals[i]);
        }
    }
    return interval;
}

int main() {
    int n; cin >> n;
    int u, v;
    vector<vector<int>> intervals;
    while (n--) {
        cin >> u >> v;
        intervals.push_back({u,v});
    }
    vector<vector<int>> res = merge(intervals);
    int ans = 0;
    for (auto& arr : res) {
        ans += arr[1] - arr[0] + 1;
    }
    
    cout << ans;
    
    return 0;
}