#include<bits/stdc++.h>
using namespace std;

int main() {
    int p, a, b, c, d, n;
    cin>>p>>a>>b>>c>>d>>n;
    vector<double> prices;
    for (int i = 1; i <= n; i++) {
        int sinangle = a*i + b;
        int cosangle = c*i + d;
        prices.push_back(p*(sin(sinangle) + cos(cosangle) + 2));
    }
    double ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (prices[i] > prices[j]) j = i;
        ans = max(ans, prices[j] - prices[i]);
    }
    printf("%.7lf\n", ans);
    return 0;
}