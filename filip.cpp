#include<bits/stdc++.h>
using namespace std;

int reverse(int num) {
    int revnum = 0;
    while (num > 0) {
        revnum = revnum*10 + num%10;
        num /= 10;
    }
    return revnum;
}

int main() {
    int a, b;
    cin>>a>>b;
    cout<<max(reverse(a), reverse(b));
    return 0;
}