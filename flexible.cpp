#include<bits/stdc++.h>
using namespace std;

int main() {
    int w, p; cin >> w >> p;
    vector<int> partitions(p+2);
    partitions[0] = 0; partitions[p+1] = w;
    for (int i = 1; i < p+1; i++) {
        cin >> partitions[i];
    }
    
    vector<bool> allowed(w+1, false);
    
    for (int i = 0; i < p+1; i++) {
        for (int j = i+1; j < p+2; j++) {
            int idx = partitions[j] - partitions[i];
            allowed[idx] = true;
        }
    }
    
    for (int i = 0; i < w+1; i++) {
        if (allowed[i]) cout << i << " ";
    }
}