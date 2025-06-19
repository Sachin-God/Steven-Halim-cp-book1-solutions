#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, p, m; cin >> n >> p >> m;
    unordered_map<string, int> player_score;
    unordered_set<string> player_won;
    string player;
    
    while (n--) {
        cin >> player;
        player_score[player] = 0;
    }
    
    int points;
    
    while (m--) {
        cin >> player >> points;
        player_score[player] += points;
        if (player_score[player] >= p && player_won.find(player) == player_won.end()) {
            cout << player << " wins!" << endl;
            player_won.insert(player);
        }
    }
    
    if (player_won.size() == 0) cout << "No winner!";
    
    return 0;
}