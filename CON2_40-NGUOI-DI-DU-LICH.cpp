#include <bits/stdc++.h>
using namespace std;
//can hieu thuat toan nguoi di du lich bai nay
const int INF = 1e9;
int n, C[16][16], dp[1 << 15][15];

int tsp(int mask, int u) {
    if (mask == (1 << n) - 1) return C[u][0];
    if (dp[mask][u] != -1) return dp[mask][u];

    int res = INF;
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) {
            res = min(res, C[u][v] + tsp(mask | (1 << v), v));
        }
    }
    return dp[mask][u] = res;
}

int main() {
 
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> C[i][j];

    memset(dp, -1, sizeof(dp));
    cout << tsp(1, 0) << endl;
    return 0;
}

