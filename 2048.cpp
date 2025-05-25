#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> puzzle(4, vector<int>(4, 0));
    int n;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> puzzle[i][j];
        }
    }

    cin >> n;

    // Move Left
    if (n == 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = j + 1; k < 4; k++) {
                    if (puzzle[i][k] == 0) continue;
                    if (puzzle[i][k] == puzzle[i][j]) {
                        puzzle[i][j] *= 2;
                        puzzle[i][k] = 0;
                        break;
                    }
                    if (puzzle[i][k] > 0) break;
                }
            }

            for (int j = 0; j < 4; j++) {
                if (puzzle[i][j] == 0) {
                    for (int k = j + 1; k < 4; k++) {
                        if (puzzle[i][k] > 0) {
                            puzzle[i][j] = puzzle[i][k];
                            puzzle[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    // Move Up
    else if (n == 1) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) {
                for (int k = i + 1; k < 4; k++) {
                    if (puzzle[k][j] == 0) continue;
                    if (puzzle[k][j] == puzzle[i][j]) {
                        puzzle[i][j] *= 2;
                        puzzle[k][j] = 0;
                        break;
                    }
                    if (puzzle[k][j] > 0) break;
                }
            }

            for (int i = 0; i < 4; i++) {
                if (puzzle[i][j] == 0) {
                    for (int k = i + 1; k < 4; k++) {
                        if (puzzle[k][j] > 0) {
                            puzzle[i][j] = puzzle[k][j];
                            puzzle[k][j] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    // Move Right
    else if (n == 2) {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 0; j--) {
                for (int k = j - 1; k >= 0; k--) {
                    if (puzzle[i][k] == 0) continue;
                    if (puzzle[i][k] == puzzle[i][j]) {
                        puzzle[i][j] *= 2;
                        puzzle[i][k] = 0;
                        break;
                    }
                    if (puzzle[i][k] > 0) break;
                }
            }

            for (int j = 3; j >= 0; j--) {
                if (puzzle[i][j] == 0) {
                    for (int k = j - 1; k >= 0; k--) {
                        if (puzzle[i][k] > 0) {
                            puzzle[i][j] = puzzle[i][k];
                            puzzle[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    // Move Down
    else {
        for (int j = 0; j < 4; j++) {
            vector<int> col;

            // Pull non-zero numbers bottom to top
            for (int i = 3; i >= 0; i--) {
                if (puzzle[i][j] > 0) col.push_back(puzzle[i][j]);
            }

            // Merge equal adjacent numbers
            vector<int> merged;
            int i = 0;
            while (i < col.size()) {
                if (i + 1 < col.size() && col[i] == col[i + 1]) {
                    merged.push_back(col[i] * 2);
                    i += 2;
                } else {
                    merged.push_back(col[i]);
                    i++;
                }
            }

            // Fill with zeros on top
            while (merged.size() < 4) merged.push_back(0);

            // Copy back to puzzle bottom to top
            for (int i = 0; i < 4; i++) {
                puzzle[3 - i][j] = merged[i];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << puzzle[i][j] << (j < 3 ? " " : "\n");
        }
    }

    return 0;
}
