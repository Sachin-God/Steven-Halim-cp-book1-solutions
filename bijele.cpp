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
    vector<int> chess = {1,1,2,2,2,8};
    
    int n, i = 0;
    while (cin>> n) {
        if (i < 6) {
            cout<<to_string(chess[i]-n)<<" ";
        } else {
            cout<<to_string(chess[i]-n);
        }
        i++;
    }
    return 0;
}