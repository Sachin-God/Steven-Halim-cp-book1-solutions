#include <bits/stdc++.h>
using namespace std;

// Task 1: Check if there are two elements that sum to a target (7777)
void twoSum(const vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left < right) {
        int sum = vec[left] + vec[right];
        if (sum == target) {
            cout << "Yes" << endl;
            return;
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    cout << "No" << endl;
}

// Task 2: Check for uniqueness
void checkUniqueness(const vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == vec[i - 1]) {
            cout << "Contains duplicate" << endl;
            return;
        }
    }
    cout << "Unique" << endl;
}

// Task 3: Find an element that appears more than n/2 times (majority element)
void findFrequency(const vector<int>& vec, int freq) {
    int current = vec[0], count = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == current) {
            count++;
        } else {
            if (count > freq) {
                cout << current << endl;
                return;
            }
            current = vec[i];
            count = 1;
        }
    }
    // Final check
    if (count > freq) {
        cout << current << endl;
        return;
    }
    cout << -1 << endl;
}

// Task 4: Find median(s)
void findMedian(const vector<int>& vec) {
    int n = vec.size();
    if (n % 2 == 1) {
        cout << vec[n / 2] << endl;
    } else {
        cout << vec[n / 2 - 1] << " " << vec[n / 2] << endl;
    }
}

// Task 5: Range query [100, 999]
void rangeQuery(const vector<int>& vec, int l, int r) {
    auto low = lower_bound(vec.begin(), vec.end(), l);
    auto high = upper_bound(vec.begin(), vec.end(), r);
    for (auto it = low; it != high; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    switch (t) {
        case 1:
            twoSum(vec, 7777);
            break;
        case 2:
            checkUniqueness(vec);
            break;
        case 3:
            findFrequency(vec, n / 2);
            break;
        case 4:
            findMedian(vec);
            break;
        case 5:
            rangeQuery(vec, 100, 999);
            break;
        default:
            cout << "Invalid task ID" << endl;
    }

    return 0;
}
