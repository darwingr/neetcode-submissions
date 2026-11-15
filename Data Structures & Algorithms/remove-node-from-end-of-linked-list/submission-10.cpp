// Trailing pointer
//  O(N)
//  O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        while (curr && n--)
            curr = curr->next;
        if (!curr)
            return head->next;
            
        ListNode* trail = head;
        while (curr->next) {
            curr = curr->next;
            trail = trail->next;
        }
        ListNode* nth = trail->next;
        trail->next = nth->next;
        nth->next = nullptr;
        delete nth;
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