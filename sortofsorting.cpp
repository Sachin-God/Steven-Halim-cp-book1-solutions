#include<bits/stdc++.h>
using namespace std;

bool compare(const string& x, const string& y) {
    if (x[0] == y[0]) return x[1] < y[1];
    return x[0] < y[0];
}

void print(vector<string>& names) {
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        vector<string> names;
        string name;
        for (int i = 0; i < n; i++) {
            cin >> name;
            names.push_back(name);
        }
        cin >> n;
        stable_sort(names.begin(), names.end(), compare);
        print(names);
        if (n != 0) cout << endl;
    }
    
    return 0;
}