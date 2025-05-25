#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void spiralOrder(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            TreeNode* node = s1.top(); s1.pop();
            cout << node->val << " ";
            if (node->left) s2.push(node->left);
            if (node->right) s2.push(node->right);
        }
        
        while (!s2.empty()) {
            TreeNode* node = s2.top(); s2.pop();
            cout << node->val << " ";
            if (node->right) s1.push(node->right);
            if (node->left) s1.push(node->left);
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        map<int, TreeNode*> nodes;
        TreeNode* root = nullptr;
        
        for (int i = 0; i < N; i++) {
            int u, v;
            char x;
            cin >> u >> v >> x;
            if (nodes.find(u) == nodes.end()) nodes[u] = new TreeNode(u);
            if (nodes.find(v) == nodes.end()) nodes[v] = new TreeNode(v);
            if (!root) root = nodes[u];
            
            if (x == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
        }
        
        spiralOrder(root);
    }
    return 0;
}
