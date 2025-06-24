#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    unordered_set<string> words;
    vector<string> word_list;
    string line, w;

    
    while (getline(cin, line)) {
        stringstream ss(line);
        while (ss >> w) {
            if (words.insert(w).second) {
                word_list.push_back(w);
            }
        }
    }

    set<string> compound_words;

    int n = word_list.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            string combined = word_list[i] + word_list[j];
            compound_words.insert(combined);
        }
    }
    
    for (const auto& cw : compound_words) {
        cout << cw << '\n';
    }

    return 0;
}
