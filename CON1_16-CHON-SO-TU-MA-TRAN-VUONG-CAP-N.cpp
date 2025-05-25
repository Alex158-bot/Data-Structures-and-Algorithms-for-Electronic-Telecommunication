#include <bits/stdc++.h>
using namespace std;

int N, K, res = 0;
int C[10][10], colUsed[10], chosen[10];

void backtrack(int row, int sum) {
    if (row == N) {
        if (sum == K) {
            res++;
            for (int i = 0; i < N; i++) cout << chosen[i] + 1 << " ";
            cout << endl;
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (!colUsed[col]) {
            colUsed[col] = 1;
            chosen[row] = col;
            backtrack(row + 1, sum + C[row][col]);
            colUsed[col] = 0;
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> C[i][j];

    memset(colUsed, 0, sizeof(colUsed));
    backtrack(0, 0);

    cout << res << endl;
    return 0;
}

