// Balance: every subtree must be balanced
//      returning balance & height
//  O(N)
//  O(log N)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balanceHeight(root).first;
    }

    pair<bool,int> balanceHeight(TreeNode* root) {
        if (!root)
            return {true, 0};
        auto [lbal, lheight] = balanceHeight(root->left);
        auto [rbal, rheight] = balanceHeight(root->right);
        int depth = abs(lheight - rheight);
        return {
            lbal && rbal && depth <= 1,
            max(lheight, rheight) + 1
        };
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