#include<bits/stdc++.h>
using namespace std;

int main() {
    string rhyme;
    getline(cin, rhyme);
    stringstream ss(rhyme);
    string token; int count = 0;
    while (ss >> token) count++;
    
    int n; cin >> n;
    queue<string> s;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        s.push(temp);
    }
    
    vector<string> team1, team2;
    bool t1 = true;
    int k = 0;
    while (!s.empty()) {
        string f = s.front(); s.pop();
        k++;
        if (k == count) {
            if (t1) team1.push_back(f);
            else team2.push_back(f);
            k = 0;
            t1 = !t1;
        } else {
            s.push(f);
        }
    }
    
    cout << team1.size() << "\n";
    for (auto& x : team1) cout << x << "\n";
    cout << team2.size() << "\n";
    for (auto& x : team2) cout << x << "\n";
}