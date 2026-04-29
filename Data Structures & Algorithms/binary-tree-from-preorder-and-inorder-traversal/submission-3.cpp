// DFS with limit
//      preorder tracks next value
//      inorder tracks right-most subtree value
//  O(N)
//  O(N)
class Solution {
    int preorder_i;
    int inorder_i;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_i = inorder_i = 0;
        return buildSubtree(preorder, inorder);
    }

    TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, int sentinel = INT_MAX) {
        if (preorder_i >= preorder.size())
            return nullptr;
        if (inorder[inorder_i] == sentinel) {
            inorder_i++;
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preorder_i]);
        preorder_i++;
        root->left  = buildSubtree(preorder, inorder, root->val);
        root->right = buildSubtree(preorder, inorder, sentinel);
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