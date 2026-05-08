// DFS recursive balanced & height
//  O(N)
//  O(N)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

    pair<bool,int> dfs(TreeNode* root) {
        if (!root)
            return {true, 0};
        auto [l_bal, l_height] = dfs(root->left);
        auto [r_bal, r_height] = dfs(root->right);
        int height = 1 + max(l_height, r_height);
        if (!l_bal || !r_bal)
            return {false, height};
        bool balanced = abs(l_height - r_height) <= 1;
        return {balanced, height};
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