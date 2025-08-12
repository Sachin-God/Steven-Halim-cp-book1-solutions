#include<bits/stdc++.h>
using namespace std;

int sum_of_digits(string s) {
    int sum = 0;
    for (auto& x : s) sum += x - '0';
    return sum;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int sum = sum_of_digits(to_string(n));
        for (int i = 11; ;i++) {
            if (sum == sum_of_digits(to_string(n*i))) {
                cout << i << "\n";
                break;
            }
        }
    }
}