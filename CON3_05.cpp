#include <bits/stdc++.h>
using namespace std;

int maxDifference(vector<int>& A, int N, int K) {
    sort(A.begin(), A.end());  
    
    
    int totalSum = accumulate(A.begin(), A.end(), 0);
    
   
    int sumSmallK = accumulate(A.begin(), A.begin() + K, 0);
    
    
    int sumLargeK = accumulate(A.end() - K, A.end(), 0);
   
    return max(abs(totalSum - 2 * sumSmallK), abs(totalSum - 2 * sumLargeK));
}

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int N, K;
        cin >> N >> K;  

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << maxDifference(A, N, K);
        cout<<endl;
    }

    return 0;
}

