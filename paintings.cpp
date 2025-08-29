#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void solve(vector<string>& colors, unordered_map<string, unordered_set<string>>& notlike,
           vector<string>& temp, vector<bool>& visited, int& count) {
    if (temp.size() == colors.size()) {
        if (ans.empty()) ans = temp;
        count++;
        return;
    }
    
    for (int i = 0; i < colors.size(); i++) {
        if (visited[i]) continue;
        
        string c1 = colors[i];
        if (!temp.empty() && notlike[c1].count(temp.back())) continue;

        visited[i] = true;
        temp.push_back(c1);

        solve(colors, notlike, temp, visited, count);

        temp.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> colors(n);
        for (int i = 0; i < n; i++) cin >> colors[i];

        int m; cin >> m;
        unordered_map<string, unordered_set<string>> notlike;
        string c1, c2;
        for (int i = 0; i < m; i++) {
            cin >> c1 >> c2;
            notlike[c1].insert(c2);
            notlike[c2].insert(c1);
        }
        
        vector<string> temp;
        ans.clear();
        vector<bool> visited(n, false);
        int count = 0;

        solve(colors, notlike, temp, visited, count);

        cout << count << "\n";
        if (!ans.empty()) {
            for (auto& x : ans) cout << x << " ";
        }
        cout << "\n";
    }
}
