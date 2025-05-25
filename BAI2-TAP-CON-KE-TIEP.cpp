//2
//5 3
//1 4 5
//5 3
//3 4 5
#include<bits/stdc++.h>
using namespace std;

void nextCombination(vector<int> &X, int N, int K) {
    vector<int> comb = X;
    int i = K - 1;
    while (i >= 0 && comb[i] == N - K + i + 1) {
        i--;
    }

    if (i < 0) {
        for (int j = 0; j < K; ++j)
            cout << j + 1 << (j == K - 1 ? "\n" : " ");
    } else {
        comb[i]++;
        for (int j = i + 1; j < K; ++j) {
            comb[j] = comb[j - 1] + 1;
        }
        for (int j = 0; j < K; ++j)
            cout << comb[j] << (j == K - 1 ? "\n" : " ");
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> X(K);
        for (int i = 0; i < K; ++i)
            cin >> X[i];
        nextCombination(X, N, K);
    }
    return 0;
}


