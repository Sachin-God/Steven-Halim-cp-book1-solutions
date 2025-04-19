#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

// macros
#define umap(KEY, VALUE) unordered_map<KEY, VALUE>

bool checkup(int n, vector<string>& line1, vector<string>& line2) {
    for (int i = 0; i < n; i++) {
        if (line1[i] != line2[i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<string> line(n);
    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }
    
    vector<string> ascline(n), descline(n);
    
    // Copy the line array into ascline and descline
    copy(line.begin(), line.end(), ascline.begin());
    copy(line.begin(), line.end(), descline.begin());
    
    // Sort ascline in increasing order
    sort(ascline.begin(), ascline.end());
    // Sort descline in decreasing order
    sort(descline.begin(), descline.end(), greater<string>());
    
    // Check the sorting order of the original array
    if (checkup(n, line, ascline)) {
        cout << "INCREASING";
    }
    else if (checkup(n, line, descline)) {
        cout << "DECREASING";
    }
    else {
        cout << "NEITHER";
    }

    return 0;
}
