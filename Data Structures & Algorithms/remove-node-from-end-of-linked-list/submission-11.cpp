//  O(n)
//  O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        while (curr && n--) {
            curr = curr->next;
        }
        if (!curr) {
            curr = head->next;
            head->next = nullptr;
            delete head;
            return curr;
        }

        ListNode* trail = head;
        while (curr->next) {
            curr = curr->next;
            trail = trail->next;
        }
        curr = trail->next;
        trail->next = trail->next->next;
        curr->next = nullptr;
        delete curr;

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