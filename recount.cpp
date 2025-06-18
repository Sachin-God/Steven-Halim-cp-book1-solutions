#include<bits/stdc++.h>
using namespace std;

int main() {
    string candidate;
    unordered_map<string, int> votes;
    while (getline(cin, candidate)) {
        if (candidate == "***") break;
        votes[candidate]++;
    }
    
    string winner;
    int max_votes = 0;
    
    for (auto& [cand, vote] : votes) {
        if (vote > max_votes) {
            max_votes = vote;
            winner = cand;
        } else if (vote == max_votes) {
            winner = "Runoff!";
        }
    }
    
    cout << winner;
    return 0;
}