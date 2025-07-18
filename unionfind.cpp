#include<bits/stdc++.h>
#include<bits/extc++.h>
#include<complex>
#include<cmath>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;

template<typename T> using v = vector<T>;
template<typename T> using minheap = std::priority_queue<T, v<T>, std::greater<T>>;
template<typename T> using maxheap = std::priority_queue<T>;
// find_by_order(k), order_of_key(x)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define umap(KEY, VALUE) unordered_map<KEY, VALUE>
#define uset(KEY) unordered_set<KEY>
#define f(i, start, end) for(int i = start; i < end; i++)
#define all(x) (x).begin(), (x).end()

class Union_find {
private:
    vector<int> parent, rank;
    int n;
public:
    Union_find(int vector_size){
        n = vector_size;
        parent.assign(n, 0); for (int i = 1; i < n; i++) parent[i] = i;
        rank.assign(n, 0);
    }

    int find(int x) {return (parent[x] == x) ? x : parent[x] = find(parent[x]);}

    void Union(int u, int v) {
        int px = find(u), py = find(v);
        if (px == py) return;
        if (rank[px] > rank[py]) parent[py] = px;
        else if (rank[px] < rank[py]) parent[px] = py;
        else {
            parent[py] = px;
            rank[px] += 1;
        }
    }

    bool isSameSet(int u, int v) {return find(u) == find(v);}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    Union_find UF(n);
    char op; int u, v;
    while (m--) {
        cin >> op >> u >> v;
        if (op == '=') {
            UF.Union(u,v);
        } else {
            cout << (UF.isSameSet(u,v) ? "yes" : "no") << "\n";
        }
    }
    return 0;
}