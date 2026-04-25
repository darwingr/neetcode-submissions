// DFS - limit arg, pre/in idx
//  O(N)
//  O(N)
class Solution {
    int pre_id;
    int in_id;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre_id = in_id = 0;
        return buildSubTree(preorder, inorder);
    }

private:
    TreeNode* buildSubTree(vector<int>& pre, vector<int>& in, int limit = INT_MAX) {
        if (pre_id >= pre.size())
            return nullptr;

        if (in[in_id] == limit) {
            in_id++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[pre_id]);
        pre_id++;
        root->left = buildSubTree(pre, in, root->val);
        root->right = buildSubTree(pre, in, limit);
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