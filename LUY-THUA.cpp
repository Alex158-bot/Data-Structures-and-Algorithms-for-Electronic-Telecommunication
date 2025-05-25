#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

long long powerMod(long long N, long long K, long long MOD) {
    long long result = 1;
    while (K > 0) {
        if (K % 2 == 1) { 
            result = (result * N) % MOD;
        }
        N = (N * N) % MOD; 
        K /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T; 
    while (T--) {
        long long N, K;
        cin >> N >> K;
        cout << powerMod(N, K, MOD) << endl;
    }
    return 0;
}

