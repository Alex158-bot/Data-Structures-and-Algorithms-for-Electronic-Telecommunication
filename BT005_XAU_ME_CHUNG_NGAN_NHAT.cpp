#include <bits/stdc++.h>
using namespace std;

int shortestCommonSupersequenceLength(const string& A, const string& B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[m][n];
}

void solve() {
    string A, B;
    cin >> A >> B;
    cout << shortestCommonSupersequenceLength(A, B) << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}

