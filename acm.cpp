#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int x;
    unordered_map<char, pair<bool, int>> map;
    while (cin>>x && x != -1) {
        char ques_num;
        string solved;
        cin>>ques_num>>solved;
        bool isit = false;
        if (solved == "right") isit = true;
        if (isit) {
            map[ques_num].first = true;
            map[ques_num].second += x;
        } else {
            map[ques_num].first = false;
            map[ques_num].second += 20;
        }
    }
    
    int ans = 0;
    int ques = 0;
    for (auto& pair : map) {
        if (pair.second.first) {
            ans += pair.second.second;
            ques++;
        }
    }
    cout<<ques<<" "<<ans;
    return 0;
}