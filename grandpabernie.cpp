#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string country; int year;
    unordered_map<string,vector<int>> mp;
    
    while(n--) {
        cin >> country >> year;
        mp[country].push_back(year);
    }
    
    for (auto& [cntry, yr] : mp) sort(yr.begin(), yr.end());
    
    cin >> n;
    int idx;
    
    while (n--) {
        cin >> country >> idx;
        cout << mp[country][idx-1] << endl;
    }
    return 0;
}