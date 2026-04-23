// Serialize & Count
//  O(N)
//  O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> serial;;
        serialize(root, serial);
        return serial.at(k-1);
    }

    void serialize(TreeNode* root, vector<int>& res) {
        if (root->left)
            serialize(root->left, res);
        res.push_back(root->val);
        if (root->right)
            serialize(root->right, res);
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