// DFS & memo
//  O(N)
//  O(N)
class Solution {
    int max_dia = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_dia = 0;
        dfs(root);
        return max_dia;
    }

    // return longest branch, update max diameter for L&R
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int l_dia = dfs(root->left);
        int r_dia = dfs(root->right);
        max_dia = max(max_dia, l_dia + r_dia);

        return 1 + max(l_dia, r_dia);
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