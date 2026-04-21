// Serialize & count
//  O(N)
//  O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        serialize(root, nodes);

        return nodes[k-1];
    }

    void serialize(TreeNode* root, vector<int>& nodes) {
        if (root->left)
            serialize(root->left, nodes);
        nodes.push_back(root->val);
        if (root->right)
            serialize(root->right, nodes);
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