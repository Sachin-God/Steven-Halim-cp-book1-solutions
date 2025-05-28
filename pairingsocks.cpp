#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n;
    stack<int> orig, auxi;
    int moves = 0;
    
    for (int i = 0; i < 2*n; i++) {
        cin >> x;
        orig.push(x);
    }
    
    while (!orig.empty()) {
        if (!auxi.empty() && auxi.top() == orig.top()) {
            auxi.pop();
            orig.pop();
        } else {
            auxi.push(orig.top());
            orig.pop();
        }
        moves++;
    }
    
    while (!auxi.empty()) {
        if (!orig.empty() && auxi.top() == orig.top()) {
            auxi.pop();
            orig.pop();
        } else {
            orig.push(auxi.top());
            auxi.pop();
        }
        moves++;
    }
    
    if (orig.empty()) cout << moves;
    else cout << "impossible";
    
    return 0;
}