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
    void helper(TreeNode* root, vector<string>& paths, string path){
        if (root->left == nullptr && root -> right == nullptr){
            paths.push_back(path.substr(0, path.length() - 2));
            return;
        }
        if (root->left){
            helper(root -> left, paths, path + to_string(root -> left -> val) + "->");
        }
        if (root -> right){
            helper(root -> right, paths, path + to_string(root -> right -> val) + "->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path;
        if (!root) return paths;

        path = to_string(root -> val) + "->";

        helper(root, paths, path);

        return paths;
    }
};
