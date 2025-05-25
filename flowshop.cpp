#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> progresstime(n, 0);
    
    int temp;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (j > 0) {
                progresstime[j] = max(progresstime[j], progresstime[j-1]) + temp;
            } else {
                progresstime[j] += temp;
            }
        }
        cout<<progresstime[n-1]<<((i < m-1) ? " " : "") ;
    }
    
    return 0;
}