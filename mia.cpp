#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x, y;
    while (cin>>a>>b>>x>>y) {
        if (a == 0) break;
        if (((a == 1 && b == 2) || (b == 1 && a == 2)) && ((x == 1 && y == 2) || (y == 1 && x == 2))) {
            cout<<"Tie."<<endl;
        } else if ((a == 1 && b == 2) || (b == 1 && a == 2)) {
            cout<<"Player 1 wins."<<endl;
        } else if ((x == 1 && y == 2) || (y == 1 && x == 2)) {
            cout<<"Player 2 wins."<<endl;
        } else if (x == y && a == b) {
            if (a > x) {
                cout<<"Player 1 wins."<<endl;
            } else if (a < x) {
                cout<<"Player 2 wins."<<endl;
            } else {
                cout<<"Tie."<<endl;
            }
        } else if (a == b) {
            cout<<"Player 1 wins."<<endl;
        } else if (x == y) {
            cout<<"Player 2 wins."<<endl;
        } else {
            int num1 = max(a,b)*10 + min(a,b);
            int num2 = max(x,y)*10 + min(x,y);
            if (num1 > num2) {
                cout<<"Player 1 wins."<<endl;
            } else if (num1 < num2) {
                cout<<"Player 2 wins."<<endl;
            } else {
                cout<<"Tie."<<endl;
            }
        }
    }
    return 0;
}