#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> res(n, 0);
    
    int t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t;
            res[i] |= t;
            res[j] |= t;
        }
    }
    
    for (auto& x : res) cout << x << " ";
    
    return 0;
}