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

pii direction(int& angle, int move) {
    angle = (angle + move + 360) % 360; // prevent negative angles
    if (angle == 0) return {0, 1};      // Right
    if (angle == 90) return {1, 0};     // Down
    if (angle == 180) return {0, -1};   // Left
    if (angle == 270) return {-1, 0};   // Up
    return {0, 0};
}

int main() {
    vector<string> board;
    string l;
    
    int r, c;
    for (int i = 0; i < 8; i++) {
        cin>>l;
        board.push_back(l);
        for(int j = 0; j < 8; j++) {
            if (l[j] == 'T') {
                r = i;
                c = j;
            }
        }
    }
    
    string instructions;
    cin>>instructions;
    pii dir = {0,1};
    int angle = 0;
    bool diamond = true;
    
    for (auto& i : instructions) {
        if (i == 'F') {
            r += dir.first;
            c += dir.second;
        } else if (i == 'R') {
            dir = direction(angle, 90);
        } else if (i == 'L') {
            dir = direction(angle, -90);
        } else {
            int nr = r + dir.first;
            int nc = c + dir.second;
        
            if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8 || board[nr][nc] != 'I') {
                diamond = false;
                break;
            }
            board[nr][nc] = '.'; // Melt the ice castle
        }
        
        if (r < 0 || r >= 8 || c < 0 || c >= 8 || board[r][c] == 'C' || board[r][c] == 'I') {
            diamond = false;
            break;
        }
    }
    
    if (diamond && board[r][c] == 'D') cout << "Diamond!" << endl;
    else cout << "Bug!" << endl;
    
    return 0;
}