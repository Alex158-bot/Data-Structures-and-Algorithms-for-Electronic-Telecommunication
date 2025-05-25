#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    
    vector<ll> A(N), B(N);
    
    for (ll &x : A) cin >> x;
    for (ll &x : B) cin >> x;

    sort(A.begin(), A.end());      
    sort(B.rbegin(), B.rend());     

    ll result = 0;
    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];      
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}

