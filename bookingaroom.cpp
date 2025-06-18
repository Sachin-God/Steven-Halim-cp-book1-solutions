#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, n, room; cin >> r >> n;
    if (r == n) {
        cout << "too late";
        return 0;
    }
    
    vector<bool> booked_rooms(r+1, false);
    while (n--) {
        cin >> room;
        booked_rooms[room] = true;
    }
    
    for (int i = 1; i < r+1; i++) {
        if (!booked_rooms[i]) {
            cout << i;
            break;
        }
    }
    
    return 0;
}