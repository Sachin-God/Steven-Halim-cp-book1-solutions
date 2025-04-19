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
    int testcases;
    cin>>testcases;
    while (testcases--) {
        int n, m;
        cin>>n>>m;
        vvi ticketsreq(n);
        vi prizes, available;
        f(i, 0, n) {
            int x, temp;
            cin>>x;
            f(j, 0, x) {cin>>temp; ticketsreq[i].push_back(temp);}
            cin>>temp;
            prizes.push_back(temp);
        }
        
        int avail;
        f(i, 0, m) {
            cin>>avail;
            available.push_back(avail);
        }
        
        int prize = 0;
        for (int i = 0; i < n; i++){
            int minticket = INT_MAX;
            for (auto& x : ticketsreq[i]) {
                minticket = min(minticket, available[x-1]);
            }
            prize += minticket * prizes[i];
        }
        cout<<prize<<endl;
    }
    return 0;
}