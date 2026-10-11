// DFS with count state?
//  O(N)
//  O(h)
class Solution {
    int good_nodes = 0;
public:
    int goodNodes(TreeNode* root) {
        good_nodes = 0;
        dfs(root);
        return good_nodes;
    }

    void dfs(TreeNode* root, int greatest = INT_MIN) {
        if (!root) return;

        if (greatest <= root->val)
            good_nodes++;
        
        dfs(root->left,  max(greatest, root->val));
        dfs(root->right, max(greatest, root->val));
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