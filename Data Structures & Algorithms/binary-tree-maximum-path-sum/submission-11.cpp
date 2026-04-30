// DFS: track and compare 3 options
//  O(N)
//  O(N)
class Solution {
    int best = 0;
public:
    int maxPathSum(TreeNode* root) {
        best = root ? root->val : 0;
        dfsPathSum(root);
        return best;
    }

    int dfsPathSum(TreeNode* root) {
        if (!root)
            return 0;
        
        // r path, l path, both+root
        int lmax = dfsPathSum(root->left);
        int rmax = dfsPathSum(root->right);

        int pathmax = root->val;
        if (root->val + lmax > 0)
            pathmax = max(pathmax, root->val + lmax);
        if (root->val + rmax > 0)
            pathmax = max(pathmax, root->val + rmax);

        best = max({
            best,
            pathmax,
            lmax + root->val + rmax
        });
        return pathmax;
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