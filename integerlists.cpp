#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        string operation, sequence;
        int m;
        cin >> operation >> m >> sequence;

        // Parse the input sequence
        deque<string> dq;
        if (m > 0) {
            sequence.pop_back(); // remove ']'
            sequence.erase(0, 1); // remove '['
            stringstream ss(sequence);
            string temp;
            while (getline(ss, temp, ',')) {
                dq.push_back(temp);
            }
        }

        // Check for too many 'D' operations
        int drop = count(operation.begin(), operation.end(), 'D');
        if (drop > m) {
            cout << "error\n";
            continue;
        }

        // Process operations
        bool rev = false, err = false;
        for (char x : operation) {
            if (x == 'R') {
                rev = !rev;
            } else {
                if (dq.empty()) {
                    err = true;
                    break;
                }
                if (rev) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (err) {
            cout << "error\n";
            continue;
        }

        // Print the result
        cout << "[";
        if (rev) reverse(dq.begin(), dq.end());
        for (size_t i = 0; i < dq.size(); ++i) {
            cout << dq[i];
            if (i < dq.size() - 1) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
