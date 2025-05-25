#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long maxSum(vector<int>& A) {
    sort(A.begin(), A.end()); // Sap xep mang tang dan
    long long result = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        result = (result + 1LL * A[i] * i) % MOD; // Tranh tran so
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        
        for (int &x : A) cin >> x
        
        cout << maxSum(A) <<endl;
    }

    return 0;
}

