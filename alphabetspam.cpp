#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[4] = {0, 0, 0, 0};
    string str; cin >> str;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (str[i] == '_') arr[0]++;
        else if (islower(str[i])) arr[1]++;
        else if (isupper(str[i])) arr[2]++;
        else arr[3]++;
    }
    
    printf("%.16f \n" , (double)arr[0] / n);
    printf("%.16f \n" , (double)arr[1] / n);
    printf("%.16f \n" , (double)arr[2] / n);
    printf("%.16f \n" , (double)arr[3] / n);
    
    return 0;
}