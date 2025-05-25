#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSortArray(vector<int>& arr) {
    int n = arr.size();
    int mid = n / 2;

    for (int i = mid; i > 0; --i) {
        int left = i - 1;
        int right = n - i;
        while (left < right) {
            if (arr[left] > arr[right]) {
                swap(arr[left], arr[right]);
            }
            left++;
            right--;
        }
    }

    
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool canSortBySymmetricSwap(vector<int> original) {
    int n = original.size();
    vector<int> sorted = original;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n / 2; ++i) {
        if (original[i] != sorted[i] && original[i] != sorted[n - 1 - i]) {
            return false;
        }
        if (original[n - 1 - i] != sorted[i] && original[n - 1 - i] != sorted[n - 1 - i]) {
            return false;
        }
        if (!((original[i] == sorted[i] && original[n - 1 - i] == sorted[n - 1 - i]) ||
              (original[i] == sorted[n - 1 - i] && original[n - 1 - i] == sorted[i]))) {
            return false;
        }
    }
    if (n % 2 == 1 && original[n / 2] != sorted[n / 2]) {
        return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        // S? d?ng phiên b?n nào b?n mu?n ki?m tra
        cout << (canSortArray(a) ? "YES" : "NO") << endl;
        // Ho?c
        // cout << (canSortBySymmetricSwap(a) ? "YES" : "NO") << endl;
    }
    return 0;
}
