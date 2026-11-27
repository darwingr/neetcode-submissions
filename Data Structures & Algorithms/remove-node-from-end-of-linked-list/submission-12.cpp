// Two pass: find count then nth predecessor
//  use a dummy
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return head;
        size_t len = 1;
        ListNode* curr = head;
        while (curr->next) {
            curr = curr->next;
            len++;
        }
        size_t nth = len - n;
        ListNode dummy;
        dummy.next = head;
        curr = &dummy;
        while (nth--)
            curr = curr->next;
        ListNode* victim = curr->next;
        curr->next = curr->next->next;
        delete victim;
        return dummy.next;
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