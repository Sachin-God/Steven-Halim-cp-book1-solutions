#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, y; cin >> n >> y;
    vector<bool> obstacles(n, false);
    int obs;
    for (int i = 0; i < y; i++) {
        cin >> obs; 
        obstacles[obs] = true;
    }
    
    int missed = 0;
    for (int i = 0; i < n; i++) {
        if (!obstacles[i]) cout << i << endl;
        else missed++;
    }
    
    cout << "Mario got " << missed << " of the dangerous obstacles.";
    
    return 0;
}