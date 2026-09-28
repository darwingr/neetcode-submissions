// DFS & memo?
//  O(N)
//  O(N)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balancedHeight(root).first;
    }
    pair<bool,int> balancedHeight(TreeNode* root) {
        if (!root)
            return {true, 0};

        auto [lbal, lheight] = balancedHeight(root->left);
        auto [rbal, rheight] = balancedHeight(root->right);
        bool balanced = lbal
                     && rbal 
                     && abs(lheight - rheight) <= 1;
        int height = 1 + max(lheight, rheight);
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