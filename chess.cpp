#include<bits/stdc++.h>
#include<complex>
#include<cmath>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

// macros
#define umap(KEY, VALUE) unordered_map<KEY, VALUE>
#define uset(KEY) unordered_set<KEY>
#define f(i, start, end) for(int i = start; i < end; i++)

bool sameColor(int x1, int y1, int x2, int y2) {
    return (x1 + y1) % 2 == (x2 + y2) % 2;
}

bool isDiagonal(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

string pos(int x, int y) {
    return string(1, 'A' + x) + " " + to_string(y + 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char col1, col2;
        int row1, row2;
        cin >> col1 >> row1 >> col2 >> row2;
        int x1 = col1 - 'A', y1 = row1 - 1;
        int x2 = col2 - 'A', y2 = row2 - 1;

        if (!sameColor(x1, y1, x2, y2)) {
            cout << "Impossible\n";
        } else if (x1 == x2 && y1 == y2) {
            // same position
            cout << "0 " << pos(x1, y1) << "\n";
        } else if (isDiagonal(x1, y1, x2, y2)) {
            // reachable in one move
            cout << "1 " << pos(x1, y1) << " " << pos(x2, y2) << "\n";
        } else {
            // try all positions to find a valid intermediate point
            bool found = false;
            f(x, 0, 8) {
                f(y, 0, 8) {
                    if (isDiagonal(x1, y1, x, y) && isDiagonal(x, y, x2, y2)) {
                        cout << "2 " << pos(x1, y1) << " " << pos(x, y) << " " << pos(x2, y2) << "\n";
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
    }
    return 0;
}
