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
    int k, n, x;
    cin>>k;
    
    while (k--) {
        cin>>n;
        double total = 0, maxVote = 0;
        int winner = 0;
        umap(int, int) mp;
        f(i, 0, n) {
            cin>>x;
            mp[x]++;
            total += x;
            if (x > maxVote) {
                maxVote = x;
                winner = i+1;
            }
        }

        if (mp[maxVote] > 1) {
            cout << "no winner" << endl;
        } else {
            // Check if the max vote is greater than half of the total votes
            if (maxVote > total / 2) {
                cout << "majority winner " << winner << endl;
            } else {
                cout << "minority winner " << winner << endl;
            }
        }
    }
    return 0;
}