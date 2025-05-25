#include <bits/stdc++.h>
using namespace std;

void nextCombination(vector<int> &X, int N, int K) {
    int i = K - 1;
    while (i >= 0 && X[i] == N - K + i + 1) {
        --i;
    }
    if (i >= 0) {
        X[i]++;
        for (int j = i + 1; j < K; ++j) {
            X[j] = X[j - 1] + 1;
        }
    } else {
        for (int j = 0; j < K; ++j) {
            X[j] = j + 1;
        }
    }
}

int main() {
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> X(K);
        for (int i = 0; i < K; ++i) {
            cin >> X[i];
        }
        
        nextCombination(X, N, K);
        
        for (int i = 0; i < K; ++i) {
            cout << X[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

