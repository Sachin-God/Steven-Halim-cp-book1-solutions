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
    int n, x;
    cin >> n;
    umap(int, int) mp;
    
    int arrows = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (mp.find(x) != mp.end() && mp[x] != 0) {
            mp[x] -= 1;
        } else {
            arrows++;
        }
        mp[x-1] += 1;
    }
    
    cout<<arrows;
    return 0;
}