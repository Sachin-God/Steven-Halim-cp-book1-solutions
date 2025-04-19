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
    int ap[4];
    cin>>ap[0]>>ap[1]>>ap[2];
    sort(ap, ap+3);
    ap[4] = INT_MAX;
    
    int a = ap[0];
    int d = min(ap[1] - ap[0], ap[2] - ap[1]);
    
    int j = 0;
    for (int i = 0; i < 4; i++) {
        int num = a + i*d;
        if (num == ap[j]) j++;
        else {
            cout<<num;
            break;
        }
    }
    
    return 0;
}