#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> res;
    
    while (n--) {
        cin >> x;
        if (res.empty() || res.back() < x) res.push_back(x);
    }
    
    cout<<res.size()<<endl;
    
    for (int i = 0; i < res.size(); i++) {
        if (i != res.size()-1 ) cout<<res[i]<<" ";
        else cout<<res[i];
    }
    return 0;
}