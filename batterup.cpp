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
    int n;
    cin>>n;
    double score = 0, times = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin>>x;
        if (x == -1) continue;
        score += x;
        times++;
    }
    cout<<(score / times);
    return 0;
}