// Morris Traversal
//      Inorder traversal with no recursion/stacks.
//      Use "thread", a right pointer, from predecessor to current node.
//  O(N) - linear
//  O(1)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                if (--k == 0)
                    return curr->val;
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;
                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    if (--k == 0)
                        return curr->val;
                    curr = curr->right;
                }
            }
        }
        return -1;
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