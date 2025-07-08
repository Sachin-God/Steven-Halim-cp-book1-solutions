#include<bits/stdc++.h>
using namespace std;

#include<bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    int n;
    string name, start, end;
    int gender;
    ost male, female;
    
    while (cin >> n && n != 0) {
        if (n == 1) {
            cin >> name >> gender;
            if (gender == 1) male.insert(name);
            else female.insert(name);
        } else if (n == 2) {
            cin >> name;
            male.erase(name);
            female.erase(name);
        } else {
            cin >> start >> end >> gender;
            if (gender == 0) {
                int male_count = male.order_of_key(end) - male.order_of_key(start);
                int female_count = female.order_of_key(end) - female.order_of_key(start);
                cout << male_count + female_count << endl;
            } else if (gender == 1) {
                cout << male.order_of_key(end) - male.order_of_key(start) << endl;
            } else {
                cout << female.order_of_key(end) - female.order_of_key(start) << endl;
            }
        }
    }
    return 0;
}