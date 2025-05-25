#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int V, E;
    cin >> V >> E;
    vector<int> degree(V + 1, 0);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    
    int odd_count = 0;
    for (int i = 1; i <= V; i++) {
        if (degree[i] % 2 != 0) odd_count++;
    }
    
    cout << (odd_count == 0 ? 2 : (odd_count == 2 ? 1 : 0)) << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
