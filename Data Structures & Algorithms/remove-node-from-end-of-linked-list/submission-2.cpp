// Trailing Pointer
//  O(N)
//  O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int pos = 0;
        ListNode* cur = head;
        ListNode* lazy = head;
        while (cur) {
            if (pos == n)
                lazy = head;
            else if (pos > n)
                lazy = lazy->next;
            
            cur = cur->next;
            pos++;
        }
        if (pos == n)
            return head->next;
        else if (pos > n) {
            ListNode* tmp = lazy->next;
            lazy->next = tmp->next;
            tmp->next = nullptr;
            delete tmp;
        }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */