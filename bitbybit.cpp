#include<bits/stdc++.h>
using namespace std;

// we don't know any thing about ? bit so assumming it as both 0 and 1 so we are forming when the result is sure 
char OR(char x, char y) {
    // if either of one is 1 that means its automatically 1 acc to or logic
    if (x == '1' || y == '1') {
        return '1';
    } else if (x == '0' && y == '0') { // if both are false
        return '0';
    }
    return '?';
}

char AND(char x, char y) {
    // if either of one is 0 that means its automatically 0 acc to and logic
    if (x == '0' || y == '0') {
        return '0';
    } else if (x == '1' && y == '1') { // if both are false
        return '1';
    }
    return '?';
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        string ins;
        int i, j;
        string str(32, '?');
        for (int k = 0; k < n; k++) {
            cin >> ins;
            if (ins == "SET") {
                cin >> i;
                i = 31 - i;
                str[i] = '1';
            } else if (ins == "CLEAR") {
                cin >> i;
                i = 31 - i;
                str[i] = '0';
            } else if (ins == "OR") {
                cin >> i >> j;
                i = 31 - i;
                j = 31 - j;
                str[i] = OR(str[i], str[j]);
            } else {
                cin >> i >> j;
                i = 31 - i;
                j = 31 - j;
                str[i] = AND(str[i], str[j]);
            }
        }
        cout << str<< endl;
    }
    
    return 0;
}