#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    unordered_set<int> CDs;
    int cd;
    
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        CDs.clear();
        int same = 0;
        
        while (n--) {
            cin >> cd;
            CDs.insert(cd);
        }
        while (m--) {
            cin >> cd;
            if (CDs.find(cd) != CDs.end()) same++;
        }
        cout << same << endl;
    }

    return 0;
}