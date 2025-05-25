#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LCS(const string& S1, const string& S2) {
    int m = S1.length();
    int n = S2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string S1, S2;
        cin >> S1 >> S2;
        cout << LCS(S1, S2) << endl;
    }
    
    return 0;
}

