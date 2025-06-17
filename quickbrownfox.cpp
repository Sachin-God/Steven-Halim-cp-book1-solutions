#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Skip the leftover newline after reading the integer

    for (int k = 0; k < n; k++) {
        string s;
        getline(cin, s); 

        vector<bool> present(26, false);

        for (char c : s) {
            if (isalpha(c)) {
                c = tolower(c);
                present[c - 'a'] = true;
            }
        }

        string missing = "";
        for (int i = 0; i < 26; i++) {
            if (!present[i])
                missing += (char)(i + 'a');
        }

        if (missing.empty()) {
            cout << "pangram\n";
        } else {
            cout << "missing " << missing << '\n';
        }
    }

    return 0;
}
