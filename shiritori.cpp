#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string word, lastword;
    unordered_set<string> words;
    
    for (int i = 0; i < n; i++) {
        cin >> word;
        if (words.find(word) != words.end() || (!lastword.empty() && lastword.back() != word[0])) {
            if (i % 2 == 0) cout << "Player 1 lost";
            else cout << "Player 2 lost";
            return 0;
        }
        words.insert(word);
        lastword = word;
    }
    
    cout << "Fair Game";

    return 0;
}