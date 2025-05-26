#include<bits/stdc++.h>
using namespace std;

int solve_insertion(vector<int>& line) {
    int ans = 0;
    for (int i = 1; i < 20; i++) {
        int j = i-1;
        int curr = line[i];
        while (j >= 0 && line[j] > curr) {
            line[j+1] = line[j];
            ++ans;
            j--;
        }
        line[j+1] = curr;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    int x;
    while (n--) {
        int Case; cin >> Case;
        vector<int> line;
        for (int i = 0; i < 20; i++) {
            cin >> x;
            line.push_back(x);
        }
        
        cout << Case << " " << solve_insertion(line);
        if (n == 0) cout << "";
        else cout << endl;
    }
    
    return 0;
}