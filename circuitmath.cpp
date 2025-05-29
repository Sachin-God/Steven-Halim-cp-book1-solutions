#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> inputs;
    char cirVal;
    
    for (int i = 0; i < n; i++) {
        cin >> cirVal;
        if (cirVal == 'T') inputs.push_back(1);
        else inputs.push_back(0);
    }
    
    cin.ignore();
    string circuit;
    getline(cin, circuit);
    stack<bool> stk;
    
    for (int i = 0; i < circuit.length(); i++) {
        if (circuit[i] == ' ') continue;
        if (stk.empty() || circuit[i] >= 'A' || circuit[i] >= 'Z') {
            int idx = circuit[i] - 'A';
            stk.push(inputs[idx]);
        } else if (circuit[i] == '*') {
            bool prev = stk.top(); stk.pop();
            stk.top() &= prev;
        } else if (circuit[i] == '+') {
            bool prev = stk.top(); stk.pop();
            stk.top() |= prev;
        } else {
            stk.top() = !stk.top();
        }
    }
    
    cout << ((stk.top()) ? 'T' : 'F');
    
    return 0;
}