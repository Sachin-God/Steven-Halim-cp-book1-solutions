#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

// macros
#define umap(KEY, VALUE) unordered_map<KEY, VALUE>

int main() {
    int n;
    cin >> n;
    vi teaprices(n);
    for (int i = 0; i < n; i++) cin >> teaprices[i];
    
    int m;
    cin >> m;
    vi toppingsprices(m);
    for (int i = 0; i < m; i++) cin >> toppingsprices[i];
    
    int x, y;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> y;
            minPrice = min(minPrice, teaprices[i] + toppingsprices[y - 1]);
        }
    }
    
    int totalmoney;
    cin >> totalmoney;

    // Check if the totalmoney is enough to buy at least one combination
    if (totalmoney < minPrice) {
        cout << 0 << endl;
    } else {
        cout << (totalmoney / minPrice) - 1 << endl;
    }
    
    return 0;
}
