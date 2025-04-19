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

int main() {
    umap(char, pii) map;
    map['A'] = {11, 11};
    map['K'] = {4, 4};
    map['Q'] = {3, 3};
    map['J'] = {20, 2};
    map['T'] = {10, 10};
    map['9'] = {14, 0};
    map['8'] = {0, 0};
    map['7'] = {0, 0};
    
    
    int n;
    char d;
    cin>>n>>d;
    int score = 0;
    string c1, c2, c3, c4;
    while (n--) {
        cin>>c1>>c2>>c3>>c4;
        if (c1[1] == d) score += map[c1[0]].first;
        else score += map[c1[0]].second;
        if (c2[1] == d) score += map[c2[0]].first;
        else score += map[c2[0]].second;
        if (c3[1] == d) score += map[c3[0]].first;
        else score += map[c3[0]].second;
        if (c4[1] == d) score += map[c4[0]].first;
        else score += map[c4[0]].second;
    }
    
    cout<<score;
    return 0;
}