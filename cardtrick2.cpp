#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> pos(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        for (int i = 1; i < n+1; i++) {
            for (int j = i; j >= 0; j--) {
                int x = q.front(); q.pop();
                if (j == 0) pos[x] = i;
                else q.push(x);
            }
        }
        
        for (auto& x : pos) cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}