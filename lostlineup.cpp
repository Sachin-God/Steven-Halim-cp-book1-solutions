#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unordered_map<int, int> u_mapii;


int main() {
    int n;
    cin>>n;
    vi line(n);
    line[0] = 1;
    int x;
    for (int i = 2; i <= n; i++) {
        cin>>x;
        line[x+1] = i;
    }
    for (int i = 0; i < n; i++) {
        cout<<line[i]<<" ";
    }
    return 0;
}