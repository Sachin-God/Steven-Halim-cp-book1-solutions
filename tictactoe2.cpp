#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

bool isWinner(const vs& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        vs board(3);
        int x = 0, o = 0;
        for (int i = 0; i < 3; i++) {
            cin >> board[i];
            for (char c : board[i]) {
                if (c == 'X') x++;
                if (c == 'O') o++;
            }
        }

        bool xWins = isWinner(board, 'X');
        bool oWins = isWinner(board, 'O');

        if ((o + 1 == x || o == x) && !(xWins && oWins)) {
            if (xWins && x != o + 1) cout << "no" << endl;
            else if (oWins && x != o) cout << "no" << endl;
            else cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
