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
    unordered_map<Node*, Node*> orig_to_clones;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        orig_to_clones.clear();
        return cloneSubGraph(node);
    }

private:
    Node* cloneSubGraph(Node* node) {
        Node* clone = new Node(node->val);
        orig_to_clones[node] = clone;
        
        for (Node* nei : node->neighbors) {
            if (!orig_to_clones.contains(nei))
                orig_to_clones[nei] = cloneSubGraph(nei);
            
            clone->neighbors.push_back(orig_to_clones[nei]);
        }

        return clone;
    }
};
