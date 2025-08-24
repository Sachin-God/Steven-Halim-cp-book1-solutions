#include<bits/stdc++.h>
using namespace std;

int main() {
    int p; cin >> p;
    while (p--) {
        int k; cin >> k;
        array<int, 12> arr;
        for (int i = 0; i < 12; i++) cin >> arr[i];
        int count = 0;
        for (int i = 1; i < 11; i++) {
            int currmin = arr[i];
            for (int j = i; j < 11; j++) {
                currmin = min(currmin, arr[j]);
                if (arr[i-1] < currmin && arr[j+1] < currmin) count++;
            }
        }
        
        cout << k << " " << count << "\n";
    }
}