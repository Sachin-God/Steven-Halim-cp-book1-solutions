#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> fav(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> fav[i];
        q.push(i);
        fav[i]--;
    }
    
    int size = n;
    while (size > 1) {
        int rem = fav[q.front()] % size;
        while (rem--) {
            int f = q.front(); q.pop();
            q.push(f);
        }
        q.pop();
        size--;
    }
    
    cout << q.front()+1;
}