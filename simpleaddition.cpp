#include<bits/stdc++.h>
using namespace std;

int main() {
    string m, n; cin >> m >> n;
    int k = m.length(), l = n.length();
    int largestSize = max(k,l);
    
    reverse(m.begin(), m.end());
    reverse(n.begin(), n.end());
    
    for (int i = 0; i < largestSize - k; i++) m += '0';
    for (int i = 0; i < largestSize - l; i++) n += '0';
    
    int carry = 0, temp;
    string res = "";
    for (int i = 0; i < largestSize; i++) {
        int a = m[i] - '0', b = n[i] - '0';
        temp = (a+b+carry) / 10;
        res += (((a+b+carry) % 10) + '0');
        carry = temp;
    }
    if (carry > 0) res += (carry + '0');
    reverse(res.begin(), res.end());
    cout << res;
    
    return 0;
}