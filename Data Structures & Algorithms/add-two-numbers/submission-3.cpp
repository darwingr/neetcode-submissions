// long long too small!
//  O(N)
//  O(N)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode;
        ListNode* head = l3;
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
        return head->next;
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