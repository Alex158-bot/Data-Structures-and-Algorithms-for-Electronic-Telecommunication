#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
using Matrix = vector<vector<long long>>;

Matrix multiplyMatrix(const Matrix& A, const Matrix& B, int N) {
    Matrix C(N, vector<long long>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < N; ++j)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Matrix matrixPower(Matrix A, long long K, int N) {
    Matrix res(N, vector<long long>(N, 0));
    for (int i = 0; i < N; ++i)
        res[i][i] = 1;
    while (K > 0) {
        if (K % 2 == 1)
            res = multiplyMatrix(res, A, N);
        A = multiplyMatrix(A, A, N);
        K /= 2;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long K;
        cin >> N >> K;
        Matrix A(N, vector<long long>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> A[i][j];
        Matrix result = matrixPower(A, K, N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << result[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}

