#include<bits/stdc++.h>
using namespace std;

vector<string> sub;
unordered_map<int, int> mp;

void substring(int idx, const string& s, string str, unordered_set<int> set) {
    if (idx == s.length()) {
        sub.push_back(str);
        return;
    }
    
    if (s[idx] == '(') {
        set.insert(idx);
        substring(idx+1, s, str, set);
        set.erase(idx);
        substring(idx+1, s, str + '(', set);
    } else if (s[idx] == ')') {
        if (set.find(mp[idx]) != set.end()) substring(idx+1, s, str, set);
        else substring(idx+1, s, str + ')', set);
    } else {
        substring(idx+1, s, str + s[idx], set);
    }
}

int main() {
    string s; cin >> s;
    
    stack<int> stk;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') stk.push(i);
        else if (s[i] == ')') {
            mp[i] = stk.top();
            stk.pop();
        }
    }
    
    substring(0, s, string (), unordered_set<int> ());
    sort(sub.begin(), sub.end());
    unordered_set<string> uniq;
    uniq.insert(s);
    for (auto x : sub) {
        if (uniq.find(x) != uniq.end()) continue;
        uniq.insert(x);
        cout << x << "\n";
    }
}