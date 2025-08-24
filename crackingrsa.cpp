#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    unordered_set<int> primes;
    vector<bool> prime(1001, true);
    prime[0] = false, prime[1] = false;
    for (int i = 2; i < 1001; i++) {
        if (!prime[i]) continue;
        for (int j = i+i; j < 1001; j += i) {
            prime[i] = false;
        }
        primes.insert(i);
    }
    
    while (t--) {
        int n; long long e; cin >> n >> e;
        int p, q;
        for (auto& x : primes) {
            if (n % x != 0) continue;
            int y = n / x;
            if (primes.find(y) == primes.end()) continue;
            p = x; q = y;
        }
        
        long long totient = (p-1)*(q-1);
        
        for (long long i = 2; i < totient; i++) {
            if ((e*i - 1) % totient == 0) {cout << i << "\n"; break;}
        }
    }
}