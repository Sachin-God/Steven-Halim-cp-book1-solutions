#include<bits/stdc++.h>
using namespace std;

bool validBoard(vector<string>& board, int i, int j) {
    if (i-1 >= 0) {
        if (j-2 >= 0 and board[i-1][j-2] == 'k') return false;
        if (j+2 < 5 and board[i-1][j+2] == 'k') return false;
    }
    if (i+1 < 5) {
        if (j-2 >= 0 and board[i+1][j-2] == 'k') return false;
        if (j+2 < 5 and board[i+1][j+2] == 'k') return false;
    }
    if (i+2 < 5) {
        if (j-1 >= 0 and board[i+2][j-1] == 'k') return false;
        if (j+1 < 5 and board[i+2][j+1] == 'k') return false;
    }
    if (i-2 >= 0) {
        if (j-1 >= 0 and board[i-2][j-1] == 'k') return false;
        if (j+1 < 5 and board[i-2][j+1] == 'k') return false;
    }
    return true;
}

int main() {
    vector<string> board;
    string temp;
    while (cin >> temp) board.push_back(temp);
    int knights = 0;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 'k') {
                if (!validBoard(board, i, j)) {
                    cout << "invalid" << endl;
                    return 0;
                }
                knights++;
            }
        }
    }
    cout<<((knights == 9) ? "valid" : "invalid");
    
    return 0;
}