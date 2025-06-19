#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr;
    int course;
    unordered_map<string, int> combinations;
    int max_course = 0;
    
    while (n--) {
        arr.clear();
        for (int i = 0; i < 5; i++) {
            cin >> course;
            arr.push_back(course);
        }
        sort(arr.begin(), arr.end());
        string res = "";
        for (int i = 0; i < 5; i++) res += to_string(arr[i]) + '-';
        combinations[res]++;
        max_course = max(max_course, combinations[res]);
    }
    
    int count = 0;
    for (auto& [c, v] : combinations) {
        if (v == max_course) count += v;
    }
    
    cout << count;
    
    return 0;
}