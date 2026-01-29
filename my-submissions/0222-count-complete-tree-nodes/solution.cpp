/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int cnt = 1;
        int sz = 1;

        while (!q.empty()) {
            while (sz--) {
                TreeNode* node = q.front(); q.pop();

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            sz = q.size();
            cnt += sz;
            if ((sz & (sz - 1)) != 0)
                return cnt;

        }
        return cnt;
    }
};
