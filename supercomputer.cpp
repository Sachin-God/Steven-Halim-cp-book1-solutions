#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & -S)

class FenwickTree {
private:
    vector<int> ft, arr;
    int n;
public:
    FenwickTree(int _n) {
        n = _n+2;
        ft.assign(n, 0);
        arr.assign(n, 0);
    }
    
    void update(int idx) {
        int val = arr[idx] == 0 ? 1 : -1;
        arr[idx] = (1 + arr[idx]) % 2;
        for (; idx < n; idx += LSOne(idx)) {
            ft[idx] += val;
        }
    }
    
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= LSOne(idx)) {
            sum += ft[idx];
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    FenwickTree ft(n);
    
    while (k--) {
        char op; int i, j;
        cin >> op;
        if (op == 'F') {
            cin >> i;
            ft.update(i+1);
        } else {
            cin >> i >> j;
            cout << ft.query(j+1) - ft.query(i) << "\n";
        }
    }
    return 0;
}