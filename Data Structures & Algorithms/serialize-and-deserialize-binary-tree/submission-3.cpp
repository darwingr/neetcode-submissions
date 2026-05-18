// DFS preorder, delimiters between nodes and for nulls
//      Avoids new string copies on both ops.
//  O(N)
//  O(N)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial = "";
        preorder_serialize(root, serial);
        return serial;
    }

    void preorder_serialize(TreeNode* root, string& serial) {
        if (!root) {
            serial += "N,";
            return;
        }
        serial += to_string(root->val) + ",";
        preorder_serialize(root->left, serial);
        preorder_serialize(root->right, serial);
    }

    // Decodes your encoded data to tree.
    size_t decode_start = 0;
    TreeNode* deserialize(const string& data) {
        if (decode_start >= data.size())
            return nullptr;

        if (data[decode_start] == 'N') {
            decode_start += 2;
            return nullptr;
        }
        
        int val;
        auto [ptr, _] = from_chars(data.data() + decode_start, data.data() + data.size(), val);
        decode_start = ptr - data.data() + 1;

        auto* root = new TreeNode(val);
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