#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    deque<int> front, back;
    
    string operation; int value;
    for (int i = 0; i < n; i++) {
        cin >> operation >> value;
        if (operation == "push_back") {
            back.push_back(value);
        } else if (operation == "push_front") {
            front.push_front(value);
        } else if (operation == "push_middle") {
            back.push_front(value);
        }
        
        if (back.size() > front.size()) {
            int val = back.front(); back.pop_front();
            front.push_back(val);
        }
        if (front.size()-1 > back.size()) {
            int val = front.back(); front.pop_back();
            back.push_front(val);
        }
        
        if (operation == "get") {
            int m = front.size();
            if (value >= m) {
                cout << back[value - m];
            } else {
                cout << front[value];
            }
            if (i < n-1) cout << endl;
        }
    }
    
    return 0;
}