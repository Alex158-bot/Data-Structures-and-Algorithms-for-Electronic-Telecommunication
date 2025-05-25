#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        map<int, Node*> nodes;
        map<int, bool> isChild;
        Node* root = nullptr;
        for (int i = 0; i < N; ++i) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (!nodes[u]) nodes[u] = new Node(u);
            if (!nodes[v]) nodes[v] = new Node(v);
            if (c == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
            isChild[v] = true;
        }
        for (auto& it : nodes) {
            if (!isChild[it.first]) {
                root = it.second;
                break;
            }
        }
        levelOrder(root);
    }
    return 0;
}

