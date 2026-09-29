// BFS
//  O(N)
//  O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)  return {};

        queue<TreeNode*> que;
        que.push(root);

        vector<int> res;
        int row_node = 1;
        int row_width = 1;

        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
            // if last in row,
            //  add to res
            //  get next row width
            if (row_node == row_width) {
                res.push_back(node->val);
                row_width = que.size();
                row_node = 1;
            }
            else
                row_node++;
        }
        return res;
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