#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef pair<int, pair<int, int>> Node;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int dijkstra(vector<vector<int>> &A, int N, int x1, int y1, int x2, int y2) {
    vector<vector<int>> dist(N, vector<int>(N, INF));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[x1][y1] = A[x1][y1];
    pq.push({A[x1][y1], {x1, y1}});

    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();
        int cost = top.first;
        int x = top.second.first;
        int y = top.second.second;

        if (x == x2 && y == y2) return cost;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                int newCost = cost + A[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1--; y1--; x2--; y2--;

        cout << dijkstra(A, N, x1, y1, x2, y2) << endl;
    }

    return 0;
}

