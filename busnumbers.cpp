#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int bus;
    vector<bool> buses(1001, false);
    while (n--) {
        cin >> bus;
        buses[bus] = true;
    }
    
    int i = 1, j;
    while (i < 1001) {
        if (buses[i]) {
            j = i+1;
            while (j < 1001 && buses[j]) j++;
            if (j - i > 2) {
                cout << to_string(i) << "-" << to_string(j-1) << " ";
                i = j;
            } else {
                cout << to_string(i) << " ";
                i++;
            } 
        } else i++;
    }
    
    return 0;
}