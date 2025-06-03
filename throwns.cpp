#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string temp;
    stack<string> stk;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        if (temp == "undo") {
            int x;
            cin >> x;
            for (int j = 0; j < x; j++) stk.pop();
        } else {
            stk.push(temp);
        }
    }
    
    int pos = 0;
    // for (auto& x : stk) cout << x << " ";  -- Stack doesn't support for each range wise loops
    while (!stk.empty()) {
        pos += stoi(stk.top());
        stk.pop();
    }
    // here there is an another issue what if pos is -ve
    if (pos < 0) pos = (pos % n) + n;
    pos %= n;
    cout << pos;
    
    return 0;
}