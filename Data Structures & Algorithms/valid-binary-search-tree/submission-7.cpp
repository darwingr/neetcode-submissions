// Recursion with min/max
//  O(N)
//  O(N)
class Solution {
public:
    bool isValidBST(TreeNode* root,
                    int min_val = INT_MIN,
                    int max_val = INT_MAX)
    {
        if (!root)
            return true;

        return root->val < max_val
            && root->val > min_val
            && isValidBST(root->left,  min_val,   root->val)
            && isValidBST(root->right, root->val, max_val);
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