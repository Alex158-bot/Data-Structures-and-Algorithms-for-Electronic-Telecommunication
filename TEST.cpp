#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    queue<int> q;

    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "dang tham dinh: " << current << ", khoang cach tu " << start << " la " << distance[current] << endl;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << "\nKhoang cach tu dinh " << start << " toi caac dinh khac:\n";
    for (int i = 0; i < n; ++i) {
        if (distance[i] != -1)
            cout << "dinh " << i << ": " << distance[i] << endl;
        else
            cout << "dinh " << i << ": Khong the toi duoc\n";
    }
}

int main() {
    int n, m;
    cout << "Nhap so dinh: "; 
    cin >> n;
    cout << "Nhaap so canh: "; 
    cin >> m;

    vector<vector<int>> graph(n);

    cout << "Nhap " << m << " canh " << n-1 << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Nhap dinh bat dau: ";
    cin >> start;

    BFS(graph, start);

    return 0;
}
