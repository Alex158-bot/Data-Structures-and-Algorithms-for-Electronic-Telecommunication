#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &X, int N) {
    int i = N - 2;
    while (i >= 0 && X[i] >= X[i + 1]) {
        --i;
    }
    if (i >= 0) {
        int j = N - 1;
        while (X[j] <= X[i]) {
            --j;
        }
        swap(X[i], X[j]);
    }
    reverse(X.begin() + i + 1, X.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> X(N);
        for (int i = 0; i < N; ++i) {
            cin >> X[i];
        }
        
        nextPermutation(X, N);
        
        for (int i = 0; i < N; ++i) {
            cout << X[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

