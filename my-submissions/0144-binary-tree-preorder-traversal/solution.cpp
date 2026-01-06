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
    void preorderTraversal(TreeNode* root, vector<int> &preOrder) {
        if (!root) return;
        preOrder.push_back(root->val);
        preorderTraversal(root -> left, preOrder);
        preorderTraversal(root -> right, preOrder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> preOrder;
        // preorderTraversal(root, preOrder);

        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            preOrder.push_back(node -> val);
            if (node -> right)
                st.push(node->right);
            if (node -> left)
                st.push(node->left);
        }
        return preOrder;
    }
};
