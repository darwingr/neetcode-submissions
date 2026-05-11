// BFS
//  O(N)
//  O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode*> qu;
        int row_nodes = 1;
        int next_row = 0;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            row_nodes--;

            if (node->left) {
                qu.push(node->left);
                next_row++;
            }
            if (node->right) {
                qu.push(node->right);
                next_row++;
            }

            if (row_nodes == 0) {
                result.push_back(node->val);
                row_nodes = next_row;
                next_row = 0;
            }
        }
        return result;
    }

    void dfs(TreeNode* root, vector<int>& out) {
        if (!root)
            return;
        else
            out.push_back(root->val);

        if(root->right)
            dfs(root->right, out);
        else if (root->left)
            dfs(root->left, out);
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