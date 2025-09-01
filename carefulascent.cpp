#include <bits/stdc++.h>
using namespace std;

int main() {
    double x, y; cin >> x >> y;
    int n; cin >> n;
    if (n == 0) printf("%.6f", (x / y));
    else {
        vector<pair<double, double>> py;
        double dis = 0.0;
        for (int i = 0; i < n; i++) {
            double l, u, f;
            cin >> l >> u >> f;
            py.push_back({l,u});
            dis += (u-l) * f;
        }
        
        sort(py.begin(), py.end());
        dis += py[0].first;
        for (int i = 1; i < py.size(); i++) {
            dis += py[i].first - py[i-1].second;
        }
        dis += y - py.back().second;
        if (x == 0) cout << 0;
        else printf("%.6f", (x / dis));
    }
}