#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countCarries(const string& a, const string& b) {
    int carry = 0, totalCarries = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0) {
        int digitA = i >= 0 ? a[i] - '0' : 0;
        int digitB = j >= 0 ? b[j] - '0' : 0;

        int sum = digitA + digitB + carry;
        if (sum >= 10) {
            totalCarries++;
            carry = 1;
        } else {
            carry = 0;
        }

        i--;
        j--;
    }

    return totalCarries;
}

int main() {
    string x, y;
    while (cin >> x >> y) {
        if (x == "0" && y == "0") break;

        int carries = countCarries(x, y);

        if (carries == 0)
            cout << "No carry operation." << endl;
        else if (carries == 1)
            cout << "1 carry operation." << endl;
        else
            cout << carries << " carry operations." << endl;
    }
    return 0;
}
