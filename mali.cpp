#include<bits/stdc++.h>
using namespace std;

int getCurrMax(vector<int> first, vector<int> second) {
    int i = 1, j = 100;
    int res = 0;
    while (i < 101 && j >= 0) {
        while (i < 101 && first[i] == 0) i++;
        while (j >= 0 && second[j] == 0) j--;
        if (i < 101 && j >= 0) {
            int idx = min(first[i], second[j]);
            res = max(res, i + j);
            first[i] -= idx;
            second[j] -= idx;
        }
    }
    return res;
}

int main() {
    int n; cin >> n;
    int i, j;
    vector<int> first(101, 0), second(101, 0);
    while (n--) {
        cin >> i >> j;
        first[i]++; second[j]++;
        cout << getCurrMax(first, second) << endl;
    }
    
    return 0;
}