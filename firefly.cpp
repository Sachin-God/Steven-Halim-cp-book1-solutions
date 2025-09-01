#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h; 
    cin >> n >> h;
    vector<int> l, hi;
    bool alt = true;
    int t;

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (alt) l.push_back(t);
        else hi.push_back(h - t);      
        alt = !alt;
    }

    sort(begin(l), end(l));
    sort(begin(hi), end(hi));

    int hit = INT_MAX, cnt = 0;

    for (int i = 1; i <= h; i++) {
        int hits = l.end() - lower_bound(begin(l), end(l), i);
        hits += lower_bound(begin(hi), end(hi), i) - hi.begin();

        if (hits < hit) {
            hit = hits;
            cnt = 1;
        } else if (hits == hit) {
            cnt++;
        }
    }

    cout << hit << " " << cnt;
}
