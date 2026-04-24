// DFS
//  O(N)
//  O(N)
class Solution {
    int pre_idx = 0;
    int in_idx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit = INT_MAX) {
        if (pre_idx >= preorder.size())
            return nullptr;
        if (inorder[in_idx] == limit) {
            in_idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_idx++]);
        root->left = dfs(preorder,inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
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