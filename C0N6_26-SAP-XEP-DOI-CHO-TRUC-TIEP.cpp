#include <bits/stdc++.h>
using namespace std;

void interchangeSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
        cout << "Buoc " << i + 1 << ": ";
        for (int k = i; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << '\n';
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    interchangeSort(arr, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;  // Nh?p s? test case
    while (T--) {
        solve();
    }

    return 0;
}

