// DFS: 3 options at each node. global adder and return value.
//  O(N)
//  O(log N) - for stack space
class Solution {
    int best;

public:
    int maxPathSum(TreeNode* root) {
        best = INT_MIN;
        dfs(root);
        return best;
    }

private:
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        
        int lsum = dfs(root->left);
        int rsum = dfs(root->right);
        int max_child = max(lsum, rsum);

        int chain_sum = root->val + max_child;
        int child_sum = root->val + lsum + rsum;
        best = ranges::max({
            best,
            chain_sum,
            child_sum, 
            root->val
        });

        return max(root->val + max_child, root->val);
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