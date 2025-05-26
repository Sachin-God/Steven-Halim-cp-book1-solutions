#include<bits/stdc++.h>
using namespace std;

void print(const vector<int>& arr) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
        if (i < 4) cout << " ";
    }
}

int main() {
    int n;
    vector<int> arr;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        arr.push_back(n);
    }
    bool first = true;
    
    for (int i = 4; i > 0; i--) {
        int j = 0;
        while (j < i) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                if (!first) cout << endl; 
                first = false;
                print(arr);
            }
            j++;
        }
    }
    
    return 0;
}