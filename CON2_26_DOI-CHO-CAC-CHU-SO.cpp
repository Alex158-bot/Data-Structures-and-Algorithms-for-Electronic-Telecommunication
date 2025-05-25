#include<bits/stdc++.h>
using namespace std;

void findMaxNumber(string &S, int K, int index, string &maxS) {
    if (K == 0 || index >= S.length()) return;
    int n = S.length();
    char maxChar = S[index];
    int maxPos = index;
    
    for (int i = index + 1; i < n; ++i) {
        if (S[i] >= maxChar) {
            maxChar = S[i];
            maxPos = i;
        }
    }
    
    if (maxPos != index) {
        swap(S[index], S[maxPos]);
        maxS = max(maxS, S);
        findMaxNumber(S, K - 1, index + 1, maxS);
        swap(S[index], S[maxPos]);
    }
    findMaxNumber(S, K, index + 1, maxS);
}

void solve() {
    int K;
    string S;
    cin >> K >> S;
    string maxS = S;
    findMaxNumber(S, K, 0, maxS);
    cout << maxS << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
