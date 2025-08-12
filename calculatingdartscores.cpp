#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool found = false;
    for (int i = 1; i <= 20 && !found; i++) {
        for (int j = 1; j <= 20 && !found; j++) {
            for (int k = 1; k <= 20 && !found; k++) {
                for (int a = 1; a <= 3 && !found; a++) {
                    for (int b = 0; b <= 3 && !found; b++) {
                        for (int c = 0; c <= 3 && !found; c++) {
                            if (a*i + b*j + c*k == n) {
                                if (a == 1) cout << "single " << i;
                                else if (a == 2) cout << "double " << i;
                                else cout << "triple " << i;
                                cout << "\n";
                                
                                if (b == 0) cout << "";
                                else if (b == 1) cout << "single " << j << "\n";
                                else if (b == 2) cout << "double " << j << "\n";
                                else cout << "triple " << j << "\n";
                                
                                if (c == 0) cout << "";
                                else if (c == 1) cout << "single " << k << "\n";
                                else if (c == 2) cout << "double " << k << "\n";
                                else cout << "triple " << k << "\n";
                                found = true;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (!found) cout << "impossible";
}