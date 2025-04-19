#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

// macros
#define umap(KEY, VALUE) unordered_map<KEY, VALUE>
#define f(i, start, end) for(int i = start; i < end; i++)

int main() {
    int n;
    cin>>n;
    (n <= 3) ? cout<<1 : cout<<n-2;
    return 0;
}