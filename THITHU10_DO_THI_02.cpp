#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] > rank[py]) parent[py] = px;
        else if (rank[px] < rank[py]) parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0), first, second, cycleEdge;
    DSU dsu(n);

    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        if (parent[v] > 0) {
            first = {parent[v], v};
            second = edge;
            edge[1] = 0;
        } else {
            parent[v] = u;
        }
    }

    for (auto &edge : edges) {
        if (edge[1] == 0) continue;
        if (!dsu.unite(edge[0], edge[1])) cycleEdge = edge;
    }

    if (!second.empty()) return cycleEdge.empty() ? second : first;
    return cycleEdge;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n, vector<int>(2));
        for (int i = 0; i < n; i++) cin >> edges[i][0] >> edges[i][1];

        vector<int> result = findRedundantDirectedConnection(edges);
        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}

