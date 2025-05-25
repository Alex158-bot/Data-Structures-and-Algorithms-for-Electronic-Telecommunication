#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj, rev_adj;
vector<bool> visited;
int V, E;

void dfs(int v, vector<vector<int>> &graph) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) dfs(u, graph);
    }
}

bool isStronglyConnected() {
    visited.assign(V + 1, false);
    int start = 1;
    while (start <= V && adj[start].empty()) start++;
    if (start > V) return true;
    dfs(start, adj);
    for (int i = 1; i <= V; i++) {
        if (!visited[i] && !adj[i].empty()) return false;
    }
    visited.assign(V + 1, false);
    dfs(start, rev_adj);
    for (int i = 1; i <= V; i++) {
        if (!visited[i] && !rev_adj[i].empty()) return false;
    }
    return true;
}

void solve() {
    cin >> V >> E;
    adj.assign(V + 1, vector<int>());
    rev_adj.assign(V + 1, vector<int>());
    vector<int> in_degree(V + 1, 0), out_degree(V + 1, 0);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
        out_degree[u]++;
        in_degree[v]++;
    }
    
    for (int i = 1; i <= V; i++) {
        if (in_degree[i] != out_degree[i]) {
            cout << "0\n";
            return;
        }
    }
    
    cout << (isStronglyConnected() ? "1\n" : "0\n");
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

