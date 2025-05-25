#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void solve() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> A(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    vector<vector<int>> dist(M, vector<int>(N, INF));
    set<pair<int, pair<int, int>>> s;

    dist[x1][y1] = A[x1][y1];
    s.insert({A[x1][y1], {x1, y1}});

    while (!s.empty()) {
        auto it = s.begin();
        int d = it->first, x = it->second.first, y = it->second.second;
        s.erase(it);

        if (x == x2 && y == y2) {
            cout << d << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                int newCost = d + A[nx][ny];
                if (newCost < dist[nx][ny]) {
                    s.erase({dist[nx][ny], {nx, ny}});
                    dist[nx][ny] = newCost;
                    s.insert({newCost, {nx, ny}});
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

