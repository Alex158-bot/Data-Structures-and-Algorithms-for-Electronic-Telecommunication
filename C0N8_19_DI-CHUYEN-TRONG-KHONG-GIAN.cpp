#include<bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, z, dist;
};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void solve() {
    int A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<char>>> grid(A, vector<vector<char>>(B, vector<char>(C)));
    queue<Node> q;
    Node start, end;
    
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < C; k++) {
                cin >> grid[i][j][k];
                if (grid[i][j][k] == 'S') start = {i, j, k, 0};
                if (grid[i][j][k] == 'E') end = {i, j, k, 0};
            }
        }
    }
    
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    q.push(start);
    visited[start.x][start.y][start.z] = true;
    
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.x == end.x && cur.y == end.y && cur.z == end.z) {
            cout << cur.dist << endl;
            return;
        }
        
        for (int d = 0; d < 6; d++) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d], nz = cur.z + dz[d];
            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < A && ny < B && nz < C && 
                !visited[nx][ny][nz] && grid[nx][ny][nz] != '#') {
                q.push({nx, ny, nz, cur.dist + 1});
                visited[nx][ny][nz] = true;
            }
        }
    }
    
    cout << "-1" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

