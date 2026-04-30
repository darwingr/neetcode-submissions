// DFS: preorder with delimiters
//  O(N)
//  O(N)
class Codec {
    int start = 0; // decode index
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "N,";
        return to_string(root->val)
            + ","
            + serialize(root->left)
            + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (start >= data.size())
            return nullptr;

        size_t i = 0;
        while (data[start + i] != ',') i++;
        auto ss = data.substr(start, i);
        start += i + 1;
        if (ss == "N")
            return nullptr;
        int val = stoi(ss);
        TreeNode* root = new TreeNode(val);
        root->left  = deserialize(data);
        root->right = deserialize(data);
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