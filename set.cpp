#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> cards(12);
    for (int i = 0; i < 12; i++) cin >> cards[i];
    
    bool found = false;
    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 11; j++) {
            for (int k = j+1; k < 12; k++) {
                bool valid = true;
                string a = cards[i], b = cards[j], c = cards[k];
                for (int l = 0; l < 4; l++) {
                    if (a[l] == b[l] && b[l] == c[l]) continue;
                    if (a[l] != b[l] && b[l] != c[l] && c[l] != a[l]) continue;
                    valid = false;
                    break;
                }
                if (valid) {
                    cout << i+1 << " " << j+1 << " " << k+1 << "\n";
                    found = true;
                }
            }
        }
    }
    if (!found) cout << "no sets\n";
}
