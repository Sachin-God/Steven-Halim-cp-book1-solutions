#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c; cin >> r >> c;
    vector<string> parking(r);
    for (int i = 0; i < r; i++) cin >> parking[i];
    
    vector<int> count(5, 0);
    
    for (int i = 0; i < r-1; i++) {
        for (int j = 0; j < c-1; j++) {
            bool _break = false;
            int p = 0;
            for (int x = i; x < i+2 && !_break; x++) {
                for (int y = j; y < j+2 && !_break; y++) {
                    if (parking[x][y] == '#') {
                        _break = true;
                    } else if (parking[x][y] == 'X') p++;
                }
            }
            if (_break) continue;
            count[p]++;
        }
    }
    
    for (auto& x : count) cout << x << "\n";
}