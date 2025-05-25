#include <bits/stdc++.h>
using namespace std;

bool canRearrange(string &s) {
    vector<int> freq(26, 0);
    int maxFreq = 0;
    
    for (char c : s) {
        freq[c - 'a']++;
        maxFreq = max(maxFreq, freq[c - 'a']);
    }

    int n = s.size();
    return maxFreq <= (n + 1) / 2; 
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << (canRearrange(s) ? 1 : -1) <<endl;
    }

    return 0;
}

