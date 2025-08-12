#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> arr;
vector<vector<int>> overlaps; // precomputes the overlap between i and j pairs basically computing no. of same performers in them
int ans = INT_MAX;
void permutations(int idx, const int& n, vector<int> temp, vector<bool>& check) {
    if (idx == n) {
        int tempans = 0;
        for (int i = 0; i < temp.size()-1; i++) {
            tempans += overlaps[temp[i]][temp[i+1]];
        }
        ans = min(ans, tempans);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        check[i] = true;
        temp.push_back(i);
        permutations(idx+1, n, temp, check);
        temp.pop_back();
        check[i] = false;
    }
}

int main() {
    int n; cin >> n;
    arr.resize(n, vector<bool> (26, false));
    string temp;
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (auto& x : temp) {
            arr[i][x-'A'] = true;
        }
    }
    
    vector<bool> t(n, false);
    overlaps.resize(n, vector<int> (n, 0));
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < 26; k++) {
                if (arr[i][k] && arr[j][k]) {overlaps[i][j]++; overlaps[j][i]++;}
            }
        }
    }
    permutations(0, n, vector<int> (), t);
    
    cout << ans;
}