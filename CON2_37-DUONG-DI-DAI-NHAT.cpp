#include <bits/stdc++.h>
using namespace std;

int longestPath = 0;
vector<vector<int>> adj;
vector<vector<bool>> visitedEdge;

// Quay lui tìm du?ng di dài nh?t
void dfs(int u, int length) {
    longestPath = max(longestPath, length);

    for (int v : adj[u]) {
        if (!visitedEdge[u][v]) {
            visitedEdge[u][v] = visitedEdge[v][u] = true; // Ðánh d?u c?nh dã di
            dfs(v, length + 1);
            visitedEdge[u][v] = visitedEdge[v][u] = false; // Quay lui
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    visitedEdge.assign(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Duy?t DFS t? m?i d?nh d? tìm du?ng dài nh?t
    longestPath = 0;
    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }

    cout << longestPath; // In k?t qu? không xu?ng dòng
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

