#include<iostream>
#include<climits>
using namespace std;

int main() {
    int testCase = 0;
    while (true) {
        int mx = INT_MIN, mn = INT_MAX;
        testCase++;
        int k, x;
        if (!(cin >> k)) break;
        while (k--) {
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        cout<<"Case "<<testCase<<": "<<mn<<" "<<mx<<" "<<(mx-mn)<<endl;
    }
    return 0;
}