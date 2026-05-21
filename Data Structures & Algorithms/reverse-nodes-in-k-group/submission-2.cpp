// LEAVE <K INTACT
//  O()
//  O()
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<pair<ListNode*,ListNode*>> headtails;
        ListNode* curr = head;
        int i = k;
        while (curr) {
            if (i == k)
                headtails.push_back({curr, nullptr});

            if (i == 1) {
                headtails.back().second = curr;
                i = k;
            }
            else
                i--;
            
            curr = curr->next;
        }
        ListNode* tail = nullptr;
        int reversals = headtails.size();
        if (i != k) {
            tail = headtails.back().first;
            reversals--;
        }
        
        // dummy
        auto* dummy = new ListNode();
        auto* last = dummy;
        for (int i=0; i<reversals; i++) {
            auto [h, t] = headtails[i];
            last->next = extract_reverse(h, t);
            last = h;
        }
        last->next = tail;
        head = dummy->next;
        delete dummy;
        return head;
    }

    ListNode* extract_reverse(ListNode* head, ListNode* tail) {
        ListNode* last = nullptr;
        while (head) {
            ListNode* succ = head->next;
            head->next = last;
            last = head;
            head = succ;
            if (last == tail)
                break;
        }
        return last;
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