#include<bits/stdc++.h>
using namespace std;

// way 1 : O(N) space Complexity
struct Node {
    int val;
    Node* left;
    Node* right;
};

int main() {
    int h; string route;
    cin >> h >> route;
    int n = pow(2, h+1) - 1;
    Node* root = new Node();
    root->val = n--;
    deque<Node*> dq = {root};
    
    while (n > 0) {
        auto& node = dq.front(); dq.pop_front();
        Node* left_node = new Node();
        Node* right_node = new Node();
        left_node->val = n--;
        right_node->val = n--;
        node->left = left_node;
        node->right = right_node;
        dq.push_back(left_node);
        dq.push_back(right_node);
    }
    
    Node* temp = root;
    for (auto& x : route) {
        if (x == 'L') temp = temp->left;
        else temp = temp->right;
    }
    
    cout << temp->val;
    
    return 0;
}

// way 2 : O(1) Space Complexity
int main() {
    int h; string route;
    cin >> h >> route;
    int n = pow(2, h+1) - 1;
    
    int i = 0;
    for (auto& x : route) {
        if (x == 'L') i = 2*i + 1;
        else i = 2*i + 2;
    }
    
    cout << n - i;
    
    return 0;
}