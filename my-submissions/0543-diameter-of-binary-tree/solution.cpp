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
private:
    int diameter = 0;
public:
    int findDepth(TreeNode* root) {
        if (!root) return 0;
        int left = findDepth(root -> left);
        int right = findDepth(root -> right);
    
        diameter = max(diameter, left + right);
        // cout << diameter << "\t" << root -> val <<endl;
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findDepth(root);
        return diameter;
    }

};
