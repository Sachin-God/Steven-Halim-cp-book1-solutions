#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string sentence;
        getline(cin, sentence);
        
        deque<char> line;
        auto cursor = line.begin();
        
        for (char x : sentence) {
            if (x == ']') cursor = line.end();
            else if (x == '[') cursor = line.begin();
            else if (x == '<') {
                if (cursor != line.begin()) {
                    cursor = line.erase(prev(cursor));
                }
            } else {
                cursor = line.insert(cursor, x);
                ++cursor;
            }
        }

        for (char ch : line) cout << ch;
        if (i < n - 1) cout << endl;
    }

    return 0;
}
