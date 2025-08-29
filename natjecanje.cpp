#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, r; cin >> n >> s >> r;
    vector<int> teams(n+1, 0);
    int temp;
    for (int i = 0; i < s; i++) {cin >> temp; teams[temp]--;}
    for (int i = 0; i < r; i++) {cin >> temp; teams[temp]++;}
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (teams[i] == -1) {
            if (i-1 >= 0 && teams[i-1] == 1) {
                teams[i]++; teams[i-1]--;
            }
            if (i+1 <= n && teams[i+1] == 1 && teams[i] == -1) {
                teams[i]++; teams[i+1]--;
            }
            count += teams[i];
        } 
    }
    cout << -count;
}