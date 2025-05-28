#include <bits/stdc++.h>
using namespace std;

bool isBracket(char c) {
    return c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']';
}

bool isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string brack;
    getline(cin, brack);

    stack<char> st;
    bool oksofar = true;

    for (int i = 0; i < n; i++) {
        char c = brack[i];
        if (!isBracket(c)) continue;

        if (isOpening(c)) {
            st.push(c);
        } else {
            if (!st.empty() && isMatching(st.top(), c)) {
                st.pop();
            } else {
                // Print mismatch and its index
                cout << c << " " << i;
                oksofar = false;
                break;
            }
        }
    }

    if (oksofar) cout << "ok so far";

    return 0;
}
