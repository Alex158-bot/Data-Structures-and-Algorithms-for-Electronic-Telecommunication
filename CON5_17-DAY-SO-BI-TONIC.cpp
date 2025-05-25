#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxBitonicSum(vector<int>& a, int n) {
    vector<int> inc(n), dec(n);

    for (int i = 0; i < n; i++) inc[i] = a[i];
    for (int i = 0; i < n; i++) dec[i] = a[i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && inc[i] < inc[j] + a[i])
                inc[i] = inc[j] + a[i];

    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (a[i] > a[j] && dec[i] < dec[j] + a[i])
                dec[i] = dec[j] + a[i];

    int max_sum = 0;
    for (int i = 0; i < n; i++)
        max_sum = max(max_sum, inc[i] + dec[i] - a[i]);

    return max_sum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxBitonicSum(A, N) << "\n";
    }
    return 0;
}

