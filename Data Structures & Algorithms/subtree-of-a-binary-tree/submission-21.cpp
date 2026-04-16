// Serialize & Match
//  O(M * N), linear with z-function or KMP
//  O(M + N)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        auto root_s = preorderSerialize(root);
        auto sroot_s = preorderSerialize(subRoot);
        
        return root_s.find(sroot_s) != -1;
    }

    string preorderSerialize(TreeNode* root) {
        if (!root)
            return "#$";
        string output = "#";
        return output.append(to_string(root->val))
                     .append(preorderSerialize(root->left))
                     .append(preorderSerialize(root->right));
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