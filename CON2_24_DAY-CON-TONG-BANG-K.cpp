#include<bits/stdc++.h>
using namespace std;

void findSubsets(vector<int>& A, int K, int index, vector<int>& current, vector<vector<int>>& result) {
    if (K == 0) {
        result.push_back(current);
        return;
    }
    for (int i = index; i < A.size(); ++i) {
        if (A[i] > K) continue;
        current.push_back(A[i]);
        findSubsets(A, K - A[i], i + 1, current, result);
        current.pop_back();
    }
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end()); 
    
    vector<vector<int>> result;
    vector<int> current;
    findSubsets(A, K, 0, current, result);
    
    if (result.empty()) {
        cout << "-1\n";
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            cout << "[";
            for (size_t j = 0; j < result[i].size(); ++j) {
                if (j > 0) cout << " ";
                cout << result[i][j];
            }
            cout << "]";
            if (i < result.size() - 1) cout << " "; 
        }
        cout << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

