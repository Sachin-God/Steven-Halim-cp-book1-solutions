#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

// macros
#define umap(KEY, VALUE) unordered_map<KEY, VALUE>

int main() {
    string word;
    cin>>word;
    int n = word.length();
    bool isit = false;
    for (int i = 0; i < n-1; i++) {
        if (word[i] == 's' && word[i+1] == 's') isit = true;
    }
    (isit) ? cout<<"hiss" : cout<<"no hiss";
    return 0;
}