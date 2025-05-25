#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    
    vector<int> curr(K);
    for (int i = 0; i < K; i++) cin >> curr[i];

    vector<int> next = curr;

    int i = K - 1;
    while (i >= 0 && next[i] == N - K + i + 1) i--;
    
    if (i < 0) { 
        cout << K << endl;
        return;
    }

    next[i]++;
    for (int j = i + 1; j < K; j++) next[j] = next[j - 1] + 1;

    unordered_set<int> oldSet(curr.begin(), curr.end());
    int count = 0;
    for (int x : next) 
        if (oldSet.find(x) == oldSet.end()) count++;

    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

