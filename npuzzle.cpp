#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> original = {"ABCD", "EFGH", "IJKL", "MNO."};
    vector<string> given(4);
    for (int i = 0; i < 4; i++) cin >> given[i];
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (given[i][j] == '.') continue;
            bool found = false;
            for (int x = 0; x < 4 && !found; x++) {
                for (int y = 0; y < 4 && !found; y++) {
                    if (original[x][y] == given[i][j]) {
                        ans += abs(i-x) + abs(j-y);
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
    
}