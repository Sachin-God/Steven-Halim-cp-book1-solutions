#include<bits/stdc++.h>
#include<bits/extc++.h>
#include<complex>
#include<cmath>
using namespace std;
using namespace __gnu_pbds;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k), order_of_key(x)

#define umap(KEY, VALUE) unordered_map<KEY, VALUE>
#define uset(KEY) unordered_set<KEY>
#define f(i, start, end) for(int i = start; i < end; i++)

int main() {
    int n; cin >> n;
    int idx, inf;
    string name;
    set<tuple<int, int, string>> pq;
    unordered_map<string, int> map;
    unordered_map<string, int> timestamp;
    int time_stamp = n;
    
    while (n--) {
        cin >> idx;
        if (idx == 0) {
            cin >> name >> inf;
            map[name] = inf;
            timestamp[name] = time_stamp;
            pq.insert({inf, time_stamp--, name});
        } else if (idx == 1) {
            cin >> name >> inf;
            auto it = pq.find({map[name], timestamp[name], name});
            if (it != pq.end()) pq.erase(it);
            map[name] += inf;
            pq.insert({map[name], timestamp[name], name});
        } else if (idx == 2) {
            cin >> name;
            auto it = pq.find({map[name], timestamp[name], name});
            if (it != pq.end()) pq.erase(it);
            map.erase(name);
            timestamp.erase(name);
        } else {
            if (pq.empty()) {cout << "The clinic is empty"<<endl; continue;}
            auto [_, t, name] = *pq.rbegin();
            cout << name << endl;
        }
    }
    return 0;
}