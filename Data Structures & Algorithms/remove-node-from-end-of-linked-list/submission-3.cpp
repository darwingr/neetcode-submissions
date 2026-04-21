// Trailing Pointer
class Solution {
public:
// 5, 1
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        while (cur && n--)
            cur = cur->next;
        
        if (!cur) // n == len 
            return head->next;
        
        ListNode* slow = head;
        while (cur->next) {
            cur = cur->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};
