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

int playerwon(int p1, string m1, int p2, string m2) {
    if (m1 == "scissors" && m2 == "paper") {
        return p1;
    } 
    if (m1 == "paper" && m2 == "scissors") {
        return p2;
    } 
    if (m1 == "rock" && m2 == "scissors") {
        return p1;
    }
    if (m1 == "scissors" && m2 == "rock") {
        return p2;
    }
    if (m1 == "paper" && m2 == "rock") {
        return p1;
    } 
    if (m1 == "rock" && m2 == "paper") {
        return p2;
    }
    return -1;
} 

int main() {
    int n, k;
    while (cin>> n && n != 0 && cin>>k) {
        int games = (k * n * (n-1)) / 2;
        vector<pair<float, float>> player(n, {0,0});
        int p1, p2;
        string m1, m2;
        while (games--) {
            cin>>p1>>m1>>p2>>m2;
            p1--, p2--; // Adjusting to 0-based indexing
            int res = playerwon(p1, m1, p2, m2);
            if (res != -1) {
                player[res].first++;
                if (res == p1) {
                    player[p2].second++;
                } else {
                    player[p1].second++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            auto& [w, l] = player[i];
            // cout<<"("<<w<<","<<l<<")"<<endl;
            if (w + l == 0) {
                cout << "-" << endl;
            } else {
                cout << fixed << setprecision(3) << (w / (w + l)) << endl;
            }
        }
        cout<<endl;
    }
    return 0;
}