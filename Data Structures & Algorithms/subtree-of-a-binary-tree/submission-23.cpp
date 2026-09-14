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

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        if (root->val == subRoot->val
            && sameSubtree(root, subRoot))
            return true;
        if (   isSubtree(root->left, subRoot)
            || isSubtree(root->right, subRoot))
            return true;
        return false;
    }

    bool sameSubtree(TreeNode* r, TreeNode* sr) {
        if (!r && !sr)
            return true;
        if (!r || !sr)
            return false;
        return r->val == sr->val
            && sameSubtree(r->left, sr->left)
            && sameSubtree(r->right, sr->right);
    }
};
