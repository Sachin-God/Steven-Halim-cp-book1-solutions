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
    int n;
    while (cin >> n && n != EOF) {
        vector<bool> check(n, false);
        int x, y;
        cin >> x;
        for (int i = 1; i < n; i++){
            cin >> y;
            if (abs(x-y) <= n-1) {
                check[abs(x-y)] = true;
                x = y;
            }
        }
        
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            if (!check[i]) jolly = false;
        }
        
        if (!jolly) cout<<"Not jolly"<<endl;
        else cout<<"Jolly"<<endl;
    }
    return 0;
}