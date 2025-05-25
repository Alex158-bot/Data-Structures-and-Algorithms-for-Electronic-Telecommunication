#include<bits/stdc++.h>

using namespace std;

vector<int> BFS(int V, const vector<vector<int>>& adj, int s, int t) {
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == t) {
            vector<int> path;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            return path;
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    return {};  // Tr? v? m?ng r?ng n?u không tìm th?y du?ng di
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        s--; t--;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> path = BFS(V, adj, s, t);

        if (path.empty()) {
            cout << -1 << endl;
        } else {
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

