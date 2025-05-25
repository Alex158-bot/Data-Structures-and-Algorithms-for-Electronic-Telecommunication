#include<bits/stdc++.h>

using namespace std;
void BFS(int V, vector<vector<int>>& adj, int start) {
    vector<bool> visited(V, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node + 1 << " ";  // Chuy?n l?i thành 1-based index
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int V, E, u;
        cin >> V >> E >> u;
        u--;  
        
        vector<vector<int>> adj(V);
        
        for (int i = 0; i < E; i++) {
            int from, to;
            cin >> from >> to;
            from--; 
            to--;    
            adj[from].push_back(to);
        }
        for (int i = 0; i < V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        BFS(V, adj, u);
    }
    
    return 0;
}
