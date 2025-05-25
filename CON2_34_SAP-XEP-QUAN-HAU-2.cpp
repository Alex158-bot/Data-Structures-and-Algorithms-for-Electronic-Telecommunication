#include<bits/stdc++.h>
using namespace std;

const int N = 8;
int board[N][N], maxScore;
bool col[N], d1[2 * N], d2[2 * N];

void backtrack(int row, int currentScore) {
    if (row == N) {
        maxScore = max(maxScore, currentScore);
        return;
    }
    
    for (int c = 0; c < N; c++) {
        if (!col[c] && !d1[row - c + N - 1] && !d2[row + c]) { 
            col[c] = d1[row - c + N - 1] = d2[row + c] = true;
            backtrack(row + 1, currentScore + board[row][c]);
            col[c] = d1[row - c + N - 1] = d2[row + c] = false;
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    maxScore = 0;
    fill(col, col + N, false);
    fill(d1, d1 + 2 * N, false);
    fill(d2, d2 + 2 * N, false);

    backtrack(0, 0);
    cout << maxScore << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

