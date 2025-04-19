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

int getidx(char c){
    if ('a' <= c && c <= 'z') return 10 + c - 'a';
    if ('A' <= c && c <= 'Z') return 36 + c - 'A';
    return c - '0'; // '0' to '9'
}

void format(vector<string>& v) {
    vector<pii> loc(62);
    int size = 0; // used bcz it is given that it will go sequentially
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[0].length(); j++){
            if (isalpha(v[i][j]) || isdigit(v[i][j])) {
                int idx = getidx(v[i][j]);
                loc[idx] = {i,j};
                size++;
            }
        }
    }
    
    for (int i = 1; i < size; i++) {
        pii p1 = loc[i-1];
        pii p2 = loc[i];
        
        if (p1.first == p2.first) {
            if (p1.second < p2.second) {
                for (int k = p1.second+1; k < p2.second; k++) {
                    if (v[p1.first][k] == '.') v[p1.first][k] = '-';
                    if (v[p1.first][k] == '|')  v[p1.first][k] = '+';
                }
            } else {
                for (int k = p1.second-1; k > p2.second; k--) {
                    if (v[p1.first][k] == '.') v[p1.first][k] = '-';
                    if (v[p1.first][k] == '|')  v[p1.first][k] = '+';
                }
            }
        } else {
            if (p1.first < p2.first) {
                for (int k = p1.first+1; k < p2.first; k++) {
                    if (v[k][p1.second] == '.') v[k][p1.second] = '|';
                    if (v[k][p1.second] == '-')  v[k][p1.second] = '+';
                }
            } else {
                for (int k = p1.first-1; k > p2.first; k--) {
                    if (v[k][p1.second] == '.') v[k][p1.second] = '|';
                    if (v[k][p1.second] == '-')  v[k][p1.second] = '+';
                }
            }
        }
    }
    
    for (auto& l : v) cout<<l<<endl;
}

int main() {
    vector<string> v;
    string line;
    
    while (getline(cin, line)){
        if (line == ""){
            format(v);
            v.clear();
            cout<<endl;
        } else {
            v.push_back(line);
        }
    }
    format(v);
    return 0;
}