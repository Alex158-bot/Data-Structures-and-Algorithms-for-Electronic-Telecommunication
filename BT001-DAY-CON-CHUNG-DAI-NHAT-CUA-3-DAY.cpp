#include <iostream>
#include <vector>
using namespace std;

int LCS3(vector<int>& A, vector<int>& B, vector<int>& C) {
    int nA = A.size(), nB = B.size(), nC = C.size();
    vector<vector<vector<int>>> dp(nA + 1, vector<vector<int>>(nB + 1, vector<int>(nC + 1, 0)));
    
    for (int i = 1; i <= nA; i++) {
        for (int j = 1; j <= nB; j++) {
            for (int k = 1; k <= nC; k++) {
                if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    return dp[nA][nB][nC];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int nA, nB, nC;
        cin >> nA;
        vector<int> A(nA);
        for (int &x : A) cin >> x;

        cin >> nB;
        vector<int> B(nB);
        for (int &x : B) cin >> x;

        cin >> nC;
        vector<int> C(nC);
        for (int &x : C) cin >> x;

        cout << LCS3(A, B, C) << endl;
    }
    return 0;
}

