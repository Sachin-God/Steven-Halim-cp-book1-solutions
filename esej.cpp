#include<bits/stdc++.h>
using namespace std;

void generateWord(const vector<string>& words) {
    for (auto& x : words) cout << x << " ";
}

int main() {
    int a, b; cin >> a >> b;
    int n = (a+b) / 2;
    vector<string> words;
    int len = 0;
    char u, v, w, x;
    string word;
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                for (int l = 0; l < 26; l++) {
                    u = 'a' + i;
                    v = 'a' + j;
                    w = 'a' + k;
                    x = 'a' + l;
                    word = string(1, u) + string(1, v) + string(1, w) + string(1, x);
                    len++;
                    words.push_back(word);
                    if (len == n) {
                        generateWord(words);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}