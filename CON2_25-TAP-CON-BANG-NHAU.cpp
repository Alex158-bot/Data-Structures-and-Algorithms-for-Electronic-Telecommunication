#include <bits/stdc++.h>
using namespace std;
//7/10
bool canPartition(vector<int>& A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 2 != 0) return false; 
    int target = sum / 2;
    bitset<10001> dp; 
    dp[0] = 1;

    for (int num : A) {
        dp |= (dp << num); 
    }

    return dp[target]; 
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> A(N);
        for (int &x : A) cin >> x;
        cout << (canPartition(A) ? "YES" : "NO") << "\n";
    }
    return 0;
}

