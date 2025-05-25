#include <iostream>
#include <vector>

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
        return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

void solve() {
    int V, E;
    cin >> V >> E;
    
    DSU dsu(V);
    bool hasCycle = false;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if (!dsu.unite(u, v)) hasCycle = true;
    }

    cout << (hasCycle ? "YES" : "NO") << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

