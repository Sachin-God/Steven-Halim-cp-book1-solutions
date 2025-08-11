#include <bits/stdc++.h>
using namespace std;

int main() {
    int winner = 1, points = 0;
    for (int i = 0; i < 5; i++) {
        int p = 0, temp;
        for (int j = 0; j < 4; j++) {
            cin >> temp;
            p += temp;
        }
        if (p > points) {
            points = p; winner = i+1;
        }
    }
    
    cout << winner << " " << points;
}