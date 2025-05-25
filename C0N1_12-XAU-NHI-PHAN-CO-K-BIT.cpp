#include<bits/stdc++.h>
using namespace std;

void generateBinaryStrings(int N, int K, int index, int ones, string &current) {
    if (index == N) {
        if (ones == K) cout << current << endl;
        return;
    }
    
    current[index] = '0';
    generateBinaryStrings(N, K, index + 1, ones, current);
    
    current[index] = '1';
    generateBinaryStrings(N, K, index + 1, ones + 1, current);
}

void solve() {
    int N, K;
    cin >> N >> K;
    string current(N, '0');
    generateBinaryStrings(N, K, 0, 0, current);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

