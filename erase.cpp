#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    bool deleted = true;
    if (n % 2 == 0) {
        // Even number of deletions: s should be equal to t
        if (s != t) deleted = false;
    } else {
        // Odd number of deletions: each bit in s should be flipped in t
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[i]) {
                deleted = false;
                break;
            }
        }
    }

    cout << (deleted ? "Deletion succeeded" : "Deletion failed") << endl;
    return 0;
}
