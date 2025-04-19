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

string formatTime(int h, int m, int s) {
    auto two_digits = [](int x) {
        return (x < 10 ? "0" : "") + to_string(x);
    };
    return two_digits(h) + ":" + two_digits(m) + ":" + two_digits(s);
}

int main() {
    string s, t;
    cin >> s >> t;
    int t1 = stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
    int t2 = stoi(t.substr(0, 2)) * 3600 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6, 2));
    
    int tm = (t2 - t1 + 24 * 3600) % (24 * 3600);

    int hh = tm / 3600;
    tm %= 3600;
    int mm = tm / 60;
    int ss = tm % 60;
    if (t1 == t2) cout<<"24:00:00";
    else {
        cout << formatTime(hh, mm, ss);
    }
    return 0;
}