class Solution {
    int longest = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        longest = 0;
        dia(root);
        return longest;
    }
    int dia(TreeNode* root) {
        if (!root)
            return 0;
        int d_right = dia(root->right);
        int d_left  = dia(root->left);
        longest = max(longest, d_right + d_left);
        return 1 + max(d_right, d_left);
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