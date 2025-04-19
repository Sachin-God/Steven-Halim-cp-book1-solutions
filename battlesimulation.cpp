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
    string monster, mecha = "";
    cin>>monster;
    int n = monster.length();
    uset(string) combo = {"RBL", "RLB", "BRL", "BLR", "LRB", "LBR"};
    
    int i = 0;
    while (i < n) {
        if (combo.find(monster.substr(i, 3)) != combo.end()) {
            mecha += "C";
            i += 2;
        } else if (monster[i] == 'R') mecha += 'S';
        else if (monster[i] == 'B') mecha += 'K';
        else mecha += 'H';
        i++;
    }
    cout<<mecha;
    
    return 0;
}