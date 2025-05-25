#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited) {
    stack<int> st;
    st.push(u);
    
    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;
        }

        for (int i = adj[v].size() - 1; i >= 0; --i) {
            int next = adj[v][i];
            if (!visited[next]) {
                st.push(next);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E, u;
        cin >> V >> E >> u;

        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);

        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        DFS(u, adj, visited);
        cout << endl;
    }
    return 0;
}

