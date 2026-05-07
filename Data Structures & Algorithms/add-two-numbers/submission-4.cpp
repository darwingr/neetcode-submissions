// Dummy head
//      Long long too small!
//      Cleanup the carry.
//      Alternatives: p2p & next_node lambda
//  O(N)
//  O(N)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode;
        ListNode* l3 = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            l3->next = new ListNode;
            l3 = l3->next;
            if (l1) {
                carry += l1->val; 
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            l3->val = carry % 10;
            carry /= 10;
        }
        ListNode* head = dummy->next;
        delete dummy;
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