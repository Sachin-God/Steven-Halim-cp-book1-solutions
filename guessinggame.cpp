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
    int n;
    int low = 0, high = 11;
    while (cin >> n && n != 0) {
        string nah, res;
        cin >> nah >> res;
        if (res == "low") low = max(n, low);
        else if (res == "high") high = min(n, high);
        else {
            if (n > low && n < high) {
                cout << "Stan may be honest"<<endl;
            } else {
                cout << "Stan is dishonest"<<endl;
            }
            low = 0;
            high = 11;
        }
    }
    return 0;
}