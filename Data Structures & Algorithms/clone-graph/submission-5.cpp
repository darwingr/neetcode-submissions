/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Map old to new
//  O(V + E)
//  O(V)
class Solution {
    unordered_map<Node*, Node*> old_to_new;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        old_to_new.clear();
        cloneSubGraph(node);
        return old_to_new[node];
    }
private:
    void cloneSubGraph(Node* node) {
        Node* clone = new Node(node->val);
        old_to_new[node] = clone;
        for (auto nei : node->neighbors) {
            if (!old_to_new.contains(nei))
                cloneSubGraph(nei);
            clone->neighbors.push_back(old_to_new[nei]);
        }
    }
};
