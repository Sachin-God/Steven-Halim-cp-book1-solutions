#include <bits/stdc++.h>
using namespace std;

#define LSOne(s) (s & -s)
typedef long long ll;

class FenwickTree {
private:
    vector<ll> ft;
    int n;
public:
    FenwickTree(int size) {
        n = size + 2;
        ft.assign(n, 0);
    }
    
    void update(int idx, ll val) {
        for (; idx < n; idx += LSOne(idx)) {
            ft[idx] += val;
        }
    }
    
    ll query(int idx) {
        ll sum = 0;
        for (; idx > 0; idx -= LSOne(idx)) {
            sum += ft[idx];
        }
        return sum;
    } 
};

int main() {
    int n, q;
    cin >> n >> q;

    array<ll, 7> val;
    for (int i = 1; i <= 6; i++) cin >> val[i];

    vector<FenwickTree> p(7, FenwickTree(n));

    string order;
    cin >> order;

    for (int i = 0; i < n; i++) {
        int digit = order[i] - '0';
        p[digit].update(i + 1, 1);
    }

    while (q--) {
        int type, idx;
        ll value;
        cin >> type >> idx >> value;

        if (type == 1) {
            int old_type = order[idx - 1] - '0';
            int new_type = (int)value;

            // Remove old type
            p[old_type].update(idx, -1);
            // Add new type
            p[new_type].update(idx, 1);

            order[idx - 1] = char(new_type + '0');

        } else if (type == 2) {
            val[idx] = value;

        } else {
            ll total = 0;
            for (int i = 1; i <= 6; i++) {
                total += (p[i].query(value) - p[i].query(idx - 1)) * val[i];
            }
            cout << total << "\n";
        }
    }

    return 0;
}
