#include <bits/stdc++.h>
using namespace std;

vector<string> perms;

void permutations(int idx, const string& s, vector<bool>& temp, string t) {
    if (idx == s.size()) {
        perms.push_back(t);
        return;
    }
    
    for (int i = 0; i < s.size(); i++) {
        if (temp[i]) continue;
        temp[i] = true;
        permutations(idx+1, s, temp, t + s[i]);
        temp[i] = false;
    }
}

int main() {
    int n; cin >> n;
    vector<bool> temp(to_string(n).size(), false);
    permutations(0, to_string(n), temp, "");
    
    int d = INT_MAX;
    string ans = "0";
    for (auto& x : perms) {
        int diff = stoi(x) - n;
        if (diff > 0) {
            if (diff < d) {
                d = diff;
                ans = x;
            }
        } 
    }
    cout << ans;
}