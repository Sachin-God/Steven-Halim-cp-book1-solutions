#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        string token;
        vector<int> arr;
        int n = 0;
        bool valid = true;
        while (ss >> token) {
            arr.push_back(stoi(token));
            n = max(n, arr.back());
        }
        
        vector<bool> check(n+1, false);
        for (int i = 0; i < arr.size() && valid; i++) {
            for (int j = i+1; j < arr.size() && valid; j++){
                int idx = abs(arr[i] - arr[j]);
                if (check[idx]) {
                    valid = false;
                }
                check[idx] = true;
            }
        }
        
        if (!valid) {
            cout << "not a ruler" << "\n";
            continue;
        }
        vector<int> missing;
        for (int i = 1; i <= n; i++) {
            if (!check[i]) {
                valid = false;
                missing.push_back(i);
            }
        }
        
        if (!valid) {
            cout << "missing ";
            for (auto& x : missing) cout << x << " ";
        } else cout << "perfect";
            cout << "\n";
    }
    
}