/* IMPROVE? 2ms, 153.5MB
    - append instead of + (2ms, 153.0)
    - iteration instead of recursion (2ms, 153.3)
    - use streams for serialize?
    - 
*/
class Solution {
public:
    // serialize preorder & match
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       string rstring = serializeBySubtree(root);
       string sstring = serializeBySubtree(subRoot);
       return (rstring.find(sstring) != string::npos);
    }

    // subtrees stay contiguous
    //  naturally recursive
    // , for node delimiter
    // # for null nodes
    string serializeBySubtree(TreeNode* root) {
        stack<TreeNode*> stack;
        stack.push(root);
        string output = "";
        while (!stack.empty()) {
            auto node = stack.top();
            stack.pop();
            output.append(",");

            if (node) {
                output.append(to_string(node->val));
                stack.push(node->right);
                stack.push(node->left);
            }
            else
                output.append("#");

        }
        // erase first comma fro better matching
        output.erase(0, 1);
        return output;
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
