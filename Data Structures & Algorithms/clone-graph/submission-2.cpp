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

// DFS
//  O(V + E)
//  O(V)
class Solution {
    unordered_map<int, Node*> vals_to_clones;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        vals_to_clones.clear();
        return cloneSubGraph(node);
    }

private:
    Node* cloneSubGraph(Node* node) {
        Node* clone = new Node(node->val);
        vals_to_clones[clone->val] = clone;
        
        for (Node* nei : node->neighbors) {
            if (!vals_to_clones.contains(nei->val))
                vals_to_clones[nei->val] = cloneSubGraph(nei);
            
            clone->neighbors.push_back(vals_to_clones[nei->val]);
        }

        return clone;
    }
};
