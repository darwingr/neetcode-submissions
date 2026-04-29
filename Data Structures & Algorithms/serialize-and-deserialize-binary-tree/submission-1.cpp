// Encodes a tree to a single string.
// BFS (queue), pre-order
// 
//  Parsing trouble. Didn't account for dead trees in the queue.
//  DFS is probably nicer for deserialize?
//
// IDEA: you can decide any serialization format you like!!!
class Codec {
public:

    string serialize(TreeNode* root) {
        std::ostringstream oss;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop_front();
            if (node) {
                oss << node->val;
                queue.push_back(node->left);
                queue.push_back(node->right);
            } else
                oss << 'N';

            oss << ',';
        }
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto root = new TreeNode();

        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        if (ss && s == "N")
            return nullptr;
        else
            root->val = std::stoi(s);

        deque<TreeNode*> queue;
        queue.push_back(root);
        string sl, sr;
        while (getline(ss, sl, ',') && !queue.empty()) {
            auto parent = queue.front();
            queue.pop_front();
            
            if (parent)
                parent->left = mkchild(sl, queue);

            if (!getline(ss, sr, ',')) break;
            if (parent)
                parent->right = mkchild(sr, queue);
        }
        return root;
    }

    TreeNode* mkchild(const string& s, deque<TreeNode*>& queue) {
        if (s == "N")
            return nullptr;
        int val = std::stoi(s);
        TreeNode* child = new TreeNode(val);
        queue.push_back(child);
        return child;
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