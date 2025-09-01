#include <bits/stdc++.h>
using namespace std;

double getHeight(const vector<pair<double,double>>& path, double t) {
    int i = lower_bound(path.begin(), path.end(), t,
                        [](const pair<double,double>& p, double val) {
                            return p.second < val;
                        }) - path.begin();
    if (i == 0) return (t / path[0].second) * path[0].first;
    if (i == path.size()) return path.back().first;

    auto [h1, t1] = path[i-1];
    auto [h2, t2] = path[i];
    return h1 + (h2 - h1) * (t - t1) / (t2 - t1);
}

int main() {
    int a, d; cin >> a >> d;
    double h, t; 
    vector<pair<double,double>> ascend, descend;

    for (int i = 0; i < a; i++) {
        cin >> h >> t;
        if (!ascend.empty()) {
            h += ascend.back().first;
            t += ascend.back().second;
        }
        ascend.push_back({h,t});
    }

    for (int i = 0; i < d; i++) {
        cin >> h >> t;
        if (!descend.empty()) {
            h += descend.back().first;
            t += descend.back().second;
        }
        descend.push_back({h,t});
    }

    double lo = 0, hi = descend.back().second;
    for (int iter = 0; iter < 100; iter++) {
        double mid = (lo+hi)/2;
        double ah = getHeight(ascend, mid);
        double dh = ascend.back().first - getHeight(descend, mid);
        if (ah >= dh) hi = mid;
        else lo = mid;
    }

    cout << fixed << setprecision(10) << lo << "\n";
}
