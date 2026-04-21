// Serialize & count
//  O(N)
//  O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        serialize(root, nodes, k);

        return nodes[k-1];
    }

    void serialize(TreeNode* root, vector<int>& nodes, int hint) {
        if (root->left)
            serialize(root->left, nodes, hint);
        nodes.push_back(root->val);
        if (nodes.size() >= hint)
            return;
        if (root->right)
            serialize(root->right, nodes, hint);
    }
};

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