//  O(m * n)
//  O(m + n)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (sameTree(root, subRoot))
                return true;

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        return false;
    }

    bool sameTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2)
            return true;
        if (!t1 || !t2)
            return false;
        return t1->val == t2->val
            && sameTree(t1->left,  t2->left)
            && sameTree(t1->right, t2->right);
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