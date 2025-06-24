#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> string_val;
    unordered_map<int, string> val_string;
    string line;
    
    while (getline(cin, line)) {
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        
        if (cmd == "clear") {
            string_val.clear();
            val_string.clear();
            
        } else if (cmd == "def") {
            string var; int val;
            ss >> var >> val;
            if (string_val.find(var) != string_val.end()) val_string.erase(string_val[var]);
            string_val[var] = val;
            val_string[val] = var;
        } else if (cmd == "calc") {
            int res = 0;
            string var; bool unknown = false;
            ss >> var;
            vector<string> expr;
            expr.push_back(var);
            
            if (string_val.find(var) != string_val.end()) {
                res += string_val[var];
            } else {
                unknown = true;
            }
            
            string sign;
            while (ss >> sign && sign != "=") {
                expr.push_back(sign);
                ss >> var;
                expr.push_back(var);
                if (string_val.find(var) != string_val.end()) {
                    if (sign == "+") res += string_val[var];
                    else res -= string_val[var];
                } else {
                    unknown = true;
                }
            }
            
            for (auto& x : expr) cout << x << " ";
            cout << "=";
            if (!unknown) {
                if (val_string.find(res) != val_string.end()) {
                    cout << " " << val_string[res];
                } else {
                    cout << " unknown";
                }
            } else {
                cout << " unknown";
            }
            cout << endl;
         }
    }
    
    return 0;
}