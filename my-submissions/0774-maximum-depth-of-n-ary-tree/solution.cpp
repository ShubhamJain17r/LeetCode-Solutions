/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) 
            return 0;

        int depth = 0;
        
        for (Node* node : root -> children) {
            depth = max(depth, maxDepth(node));
        } 

        return depth + 1;
        
        // queue<Node*> q;
        // q.push(root);

        // int depth = 0;

        // while (!q.empty()) {
        //     int sz = q.size();

        //     while (sz--) {
        //         Node* node = q.front(); q.pop();

        //         for (Node* temp : node -> children) {
        //             q.push(temp);
        //         }
        //     }
        //     depth++;
        // }

        // return depth;
    }
};
