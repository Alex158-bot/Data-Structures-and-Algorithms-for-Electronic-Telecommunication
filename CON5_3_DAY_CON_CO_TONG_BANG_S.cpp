#include <bits/stdc++.h>
using namespace std;
//co the làm và suy luan
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, S;
        cin >> N >> S;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        vector<bool> dp(S + 1, false);
        dp[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = S; j >= A[i]; j--) {
                if (dp[j - A[i]]) dp[j] = true;
            }
        }
        cout << (dp[S] ? "YES" : "NO") << "\n";
    }
    return 0;
}

