#include <bits/stdc++.h>
using namespace std;

int seq(int prev) {
    int i = 2;
    while (true) {
        int curr = to_string(prev).length();
        if (curr == prev) {
            return i;
        } else {
            i++;
            prev = curr;
        }
    }
}

int main() {
    string n;
    while (true) {
        cin >> n;
        if (n == "END") {
            break;
        }

        int l = n.length();

        if (l < 8 && stoi(n) == l) {
            cout << 1 << endl;
        } else {
            cout << seq(l) << endl;
        }
    }
    return 0;
}
