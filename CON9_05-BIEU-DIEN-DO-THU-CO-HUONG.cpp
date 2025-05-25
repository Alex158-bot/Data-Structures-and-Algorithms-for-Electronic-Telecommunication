#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 1; i <= V; ++i) {
            sort(adj[i].begin(), adj[i].end());
            cout << i << ":";
            if (adj[i].empty()) {
                cout << " " << i;  
            } else {
                for (int v : adj[i]) {
                    cout << " " << v;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}

