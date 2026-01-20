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
    void invert(TreeNode* node, TreeNode* ans) {        
        if (node -> left) {
            ans -> right = new TreeNode(node -> left -> val);

            invert(node -> left, ans -> right);
        }
        if (node -> right) {
            ans -> left = new TreeNode(node -> right -> val);
            
            invert(node -> right, ans -> left);
        }

    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* ans = new TreeNode(root -> val);
        invert(root, ans);
        return ans;
    }
};
