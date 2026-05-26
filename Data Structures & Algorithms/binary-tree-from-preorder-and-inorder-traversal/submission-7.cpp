// Preorder-DFS: 2 indices, inorder limit
//      degen cases upfront
//  O(N)
//  O(N) - recursion stack
class Solution {
    size_t pre_i;
    size_t ino_i;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre_i = ino_i = 0;
        return dfs(preorder, inorder);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit = INT_MAX) {
        if (pre_i >= preorder.size())
            return nullptr;
        if (inorder.at(ino_i) == limit) {
            ++ino_i;
            return nullptr;
        }

        auto* root = new TreeNode(preorder[pre_i++]);
        root->left  = dfs(preorder, inorder, root->val);
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