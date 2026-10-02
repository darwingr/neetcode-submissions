// DFS: no level tracking
//  O(N)
//  O(N)
class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        res = vector<vector<int>>();
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root, int level=0) {
        if (!root) return;
        while (level >= res.size())
            res.push_back({});
        res[level].push_back(root->val);
        dfs(root->left,  level+1);
        dfs(root->right, level+1);
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