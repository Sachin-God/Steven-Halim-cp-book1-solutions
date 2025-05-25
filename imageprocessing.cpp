#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n, h, f;
    cin >> m >> n >> h >> f;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    vector<int> val(h*f, 0);
    
    int temp;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            mat[i][j] = temp;
        }
    }
    
    int k = h*f - 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < f; j++) {
            cin >> temp;
            val[k--] = temp;
        }
    }
    
    vector<vector<int>> res(m-h+1, vector<int>(n-f+1, 0));
    
    for (int i = 0; i < m-h+1; i++) {
        for (int j = 0; j < n-f+1; j++) {
            int k = 0;
            for (int a = i; a < i+h; a++) {
                for (int b = j; b < f+j; b++) {
                    res[i][j] += mat[a][b] * val[k++];
                }
            }
        }
    }
    
    for (int i = 0; i < m-h+1; i++) {
        for (int j = 0; j < n-f+1; j++) {
            cout<<res[i][j]<<((j < n-f) ? " " : "") ;
        }
        cout<<endl;
    }
    
    return 0;
}