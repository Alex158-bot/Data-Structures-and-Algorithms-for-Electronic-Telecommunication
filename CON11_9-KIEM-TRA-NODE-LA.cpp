#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

unordered_map<int, TreeNode*> nodes;
bool checkLeafLevel(TreeNode* root) {
    if (!root) return true;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int leafLevel = -1;
    
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if (!node->left && !node->right) { 
            if (leafLevel == -1) leafLevel = level;
            else if (leafLevel != level) return false;
        }
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        nodes.clear();
        
        TreeNode* root = nullptr;
        for (int i = 0; i < N; i++) {
            int u, v;
            char dir;
            cin >> u >> v >> dir;
            
            if (nodes.find(u) == nodes.end()) nodes[u] = new TreeNode(u);
            if (nodes.find(v) == nodes.end()) nodes[v] = new TreeNode(v);
            
            if (!root) root = nodes[u];
            
            if (dir == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
        }
        
        cout << (checkLeafLevel(root) ? "1" : "0") << "\n";
    }
    
    return 0;
}

