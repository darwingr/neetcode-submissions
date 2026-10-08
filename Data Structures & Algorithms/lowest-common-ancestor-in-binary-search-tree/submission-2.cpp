// Binary Search...for [p, q]
//  O(log N) == O(h)
//  O(log N) == O(h)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val)
            swap(p, q);
        return dfs(root, p->val, q->val);
    }
    
    TreeNode* dfs(TreeNode* root, int p, int q) {
        if (!root) return nullptr;
        
        if (root->val >= p && root->val <= q)
            return root;
        else if (q < root->val)
            return dfs(root->left, p, q);
        else
            return dfs(root->right, p, q);
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