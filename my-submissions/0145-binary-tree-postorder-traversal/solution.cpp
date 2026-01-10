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
    void postorderTraversal(TreeNode* node, vector<int> &postOrder) {
        if (!node) return;
        postorderTraversal(node -> left, postOrder);
        postorderTraversal(node -> right, postOrder);
        postOrder.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> postOrder;
        // postorderTraversal(root, postOrder);

        stack<TreeNode*> st;

        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            postOrder.push_back(node->val);

            if (node->left)
                st.push(node->left);
            if (node->right)
                st.push(node->right);
        }
        reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }
};
