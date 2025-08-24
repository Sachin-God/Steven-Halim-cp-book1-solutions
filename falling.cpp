#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    bool found = false;

    for (long long a = 1; a * a <= n; a++) {
        if (n % a == 0) {
            long long b = n / a;
            if ((a + b) % 2 == 0) {
                long long i = (a + b) / 2;
                long long j = (b - a) / 2;
                if (j >= 0) {
                    cout << j << " " << i;
                    found = true;
                    break;
                }
            }
        }
    }
    if (!found) cout << "impossible";
}
