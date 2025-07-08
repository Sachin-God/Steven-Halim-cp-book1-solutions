#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

// Multiset using pair to allow duplicates
typedef tree<pair<long long, int>, null_type, less<pair<long long, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ost sorted;
        long long temp, count = 0;
        int idx = 0;

        for (int i = 1; i <= n; i++) {
            cin >> temp;
            sorted.insert({temp, idx++});

            if (i % 2 == 0) {
                long long left = sorted.find_by_order(i / 2 - 1)->first;
                long long right = sorted.find_by_order(i / 2)->first;
                count += (left + right) / 2;
            } else {
                count += sorted.find_by_order(i / 2)->first;
            }
        }

        cout << count << endl;
    }

    return 0;
}
