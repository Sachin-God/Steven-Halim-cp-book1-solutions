#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> rolls(n);
    for (int i = 0; i < n; i++) cin >> rolls[i];

    vector<int> freq(7, 0);
    for (int x : rolls) freq[x]++;
    
    for (int val = 6; val >= 1; val--) {
        if (freq[val] == 1) {
            for (int i = 0; i < n; i++) {
                if (rolls[i] == val) {
                    cout << i + 1; 
                    return 0;
                }
            }
        }
    }

    cout << "none";
}
