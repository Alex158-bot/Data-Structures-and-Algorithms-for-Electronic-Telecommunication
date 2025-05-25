#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void DFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;
    
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                s.push(v);
                visited[v] = true;
            }
        }
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int V, E, start;
        cin >> V >> E >> start;
        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);
        
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= V; i++)
            sort(adj[i].begin(), adj[i].end(), greater<int>());

        DFS(start, adj, visited);
    }
    return 0;
}

