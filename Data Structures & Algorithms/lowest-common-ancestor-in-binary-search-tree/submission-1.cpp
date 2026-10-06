//  O(log N)
//  either parent, sibling or cousin
//      each side: contains p or q? 
class Solution {
    TreeNode* lca = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = nullptr;
        hasPQ(root, p, q);
        return lca;
    }
    pair<bool,bool> hasPQ(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return {false, false};
        auto [l_hasP, l_hasQ] = hasPQ(root->left, p, q);
        auto [r_hasP, r_hasQ] = hasPQ(root->right, p, q);
        pair<bool,bool> pq = {
            root->val == p->val || l_hasP || r_hasP,
            root->val == q->val || l_hasQ || r_hasQ,
        };
        if (pq.first && pq.second && !lca)
            lca = root;
        return pq;
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