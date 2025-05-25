#include <bits/stdc++.h>
using namespace std;

long long minSum(vector<int> &A) {
    sort(A.begin(), A.end()); 
    
    long long num1 = 0, num2 = 0;
    for (int i = 0; i < A.size(); i++) {
        if (i % 2 == 0) num1 = num1 * 10 + A[i]; 
        else num2 = num2 * 10 + A[i];  
    }
    
    return num1 + num2; 
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << minSum(A) << endl;
    }
    return 0;
}

