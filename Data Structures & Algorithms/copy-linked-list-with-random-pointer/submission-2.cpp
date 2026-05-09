// 2-pass: map old to new
//  O(N)
//  O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> oldToNew;

        Node* node = head;
        while (node) {
            oldToNew[node] = new Node(node->val);
            node = node->next;
        }

        node = head;
        while (node) {
            if (node->next)
                oldToNew[node]->next = oldToNew[node->next];
            if (node->random)
                oldToNew[node]->random = oldToNew[node->random];
            node = node->next;
        }
        
        return oldToNew[head];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/