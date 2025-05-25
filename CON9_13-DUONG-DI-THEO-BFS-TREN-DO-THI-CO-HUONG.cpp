#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1005;

vector<int> adj[MAX];
int parent[MAX];
bool visited[MAX];

void bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
                if (v == t) return; // stop early if destination is found
            }
        }
    }
}

void printPath(int s, int t) {
    if (!visited[t]) {
        cout << -1 << '\n';
        return;
    }
    vector<int> path;
    for (int cur = t; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << (i ? " " : "\n");
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;

        // Clear data
        for (int i = 1; i <= V; ++i) {
            adj[i].clear();
        }
        memset(visited, false, sizeof(visited));

        // Input edges
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // directed graph
        }

        bfs(s, t);
        printPath(s, t);
    }
    return 0;
}

