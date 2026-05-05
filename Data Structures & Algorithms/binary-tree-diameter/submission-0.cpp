
class Solution {
    int longest;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        longest = 0;
        dfs(root);
        return longest;
    }

    // return longest branch, write the overall longest path
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        
        int l_length = dfs(root->left); 
        int r_length = dfs(root->right);

        longest = max(longest, l_length + r_length);

        return max(l_length, r_length) + 1;
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