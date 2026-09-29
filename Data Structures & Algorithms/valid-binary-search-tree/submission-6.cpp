// Recursion/DFS
//  O(N)
//  O(N)
class Solution {
public:
    bool isValidBST(TreeNode* root, int val_min = INT_MIN, int val_max = INT_MAX) {
        if (!root) return true;
        if (root->val <= val_min || root->val >= val_max)
            return false;
        return isValidBST(root->left, val_min, root->val)
            && isValidBST(root->right, root->val, val_max);
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