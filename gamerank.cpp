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
    string games;
    cin >> games;
    
    vi leagueMaxStars = {0,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2};
    int league = 25, stars = 0, winstreak = 0;
    bool legend = false;
    
    for (char& c : games) {
        if (c == 'W'){
            winstreak++;
            if (league >= 6 && winstreak >= 3) {
                stars++;
                if (leagueMaxStars[league]+1 == stars) {
                    league--;
                    stars = 1;
                }
            }
            
            stars++;
            if (leagueMaxStars[league]+1 == stars) {
                league--;
                stars = 1;
            }
            
            if (league == 0) legend = true;
        } else {
            winstreak = 0;
            if (league <= 20) stars--;
            if (stars == -1) {
                if (league == 20) stars = 0;
                if (league < 20) {
                    league++;
                    stars = leagueMaxStars[league]-1;
                }
            }
        }
    }
    
    if(legend) {
        cout << "Legend" << endl;
    }
    else {
        cout << league << endl;
    }
    return 0;
}