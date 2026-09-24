// Iterative
//  O(N+M)
//  O(N+M)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2)   return nullptr;
        if (!list1)             return list2;
        if (!list2)             return list1;

        if (list1->val > list2->val)
            swap(list1, list2);
        ListNode* head = list1;
        list1 = list1->next;
        
        ListNode* tail = head;
        while (list1 && list2) {
            if (list1->val > list2->val)
                swap(list1, list2);
            tail->next = list1;
            list1 = list1->next;
            tail  = tail->next;
        }
        if (list1)
            tail->next = list1;
        if (list2)
            tail->next = list2;
        return head;
    }
};
