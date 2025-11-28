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
    unordered_map<int,int> indexMap;  
    int postIdx;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, 
                              int inLeft, int inRight) {

        if (inLeft > inRight)
            return nullptr;

        // Pick root from postorder
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        // Split inorder using hashmap
        int idx = indexMap[rootVal];

        // Build right subtree first, then left
        root->right = buildTreeHelper(inorder, postorder, idx + 1, inRight);
        root->left  = buildTreeHelper(inorder, postorder, inLeft, idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIdx = n - 1;

        // Build hashmap for fast index lookup
        for (int i = 0; i < n; i++)
            indexMap[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, 0, n - 1);
    }
};

