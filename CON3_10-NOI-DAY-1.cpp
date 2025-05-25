#include <bits/stdc++.h>
using namespace std;

long long minCostToConnectRopes(vector<int>& A) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(A.begin(), A.end());
    long long totalCost = 0;

    while (pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        long long cost = first + second;
        totalCost += cost;
        pq.push(cost);
    }
    return totalCost;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << minCostToConnectRopes(A) << '\n';
    }
    return 0;
}

