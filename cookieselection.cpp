#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    string input;
    int size = 0;
    ost cookies;

    while (cin >> input) {
        if (input == "#") {
            if (cookies.empty()) continue;

            int median_idx = size / 2;
            auto it = cookies.find_by_order(median_idx);

            cout << it->first << endl;
            cookies.erase(it);
            size--;
        } else {
            try {
                int diameter = stoi(input);
                if (diameter > 300000000) continue;
                cookies.insert({diameter, size++});
            } catch (...) {
                continue;
            }
        }
    }

    return 0;
}
