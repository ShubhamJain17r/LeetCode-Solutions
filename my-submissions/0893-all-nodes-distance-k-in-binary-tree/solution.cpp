/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root); 
        parent[root] = nullptr;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        while (k > 0 && !q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* node = q.front(); q.pop();
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (node != root && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            k--;
        }
        vector<int> nodes;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            nodes.push_back(node->val);
        }
        return nodes;
    }
};
