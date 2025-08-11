#include<bits/stdc++.h>
using namespace std;

#define LSOne(S) (S & -S)

class FenwickTree {
private:
    vector<long long> ft;
    int n;
public:
    FenwickTree(int _n) {
        n = _n+2;
        ft.assign(n, 0);
    }
    
    void update(int idx, long long val) {
        for (; idx < n; idx += LSOne(idx)) {
            ft[idx] += val;
        }
    }
    
    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= LSOne(idx)) {
            sum += ft[idx];
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q; cin >> n >> q;
    FenwickTree ft(n);
    
    while (q--) {
        char op; int idx; long long num;
        cin >> op;
        if (op == '+') {
            cin >> idx >> num;
            ft.update(idx+1, num);
        } else {
            cin >> idx;
            cout << ft.query(idx) << "\n";
        }
    }
    return 0;
}