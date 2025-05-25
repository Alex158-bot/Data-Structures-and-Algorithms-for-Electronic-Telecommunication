#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef pair<int, pair<int, int>> Node; // {cost, {row, col}}

// 4 hu?ng di chuy?n: Trái, Ph?i, Lên, Xu?ng
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dijkstra(vector<vector<int>> &A, int M, int N, int x1, int y1, int x2, int y2) {
    vector<vector<int>> dist(M, vector<int>(N, INF));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Kh?i t?o di?m b?t d?u
    dist[x1][y1] = A[x1][y1];
    pq.push({A[x1][y1], {x1, y1}});

    while (!pq.empty()) {
        auto [cost, pos] = pq.top();
        pq.pop();
        int x = pos.first, y = pos.second;

        // N?u d?n dích, tr? v? chi phí nh? nh?t
        if (x == x2 && y == y2) return cost;

        // Ki?m tra 4 hu?ng di chuy?n
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                int newCost = cost + A[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }

    return -1; // Không tìm th?y du?ng di (không x?y ra do d? bài d?m b?o có du?ng)
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int M, N;
        cin >> M >> N;

        vector<vector<int>> A(M, vector<int>(N));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Ðua v? index 0-based
        x1--; y1--; x2--; y2--;

        cout << dijkstra(A, M, N, x1, y1, x2, y2) << endl;
    }

    return 0;
}

