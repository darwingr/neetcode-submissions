// Index for each, dfs & inorder sentinel

class Solution {
    int in_i;
    int pre_i;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        in_i = pre_i = 0;
        return buildSubtree(preorder, inorder);
    }

    TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, int sentinel = INT_MAX) {
        if (pre_i >= preorder.size())
            return nullptr;
        if (inorder[in_i] == sentinel) {
            in_i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[pre_i]);
        pre_i++;
        node->left = buildSubtree(preorder, inorder, node->val);
        node->right = buildSubtree(preorder, inorder, sentinel);
        return node;
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