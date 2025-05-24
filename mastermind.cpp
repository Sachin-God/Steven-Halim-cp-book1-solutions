#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string t, u;
    cin >> n >> t >> u;
    int r = 0, s = 0;
    
    unordered_map<char, int> mpt, mpu;
    
    for (int i = 0; i < n; i++) {
        if (t[i] == u[i]) {
            r++;
        } else {
            mpt[t[i]]++;
            mpu[u[i]]++;
        }
    }
    
    for (auto& [key, val] : mpt) {
        if (mpu.find(key) != mpu.end()) {
            s += min(val, mpu[key]);
        }
    }
    
    cout << r << " " << s;
    
    return 0;
}