// DFS: accumulate a count, track biggest so far in each path
//  O(N)
//  O(N)
class Solution {
    int count;
public:
    int goodNodes(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }

    void dfs(TreeNode* root, int biggest = INT_MIN) {
        if (!root)
            return;

        if (root->val >= biggest) {
            count++;
            biggest = max(biggest, root->val);
        }

        dfs(root->left,  biggest);
        dfs(root->right, biggest);
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