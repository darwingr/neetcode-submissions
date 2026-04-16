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

// IMPROVE? 2ms, 153.5MB
/*  - use streams for serialize?
    - 
*/
class Solution {
public:
    // serialize preorder & match
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       string rstring = serialize(root);
       string sstring = serialize(subRoot);
       rstring.erase(0, 1);
       sstring.erase(0, 1);
       return matches(rstring, sstring);
    }

    bool matches(const string& s1, const string& s2) {
        return (s1.find(s2) != string::npos);
    }

    // SERIALIZE by subtree
    // subtrees stay contiguous
    //  naturally recursive
    // , for node delimiter
    // # for null nodes
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return ",#";

        // preorder
        return "," + to_string(root->val)
                   + serialize(root->left)
                   + serialize(root->right);
    }
};
