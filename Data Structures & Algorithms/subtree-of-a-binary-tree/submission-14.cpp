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
    // RECURSIVE / STACK
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isSame(root, subRoot)
            || (root->left  && isSubtree(root->left,  subRoot))
            || (root->right && isSubtree(root->right, subRoot));
    }

    bool isSame(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2)
            return true;
        if (!t1 || !t2)
            return false;
        if (t1->val != t2->val)
            return false;
        return isSame(t1->left,  t2->left)
            && isSame(t1->right, t2->right);
    }
};
