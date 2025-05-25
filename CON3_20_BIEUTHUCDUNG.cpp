#include <bits/stdc++.h>
using namespace std;

long long solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> open_positions;
    long long swaps = 0;
    int imbalance = 0, idx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') {
            open_positions.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') {
            imbalance++;  
            idx++;        
        } else { 
            imbalance--;  
            if (imbalance < 0) { 
                swaps += open_positions[idx] - i;
                swap(s[i], s[open_positions[idx]]);
                imbalance = 1; 
                idx++; 
            }
        }
    }
    return swaps;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

