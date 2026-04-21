// Reverse then Merge
//  O(N)
//  O(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        // find mid
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* l2 = reverse(slow->next);
        slow->next = nullptr;
        ListNode* l1 = head->next;

        while (l1) {
            head->next = l2;
            l2 = l2->next;
            head = head->next;

            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        if (l2)
            head->next = l2;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* tail = head;
        head = head->next;
        tail->next = nullptr;
        while (head->next) {
            ListNode* neck = head;
            head = head->next;
            neck->next = tail;
            tail = neck;
        }
        head->next = tail;
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