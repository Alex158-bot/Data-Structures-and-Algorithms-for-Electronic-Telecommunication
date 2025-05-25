#include <iostream>
using namespace std;

int n, solutions = 0;
bool col[10], diag1[20], diag2[20]; // Ðánh d?u c?t, chéo chính, chéo ph?

void backtrack(int row) {
    if (row == n) {
        solutions++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !diag1[row - c + n] && !diag2[row + c]) {
            col[c] = diag1[row - c + n] = diag2[row + c] = 1;
            backtrack(row + 1);
            col[c] = diag1[row - c + n] = diag2[row + c] = 0;
        }
    }
}

int main() {
    cin >> n;
    if (n > 10) {
        cout << "-1" << endl;
        return 0; 
    }
    solutions = 0;
    backtrack(0);
    cout << solutions << endl;
    return 0;
}

