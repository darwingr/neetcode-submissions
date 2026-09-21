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

class Solution {
public:
    // FAST/SLOW POINTERS
    // 1ms, 147MB
    // O(N) time
    // O(1) space
    bool hasCycle(ListNode* head) {
        if (!head)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow && fast) {
            if (slow == fast)
                return true;

            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
            else
                return false;
        }
        return false;
    }
};
