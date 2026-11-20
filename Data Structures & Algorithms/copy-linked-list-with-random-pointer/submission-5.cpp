// DFS
//  O(n)
//  O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        copyList(head);
        Node* list2 = head->random;
        copyRandoms(head);
        unzip(head);
        return list2;
    }

    void unzip(Node* head) {
        if (!head)
            return;
        Node* node = head->random;
        head->random = node->next;
        node->next = head->next ? head->next->random
                                : nullptr;
        unzip(head->next);
    }

    void copyRandoms(Node* head) {
        if (!head)
            return;
        Node* node = head->random;
        node->random = (node->next) ? node->next->random
                                    : nullptr;
        copyRandoms(head->next);
    }
    
    void copyList(Node* head) {
        if (!head)
            return;
        
        Node* node = new Node(head->val);
        node->next = head->random;
        head->random = node;
        copyList(head->next);
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