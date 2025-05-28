#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main() {
    int n, x; cin >> n;
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (st.empty() == 1 || (st.top() + x) % 2 != 0) {
            st.push(x);
        } else {
            st.pop();
        }
    }
    cout << st.size();
    
    return 0;
}