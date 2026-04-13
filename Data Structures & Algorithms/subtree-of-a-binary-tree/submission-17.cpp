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
        return sameTree(root, subRoot)
            || (root->left  && isSubtree(root->left, subRoot))
            || (root->right && isSubtree(root->right,subRoot));
    }

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;
        else if (!root || !subRoot)
            return false;
        
        return subRoot->val == root->val
            && sameTree(root->left, subRoot->left)
            && sameTree(root->right,subRoot->right);
    }
};
